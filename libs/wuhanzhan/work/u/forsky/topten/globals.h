// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories

#pragma save_binary
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR     "/adm/etc/"
#define DATA_DIR     "/data/"
#define HELP_DIR     "/doc/"
#define LOG_DIR        "/log/"

// Daemons

#define ALIAS_D        "/adm/daemons/aliasd"
#define CHANNEL_D     "/adm/daemons/channeld"
#define SPELL_D                 "/adm/daemons/spelld"
#define MISC_D                  "/adm/daemons/miscd"



#define CHAR_D        "/adm/daemons/chard"
#define CHINESE_D     "/adm/daemons/chinesed"
#define COMBAT_D     "/adm/daemons/combatd"
#define COMMAND_D     "/adm/daemons/cmd_d"
#define CONVERT_D     "/adm/daemons/convertd"
#define EMOTE_D        "/adm/daemons/emoted"
#define FINGER_D     "/adm/daemons/fingerd"
#define INQUIRY_D     "/adm/daemons/inquiryd"
#define LOGIN_D        "/adm/daemons/logind"
// added by snowcat 6/20/1997
#define MONITOR_D     "/adm/daemons/monitord"
#define NATURE_D     "/adm/daemons/natured"
#define PROFILE_D     "/adm/daemons/profiled"
#define RANK_D        "/adm/daemons/rankd"
#define SECURITY_D     "/adm/daemons/securityd"
#define UPDATE_D     "/adm/daemons/updated"
#define VIRTUAL_D     "/adm/daemons/virtuald"
#define WEAPON_D     "/adm/daemons/weapond"
#define BAN_D      "/adm/daemons/band.lpc"

// Auxil Daemons

#define MONEY_D      "/adm/auxil/moneyd"
#define PIG_D      "/adm/auxil/pigd"

#define QUEST_D(x)     ("/daemon/quest/qlist" + x)
#define CLASS_D(x)     ("/daemon/class/" + x)
#define SKILL_D(x)     ("/daemon/skill/" + x)
#define CONDITION_D(x)   ("/daemon/condition/" + x)

// Clonable/Non-inheritable Standard Objects

#define COIN_OB        "/obj/money/coin"
#define CORPSE_OB     "/obj/corpse"
#define GOLD_OB     "/obj/money/gold"
#define LOGIN_OB     "/obj/login"
#define MASTER_OB     "/adm/obj/master"
#define MAILBOX_OB     "/obj/mailbox"
#define SILVER_OB     "/obj/money/silver"
#define SIMUL_EFUN_OB   "/adm/obj/simul_efun"
#define THCASH_OB          "/obj/money/thousand-cash"
#define TECASH_OB          "/obj/money/tenthousand-cash"
#define USER_OB        "/obj/user"
#define VOID_OB        "/obj/void"

// Inheritable Standard Objects

#define BANK        "/std/room/bank"
#define BULLETIN_BOARD   "/std/bboard"
#define BBS_BOARD     "/std/bbsboard"
#define CHARACTER     "/std/char"
#define CLASS_GUILD     "/std/room/class_guild"
#define COMBINED_ITEM   "/std/item/combined"
#define EQUIP        "/std/equip"
#define FORCE        "/std/force"
#define HOCKSHOP     "/std/room/hockshop"
#define ITEM        "/std/item"
#define LIQUID        "/std/liquid"
#define MONEY        "/std/money"
#define NPC        "/std/char/npc"
#define NPC_SAVE     "/std/char/npcsave"
#define QUEST            "/std/quest"
#define POWDER        "/std/medicine/powder"
#define ROOM        "/std/room"
#define SKILL        "/std/skill"
#define SSERVER        "/std/sserver"

// User IDs

#define ROOT_UID     "Root"
#define BACKBONE_UID   "Backbone"

// Features

#define F_ACTION     "/feature/action.lpc"
#define F_ALIAS        "/feature/alias.lpc"
#define F_APPRENTICE   "/feature/apprentice.lpc"
#define F_ATTACK     "/feature/attack.lpc"
#define F_ATTRIBUTE     "/feature/attribute.lpc"
#define F_AUTOLOAD     "/feature/autoload.lpc"
#define F_BANKOWNER             "/feature/bankowner.lpc"
#define F_BANKPAWNOWNER         "/feature/bankpawnowner.lpc"
#define F_CLEAN_UP     "/feature/clean_up.lpc"
#define F_COMMAND     "/feature/command.lpc"
#define F_CONDITION     "/feature/condition.lpc"
#define F_DAMAGE     "/feature/damage.lpc"
#define F_DEALER        "/feature/dealer.lpc"
#define F_DBASE        "/feature/dbase.lpc"
#define F_EDIT        "/feature/edit.lpc"
#define F_ENCODING     "/feature/encoding.lpc"
#define F_EQUIP        "/feature/equip.lpc"
#define F_FINANCE     "/feature/finance.lpc"
#define F_FOOD        "/feature/food.lpc"
#define F_LIQUID     "/feature/liquid.lpc"
#define F_MASTER     "/std/char/master.lpc"
#define F_MESSAGE     "/feature/message.lpc"
#define F_MORE        "/feature/more.lpc"
#define F_MOVE        "/feature/move.lpc"
#define F_NAME        "/feature/name.lpc"
#define F_ONEOWNER     "/feature/oneowner.lpc"
#define F_PAWN                  "/feature/pawn.lpc"
#define F_PAWNOWNER             "/feature/pawnowner.lpc"
#define F_QUEST        "/feature/quest.lpc"
#define F_SAVE        "/feature/save.lpc"
#define F_BACKUP     "/feature/backup.lpc"
#define F_SKILL        "/feature/skill.lpc"
#define F_TEAM        "/feature/team.lpc"
#define F_TREEMAP     "/feature/treemap.lpc"
#define F_UNIQUE     "/feature/unique.lpc"
#define F_VENDOR     "/feature/vendor.lpc"
#define F_VENDOR_SALE     "/feature/vendor_sale.lpc"

#define TOPTEN_RICH    "/topten/rich.txt"
#define TOPTEN_PKER   "/topten/pker.txt"
#define TOPTEN_EXP   "/topten/exp.txt"
#define TOPTEN_SHEN1   "/topten/shen1.txt"
#define TOPTEN_SHEN2   "/topten/shen2.txt"
#define TOPTEN_PER1   "/topten/per1.txt"
#define TOPTEN_NEILI   "/topten/neili.txt"
#define TOPTEN_PER2   "/topten/per2.txt"
#define TOPTEN_AGE   "/topten/age.txt"
#define RICH_B    "十大富人"
#define PKER_B    "十大杀人狂"
#define EXP_B     "十大道行高手"
#define SHEN2_B    "十大法力高手"
#define SHEN1_B     "十大魔头"
#define NEILI_B   "十大内力高手"
#define PER1_B    "十大白马王子"
#define PER2_B    "十大梦中情人"
#define AGE_B    "十大老不死"
#define TOPTEN_D   "/adm/daemons/toptend"
#define CHINESE_MUD_NAME   "大话西游"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS
