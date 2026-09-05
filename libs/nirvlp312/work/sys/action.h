/*
 * /sys/action.h defines macros to be used as keys in 'actions' as understood
 * by the combat system.
 */

#ifndef _sys_action_h
#define _sys_action_h

/* These strings are keys in an action-(event-)mapping */
#define A_NEEDED_USED     "needed_used"
#define A_NEEDED_SHARED   "needed_shared"
#define A_POSSIBLE_USED   "possible_used"
#define A_POSSIBLE_SHARED "possible_shared"
#define A_USED            "used"
#define A_SHARED          "shared"
#define A_AWAITED         "awaited"
#define A_CONCENTRATION   "concentration"

#define A_ABORTED         "aborted"
#define A_STALLED         "stalled"
#define A_ABORT_ACTION    "abort_action"

#define A_PREPARE_TIME    "prepare_time"
#define A_RUNTIME         "runtime"
#define A_FINISH_TIME     "finish_time"

/* These values are bits for actions */
#define A_MODE_FAST       1
#define A_MODE_PREPEND    2
#define A_MODE_SHORT      4
#define A_MODE_INTERRUPT  3  /* (A_MODE_FAST|A_MODE_PREPEND) */
#define A_MODE_NORMAL     0

/* Here come action-priorites */
#define AP_HIGH           1
#define AP_LOW            0

#define TOOL_ACTION       "basic/tool_action"

/* action-identifier-prefixed */
#define A_STOP_           "stop_"
#define A_PLANNED_        "planned_"
#define A_FAST_           "fast_"
#define A_INTERRUPT_      "interrupt_"

/* action parser classes */
#define A_G_TARGET        "<action#target>"
#define A_G_WEAPON        "<action#weapon>"
#define A_G_TOOL          "<action#tool>"
#define A_G_POSITION      "<action#position>"
#define A_G_DIRECTION     "<action#direction>"
#define A_G_BODYPART      "<action#bodypart>"
#define A_G_OBJECT        "<object>"
#define A_G_INDIRECT      "<indirect>"
#define A_G_LIVING        "<living>"

#endif /* _sys_action_h */
