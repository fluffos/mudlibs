// command.h

#define ADM_PATH ({"/cmds/adm/", "/cmds/wiz/", "/cmds/usr/","/cmds/npc/"})
#define WIZ_PATH ({"/cmds/wiz/", "/cmds/usr/", "/cmds/npc/" })

#define KIN_PATH ({ "/cmds/king/", "/cmds/min/" })
#define MIN_PATH ({ "/cmds/min/" })

#define PLR_PATH ({"/cmds/npc/", "/cmds/usr/"})
#define NPC_PATH ({"/cmds/npc/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD		"/cmds/npc/drop"
#define GET_CMD			"/cmds/npc/get"
#define GO_CMD			"/cmds/npc/go"
#define TELL_CMD		"/cmds/npc/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"
