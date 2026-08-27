// command.h

#define ADM_PATH ({"/cmds/std/","/cmds/usr/","/cmds/imm/","/cmds/appr/","/cmds/wiz/","/cmds/arch/","/cmds/adm/","/cmds/susr/" })
#define ARC_PATH ({"/cmds/std/","/cmds/usr/","/cmds/imm/","/cmds/appr/","/cmds/wiz/","/cmds/arch/","/cmds/susr/"})
#define WIZ_PATH ({"/cmds/std/","/cmds/usr/","/cmds/imm/","/cmds/appr/","/cmds/wiz/","/cmds/susr/" })
#define APR_PATH ({"/cmds/std/","/cmds/usr/","/cmds/imm/","/cmds/appr/","/cmds/susr/"})
#define IMM_PATH ({"/cmds/std/","/cmds/usr/","/cmds/imm/" ,"/cmds/susr/"})
#define SPL_PATH ({"/cmds/std/","/cmds/usr/","/cmds/susr/"})
#define PLR_PATH ({"/cmds/std/","/cmds/usr/"})
#define NPC_PATH ({"/cmds/std/"})
// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"
#define REMOVE_CMD		"/cmds/std/remove"
#define UNWIELD_CMD		"/cmds/std/unwield"
#define RIDE_CMD		"/cmds/std/ride"
#define RECALL_CMD		"/cmds/usr/recall"
#define LOOK_CMD		"/cmds/std/look"
#define SNOOP_CMD		"/cmds/wiz/snoop"
#define QUIT_CMD		"/cmds/std/quit"
#define UPDATE_CMD		"/cmds/appr/update"
#define EDIT_CMD		"/cmds/appr/edit"
