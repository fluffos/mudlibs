#ifndef _GLOBALS_H_
#define _GLOBALS_H_

// globals.h
// this file will be automatically included by the driver
#define private protected

// Improve function
#define move_to_ob(ob)  move(resolve_path(__DIR__, ob))
#define new_ob(str)     new(resolve_path(__DIR__, str))
#define replace_program(x)

// Important directories
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR      "/adm/etc/"
#define DATA_DIR        "/data/"
#define HELP_DIR        "/help/"
#define INC_DIR         "/include/"
#define LOG_DIR         "/log/"
#define SAVE_EXTENSION  ".o"

// Daemons
#define ALIAS_D         "/adm/daemons/aliasd"
#define BAN_D           "/adm/daemons/band"
#define CHANNEL_D       "/adm/daemons/channeld"
#define CHAR_D          "/adm/daemons/chard"
#define CHINESE_D       "/adm/daemons/chinesed"
#define COMBAT_D        "/adm/daemons/combatd"
#define COMMAND_D       "/adm/daemons/commandd"
#define EMOTE_D         "/adm/daemons/emoted"
#define FINGER_D        "/adm/daemons/fingerd"
#define FTP_D           "/adm/daemons/ftpd"
#define INQUIRY_D       "/adm/daemons/inquiryd"
#define IP_D		"/adm/daemons/ipd"
#define LOG_D		"/adm/daemons/logd"
#define LOGIN_D         "/adm/daemons/logind"
#define MONEY_D         "/adm/daemons/moneyd"
#define MAP_D         	"/adm/daemons/mapd"
#define NATURE_D        "/adm/daemons/natured"
#define PIG_D           "/adm/daemons/pigd"
#define PROFILE_D       "/adm/daemons/profiled"
#define RANK_D          "/adm/daemons/rankd"
#define SECURITY_D      "/adm/daemons/securityd"
#define SMTP_D          "/adm/daemons/smtpd"
#define TASK_D          "/adm/daemons/taskd"
#define UPDATE_D        "/adm/daemons/updated"
#define VIRTUAL_D       "/adm/daemons/virtuald"
#define WEAPON_D        "/adm/daemons/weapond"
#define QUEST_D  	"/adm/daemons/questd"

//directories
#define ARMOR_D(x)      ("/clone/armor/" + x)
#define BINGQI_D(x)     ("/clone/weapon/" + x)
#define CLASS_D(x)      ("/kungfu/class/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
#define FOOD_D(x)       ("/clone/food/" + x)
#define MEDICINE_D(x)   ("/clone/medicine/" + x)
#define MISC_D(x)       ("/clone/misc/" + x)
#define NPC_D(x)        ("/clone/npc/" + x)
#define SKILL_D(x)      ("/kungfu/skill/" + x)

// Clonable/Non-inheritable Standard Objects
#define COIN_OB         "/clone/money/coin"
#define CORPSE_OB       "/clone/misc/corpse"
#define EXPLORE_OB       "/clone/misc/explore_ob"
#define GOLD_OB         "/clone/money/gold"
#define LOADUSER_OB     "/clone/user/loaduser"
#define LOGIN_OB        "/clone/user/login"
#define MAILBOX_OB      "/clone/misc/mailbox"
#define MASTER_OB       "/adm/single/master"
#define SILVER_OB       "/clone/money/silver"
#define SIMUL_EFUN_OB   "/adm/single/simul_efun"
#define USER_OB         "/clone/user/user"
#define VOID_OB         "/clone/misc/void"

// Inheritable Standard Objects
#define BANK            "/inherit/room/bank"
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define CHARACTER       "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP           "/inherit/misc/equip"
#define FIRE_ITEM       "/inherit/item/fire_item"
#define FORCE           "/inherit/skill/force"
#define HOCKSHOP        "/inherit/room/hockshop"
#define ITEM            "/inherit/item/item"
#define LIQUID          "/inherit/food/liquid"
#define MONEY           "/inherit/item/money"
#define NPC             "/inherit/char/npc"
#define PILL            "/inherit/medicine/pill"
#define POWDER          "/inherit/medicine/powder"
#define ROOM            "/inherit/room/room"
#define SKILL           "/inherit/skill/skill"

// User IDs
#define BACKBONE_UID    "Backbone"
#define ROOT_UID        "Root"

// Features
#define F_ACTION                "/feature/action.lpc"
#define F_ALIAS                 "/feature/alias.lpc"
#define F_APPRENTICE            "/feature/apprentice.lpc"
#define F_ATTACK                "/feature/attack.lpc"
#define F_ATTRIBUTE             "/feature/attribute.lpc"
#define F_AUTOLOAD              "/feature/autoload.lpc"
#define F_BANKER                "/feature/banker.lpc"
#define F_BOAT                  "/feature/boat.lpc"
#define F_CLEAN_UP              "/feature/clean_up.lpc"
#define F_COMMAND               "/feature/command.lpc"
#define F_CONDITION             "/feature/condition.lpc"
#define F_DAMAGE                "/feature/damage.lpc"
#define F_DBASE                 "/feature/dbase.lpc"
#define F_DEALER                "/feature/dealer.lpc"
#define F_EDIT                  "/feature/edit.lpc"
#define F_EQUIP                 "/feature/equip.lpc"
#define F_FINANCE               "/feature/finance.lpc"
#define F_FOOD                  "/feature/food.lpc"
#define F_LINEUP                "/feature/lineupquery.lpc"
#define F_LIQUID                "/feature/liquid.lpc"
#define F_MASTER                "/inherit/char/master.lpc"
#define F_MESSAGE               "/feature/message.lpc"
#define F_MORE                  "/feature/more.lpc"
#define F_MOVE                  "/feature/move.lpc"
#define F_NAME                  "/feature/name.lpc"
#define F_PILL                  "/feature/pill.lpc"
#define F_REPORT                "/feature/report.lpc"
#define F_SAVE                  "/feature/save.lpc"
#define F_SKILL                 "/feature/skill.lpc"
#define F_SSERVER               "/feature/sserver.lpc"
#define F_TASK                  "/feature/task.lpc"
#define F_TEAM                  "/feature/team.lpc"
#define F_TREEMAP               "/feature/treemap.lpc"
#define F_UNIQUE                "/feature/unique.lpc"
#define F_VENDOR                "/feature/vendor.lpc"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS

// Mathematic
#define ABS(x)                  ((x) >= 0 ? (x) : -(x))
#define MAX(a, b)               ((a) > (b) ? (a) : (b))
#define MIN(a, b)               ((a) < (b) ? (a) : (b))
#define SGN(x)                  ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
#define SWAP(x, y)		(x ^= y ^= x ^= y)

#endif
