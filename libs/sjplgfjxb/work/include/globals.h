//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories
#define PAWN		"/feature/pawn"
#define F_BANKER		"/feature/banker"
#define QUEST_OB		"/feature/quest_list"
#define EXPLIST		"/clone/quest/explist"


#define TOPTEN_RICH 	  "/topten/rich.txt"
#define TOPTEN_PKER	  "/topten/pker.txt"
#define TOPTEN_EXP	  "/topten/exp.txt"
#define TOPTEN_SWORD      "/topten/sword.txt"
#define TOPTEN_UNARMED    "/topten/unarmed.txt"
#define TOPTEN_D		"/adm/daemons/toptend"

#define F_VI "/feature/vi"
#define INC_DIR		"/include/"

#define COMMAND_DIR             "/cmds/"
#define CONFIG_DIR              "/adm/etc/"
#define DATA_DIR                "/data/"
#define HELP_DIR                "/doc/"
#define LOG_DIR                 "/log/"

// Daemons
#define BAN_D			"/adm/daemons/band"
#define ALIAS_D                 "/adm/daemons/aliasd"
#define CHANNEL_D               "/adm/daemons/channeld"
#define CHAR_D                  "/adm/daemons/chard"
#define CHINESE_D               "/adm/daemons/chinesed"
#define GBB5_D	  	   	"/adm/daemons/gbb5_d"
#define B5GB_D	 	   	"/adm/daemons/b5gb_d"
#define COMBAT_D                "/adm/daemons/combatd"
#define PARRY_D                  "/adm/daemons/parryd"
#define COMMAND_D               "/adm/daemons/cmd_d"
#define EMOTE_D                 "/adm/daemons/emoted"
#define FINGER_D                "/adm/daemons/fingerd"
#define INQUIRY_D               "/adm/daemons/inquiryd"
#define LOGIN_D                 "/adm/daemons/logind"
#define NATURE_D                "/adm/daemons/natured"
#define PROFILE_D               "/adm/daemons/profiled"
#define RANK_D                  "/adm/daemons/rankd"
#define SECURITY_D              "/adm/daemons/securityd"
#define UPDATE_D                "/adm/daemons/updated"
#define VIRTUAL_D               "/adm/daemons/virtuald"
#define WEAPON_D                "/adm/daemons/weapond"
#define WHO_D			"/adm/daemons/whod"
#define NEWNPC_D	 	"/adm/daemons/newnpc_d"
//add by John Darks
#define LANGUAGE_D		"/adm/daemons/languaged.lpc"
// added by Tie for questing

#define QUEST_D(x)		("/quest/qlist" + x)
#define CLASS_D(x)              ("/daemon/class/" + x)
#define SKILL_D(x)              ("/daemon/skill/" + x)
#define TROOP_D(x)              ("/daemon/troop/" + x)
#define CONDITION_D(x)  ("/daemon/condition/" + x)

// Clonable/Non-inheritable Standard Objects

#define COIN_OB                 "/obj/money/coin"
#define CORPSE_OB               "/obj/corpse"
#define LOGIN_OB                "/obj/login"
#define MASTER_OB               "/adm/obj/master"
#define MAILBOX_OB              "/obj/mailbox"
#define SILVER_OB               "/obj/money/silver"
#define GOLD_OB                 "/obj/money/gold"
#define THCASH_OB               "/obj/money/thousand-cash"
#define TECASH_OB               "/obj/money/tenthousand-cash"
#define SIMUL_EFUN_OB   "/adm/obj/simul_efun"
#define USER_OB                 "/obj/user"
#define VOID_OB                 "/obj/void"

// Inheritable Standard Objects

#define BANK                    "/std/room/bank"
#define BULLETIN_BOARD  "/std/bboard"
#define CHARACTER               "/std/char"
#define CLASS_GUILD             "/std/room/class_guild"
#define COMBINED_ITEM   "/std/item/combined"
#define EQUIP                   "/std/equip"
#define FORCE                   "/std/force"
#define HOCKSHOP                "/std/room/hockshop"
#define ITEM                    "/std/item"
#define Q_ITEM                    "/std/qitem"
#define LIQUID                  "/std/liquid"
#define MONEY                   "/std/money"
#define NPC                             "/std/char/npc"
// added by baiwt@sjpl 4/99
#define NPC_SAVE		"/std/char/npcsave"
#define POWDER                  "/std/medicine/powder"
#define ROOM                    "/std/room"
#define SKILL                   "/std/skill"
#define SSERVER                 "/std/sserver"
#define NEW_NPC			"/std/char/new_npc"	// 07/09/98 by mai
#define NEW_VENDOR		"/std/char/newvendor"      // 01/22/97 by mai
#define TROOP                   "/std/troop"

// User IDs

#define ROOT_UID                "Root"
#define BACKBONE_UID    "Backbone"

// Features

#define F_ACTION                "/feature/action.lpc"
#define F_ALIAS                 "/feature/alias.lpc"
#define F_PAWN			"/feature/pawn.lpc"
#define F_APPRENTICE    	"/feature/apprentice.lpc"
#define F_ATTACK                "/feature/attack.lpc"
#define F_ATTRIBUTE             "/feature/attribute.lpc"
#define F_AUTOLOAD              "/feature/autoload.lpc"
#define F_CLEAN_UP              "/feature/clean_up.lpc"
#define F_COMMAND               "/feature/command.lpc"
#define F_CONDITION             "/feature/condition.lpc"
#define F_DAMAGE                "/feature/damage.lpc"
#define F_DBASE                 "/feature/dbase.lpc"
#define F_EDIT                  "/feature/edit.lpc"
#define F_EQUIP                 "/feature/equip.lpc"
#define F_FINANCE               "/feature/finance.lpc"
#define F_FOOD                  "/feature/food.lpc"
#define F_LIQUID                "/feature/liquid.lpc"
#define F_MASTER                "/std/char/master.lpc"
#define F_MESSAGE               "/feature/message.lpc"
#define F_MORE                  "/feature/more.lpc"
#define F_MOVE                  "/feature/move.lpc"
#define F_NAME                  "/feature/name.lpc"
#define F_SAVE                  "/feature/save.lpc"
#define F_SKILL                 "/feature/skill.lpc"
#define F_TEAM                  "/feature/team.lpc"
#define F_TREEMAP               "/feature/treemap.lpc"
#define F_TROOP                 "/feature/troop.lpc"
#define F_VENDOR                "/feature/vendor.lpc"
#define F_VENDOR_SALE                "/feature/vendor_sale.lpc"
#define F_QUEST			"/feature/quest.lpc"
#define F_PAWNOWNER		"/feature/pawnowner.lpc"
#define F_BANKOWNER		"/feature/bankowner.lpc"
#define F_BANKPAWNOWNER		"/feature/bankpawnowner.lpc"
#define SAVE_EXTENSION          __SAVE_EXTENSION__
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
