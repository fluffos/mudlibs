/*
  /local.h

  This file contains all world specific information. To configure your
  own world and set up your own mud, make changes to this file.

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
/* FluffOS PORT NOTE (AGENTS.md \S7.39): the driver auto-predefines
 * MUD_NAME from config.fluffos's own "name :" field -- the mudlib
 * redefining it is a hard compile error ("Illegal to redefine a
 * predefined value"), not a silent shadow. secure/master.lpc's
 * get_mud_name() already falls back correctly to the driver's (string)
 * MUD_NAME via its "else if (stringp(MUD_NAME))" branch once this mapping
 * form is gone, so this is a safe drop, not a functionality loss. */
/* #define MUD_NAME ([ 0: "Teoria_test", 23: "Teoria" ]) */

/*
 * DEFAULT_WIZARDS
 *
 * This array contains the default setup of wizards of this LPmud.
 */
/* FluffOS PORT NOTE: this port's seeded admin account ("fluffos") is
 * added to this mapping only AFTER its player file already exists --
 * secure/login.lpc's new_character() refuses to let a brand new mortal
 * register a name for which query_wiz_rank() is already nonzero ("this
 * name once belonged to a wizard..."), so listing "fluffos" here before
 * ever registering it as a mortal makes it permanently unregistrable
 * through normal play. See NOTES.md for the two-step bootstrap actually
 * used. "root" is left untouched either way because the shipped archive
 * already has a real player save at /players/r/root.o.backup (the
 * original author's own elf wizard character) that we must not collide
 * with or overwrite. */
/* FluffOS PORT NOTE: this port's seeded admin account "fluffos" is
 * listed here (step 2 of 2 -- its mortal player file at
 * /players/f/fluffos.o was created FIRST, through normal registration,
 * while this entry was temporarily commented out; see NOTES.md).
 * secure/login.lpc's new_character() refuses to let a brand new mortal
 * register a name for which query_wiz_rank() is already nonzero ("this
 * name once belonged to a wizard..."), so listing a not-yet-registered
 * name here would make it permanently unregistrable through normal
 * play. "root" is left untouched either way because the shipped archive
 * already has a real player save at /players/r/root.o.backup (the
 * original author's own elf wizard character) that we must not collide
 * with or overwrite. */
#define DEFAULT_WIZARDS ([ \
    "root":({9,50,"root","Wiz","root",}), \
    "fluffos":({9,50,"root","Wiz","root",}), \
    "wiz":({7,35,"root","Wiz","root",}),])

/*
 * DEFAULT_DOMAINS
 *
 * This array contains the default setup of domains of this LPmud.
 */
/* FluffOS PORT NOTE: this macro's tuples (in BOTH this file and the
 * shipped local.h.Genesis alternate) were laid out one field short and
 * with MEMBERS/STEWARD swapped relative to what secure/master/fob.lpc's
 * own FOB_DOM_* constants (and its own add_domain(), which builds
 * "({ dom_count++, sname, wname, "", ({ }), "", DOMAIN_MAX, 0, 0, 0 })")
 * actually expect: NUM, SHORT, LORD, STEWARD, MEMBERS, MADWAND, MAXSIZE,
 * QXP, CXP, CMNDS (10 fields). The original 9-field tuples put the
 * members array where STEWARD belongs and an empty string where MEMBERS
 * belongs, so query_mage_links()'s `m_domains[WIZARD_DOMAIN][FOB_DOM_MEMBERS]`
 * read that stray "" and crashed on `({}) + ""` ("Bad type argument to
 * +. Had array and string") the moment this data was ever actually
 * loaded -- a pre-existing bug in the shipped defaults, never exercised
 * before because this archive's own KEEPERSAVE.o shipped with fully
 * empty m_domains/m_wizards (see syslog/KEEPERSAVE.o.orig-empty-backup),
 * so load_fob_defaults() (and this macro) never actually ran. Fixed to
 * match fob.lpc's real field order. */
#define DEFAULT_DOMAINS ([ \
    "Standard":({0,"gen","postmaster","",({"postmaster",}),"",1,0,0,0 }), \
    "Wiz":({1,"wiz","wiz","",({"wiz","root","fluffos",}),"",1,0,0,0}),])

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
#define OPEN_LOG_DIR "/d/Standard/log"

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
#define DEFAULT_PLAYER "/d/Standard/race/czlowiek_std"

/*
 * DEFAULT_START
 *
 * This is the default starting location if nothing else is defined
 */
#define DEFAULT_START "/d/Standard/start/church"

/*
 * STARTING PLACES
 *
 * This array contains all the places that are acknowledged starting places
 * by default. 
 *
 */
#define STARTING_PLACES ({ "/d/Standard/start/church", \
			   "/d/Standard/start/church", \
   			   "/d/Standard/start/church", \
			   "/d/Standard/start/church", \
			   "/d/Standard/start/church"})
#define TEMP_STARTING_PLACES ({ })

/*
 * WIZ_ROOM
 *
 * This is the path to the cozy room to which we set new wizards starting
 * location.
 */
#define WIZ_ROOM "/d/Standard/wiz/wizroom"

/*
 * ADMIN_HOME
 *
 * This is the administrators workroom. Has some special functions in the game.
 */
#define ADMIN_HOME "/d/Standard/private/adminroom"

/*
 * WIZ_APPRENTICE_SCROLL 
 *
 * This is the path to the scroll that gets loaded and given to new wizards.
 */
#define WIZ_APPRENTICE_SCROLL "/d/Standard/obj/init_scroll"
#define APPRENTICE_SCROLL_FILE "/d/Standard/obj/init_scroll"

/* 
 * LOGIN_NEW_PLAYER
 *
 * This is the player object that manages all entering of new players
 */
#define LOGIN_NEW_PLAYER "/d/Standard/login/ghost_player"

/*
 * WIZ_MAKER
 *
 * This is a list of the paths to objects that may create apprentices
 */
#define WIZ_MAKER ({ "/d/Standard/start/church" })

/* 
 * LOGIN_FILE_WELCOME
 * LOGIN_FILE_NEWS
 *
 * This is the names of the files that are written to user logging in.
 */
#define LOGIN_FILE_WELCOME "/d/Standard/doc/login/WELCOME"
#define LOGIN_FILE_NEWS "/d/Standard/doc/login/NEWS"
#define LOGIN_FILE_RUNLEVEL "/d/Standard/doc/login/RUNLEVEL"

/* 
 * MAIL_INFO_OBJ
 * SPECIAL_INFO_OBJ
 * 
 * These are the objects that the finger_player object uses to find out
 * interesting stuff about the player
 */
#define MAIL_INFO_OBJ "/d/Standard/std/mail_stuff"
#define SPECIAL_INFO_OBJ "/d/Standard/std/special_stuff"

/* 
 * DEFAULT_DEATH tells what object should be loaded when a player dies
 */

#define DEFAULT_DEATH "/d/Standard/smierc/death_mark"

/*
 * DOMAIN_LINK
 * WIZARD_LINK
 *
 * Filenames trailing /d/Domain_name/ and /d/<WIZARD_DOMAIN>/wizard_name/
 * to preload on startup
 */
#define DOMAIN_LINK "domain_link"
#define WIZARD_LINK "wizard_link"

/*
 * GAMEINFO_LOGIN
 * GAMEINFO_INFO
 *
 * Information about the game in login procedure.
 */
#define GAMEINFO_LOGIN	"gameinfo"
#define GAMEINFO_INFO	"/d/Standard/doc/login/GAMEINFO_INFO"

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
/* FluffOS PORT NOTE (standing project policy, AGENTS.md \S1.3e -- legacy
 * connection-time gates that made sense for a live, publicly-hosted,
 * multi-year game don't make sense for a local/solo instance):
 * ALWAYS_APPLY forces every new character through a human-reviewed
 * "podanie" (application) submission that only ever produces a mail
 * message for an administrator to read -- it never creates a playable
 * character by itself, and there is no administrator present to review
 * it in this environment, so it permanently blocks the normal
 * new-character flow end to end (confirmed live) with no way to bypass
 * it for a genuinely new name (the "*jr" junior-account exception
 * checked further down this same function only applies to a LATER,
 * different gate). The archive's own alternate config,
 * config/sys/local.h.Genesis, already ships this same knob undefined --
 * confirming it's a deliberate, toggleable site policy, not core game
 * logic -- so it's undefined here the same way. */
#undef ALWAYS_APPLY
#define APPLICATION_LOGIN	"podanie"
#define APPLICATION_INFO	"/d/Standard/doc/login/APPLICATION_INFO"
#define APPLICATION_BOARD_LOC	"/d/Standard/private/applroom"

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
#define MAX_PLAY	80

/*
 * SMALL_MEMORY_LIMIT
 * LARGE_MEMORY_LIMIT
 *
 * This is the maximum memory allowed by the master object before itself
 * starts Armageddon. The memory consumption is fetched from the
 * debug("malloc") efun as the number before (a). The use of SMALL/LARGE
 * is determined by external calls to the gamedriver.
 */
#define SMALL_MEMORY_LIMIT 60000000
#define LARGE_MEMORY_LIMIT 60000000

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
#define SWAP_MEM_MIN    0
#define SWAP_MEM_MAX    60000000
#define SWAP_TIME_MIN   180
#define SWAP_TIME_MAX   900

/*
 * ARMAGEDDON
 *
 * This is the object to call "slow_shut" in when the GD tells master
 * that the memory is getting low.
 */
#define ARMAGEDDON "/d/Standard/obj/armageddon"

/*
 * NPC_SOULS
 *
 * The array of sould that all mobiles should have
 */
#define NPC_SOULS ({ "/cmd/std/soul_cmd", "/cmd/std/misc_cmd" })

/*
 * MAX_IDLE_TIME
 *
 * The maximum time you are guaranteed to be able to stay idle before
 * being logged out. The amount is counted in seconds.
 */
#define MAX_IDLE_TIME 1800

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
 * FORCE_PASSWORD_CHANGE
 *
 * Define this if you want to force players to alter their password at least
 * every once every six months. This way, it will be even less likely that a
 * password is found. When undefined, passwords have no expiration.
 * Dla czarodziei okres na haslo wynosi tylko 4 miesiace.
 */
#define FORCE_PASSWORD_CHANGE

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
#define OWN_STATUE "/d/Standard/obj/statue"
#define STATUE_DESC "Zamieniony w statue"
#define STATUE_TURNS_INTO "obraca sie w kamien"
#define STATUE_TURNS_ALIVE "ozywa z powrotem"

/*
 * EDITOR_SAVE_OBJECT
 *
 * Will be called from the editor if a player goes linkdead while editing
 * something, a note, mail, whatever. Allows them to restore the message
 * from the editor after they re-link.
 */
#define EDITOR_SAVE_OBJECT "/d/Standard/private/editor_save"

/*
 * UDP_MANAGER
 *
 * The object that manages udp messages
 */
#define UDP_MANAGER "/d/Standard/obj/udp"

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

#undef LOCKOUT_START_TIME	1
#undef LOCKOUT_END_TIME		24	
#undef LOCKOUT_LEVEL		1

/* 
 * NO_ALIGN_TITLE
 *
 * Defined if alignment title is not used
 */
#define NO_ALIGN_TITLE

#undef NO_SKILL_DECAY

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
#define CYCLIC_LOG_SIZE ([ 0 : 10000, "root" : -1, "Standard" : 50000 ])

/*
 * PRELOAD_FIRST
 *
 * Information on what files are to be preloaded before anything else.
 * This can either be a string and is then a filename holding all
 * files to be preloaded.
 *
 * It can also be an array holding the files to preload.
 */
#define PRELOAD_FIRST "/secure/preload.data"

#endif
