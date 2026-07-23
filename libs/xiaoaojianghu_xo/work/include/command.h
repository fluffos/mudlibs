// filename : /include/command.h

#ifndef __COMMAND_H__
#define __COMMAND_H__

#define NPC_PATH      ({"/cmds/verb/", "/cmds/comm/"})
#define PPL_PATH        NPC_PATH + ({"/cmds/skill/"})
#define IMM_PATH 	PPL_PATH + ({"/cmds/imm/"})
#define APR_PATH 	IMM_PATH + ({"/cmds/app/"})
#define WIZ_PATH 	APR_PATH + ({"/cmds/wiz/"})
#define ARC_PATH 	WIZ_PATH + ({"/cmds/arch/"})
#define ADM_PATH 	ARC_PATH + ({"/cmds/adm/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD	"/cmds/verb/drop"
#define GET_CMD		"/cmds/verb/get"
#define GO_CMD		"/cmds/verb/go"
#define LOOK_CMD    "/cmds/verb/look"
#define TELL_CMD	"/cmds/comm/tell"
#define UPTIME_CMD	"/cmds/comm/uptime"
#define WHO_CMD		"/cmds/comm/who"
#define LOG_CMD     "/cmds/comm/log"
#define SUICIDE_CMD "/cmds/comm/suicide"
#define HP_CMD      "/cmds/comm/hp"

#endif

