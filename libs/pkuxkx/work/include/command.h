// command.h

#define ADM_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/wiz/", "/cmds/app/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/","/cmds/stunt/"})
#define ARC_PATH ({"/cmds/arch/", "/cmds/wiz/", "/cmds/app/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/","/cmds/stunt/"})
#define WIZ_PATH ({"/cmds/wiz/", "/cmds/app/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/","/cmds/stunt/"})
#define APR_PATH ({"/cmds/app/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/","/cmds/stunt/"})
#define IMM_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/","/cmds/stunt/"})
#define GUD_PATH ({"/cmds/guider/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/","/cmds/stunt/"})
#define PLR_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/skill/","/cmds/stunt/"})
#define UNR_PATH ({"/cmds/usr/", "/cmds/std/","/cmds/stunt/"})
#define NPC_PATH ({"/cmds/std/", "/cmds/skill/","/cmds/stunt/"})
#define NON_PATH ({})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"

string process_shell(string str);

string process_shell_str(string arg);

mixed process_shell(string arg);


