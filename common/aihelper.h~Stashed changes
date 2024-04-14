
#ifndef FC__AIHELPER_H
#define FC__AIHELPER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SPECENUM_NAME entity_type
#define SPECENUM_VALUE0 ENTITY_TYPE_UNIT
#define SPECENUM_VALUE0NAME "unit"
#define SPECENUM_VALUE1 ENTITY_TYPE_CITY
#define SPECENUM_VALUE1NAME "city"
#define SPECENUM_INVALID ((enum entity_type) (ENTITY_TYPE_CITY + 1))
#include "specenum_gen.h"

struct packet_ai_player_action_response;

typedef struct ActionNode{
    int actor_id;
    int actor_type;
    int target_playerno;
    int target_actor_id;
    int action_type;
    int playerno;
    int unique_id;
    char js_data[512];
    struct ActionNode* next;
} ActionNode;

typedef struct ActionQueue{
    struct ActionNode *front, *rear;
} ActionQueue;

ActionNode* newNode(struct packet_ai_player_action_response pdata);

ActionQueue *initQueue(void);

void putNode(ActionQueue *action_q, struct packet_ai_player_action_response data);

struct packet_ai_player_action_response getPacket(ActionNode *node);

struct packet_ai_player_action_response getNode(struct player *pplayer, ActionQueue *action_q);
struct packet_ai_player_action_batch_response getBatch(struct player *pplayer, ActionQueue *action_q, int batch_size);
struct packet_ai_player_action_response load_packet(struct player *pplayer, 
                                                  int actor_id, 
                                                  int action_type, 
                                                  char* js_data, 
                                                  int actor_type, 
                                                  struct player *aplayer,
                                                  int target_actor_id);
void send_ai_assistant_message(struct player *pplayer, 
                               struct packet_ai_player_action_response packet);
bool is_assistant(const struct player *pplayer);
void helper_set_tile_worked(struct tile *ptile, struct city *pcity);
void helper_set_city_production(struct player *pplayer, struct city *pcity, int kind, const char* name);
void helper_set_unit_action(struct player *pplayer, int unit_id, int act_id, int dir8, int target_id);
void jsonizeQueue(ActionQueue *action_q, size_t n, char **json_str);
void helper_set_unit_activities(struct player *pplayer, int unit_id, int act_id);
void helper_do_unit_action(struct player *pplayer, int unit_id, int act_id, char* js_data);
void helper_set_player_diplomacy(struct player *pplayer, struct player *aplayer, int clause, char* js_data);
void helper_set_tech_goal(struct player *pplayer, int tech_id);
void helper_set_tech_researching(struct player *pplayer, int tech_id);

extern ActionQueue* human_assistant;
extern bool openTileWorked;
extern bool openUnitTile;
struct unit *copyUnit(const struct unit *source);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* FC__AIHELPER_H */
