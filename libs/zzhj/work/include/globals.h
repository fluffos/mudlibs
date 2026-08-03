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
#define DAEMON_D		"/adm/daemons/daemond"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define MOB_PROG_D		"/adm/daemons/mob_progd"
#define NATURE_D		"/adm/daemons/natured"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define SPACE_SHIP_D		"/adm/daemons/space_shipd"
#define UPDATE_D		"/adm/daemons/updated"
#define VEHICLE_D		"/adm/daemons/vehicled"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"

#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)		("/daemon/skill/" + x)
#define CONDITION_D(x)		("/daemon/condition/" + x)

// Clonable/Non-inheritable Standard Objects

#define COPPER_OB		"/obj/money/copper"
#define CORPSE_OB		"/obj/corpse"
#define GOLD_OB			"/obj/money/gold"
#define LOGIN_OB		"/obj/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB		"/obj/mailbox"
#define PLATINUM_OB		"/obj/money/platinum"
#define SILVER_OB		"/obj/money/silver"
#define SIMUL_EFUN_OB		"/adm/obj/simul_efun"
#define TRASH_OB		"/obj/trash"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"

// Inheritable Standard Objects

#define ARMOR			"/std/armor"
#define BANK			"/std/room/bank"
#define BOARDING_TUBE		"/std/space/boarding_tube"
#define BULLETIN_BOARD		"/std/bboard"
#define CHARACTER		"/std/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM		"/std/item/combined"
#define EQUIP			"/std/equip"
#define GROUND_CAR		"/std/vehicle/ground_car"
#define SHOP			"/std/room/shop"
#define ITEM			"/std/item"
#define LIQUID			"/std/liquid"
#define MONEY			"/std/money"
#define NPC			"/std/char/npc"
#define PLANET			"/std/space/planet"
#define POWDER			"/std/medicine/powder"
#define ROOM			"/std/room"
#define SHUTTLE			"/std/space_ship/shuttle"
#define SHUTTLE_BAY		"/std/space/shuttle_bay"
#define SKILL			"/std/skill"
#define SPACE			"/std/space/space"
#define SPACE_SHIP		"/std/space_ship/space_ship"
#define SPACE_STATION		"/std/space/space_station"
#define SS_ROOM			"/std/space_ship/space_ship_room"
#define VEHICLE			"/std/vehicle"
#define WEAPON			"/std/weapon/weapon"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID		"Backbone"
#define DOMAIN_UID		"Domain"
#define MUDLIB_UID		"Mudlib"

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
#define F_CONTAINER		"/feature/container.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_DOOR			"/feature/door.lpc"
#define F_EDIT			"/feature/edit.lpc"
#define F_EQUIP			"/feature/equip.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD			"/feature/food.lpc"
#define F_MASTER		"/std/char/master.lpc"
#define F_ME			"/feature/me.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MORE			"/feature/more.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_POLICE		"/feature/char/police.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_S_CLEAN_UP	"/feature/s_clean_up.lpc"
#define F_S_MOVE		"/feature/s_move.lpc"
#define F_SPACE_SHIP		"/feature/space_ship.lpc"
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_V_DAMAGE		"/feature/v_damage.lpc"
#define F_VENDOR		"/feature/vendor.lpc"
#define F_CMD                   "/feature/cmd_d.lpc"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#define PROFILE_COMMANDS
