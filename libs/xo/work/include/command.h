// filename : /include/command.h

#ifndef __COMMAND_H__
#define __COMMAND_H__

#define NPC_PATH      ({"/cmds/verb/", "/cmds/comm/"})
#define PLAYER_PATH    NPC_PATH + ({"/cmds/skill/"})
#define HM_PATH        PLAYER_PATH + ({"/cmds/hm/"})
#define AVATAR_PATH    HM_PATH + ({"/cmds/avatar/"})
#define APP_PATH       AVATAR_PATH + ({"/cmds/app/"})
#define ARCH_PATH       APP_PATH + ({"/cmds/arch/"})
#define ADMIN_PATH       ARCH_PATH + ({"/cmds/admin/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD    "/cmds/verb/drop"
#define GET_CMD        "/cmds/verb/get"
#define GO_CMD        "/cmds/verb/go"
#define LOOK_CMD    "/cmds/verb/look"
#define TELL_CMD    "/cmds/comm/tell"
#define UPTIME_CMD    "/cmds/comm/uptime"
#define WHO_CMD        "/cmds/comm/who"
#define LOG_CMD     "/cmds/comm/log"
#define SUICIDE_CMD "/cmds/comm/suicide"
#define HP_CMD      "/cmds/comm/hp"
#define XPLOR_CMD   "/cmds/app/xplor.lpc"

#define LL_CMD  "/cmds/arch/ll.lpc"
#endif

