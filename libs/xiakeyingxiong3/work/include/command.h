// command.h

#define ADM_PATH ({"/cmds/adm/", "/cmds/arch/","/cmds/mon/", "/cmds/wiz/", "/cmds/apr/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define ARC_PATH ({"/cmds/arch/","/cmds/mon/","/cmds/wiz/", "/cmds/apr/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define MON_PATH ({"/cmds/mon/", "/cmds/wiz/", "/cmds/apr/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define WIZ_PATH ({"/cmds/wiz/", "/cmds/apr/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define APR_PATH ({"/cmds/apr/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define IMM_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define PLR_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define UNR_PATH ({"/cmds/usr/", "/cmds/std/"})
#define NPC_PATH ({"/cmds/std/", "/cmds/skill/"})

// These are command objects that will also be called in those
// non-player objects.

#define GO_CMD			"/cmds/std/go"
#define PUT_CMD			"/cmds/std/put"
#define GET_CMD			"/cmds/std/get"
#define GIVE_CMD		"/cmds/std/give"
#define DROP_CMD		"/cmds/std/drop"
#define RIDE_CMD		"/cmds/std/ride"
#define TELL_CMD		"/cmds/std/tell"
#define KILL_CMD		"/cmds/std/kill"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"
