//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories

#define COMMAND_DIR		"/cmds/"
#define F_ME  "/feature/ed.lpc" //定义新的编辑器 by chan
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR			"/log/"
#define QUEST			"/data/quests"

// Daemons

#define ALIAS_D			"/adm/daemons/aliasd"
#define BANMULTI_D		"/adm/daemons/banmultid"
#define CBIP_D          	"/adm/daemons/cbipd"
#define COLOR_D			"/adm/daemons/colord"
#define CON_D			"/adm/daemons/conditiond"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define CLAN_D			"/adm/daemons/cland"
#define CLANV_D     		"/adm/daemons/clanvd"
#define CMAIL_D          	"/adm/daemons/cmaild"
#define DIR_D			"/adm/daemons/dird"
#define ENTER_D			"/adm/daemons/enterd"
#define EMOTE_D			"/adm/daemons/emoted"
#define F_SKILL_D		"/adm/daemons/skilld"
#define FINGER_D		"/adm/daemons/fingerd"
#define GUILD_D			"/adm/daemons/guildd"
#define LOGIN_D			"/adm/daemons/logind"
#define MAIL_D			"/adm/daemons/maild"
#define NATURE_D		"/adm/daemons/natured"
#define PK_D			"/adm/daemons/pkd"
#define PROFILE_D		"/adm/daemons/profiled"
#define PUNLISH_D		"/adm/daemons/punlishd"
#define RANK_D			"/adm/daemons/rankd"
#define STORY_D          "/adm/daemons/storyd"
#define SECURITY_D		"/adm/daemons/securityd"
#define TEMP_D			"/adm/daemons/tempd"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
#define QUEST_D			"/adm/daemons/questd"
// 好像没用了 #define FRIEND_D		"/adm/daemons/friend"

#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)		("/daemon/skill/" + x)
#define CONDITION_D(x)		("/daemon/condition/" + x)
#define SEC_KEE_D(x)		("/daemon/sec_kee/" + x)
#define PERFORM_D(x)            ("/daemon/perform/" + x)

// Clonable/Non-inheritable Standard Objects

#define MASTER_OB		"/adm/obj/master"
#define SIMUL_EFUN_OB		"/adm/obj/simul_efun"
#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MAILBOX_OB		"/obj/mailbox"
#define DIAMOND_OB		"/obj/money/diamond"
#define CASH_OB         "/obj/money/cash"
#define GOLD_OB			"/obj/money/gold"
#define SILVER_OB		"/obj/money/silver"
#define COIN_OB			"/obj/money/coin"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"

// Inheritable Standard Objects

#define BOOK			"/obj/book"
#define BANK			"/std/room/bank"
#define BULLETIN_BOARD		"/std/bboard"
#define CHARACTER		"/std/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM		"/std/item/combined"
#define EQUIP			"/std/equip"
#define PAL			"/std/pal"
#define HOCKSHOP		"/std/room/hockshop"
#define SHOP			"/std/room/shop"
#define ITEM			"/std/item"
#define LIQUID			"/std/liquid"
#define MONEY			"/std/money"
#define OLD_NPC			"/std/char/npc"
#define NPC			"/std/char/new_npc"
#define OLD_ROOM		"/std/room"
#define ROOM			"/std/room"
#define RECORD_ROOM		"/std/record_room"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"
#define PARTY_NPC		"/std/char/party_npc"
#define TRANS_ROOM      "/std/room/trans_room"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID		"Backbone"
#define DOMAIN_UID              "Domain"
#define MUDLIB_UID              "Mudlib"


// Features

#define F_MASTER		"/std/char/master.lpc"
#define F_ACTION		"/feature/action.lpc"
#define F_MAGIC			"/feature/magic.lpc"
#define F_ALIAS			"/feature/alias.lpc"
#define F_APPRENTICE		"/feature/apprentice.lpc"
#define F_ATTACK		"/feature/attack.lpc"
#define F_AUTOLOAD		"/feature/autoload.lpc"
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
#define F_CONDITION		"/feature/condition.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_EDIT			"/feature/edit.lpc"
#define F_EQUIP			"/feature/equip.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD			"/feature/food.lpc"
#define F_LIQUID		"/feature/liquid.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MORE			"/feature/more.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_QUESTS                "/u/k/konn/blade/quests.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_MLIST         	"/feature/mlist.lpc"
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_VENDOR		"/feature/vendor.lpc"
#define F_MEDICINE		"/feature/medicine.lpc"
#define F_SOLDIER		"/feature/call_soldier.lpc"
#define F_WIND_GUARD	    	"/feature/call_wind_soldier.lpc"
#define F_CATCHER		"/feature/catcher.lpc"
#define F_GUILDCMDS		"/feature/guildcmds.lpc"
#define F_ED			"/feature/ed.lpc"
#define F_PLACE         	"/feature/place.lpc"

// 底下的定义会记录命令的使用/请配合 profile 命令的使用
#undef PROFILE_COMMANDS
// #define PROFILE_COMMANDS	1

// for guild function
#define F_FUNCTION "/feature/function"
#define F_SPELL "/feature/spell"

// 自动 reboot 用的
#define REBOOT_PLACE "/u/w/wade/workroom"
#define WEATHER
#define LIGHT	// 火把系统
#undef FUZZY_LOOK // ....
#undef SEND_MONEY // 发钱系统
#undef FIND_ROBBOT // 找机器人
#define SAVEEQ	// 可以在 quit 时自动储三件装备，但是要先 wear + secure 才行
