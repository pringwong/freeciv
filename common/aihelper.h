
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
    int action_type;
    int playerno;
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

struct packet_ai_player_action_response load_packet(struct player *pplayer, int actor_id, int action_type);
void send_ai_assistant_message(struct player *pplayer, 
                               struct packet_ai_player_action_response packet);
bool is_assistant(const struct player *pplayer);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* FC__AIHELPER_H */
