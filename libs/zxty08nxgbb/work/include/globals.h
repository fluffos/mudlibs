// this file will be automatically included by the driver
// for XKX mudlib, by Xiang
#include "ansi.h"
#include  "tomud.h"

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected static
#endif


// Important directories
#define DUMP_DIR        "/dump/"
#define INC_DIR     "/include/"
#define COMMAND_DIR "/cmds/"
#define CONFIG_DIR  "/adm/etc/"
#define DATA_DIR    "/data/"
#define HELP_DIR    "/doc/"
#define ITEM_DIR        "/clone/item/data/"
#define LOG_DIR     "/log/"
#define SHOP_DIR        "/d/shop/"
#define EVENT_DIR       "/adm/daemons/event/"
//add for job
#define MIS_REW     "/adm/daemons/MissionReward"

// Daemons
#define ALIAS_D     "/adm/daemons/aliasd"
#define BAN_D       "/adm/daemons/band"
#define BR_D     "/adm/daemons/brd"
#define BALANCE_D       "/adm/daemons/balanced.c"
#define BACKUP_D     "/adm/daemons/backupd"
#define CONFIG_D     "/adm/daemons/configd"
#define IP_D                    "/adm/daemons/ipd" 
#define CPU_D     "/adm/daemons/cpud"
#define ITEM_D          "/adm/daemons/itemd"
#define NEWS_D    "/adm/daemons/newsd"
#define VERSION_D     "/adm/daemons/versiond"
#define CHANNEL_D   "/adm/daemons/channeld"
#define CHAR_D      "/adm/daemons/chard"
#define CHINESE_D   "/adm/daemons/chinesed"
#define COMBAT_D    "/adm/daemons/combatd"
#define COMMAND_D   "/adm/daemons/commandd"
#define CHOOSE_D     "/adm/daemons/choosed"
#define DBASE_D         "/adm/daemons/dbased"
#define EMOTE_D     "/adm/daemons/emoted"
#define EVENT_D     "/adm/daemons/eventd"
#define EXAMINE_D   "/adm/daemons/examined"
#define FINGER_D    "/adm/daemons/fingerd"
#define CLOSE_D   "/adm/daemons/closed"
#define INQUIRY_D   "/adm/daemons/inquiryd"
//#define SHOP_D   "/adm/daemons/shopd"
#define LOGIN_D     "/adm/daemons/logind"
#define RNAME_D		"/adm/daemons/rnamed"
#define MONEY_D     "/adm/daemons/moneyd"
#define MEMORY_D     "/adm/daemons/memoryd"
#define MAP_D     "/adm/daemons/mapd"
#define MESSAGE_D       "/adm/daemons/network/messaged"
#define NATURE_D    "/adm/daemons/natured"
#define NPC_D     "/adm/daemons/npcd"
#define NAME_D     "/adm/daemons/named"
#define PIG_D       "/adm/daemons/pigd"
#define PROFILE_D   "/adm/daemons/profiled"
#define PK_D     "/adm/daemons/pkd"
#define RANK_D      "/adm/daemons/rankd"
#define SECURITY_D  "/adm/daemons/securityd"
#define STORY_D     "/adm/daemons/storyd"
// #define SECURITY_D  "/adm/daemons/securd"
#define UPDATE_D    "/adm/daemons/updated"
#define VIRTUAL_D   "/adm/daemons/virtuald"
#define MONITOR_D   "/adm/daemons/monitord"
#define WEAPON_D    "/adm/daemons/weapond"
#define LANGUAGE_D    "/adm/daemons/languaged"
#define STATUS_D    "/adm/daemons/statud"
/*
#define TASK_D        "/adm/daemons/questd"
#define CRON_D            "/adm/daemons/cron"
*/
// Added for questing
// by Hop, 1997.05.16
#define QUEST_D(x)  ("/quest/qlist" + x)
// End of appendence
#define CLASS_D(x)  ("/kungfu/class/" + x)
#define ARMOR_D(x)	("/clone/job/" + x)
#define BINGQI_D(x)	("/clone/job2/" + x)
#define SKILL_D(x)  ("/kungfu/skill/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
// Clonable/Non-inheritable Standard Objects
#define CORPSE_OB   "/clone/misc/corpse"
#define LOGIN_OB    "/clone/user/login"
#define MASTER_OB   "/adm/obj/master"
#define MAILBOX_OB  "/clone/misc/mailbox"
#define THGOLD_OB   "/clone/money/thousand-gold" 
#define THCASH_OB   "/clone/money/thousand-cash"
#define GOLD_OB     "/clone/money/gold"
#define SILVER_OB   "/clone/money/silver"
#define COIN_OB     "/clone/money/coin"
#define SIMUL_EFUN_OB   "/adm/obj/simul_efun"
#define USER_OB     "/clone/user/user"
#define VOID_OB     "/clone/misc/void"
// Inheritable Standard Objects
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define BULLETIN_JBOARD "/inherit/misc/jboard"
#define CHARACTER   "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP       "/inherit/misc/equip"
#define FORCE       "/inherit/skill/force"
#define HOCKSHOP    "/inherit/room/hockshop"
#define ITEM        "/inherit/item/item"
#define LIQUID      "/inherit/food/liquid"
#define MONEY       "/inherit/item/money"
#define NPC     "/inherit/char/npc"
#define PILL        "/inherit/medicine/pill"
#define POWDER      "/inherit/medicine/powder"
#define ROOM        "/inherit/room/room"
#define SKILL       "/inherit/skill/skill"
#define SELL_SALT   "/inherit/char/sell_salt"
#define NPC_SAVE        "/inherit/char/npcsave"
#define BHNPC        "/inherit/misc/bhnpc.c"
#define BANGHUI        "/inherit/misc/banghui"
#define WAITER          "/inherit/char/waiter"
#define SHOP            "/inherit/room/shop"
#define FERRY            "/inherit/room/ferry"

#define QUEST            "/inherit/quest"

// #define USER-ROOM   "/inherit/room/user_room"
// User IDs
#define ROOT_UID    "Root"
#define BACKBONE_UID    "Backbone"
// Features
#define F_ACTION        "/feature/action.c"
#define F_ALIAS         "/feature/alias.c"
#define F_APPRENTICE        "/feature/apprentice.c"
#define F_ATTACK        "/feature/attack.c"
#define F_ATTRIBUTE     "/feature/attribute.c"
#define F_AUTOLOAD      "/feature/autoload.c"
#define F_CLEAN_UP      "/feature/clean_up.c"
#define F_COMMAND       "/feature/command.c"
#define F_CONDITION     "/feature/condition.c"
#define F_DAMAGE        "/feature/damage.c"
#define F_DBASE         "/feature/dbase.c"
#define F_DEALER        "/feature/dealer.c"
#define F_TYDEALER        "/feature/tydealer.c"
#define F_TYDEALER1        "/feature/ty_dealer.c"
#define F_DEALERVIP        "/feature/dealervip.c"
#define F_DEALER1        "/feature/dealer1.c"
#define F_EDIT          "/feature/edit.c"
#define F_EQUIP         "/feature/equip.c"
#define F_FINANCE       "/feature/finance.c"
#define F_FOOD          "/feature/food.c"
#define F_LIQUID        "/feature/liquid.c"
#define F_MASTER        "/inherit/char/master.c"
#define F_MESSAGE       "/feature/message.c"
#define F_MORE          "/feature/more.c"
#define F_MOVE          "/feature/move.c"
#define F_NAME          "/feature/name.c"
#define F_SAVE          "/feature/save.c"
#define F_OBSAVE        "/feature/obsave.c"
#define F_NOCLONE       "/feature/noclone.c"
#define F_SHADOW        "/feature/shadow.c"
#define F_BACKUP     "/feature/backup.c"
#define F_ITEMMAKE     "/feature/itemmake.c"
#define F_SKILL         "/feature/skill.c"
#define F_TEAM          "/feature/team.c"
#define F_TREEMAP       "/feature/treemap.c"
#define F_VENDOR        "/feature/dealer.c"
#define F_SSERVER       "/feature/sserver.c"
#define F_UNIQUE        "/feature/unique.c"
#define F_BANKER        "/feature/banker.c"

#define SKILL_MODEL_UNARMED    "/meskill/skill_model_unarmed.c"

#define SKILL_MODEL_WEAPON     "/meskill/skill_model_weapon.c"
#define SKILL_MODEL_DEFAULT    "/meskill/skill_model_default.c"
#define F_VENDOR_SALE           "/feature/vendor_sale.c"
#define F_BVENDOR        "/feature/vendor.c"
#define ABS(x)		((x) >= 0 ? (x) : -(x))
#define MAX(a, b)	((a) > (b) ? (a) : (b))
#define MIN(a, b)	((a) < (b) ? (a) : (b))
#define SGN(x)		((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
#define SWAP(x, y)	(x ^= y ^= x ^= y)

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.
#undef PROFILE_COMMANDS

