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
#define private protected
#define nosave nosave
#define this thisa

#define COMMAND_DIR         "/cmds/"
#define SECURE_CONFIG_DIR   "/secure/etc/"
#define SYSTEM_CONFIG_DIR   "/system/etc/"
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

// Filename

#define AUTOLOAD_LOG        "autoload"
#define CONDITION_LOG       "condition"
#define MOVE_LOG            "move"
#define DESTRUCT_LOG        "destruct"
#define WRITE_FAIL_LOG      "write_fail"
#define READ_FAIL_LOG       "read_fail"
#define ROOM_LOG            "room_log"
#define PPL_USAGE_LOG       "nosave/usage"
#define WIZ_USAGE_LOG       "nosave/wiz_usage"
#define PURGE_LOG           "nosave/purge"
#define COMMAND_LIMIT_LOG   "nosave/command_limit"
#define PROMOTE_LOG         "nosave/promote"
#define MULTI_LOGIN_LOG     "nosave/multi_login"
#define WIZ_LOGIN_ERR_LOG   "nosave/wiz_login_err"
#define ACTION_LOG          "nosave/action_log"

// Security Daemons

#define PROFILE_D           "/secure/daemon/profiled"
#define SECURITY_D          "/secure/daemon/securityd"

// System Daemons

#define ALLOW_D             DAEMON_DIR "allowd"
#define ALIAS_D             DAEMON_DIR "aliasd"
#define AUTO_D              DAEMON_DIR "autod"
#define BAN_D               DAEMON_DIR "band"
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
#define RANK_D              DAEMON_DIR "rankd"
#define SMTP_D              DAEMON_DIR "network/smtp"
#define INTERMUD_D          DAEMON_DIR "network/intermud"
#define UPDATE_D            DAEMON_DIR "updated"
#define UNIQUE_D            DAEMON_DIR "uniqued"
#define USER_D              SECURE_DAEMON_DIR "userd"
#define VIRTUAL_D           DAEMON_DIR "virtuald"
#define WEAPON_D            DAEMON_DIR "weapond"
#define REWARD_D            DAEMON_DIR "reward_d"
#define FAMILY_D            DAEMON_DIR "familyd"
#define ZUZHI_D             DAEMON_DIR "zuzhid"
//#define TASK_D            DAEMON_DIR "taskd"

//Menpai daemons

#define YIPIN_D             MENPAI_DIR "yipind"
#define XUANWU_D            MENPAI_DIR "xuanwud"

#define CLASS_D(x)          ("/system/menpai/" + x)
#define SKILL_D(x)          (call_other(DAEMON_DIR "skilld","find_skill",x)) 
#define CONDITION_D(x)      ("/system/condition/" + x)
#define APPLY_D                DAEMON_DIR "applyd"
#define MARRY_D             DAEMON_DIR "marryd"

// Menpai Daemons
#define WULIANG_DIR         MENPAI_DIR "wuliang/"
#define WULIANG_D           WULIANG_DIR "wuliang_d"
#define BIAOJU_DIR          MENPAI_DIR "biaoju/"
#define BIAOJU_D            BIAOJU_DIR "biaoju_d"

// Clonable/Non-inheritable Standard Objects

#define BANDAGE_OB          "/clone/misc/bandage"
#define COIN_OB             "/clone/money/coin"
#define CORPSE_OB           "/clone/user/corpse"
#define LOGIN_OB            "/clone/user/login"
#define MASTER_OB           "/secure/daemon/master"
#define MAILBOX_OB          "/clone/misc/mailbox"
#define SILVER_OB           "/clone/money/silver"
#define SIMUL_EFUN_OB       "/secure/daemon/sefun"
#define USER_OB             "/clone/user/user"
#define VOID_OB             "/clone/misc/void"

// Inheritable Standard Objects

#define BANK                STD_DIR "room/bank"
#define BULLETIN_BOARD      STD_DIR "board/bboard"
#define CHARACTER           STD_DIR "char/character"
#define CLASS_GUILD         STD_DIR "room/class_guild"
#define COMBINED_ITEM       STD_DIR "item/combined"
#define PILL                STD_DIR "medicine/pill"
#define POWDE               STD_DIR "medicine/powder"
//#define EQUIP               STD_DIR "equip"
#define FORCE               STD_DIR "skill/force"
#define HOCKSHOP            STD_DIR "room/hockshop"
#define ITEM                STD_DIR "item/item"
//#define LIQUID              STD_DIR "liquid"
#define MONEY               STD_DIR "money"
#define NPC                 STD_DIR "char/npc"
#define FILLER              STD_DIR "char/filler"
#define HEALER              STD_DIR "char/healer"
#define RENHE               STD_DIR "char/renhe"
#define TEA                 CLONE_DIR "misc/tea"
#define TREE                STD_DIR "item/tree"
#define ROOM                STD_DIR "room/room"
#define SMITHSHOP           STD_DIR "room/smithshop"
#define SHOP                STD_DIR "room/shop"
#define MARRIAGEROOM        STD_DIR "room/mroom"
#define SOLDIER             "/d/city/capital/npc/soldier0"
#define ROAD                STD_DIR "room/road"
#define SKILL               STD_DIR "skill/skill"
// #define SSERVER             STD_DIR "sserver"
#define ZUZHI               STD_DIR "zuzhi"
// #define TASK                STD_DIR "task"
// #define GROUP_TASK          STD_DIR "group_task"
#define ZUOJI               STD_DIR "char/zuoji"
#define HALL                "/d/place/wiz/inn_hall"
#define STREET              STD_DIR "room/street"
#define PPLROOM             STD_DIR "room/pplroom"

// User IDs

#define ROOT_UID            "Root"
#define BACKBONE_UID        "Backbone"

// Features
#define F_ACTION            FEATURE_DIR "char/action.lpc"
#define F_ADD_ACTION        FEATURE_DIR "base/add_action.lpc"
#define F_ALIAS             FEATURE_DIR "user/alias.lpc"
#define F_APPRENTICE        FEATURE_DIR "char/apprentice.lpc"
#define F_ATTACK            FEATURE_DIR "char/attack.lpc"
#define F_ATTRIBUTE         FEATURE_DIR "char/attribute.lpc"
#define F_AUTOSAVE          FEATURE_DIR "user/autosave.lpc"
#define F_AUTOLOAD          FEATURE_DIR "user/autoload.lpc"
#define F_CLEAN_UP          FEATURE_DIR "base/clean_up.lpc"
#define F_COMMAND           FEATURE_DIR "char/command.lpc"
#define F_CONDITION         FEATURE_DIR "char/condition.lpc"
#define F_CLOTHNAME         FEATURE_DIR "misc/clothname.lpc"
#define F_DAMAGE            FEATURE_DIR "char/damage.lpc"
#define F_DBASE             FEATURE_DIR "base/dbase.lpc"
#define F_EDIT              FEATURE_DIR "user/edit.lpc"
//#define F_EQUIP             FEATURE_DIR "item/equip.lpc"
// 原equip分成weapon &armor两种 --nerd -- need include weapon.h armor.h
#define F_FINANCE           FEATURE_DIR "char/finance.lpc"
#define F_FRUIT             FEATURE_DIR "item/fruit.lpc"
#define F_FOOD              FEATURE_DIR "item/food.lpc"
#define F_LIQUID            FEATURE_DIR "item/liquid.lpc"
#define F_MASTER            STD_DIR "char/master.lpc"
#define F_MESSAGE           FEATURE_DIR "user/message.lpc"
#define F_MORE              FEATURE_DIR "user/more.lpc"
#define F_MOVE              FEATURE_DIR "base/move.lpc"
#define F_NAME              FEATURE_DIR "base/name.lpc"
#define F_SAVE              FEATURE_DIR "base/save.lpc"
#define F_NAMEDATA          FEATURE_DIR "misc/namedata.lpc"
#define F_SKILL             FEATURE_DIR "char/skill.lpc"
#define F_TEAM              FEATURE_DIR "char/team.lpc"
#define F_TREEMAP           FEATURE_DIR "base/treemap.lpc"
#define F_VENDOR            FEATURE_DIR "char/vendor.lpc"
#define F_UNIQUE            FEATURE_DIR "item/unique.lpc"
#define F_FAMILY            FEATURE_DIR "char/family.lpc"
#define F_ZUZHI             FEATURE_DIR "char/zuzhi.lpc"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS

#endif
