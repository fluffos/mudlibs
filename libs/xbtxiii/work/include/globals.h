//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories
#define COMMAND_DIR             "/cmds/"
#define CONFIG_DIR              "/adm/etc/"
#define TEMP_DIR                "/temp/"
#define DUMP_DIR                "/dump/"
#define DATA_DIR                "/data/"
#define HELP_DIR                "/doc/"
#define LOG_DIR                 "/log/"
#define WIZ_DIR		            "/open/"
#define BACKUP_DIR              "/backup/"

// 关于玩家排行
//   #define TOPTEN_RICH 	    "/topten/rich.txt"
//   #define TOPTEN_PKER	    "/topten/pker.txt"
#define TOPTEN_EXP	            "/topten/exp.txt"
//   #define TOPTEN_AGE	        "/topten/age.txt"
//   #define TOPTEN_KILLED       "/topten/killed.txt"
//   #define RICH_B             "十大富翁排行榜"
//   #define PKER_B              "十大魔头排行榜"
#define EXP_B                   "十大高手排行榜"
//   #define AGE_B              "十大老手排行榜"
//   #define KILLED_B           "十大悲情人物排行榜"
#define TOPTEN_D		        "/adm/daemons/toptend"

// Daemons
#define BAN_D			        "/adm/daemons/band"
#define ALIAS_D                 "/adm/daemons/aliasd"
#define BACKUP_D                "/adm/daemons/backupd"
#define CHANNEL_D               "/adm/daemons/channeld"
#define CHAR_D                  "/adm/daemons/chard"
#define CHINESE_D               "/adm/daemons/chinesed"
#define PRIX_D                  "/adm/daemons/prixd"
#define ADVERSE_D               "/adm/daemons/adversed"
#define TASK_D                  "/adm/daemons/taskd"

#define QUIT_D                  "/adm/daemons/quitd"
#define COMBAT_D                "/adm/daemons/combatd"
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
#define REWARD_D                "/adm/daemons/reward"
#define MONEY_D                 "/adm/daemons/moneyd"
#define VOTE_D                  "/adm/daemons/voted"
#define LANGUAGE_D		        "/adm/daemons/languaged"
#define EXPLORE_D               "/adm/daemons/explored"
#define QUEST_D(x)		        ("/quest/qlist" + x)
#define CLASS_D(x)              ("/daemon/class/" + x)
#define SKILL_D(x)              ("/daemon/skill/" + x)
#define CONDITION_D(x)          ("/daemon/condition/" + x)

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
#define SIMUL_EFUN_OB           "/adm/obj/simul_efun"
#define USER_OB                 "/obj/user"
#define VOID_OB                 "/obj/void"
#define SOCKET			        "/adm/obj/socket"
#define TELNET_OB	        	"/adm/object/telnet"
// Inheritable Standard Objects

#define BANK                    "/std/room/bank"
#define BULLETIN_BOARD          "/std/bboard"
#define CHARACTER               "/std/char"
#define CLASS_GUILD             "/std/room/class_guild"
#define COMBINED_ITEM           "/std/item/combined"
#define EQUIP                   "/std/equip"
#define FORCE                   "/std/force"
#define HOCKSHOP                "/std/room/hockshop"
// ADD BY alvins@XBTXII
#define GUANFU                  "/std/room/guanfu"
#define ITEM                    "/std/item"
#define LIQUID                  "/std/liquid"
#define MONEY                   "/std/money"
#define NPC                     "/std/char/npc"
#define POWDER                  "/std/medicine/powder"
#define ROOM                    "/std/room"
// ADD BY RONGG@XBTXII
#define M_POOL      		    "/std/magicpool"
#define SKILL                   "/std/skill"
#define SSERVER                 "/std/sserver"
#define TORCH			        "/std/torch"
#define MAGIC                   "/std/magic.lpc"
// User IDs

#define ROOT_UID                "Root"
#define BACKBONE_UID            "Backbone"

// Features

#define F_ACTION                "/feature/action.lpc"
#define F_ALIAS                 "/feature/alias.lpc"
#define F_PAWN			        "/feature/pawn.lpc"
#define F_APPRENTICE        	"/feature/apprentice.lpc"
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
#define F_EXPLORE               "/feature/explore.lpc"
#define F_MASTER                "/std/char/master.lpc"
#define F_MESSAGE               "/feature/message.lpc"
#define F_MORE                  "/feature/more.lpc"
#define F_MOVE                  "/feature/move.lpc"
#define F_NAME                  "/feature/name.lpc"
#define F_SAVE                  "/feature/save.lpc"
#define F_SKILL                 "/feature/skill.lpc"
#define F_TEAM                  "/feature/team.lpc"
#define F_TREEMAP               "/feature/treemap.lpc"
#define F_VENDOR                "/feature/vendor.lpc"
#define F_SSERVER               "/feature/sserver.lpc"
#define F_UNIQUE                "/feature/unique.lpc"

// added by Tie Yu@fengyun 4/96
#define F_QUEST			        "/std/char/quest.lpc"
// added by Tie@fengyun 8/96
#define F_PAWNOWNER		        "/feature/pawnowner.lpc"
#define F_BANKOWNER		        "/feature/bankowner.lpc"
#define F_BANKPAWNOWNER	      	"/feature/bankpawnowner.lpc"
// Profiling switches
//
#define PASSWORD_D		        "/adm/daemons/passwordd.lpc"
#define STORY_D                 "/adm/daemons/storyd.lpc"
#define STORY_DIR               "/task/storylist/"
//about password,add by rongg@xbtxII 2000/4/1
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS


