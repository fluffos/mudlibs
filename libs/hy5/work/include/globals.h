// globals.h
// this file will be automatically included by the driver
// for XKX mudlib, by Xiang

#define SAVE_EXTENSION __SAVE_EXTENSION__ 
#define save_binary
#pragma optimize
#pragma save_binary

// Important directories
#define INC_DIR		"/include/"
#define COMMAND_DIR	"/cmds/"
#define CONFIG_DIR	"/adm/etc/"
#define DATA_DIR	"/data/"
#define HELP_DIR	"/help/"
#define LOG_DIR		"/log/"
#define STORY_DIR       "/clone/gift/"
// Daemons
#define BR_D		"/adm/daemons/brd"
#define ALIAS_D		"/adm/daemons/aliasd"
#define BAN_D		"/adm/daemons/band"
#define CHANNEL_D	"/adm/daemons/channeld"
#define CHAR_D		"/adm/daemons/chard"
#define CHINESE_D	"/adm/daemons/chinesed"
#define COMBAT_D	"/adm/daemons/combatd"
#define COMMAND_D	"/adm/daemons/commandd"
#define EMOTE_D		"/adm/daemons/emoted"
#define FINGER_D	"/adm/daemons/fingerd"
#define FTP_D		"/adm/daemons/ftpd"
#define INQUIRY_D	"/adm/daemons/inquiryd"
#define LOGIN_D		"/adm/daemons/logind"
#define MONEY_D		"/adm/daemons/moneyd"
#define NATURE_D	"/adm/daemons/natured"
#define PIG_D		"/adm/daemons/pigd"
#define PROFILE_D	"/adm/daemons/profiled"
#define RANK_D		"/adm/daemons/rankd"
#define SECURITY_D      "/adm/daemons/securd"
#define TASK_D  	"/adm/daemons/questd"
#define UPDATE_D	"/adm/daemons/updated"
#define VIRTUAL_D	"/adm/daemons/virtuald"
#define WEAPON_D	"/adm/daemons/weapond"
#define WHO_D		"/adm/daemons/whod"
#define STATUS_D	"/adm/daemons/statusd"
#define STORY_D	        "/adm/daemons/storyd"
#define CONVERT_D       "/adm/daemons/convertd"
#define LANGUAGE_D      "/adm/daemons/languaged"
#define BACKUP_DIR      "/backup/"
#define FAMILY_D        "/adm/daemons/familyd"
#define SCHEDULE_D         "/adm/daemons/scheduled"
#define VRM_SERVER		"/adm/daemons/vrm_server"
#define MEMBER_D		"/adm/daemons/memoryd"
#define FUBEN_D		"/adm/daemons/fubend"
#define BG_D		"/adm/daemons/bgift"
#define TIME_D		"/adm/daemons/timed"

#define CLASS_D(x)	("/kungfu/class/" + x)
#define SKILL_D(x)	("/kungfu/skill/" + x)
#define CONDITION_D(x)	("/kungfu/condition/" + x)

// 高手排行板
#define RICHMAN_D       "/adm/daemons/tenrichmand"
#define GAOSHOU_D       "/adm/daemons/tengaoshoud"
#define STOCK_D       "/adm/daemons/stockd"

//自造武功
#define SKILL_MODEL_UNARMED    "/maxim/skill_model_unarmed.lpc"
#define SKILL_MODEL_WEAPON     "/maxim/skill_model_weapon.lpc"
#define SKILL_MODEL_DEFAULT    "/maxim/skill_model_default.lpc"

// Added for questing
// by Hop, 1997.05.16
#define QUESTH_D(x)	("/quest/qhlist" + x)
#define QUESTS_D(x)	("/quest/qslist" + x)
#define QUESTW_D(x)	("/quest/qwlist" + x)

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

// Inheritable Standard Objects
#define BANK		"/inherit/room/bank"
#define BULLETIN_BOARD	"/inherit/misc/bboard"
#define CHARACTER	"/inherit/char/char"
#define COMBINED_ITEM	"/inherit/item/combined"
#define EQUIP		"/inherit/misc/equip"
#define FORCE		"/inherit/skill/force"
#define HOCKSHOP	"/inherit/room/hockshop"
#define ITEM		"/inherit/item/item"
#define LIQUID		"/inherit/food/liquid"
#define MONEY		"/inherit/item/money"
#define NPC		"/inherit/char/npc"
#define BOSS		"/inherit/char/boss"
#define PILL		"/inherit/medicine/pill"
#define POWDER		"/inherit/medicine/powder"
#define ROOM		"/inherit/room/room"
#define SKILL		"/inherit/skill/skill"

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
#define F_BANKER		"/feature/banker.lpc"
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
#define F_CONDITION		"/feature/condition.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_DEALER		"/feature/dealer.lpc"
#define F_EDIT			"/feature/edit.lpc"
#define F_ENCODING              "/feature/encoding.lpc"
#define F_EQUIP			"/feature/equip.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD			"/feature/food.lpc"
#define F_LIQUID		"/feature/liquid.lpc"
#define F_MASTER		"/inherit/char/master.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MORE			"/feature/more.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_VENDOR		"/feature/dealer.lpc"
#define F_SSERVER		"/feature/sserver.lpc"
#define F_UNIQUE		"/feature/unique.lpc"
#define F_VI                    "/feature/vi"
// for gem system(by xbd)
#define F_GEMS			"/feature/gems.lpc"
#define S_WEAPON		"/inherit/gems/weapon.lpc"
#define S_ROBE			"/inherit/gems/robe.lpc"
#define S_RING			"/inherit/gems/ring.lpc"
#define F_ANA			  "/feature/anamichi.lpc"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
