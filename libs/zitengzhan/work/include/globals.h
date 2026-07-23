//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)
// AGENTS.md §15z: this was originally an old-driver compatibility shim
// (#define nosave static / #define protected static) for a driver that
// didn't understand nosave/protected as real keywords. __SENSIBLE_MODIFIERS__
// is never defined by this FluffOS build, so the shim was always active;
// after AGENTS.md §3's blanket static->nosave sed it became
// "#define protected nosave", silently aliasing protected to nosave.
// Both keywords are real and correctly-behaving natively on this driver --
// neutralized entirely, no translation needed.
#if 0
#ifndef __SENSIBLE_MODIFIERS__
#define nosave nosave
#define protected nosave
#endif
#endif
#pragma save_binary
#define JOB_OB(x)		("/job/"+x+"/job")
#define CITY_OB(city,room)   ("/d/"+city+"/"+room)
//added by Beeby @ DTXY for TOPTEN
#define TOPTEN_RICH     "/data/topten/rich.o"
#define TOPTEN_PKER     "/data/topten/pker.o"
#define TOPTEN_EXP      "/data/topten/exp.o"
#define TOPTEN_DAOXING  "/data/topten/daoxing.o"
#define TOPTEN_SHEN1    "/data/topten/shen1.o"
#define TOPTEN_SHEN2    "/data/topten/shen2.o"
#define TOPTEN_neili    "/data/topten/neili.o"
#define TOPTEN_PER1     "/data/topten/per1.o"
#define TOPTEN_PER2     "/data/topten/per2.o"
#define TOPTEN_AGE      "/data/topten/age.o"
#define TOPTEN_POTENTIAL "/data/topten/potential.o"
#define TOPTEN_NINEMI   "/data/topten/ninemi.o"
#define TOPTEN_KXCD   "/data/topten/kxcd.o"
#define RICH_B          "十大富人"
#define PKER_B          "十大恶人"
#define EXP_B           "十大武林高手"
#define DAOXING_B	"十大得道真仙"
#define POTENTIAL_B	"十大潜在高手"
#define SHEN1_B         "十大魔头"
#define SHEN2_B         "十大法力高手"
#define neili_B         "十大内力高手"
#define PER1_B          "十大白马王子"
#define PER2_B          "十大梦中情人"
#define AGE_B           "十大老不死"
#define NINEMI_B        "十大九迷高手"
#define KXCD_B        "十大知识高手"
#define TOPTEN_D        "/adm/daemons/toptend"

// Directories

#define COMMAND_DIR		"/cmds/"
#define QUEST_DIR       "/adm/daemons/quest/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define STORY_DIR                "/story/"
#define HELP_DIR		"/doc/"
#define BACKUP_DIR      	"/backup/"
#define LOG_DIR			"/log/"
#define PLAYERCITY_DIR      "/data/playercity/"
#define PLAYERCITY_FILE_DIR      "/d/playercity/"
#define VRM_DIR              "/d/room/vr_room/" //迷宫
#define VRM_NPC              "/d/npc/vr_room/"  //迷宫

// Daemons
#define MAZE_D          "/adm/daemons/mazed"
#define MAZE_OB         "/u/nanf/maze/mazes"
#define GIFT_D          "/adm/daemons/giftd"
#define VIRTUAL_D        "/adm/daemons/virtuald"  //迷宫
#define VRM_SERVER        "/std/room/vrm_server"  //迷宫
#define ALIAS_D			"/adm/daemons/aliasd"
#define TEAMK_D                 "/adm/daemons/teamkd"
#define BR_D                 "/adm/daemons/brd"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define CONVERT_D		"/adm/daemons/convertd"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define CLUB_D			"/adm/daemons/clubd"
#define CPU_D                   "/adm/daemons/cpud"
// mon@xiyouji 10/19/98
#define MISC_D		        "/adm/daemons/miscd"
// added by snowcat 6/20/1997
#define MONITOR_D		"/adm/daemons/monitord"
#define NATURE_D		"/adm/daemons/natured"
#define NPC_D                   "/adm/daemons/npcd"
#define OBSTACLE_D              "/adm/daemons/obstacled"
#define QUEST_D              "/u/pujing/quest"
#define PFM_D                   "/adm/daemons/pfmd"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define SPELL_D		        "/adm/daemons/spelld"
#define STORY_D                 "/adm/daemons/storyd"
#define MONEY_D                 "adm/daemons/moneyd"
#define UPDATE_D		"/adm/daemons/updated"
//#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
#define BAN_D		 	"/adm/daemons/band.lpc"
#define TASK_D                  "/adm/daemons/questd"
#define CRON_D                  "/adm/daemons/cron"
#define COLOR_D                 "/adm/daemons/colord"
#define TITLE_D	               "/adm/daemons/titled.lpc"         //huarong 2003.7
#define IP_D                    "/adm/daemons/ipd.lpc"         //huarong 2004/9
#define CLASS_D(x)              ("/daemon/skill/" + x)
#define SKILL_D(x)		("/daemon/skill/" + x)
#define CONDITION_D(x)	("/daemon/condition/" + x)
#define ZYSKILL_D(x)		("/daemon/zyskill/" + x)
#define QUESTS_D          "/adm/daemons/quests"  //wsw 20051015 任务总管

// Clonable/Non-inheritable Standard Objects

#define COIN_OB			"/obj/money/coin"
#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB		"/obj/mailbox"
#define SILVER_OB		"/obj/money/silver"
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"
#define NEWITEMS_OB "/d/obj/newitem/newitems"
#define NEWITEMS_DIR 	"/d/obj/newitem"

// Inheritable Standard Objects

#define BANK			"/std/room/bank"
#define BULLETIN_BOARD	       "/std/bboard"
#define SCORESHEET	       "/std/scoresheet"
#define BBS_BOARD		"/std/bbsboard"
#define CHARACTER		"/std/char"
#define CHARACTER2               "/std/char2"

#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM	"/std/item/combined"
#define EQUIP			"/std/equip"
#define FORCE			"/std/force"
#define HOCKSHOP		"/std/room/hockshop"
#define ITEM			"/std/item"
#define KZZNPC			"/std/char/kzznpc"
#define LIQUID			"/std/liquid"
#define MONEY			"/std/money"
#define NPC			"/std/char/npc"
#define NPC_SAVE		"/std/char/npcsave"
#define POWDER			"/std/medicine/powder"
#define QUEST			"/std/quest"
#define ROOM			"/std/room"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"
#define SSSERVER                   "/std/ssserver"
#define WARPLACE                "/d/zhanchang/warplace"
#define CJNPC_EASY              "/std/char/cjnpc_easy"//huarong 2003/10
#define ZYSKILL			"/std/zyskill"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID	"Backbone"

// Features

#define F_ACTION		"/feature/action.lpc"
#define F_ALIAS			"/feature/alias.lpc"
#define F_APPRENTICE	"/feature/apprentice.lpc"
#define F_ATTACK		"/feature/attack.lpc"
#define F_ATTRIBUTE		"/feature/attribute.lpc"
#define F_AUTOLOAD		"/feature/autoload.lpc"
#define F_BH           		"/feature/banghui.lpc"
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
#define F_COMMAND2               "/feature/command2.lpc"

#define F_CONDITION		"/feature/condition.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_EDIT			"/feature/edit.lpc"
#define F_ENCODING		"/feature/encoding.lpc"
#define F_EQUIP			"/feature/equip.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD			"/feature/food.lpc"
#define F_LIQUID		"/feature/liquid.lpc"
#define F_MASTER		"/std/char/master.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MORE			"/feature/more.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_ONEOWNER		"/feature/oneowner.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_BACKUP		"/feature/backup.lpc"
#define F_FUNCTION                "/feature/function.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_TEAM			"/feature/team.lpc"
#define F_QUESTER       "/feature/quester.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_UNIQUE		"/feature/unique.lpc"
#define F_UNIQUECHECK           "/feature/uniquecheck.lpc"
#define F_VENDOR		"/feature/vendor.lpc"
#define F_VENDOR_SALE		"/feature/vendor_sale.lpc"
#define F_LOCATION	        "/adm/daemons/locationd.lpc"
#define LOCATIOND	        "/adm/daemons/locationd.lpc"
#define NAME_D	        "/adm/daemons/named.lpc"
#define ROBOT_D	        "/adm/daemons/robotd.lpc"
#define F_ZYSKILL			"/feature/zyskill.lpc"
#define        __OFF__                0  //迷宫开关
#define        __ON__                1
#define        __AUTO__            2

#define        RDM_VRM_SUPPORT            __OFF__    
//    是否开放随机刷新的迷宫

#define        VRM_0001_SUPPORT        __ON__
//    是否开放迷宫：埋骨之地

#define        VRM_0002_SUPPORT        __ON__
//    是否开放迷宫：天外天

#define        VRM_0003_SUPPORT        __ON__
//    是否开放迷宫：镇魔塔林

#define        VRM_0004_SUPPORT        __ON__
//    是否开放迷宫：血海冥河

#define        VRM_0005_SUPPORT        __ON__
//    是否开放迷宫：上古洪荒

#define        VRM_0011_SUPPORT        __ON__
//    是否开放迷宫：归墟

#define        VRM_0501_SUPPORT        __ON__
//    是否开放迷宫：蛇洞

#define        VRM_0502_SUPPORT        __ON__
//    是否开放迷宫：试炼之地

// nanf
#define KEE ({"kee"})
#define SEN ({"sen"})
#define BOTH ("kee","sen")

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS
