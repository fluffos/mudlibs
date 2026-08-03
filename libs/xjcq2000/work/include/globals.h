// globals.h
// this file will be automatically included by the driver
// for JY mudlib
#pragma save_binary
//added by JackyBoy @ CCTX for TOPTEN
#define TOPTEN_RICH 	"/topten/rich.txt"
#define TOPTEN_PKER	"/topten/pker.txt"
#define TOPTEN_EXP	"/topten/exp.txt"
#define TOPTEN_SHEN1	"/topten/shen1.txt"
#define TOPTEN_SHEN2	"/topten/shen2.txt"
#define TOPTEN_neili	"/topten/neili.txt"
#define TOPTEN_PER1	"/topten/per1.txt"
#define TOPTEN_PER2	"/topten/per2.txt"
#define TOPTEN_AGE	"/topten/age.txt"
#define GROUP_D			"/adm/daemons/groupd"

#define RICH_B 		"十大富人"
#define PKER_B 		"十大杀人狂"
#define EXP_B  		"十大道行高手"
#define SHEN1_B 	"十大魔"
#define SHEN2_B 	"十大法力高手"
#define neili_B		"十大内力高手"
#define PER1_B		"十大白马王子"
#define PER2_B		"十大梦中情人"
#define AGE_B		"十大老不死"
#define TOPTEN_D	"/adm/daemons/toptend"
#define JOB_OB(x)		("/d/job/"+x+"/job")
#define CITY_OB(city,room)   ("/d/"+city+"/"+room)
#define SKILL_MODEL_UNARMED    "/meskill/skill_model_unarmed.lpc"
#define SKILL_MODEL_WEAPON     "/meskill/skill_model_weapon.lpc"
#define SKILL_MODEL_DEFAULT    "/meskill/skill_model_default.lpc"
// Improve function
#define new_ob(str)     new(resolve_path(__DIR__, str))
#define move_to_ob(ob)  move(resolve_path(__DIR__, ob))
//added by Doing @ CCTX
#define PRIVATE_ROOM	"/inherit/private_room.lpc"
#define RECORDABLE_ROOM	"/inherit/recordable_room.lpc"
#define ROOM_D		"/adm/daemons/roomd.lpc"	
#define BANNED_SITES "/adm/etc/banned_sites";
#define PAWN		"/feature/pawn"
#define BR_D		"/adm/daemons/brd"
#define QUEST_OB		"/feature/quest_list"
#define EXPLIST		"/clone/quest/explist"
#define WAIMAO_D	"/adm/daemons/waimaod"
// Important directories
#define private
#define SAVE_EXTENSION  ".o"
#define INC_DIR         "/include/"
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR      "/adm/etc/"
#define DATA_DIR        "/data/"
#define HELP_DIR        "/help/"
#define LOG_DIR         "/log/"
#define F_VI "/feature/vi"
#define STORY_DIR       "/clone/gift/"
// Daemons
#define MONITOR_D		"/adm/daemons/monitord"
#define OBSTACLE_D              "/adm/daemons/obstacled"
#define SPELL_D		        "/adm/daemons/spelld"


#define ALIAS_D         "/adm/daemons/aliasd"
#define BAN_D           "/adm/daemons/band"
#define CHANNEL_D       "/adm/daemons/channeld"
#define CHAR_D           "/adm/daemons/chard"
#define NEWS_D          "/clone/board/news_b"

#define CHINESE_D       "/adm/daemons/chinesed"
#define COMBAT_D        "/adm/daemons/combatd"
#define COMMAND_D       "/adm/daemons/commandd"
#define EMOTE_D         "/adm/daemons/emoted"
#define FINGER_D        "/adm/daemons/fingerd"
#define FTP_D           "/adm/daemons/ftpd"
#define INQUIRY_D       "/adm/daemons/inquiryd"
#define LOGIN_D         "/adm/daemons/logind"
#define MONEY_D         "/adm/daemons/moneyd"
#define NATURE_D        "/adm/daemons/natured"
#define PIG_D           "/adm/daemons/pigd"
#define PROFILE_D       "/adm/daemons/profiled"
#define RANK_D          "/adm/daemons/rankd"
#define SECURITY_D      "/adm/daemons/securityd"
#define VIRTUAL_D       "/adm/daemons/virtuald"
#define WEAPON_D        "/adm/daemons/weapond"
#define UPDATE_D	"/adm/daemons/updated"
#define TASK_D        "/adm/daemons/questd"
#define CRON_D            "/adm/daemons/cron"
#define STATUS_D	"/adm/daemons/statusd"
#define WHO_D		"/adm/daemons/who_d"
#define STORY_D	        "/adm/daemons/storyd"




//directories
#define CLASS_D(x)      ("/kungfu/class/" + x)
#define SKILL_D(x)      ("/kungfu/skill/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
#define BINGQI_D(x)     ("/clone/weapon/" + x)
#define ARMOR_D(x)      ("/clone/armor/" + x)
#define MEDICINE_D(x)   ("/clone/medicine/" + x)
#define FOOD_D(x)       ("/clone/food/" + x)
#define MISC_D(x)       ("/clone/misc/" + x)
#define NPC_D(x)        ("/clone/npc/" + x)
// 高手排行板
#define RICHMAN_D       "/adm/daemons/tenrichmand"
#define GAOSHOU_D       "/adm/daemons/tengaoshoud"

// Added for questing
// by Hop, 1997.05.16
#define QUESTH_D(x)	("/quest/qhlist" + x)
#define QUESTS_D(x)	("/quest/qslist" + x)
#define QUESTW_D(x)	("/quest/qwlist" + x)

// Clonable/Non-inheritable Standard Objects
#define COIN_OB         "/clone/money/coin"
#define CORPSE_OB       "/clone/misc/corpse"
#define GOLD_OB         "/clone/money/gold"
#define LOGIN_OB        "/clone/user/login"
#define MASTER_OB       "/adm/single/master"
#define MAILBOX_OB      "/clone/misc/mailbox"
#define SILVER_OB       "/clone/money/silver"
#define SIMUL_EFUN_OB   "/adm/single/simul_efun"
#define USER_OB         "/clone/user/user"
#define LOADUSER_OB     "/clone/user/loaduser"
#define VOID_OB         "/clone/misc/void"
// Added for questing
// by Hop, 1997.05.16
#define QUEST_D(x)	("/quest/qlist" + x)
// Inheritable Standard Objects
#define BANK            "/inherit/room/bank"
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define CHARACTER       "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP           "/inherit/misc/equip"
#define FORCE           "/inherit/skill/force"
#define HOCKSHOP        "/inherit/room/hockshop"
#define ITEM            "/inherit/item/item"
#define LIQUID          "/inherit/food/liquid"
#define MONEY           "/inherit/item/money"
#define NPC             "/inherit/char/npc"
#define PILL            "/inherit/medicine/pill"
#define POWDER          "/inherit/medicine/powder"
#define ROOM            "/inherit/room/room"
#define SKILL           "/inherit/skill/skill"

// User IDs

#define ROOT_UID        "Root"
#define BACKBONE_UID    "Backbone"

// Features

#define F_ACTION                "/feature/action.lpc"
#define F_ALIAS                 "/feature/alias.lpc"
#define F_APPRENTICE            "/feature/apprentice.lpc"
#define F_ATTACK                "/feature/attack.lpc"
#define F_ATTRIBUTE             "/feature/attribute.lpc"
#define F_AUTOLOAD              "/feature/autoload.lpc"
#define F_BANKER                "/feature/banker.lpc"
#define F_BOAT                  "/feature/boat.lpc"
#define F_CLEAN_UP              "/feature/clean_up.lpc"
#define F_COMMAND               "/feature/command.lpc"
#define F_CONDITION             "/feature/condition.lpc"
#define F_DAMAGE                "/feature/damage.lpc"
#define F_DBASE                 "/feature/dbase.lpc"
#define F_DEALER                "/feature/dealer.lpc"
#define F_EDIT                  "/feature/edit.lpc"
#define F_DISASTER		"/feature/disaster.lpc"
#define F_EQUIP                 "/feature/equip.lpc"
#define F_FINANCE               "/feature/finance.lpc"
#define F_FOOD                  "/feature/food.lpc"
#define F_LIQUID                "/feature/liquid.lpc"
#define F_MASTER                "/inherit/char/master.lpc"
#define F_MESSAGE               "/feature/message.lpc"
#define F_MORE                  "/feature/more.lpc"
#define F_MOVE                  "/feature/move.lpc"
#define F_NAME                  "/feature/name.lpc"
#define F_PILL                  "/feature/pill.lpc"
#define F_QUEST                 "/feature/quest.lpc"
#define F_SAVE                  "/feature/save.lpc"
#define F_SKILL                 "/feature/skill.lpc"
#define F_TEAM                  "/feature/team.lpc"
#define F_TREEMAP               "/feature/treemap.lpc"
#define F_VENDOR                "/feature/dealer.lpc"
#define F_SSERVER               "/feature/sserver.lpc"
#define F_UNIQUE                "/feature/unique.lpc"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS

// Mathematic
#define MAX(a, b)               ((a) > (b) ? (a) : (b))
#define MIN(a, b)               ((a) < (b) ? (a) : (b))
#define ABS(x)                  ((x) >= 0 ? (x) : -(x))
#define SGN(x)                  ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
#define CT(x)      		(CDTION_DIR  + x)
#define DM(x)			("/adm/daemons/" + x)
#define FT(x)			("/feature/" + x)
#define DIR(x)			(DIS_DIR + x)
#define QUEST(x)		(QUEST_DIR + x)

#define STUNT(x)		(STUNT_DIR   + x)
#define SYS(x)			(SYS_DIR + x)
