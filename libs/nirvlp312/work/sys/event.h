#ifndef _sys_event_h
#define _sys_event_h

#define EPRIO_MODIFY    600
#define EPRIO_MODIFY2   700
#define EPRIO_MODIFY3   800
#define EPRIO_CANCEL    300
#define EPRIO_CANCEL2   400
#define EPRIO_CANCEL3   500
#define EPRIO_HANDLE      0
#define EPRIO_HANDLE2   100
#define EPRIO_HANDLE3   200
/* If you want different notice-priorities, use an offset
 * like EPRIO_NOTICE+offset  */
#define EPRIO_NOTICE  (-300)

#define EPRIO_NOTICE2 (EPRIO_NOTICE+1)  /* for compatibility */
#define EPRIO_NOTICE3 (EPRIO_NOTICE+2)  /* for compatibility */

#define E_TYPE             "?"
#define E_HANDLER          "@"
#define E_HANDLER_PRIORITY "!"

#define EH_DEFAULT      0
#define EH_NORMAL      10
#define EH_OVERRIDE    20

/* These fields are put into the event-mapping automatically */
#define E_COMMAND      "command"
#define E_SENDER       "sender"
#define E_RECEIVERS    "receivers"

/* The next few are to prevent too deep recursions */
#define E_MODIFIERS    "modifiers"
#define E_PREVENTERS   "preventers"
#define E_HANDLERS     "handlers"
#define E_REACTORS     "reactors"
#define E_HANDLED      "handled"
#define E_CANCELLED    "cancelled"

#define E_TIME         "time"
#define E_AGENT        "agent"
#define E_CO_AGENTS    "co_agents"
#define E_TARGET       "target"
#define E_TOOL         "tool"
#define E_WITH         "with"
#define E_WEAPON       "weapon"
#define E_DAMAGE       "damage"
#define E_WOUND        "wound"
#define E_DAMAGE_TYPE  "damage_type"
#define E_ACTION       "action"
#define E_SUCCESS      "success"
#define E_SKILL        "skill"
#define E_DIFFICULTY   "difficulty"
#define E_RANGE        "range"
#define E_MODE         "mode"
#define E_PHASE        "phase"

#define E_OBJECT       "object"
#define E_LINKED       "linked"
#define E_RECIPIENT    "recipient"
#define E_WHERE        "where"
#define E_BODY         "body"
#define E_CONTAINER    "container"

/* combat-related events */
#define E_DEFENSE      "defense"
#define E_DEFENSE_TYPE "defense_type"
#define E_ATTACK       "attack"
#define E_ATTACK_TYPE  "attack_type"

/* If this is set with an object, it will be used instead of the standard
 * death mark /room/death/death_mark
  */
#define E_DEATH_MARK   "death_mark"

/* for /bin/soul.c */
#define E_FEELING      "feeling"
#define E_PERSONS      "persons"
#define E_ADVERBS      "adverbs"
#define E_BODYPARTS    "bodyparts"
#define E_REMOTE_TARGET "remote_target" /* for the remote target(s), who also
                                         * see feelings of other rooms */

#define E_FROM         "from"
#define E_TO           "to"
#define E_DIR          "dir"
#define E_IN           "in"
#define E_OUT          "out"
#define E_CMD          "cmd"

/* for message-event in /global/commands/comm.c */
#define E_MSG_TYPE     "msgtype"
#define E_RECIPIENTS   "recipients"
#define E_MSG          "message"
#define E_MESSAGES     "messages"

#define E_ID           "id"
#define E_NUMBER       "number"

#define E_TEXT         "text"
#define E_TONGUE       "tongue"

#define E_AGENT_MSG    "agent_msg"
#define E_ROOM_MSG     "room_msg"
#define E_NOTIFY_FAIL  "notify_fail"
#define E_KEY          "key"
#define E_PREPOSITION  "preposition"
#define E_PARTNER      "partner"

/* some additions required for magic */
#define E_MAGIC        "magic"
#define E_ART          "art"
#define E_LORE         "lore"
#define E_REQUISITE    "requisite"
#define E_SPELL        "spell"
#define E_COMPONENT    "component"
#define E_LEVEL        "level"
#define E_COST         "cost"
#define E_DELAY        "delay"
#define E_EXTRA_DELAY  "extra_delay"

/* some additions for the quest event */
#define E_QUEST        "quest"
#define E_REWARD       "reward"
#define E_QP_REWARD    "qp_reward"
#define E_FIRST_SOLVING "first_solving"

/* some additions for the consume, eat, drink, and poison event */
#define E_ALCOHOL_RATE       "alcohol_rate"
#define E_BODY_HEALING_RATE  "body_healing_rate"
#define E_MIND_HEALING_RATE  "mind_healing_rate"
#define E_AMOUNT             "amount"

#define E_POISON_RATE        "poison_rate"
#define E_POISON_SPEED       "poison_speed"

/* for the modify_skill event */
#define E_MODIFICATION       "modification"

/* for the quit_really event */
#define E_EQUIPMENT          "equipment"  /* equipment to be store */

/* for the play [instrument] event */
#define E_MELODY             "melody"

#endif  /* _sys_event_h */
