#ifndef _COMMAND_H_
#define _COMMAND_H_
// command.h

#define ADM_PATH ({"/cmds/group/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/", "/cmds/wiz/", "/cmds/arch/", "/cmds/ass/", "/cmds/common/", "/cmds/adm/"})
#define ASS_PATH ({"/cmds/group/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/", "/cmds/wiz/", "/cmds/ass/", "/cmds/common/"})
#define ARC_PATH ({"/cmds/group/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/", "/cmds/wiz/", "/cmds/arch/", "/cmds/common/"})
#define WIZ_PATH ({"/cmds/group/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/", "/cmds/wiz/"})
#define APR_PATH ({"/cmds/group/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/"})
#define IMM_PATH ({"/cmds/group/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/"})
#define PLR_PATH ({"/cmds/group/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define UNR_PATH ({"/cmds/group/", "/cmds/usr/"})
#define NPC_PATH ({"/cmds/group/", "/cmds/std/", "/cmds/skill/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define IRC_CMD			"/cmds/usr/irc"
#define TELL_CMD		"/cmds/std/tell"
#define TOP_CMD			"/cmds/usr/top"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"

#endif
