//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories

#include "tomud.h"   //鼠标化 angelus 2012.2.15
#include "ansi.h"    //全局颜色 angelus  

#define CMD_LOOK                   "/cmds/std/look"

#define nosave nosave
#define COMMAND_DIR             "/cmds/"
#define CONFIG_DIR              "/adm/etc/"
#define DATA_DIR                "/data/"
#define BACKUP_DIR      	"/backup/"
#define HELP_DIR                "/doc/"
#define LOG_DIR                 "/log/"
#define BOARD_DIR               "/obj/board/"
#define BOARD_PATH              "/obj/sboard/"
// Daemons
#define BAN_D                   "/adm/daemons/band"
#define ALIAS_D                 "/adm/daemons/aliasd"
#define CHANNEL_D               "/adm/daemons/channeld"
#define CHAR_D                  "/adm/daemons/chard"
#define COMPETE_D               "/adm/daemons/competed"
#define CHINESE_D               "/adm/daemons/chinesed"
#define COMBAT_D                "/adm/daemons/combatd"
#define COMMAND_D               "/adm/daemons/cmd_d"
#define EXAMINE_D               "/adm/daemons/examined"
#define CONVERT_D           "/adm/daemons/convertd"
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
#define MONEY_D			"/adm/daemons/moneyd"
#define MAIN_D                          "/adm/daemons/maind"
#define LANGUAGE_D              "/adm/daemons/languaged.lpc"
#define MISC_D              "/adm/daemons/miscd.lpc"
#define WORKER_D	           "/adm/daemons/workerd"
#define BBS_D		             "/adm/daemons/bbsd"


// added by Tie for questing

#define QUEST_D(x)              ("/quest/qlist" + x)
#define CLASS_D(x)              ("/daemon/class/" + x)
#define SKILL_D(x)              ("/daemon/skill/" + x)
#define CONDITION_D(x)          ("/daemon/condition/" + x)
#define BINGQI_D(x)	            ("/clone/weapon/" + x)
#define ARMOR_D(x)	            ("/clone/armor/" + x)
#define NPC_D(x)		            ("/clone/npc/" + x)

// Clonable/Non-inheritable Standard Objects

#define COIN_OB                 "/obj/money/coin"
#define NPC_SAVE     "/std/char/npcsave"
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

// web board by laxnin
#define BOARD_OB(x)             ("/obj/board/" + x)

// Inheritable Standard Objects
#define DAEMON          "/std/cmd_m"
#define BULLETIN_BOARD  "/std/bboard"
#define CHARACTER               "/std/char"
#define CLASS_GUILD             "/std/room/class_guild"
#define COMBINED_ITEM   "/std/item/combined"
#define EQUIP                   "/std/equip"
#define FORCE                   "/std/force"
#define ITEM                    "/std/item"
#define BANK        "/std/room/bank"
#define HOCKSHOP     "/std/room/hockshop"
#define LIQUID                  "/std/liquid"
#define MONEY                   "/std/money"
#define NPC                             "/std/char/npc"
#define FIGHTER                 "/std/char/fighter"
#define JOBNPC                  "/std/char/jobnpc"
#define POWDER                  "/std/medicine/powder"
#define ROOM                    "/std/room"
#define SKILL                   "/std/skill"
#define SSERVER                 "/std/sserver"
#define OBJECT          "/std/object/ob"
#define JOIN        "/feature/join"//ADD BY YANYAN.
//give_job add zpl
#define JOB                        "/std/give_jobd.lpc"


// User IDs

#define ROOT_UID                "yanyan"
#define BACKBONE_UID    "Backbone"
#define MUDLIB_UID              "Mudlib"
// Features

#define F_ACTION                "/feature/action.lpc"
#define F_ALIAS                 "/feature/alias.lpc"
#define F_PAWN                  "/feature/pawn.lpc"
#define F_APPRENTICE            "/feature/apprentice.lpc"
#define F_ATTACK                "/feature/attack.lpc"
#define F_ATTRIBUTE             "/feature/attribute.lpc"
#define F_AUTOLOAD              "/feature/autoload.lpc"
#define F_CLEAN_UP              "/feature/clean_up.lpc"
#define F_COMMAND               "/feature/command.lpc"
#define F_CONDITION             "/feature/condition.lpc"
#define F_DAMAGE                "/feature/damage.lpc"
#define F_DBASE                 "/feature/dbase.lpc"
#define F_EDIT                  "/feature/edit.lpc"
#define F_SED                           "/feature/sedit.lpc"
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
#define F_UNIQUE                "/feature/unique.lpc"
#define F_VENDOR                "/feature/vendor.lpc"
#define F_DEALER                "/feature/dealer.lpc"
#define F_ENCODING                     "/feature/encoding.lpc"
#define F_QUEST                     "/feature/quest.lpc"
#define F_PAWNOWNER                     "/feature/pawnowner.lpc"
#define F_BANKOWNER                      "/feature/bankowner.lpc"
#define F_BANKPAWNOWNER          "/feature/bankpawnowner.lpc"
#define F_CMD                   "/feature/cmd_d.lpc"
#define F_VI                    "/feature/vi.lpc"
#define F_VENDOR_SALE     "/feature/vendor_sale.lpc"
#define F_REPAIR     "/feature/repair.lpc"//add by yanyan
#define F_OFFICE     "/feature/office_vendor.lpc"//add by yanyan
#define F_FIGHT_OWNER "/std/char/fightowner.lpc"//add by yanyan

//讲故事发奖励
#define STORY_DIR	        "/clone/gift/"
#define STORY_D	        "/adm/daemons/storyd"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS

// Mathematic
#define ABS(x)		((x) >= 0 ? (x) : -(x))
#define MAX(a, b)	((a) > (b) ? (a) : (b))
#define MIN(a, b)	((a) < (b) ? (a) : (b))
#define SGN(x)		((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
#define SWAP(x, y)	(x ^= y ^= x ^= y)

