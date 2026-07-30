// command.h
//New Writen by Alarms 3/31/99
//Update by Alarms 4/4/99

///*Masked by Alarms 3/31/99
#define ADM_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/","cmds/space/"})
#define ARC_PATH ({"/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/","cmds/space/"})
#define WIZ_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/wiz/","cmds/space/"})
#define APR_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/wiz/","cmds/space/"})
#define IMM_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/","cmds/space/"})
#define PLR_PATH ({"/cmds/std/", "/cmds/usr/","cmds/space/"})
#define NPC_PATH ({"/cmds/std/","cmds/space/"})
//*/

// These are command objects that will also be called in those
// non-player objects.

//New Writen
#define POSITION_CMD		"/cmds/usr/position"
#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define SAY_CMD			"/cmds/std/say"
#define TIME_CMD		"/cmds/usr/time"
#define SCORE_CMD		"/cmds/usr/score"
//New Writen end
#define GO_CMD			"/cmds/std/go"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"
