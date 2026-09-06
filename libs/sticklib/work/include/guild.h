#ifndef _GUILD_H
#define	_GUILD_H

/* Note that as the StickLib-distribution only contains one of
 * the guilds StickMud has; the priest guild. Thus, most
 * guild defines here are commented out. They are left in comments
 * here though just to show what could be in here, if some old
 * code should need them.
 */

// Define to begin a Guildless Time /Graah
#undef GUILDLESS

// The standard header-file defining the names of the guilds
// (used by set_guild & query_guild).

#define GN_DRUID	"druid"
#define	GN_PRIEST	"priest"
#define GN_THIEF	"thief"

#define	GN_NONE		"no-guild"

#define	GUILD_PATH_DRUID	"/guilds/druids/"
#define	GUILD_PATH_PRIEST	"/guilds/priests/"
#define GUILD_PATH_THIEF	"/guilds/thieves/"

// Hooks guilds can set:

#define G_HOOK_NONE             0
#define G_HOOK_ALL              -1
#define G_HOOK_QUIT             1
#define G_HOOK_DEATH            2
#define G_HOOK_GO_LD            3
#define G_HOOK_RECOVER_FROM_LD  4
#define G_HOOK_HIT_PLAYER       5
#define G_HOOK_GO_MORT          6
#define G_HOOK_ADD_EXP          7
#define G_HOOK_PREVENT_ATTACK   8
#define G_HOOK_LWIELD_WEAPON    9
#define G_HOOK_WIELD_WEAPON     10
#define G_HOOK_REMOVE_WEAPON    11
#define G_HOOK_PRIMARY_ATTACK   12
#define G_HOOK_SECONDARY_ATTACK 13
#define G_HOOK_MOVE_PLAYER      14

/** locations of guild marks **/

#define DRUID_MARK_PATH "/guilds/druids/mark"
#define PRIEST_MARK_PATH "/guilds/priests/symbol"
#define THIEF_MARK_PATH "/guilds/thieves/thief_mark_new"

#endif
