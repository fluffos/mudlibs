// Code of ShenZhou
// globals.h
// this file will be automatically included by the driver
// for XKX mudlib, by Xiang

// Important directories
#define INC_DIR		"/include/"
#define COMMAND_DIR	"/cmds/"
#define CONFIG_DIR	"/adm/etc/"
#define DATA_DIR	"/data/"
#define HELP_DIR	"/help/"
#define LOG_DIR		"/log/"
#define STORY_DIR	        "/clone/gift/"

// the following added by sdong, 3/30/2000
/*
#define OBJECT          "/std/object/ob"
#define SECURE_OBJECT   "/std/object/sec_ob"
#define USER            "/std/user"
#define BODY_BASE       "/std/body"
#define ROOM            "/std/room"
#define DAEMON          "/std/cmd_m"
#define SERVER          "/std/server"
#define WEAPON          "/std/weapon"
#define ARMOR           "/std/armor"
#define MONSTER         "/std/monster"
#define LIVING          "/std/living"
#define GHOST           "/std/ghost"
#define CONTAINER       "/std/container"
#define COINVALUE       "/std/coinvalue"
#define LOCK            "/std/lock"
#define DOORS           "/std/doors"
#define BOARD           "/std/board/bboard"
*/
// The next is to make save extension work for v20.*and v21.*
#ifndef __SAVE_EXTENSION__
#define __SAVE_EXTENSION__ SAVE_EXTENSION
#endif


// Daemons
#define ALIAS_D		"/adm/daemons/aliasd"
#define BAN_D		"/adm/daemons/band"
#define CHANNEL_D	"/adm/daemons/channeld"
#define CHAR_D		"/adm/daemons/chard"
#define CHINESE_D	"/adm/daemons/chinesed"
#define CLUB_D        "/adm/daemons/clubd" 
#define COMBAT_D	"/adm/daemons/combatd"
#define COMMAND_D	"/adm/daemons/commandd"
#define EMOTE_D		"/adm/daemons/emoted"
#define FINGER_D	"/adm/daemons/fingerd"
#define FTP_D		"/adm/daemons/ftpd"
#define INQUIRY_D	"/adm/daemons/inquiryd"
#define LOGIN_D		"/adm/daemons/logind"
#define MARRY_D		"/adm/daemons/marryd"
#define MONEY_D		"/adm/daemons/moneyd"
#define NATURE_D	"/adm/daemons/natured"
#define PIG_D		"/adm/daemons/pigd"
#define PROFILE_D	"/adm/daemons/profiled"
#define RANK_D		"/adm/daemons/rankd"
#define REGBAN_D	"/adm/daemons/regband"
#define REGI_D		"/adm/daemons/regid"
#define SECURITY_D	"/adm/daemons/securityd"
#define STORY_D	        "/adm/daemons/storyd"
#define UPDATE_D	"/adm/daemons/updated"
#define VIRTUAL_D	"/adm/daemons/virtuald"
#define WEAPON_D	"/adm/daemons/weapond"
#define CLASS_D(x)	("/kungfu/class/" + x)
#define SKILL_D(x)	("/kungfu/skill/" + x)
#define CONDITION_D(x)	("/kungfu/condition/" + x)
#define BEAST_D(x)	("/clone/beast/" + x)
#define DRUG_D(x)	("/clone/drug/" + x)
#define HERB_D(x)	("/clone/herb/" + x)

// Clonable/Non-inheritable Standard Objects
#define COIN_OB		"/clone/money/coin"
#define CORPSE_OB	"/clone/misc/corpse"
#define GOLD_OB		"/clone/money/gold"
#define LOGIN_OB	"/clone/user/login"
#define MASTER_OB	"/adm/single/master"
#define MAILBOX_OB	"/clone/misc/mailbox"
#define SILVER_OB	"/clone/money/silver"
#define SIMUL_EFUN_OB	"/adm/single/simul_efun"
#define USER_OB		"/clone/user/user"
#define VOID_OB		"/clone/misc/void"
#define F_VI            "/feature/vi"

// Inheritable Standard Objects
#define BANK		"/inherit/room/bank"
#define BULLETIN_BOARD	"/inherit/misc/bboard"
#define CHARACTER	"/inherit/char/char"
#define COMBINED_ITEM	"/inherit/item/combined"
#define EQUIP		"/inherit/misc/equip"
#define FERRY		"/inherit/room/ferry"
#define FORCE		"/inherit/skill/force"
#define HARBOR		"/inherit/room/harbor"
#define HOCKSHOP	"/inherit/room/hockshop"
#define ITEM		"/inherit/item/item"
#define LIQUID		"/inherit/food/liquid"
#define MONEY		"/inherit/item/money"
#define NPC		"/inherit/char/npc"
#define NPC_TRAINEE	"/inherit/char/trainee"
#define PILL		"/inherit/medicine/pill"
#define POWDER		"/inherit/medicine/powder"
#define ROOM		"/inherit/room/room"
#define SHIP		"/inherit/room/ship"
#define SKILL		"/inherit/skill/skill"
#define LOCALTIME   "/inherit/localtime"

// User IDs

#define ROOT_UID	"Root"
#define BACKBONE_UID	"Backbone"

// Features

#define F_ACTION		"/feature/action.lpc"
#define F_ALIAS			"/feature/alias.lpc"
#define F_APPRENTICE		"/feature/apprentice.lpc"
#define F_ATTACK		"/feature/attack.lpc"
#define F_ATTRIBUTE		"/feature/attribute.lpc"
#define F_AUTOLOAD		"/feature/autoload.lpc"
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
#define F_CONDITION		"/feature/condition.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_DEALER		"/feature/dealer.lpc"
#define F_EDIT			"/feature/edit.lpc"
#define F_EQUIP			"/feature/equip.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD			"/feature/food.lpc"
#define F_JIEBAI                "/feature/jiebai.lpc"
#define F_LIQUID		"/feature/liquid.lpc"
#define F_MARRY			"/feature/marry.lpc"
#define F_MASTER		"/inherit/char/master.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MORE			"/feature/more.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_MULTI			"/feature/multi.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_TRIGGER 		"/feature/trigger" 
#define F_VENDOR		"/feature/dealer.lpc"
#define F_SSERVER		"/feature/sserver.lpc"
#define F_UNIQUE		"/feature/unique.lpc"
#define F_CLONEABLE		"/feature/cloneable.lpc"

#define SAVE_OB			"/inherit/save.lpc"


//quest job add by buwu
#define NAME_D			"/adm/daemons/named"
#define TASK_D 			"/adm/daemons/taskd"

// SKIP BY SCATTER

// Heidian system add by FunBoo
#define HEIDIAN_DIR     "/clone/heidian/"
#define HEIDIAN_D       "/adm/daemons/heidiand"
#define F_HEIDIAN       "/feature/heidian.lpc"
#define F_HEIDIAN_HUOJI "/feature/heidian_huoji.lpc"
// End

/*



//added by Yujie
#define PAWN		"/feature/pawn"
#define F_BANKER		"/feature/banker"
#define QUEST_OB		"/feature/quest_list"
#define EXPLIST		"/clone/quest/explist"

//added by Yujie for TOPTEN
//#define TOPTEN_NEILI     "/topten/neili.txt"
#define TOPTEN_RICH 	"/topten/rich.txt"
#define TOPTEN_PKER     "/topten/pker.txt"
#define TOPTEN_EXP     "/topten/exp.txt"
#define TOPTEN_MUDAGE      "/topten/mudage.txt"


#define EXP_B "◎【神州】◎百大武学高手排行榜"
#define MUDAGE_B "◎【神州】◎百大老不死排行榜"

//#define NEILI_B "◎【神州】◎百大内力高手排行榜"


#define RICH_B "◎【神州】◎百大富豪排行榜"
#define PKER_B "◎【神州】◎百大杀手排行榜"
*/

// END OF SKIPPING



#define TOPTEN_D		"/adm/daemons/topd"

//#define TOPTEN_SOURCE       "/topten/source"
#define TOPTEN_DIR       "/topten/"
#define TOPTEN_FILE       "/topten/topten_file"
#define TOP_NAME       0
#define TOP_PROP       1
#define TOP_NAME_PROP       10
#define TOP_ID_NAMES       100
#define TOP_ID_PROPS       200
#define TOP_IDS       300
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS

// others
#define SAVE_EXTENSION ".o"
