//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

#pragma save_binary

#ifndef __SENSIBLE_MODIFIERS__
/* compatibility shim neutralized: nosave and protected are real
   keywords on this driver (AGENTS 4.3) */
#endif

/* #undef of driver-predefined values is illegal on this driver */
#undef _NO_ANSI___

#define JOB_OB(x)		("/d/job/"+x+"/job")
#define CITY_OB(city,room)   ("/d/"+city+"/"+room)
// Directories

#define BACKUP_DIR      "/u/backup/"
#define COMMAND_DIR		"/cmds/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR			"/log/"
#define RING_DIR        "/u/mudring/"
// mudring ...
#define WIZARD_ROOM        "/adm/npc/wizroom"

// Daemons
#define TOPTEN_D	        "/adm/daemons/toptend"
#define ALIAS_D			"/adm/daemons/aliasd"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define CONVERT_D       "/adm/daemons/gb_b5d"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define CLUB_D			"/adm/daemons/clubd"
#define PARTY_D          "/adm/daemons/partyd"
// mon@xiyouji 10/19/98
#define MISC_D		        "/adm/daemons/miscd"
// added by snowcat 6/20/1997
#define BJTIME_D                "/cmds/usr/bjtime"
#define MONITOR_D		"/adm/daemons/monitord"
#define NATURE_D		"/adm/daemons/natured"
#define OBSTACLE_D              "/adm/daemons/obstacled"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define SPELL_D		        "/adm/daemons/spelld"
#define LEAGUE_D        "/adm/daemons/leagued"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
#define WSAVE_D                "/adm/daemons/w_saved"
#define BAN_D		 "/adm/daemons/band.lpc"
#define MONEY_D		 "/adm/daemons/moneyd.lpc"
#define XYJTIME_D          "/adm/daemons/xyjtimed.lpc" 
#define TOPTEN_D	        "/adm/daemons/toptend"
#define TASK_D                  "/adm/daemons/questd"
#define CRON_D                  "/adm/daemons/cron"
#define DISASTER_D              "/adm/daemons/disasterd"
#define COLOR_D                  "/adm/daemons/colord"
#define NEWS_D                  "/adm/daemons/newsd"
#define NAME_D                  "/adm/daemons/named"
#define NPC_D                   "/adm/daemons/npcd"
#define QUIZ_D                   "/adm/daemons/quizd"
#define CITY_D                   "/adm/daemons/cityd"
#define PFM_D                   "/adm/daemons/pfmd"
#define STATU_D                 "/adm/daemons/statud"
#define PKMANAGER_D                 "/adm/daemons/pk_manager"
//加入等级自动升级系统by koker@2004/06/16
#define UPEXP_D		        "/adm/daemons/upexpd"

#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)              ("/daemon/skill/" + x)
// 75  #define SKILL_D(x)          (call_other("/adm/daemons/skilld", "find_skill", x))
#define CONDITION_D(x)	("/daemon/condition/" + x)
#define BINGQI_D(x)              ("/d/obj/weapon/" + x)

// Clonable/Non-inheritable Standard Objects

#define COIN_OB			"/obj/money/coin"
#define CORPSE_OB               "/obj/misc/corpse"
#define GOLD_OB                 "/obj/money/gold"
#define LOGIN_OB                "/obj/user/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB              "/obj/misc/mailbox"
#define SILVER_OB		"/obj/money/silver"
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"
#define USER_OB                 "/obj/user/user"
#define VOID_OB                 "/obj/misc/void"
#define EMPTY_OB                 "/obj/misc/empty"

// Inheritable Standard Objects

#define BANK			"/std/room/bank"
#define BULLETIN_BOARD        "/std/misc/bboard"
#define BBS_BOARD               "/std/misc/bbsboard"
#define CHARACTER               "/std/char/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM	"/std/item/combined"
#define EQUIP                   "/std/misc/equip"
#define FORCE                   "/std/skill/force"
#define HOCKSHOP		"/std/room/hockshop"
#define ITEM                    "/std/item/item"
#define LIQUID                  "/std/misc/liquid"
#define MONEY                   "/std/item/money"
#define NPC			"/std/char/npc"
#define NPC_SAVE		"/std/char/npcsave"
#define POWDER			"/std/medicine/powder"
#define QUEST                   "/std/misc/quest"
#define ROOM                    "/std/room/room"
#define CROOM                   "/std/room/cleanroom"
#define SKILL                   "/std/skill/skill"
#define SSERVER                 "/std/skill/sserver"
#define YUEQI                 "/std/item/yueqi"
#define JOBNPC                "/std/char/jobnpc"
#define PARTY                "/std/char/party"

#define HELL_ROOM             "/std/room/hellroom"
#define MOFENG_ROOM             "/std/room/mofengroom"
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
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
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
#define F_SSERVER                  "/feature/sserver.lpc"
#define F_BACKUP		"/feature/backup.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_UNIQUE		"/feature/unique.lpc"
#define F_VENDOR		"/feature/vendor.lpc"
#define F_VENDOR_SALE		"/feature/vendor_sale.lpc"
#define F_SHADOW       "/feature/shadow.lpc"
#define STORY_DIR	        "/clone/gift/"
#define STORY_D	        "/adm/daemons/storyd.lpc"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS
// add for cmds me
#define F_VI               "/feature/vi.lpc"
#define CLOSE_D               "/adm/daemons/closed"
#define MUSIC_D               "/adm/daemons/musicd"
#define EXAMINE_D               "/adm/daemons/examined"
#define F_NOCLONE               "/feature/noclone.lpc"
#define INSTALL_COMBAT_TEST     1
#define NWEAPON_D               "/adm/daemons/nweapond"
