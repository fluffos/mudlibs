// command.h

#define ADM_PATH ({"/cmds/adm/","/cmds/arch/","/cmds/wiz/","/cmds/apr/","/cmds/imm/","/cmds/usr/","/cmds/std/","/cmds/skill/"})
#define ARC_PATH ({"/cmds/arch/","/cmds/wiz/","/cmds/apr/","/cmds/imm/","/cmds/usr/","/cmds/std/","/cmds/skill/"})
#define WIZ_PATH ({"/cmds/wiz/","/cmds/apr/","/cmds/imm/","/cmds/usr/","/cmds/std/","/cmds/skill/"})
#define APR_PATH ({"/cmds/apr/","/cmds/imm/","/cmds/usr/","/cmds/std/","/cmds/skill/"})
#define IMM_PATH ({"/cmds/imm/","/cmds/usr/","/cmds/std/","/cmds/skill/"})
#define PLR_PATH ({"/cmds/usr/","/cmds/std/","/cmds/skill/"})
#define UNR_PATH ({"/cmds/usr/","/cmds/std/"})
#define NPC_PATH ({"/cmds/std/","/cmds/skill/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD                "/cmds/std/drop"
#define GET_CMD                 "/cmds/std/get"
#define GO_CMD                  "/cmds/std/go"
#define TELL_CMD                "/cmds/std/tell"
#define UPTIME_CMD              "/cmds/usr/uptime"
#define WHO_CMD                 "/cmds/usr/who"
#define LOOK_CMD                "/cmds/std/look"
#define REMOVE_CMD              "/cmds/std/remove"
#define MUDLIST_CMD             "/cmds/std/mudlist"
#define NEWS_CMD                "/cmds/usr/news"
#define DAUB_CMD		"/cmds/std/daub"
#define EAT_CMD			"/cmds/std/eat"
#define DRINK_CMD		"/cmds/std/drink"
#define QUIT_CMD		"/cmds/usr/quit"
