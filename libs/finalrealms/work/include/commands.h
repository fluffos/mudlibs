#ifndef __COMMANDS_HEADER__
#define __COMMANDS_HEADER__

// command and soul information
// 1995 Jun 15  Laggard     added priorities, moved costs here from player.h

#define COMMAND_SERVER "/std/commands"
#define SOUL_OBJECT "/obj/handlers/soul"


// timing of commands
#define FOREVER_TIME       100

#define SPEAK_TIME           5
#define LOOK_TIME            5
#define EXAMINE_ITEM_TIME    2


// social point costs
#define WIMP_CHAT           15  // Cost of newbie or guest chatting...


// Action Priorities
#define A_P_SOUL_FORCE       20000
#define A_P_EMERGENCY        10003
#define A_P_ALWAYS           10002
#define A_P_STOP_QUEUE       10001
#define A_P_CHECK_TIME       10000
#define A_P_NO_SOUL              1
#define A_P_SOUL               (-2)
#define A_P_CMD              (-500)
#define A_P_CHECK_FINAL    (-10000)


#endif
