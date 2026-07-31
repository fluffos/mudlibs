// command.h
#define ZHU_PATH ({"/cmds/zhu/", "/cmds/adm/", "/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/", "/cmds/app/"})
#define ADM_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/", "/cmds/app/"})
#define ARC_PATH ({"/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/", "/cmds/app/"})
#define WIZ_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/wiz/", "/cmds/app/"})
#define APR_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/app/"})
#define IMM_PATH ({"/cmds/imm/",  "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define PLR_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define UNR_PATH ({"/cmds/usr/", "/cmds/std/"})
#define NPC_PATH ({"/cmds/std/", "/cmds/skill/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"
#define LOOK_CMD		"/cmds/std/look"
#define FORCE_CMD               "/cmds/arch/force"
#define NEWS_CMD                "/cmds/usr/news"
#define ALLIP_CMD              "/cmds/usr/allowip"
#define REMOVE_CMD		"/cmds/std/remove"
