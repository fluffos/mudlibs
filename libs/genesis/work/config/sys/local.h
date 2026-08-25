/*
  /local.h

  This file contains all world specific information. To configure your
  own world and set up your own mud, make changes to this file.

  This file is configured for Genesis.

*/
#ifndef CONFIG_DEFINED
#define CONFIG_DEFINED

/*
 *
 * MUD_NAME
 *
 * The name of the mud. This will be defined in all files compiled.
 * It is either a single string or a mapping of one names for each
 * port it might be running on. '0' in the mapping means default name.
 *
 */
/* This driver already predefines MUD_NAME (from config.fluffos's "name"
 * directive) as a plain string macro -- redefining it here as a mapping
 * hard-errors ("Illegal to redefine a predefined value"). master.lpc's
 * get_mud_name() already handles the stringp(MUD_NAME) case, so we just
 * drop this mudlib-side #define and let the driver's own value win. */


/*
 * DEFAULT_WIZARDS
 *
 * This array contains the default setup of wizards of this LPmud.
 *
 * FluffOS PORT NOTE: every entry below is only 5 elements
 * ({rank, level, chlevel, dom, chdom}), but secure/master/fob.lpc's
 * own FOB_WIZ_* field constants define 8 (through FOB_WIZ_STUDENTS,
 * index 7) -- e.g. query_restrict() indexes FOB_WIZ_RESTRICT (5)
 * unconditionally once sizeof(m_wizards[wiz]) is nonzero, with no
 * per-field bounds check, so a short entry hard-errors ("Array index
 * out of bounds") the first time ANY of these default wizards (not
 * just "fluffos", added below) hits a restrict/mentor/students check
 * -- for "fluffos" specifically, that happened on the very first
 * "update" command. Padded every entry to the full 8-element shape
 * with the neutral default for each field (0 restrictions, no mentor,
 * no students) -- structural completion of the field shape
 * FOB_WIZ_STUDENTS already documents, not invented wizard content.
 *
 * "fluffos" itself (WIZ_KEEPER, top rank, matching "lars") is this
 * onboarding project's standard admin/test account, per this
 * project's standard admin-seeding procedure -- registered as a plain
 * mortal through the normal "new" flow FIRST (secure/login.lpc
 * refuses new-character registration for any name already present
 * here, since that's meant to catch "someone's trying to steal a
 * wizard's name"), *then* granted rank by adding the entry here
 * afterward. Every other entry is genuine pre-existing upstream
 * content (just padded, not otherwise changed).
 */
#define DEFAULT_WIZARDS ([ \
    "postmaster":({7,35,"root","Genesis","root",0,"",({})}), \
    "wiz":({7,35,"root","Wiz","root",0,"",({})}), \
    "mrpr":({8,50,"root","Wiz","root",0,"",({})}), \
    "lars":({9,50,"root","Wiz","root",0,"",({})}), \
    "tintin":({8,50,"root","Wiz","root",0,"",({})}), \
    "mercade":({8,50,"root","Wiz","root",0,"",({})}), \
    "marvin":({8,42,"root","Wiz","root",0,"",({})}), \
    "fluffos":({9,50,"root","Wiz","root",0,"",({})}),])

/*
 * DEFAULT_DOMAINS
 *
 * This array contains the default setup of domains of this LPmud.
 */
#define DEFAULT_DOMAINS ([ \
    "Genesis":({0,"gen","postmaster","",({"postmaster",}),1,0,0,0 }), \
    "Wiz":({1,"wiz","wiz","",({"wiz","mrpr","lars","tintin", \
        "mercade","marvin",}),10,0,0,0}),])

#define BASE_DOMAIN "Genesis"

/*
 * GLOBAL_READ_EXEMPT_DOMAINS
 *
 * Domains for which global read is not enough.
 */
#define GLOBAL_READ_EXEMPT_DOMAINS  ({ "Liwitch" })

/*
 * WIZARD_DOMAIN
 *
 * This is the name of the special domain where all 'lonely' wizards are
 * placed. This domain has no domainlord and no common, open dirs
 *
 */
#define WIZARD_DOMAIN "Wiz"

/*
 * OPEN_LOG_DIR
 *
 * This is the location of the open logs.
 */
#define OPEN_LOG_DIR "/d/Genesis/log"

/*
 * DISCARD_DOMAIN_DIR
 *
 * This is the name of the directory where all the removed domains are
 * put awaiting further developments.
 */
#define DISCARD_DOMAIN_DIR "/d/Discarded"

/*
 * DEFAULT_PLAYER
 *
 * This is the default player file if nothing else is defined
 */
#define DEFAULT_PLAYER "/d/Genesis/race/human_std"

/*
 * DEFAULT_START
 *
 * This is the default starting location if nothing else is defined
 */
#define DEFAULT_START "/d/Genesis/start/human/town/church"

/*
 * DEF_STARTING_PLACES
 *
 * This array contains all the places that are acknowledged starting places
 * by default.
 */
#define DEF_STARTING_PLACES ({ "/d/Genesis/start/human/town/church", \
			       "/d/Genesis/start/goblin/caverns/quarters", \
   			       "/d/Genesis/start/elf/room/begin", \
			       "/d/Genesis/start/hobbit/v/church", \
			       "/d/Genesis/start/dwarf/lvl1/temple"})
#define TEMP_STARTING_PLACES ({ })

/*
 * WIZ_ROOM
 *
 * This is the path to the cozy room to which we set new wizards starting
 * location.
 *
 * FluffOS PORT NOTE: the real WIZ_ROOM ("the cozy room") is missing
 * content, like the rest of the /d/Genesis domain -- pointed at the
 * bare bootstrap landing room this project added specifically to
 * unblock login/testing (see secure/login/bootstrap_room.lpc's own
 * doc comment for why: without ANY valid room, new-wizard registration
 * could never complete a first successful save at all). Not a content
 * fix, purely a "let login work" one.
 */
#define WIZ_ROOM "/secure/login/bootstrap_room"

/*
 * ADMIN_HOME
 *
 * This is the administrators workroom. Has some special functions in the game.
 */
#define ADMIN_HOME "/d/Genesis/wiz/admin"

/*
 * WIZ_APPRENTICE_SCROLL
 *
 * This is the path to the scroll that gets loaded and given to new wizards.
 */
#define WIZ_APPRENTICE_SCROLL "/d/Genesis/obj/init_scroll"
#define APPRENTICE_SCROLL_FILE "/doc/man/general/WIZARD_101"

/*
 * LOGIN_NEW_PLAYER
 *
 * This is the player object that manages all entering of new players.
 *
 * FluffOS PORT NOTE: /d/Genesis/login/ghost_player never shipped
 * anywhere in the upstream repo (unlike ARMAGEDDON, there was no
 * pre-existing real implementation under a different path either) --
 * see secure/login/ghost_player.lpc's own doc comment for why this is
 * genuinely load-bearing infrastructure (character creation and every
 * player save/load) rather than a gracefully-degradable content gap,
 * and for what the minimal bootstrap replacement does and doesn't
 * cover. LOGIN_TEST_PLAYER (used only for "*sr"-suffixed throwaway
 * test character names, per secure/login.lpc) points at the same file
 * rather than a separate missing test variant.
 */
#define LOGIN_NEW_PLAYER  "/secure/login/ghost_player"
#define LOGIN_TEST_PLAYER "/secure/login/ghost_player"

/*
 * WIZ_MAKER
 *
 * This is a list of the paths to objects that may create apprentices
 */
#define WIZ_MAKER ({ "/d/Genesis/start/human/town/adv_guild" })

/*
 * LOGIN_FILE_WELCOME  - general welcome before password.
 * LOGIN_FILE_NEWS     - special news message after password.
 * LOGIN_FILE_RUNLEVEL - message about using a runlevel.
 * LOGIN_FILE_NEWCHAR  - message to new characters before confirmation.
 *
 * This is the names of the files that are written to user logging in.
 */
#define LOGIN_FILE_WELCOME  "/d/Genesis/doc/login/WELCOME"
#define LOGIN_FILE_NEWS     "/d/Genesis/doc/login/NEWS"
#define LOGIN_FILE_RUNLEVEL "/d/Genesis/doc/login/RUNLEVEL"
#define LOGIN_FILE_NEWCHAR  "/d/Genesis/doc/login/NEWCHAR"

/*
 * INFOWIZ_PATH - directory with special info on wizards.
 * LOCAL_HELP_PATH - directory with mud-specific help files.
 */
#define INFOWIZ_PATH    "/d/Genesis/doc/infowiz/"
#define LOCAL_HELP_PATH "/d/Genesis/doc/help/"

/*
 * DEFAULT_DEATH tells what object should be loaded when a player dies
 */

#define DEFAULT_DEATH "/d/Genesis/room/death/death_mark"

/*
 * DOMAIN_LINK
 *
 * Filenames trailing /d/Domain_name/ to preload on startup
 */
#define DOMAIN_LINK "domain_link"

/*
 * GAMEINFO_LOGIN
 * GAMEINFO_INFO
 *
 * Information about the game in login procedure.
 */
#define GAMEINFO_LOGIN	"gameinfo"
#define GAMEINFO_INFO	"/d/Genesis/doc/login/GAMEINFO_INFO"

/*
 * ALWAYS_APPLY - Define this if you always want players to apply before
 *                they can create a character. Undefine it if you want to
 *                have automatic character creation.
 * APPLICATION_LOGIN
 * APPLICATION_INFO
 * APPLICATION_BOARD_LOC
 *
 * Banned site login procedure
 */
#undef ALWAYS_APPLY
#define APPLICATION_LOGIN	"application"
#define APPLICATION_INFO	"/d/Genesis/doc/login/APPLICATION_INFO"
#define APPLICATION_BOARD_LOC	"/d/Genesis/wiz/admin"

/*
 * NO_GUEST_LOGIN
 *
 * Define this if you do not want a shared "guest" character to log in
 * without using a password. Undefine this and "guest" will be able to
 * log in.
 */
#define NO_GUEST_LOGIN

/*
 * COMBAT_FILE
 *
 * This file is cloned to manage a fight for a living object.
 */
#define COMBAT_FILE "/std/combat/cbase"

/*
 * MAX_PLAY
 *
 * This is the maximum amount of players that may be logged on at
 * one time.
 */
#define MAX_PLAY        (2048)

/*
 * SMALL_MEMORY_LIMIT
 * LARGE_MEMORY_LIMIT
 *
 * This is the maximum memory allowed by the master object before itself
 * starts Armageddon. The memory consumption is fetched from the
 * debug("malloc") efun as the number before (a). The use of SMALL/LARGE
 * is determined by external calls to the gamedriver.
 * No need for us to monitor this any more, I'm setting this to a very
 * high value, in effect disabling the monitoring functionality. /Mrpr
 * 1.0 GB = 1073741824
 */
#define SMALL_MEMORY_LIMIT (2147483648)
#define LARGE_MEMORY_LIMIT (2147483648)

/*
 * SWAP_MEM_MIN
 * SWAP_MEM_MAX
 * SWAP_TIME_MIN
 * SWAP_TIME_MAX
 *
 * These are swapping control parameters and control when we do swapping.
 * The swapping will start when we have used SWAP_MEM_MIN bytes of memory,
 * when we reach SWAP_MEM_MAX we will swap as much as possible. We will
 * not swap objects unless it is SWAP_TIME_MIN seconds old and we will
 * swap all objects older than SWAP_TIME_MAX seconds.
 */
#define SWAP_MEM_MIN    350000000
#define SWAP_MEM_MAX    450000000
#define SWAP_TIME_MIN   180
#define SWAP_TIME_MAX   900

/*
 * ARMAGEDDON
 *
 * This is the object to call "slow_shut" in when the GD tells master
 * that the memory is getting low.
 *
 * FluffOS PORT NOTE: unlike the other domain-content paths in this
 * file (which point at genuinely-missing /d/Genesis files), this
 * singleton's actual implementation ships in this repo at
 * /secure/armageddon.lpc (same convention as SECURITY/DOCMAKER/
 * MAP_CENTRAL/etc. in sys/files.h, all pointing at /secure/...) --
 * the upstream /d/Genesis/obj/armageddon path was simply never updated
 * to match. Left pointing at the missing domain path, this breaks
 * ARMAGEDDON->shutdown_active() et al with a hard
 * "call_other() couldn't find object" error on every single login
 * attempt (secure/login.lpc's get_name() calls it unconditionally),
 * not a graceful missing-content gap. */
#define ARMAGEDDON "/secure/armageddon"

/*
 * NPC_SOULS
 *
 * The array of sould that all mobiles should have
 */
#define NPC_SOULS ({ "/cmd/std/soul_cmd", "/d/Genesis/cmd/misc" })

/*
 * MAX_IDLE_TIME
 *
 * The maximum time you are guaranteed to be able to stay idle before
 * being logged out. The amount is counted in seconds.
 */
#define MAX_IDLE_TIME 3600

/*
 * NO_WIZARD_IDLE_CHECK
 *
 * If defined, wizards will not be checked for idleness. Undefine to
 * make wizards checked, too. The total idle time in seconds is the
 * rank * MAX_IDLE_TIME.
 */
#undef NO_WIZARD_IDLE_CHECK
#define NO_WIZARD_IDLE_CHECK

/*
 * FOB_KEEP_CHANGE_TIME
 *
 * Define this when you also want to keep track in the KEEPERSAVE of the time
 * the domain or rank/level of the wizard was changed. When undefined, this
 * infromation will not be kept. Naturally the LEVEL log will still contain
 * that information, should that be defined.
 */
#undef FOB_KEEP_CHANGE_TIME

/*
 * USE_WIZ_LEVELS
 *
 * Define this when you want to allow individual wizard levels within a rank.
 * Ranks are wizard/mage/arch, levels are 15, 16, 17.
 */
#undef USE_WIZ_LEVELS

/*
 * FORCE_PASSWORD_CHANGE <seconds>
 *
 * Define this if you want to force players to alter their password at least
 * every once in a while. This way, it will be less likely that a password is
 * found. When undefined, passwords have no expiration.
 *
 * Seconds is the number of seconds between two forced password changes.
 */
#undef FORCE_PASSWORD_CHANGE


/*
 * UPGRADE_PASSWORD_HASH
 *
 * If this is defined passwords using old hash methods will be upgraded
 * as players login.
 */
#define UPGRADE_PASSWORD_HASH

/*
 * BLOCK_DOUBLE_LOGIN
 *
 * Define this to block double logins from listed seconds.
 */
#define BLOCK_DOUBLE_LOGIN

/*
 * MET_ACTIVE
 *
 * If defined all livings will have an 'unmet' name and a normal name.
 */
#define MET_ACTIVE

/*
 * DAY_AND_NIGHT
 *
 * If DAY_AND_NIGHT is active there will be a day night cyclus from 10 pm
 * to 5 am.
 */
#undef DAY_AND_NIGHT

/*
 * STATUE_WHEN_LINKDEAD
 *
 * Show players as statues when they are linkdead.
 *
 */
#define STATUE_WHEN_LINKDEAD
#define OWN_STATUE "/d/Genesis/obj/statue"
#define STATUE_DESC "statue of"
#define STATUE_TURNS_INTO "turns into stone"
#define STATUE_TURNS_ALIVE "turns alive again"

/*
 * EDITOR_SAVE_OBJECT
 *
 * Will be called from the editor if a player goes linkdead while editing
 * something, a note, mail, whatever. Allows them to restore the message
 * from the editor after they re-link.
 */
#define EDITOR_SAVE_OBJECT "/w/postmaster/editor_save"

/*
 * UDP_MANAGER
 *
 * The object that manages udp messages
 */
#undef UDP_MANAGER "/d/Genesis/obj/udp"

/*
 * DECAY_XP
 *
 * The part of xp decayed each 15 minutes. (xp -= xp / DECAY_XP)
 * If this is 0 then no decay occurs.
 */
#define DECAY_XP 250

/*
 * DOMAIN_RANKWEIGHT_FORMULA
 *
 * This is the formula for calculating the weight factor in the domain
 * ranking list. q and c are quest and combat xp given to mortals by the
 * domain. Normally it is good to give quest xp and bad to give combat xp.
 * This is so because we want to promote the making of quests.
 */
#define DOMAIN_RANKWEIGHT_FORMULA(q, c)  (100 + (q / 25) + ((-c) / 10000))

/*
 * REGULAR_REBOOT
 *
 * If defined, the hour during which the game will be rebooted.
 */
#undef REGULAR_REBOOT 9

/*
 * REGULAR_UPTIME
 * UPTIME_VARIATION
 *
 * Define this to specify the amount of hours uptime after which a reboot
 * shall follow. The variation is the total time window in hours on this
 * maximum uptime. I.e. an uptime of 10 hours and var of 2 means 9 - 11.
 * This shouldn't be a whole number of days, so it cycles through the day.
 */
#define REGULAR_UPTIME 332
#define UPTIME_VARIATION 2

/*
 * NO_ALIGN_TITLE
 *
 * Defined if alignment title is not used
 */
#define NO_ALIGN_TITLE

#undef NO_SKILL_DECAY

/*
 * LANG_PRETITLES
 *
 * We use badname instead of the pretitle check.
 */
#undef LANG_PRETITLES

/*
 * CYCLIC_LOG_SIZE
 *
 * This is a mapping containing the maximum file size for logs for a given
 * euid. Normally the maximum file size for a log is given with the euid '0',
 * however, if the name of the euid appears in this mapping, the owner of the
 * euid has the option of allowing the size grow to the given value before
 * cycling is done.
 * If the size is less than 0, the log will be allowed to grow indefinately.
 */
#define CYCLIC_LOG_SIZE ([ 0 : 20000, "root" : -1, "Genesis" : 100000 ])

/*
 * PRELOAD_FIRST
 *
 * Information on what files are to be preloaded before anything else.
 * This can either be a string and is then a filename holding all
 * files to be preloaded.
 *
 * It can also be an array holding the files to preload.
 */
#define PRELOAD_FIRST "/secure/preload_list"

#endif

