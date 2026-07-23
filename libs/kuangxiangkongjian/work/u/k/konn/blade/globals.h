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
#define QUEST			"/data/quests"

// Daemons

#define COLOR_D			"/adm/daemons/colord"
#define PK_D			"/adm/daemons/pkd"
#define DIR_D			"/adm/daemons/dird"
#define ALIAS_D			"/adm/daemons/aliasd"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define LOGIN_D			"/adm/daemons/logind"
#define NATURE_D		"/adm/daemons/natured"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
#define QUEST_D			"/adm/daemons/questd"
#define FRIEND_D		"/adm/daemons/friend"
#define F_SKILL_D		"/adm/daemons/skilld"
#define GUILD_D			"/adm/daemons/guildd"
#define PUNLISH_D		"/adm/daemons/punlishd"

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
#define CASH_OB			"/obj/money/thousand-cash"
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
#define HOCKSHOP		"/std/room/hockshop"
#define SHOP			"/std/room/shop"
#define ITEM			"/std/item"
#define LIQUID			"/std/liquid"
#define MONEY			"/std/money"
#define NPC			"/std/char/npc"
#define ROOM			"/std/room"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"
#define PARTY_NPC		"/std/char/party_npc"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID		"Backbone"

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
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_VENDOR		"/feature/vendor.lpc"
#define F_MEDICINE		"/feature/medicine.lpc"
#define F_SOLDIER		"/feature/call_soldier.lpc"
#define F_CATCHER		"/feature/catcher.lpc"
#define F_GUILDCMDS		"/feature/guildcmds.lpc"

// 底下的定义会记录命令的使用/请配合 profile 命令的使用
// #undef PROFILE_COMMANDS
#define PROFILE_COMMANDS	1

// for joke 个数
#define JOKE_SIZE 212

// for guild function
#define F_FUNCTION "/feature/function"

#undef LOCK_PLAYER	"对不起, 由于一堆 bug, 目前内部整修中....\n不便之处请原谅"
#undef LOCK_WIZARD	"对不起, 目前只让玩家进来, 正在测试\n不便之处请多多包含...."
