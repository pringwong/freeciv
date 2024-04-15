#include <stdlib.h>
#include <string.h>
#include <math.h> /* pow, sqrt, exp */
#include <time.h>
#include <game.h>
#include <jansson.h>
#include "aihelper.h"

ActionQueue* human_assistant;

bool openTileWorked = false;
bool openUnitTile = false;

ActionQueue* initQueue(void){
    ActionQueue *action_q = (ActionQueue*)malloc(sizeof(ActionQueue));
    action_q->front = action_q->rear = NULL;
    return action_q;
}

ActionNode* newNode(struct packet_ai_player_action_response pdata)
{
    ActionNode* temp
        = (struct ActionNode*)malloc(sizeof(ActionNode));
    temp->actor_id = pdata.actor_id;
    temp->action_type = pdata.action_type;
    temp->actor_type = pdata.actor_type;
    temp->target_playerno = pdata.target_playerno;
    temp->target_actor_id = pdata.target_actor_id;
    temp->playerno = pdata.playerno;
    temp->unique_id = 0;
    sz_strlcpy(temp->js_data, pdata.js_data);
    temp->next = NULL;
    return temp;
}

void putNode(ActionQueue* action_q, struct packet_ai_player_action_response data)
{
    log_normal("putNode: %d", data.actor_id)
    // Create a new LL node
    ActionNode* temp = newNode(data);
 
    // If queue is empty, then new node is front and rear
    if (action_q->rear == NULL) {
        action_q->front = action_q->rear = temp;
        return;
    }
 
    // Add the new node at the end of queue and change rear
    temp->unique_id = action_q->rear->unique_id + 1;
    action_q->rear->next = temp;
    action_q->rear = temp;
}

struct packet_ai_player_action_response getPacket(ActionNode *node)
{
    struct packet_ai_player_action_response packet;
    packet.actor_id = node->actor_id;
    packet.action_type = node->action_type;
    packet.actor_type = node->actor_type;
    packet.playerno = node->playerno;
    packet.target_playerno = node->target_playerno;
    packet.target_actor_id = node->target_actor_id;
    packet.unique_id = node->unique_id;
    sz_strlcpy(packet.js_data, node->js_data);
    return packet;
}

struct packet_ai_player_action_response getNode(struct player *pplayer, ActionQueue *action_q)
{
    if (action_q->front == NULL)
    {
        struct packet_ai_player_action_response packet;
        packet.action_type = -1;
        packet.actor_type = -1;
        packet.actor_id = -1;
        packet.target_actor_id = -1;
        packet.target_playerno = -1;
        packet.playerno = player_number(pplayer);
        return packet;
    }
    ActionNode* temp = action_q->front;
 
    action_q->front = action_q->front->next;
 
    if (action_q->front == NULL)
    {
        action_q->rear = NULL;
    }

    struct packet_ai_player_action_response packet = getPacket(temp);
 
    free(temp);

    return packet;
}

void jsonizeQueue(ActionQueue *action_q, size_t n, char **json_str) {
    json_t *j_array = json_array();
    size_t index = 0;
    ActionNode *current = action_q->front;
    
    while (current != NULL && index < n) {
        json_t *j_object = json_object();
        json_object_set_new(j_object, "actor_id", json_integer(current->actor_id));
        json_object_set_new(j_object, "action_type", json_integer(current->action_type));
        json_object_set_new(j_object, "actor_type", json_integer(current->actor_type));
        json_object_set_new(j_object, "target_playerno", json_integer(current->target_playerno));
        json_object_set_new(j_object, "target_actor_id", json_integer(current->target_actor_id));
        json_object_set_new(j_object, "playerno", json_integer(current->playerno));
        json_object_set_new(j_object, "unique_id", json_integer(current->unique_id));
        json_object_set_new(j_object, "js_data", json_string(current->js_data));
        json_array_insert(j_array, index, j_object);
        
        ActionNode *next = current->next;
        free(current);
        
        current = next;
        index++;
    }
    
    if (index > 0) {
        ActionNode *temp = action_q->front;
        while (temp != NULL && index > 0) {
            temp = temp->next;
            index--;
        }
        action_q->front = temp;
        if (action_q->front == NULL) {
            action_q->rear = NULL;
        }
    }
    
    *json_str = json_dumps(j_array, JSON_INDENT(4));
    json_decref(j_array);
}


struct packet_ai_player_action_batch_response getBatch(struct player *pplayer, ActionQueue *action_q, int batch_size)
{
    char *json_output = NULL;
    jsonizeQueue(action_q, batch_size, &json_output);
    struct packet_ai_player_action_batch_response batch_packet;
    strcpy(batch_packet.batch_data, json_output);
    batch_packet.batch_data[sizeof(batch_packet.batch_data) - 1] = '\0';
    free(json_output);
    batch_packet.playerno = player_number(pplayer);
    return batch_packet;
}

struct packet_ai_player_action_response load_packet(struct player *pplayer, 
                                                 int actor_id, 
                                                 int action_type, 
                                                 char* js_data, 
                                                 int actor_type, 
                                                 struct player *aplayer,
                                                 int target_actor_id)
{
    struct packet_ai_player_action_response packet;
    packet.actor_id = actor_id;
    packet.action_type = action_type;
    packet.actor_type = actor_type;
    if (aplayer != NULL){
        packet.target_playerno = player_number(aplayer);
    } else {
        packet.target_playerno = -1;
    }
    packet.target_actor_id = target_actor_id;
    sz_strlcpy(packet.js_data, js_data);
    packet.playerno = player_number(pplayer);
    return packet;
}

void send_ai_assistant_message(struct player *pplayer, 
                               struct packet_ai_player_action_response packet)
{
    conn_list_iterate(game.est_connections, pconn) {
      struct player *aplayer = conn_get_player(pconn);
        if (aplayer == pplayer) {
          send_packet_ai_player_action_response(pconn, &packet);
        }
    } conn_list_iterate_end;
}

bool is_assistant(const struct player *pplayer)
{
    return is_human(pplayer) && game.server.advisor;
}

/**********************************************************************//**
  Human assistant.
  actor_id: 
    0: unit
    1: diplomacy
    2: tech
    3: city- 0: unset, 1: set, 2: product
**************************************************************************/
void helper_set_unit_action(struct player *pplayer, int unit_id, int act_id, int dir8, int target_id)
{
    json_t* js_data = json_object();
    json_object_set_new(js_data, "target_id", json_integer(target_id));
    json_object_set_new(js_data, "dir8", json_integer(dir8));
    char* js_str = json_dumps(js_data, 0);
    log_normal("helper_set_unit_action: unit_id=%d, act_id=%d, dir8=%d, js_str=%s", unit_id, act_id, dir8, js_str)
    struct packet_ai_player_action_response packet = load_packet(pplayer, unit_id, act_id, js_str, 0, NULL, -1);
    putNode(human_assistant, packet);
}

void helper_set_city_production(struct player *pplayer, struct city *pcity, int kind, const char* name){
    log_normal("helper_set_city_production: %s, %d, %d, %s", player_name(pplayer), pcity->id, kind, name)
    int actor_type = 3;
    json_t* js_data = json_object();
    json_object_set_new(js_data, "kind", json_integer(kind));
    json_object_set_new(js_data, "name", json_string(name));
    char* js_str = json_dumps(js_data, 0);
    struct packet_ai_player_action_response packet = load_packet(pplayer, pcity->id, 2, js_str, actor_type, NULL, -1);
    putNode(human_assistant, packet);
}

void helper_set_tile_worked(struct tile *ptile, struct city *pcity)
{

    if (ptile->worked == NULL && pcity == NULL) {
      return;
    }

    struct packet_ai_player_action_response packet;
    int actor_type = 3;

    // unset
    if (pcity == NULL){
       log_normal("helper_set_tile_worked[unset]: %s, %d, %s", player_name(ptile->worked->owner), ptile->worked->id, terrain_rule_name(ptile->terrain))
       packet = load_packet(ptile->worked->owner, ptile->worked->id, 0, "", actor_type, NULL, ptile->index);
    }

    // set
    if (ptile->worked == NULL) {
       log_normal("helper_set_tile_worked[set]: %s, %d, %s", player_name(pcity->owner), pcity->id, terrain_rule_name(ptile->terrain))
       packet = load_packet(pcity->owner, pcity->id, 1, "", actor_type, NULL, ptile->index);
    }

    putNode(human_assistant, packet);
}


/**
 * Unit
*/
void helper_set_unit_activities(struct player *pplayer, int unit_id, int act_id)
{
    if (act_id != ACTIVITY_IDLE) {
        log_normal("helper_set_unit_activities: %d, %d, %d", ENTITY_TYPE_UNIT, unit_id, act_id)
        json_t* js_data = json_object();
        json_object_set_new(js_data, "is_activity", json_integer(1));
        char* js_str = json_dumps(js_data, 0);
        struct packet_ai_player_action_response packet = load_packet(pplayer, unit_id, act_id, js_str, 0, NULL, -1);
        putNode(human_assistant, packet);
    }
}

void helper_do_unit_action(struct player *pplayer, int unit_id, int act_id, char* js_data)
{
    log_normal("helper_do_unit_action: %d %d, %s", unit_id, act_id, js_data)

    struct packet_ai_player_action_response packet = load_packet(pplayer, unit_id, act_id, js_data, 0, NULL, -1);

    putNode(human_assistant, packet);
}

/**
 * Diplomacy
*/
void helper_set_player_diplomacy(struct player *pplayer, struct player *aplayer, int clause, char* js_data)
{
    log_normal("helper_set_player_diplomacy: %s, %s, %d", player_name(pplayer), player_name(aplayer), clause)
    struct packet_ai_player_action_response packet = load_packet(pplayer, player_index(pplayer), clause, js_data, 1, NULL, -1);
    putNode(human_assistant, packet);
}

/**
 * Tech
*/
void helper_set_tech_goal(struct player *pplayer, int tech_id, const char* tech_name)
{
    log_normal("helper_set_tech_goal: %s, %d, %s", player_name(pplayer), tech_id, tech_name)
    int actor_type = 2;
    int actor_id = 0;// goal

    json_t* js_data = json_object();
    json_object_set_new(js_data, "tech_name", json_string(tech_name));
    char* js_str = json_dumps(js_data, 0);

    struct packet_ai_player_action_response packet = load_packet(pplayer, actor_id, tech_id, js_str, actor_type, NULL, -1);

    putNode(human_assistant, packet);
}

void helper_set_tech_researching(struct player *pplayer, int tech_id)
{
    log_normal("helper_set_tech_researching: %s, %d", player_name(pplayer), tech_id)
    int actor_type = 2;
    int actor_id = 1;// researching
    struct packet_ai_player_action_response packet = load_packet(pplayer, actor_id, tech_id, "", actor_type, NULL, -1);

    putNode(human_assistant, packet);
}