#include <stdlib.h>
#include <string.h>
#include <math.h> /* pow, sqrt, exp */
#include <time.h>
#include <game.h>
#include "aihelper.h"

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
    packet.playerno = node->playerno;
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
        packet.actor_id = -1;
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

struct packet_ai_player_action_response load_packet(struct player *pplayer, int actor_id, int action_type, char* js_data)
{
    struct packet_ai_player_action_response packet;
    packet.actor_id = actor_id;
    packet.action_type = action_type;
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
