// command.h

#define ADM_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/", "/cmds/xmud/"})
#define ARC_PATH ({"/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/", "/cmds/xmud/"})
#define WIZ_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/wiz/", "/cmds/xmud/"})
#define APR_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/wiz/", "/cmds/xmud/"})
#define IMM_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/xmud/"})
#define PLR_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/", "/cmds/xmud/"})
#define UNR_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/xmud/"})
#define NPC_PATH ({"/cmds/std/", "/cmds/skill/", "/cmds/xmud/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"
#define LOOK_CMD		"/cmds/std/look"
#define REMOVE_CMD		"/cmds/std/remove"
