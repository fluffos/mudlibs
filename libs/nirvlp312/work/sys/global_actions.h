#ifndef _sys_global_action_h
#define _sys_global_action_h

#define ACTION_DAEMON           "bin/actions"
#define ACTIONS_OF(ob)          ((ACTION_DAEMON)->find_instance(ob))

#define ACTION                  "/obj/actions"

/* These defines are for usage in apply_action()  */
#define ACTION_CLIMB            "climb"
#define ACTION_FORGE            "forge"
#define ACTION_PICK_LOCK        "pick lock"
#define ACTION_PICK_POCKET      "pick pocket"
#define ACTION_PLAY_INSTRUMENT  "play instrument"
#define ACTION_READ             "read"
#define ACTION_SEARCH           "search"
#define ACTION_THROW            "throw"

#endif  /* _sys_global_action_h */
