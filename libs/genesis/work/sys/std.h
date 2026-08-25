/*
 * /std/std.h
 *
 * This file holds all global constants and macros relevant to game security.
 */

#ifndef SECURE_DEFINED
#define SECURE_DEFINED

#ifndef FILES_DEFINED
#include "/sys/files.h"
#endif  FILES_DEFINED

/*
 * MUDLIB_VERSION
 *
 * This is the name of the version of the mudlib.
 */
#define MUDLIB_VERSION ("CD.01.01")

/*
 * PLAYER_FILE(player)
 * BANISH_FILE(name)
 * SANCTION_DIR
 *
 * This is the macro for finding the filename for saving the player object.
 * The second macro returns the filename for a banished-file.
 */
#define PLAYER_FILE_DIR "/data/players/"
#define PLAYER_FILE(n)  (PLAYER_FILE_DIR + ((n))[0..0] + "/" + (n))
#define BANISH_FILE(n)  ("/data/banished/" + ((n))[0..0] + "/" + (n))
#define PINFO_FILE(n)   ("/data/pinfo/" + ((n))[0..0] + "/" + (n))
#define DELETED_FILE(n) ("/data/deleted/" + ((n))[0..0] + "/" + (n))
#define SANCTION_DIR    "/data/sanctions/"
#define SAVED_PLAYERS_DIR "/data/saved/"
#define SECONDS_SAVE    "/data/seconds"

/*
 * CALLED_BY_SECURITY
 *
 * SECURITY holds all functions that have to do with levels, rights etcetera.
 * Use CALLED_BY_SECURITY to see whether a function is called from this
 * master module.
 */
#define CALLED_BY_SECURITY (previous_object() == find_object(SECURITY))

/*
 * ROOT_UID
 * BACKBONE_UID
 *
 * These are the default defined userids.
 */
#define ROOT_UID	"root"
#define BACKBONE_UID	"backbone"

/*
 * These are the possible types of wizards
 */
#define WIZ_MORTAL	0
#define WIZ_APPRENTICE	1
#define WIZ_PILGRIM	2
#define WIZ_RETIRED	3
#define WIZ_NORMAL	4
#define WIZ_MAGE	5
#define WIZ_STEWARD	6
#define WIZ_LORD	7
#define WIZ_ARCH	8
#define WIZ_KEEPER	9

#define WIZNAME_MORTAL		"mortal"
#define WIZNAME_APPRENTICE	"apprentice"
#define WIZNAME_PILGRIM		"pilgrim"
#define WIZNAME_RETIRED    	"retired"
#define WIZNAME_NORMAL		"wizard"
#define WIZNAME_MAGE		"mage"
#define WIZNAME_STEWARD		"steward"
#define WIZNAME_LORD		"liege"
#define WIZNAME_ARCH		"arch"
#define WIZNAME_KEEPER		"keeper"

/*
 * WIZ_R
 * WIZ_S
 * WIZ_N
 *
 * This macro gives you the wizard types (ranks, short name and name) in
 * an array. The short name always has four letters.
 */
#define WIZ_R ( ({ WIZ_MORTAL, WIZ_APPRENTICE, WIZ_PILGRIM, WIZ_RETIRED,  \
		   WIZ_NORMAL, WIZ_MAGE, WIZ_STEWARD, WIZ_LORD, WIZ_ARCH, \
		   WIZ_KEEPER }) )

#define WIZ_N ( ({ WIZNAME_MORTAL, WIZNAME_APPRENTICE, WIZNAME_PILGRIM, \
		   WIZNAME_RETIRED, WIZNAME_NORMAL, WIZNAME_MAGE,       \
		   WIZNAME_STEWARD, WIZNAME_LORD, WIZNAME_ARCH,         \
		   WIZNAME_KEEPER }) )

#define WIZ_S ( ({ "mort", "appr", "pilg", "retd", "wiz ", "mage", "stwd", \
		   "lieg", "arch", "keep" }) )

/*
 * WIZ_RANK_NAME(rank)
 * WIZ_RANK_SHORT_NAME(rank)
 *
 * Get the (short) description of the rank based on the rank.
 */
#define WIZ_RANK_NAME(rank)       WIZ_N[(rank)]
#define WIZ_RANK_SHORT_NAME(rank) WIZ_S[(rank)]

/*
 * WIZ_RANK_MIN_LEVEL(rank)
 * WIZ_RANK_MAX_LEVEL(rank)
 * WIZ_RANK_START_LEVEL(rank)
 * WIZ_RANK_NEW_DOMAIN
 *
 * These defines give respectively the minimum and maximum level that a
 * person with a certain rank can have. The third contains the starting
 * level for each rank. The last is the level the lord of a newly created
 * domain is awarded.
 */
#define WIZ_RANK_MIN_LEVEL(rank) \
    ( ({ 0, 1, 2, 9, 10, 20, 25, 30, 45, 50 })[(rank)])
#define WIZ_RANK_MAX_LEVEL(rank) \
    ( ({ 0, 1, 8, 9, 24, 29, 29, 44, 49, 50 })[(rank)])
#define WIZ_RANK_START_LEVEL(rank) \
    ( ({ 0, 1, 5, 9, 15, 29, 26, 35, 49, 50 })[(rank)])
#define WIZ_RANK_NEW_DOMAIN (33)

/*
 * WIZ_CHECK
 *
 * This macro is used for terminating functions if a wizards level is
 * not sufficiently high. It returns the rank of the currently interactive
 * player, to be checked against WIZ_NORMAL, WIZ_ARCH etcetera.
 */
#define WIZ_CHECK \
    (SECURITY->query_wiz_rank(this_interactive()->query_real_name()))

/*
 * WIZ_RANK_POSSIBLE_CHANGE(rank)
 *
 * This macro returns an array of ranks to which it is possible to promote
 * or demote someone with the normal promote/demote command. Note that
 * some changes are possible, but not in this macro.
 * - At domain-creation you need to make an apprentice into a Lord. That is
 *   done through domain creation.
 * - Apprentices cannot be promoted to full wizard. That has to be done via
 *   the "draft" or "accept" command.
 * - It is not possible to promote/demote keepers via that command. There is a
 *   special "keeper" command in the keeper-soul.
 */
#define WIZ_RANK_POSSIBLE_CHANGE(rank) ( ([                                 \
    WIZ_MORTAL:     ({ WIZ_APPRENTICE }),                                   \
    WIZ_APPRENTICE: ({ WIZ_MORTAL, WIZ_PILGRIM, WIZ_RETIRED }),             \
    WIZ_PILGRIM:    ({ WIZ_MORTAL, WIZ_APPRENTICE }),                       \
    WIZ_RETIRED:    ({ WIZ_MORTAL, WIZ_APPRENTICE }),                       \
    WIZ_NORMAL:     ({ WIZ_MORTAL, WIZ_APPRENTICE, WIZ_RETIRED,             \
			WIZ_STEWARD, WIZ_MAGE, WIZ_LORD, WIZ_ARCH }),       \
    WIZ_MAGE:       ({ WIZ_MORTAL, WIZ_APPRENTICE, WIZ_RETIRED, WIZ_NORMAL, \
			WIZ_STEWARD, WIZ_LORD, WIZ_ARCH }),                 \
    WIZ_STEWARD:    ({ WIZ_MORTAL, WIZ_APPRENTICE, WIZ_RETIRED, WIZ_NORMAL, \
			WIZ_MAGE, WIZ_LORD, WIZ_ARCH }),                    \
    WIZ_LORD:       ({ WIZ_MORTAL, WIZ_APPRENTICE, WIZ_RETIRED, WIZ_NORMAL, \
			WIZ_MAGE, WIZ_STEWARD, WIZ_ARCH }),                 \
    WIZ_ARCH:       ({ WIZ_MORTAL, WIZ_APPRENTICE, WIZ_RETIRED, WIZ_NORMAL, \
			WIZ_MAGE, WIZ_STEWARD, WIZ_LORD }),                 \
    WIZ_KEEPER:     ({ }) ])[rank])

/*
 * CHANNELS_SAVE
 *
 * This file stores the channels available and the members of those channels.
 * Since there are also hidden members, we have to store this list in a
 * safe place.
 */
#define CHANNELS_SAVE "/data/channels"

/*
 * WIZ_SOUL(rank)
 *
 * This macro gives the wizard command file to use for a certain wizard rank.
 * Not every wizard gets the soul of his own rank since it is useless to give
 * someone an empty soul.
 */
#define WIZ_SOUL(rank) ( ({ \
    WIZ_CMD_MORTAL,         \
    WIZ_CMD_APPRENTICE,     \
    WIZ_CMD_PILGRIM,        \
    WIZ_CMD_APPRENTICE,     \
    WIZ_CMD_WIZARD,         \
    WIZ_CMD_MAGE,           \
    WIZ_CMD_LORD,           \
    WIZ_CMD_LORD,           \
    WIZ_CMD_ARCH,           \
    WIZ_CMD_KEEPER })[(rank)])

/*
 * Wizard restriction definitions
 */
#define RESTRICT_SNOOP		0x001
#define RESTRICT_SNOOP_DOMAIN	0x002
#define RESTRICT_RW_HOMEDIR	0x004
#define RESTRICT_LOG_COMMANDS	0x008
#define RESTRICT_STAT		0x010
#define RESTRICT_NO_W_DOMAIN	0x020
/* New wizards don't have the RW_HOMEDIR restriction by default. */
#define RESTRICT_NEW_WIZ	0x03B
#define RESTRICT_ALL		0x03F

/* Siteban flags */
#define SITEBAN_NOLOGIN 1
#define SITEBAN_NONEW   2
#define SITEBAN_SUFFIXES ({ "", "-all", "-new" })

/*
 * ALLOWED_LIEGE_COMMANDS
 *
 * A list of player info commands allowed to lieges.
 */
#define ALLOWED_LIEGE_COMMANDS ({ "badname", "pinfo" })

/*
 * MUDLIST_SERVER
 *
 * Address to the mudlist server. /secure/master will send a message to
 * this address on startup. Other interaction is possible through a
 * special protocol using the udp messages.
 *
 * The default server is defined as Genesis below. You can change this in
 * your /config/sys/local.h by undefining and redefining this symbol.
 */
#define MUDLIST_SERVER ({ "129.16.227.203", 2501 })

#ifndef CONFIG_DEFINED
#include "/sys/config.h"
#endif  CONFIG_DEFINED

/*
 * CRYPT_METHOD
 *
 * The method used to encrypt long passwords. See 'man crypt'.
 */
/* FluffOS PORT NOTE: this driver's crypt() only recognizes the bcrypt
 * prefixes $2a$/$2x$/$2y$, not $2b$ (see packages/core/efuns_main.cc's
 * f_crypt()) -- changed from the original "$2b$06$" for driver
 * compatibility (a fresh install with no legacy password hashes to
 * stay compatible with). Also, unlike the CD driver's crypt(str,
 * method, saltlen) three-arg form, this driver's two-arg crypt(str,
 * salt) needs a COMPLETE salt string (prefix + actual random
 * characters) -- passing the bare method prefix alone leaves the
 * underlying libc crypt() with no real salt and it errors. See
 * secure/simul_efun.c's gensalt() and the call sites using it. */
#define CRYPT_METHOD        ("$2a$06$")
#define CRYPT_SALT_LENGTH   22

/* No definitions beyond this line. */
#endif SECURE_DEFINED
