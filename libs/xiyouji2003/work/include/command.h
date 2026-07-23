// Update by waiwai@2003/04/25

#include "ansi.h"

#define ADM_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/eld/", "/cmds/usr/","/cmds/std/"})
#define ARC_PATH ({"/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/eld/", "/cmds/usr/","/cmds/std/"})
#define WIZ_PATH ({"/cmds/imm/", "/cmds/eld/", "/cmds/usr/", "/cmds/std/", "/cmds/wiz/"})
#define APR_PATH ({"/cmds/imm/", "/cmds/eld/", "/cmds/usr/", "/cmds/std/", "/cmds/wiz/"})
#define IMM_PATH ({"/cmds/imm/", "/cmds/eld/", "/cmds/usr/", "/cmds/std/"})
#define ELD_PATH ({"/cmds/eld/", "/cmds/usr/", "/cmds/std/"})
#define PLR_PATH ({"/cmds/std/", "/cmds/usr/"})
#define NPC_PATH ({"/cmds/std/"})

#define TIME_TICK2 		(time()*60)
#define TIME_TICK1 		((time()-890000000)*60)
#define TIME_TICK 		((time()-900000000)*60) 
#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD		"/cmds/std/get"
#define GO_CMD		"/cmds/std/go"
#define LOOK_CMD		"/cmds/std/look"
#define QUIT_CMD		"/cmds/usr/quit"
#define REMOVE_CMD          "/cmds/std/remove"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD		"/cmds/usr/who"
#define XUE_CMD             "/cmds/std/learn"  
#define EXAMINE_CMD         "/cmds/arch/examine"
#define BJTIME_CMD		"/cmds/usr/bjtime"
#define TIME_CMD		"/cmds/usr/time"
#define PORT_CMD		"/cmds/usr/port"
#define XYJTIME_CMD		"/cmds/usr/xyjtime"
#define NEWS_CMD		"/cmds/usr/news"
#define WEAR_CMD		"/cmds/std/wear"
#define WIELD_CMD		"/cmds/std/wield"
