// file: globals.h

#pragma save_binary

#define DRUG_D(x)               ("/clone/drug/" + x)
#define HERB_D(x)               ("/clone/herb/" + x)
#define JOB_OB(x)               ("/d/job/"+x+"/job")
#define CITY_OB(city,room)      ("/d/"+city+"/"+room)

// 重要的索引目录(Directories)
#define COMMAND_DIR             "/cmds/"
#define CONFIG_DIR              "/adm/etc/"
#define DATA_DIR                "/data/"
#define HELP_DIR                "/doc/"
#define LOG_DIR                 "/log/"
#define BACKUP_DIR              "/backup/"

// 系统精灵后台(Daemons)
#define DBASE_D                 "/adm/daemons/dbased"
#define TOPTEN_D                "/adm/daemons/toptend"
#define ALIAS_D                 "/adm/daemons/aliasd"
#define CHANNEL_D               "/adm/daemons/channeld"
#define CHAR_D                  "/adm/daemons/chard"
#define CHINESE_D               "/adm/daemons/chinesed"
#define COMBAT_D                "/adm/daemons/combatd"
#define COMMAND_D               "/adm/daemons/cmd_d"
#define CONVERT_D               "/adm/daemons/convertd"
#define CONFIG_D                "/adm/daemons/configd"
#define EMOTE_D                 "/adm/daemons/emoted"
#define FINGER_D                "/adm/daemons/fingerd"
#define INQUIRY_D               "/adm/daemons/inquiryd"
#define LOGIN_D                 "/adm/daemons/logind"
#define CLUB_D                  "/adm/daemons/clubd"
#define MISC_D                  "/adm/daemons/miscd"
#define MONITOR_D               "/adm/daemons/monitord"
#define NATURE_D                "/adm/daemons/natured"
#define OBSTACLE_D              "/adm/daemons/obstacled"
#define PROFILE_D               "/adm/daemons/profiled"
#define RANK_D                  "/adm/daemons/rankd"
#define SECURITY_D              "/adm/daemons/securityd"
#define SPELL_D                 "/adm/daemons/spelld"
#define UPDATE_D                "/adm/daemons/updated"
#define VERSION_D               "/adm/daemons/versiond"
#define VIRTUAL_D               "/adm/daemons/virtuald"
#define WEAPON_D                "/adm/daemons/weapond"
#define WSAVE_D                 "/adm/daemons/w_saved"
#define USER_WEAPOND            "/adm/daemons/user_weapond" 
#define BAN_D                   "/adm/daemons/band.lpc"
#define MONEY_D                 "/adm/daemons/moneyd.lpc"
#define TOPTEN_D                "/adm/daemons/toptend"
#define TASK_D                  "/adm/daemons/questd"
#define CRON_D                  "/adm/daemons/cron"
#define DISASTER_D              "/adm/daemons/disasterd"
#define COLOR_D                 "/adm/daemons/colord"
#define CPU_D                   "/adm/daemons/cpud" 
#define MSG_D                   "/adm/daemons/msgd"
#define CLASS_D(x)              ("/daemon/class/" + x)
#define SKILL_D(x)              ("/daemon/skill/" + x)
#define CONDITION_D(x)          ("/daemon/condition/" + x)
#define RTIME_D                 "/cmds/usr/ttime"
#define NEWS_D                  "/cmds/usr/news"
#define DIR_D                   "/adm/daemons/dird"
//#define BANGHUI_D                   "/adm/daemons/banghuid"
#define NAME_D                  "/adm/daemons/named"
#define ITEM_D                  "/adm/daemons/itemd" 
//Addby Snowtu@xmxyj2000/2004
#define PERFORM_D                  "/adm/daemons/performd" 
//snowtu add by 2011 迷宫副本
#define MAZE_D     "/adm/daemons/mazed"
#define VRM_SERVER    "/adm/daemons/vrm_server"

// 可克隆的标准物件
#define COIN_OB                 "/obj/money/coin"
#define CORPSE_OB               "/obj/corpse"
#define LOGIN_OB                "/obj/login"
#define MASTER_OB               "/adm/obj/master"
#define MAILBOX_OB              "/obj/mailbox"
#define SILVER_OB               "/obj/money/silver"
#define SIMUL_EFUN_OB           "/adm/obj/simul_efun"
#define USER_OB                 "/obj/user"
#define VOID_OB                 "/obj/void"

// 可继承的标准物件
#define PRIVATE_ROOM            "/inherit/room/privateroom"
#define BANK                    "/std/room/bank"
#define BULLETIN_BOARD          "/std/bboard"
#define BBS_BOARD               "/std/bbsboard"
#define CHARACTER               "/std/char"
#define CLASS_GUILD             "/std/room/class_guild"
#define COMBINED_ITEM           "/std/item/combined"
#define EQUIP                   "/std/equip"
#define FORCE                   "/std/force"
#define HOCKSHOP                "/std/room/hockshop"
#define ITEM                    "/std/item"
#define LIQUID                  "/std/liquid"
#define MONEY                   "/std/money"
#define NPC                     "/std/char/npc"
#define NPC_SAVE                "/std/char/npcsave"
#define POWDER                  "/std/medicine/powder"
#define QUEST                   "/std/quest"
#define ROOM                    "/std/room"
#define MAGIC_ROOM              "/std/magicroom"
#define SKILL                   "/std/skill"
#define SSERVER                 "/std/sserver"
#define SELLYAO                 "/std/room/sellyao"
//#define COMBINE                 "/std/room/combine"
//#define MAZE                    "/u/koker/files/maze"
//AddBy Snowtu
#define PERFORM                 "/std/perform"
#define FABAO                 "/std/fabao"

// User IDs
#define ROOT_UID                "Root"
#define BACKBONE_UID            "Backbone"

// Features
#define F_OBSAVE                "/feature/obsave.lpc"
#define F_ACTION                "/feature/action.lpc"
#define F_ALIAS                 "/feature/alias.lpc"
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
#define F_ENCODING              "/feature/encoding.lpc"
#define F_EQUIP                 "/feature/equip.lpc"
#define F_FINANCE               "/feature/finance.lpc"
#define F_FOOD                  "/feature/food.lpc"
#define F_LIQUID                "/feature/liquid.lpc"
#define F_MASTER                "/std/char/master.lpc"
#define F_MESSAGE               "/feature/message.lpc"
#define F_MORE                  "/feature/more.lpc"
#define F_MOVE                  "/feature/move.lpc"
#define F_NAME                  "/feature/name.lpc"
#define F_ONEOWNER              "/feature/oneowner.lpc"
#define F_SAVE                  "/feature/save.lpc"
#define F_BACKUP                "/feature/backup.lpc"
#define F_SKILL                 "/feature/skill.lpc"
#define F_TEAM                  "/feature/team.lpc"
#define F_TREEMAP               "/feature/treemap.lpc"
#define F_UNIQUE                "/feature/unique.lpc"
#define F_VENDOR                "/feature/vendor.lpc"
#define F_VENDOR_SALE           "/feature/vendor_sale.lpc"
#define STORY_DIR               "/clone/gift/"
#define STORY_D                 "/adm/daemons/storyd.lpc"
#define F_YAO                   "/feature/yaocai.lpc"
#define F_DISASTER                "/feature/disaster.lpc"

//topten
#define TOPTEN_EXP     "/topten/exp.o"
#define TOPTEN_DAOHENG     "/topten/daoheng.o"
#define TOPTEN_LEVEL     "/topten/level.o"
#define TOPTEN_AGE     "/topten/age.o"
#define TOPTEN_RICH     "/topten/rich.o"
#define TOPTEN_FORCE     "/topten/force.o"
#define TOPTEN_MANA     "/topten/mana.o"
#define TOPTEN_QUESTS     "/topten/quests.o"
#define TOPTEN_KILL     "/topten/kill.o"
#define TOPTEN_DEAD     "/topten/dead.o"
#define TOPTEN_ZHUZAO     "/topten/zhuzao.o"
#define TOPTEN_TASK     "/topten/task.o"
#define TOPTEN_LITERATE     "/topten/literate.o"
#define TOPTEN_MEDICAL     "/topten/medical.o"
#define TOPTEN_TIANFU     "/topten/tianfu.o"
#define TOPTEN_UNARMED     "/topten/unarmed.o"
#define TOPTEN_DODGE     "/topten/dodge.o"
#define TOPTEN_SWORD     "/topten/sword.o"
#define TOPTEN_BLADE     "/topten/blade.o"
#define TOPTEN_STICK     "/topten/stick.o"
#define TOPTEN_STAFF     "/topten/staff.o"
#define TOPTEN_WHIP     "/topten/whip.o"

#define EXP_B          "【  西游记--神魔传说十大武学至尊  】"
#define DAOHENG_B          "【  西游记--神魔传说十大道高德隆  】"
#define LEVEL_B          "【  西游记--神魔传说十大等级狂飙  】"
#define AGE_B          "【  西游记--神魔传说十大寿比南山  】"
#define RICH_B          "【  西游记--神魔传说十大富可敌国  】"
#define FORCE_B          "【  西游记--神魔传说十大内功精湛  】"
#define MANA_B          "【  西游记--神魔传说十大法力高深  】"
#define QUESTS_B          "【  西游记--神魔传说十大解谜圣手  】"
#define KILL_B          "【  西游记--神魔传说十大冷血杀手  】"
#define DEAD_B          "【  西游记--神魔传说十大快乐死神  】"
#define ZHUZAO_B          "【  神州十大铸造大师  】"
#define TASK_B          "【  西游记--神魔传说十大神书大成  】"
#define LITERATE_B          "【  西游记--神魔传说十大圣学鸿儒  】"
#define MEDICAL_B          "【  当世十大妙手神医  】"
#define TIANFU_B          "【  西游记--神魔传说十大绝世天资  】"
#define UNARMED_B          "【  神拳无敌震五岳  】"
#define DODGE_B          "【  凌空渡虚傲三界  】"
#define SWORD_B          "【  天下十大无敌剑魔  】"
#define BLADE_B          "【  宇内十大霸绝刀皇  】"
#define STICK_B          "【  擎天一棍舞十方  】"
#define STAFF_B          "【  海内十大逍遥杖客  】"
#define WHIP_B          "【  西游记--神魔传说十绝鞭  】"

//sds
#define SDS_D		"/adm/daemons/sdsd"
#define SDS_ROOM(x)	("/d/圣斗士/room/"+x)
#define SDS_NPC(x)	("/d/圣斗士/npc/"+x)
#define SDS_OBJ(x)	("/d/圣斗士/item/"+x)
#define SDS_BOOK(x)	("/d/圣斗士/item/book/"+x)
#define SDS_FOOD(x)	("/d/圣斗士/item/food/"+x)
#define SDS_DRUG(x)	("/d/圣斗士/item/drug/"+x)
#define SDS_W(x)	("/d/圣斗士/item/weapon/"+x)
#define SDS_IN(x)	("/d/圣斗士/include/"+x)
#define SROOM		"/std/sroom"
#define BOSS		"/std/char/boss"

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS

