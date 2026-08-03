// command.h

#define ADM_PATH ({"/cmds/adm/","/cmds/arch/","/cmds/wiz/","/cmds/apr/","/cmds/imm/","/cmds/std/"})
#define ARCH_PATH ({"/cmds/arch/","/cmds/wiz/","/cmds/apr/","/cmds/imm/","/cmds/std/"})
#define WIZ_PATH ({"/cmds/wiz/","/cmds/apr/","/cmds/imm/","/cmds/std/"})
#define APR_PATH ({"/cmds/apr/","/cmds/imm/","/cmds/std/"})
#define IMM_PATH ({"/cmds/imm/","/cmds/std/"})
#define PLR_PATH ({"/cmds/std/"})
#define NPC_PATH ({"/cmds/std/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/std/uptime"
#define WHO_CMD			"/cmds/std/who"
