// globals.h

// Improve function

#define new_ob(str)     new(resolve_path(__DIR__, str))
#define move_to_ob(ob)  move(resolve_path(__DIR__, ob))

// Important directories


#define BACKUP_DIR      "/backup/"
#define SAVE_EXTENSION  ".o"
#define INC_DIR         "/include/"
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR      "/adm/etc/"
#define DATA_DIR        "/data/"
#define DUMP_DIR        "/dump/"
#define EVENT_DIR       "/adm/daemons/event/"
#define HELP_DIR        "/help/"
#define ITEM_DIR        DATA_DIR "item/"
#define LOG_DIR         "/log/"
#define QUEST_DIR       "/adm/daemons/quest/"
#define	SHADOW_DIR	"/shadow/"
#define STORY_DIR       "/adm/daemons/story/"
#define TEMP_DIR        "/temp/"

#define NO_MUDLIST      0

// Daemons

#define ALIAS_D         "/adm/daemons/aliasd"
#define BAN_D           "/adm/daemons/band"
#define BASE64_D        "/adm/daemons/base64_d"
#define CHANNEL_D       "/adm/daemons/channeld"
#define CHAR_D          "/adm/daemons/chard"
#define CHINESE_D       "/adm/daemons/chinesed"
#define CLOSE_D         "/adm/daemons/closed"
#define COMBAT_D        "/adm/daemons/combatd"
#define COMMAND_D       "/adm/daemons/commandd"
#define CONFIG_D        "/adm/daemons/configd"
#define CPU_D           "/adm/daemons/cpud"
#define DBASE_D         "/adm/daemons/dbased"
#define DEFEND_D        "/adm/daemons/defendd"
#define EMOTE_D         "/adm/daemons/emoted"
#define EVENT_D         "/adm/daemons/eventd"
#define EXAMINE_D       "/adm/daemons/examined"
#define FAMILY_D        "/adm/daemons/familyd"
#define FINGER_D        "/adm/daemons/fingerd"
#define FTP_D           "/adm/daemons/ftpd"
#define INQUIRY_D       "/adm/daemons/inquiryd"
#define ITEM_D          "/adm/daemons/itemd"
#define LEAGUE_D        "/adm/daemons/leagued"
#define LOGIN_D         "/adm/daemons/logind"
#define MAP_D           "/adm/daemons/mapd"
#define MESSAGE_D       "/adm/daemons/network/messaged"
#define MONEY_D         "/adm/daemons/moneyd"
#define MUSIC_D         "/adm/daemons/musicd"
#define NAME_D          "/adm/daemons/named"
#define NATURE_D        "/adm/daemons/natured"
#define NEWS_D          "/adm/daemons/newsd"
#define NPC_D           "/adm/daemons/npcd"
#define PIG_D           "/adm/daemons/pigd"
#define PK_D            "/adm/daemons/pkd"
#define PROFILE_D       "/adm/daemons/profiled"
#define QUEST_D         "/adm/daemons/questd"
#define RANK_D          "/adm/daemons/rankd"
#define RECITE_D        "/adm/daemons/recited"
#define SECURITY_D      "/adm/daemons/securityd"
#define SMTP_D          "/adm/daemons/smtp_d"
#define STORY_D         "/adm/daemons/storyd"
#define TASK_D          "/adm/daemons/taskd"
#define VERSION_D       "/adm/daemons/versiond"
#define VIRTUAL_D       "/adm/daemons/virtuald"
#define UPDATE_D        "/adm/daemons/updated"
#define WEAPON_D        "/adm/daemons/weapond"

// Directories

#define CLASS_D(x)      ("/kungfu/class/" + x)
#define SKILL_D(x)      ("/kungfu/skill/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
#define BINGQI_D(x)     ("/clone/weapon/" + x)
#define ARMOR_D(x)      ("/clone/armor/" + x)
#define MEDICINE_D(x)   ("/clone/medicine/" + x)
#define FOOD_D(x)       ("/clone/food/" + x)
#define MISC_D(x)       ("/clone/misc/" + x)
#define NPC_DIR(x)      ("/clone/npc/" + x)
#define SPECIAL_D(x)    ("/kungfu/special/" + x)

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
#define TEMP_OB         "/clone/misc/temp"
#define VOID_OB         "/clone/misc/void"

// Inheritable Standard Objects

#define BANK            "/inherit/room/bank"
#define BULLETIN_BOARD  "/inherit/misc/bbsboard"
#define BUILD_ROOM      "/inherit/room/buildroom"
#define CHATROOM_BOARD  "/clone/board/chatboard"
#define CHALLENGER      "/inherit/char/challenger"
#define CHARACTER       "/inherit/char/char"
#define CHATROOM        "/inherit/room/chatroom"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP           "/inherit/misc/equip"
#define FORCE           "/inherit/skill/force"
#define FIGHTER         "/inherit/char/fighter"
#define HOCKSHOP        "/inherit/room/hockshop"
#define ITEM            "/inherit/item/item"
#define KNOWER          "/inherit/char/knower"
#define LIQUID          "/inherit/food/liquid"
#define MONEY           "/inherit/item/money"
#define NPC             "/inherit/char/npc"
#define PILL            "/inherit/medicine/pill"
#define POWDER          "/inherit/medicine/powder"
#define ROOM            "/inherit/room/room"
#define SKILL           "/inherit/skill/skill"
#define SMITH           "/inherit/char/smith"
#define VRM_SERVER      "/inherit/room/vrm_server"
#define YUEQI           "/inherit/item/yueqi"

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
#define F_CUTABLE               "/feature/cutable.lpc"
#define F_DAMAGE                "/feature/damage.lpc"
#define F_DBASE                 "/feature/dbase.lpc"
#define F_DEALER                "/feature/dealer.lpc"
#define F_EDIT                  "/feature/edit.lpc"
#define F_EQUIP                 "/feature/equip.lpc"
#define F_FINANCE               "/feature/finance.lpc"
#define F_FOOD                  "/feature/food.lpc"
#define F_GUARDER               "/feature/guarder.lpc"
#define F_ITEMMAKE              "/feature/itemmake.c
#define F_LIQUID                "/feature/liquid.lpc"
#define F_MASTER                "/feature/master.lpc"
#define F_MESSAGE               "/feature/message.lpc"
#define F_MORE                  "/feature/more.lpc"
#define F_MOVE                  "/feature/move.lpc"
#define F_NAME                  "/feature/name.lpc"
#define F_NOCLONE               "/feature/noclone.lpc"
#define F_OBSAVE                "/feature/obsave.lpc"
#define F_PUNISHER              "/feature/punisher.lpc"
#define F_PILL                  "/feature/pill.lpc"
#define F_QUEST                 "/feature/quest.lpc"
#define F_QUESTER               "/feature/quester.lpc"
#define F_SAVE                  "/feature/save.lpc"
#define	F_SILENTDEST            "/feature/silentdest.lpc"
#define F_SKILL                 "/feature/skill.lpc"
#define F_RNAME                 "/feature/random_name.lpc"
#define F_TEAM                  "/feature/team.lpc"
#define F_TREEMAP               "/feature/treemap.lpc"
#define F_VENDOR                "/feature/dealer.lpc"
#define F_SHADOW                "/feature/shadow.lpc"
#define F_SSERVER               "/feature/sserver.lpc"
#define F_TRANSPORT             "/feature/transport.lpc"
#define F_UNIQUE                "/feature/unique.lpc"

// Status

#define ADM                     "(admin)"
#define ARC                     "(arch)"
#define WIZ                     "(wizard)"
#define APP                     "(apprentice)"
#define IMM                     "(immortal)"
#define PLA                     "(player)"

// Profiling switches

#undef PROFILE_COMMANDS

// Mathematic

#define MAX(a, b)               ((a) > (b) ? (a) : (b))
#define MIN(a, b)               ((a) < (b) ? (a) : (b))
#define ABS(x)                  ((x) >= 0 ? (x) : -(x))
#define SGN(x)                  ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))

