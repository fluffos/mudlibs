//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories

#define BOARD_DIR		"/daemon/board/"
#define COMMAND_DIR		"/cmds/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR			"/log/"

// Daemons

#define ALIAS_D			"/adm/daemons/aliasd"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define DAEMON_D		"/adm/daemons/daemond"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define ITEM_D			"/adm/daemons/itemd"
#define LOGIN_D			"/adm/daemons/logind"
#define NATURE_D		"/adm/daemons/natured"
#define PROFILE_D		"/adm/daemons/profiled"
#define SECURITY_D		"/adm/daemons/securityd"
#define VIRTUAL_D		"/adm/daemons/virtuald"

#define CLASS_D(x)		(DAEMON_D->query_daemon("class:"+(x)))
#define CONDITION_D(x)	(DAEMON_D->query_daemon("condition:"+(x)))
#define OBJECT_D(x)		(DAEMON_D->query_daemon("object:"+(x)))
#define RACE_D(x)		(DAEMON_D->query_daemon("race:"+(x)))
#define SKILL_D(x)		(DAEMON_D->query_daemon("skill:"+(x)))

// Clonable/Non-inheritable Standard Objects

#define COIN_OB			"/obj/money/coin"
#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB		"/obj/mailbox"
#define SILVER_OB		"/obj/money/silver"
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"

// Inheritable Standard Objects

#define BULLETIN_BOARD	"/std/bboard"
#define CHARACTER		"/std/char"
#define COMBINED_ITEM	"/std/item/combined"
#define EQUIP			"/std/equip"
#define FORCE			"/std/force"
#define ITEM			"/std/item"
#define LIQUID_ITEM		"/std/item/liquid"
#define MONEY			"/std/money"
#define NPC				"/std/char/npc"
#define POWDER			"/std/medicine/powder"
#define ROOM			"/std/room/room"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID	"Backbone"
#define DOMAIN_UID		"Domain"
#define MUDLIB_UID		"Mudlib"

// Features

#define F_ATTRIBUTE		"/feature/attribute.lpc"
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_EQUIP			"/feature/equip.lpc"
#define F_FOOD			"/feature/food.lpc"
#define F_DRINK			"/feature/drink.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_STATISTIC		"/feature/statistic.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_UNIQUE		"/feature/unique.lpc"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
