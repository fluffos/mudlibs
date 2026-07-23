// command.h



#define ADM_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/ang/", "/cmds/wiz/", "/cmds/app/", "/cmds/gen/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})

#define SAG_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/ang/", "/cmds/wiz/", "/cmds/app/", "/cmds/gen/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})

#define ARC_PATH ({"/cmds/arch/", "/cmds/ang/", "/cmds/wiz/", "/cmds/app/", "/cmds/gen/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})

#define ANG_PATH ({"/cmds/ang/", "/cmds/wiz/", "/cmds/app/", "/cmds/gen/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})

#define WIZ_PATH ({"/cmds/wiz/", "/cmds/app/", "/cmds/gen/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})

#define APP_PATH ({"/cmds/app/", "/cmds/gen/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})

#define GEN_PATH ({"/cmds/gen/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})

#define IMM_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})

#define PLR_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})

#define UNR_PATH ({"/cmds/usr/", "/cmds/std/"})

#define NPC_PATH ({"/cmds/std/", "/cmds/skill/"})



// These are command objects that will also be called in those

// non-player objects.

#define ACCEPT_CMD              "/cmds/std/accept"
#define DAUB_CMD                "/cmds/std/daub"
#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"
#define LOOK_CMD		"/cmds/std/look"
#define REMOVE_CMD		"/cmds/std/remove"
