// Update by waiwai@2003/04/10

#pragma save_binary

// 重要的索引目录(Directories)
#define COMMAND_DIR		"/cmds/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR		"/log/"
#define STORY_DIR           "/adm/daemons/story/"
#define TEMP_DIR        "/temp/"
#define DUMP_DIR        "/dump/"
#define BACKUP_DIR      "/backup/"
//#define VERSION_DIR     "/version/"
#define HEIDIAN_DIR     	"/d/obj/heidian/"
#define ITEM_DIR        DATA_DIR "item/"

// 系统精灵后台
#define ONLINE_D              "/adm/daemons/onlined"
#define MPTOP_D               "/adm/daemons/mptopd"
#define VERSION_D       	"/adm/daemons/versiond"
#define DIABLO_D                "/adm/daemons/diablod"
#define COLOR_D		"/adm/daemons/colord"
#define STORY_D                "/adm/daemons/storyd"
#define BACKUP_D     	"/adm/daemons/backupd"
#define CLOSE_D		"/adm/daemons/closed"
#define ALIAS_D		"/adm/daemons/aliasd"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CLUB_D              "/adm/daemons/clubd"
#define CHAR_D		"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define CONVERT_D		"/adm/daemons/convertd"
#define CRON_D             "/adm/daemons/cron"
#define EMOTE_D		"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D		"/adm/daemons/logind"
#define MISC_D		"/adm/daemons/miscd"
#define MONITOR_D		"/adm/daemons/monitord"
#define MONEY_D          "/adm/daemons/moneyd.lpc" 
#define XYJTIME_D          "/adm/daemons/xyjtimed.lpc" 
#define HEIDIAN_D       	"/adm/daemons/heidiand"
#define FAMILY_D       	"/adm/daemons/familyd"
#define NAME_D	       "/adm/daemons/named"
#define NAME2_D	       "/adm/daemons/named2"
#define DIR_D			"/adm/daemons/dird"
#define NEWS_D       	"/adm/daemons/newsd.lpc"
#define NATURE_D		"/adm/daemons/natured"
#define OBSTACLE_D            "/adm/daemons/obstacled"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D		"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define SPELL_D		"/adm/daemons/spelld"
#define SPELL2_D		"/adm/daemons/spelld2"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
#define BAN_D		 	"/adm/daemons/band.lpc"
#define UPEXP_D		"/adm/daemons/upexpd"
#define TASK_D             "/adm/daemons/taskd"
#define ITEM_D          	"/adm/daemons/itemd"
#define DBASE_D       	"/adm/daemons/dbased"
#define TOPTEN_D	       "/adm/daemons/toptend"
#define WEAPONTOP_D	       "/adm/daemons/weapontopd"
#define MESSAGE_D		"/adm/daemons/network/messaged"
#define CONFIG_D       	"/adm/daemons/configd"

#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)		("/daemon/skill/" + x)
#define CONDITION_D(x)	("/daemon/condition/" + x)
#define JOB_D(x)		("/job/"+x+"/")
#define JOB_OB2(x)		("/job/"+x+"/job")
#define JOB_OB(x)		("job/"+x+"/job")
#define CITY_OB(city,room)	("/d/"+city+"/"+room)
#define QJ_OB(city,room)	("/d/qujing/"+city+"/"+room)
#define SPECIAL_D(x)    	("/daemon/special/" + x)

// 可克隆的标准物件
#define COIN_OB		"/obj/money/coin"
#define GOLD_OB       	"/obj/money/gold"
#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB		"/obj/mailbox"
#define SILVER_OB		"/obj/money/silver"
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"
#define USER_OB		"/obj/user"
#define VOID_OB		"/obj/void"
#define TEMP_OB         	"/obj/temp"
#define EXPLORE_OB       	"/obj/explore_ob"
#define DIABLO_BOX            "/obj/diablo_box"

// 可继承的标准物件
#define BANK			"/std/room/bank"
#define BULLETIN_BOARD	"/std/item/bboard"
#define BBS_BOARD		"/std/item/bbsboard"
#define CHARACTER		"/std/char/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM	"/std/item/combined"
#define EQUIP			"/std/item/equip"
#define FORCE			"/std/skill/force"
#define HOCKSHOP		"/std/room/hockshop"
#define ITEM			"/std/item/item"
//#define LIQUID		"/std/liquid"
#define MONEY			"/std/item/money"
#define NPC			"/std/char/npc"
#define NPC_SAVE		"/std/char/npcsave"
#define POWDER		"/std/medicine/powder"
#define QUEST			"/std/quest"
#define ROOM			"/std/room/room"
#define SKILL			"/std/skill/skill"
#define SSERVER		"/std/skill/sserver"
#define KZZNPC		"/std/char/kzznpc"
#define J_BOARD		"/std/item/jboard"
#define RECORD_ROOM		"/std/record_room"
#define POISON_INSECT   	"/std/char/insect"
#define VRM_SERVER           "/std/room/vrm_server"
#define INVENT_SKILL         "/std/skill/invent"

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID	"Backbone"

// Features

#define F_ACTION		"/feature/action.lpc"
#define F_ALIAS		"/feature/alias.lpc"
#define F_APPRENTICE		"/feature/apprentice.lpc"
#define F_ATTACK		"/feature/attack.lpc"
#define F_ATTRIBUTE		"/feature/attribute.lpc"
#define F_AUTOLOAD		"/feature/autoload.lpc"
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
#define F_CONDITION		"/feature/condition.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE		"/feature/dbase.lpc"
#define F_EDIT		"/feature/edit.lpc"
#define F_ENCODING		"/feature/encoding.lpc"
#define F_EQUIP		"/feature/equip.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD		"/feature/food.lpc"
#define F_LIQUID		"/feature/liquid.lpc"
#define F_MASTER		"/std/char/master.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MORE		"/feature/more.lpc"
#define F_MOVE		"/feature/move.lpc"
#define F_NAME		"/feature/name.lpc"
#define F_ONEOWNER		"/feature/oneowner.lpc"
#define F_SAVE		"/feature/save.lpc"
#define F_BACKUP		"/feature/backup.lpc"
#define F_SKILL		"/feature/skill.lpc"
#define F_TEAM		"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_UNIQUE		"/feature/unique.lpc"
#define F_VENDOR		"/feature/vendor.lpc"
#define F_VENDOR_SALE	"/feature/vendor_sale.lpc"
#define F_HEIDIAN       	"/feature/heidian.lpc"
#define F_HEIDIAN_HUOJI 	"/feature/heidian_huoji.lpc"
#define F_NOCLONE          "/feature/noclone.lpc"
#define F_CUTABLE		"/feature/cutable.lpc"
#define F_SILENTDEST	       "/feature/silentdest.lpc"
#define F_CMD              "/feature/cmd_d.lpc"
#define F_ITEMMAKE      "/feature/itemmake.lpc"
#define F_BH			"/feature/banghui.lpc"
#define F_SHADOW       "/feature/shadow.lpc"
#define F_SSERVER       	"/feature/sserver.lpc"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS

// Added by waiwai@2003/06/01
// 可以在 quit 时自动储三件装备，但是要先 wear + secure 才行
#define SAVEEQ	
