// globals.h
// this file will be automatically included by the driver
// for 1.YXCS mudlib, by lonely
#include "ansi.h"

// AGENTS.md finding: this lib's original macro was
// `#define nosave static` / `#define protected static`, guarded by
// `#ifndef __SENSIBLE_MODIFIERS__` -- a macro this driver never predefines
// to LPC code, so the branch always fired, silently turning every
// `nosave <type> name(...)` function declaration in this lib into
// `static <type> name(...)`, a HARD parse error on this driver (AGENTS.md
// #3 -- static is illegal on functions here, only legal on variables).
// convert_lib.sh's blanket static->nosave sed already turned the macro
// BODY text into `#define nosave nosave` (self-mapped, a no-op given the
// preprocessor's "blue paint" rule) which accidentally neutralized the
// nosave half correctly, but also flattened `protected` to `nosave` --
// changing its semantics (DECL_PROTECTED -> DECL_NOSAVE). Both `nosave`
// and `protected` are real, fully-supported keywords on this driver
// (verified empirically), so just let them pass through unchanged.
#ifndef __SENSIBLE_MODIFIERS__
#define protected protected
#endif


// Important directories
#define INC_DIR     "/include/"
#define COMMAND_DIR "/cmds/"
#define CONFIG_DIR  "/adm/etc/"
#define DATA_DIR    "/data/"
#define HELP_DIR    "/doc/"
#define LOG_DIR     "/log/"
#define EVENT_DIR       "/adm/daemons/event/"
//#define QUEST_DIR       "/adm/daemons/quest/"
// Daemons
#define ALIAS_D     "/adm/daemons/aliasd"
#define ADVERSE_D     "/adm/daemons/adversed"
#define BAN_D       "/adm/daemons/band"
#define CHANNEL_D   "/adm/daemons/channeld"
#define LEAGUE_D        "/adm/daemons/leagued"
#define FAMILY_D   "/adm/daemons/familyd"
#define CONFIG_D        "/adm/daemons/configd"
#define DYNAMIC_D        "/adm/daemons/dynamicd"
#define BR_D            "/adm/daemons/brd"
#define NPC_D         "/adm/daemons/npcd"
#define NEWSBOARD   "/d/board/news_b"
#define PK_D            "/adm/daemons/pkd"
#define CHAR_D      "/adm/daemons/chard"
#define CHINESE_D   "/adm/daemons/chinesed"
#define COMBAT_D    "/adm/daemons/combatd"
#define COMMAND_D   "/adm/daemons/commandd"
#define CLOSE_D   "/adm/daemons/closed"
#define EMOTE_D     "/adm/daemons/emoted"
#define FINGER_D    "/adm/daemons/fingerd"
#define FINGER_D2    "/adm/daemons/fingerd2"
#define FTP_D       "/adm/daemons/ftpd"
#define INQUIRY_D   "/adm/daemons/inquiryd"
#define LOGIN_D     "/adm/daemons/logind"
#define MONEY_D     "/adm/daemons/moneyd"
#define NATURE_D    "/adm/daemons/natured"
#define PIG_D       "/adm/daemons/pigd"
#define PROFILE_D   "/adm/daemons/profiled"
#define VERSION_D       "/adm/daemons/versiond"
#define RANK_D      "/adm/daemons/rankd"
#define NAME_D      "/adm/daemons/named"
#define SECURITY_D  "/adm/daemons/securityd"
#define UPDATE_D    "/adm/daemons/updated"
#define UNIQUE_D        "/adm/daemons/uniqued"
#define EVENT_D         "/adm/daemons/eventd"
#define VIRTUAL_D   "/adm/daemons/virtuald"
#define MONITOR_D   "/adm/daemons/monitord"
#define WEAPON_D    "/adm/daemons/weapond"
#define LANGUAGE_D  "/adm/daemons/languaged"
#define STATUS_D    "/adm/daemons/statud"
#define TASK_D       "/adm/daemons/questd"
#define JOB_D       "/adm/daemons/taskd"
#define CRON_D       "/adm/daemons/cron"
// Added for questing
// by Hop, 1997.05.16
#define QUEST_D(x)  ("/quest/qlist" + x)
#define QUESTH_D(x)     ("/quest/qhlist" + x)
#define QUESTS_D(x)     ("/quest/qslist" + x)
#define QUESTW_D(x)     ("/quest/qwlist" + x)

// End of appendence
#define CLASS_D(x)  ("/kungfu/class/" + x)
#define JOB_OB(x)              ("/job/"+x+"/job")
#define SKILL_D(x)  ("/kungfu/skill/" + x)
#define SPECIAL_D(x)    ("/kungfu/special/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
// Clonable/Non-inheritable Standard Objects
#define CORPSE_OB   "/clone/misc/corpse"
#define LOGIN_OB    "/clone/user/login"
#define MASTER_OB   "/adm/obj/master"
#define MAILBOX_OB  "/clone/misc/mailbox"
#define THGOLD_OB   "/clone/money/thousand-gold" 
#define THCASH_OB   "/clone/money/thousand-cash"
#define GOLD_OB     "/clone/money/gold"
#define SILVER_OB   "/clone/money/silver"
#define COIN_OB     "/clone/money/coin"
#define CHALLENGER      "/inherit/char/challenger"
#define SIMUL_EFUN_OB   "/adm/obj/simul_efun"
#define USER_OB     "/clone/user/user"
#define VOID_OB     "/clone/misc/void"
// Inheritable Standard Objects
#define BULLETIN_BOARD  "/inherit/misc/bbsboard"
#define BULETIN_BOARD  "/u/lonely/inherit/bboard.lpc"
#define BULLETIN_JBOARD "/inherit/misc/jboard"
#define CHARACTER   "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP       "/inherit/misc/equip"
#define FORCE       "/inherit/skill/force"
#define HOCKSHOP    "/inherit/room/hockshop"
#define ITEM        "/inherit/item/item"
#define LIQUID      "/inherit/food/liquid"
#define MONEY       "/inherit/item/money"
#define NPC     "/inherit/char/b_npc"
#define PILL        "/inherit/medicine/pill"
#define POWDER      "/inherit/medicine/powder"
#define ROOM        "/inherit/room/room"
#define BABY        "/inherit/char/baby"
#define FERRY           "/inherit/room/ferry"
#define SKILL       "/inherit/skill/skill"
#define MAGIC          "/inherit/magic/magic.lpc"
#define SELL_SALT   "/inherit/char/sell_salt"
#define NPC_SAVE	"/inherit/char/npcsave"
// #define BHNPC       "/u/lonely/banghui/bhnpc"
#define BH_NPC       "/inherit/char/bh_npc"
#define F_BH                    "/feature/banghui.lpc"
#define QUEST            "/inherit/quest"
#define GUANFU                  "/u/lonely/inherit/guanfu"

// #define USER-ROOM   "/inherit/room/user_room"
// User IDs
#define ROOT_UID    "Root"
#define BACKBONE_UID    "Backbone"
// Features
#define F_ACTION        "/feature/action.lpc"
#define F_ALIAS         "/feature/alias.lpc"
#define F_APPRENTICE        "/feature/apprentice.lpc"
#define F_ATTACK        "/feature/attack.lpc"
#define F_ATTRIBUTE     "/feature/attribute.lpc"
#define F_AUTOLOAD      "/feature/autoload.lpc"
#define F_CLEAN_UP      "/feature/clean_up.lpc"
#define F_COMMAND       "/feature/command.lpc"
#define F_CONDITION     "/feature/condition.lpc"
#define F_DAMAGE        "/feature/damage.lpc"
#define F_DBASE         "/feature/dbase.lpc"
#define F_DEALER        "/feature/dealer.lpc"
#define F_EDIT          "/feature/edit.lpc"
#define F_EQUIP         "/feature/equip.lpc"
#define F_FINANCE       "/feature/finance.lpc"
#define F_FOOD          "/feature/food.lpc"
#define F_LIQUID        "/feature/liquid.lpc"
#define F_MASTER        "/inherit/char/master.lpc"
#define F_MESSAGE       "/feature/message.lpc"
#define F_MORE          "/feature/more.lpc"
#define F_MOVE          "/feature/move.lpc"
#define F_NAME          "/feature/name.lpc"
#define F_RIDDING           "/feature/ridding.lpc"
#define F_ONEOWNER          "/feature/oneowner.lpc"
#define F_SAVE          "/feature/save.lpc"
#define F_BACKUP     "/feature/backup.lpc"
#define F_SKILL         "/feature/skill.lpc"
#define F_TEAM          "/feature/team.lpc"
#define F_TREEMAP       "/feature/treemap.lpc"
#define F_VENDOR        "/feature/dealer.lpc"
#define F_SSERVER       "/feature/sserver.lpc"
// AGENTS.md #8g (missing-#define variant): bare `SSERVER`/`F_NOCLONE` are
// referenced by a handful of files (5 skill files, 4 boss-NPC files) but
// were never #define'd anywhere in this archive -- a hard hard compile
// error (`inherit SSERVER;`/`inherit F_NOCLONE;` parse as "inherit
// <undefined identifier>", not a string). SSERVER is just the un-prefixed
// name for the already-existing F_SSERVER mixin (identical
// offensive_target() helper in both feature/sserver.lpc and
// inherit/sserver.lpc). F_NOCLONE is never implemented as its own file
// anywhere in the archive, but every sibling boss-NPC file with the same
// shape (`inherit NPC; inherit F_MASTER; inherit F_UNIQUE;`) uses F_UNIQUE
// for exactly this "only one instance may exist" semantics, so F_NOCLONE
// is aliased to it rather than fabricated from scratch.
#define SSERVER         F_SSERVER
#define F_NOCLONE       F_UNIQUE
#define F_UNIQUE        "/feature/unique.lpc"
#define F_UNIQUE1         "/u/lonely/feature/unique.lpc"
#define F_BANKER        "/feature/banker.lpc"

#define SKILL_MODEL_UNARMED    "/meskill/skill_model_unarmed.lpc"

#define SKILL_MODEL_WEAPON     "/meskill/skill_model_weapon.lpc"
#define SKILL_MODEL_DEFAULT    "/meskill/skill_model_default.lpc"
#define F_VENDOR_SALE		"/feature/vendor_sale.lpc"
#define F_BVENDOR        "/u/lonely/banghui/vendor.lpc"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.
#define BACKUP_DIR              "/backup/"
#define BACKUP_D                 "/adm/daemons/backupd.lpc"
#define STORY_D                 "/adm/daemons/storyd.lpc"
#define STORY_DIR               "/adm/daemons/story/"
#define DUMP_DIR                                "/bak/dump/"
#define TEMP_DIR                                "/temp/"
#define SAVE_EXTENSION ".o"
#undef PROFILE_COMMANDS
