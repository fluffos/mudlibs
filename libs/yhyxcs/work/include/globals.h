//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories

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
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define NATURE_D		"/adm/daemons/natured"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"

#define CONDITION_D(x)		("/daemon/condition/" + x)
//#define CLASS_D(x)		("/class/" + x)
//#define RACE_D(x)		("/daemon/race/" + x)
//#define SKILL_D(x)		(call_other("/adm/daemons/skilld", "query_skill_daemon", x))

// Clonable/Non-inheritable Standard Objects

//#define COIN_OB		"/obj/money/coin"
//#define SILVER_OB		"/obj/money/silver"
#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB		"/obj/mailbox"
#define SIMUL_EFUN_OB		"/adm/obj/simul_efun"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"

// Inheritable Standard Objects

//#define BANK			"/std/room/bank"
//#define FORCE			"/std/force"
//#define HOCKSHOP		"/std/room/hockshop"
//#define MONEY			"/std/money"
//#define CLASS_GUILD		"/std/room/class_guild"
#define BULLETIN_BOARD		"/std/bboard"
#define CHARACTER		"/std/char"
#define ITEM			"/std/item"
#define EQUIP			"/std/equip"
#define ROOM			"/std/room"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"
#define COMBINED_ITEM		"/std/item/combined"
#define LIQUID_ITEM		"/std/item/liquid"
#define NPC			"/std/char/npc"
#define POWDER			"/std/medicine/powder"
// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID		"Backbone"

// Features

//#define F_ACTION		"/feature/action.lpc"
#define F_ALIAS			"/feature/alias.lpc"
#define F_ATTACK		"/feature/attack.lpc"
#define F_ATTRIBUTE		"/feature/attribute.lpc"
#define F_AUTOLOAD		"/feature/autoload.lpc"
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
#define F_CONDITION		"/feature/condition.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_EDIT			"/feature/edit.lpc"
#define F_EQUIP			"/feature/equip.lpc"
//#define F_FAMILY		"/feature/family.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD			"/feature/food.lpc"
#define F_LIQUID		"/feature/liquid.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MORE			"/feature/more.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_UNIQUE		"/feature/unique.lpc"

#define F_MASTER		"/std/char/master.lpc"
#define F_MERCENARY		"/std/char/mercenary.lpc"
#define F_VENDOR		"/std/char/vendor.lpc"

//New Writen by Alarms
#define F_S_ATTRIBUTE		"/feature/s_attribute.lpc"
#define F_CURRENT		"/feature/current.lpc"
//#define F_AFFAIR		"/feature/affair.lpc"
#define F_DISTANCE		"/feature/distance.lpc"
#define F_SPACE_MOVE		"/feature/space_move.lpc"
#define F_SPACEEQUIP		"/feature/spaceequip.lpc"
#define F_STARPORT		"/feature/starport.lpc"
//#define F_FORMATION		"/feature/formation.lpc"
#define F_APPRENTICE		"/feature/apprentice.lpc"

#define SPACE_ROOM		"/std/space_room.lpc"
#define S_SKILL			"/std/s_skill.lpc"
#define S_EQUIP			"/std/s_equip.lpc"
#define PLANET			"/std/planet.lpc"
#define F_QUEST			"/std/char/quest.lpc"
#define F_RANK			"/std/char/rank.lpc"
#define F_GENERAL		"/std/char/general.lpc"
#define F_APPLY			"/std/char/apply.lpc"
#define F_SUPPLY		"/std/char/supply.lpc"
#define F_VOYAGE		"/std/char/voyage.lpc"
#define F_BANKER		"/std/char/banker.lpc"

#define WRECK_OB		"/obj/wreck.lpc"

#define S_COMBAT_D		"/adm/daemons/s_combatd.lpc"
#define MONITOR_D		"/adm/daemons/monitord.lpc"
#define TASK_D			"/adm/daemons/taskd.lpc"

#define SKILL_D(x)		("/daemon/skill/" + x )
#define S_SKILL_D(x)		("/daemon/s_skill/" + x )
#define QUEST_D(x)		("/daemon/quest/" + x )

#define SAVE_EXTENSION		".o"
//New Writen end



// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
