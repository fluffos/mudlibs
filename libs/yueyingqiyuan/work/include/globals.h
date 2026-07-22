//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

#pragma save_binary

#define JOB_OB(x)		("/d/job/"+x+"/job")
#define CITY_OB(city,room)   ("/d/"+city+"/"+room)
// Directories

#define COMMAND_DIR		"/cmds/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR			"/log/"

// Daemons

#define BR_D			"/adm/daemons/brd"
#define ALIAS_D			"/adm/daemons/aliasd"
#define BAN_D     	        "/adm/daemons/band.lpc"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define CONVERT_D		"/adm/daemons/convertd"
#define CRON_D          "/adm/daemons/cron"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define EVENT_D	        "/adm/daemons/eventd"
#define CLUB_D			"/adm/daemons/clubd"
#define LANGUAGE_D      "/adm/daemons/languaged.lpc"
#define MISC_D		    "/adm/daemons/miscd"
#define MONITOR_D		"/adm/daemons/monitord"
#define MONEY_D	        "/adm/daemons/moneyd"
#define NATURE_D		"/adm/daemons/natured"
#define OBSTACLE_D      "/adm/daemons/obstacled"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define SPELL_D		    "/adm/daemons/spelld"
#define STORY_D	        "/adm/daemons/storyd.lpc"
#define TASK_D          "/adm/daemons/questd"
#define TOPTEN_D	    "/adm/daemons/toptend"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
// added by stone 20020607
#define LOCATION_D      "/adm/daemons/locationd"

#define MASTER_OB		"/adm/obj/master"
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"

#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)		("/daemon/skill/" + x)
#define CONDITION_D(x)	("/daemon/condition/" + x)

// Clonable/Non-inheritable Standard Objects

#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MAILBOX_OB		"/obj/mailbox"
#define JINBI_OB		"/obj/money/gold-coin"
#define RMB_OB			"/obj/money/rmb"
#define GOLD_OB			"/obj/money/gold"
#define SILVER_OB		"/obj/money/silver"
#define COIN_OB			"/obj/money/coin"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"
#define STORY_DIR       "/obj/story/"

// Inheritable Standard Objects

#define BANK			"/std/room/bank"
#define BULLETIN_BOARD	"/std/bboard"
#define BBS_BOARD		"/std/bbsboard"
#define BULLE_BOARD     "/std/bbsboard_b"
#define CHARACTER		"/std/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM	"/std/item/combined"
#define EQUIP			"/std/equip"
#define FORCE			"/std/force"
#define CITY			"/std/city"
#define HOCKSHOP		"/std/room/hockshop"
#define ITEM			"/std/item"
#define LIQUID			"/std/liquid"
#define MONEY			"/std/money"
#define NPC			    "/std/char/npc"
#define NPC_SAVE		"/std/char/npcsave"
#define POWDER			"/std/medicine/powder"
#define QUEST			"/std/quest"
#define ROOM			"/std/room"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"
#define SKILL_MODEL_UNARMED    "/std/skill_model_unarmed.lpc"
#define SKILL_MODEL_WEAPON     "/std/skill_model_weapon.lpc"
#define SKILL_MODEL_DEFAULT    "/std/skill_model_default.lpc"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID	"Backbone"

// Features

#define F_ACTION		"/feature/action.lpc"
#define F_ALIAS			"/feature/alias.lpc"
#define F_APPRENTICE	"/feature/apprentice.lpc"
#define F_ATTACK		"/feature/attack.lpc"
#define F_ATTRIBUTE		"/feature/attribute.lpc"
#define F_AUTOLOAD		"/feature/autoload.lpc"
#define F_BANKER		"/feature/banker.lpc"
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
#define F_CONDITION		"/feature/condition.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_EDIT			"/feature/edit.lpc"
#define F_ENCODING		"/feature/encoding.lpc"
#define F_EQUIP			"/feature/equip.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD			"/feature/food.lpc"
#define F_LIQUID		"/feature/liquid.lpc"
#define F_MASTER		"/std/char/master.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MORE			"/feature/more.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_ONEOWNER		"/feature/oneowner.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_BACKUP		"/feature/backup.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_UNIQUE		"/feature/unique.lpc"
#define F_VENDOR		"/feature/vendor.lpc"
#define F_VENDOR_SALE   "/feature/vendor_sale.lpc"
#define F_FROZEN        "/feature/frozen.lpc"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

//topten
#define TOPTEN_RICH 	"/topten/rich.o"
#define TOPTEN_PKER 	"/topten/pker.o"
#define TOPTEN_EXP  	"/topten/exp.o"
#define TOPTEN_DX   	"/topten/dx.o"
#define TOPTEN_KILL		"/topten/killer.o"
#define TOPTEN_QUESTS	"/topten/quests.o"
#define TOPTEN_SPELLS	"/topten/spells.o"
#define TOPTEN_TASK		"/topten/task.o"
#define TOPTEN_FORCE	"/topten/force.o"
#define TOPTEN_PER1 	"/topten/per1.o"
#define TOPTEN_PER2 	"/topten/per2.o"
#define TOPTEN_AGE  	"/topten/age.o"
#define TOPTEN_MASTER  	"/topten/master.o"

#define RICH_B 		"TOP TEN 【 月影奇缘十大富豪　　 】排行榜"
#define PKER_B 		"TOP TEN 【 月影奇缘十大狂魔　　 】排行榜"
#define EXP_B  		"TOP TEN 【 月影奇缘十大武学高手 】排行榜"
#define DX_B  		"TOP TEN 【 月影奇缘十大道行高手 】排行榜"
#define KILL_B 		"TOP TEN 【 月影奇缘十大魔头　　 】排行榜"
#define QUESTS_B    "TOP TEN 【 月影奇缘十大解迷高手 】排行榜"
#define TASK_B      "TOP TEN 【 月影奇缘十大TASK高手 】排行榜"
#define SPELLS_B 	"TOP TEN 【 月影奇缘十大魔法高手 】排行榜"
#define FORCE_B		"TOP TEN 【 月影奇缘十大内力高手 】排行榜"
#define PER1_B		"TOP TEN 【 月影奇缘十大白马王子 】排行榜"
#define PER2_B		"TOP TEN 【 月影奇缘十大梦中情人 】排行榜"
#define AGE_B		"TOP TEN 【 月影奇缘十大老不死　 】排行榜"
#define MASTER_B	"TOP TEN 【 月影奇缘十大高手　　 】排行榜"

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS
