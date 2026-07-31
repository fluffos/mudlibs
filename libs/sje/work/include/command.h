// command.h

#define ADM_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/", "/cmds/wiz/", "/cmds/arch/", "/cmds/ass/", "/cmds/adm/"})
#define ASS_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/", "/cmds/wiz/", "/cmds/ass/"})
#define ARC_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/", "/cmds/wiz/", "/cmds/arch/"})
#define WIZ_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/", "/cmds/wiz/"})
#define APR_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/", "/cmds/app/"})
#define IMM_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/imm/"})
#define KIN_PATH ({"/cmds/skill/","/cmds/std/","/cmds/usr/","/cmds/minister/","/cmds/king/"})
#define MIN_PATH ({"/cmds/skill/", "/cmds/std/","/cmds/usr/","/cmds/minister/"})
#define PLR_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define UNR_PATH ({"/cmds/std/"})
#define NPC_PATH ({"/cmds/std/", "/cmds/skill/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD                "/cmds/std/drop"
#define GET_CMD                 "/cmds/std/get"
#define GO_CMD                  "/cmds/std/go"
#define TELL_CMD                "/cmds/std/tell"
#define UPTIME_CMD              "/cmds/usr/uptime"
#define WHO_CMD                 "/cmds/usr/who"
