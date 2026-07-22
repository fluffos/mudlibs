//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

// the Truth of life
#define TRUE        1
#define FALSE       0
// Directories
//#define private nosave
//#define nosave

#define COMMAND_DIR         "/cmds/"
#define SECURE_CONFIG_DIR   "/etc/"
#define SYSTEM_CONFIG_DIR   "/etc/"
#define CONFIG_DIR          "/etc/"
#define DATA_DIR            "/data/"
#define HELP_DIR            "/help/user/"
#define LOG_DIR             "/log/"
#define SECURE_DIR          "/secure/"
#define SECURE_DAEMON_DIR   SECURE_DIR "daemon/"
#define CLONE_DIR           "/clone/"
#define STD_DIR             "/system/std/"
#define FEATURE_DIR         "/system/feature/"
#define DAEMON_DIR          "/system/daemon/"
#define MENPAI_DIR          "/system/menpai/"
#define ZUZHI_DIR           "/system/zuzhi/"
#define EXERT_DIR           "/system/skill/exert/"
#define PERFORM_DIR         "/system/skill/perform/"
#define TASK_DIR            "/system/task/"
#define TEMP_DIR            "/tmp/"
#define TEMPLATE_DIR        "/template/"

#define MONEY_DIR           CLONE_DIR "money/"
#define SOLDIER_DIR         CLONE_DIR "soldier/"
#define MISC_DIR            CLONE_DIR "misc/"
#define NPC_DIR             CLONE_DIR "npc/"
// clone dir wear
#define WEAR_DIR            CLONE_DIR "wear/"
#define CLOTH_DIR           WEAR_DIR "cloth/"
#define ARMOR_DIR           WEAR_DIR "armor/"
#define BOOTS_DIR           WEAR_DIR "boots/"
#define FINGER_DIR          WEAR_DIR "finger/"
#define HANDS_DIR           WEAR_DIR "hands/"
#define HEAD_DIR            WEAR_DIR "head/"
#define NECK_DIR            WEAR_DIR "neck/"
#define SHIELD_DIR          WEAR_DIR "shield/"
#define SKIRT_DIR           WEAR_DIR "skirt/"
#define SURCOAT_DIR         WEAR_DIR "surcoat/"
#define WAIST_DIR           WEAR_DIR "waist/"
#define WRISTS_DIR          WEAR_DIR "wrists/"

// clone dir weapon
#define WEAPON_DIR          CLONE_DIR "weapon/"
#define SWORD_DIR           WEAPON_DIR "sword/"
#define BLADE_DIR           WEAPON_DIR "blade/"
#define LONG_DIR            WEAPON_DIR "long/"
#define SHORT_DIR           WEAPON_DIR "short/"
#define WHIP_DIR            WEAPON_DIR "whip/"

// clone dir eat
#define EAT_DIR             CLONE_DIR "eat/"
#define FOOD_DIR            EAT_DIR "food/"
#define FRUIT_DIR           EAT_DIR "fruit/"
#define LIQUID_DIR          EAT_DIR "liquid/"

// clone dir book
#define BOOK_DIR            CLONE_DIR "book/"

// clone dir medicine
#define MED_DIR                CLONE_DIR "medicine/"

// log Filename
#define AUTOLOAD_LOG        "autoload"
#define CONDITION_LOG       "condition"
#define MOVE_LOG            "move"
#define DESTRUCT_LOG        "destruct"
#define WRITE_FAIL_LOG      "write_fail"
#define READ_FAIL_LOG       "read_fail"
#define ROOM_LOG            "room_log"
#define PPL_USAGE_LOG       "nosave/usage"
#define WIZ_USAGE_LOG       "nosave/wiz_usage"
#define PURGE_LOG           "acct/purge"
#define COMMAND_LIMIT_LOG   "nosave/command_limit"
#define PROMOTE_LOG         "acct/promote"
#define BAN_LOG				"acct/ban"
#define MULTI_LOGIN_LOG     "nosave/multi_login"
#define WIZ_LOGIN_ERR_LOG   "nosave/wiz_login_err"
#define ACTION_LOG          "nosave/action_log"

//some etc config name
#define BANNED_SITES    SYSTEM_CONFIG_DIR "banned_sites"
#define BANNED_NAME     SYSTEM_CONFIG_DIR "banned_name"
#define BANNED_ID       SYSTEM_CONFIG_DIR "banned_id"
#define MULTI_ALLOW     SYSTEM_CONFIG_DIR "multi.allow" 
#define MULTI_DENY      SYSTEM_CONFIG_DIR "multi.deny"

// Security Daemons

#define PROFILE_D           "/secure/daemon/profiled"
#define SECURITY_D          "/secure/daemon/securityd"

// System Daemons
#define ALLOW_D             DAEMON_DIR "allowd"
#define ALIAS_D             DAEMON_DIR "aliasd"
#define AUTO_D              DAEMON_DIR "autod"
#define BAN_D               DAEMON_DIR "band"
#define BET_D               DAEMON_DIR "betd"
#define BIWU_D              DAEMON_DIR "biwud"
#define CHANNEL_D           DAEMON_DIR "channeld"
#define CHAR_D              DAEMON_DIR "chard"
#define CHINESE_D           DAEMON_DIR "chinesed"
#define COMBAT_D            DAEMON_DIR "combatd"
#define COMMAND_D           DAEMON_DIR "cmd_d"
#define CRIME_D             DAEMON_DIR "crime_d"
#define LOG_D               DAEMON_DIR "log_d"
#define EMOTE_D             DAEMON_DIR "emoted"
#define FINGER_D            DAEMON_DIR "fingerd"
#define INQUIRY_D           DAEMON_DIR "inquiryd"
#define LOGIN_D             DAEMON_DIR "logind"
#define NATURE_D            DAEMON_DIR "natured"
#define PLACE_D             DAEMON_DIR "placed"
#define POISON_D            DAEMON_DIR "poisond"
#define PIG_D               DAEMON_DIR "pig_d"
#define RANK_D              DAEMON_DIR "rankd"
#define SMTP_D              DAEMON_DIR "network/smtp"
#define STATIC_D            DAEMON_DIR "staticd"
#define TOPTEN_D            DAEMON_DIR "toptend"
#define INTERMUD_D          DAEMON_DIR "network/intermud"
#define UPDATE_D            DAEMON_DIR "updated"
#define UNIQUE_D            DAEMON_DIR "uniqued"
#define USER_D              SECURE_DAEMON_DIR "userd"
#define VIRTUAL_D           DAEMON_DIR "virtuald"
#define WEAPON_D            DAEMON_DIR "weapond"
#define REWARD_D            DAEMON_DIR "reward_d"
#define FAMILY_D            DAEMON_DIR "familyd"
#define NEWS_D              DAEMON_DIR "newsd"
#define ZUZHI_D             DAEMON_DIR "zuzhid"
#define TASK_D              DAEMON_DIR "taskd"
#define VRM_SERVER          DAEMON_DIR "vrm_server"
#define SCHEDULE_D          DAEMON_DIR "scheduled"
#define BETRAY_D            DAEMON_DIR "betrayd"
#define APPRENTICE_D        DAEMON_DIR "apprenticed"
#define MAZE_D              DAEMON_DIR "mazed"
#define QINGJIAO_D          DAEMON_DIR "qingjiaod"
#define YUNBIAO_D           DAEMON_DIR "yunbiaod"
#define NPC_D               DAEMON_DIR "npcd"
#define QUEST_D             DAEMON_DIR "questd"
#define OLD_QUEST_D         DAEMON_DIR "old_questd"
#define MONEY_D             DAEMON_DIR "moneyd"
#define EQUIPMENT_D         DAEMON_DIR "equipmentd"
#define TEMPLATE_D          DAEMON_DIR "templated"
#define X_NameD             DAEMON_DIR "x_named"
#define ACTION_D            DAEMON_DIR "actiond"
#define ATTRIBUTE_D         DAEMON_DIR "attributed"
#define AUTOLOAD_D          DAEMON_DIR "autoloadd"
#define INTERACTIVE_D       DAEMON_DIR "interactived"
#define MORE_D              DAEMON_DIR "mored"
#define CLEANUP_D           DAEMON_DIR "cleanupd"
#define CLOSE_D             DAEMON_DIR "closed"
#define ZHOUTIAN_D          DAEMON_DIR "zhoutiand"
#define GIFT_D              DAEMON_DIR "giftd"
#define FUBEN_D             DAEMON_DIR "fubend"
#define MYGIFT_D            DAEMON_DIR "mygiftd"

//Menpai daemons

#define YIPIN_D             MENPAI_DIR "yipind"
#define XUANWU_D            MENPAI_DIR "xuanwud"

#define CLASS_D(x)          ("/system/menpai/" + x)
#define SKILL_D(x)          (call_other(DAEMON_DIR "skilld","find_skill",x)) 
#define KUNGFU_D            DAEMON_DIR "skilld"
#define CONDITION_D(x)      ("/system/condition/" + x)
#define APPLY_D                DAEMON_DIR "applyd"
#define MARRY_D             DAEMON_DIR "marryd"

// Menpai Daemons
#define WULIANG_DIR         MENPAI_DIR "wuliang/"
#define BIAOJU_DIR          MENPAI_DIR "biaoju/"

// Clonable/Non-inheritable Standard Objects

#define BANDAGE_OB          "/clone/misc/bandage"
#define COIN_OB             "/clone/money/coin"
#define CORPSE_OB           "/clone/user/corpse"
#define LOGIN_OB            "/clone/user/login"
#define MASTER_OB           "/secure/daemon/master"
#define MAILBOX_OB          "/clone/misc/mailbox"
#define SILVER_OB           "/clone/money/silver"
#define GOLD_OB             "/clone/money/gold"
#define SIMUL_EFUN_OB       "/secure/daemon/sefun"
#define USER_OB             "/clone/user/user"
#define VOID_OB             "/clone/misc/void"

// Inheritable Standard Objects

#define BANK                STD_DIR "room/bank"
#define BULLETIN_BOARD      STD_DIR "board/bboard"
#define CHARACTER           STD_DIR "char/character"
#define CLASS_GUILD         STD_DIR "room/class_guild"
#define COMBINED_ITEM       STD_DIR "item/combined"
#define CONTAINER           STD_DIR "item/container"
#define PILL                STD_DIR "medicine/pill"
#define POWDE               STD_DIR "medicine/powder"
//#define EQUIP               STD_DIR "equip"
#define HOCKSHOP            STD_DIR "room/hockshop"
#define ITEM                STD_DIR "item/item"
#define BOOK                STD_DIR "item/book"
//#define LIQUID              STD_DIR "liquid"
#define MONEY               STD_DIR "money"
#define NPC                 STD_DIR "char/npc"
#define FILLER              STD_DIR "char/filler"
#define HEALER              STD_DIR "char/healer"
#define RENHE               STD_DIR "char/renhe"
#define TEA                 CLONE_DIR "misc/tea"
#define TREE                STD_DIR "item/tree"
#define ROOM                STD_DIR "room/room"
#define MAZE_ROOM           STD_DIR "room/maze_room"
#define DOOR_ROOM           STD_DIR "room/door_room"
#define KITCHEN_ROOM        STD_DIR "room/kitchen"
#define SLEEP_ROOM          STD_DIR "room/sleep_room"
#define SMITHSHOP           STD_DIR "room/smithshop"
#define SHOP                STD_DIR "room/shop"
#define MARRIAGEROOM        STD_DIR "room/mroom"
#define SOLDIER             "/d/city/capital/npc/soldier0"
#define ROAD                STD_DIR "room/road"
#define SKILL               STD_DIR "skill/skill"
#define SKILL_SWORD         STD_DIR "skill/sword"
#define SKILL_BLADE         STD_DIR "skill/blade"
#define SKILL_DODGE         STD_DIR "skill/dodge"
#define SKILL_UNARMED       STD_DIR "skill/unarmed"
#define SKILL_LONG          STD_DIR "skill/long"
#define SKILL_SHORT         STD_DIR "skill/short"
#define SKILL_FORCE         STD_DIR "skill/force"
#define FORCE_YANG          STD_DIR "skill/force_yang"
#define FORCE_YIN           STD_DIR "skill/force_yin"
#define ART                 STD_DIR "skill/art"
// #define SSERVER             STD_DIR "sserver"
#define ZUZHI               STD_DIR "zuzhi"
// #define TASK                STD_DIR "task"
// #define GROUP_TASK          STD_DIR "group_task"
#define ZUOJI               STD_DIR "char/zuoji"
#define HALL                "/d/place/wiz/inn_hall"
#define STREET              STD_DIR "room/street"
#define PPLROOM             STD_DIR "room/pplroom"
#define VERB                STD_DIR "verb"

// User IDs

#define ROOT_UID            "Root"
#define BACKBONE_UID        "Backbone"

// Features
#define F_ACTION            FEATURE_DIR "char/action"
#define F_ADD_ACTION        FEATURE_DIR "base/add_action"
#define F_ALIAS             FEATURE_DIR "user/alias"
#define F_APPRENTICE        FEATURE_DIR "char/apprentice"
#define F_ATTACK            FEATURE_DIR "char/attack"
#define F_ATTRIBUTE         FEATURE_DIR "char/attribute"
#define F_AUTOSAVE          FEATURE_DIR "user/autosave"
#define F_AUTOLOAD          FEATURE_DIR "user/autoload"
#define F_CLEAN_UP          FEATURE_DIR "base/clean_up"
#define F_COMMAND           FEATURE_DIR "char/command"
#define F_CONDITION         FEATURE_DIR "char/condition"
#define F_CLOTHNAME         FEATURE_DIR "misc/clothname"
#define F_DAMAGE            FEATURE_DIR "char/damage"
#define F_DBASE             FEATURE_DIR "base/dbase"
//#define F_EDIT              FEATURE_DIR "user/edit"
#define F_EDITOR            FEATURE_DIR "user/editor"
//#define F_EQUIP             FEATURE_DIR "item/equip"
// 原equip分成weapon &armor两种 --nerd -- need include weapon.h armor.h
#define F_FINANCE           FEATURE_DIR "char/finance"
#define F_FRUIT             FEATURE_DIR "item/fruit"
#define F_FOOD              FEATURE_DIR "item/food"
#define F_INTERFACE         FEATURE_DIR "user/interface"
#define F_INTERACTIVE       FEATURE_DIR "user/interactive"
#define F_LIQUID            FEATURE_DIR "item/liquid"
#define F_MASTER            STD_DIR "char/master"
#define F_NEW_MASTER        STD_DIR "char/new_master"
#define F_MESSAGE           FEATURE_DIR "user/message"
#define F_MORE              FEATURE_DIR "user/more"
#define F_MOVE              FEATURE_DIR "base/move"
#define F_NAME              FEATURE_DIR "base/name"
#define F_SAVE              FEATURE_DIR "base/save"
#define F_NAMEDATA          FEATURE_DIR "misc/namedata"
#define F_SKILL             FEATURE_DIR "char/skill"
#define F_ART               FEATURE_DIR "char/art"
#define F_TEAM              FEATURE_DIR "char/team"
#define F_TREEMAP           FEATURE_DIR "base/treemap"
#define F_VENDOR            FEATURE_DIR "char/vendor"
#define F_UNIQUE            FEATURE_DIR "item/unique"
#define F_FAMILY            FEATURE_DIR "char/family"

#define BAOXIANG_ITEM       FEATURE_DIR "item/baoxiang"
#define TESSERA             FEATURE_DIR "item/tessera"

#define F_ZUZHI             FEATURE_DIR "char/zuzhi"
//by ppfx
#define KAIFANG             STD_DIR "room/kaifang"
//end ppfx
#define NEWBIE_NPC          "/d/place/newbie/npc/newbie"

#define MAZE_PATH           "/d/maze/"

#define SAVE_EXTENSION          ".o"
#define FILE_EXTENSION          ".lpc"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS

#define EVENT_DIR           "/system/event/"
#define EVENT_LOOK          EVENT_DIR "look"
#define EVENT_GIVE          EVENT_DIR "give"
#endif
