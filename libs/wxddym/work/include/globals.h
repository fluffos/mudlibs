// globals.h
// this file will be automatically included by the driver
#include "ansi.h"
#include "zjmud.h"
#include "tomud.h"
#define crypt oldcrypt

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected static
#else
#define private protected
#define static nosave
#endif

#define BUSY_MESSAGE    "你现在忙得很，无法做任何事情。\n"
// Important directories
#define TEMPLATE_DIR            "/template/"
#define GROUP_QUEST_DIR         "/adm/daemons/group_quest/"
#define GROUP_QUEST_D           "/adm/daemons/group_questd"
#define WORK_DIR                "/adm/daemons/work/"
#define TEMPLATE_D              "/adm/daemons/templated"
#define ABILITY_D               "/adm/daemons/abilityd"
#define ACTION_D                "/adm/daemons/actiond"
#define AHACK_D                 "/adm/daemons/ahackerd"
#define ANALECTA_D              "/adm/daemons/analectad"
#define ARENA_D                 "/adm/daemons/arenad"
#define BABY                    "/inherit/char/baby"
#define BAOXIANG_ITEM           "/inherit/item/baoxiang"
#define BBASE_D                 "/adm/daemons/bbased"
#define BOOK                    "/inherit/item/book"
#define BUFF_D                  "/adm/daemons/buffd"
#define BULLETIN_JBOARD         "/inherit/misc/jboard"
#define BUSINESS_D              "/adm/daemons/businessd"
#define CHOUQIAN                "/inherit/misc/chouqian"
#define COMPETE_D               "/adm/daemons/competed"
#define CONFIG_D                "/adm/daemons/configd"
#define CONTEST_D               "/adm/daemons/contestd"
#define CRON_D                  "/adm/daemons/crond"
#define CRUISE_D                "/adm/daemons/cruised"
#define DATABASE_BOARD          "/inherit/misc/dboard"
#define DATABASE_D              "/adm/daemons/databased"
#define DEMONROOM               "/inherit/room/demonroom"
#define DRUG_D(x)               ("/clone/drug/" + x)
#define EXPLIST                 "/clone/quest/explist"
#define F_BACKUP                "/feature/backup.c"
#define F_BUSINESS              "/feature/business.c"
#define F_DTIME                 "/feature/dtime.c"
#define F_EQUIP_LIV             "/feature/equip_liv.c"
#define F_FIRST                 "/inherit/char/first.c"
#define F_FRUIT                 "/feature/fruit.c"
#define F_NATURE                "/feature/nature.c" 
#define F_QUEST                 "/feature/quest.c"
#define F_SHELL                 "/feature/shell.c"
#define F_SILENTDEST            "/feature/silentdest.c"
#define F_VI                    "/feature/vi.c"
#define FAE                     "/adm/npc/fa-e"
#define FESTIVAL_D              "/adm/daemons/festivald"
#define HTML_D                  "/adm/daemons/html_d"
#define IDENTIFY_D              "/adm/daemons/identifyd"
#define INTERMUD2_D             "/adm/daemons/intermud2_d" 
#define MAIL_D                  "/adm/daemons/maild"
#define MAP_D                   "/adm/daemons/mapd"
#define MASTER_D                "/adm/daemons/masterd"
#define MENGZHU                 "/adm/npc/meng-zhu"
#define MESSAGE_D               "/adm/daemons/network/messaged"
#define MINE_D                   /adm/daemons/mined
#define MODULE_D                "/adm/daemons/moduled"
#define MONITOR_D               "/adm/daemons/monitord"
#define MRTG_D                  "/adm/daemons/mrtgd"
#define MUDLIST_D               "/adm/daemons/mudlistd"
#define NAMES_D                 "/adm/daemons/namesd"
#define NPC_SAVE                "/inherit/char/npcsave"
#define NPC_TRAINEE             "/inherit/char/trainee"
#define NUMBER_D                "/adm/daemons/numberd"
#define PARTY_QUEST_D           "/adm/daemons/party_questd"
#define PIG_ROOM                "/inherit/room/pigroom"
#define QUEST                   "/inherit/quest"
#define REALNEWS_D              "/adm/daemons/realnewsd"
#define RESTROOM_IN             "/inherit/room/restroom_in"
#define RESTROOM_OUT            "/inherit/room/restroom_out"
#define RIVER                   "/inherit/room/river"
#define SCBORN_D                "/adm/daemons/scbornd"
#define SERIAL_NUMBER_D         "/adm/daemons/serial_numberd"
#define SHANGSHAN               "/adm/npc/shang-shan"
#define SHOP                    "/inherit/room/shop"
#define SKI_ZHEN                "/inherit/skill/array"
#define SKYBOOK_D               "/adm/daemons/skybookd"
#define SMITH                   "/inherit/char/smith"
#define SMTP_D                  "/adm/daemons/smtpd"
#define SOCKET_D                "/adm/daemons/socketd"
#define STOCK_D                 "/adm/daemons/stockd"
#define SYSTEM_D                "/adm/daemons/systemd"
#define TASK                    "/inherit/item/task"
#define TESSERA                 "/inherit/item/tessera"
#define THCASH_OB               "/clone/money/thousand-cash"
#define THGOLD_OB               "/clone/money/thousand-gold"
#define TIME_D                  "/adm/daemons/timed"
#define TOPTEN_D                "/adm/daemons/toptend"
#define USER_OB                 "/clone/user/user"
#define WAITER                  "/inherit/char/waiter"
#define WAR_D                   "/adm/daemons/ward"
#define WAREHOUSE               "/inherit/room/warehouse"
#define WORK_D                  "/adm/daemons/workd"
#define X_PointD                "/adm/daemons/x_pointd"
#define X_QuestD                "/adm/daemons/x_questd"
#define ULTRA_QUEST_D           "/adm/etc/magic_item"
#define TASK_D                  "/adm/daemons/taskd"
#define FAMILY_D	"/adm/daemons/familyd"
#define TOP_D	 	"/adm/daemons/topd"

#define GROUP_QUEST_DIR         "/adm/daemons/group_quest/"
#define BACKUP_DIR      "/backup/"
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR      "/adm/etc/"
#define DATA_DIR        "/data/"
#define DUMP_DIR        "/dump/"
#define EVENT_DIR       "/adm/daemons/event/"
#define HELP_DIR        "/help/"
#define INC_DIR         "/include/"
#define ITEM_DIR        DATA_DIR "item/"
#define LOG_DIR         "/log/"
#define QUEST_DIR       "/adm/daemons/quest/"
#define	SHADOW_DIR	"/shadow/"
#define STORY_DIR       "/adm/daemons/story/"
#define TEMP_DIR        "/temp/"
#define BUNCHER                 "/inherit/char/buncher"
#define ARMOR_DIR               "/clone/armor/"              //护具
#define WEAPON_DIR              "/clone/weapon/"             //兵器
#define BOOK_DIR                "/clone/book/"               //书籍
#define MONEY_DIR               "/clone/money/"              //货币
#define ANIMAL_DIR              "/clone/animal/"             //动物
#define JEWELRY_DIR             "/clone/jewelry/"            //珠宝
#define FOOD_DIR                "/clone/food/"               //食物
#define FRUIT_DIR               "/clone/food/fruit/"         //水果
#define LIQUID_DIR              "/clone/food/liquid/"        //饮料
#define TEA_DIR                 "/clone/food/tea/"           //茶水
#define FODDER_DIR              "/clone/food/fodder/"        //饲料
#define CLOTH_DIR               "/clone/cloth/"              //衣服
#define HEAD_DIR                "/clone/cloth/head/"         //盔帽
#define BOOT_DIR                "/clone/cloth/boot/"         //鞋靴
#define NOSTRUM_DIR             "/clone/medicine/nostrum/"   //成药
#define POISON_DIR              "/clone/medicine/poison/"    //毒药
#define VEGETABLE_DIR           "/clone/medicine/vegetable/" //草药
#define SHOP_DIR                "/clone/shop/"               //商店
#define BUNCH_D                 "/adm/daemons/bunchd"
#define BATTLEFIELD_D           "/adm/daemons/battlefieldd"
#define BOARD_D                 "/adm/daemons/boardd"
#define FUBEN_D                 "/adm/daemons/fubend"
//#define GIFT_D                  "/adm/daemons/giftd"
// Daemons
#define EQUIPMENT_D             "/adm/daemons/equipmentd"
#define DB_D                    "/adm/daemons/dbd"
#define WABAO_D                    "/adm/daemons/wabaod"
#define ALIAS_D         "/adm/daemons/aliasd"
#define BAN_D           "/adm/daemons/band"
#define BACKUP_D        "/adm/daemons/backupd"
#define CHANNEL_D       "/adm/daemons/channeld"
#define CHAR_D          "/adm/daemons/chard"
#define CHINESE_D       "/adm/daemons/chinesed"
#define CLOSE_D         "/adm/daemons/closed"
#define COMBAT_D        "/adm/daemons/combatd"
#define COMMAND_D       "/adm/daemons/commandd"
#define HISTORY_D               "/adm/daemons/historyd
#define LANGUAGE_D              "/adm/daemons/languaged"
#define MEMBER_D                "/adm/daemons/memberd"
#define CPU_D           "/adm/daemons/cpud"
#define ULTRA_D        "/adm/daemons/ultra_questd"
#define GIFT_D 		"/adm/daemons/giftd"
#define DBASE_D         "/adm/daemons/dbased"
#define EMOTE_D         "/adm/daemons/emoted"
#define EVENT_D         "/adm/daemons/eventd"
#define EXAMINE_D       "/adm/daemons/examined"
#define FINGER_D        "/adm/daemons/fingerd"
#define FTP_D           "/adm/daemons/ftpd"
#define RANK_D          "/adm/daemons/rankd"
#define INQUIRY_D       "/adm/daemons/inquiryd"
#define ITEM_D          "/adm/daemons/itemd"
#define LEAGUE_D        "/adm/daemons/leagued"
#define LOGIN_D         "/adm/daemons/logind"
#define MAZE_D          "/adm/daemons/mazed"
#define MONEY_D         "/adm/daemons/moneyd"
#define NAME_D          "/adm/daemons/named"
#define NATURE_D        "/adm/daemons/natured"
#define NEWS_D          "/adm/daemons/newsd"
#define NPC_D           "/adm/daemons/npcd"
#define PIG_D           "/adm/daemons/pigd"
#define PK_D            "/adm/daemons/pkd"
#define PROFILE_D       "/adm/daemons/profiled"
#define QUEST_D         "/adm/daemons/questd"
#define RANK_D          "/adm/daemons/rankd"
#define SECURITY_D      "/adm/daemons/securityd"
#define SKILLS_D        "/adm/daemons/skillsd"
#define SCHEDULE_D      "/adm/daemons/scheduled"
#define STORY_D         "/adm/daemons/storyd"
#define UPDATE_D        "/adm/daemons/updated"
#define VERSION_D       "/adm/daemons/versiond"
#define VRM_SERVER      "/adm/daemons/vrm_server"
#define VIRTUAL_D       "/adm/daemons/virtuald"
#define WEAPON_D        "/adm/daemons/weapond"
#define WEEKLY_D	"/adm/daemons/weeklyd"
#define VIP_D	        "/adm/daemons/vipd"
#define SHOP_D                  "/adm/daemons/shopd"
#define XINRUI_D                "/adm/daemons/xinruid"
#define ZHOUTIAN_D              "/adm/daemons/zhoutiand"
#define XYWAR_D                 "/adm/daemons/xyward"
#define X_NameD                 "/adm/daemons/x_named"

#define CLASS_D(x)      ("/kungfu/class/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
#define SKILL_D(x)      ("/kungfu/skill/" + x)
#define SPECIAL_D(x)    ("/kungfu/special/" + x)
#define replace_program(x)    ""




// Clonable/Non-inheritable Standard Objects
#define COIN_OB         "/clone/money/coin"
#define CORPSE_OB       "/clone/misc/corpse"
#define GOLD_OB         "/clone/money/gold"
#define LOGIN_OB        "/clone/user/login"
#define MASTER_OB       "/adm/single/master"
#define MAILBOX_OB      "/clone/misc/mailbox"
#define SILVER_OB       "/clone/money/silver"
#define SIMUL_EFUN_OB   "/adm/single/simul_efun"
#define TEMP_OB         "/clone/misc/temp"
#define VOID_OB         "/clone/misc/void"
#define QUESTH_D(x)	("/quest/qhlist" + x)
#define QUESTS_D(x)	("/quest/qslist" + x)
#define QUESTW_D(x)	("/quest/qwlist" + x)

// Inheritable Standard Objects
#define BANK            "/inherit/room/bank"
#define BUILD_ROOM      "/inherit/room/buildroom"
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define CHALLENGER      "/inherit/char/challenger"
#define CHARACTER       "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP           "/inherit/misc/equip"
#define FIGHTER         "/inherit/char/fighter"
#define FORCE           "/inherit/skill/force"
#define HOCKSHOP        "/inherit/room/hockshop"
#define ILLNESS         "/inherit/condition/illness"
#define ITEM            "/inherit/item/item"
#define KNOWER          "/inherit/char/knower"
#define LIQUID          "/inherit/food/liquid"
#define MONEY           "/inherit/item/money"
#define NPC             "/inherit/char/npc"
#define PILL            "/inherit/medicine/pill"
#define POISON          "/inherit/condition/poison"
#define POISON_INSECT   "/inherit/char/insect"
#define POWDER          "/inherit/medicine/powder"
#define PRIVATE_ROOM    "/inherit/room/privateroom"
#define ROOM            "/inherit/room/room"
#define SHAOLIN_SKILL   "/inherit/skill/shaolin"
#define SKILL           "/inherit/skill/skill"
#define SNAKE           "/inherit/char/snake"
#define BOSS                    "/inherit/char/boss"
#define QUARRY                  "/inherit/char/quarry"
#define WORM                    "/inherit/char/worm"
#define DREAM_NPC               "/inherit/char/dream_npc"
// User IDs
#define ROOT_UID        "Root"
#define BACKBONE_UID    "Backbone"
#define MYGIFT_D                "/adm/daemons/mygiftd"
// Features
#define EQUIP_SOUL              "/inherit/item/equipsoul"
#define F_ACTION        "/feature/action.c"
#define F_ALIAS         "/feature/alias.c"
#define F_APPRENTICE    "/feature/apprentice.c"
#define F_ATTACK        "/feature/attack.c"
#define F_ATTRIBUTE     "/feature/attribute.c"
#define F_AUTOLOAD      "/feature/autoload.c"
#define F_BANKER        "/feature/banker.c"
#define F_CLEAN_UP      "/feature/clean_up.c"
#define F_COAGENT       "/feature/coagent.c"
#define F_COMMAND       "/feature/command.c"
#define F_CONDITION     "/feature/condition.c"
#define F_CUTABLE       "/feature/cutable.c"
#define F_DAMAGE        "/feature/damage.c"
#define F_DBASE         "/feature/dbase.c"
#define F_DEALER        "/feature/dealer.c"
#define F_EDIT          "/feature/edit.c"
#define F_EQUIP         "/feature/equip.c"
#define F_FINANCE       "/feature/finance.c"
#define F_FOOD          "/feature/food.c"
#define F_GUARDER       "/feature/guarder.c"
#define F_ITEMMAKE      "/feature/itemmake.c"
#define F_LIQUID        "/feature/liquid.c"
#define F_MASTER        "/feature/master.c"
#define F_MESSAGE       "/feature/message.c"
#define F_MORE          "/feature/more.c"
#define F_MOVE          "/feature/move.c"
#define F_NAME          "/feature/name.c"
#define F_NOCLONE       "/feature/noclone.c"
#define F_OBSAVE        "/feature/obsave.c"
#define F_PUNISHER      "/feature/punisher.c"
#define F_QUESTER       "/feature/quester.c"
#define F_SAVE          "/feature/save.c"
#define F_SHADOW        "/feature/shadow.c"
#define F_SKILL         "/feature/skill.c"
#define F_SSERVER       "/feature/sserver.c"
#define F_TEAM          "/feature/team.c"
#define F_TRANSPORT     "/feature/transport.c"
#define F_TREEMAP       "/feature/treemap.c"
#define F_VENDOR        "/feature/dealer.c"
#define F_UNIQUE        "/feature/unique.c"
#define F_LEVEL        "/feature/level.c"
#define F_SUIT                "/feature/suit.c"           //套装
//
#define SKILL_MODEL_UNARMED    "/clone/meskill/skill_model_unarmed.h"
#define SKILL_MODEL_WEAPON     "/clone/meskill/skill_model_weapon.h"
#define SKILL_MODEL_DEFAULT    "/clone/meskill/skill_model_default.h"

// music instructment
#define F_XIAO          "/inherit/misc/_xiao.c"

#define SAVE_EXTENSION          ".o"
#define FILE_EXTENSION          ".c"
#define TEMPLATE_DIR            "/template/"
// Others

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it
// in effect.

// Install information
#define INSTALL_COMBAT_TEST     1

#undef PROFILE_COMMANDS
