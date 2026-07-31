// globals.h
// this file will be automatically included by the driver

#pragma save_binary

#ifndef __SENSIBLE_MODIFIERS__
#endif

// Important directories
#define BACKUP_DIR      "/backup/"
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR      "/adm/etc/"
#define DATA_DIR        "/data/"
#define DUMP_DIR        "/dump/"
#define EVENT_DIR       "/adm/daemons/event/"
#define HELP_DIR        "/help/"
#define INC_DIR         "/include/"
#define ITEM_DIR        DATA_DIR "item/"
#define LOG_DIR         "/log/"
#define QUEST_DIR       "/adm/daemons/quest/"
#define	SHADOW_DIR	"/shadow/"
#define STORY_DIR       "/adm/daemons/story/"
#define TEMP_DIR        "/temp/"
#define WORK_DIR        "/adm/daemons/work/"

// Daemons
#define ALIAS_D         "/adm/daemons/aliasd"
#define BAN_D           "/adm/daemons/band"
#define BACKUP_D        "/adm/daemons/backupd"
#define BUNCH_D         "/adm/daemons/bunchd"
#define BUSINESS_D      "/adm/daemons/businessd.lpc"
#define CHANNEL_D       "/adm/daemons/channeld"
#define CHAR_D          "/adm/daemons/chard"
#define CHINESE_D       "/adm/daemons/chinesed"
#define CLOSE_D         "/adm/daemons/closed"
#define COMBAT_D        "/adm/daemons/combatd"
#define COMMAND_D       "/adm/daemons/commandd"
#define CONFIG_D        "/adm/daemons/configd"
#define CPU_D           "/adm/daemons/cpud"
#define DBASE_D         "/adm/daemons/dbased"
#define DEFEND_D        "/adm/daemons/defend"
#define EMOTE_D         "/adm/daemons/emoted"
#define EVENT_D         "/adm/daemons/eventd"
#define EXAMINE_D       "/adm/daemons/examined"
#define FAMILY_D        "/adm/daemons/familyd"
#define FINGER_D        "/adm/daemons/fingerd"
#define FTP_D           "/adm/daemons/ftpd"
#define GIFT_D          "/adm/daemons/giftd"
#define GROUP_D         "/adm/daemons/groupd"
#define INQUIRY_D       "/adm/daemons/inquiryd"
#define ITEM_D          "/adm/daemons/itemd"
#define LANGUAGE_D      "/adm/daemons/languaged"
#define LEAGUE_D        "/adm/daemons/leagued"
#define LOGIN_D         "/adm/daemons/logind"
#define	MAIL_D		"/adm/daemons/maild"
#define	MAP_D		"/adm/daemons/mapd"
#define MASTER_D        "/adm/daemons/masterd"
#define	MESSAGE_D	"/adm/daemons/network/messaged"
#define MONEY_D         "/adm/daemons/moneyd"
#define NAME_D          "/adm/daemons/named"
#define NATURE_D        "/adm/daemons/natured"
#define NEWS_D          "/adm/daemons/newsd"
#define NPC_D           "/adm/daemons/npcd"
#define PIG_D           "/adm/daemons/pigd"
#define PK_D            "/adm/daemons/pkd"
#define PROFILE_D       "/adm/daemons/profiled"
#define QUEST_D         "/adm/daemons/questd"
#define RANK_D          "/adm/daemons/rankd"
#define SECURITY_D      "/adm/daemons/securityd"
#define SLOUGH_D        "/adm/daemons/sloughd"
#define STORY_D         "/adm/daemons/storyd"
#define TASK_D          "/adm/daemons/taskd"
#define ULTRA_D         "/adm/daemons/ultrad"
#define UPDATE_D        "/adm/daemons/updated"
#define VERSION_D       "/adm/daemons/versiond"
#define VIRTUAL_D       "/adm/daemons/virtuald"
#define WAR_D           "/adm/daemons/ward"
#define WEAPON_D        "/adm/daemons/weapond"
#define WEEKLY_D        "/adm/daemons/weekly_d"
#define WORK_D          "/adm/daemons/workd"

#define CLASS_D(x)      ("/kungfu/class/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
#define SKILL_D(x)      ("/kungfu/skill/" + x)
#define SPECIAL_D(x)    ("/kungfu/special/" + x)

// Clonable/Non-inheritable Standard Objects
#define COIN_OB         "/clone/money/coin"
#define CORPSE_OB       "/clone/misc/corpse"
#define GOLD_OB         "/clone/money/gold"
#define LOGIN_OB        "/clone/user/login"
#define MASTER_OB       "/adm/single/master"
#define MAILBOX_OB      "/clone/misc/mailbox"
#define SILVER_OB       "/clone/money/silver"
#define SIMUL_EFUN_OB   "/adm/single/simul_efun"
#define TEMP_OB         "/clone/misc/temp"
#define USER_OB         "/clone/user/user"
#define VOID_OB         "/clone/misc/void"

// Inheritable Standard Objects
#define AREA_ROOM       "/inherit/room/arearoom"
#define BANK            "/inherit/room/bank"
#define BABY           "/inherit/char/baby"
#define BUILD_ROOM      "/inherit/room/buildroom"
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define BUNCH_NPC       "/inherit/char/b_npc"
#define CHALLENGER      "/inherit/char/challenger"
#define CHARACTER       "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP           "/inherit/misc/equip"
#define FIGHTER         "/inherit/char/fighter"
#define FORCE           "/inherit/skill/force"
#define HOCKSHOP        "/inherit/room/hockshop"
#define ILLNESS         "/inherit/condition/illness"
#define ITEM            "/inherit/item/item"
#define KNOWER          "/inherit/char/knower"
#define LIQUID          "/inherit/food/liquid"
#define MONEY           "/inherit/item/money"
#define NPC             "/inherit/char/npc"
#define	PIG_ROOM	"/inherit/room/pigroom"
#define PILL            "/inherit/medicine/pill"
#define POISON          "/inherit/condition/poison"
#define POISON_INSECT   "/inherit/char/insect"
#define POWDER          "/inherit/medicine/powder"
#define PRIVATE_ROOM    "/inherit/room/privateroom"
#define QUARRY          "/inherit/char/quarry"
#define ROOM            "/inherit/room/room"
#define SHAOLIN_SKILL   "/inherit/skill/shaolin"
#define SKILL           "/inherit/skill/skill"
#define SMITH           "/inherit/char/smith" 
#define WORM            "/inherit/char/worm"
#define SNAKE           "/inherit/char/snake"
#define WAREHOUSE       "/inherit/room/warehouse" 

// User IDs
#define ROOT_UID        "Root"
#define BACKBONE_UID    "Backbone"

// Features

#define F_ACTION        "/feature/action.lpc"
#define F_ALIAS         "/feature/alias.lpc"
#define F_APPRENTICE    "/feature/apprentice.lpc"
#define F_ATTACK        "/feature/attack.lpc"
#define F_ATTRIBUTE     "/feature/attribute.lpc"
#define F_AUTOLOAD      "/feature/autoload.lpc"
#define F_BANKER        "/feature/banker.lpc"
#define F_BUSINESS      "/feature/business"
#define F_CLEAN_UP      "/feature/clean_up.lpc"
#define F_COAGENT       "/feature/coagent.lpc"
#define F_COMMAND       "/feature/command.lpc"
#define F_CONDITION     "/feature/condition.lpc"
#define F_CUTABLE       "/feature/cutable.lpc"
#define F_DAMAGE        "/feature/damage.lpc"
#define F_DBASE         "/feature/dbase.lpc"
#define F_DEALER        "/feature/dealer.lpc"
#define F_EDIT          "/feature/edit.lpc"
#define F_EQUIP         "/feature/equip.lpc"
#define F_FINANCE       "/feature/finance.lpc"
#define F_FOOD          "/feature/food.lpc"
#define F_GUARDER       "/feature/guarder.lpc"
#define F_ITEMMAKE      "/feature/itemmake.lpc"
#define F_LIQUID        "/feature/liquid.lpc"
#define F_MASTER        "/feature/master.lpc"
#define F_MESSAGE       "/feature/message.lpc"
#define F_MORE          "/feature/more.lpc"
#define F_MOVE          "/feature/move.lpc"
#define F_NAME          "/feature/name.lpc"
#define F_NOCLONE       "/feature/noclone.lpc"
#define F_OBSAVE        "/feature/obsave.lpc"
#define F_PUNISHER      "/feature/punisher.lpc"
#define F_QUESTER       "/feature/quester.lpc"
#define F_SAVE          "/feature/save.lpc"
#define F_SHADOW        "/feature/shadow.lpc"
#define F_SHELL         "/feature/shell.lpc"
#define	F_SILENTDEST	"/feature/silentdest.lpc"
#define F_SKILL         "/feature/skill.lpc"
#define F_SSERVER       "/feature/sserver.lpc"
#define F_TEAM          "/feature/team.lpc"
#define F_TRANSPORT     "/feature/transport.lpc"
#define F_TREEMAP       "/feature/treemap.lpc"
#define F_VENDOR        "/feature/dealer.lpc"
#define F_UNIQUE        "/feature/unique.lpc"

// music instructment
#define F_XIAO          "/inherit/misc/_xiao.lpc"

// Others

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#include "tomud.h"

// Install information
#define INSTALL_COMBAT_TEST     1

#undef PROFILE_COMMANDS
