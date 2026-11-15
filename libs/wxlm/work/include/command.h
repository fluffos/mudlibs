// command.h

#define COMMON_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/wiz/", "/cmds/app/", "/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/quest/", "/cmds/beast_master/"})

#define ADM_PATH COMMON_PATH
#define ARC_PATH COMMON_PATH
#define WIZ_PATH COMMON_PATH
#define APR_PATH COMMON_PATH
#define IMM_PATH COMMON_PATH

#define PLR_PATH ({"/cmds/skill/", "/cmds/std/", "/cmds/usr/", "/cmds/app/", "/cmds/imm/", "/cmds/quest/", "/cmds/beast_master/"})
#define UNR_PATH ({"/cmds/usr/", "/cmds/std/", "/cmds/quest/", "/cmds/beast_master/"})
#define NPC_PATH ({"/cmds/std/", "/cmds/skill/","/cmds/usr/", "/cmds/quest/", "/cmds/beast_master/"})//新增npc可以执行usr目录的命令

#define PNE_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/quest/"})

// These are command objects that will also be called in those
// non-player objects.
#define ACCEPT_CMD	      "/cmds/std/accept"
#define DAUB_CMD		"/cmds/std/daub"
#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define	HELP_CMD		"/cmds/usr/help"
#define LOOK_CMD		"/cmds/std/look"
#define QUIT_CMD		"/cmds/usr/quit"
#define REMOVE_CMD		"/cmds/std/remove"
#define REPLY_CMD	       "/cmds/std/reply"
#define SKIP_CMD		"/cmds/usr/skip"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WEAR_CMD		"/cmds/std/wear"
#define WHO_CMD			"/cmds/usr/who"
#define WIELD_CMD	       "/cmds/std/wield"
#define XUE_CMD		 "/cmds/skill/learn"

// wizard command object
#define EXAMINE_CMD	     "/cmds/arch/examine"
