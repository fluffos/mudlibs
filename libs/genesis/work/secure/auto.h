/* Automatically included in all files */

/*
 * RACES
 *
 * FluffOS PORT NOTE: RACES is referenced throughout std/, cmd/ and
 * secure/ (width_height.lpc, description.lpc, guild_support.lpc,
 * finger_player.lpc, state.lpc, ...) but was never actually #defined
 * anywhere in this repo -- it's normally domain content, and this repo
 * ships no /d/Genesis domain at all (see the note at the top of
 * config/sys/local.h). Left undefined, every one of those files fails
 * to compile outright (a hard "Undefined variable" error, not just a
 * missing-content gap), so a real definition is needed just to get the
 * mudlib to compile. Derived directly from the six race std files this
 * repo's own secure/preload_list already names
 * (/d/Genesis/race/{human,dwarf,elf,goblin,hobbit,gnome}_std) --
 * itself missing, like the rest of the domain -- rather than invented,
 * to keep this as close to "what upstream's own preload list implies"
 * as possible. Defined here (this project's chosen "global include
 * file", see config.fluffos) rather than in some specific header,
 * since no single header this codebase already has is included by
 * every file that references RACES.
 */
#ifndef RACES
#define RACES ({ "human", "dwarf", "elf", "goblin", "hobbit", "gnome" })
#endif

/*
 * RACES_SHORT
 *
 * FluffOS PORT NOTE: another domain-content symbol missing for the same
 * reason as RACES above (per the CD changelog, doc/changelog/CD.01.00,
 * it was meant to be defined in /config.std/login/login.h -- the same
 * missing-domain file config/sys/login.h forwards to). Unlike RACES,
 * this repo gives no hint at what the actual short-name mapping should
 * contain (it's cosmetic per-race abbreviation content, e.g. "Hum" for
 * "human"), so rather than invent that content, define it as an empty
 * mapping: cmd/wiz/apprentice/people.lpc's only reader already falls
 * back to a 3-char substring of the full race name whenever a race has
 * no entry here, which is the correct behavior for every race with no
 * override.
 */
#ifndef RACES_SHORT
#define RACES_SHORT ([ ])
#endif

/*
 * RACESOUND
 *
 * FluffOS PORT NOTE: another missing domain-content mapping, same
 * situation as RACES_SHORT above -- std/living/cmdhooks.lpc's only
 * reader (cmdhooks_reset()) already falls back to an empty mapping
 * whenever RACESOUND[query_race()] comes back falsy, so an empty
 * mapping here is the content-neutral definition, not an invented one.
 */
#ifndef RACESOUND
#define RACESOUND ([ ])
#endif

/*
 * RACEATTR, SPREAD_PROC, HEIGHTDESC, WIDTHDESC, RACEMAP
 *
 * FluffOS PORT NOTE: five more missing domain-content symbols, same
 * situation as RACES_SHORT/RACESOUND above -- referenced by
 * std/living/width_height.lpc (a fragment #included into every living,
 * so leaving them undefined is a hard compile-blocker for players and
 * NPCs alike) and lib/guild_support.lpc. Defined empty rather than
 * invented: std/living.lpc's own create() path (every living's
 * creation) only ever reaches these through set_random_size_descs() ->
 * set_height_desc()/set_width_desc(), both of which already guard with
 * `if ((index = member_array(str, HEIGHTDESC/WIDTHDESC)) < 0) return 0;`
 * before indexing into RACEATTR/SPREAD_PROC -- so empty arrays there
 * degrade gracefully (one_of_list() on an empty array already returns 0
 * per its own doc comment in secure/simul_efun.lpc, member_array(0, ({}))
 * is -1, guard fires, no crash) and boot/player-creation is unaffected.
 * The interactive-only query_height_desc()/query_width_desc()/
 * lib/guild_support.lpc "newlook" commands (never called during boot)
 * are not guarded the same way and would hit a runtime error if actually
 * invoked with no race content configured -- a missing-content gap left
 * deferred and documented here, same as this project's other
 * missing-domain-content gaps, rather than invented as real race
 * attribute numbers and description text (which would be content, not
 * a compile/driver-compat fix).
 */
#ifndef RACEATTR
#define RACEATTR ([ ])
#endif
#ifndef SPREAD_PROC
#define SPREAD_PROC ({ })
#endif
#ifndef HEIGHTDESC
#define HEIGHTDESC ({ })
#endif
#ifndef WIDTHDESC
#define WIDTHDESC ({ })
#endif
#ifndef RACEMAP
#define RACEMAP ([ ])
#endif

/*
 * RACESTART
 *
 * FluffOS PORT NOTE: another missing domain-content mapping (per-race
 * starting room path). std/player.lpc's query_def_start() (its only
 * reader) already has its own graceful "no valid start room" fallback
 * chain culminating in a catch() that prints "PANIC, your starting
 * locations are corrupt!!" and destruct()s the player -- but that
 * destruct() happens *before* std/player.lpc's own first save_me()
 * call ever runs, which meant NO character (mortal or wizard) could
 * ever complete registration at all, including this project's own
 * "fluffos" admin/test account (see this project's standard
 * admin-seeding convention). Rather than leave this empty (the
 * content-neutral choice used for the other RACE* mappings above,
 * appropriate where a graceful fallback already exists), every race is
 * mapped to the same bare bootstrap landing room this project added
 * specifically to unblock login/testing (see
 * secure/login/bootstrap_room.lpc's own doc comment) -- infrastructure
 * to let login work, not invented world content.
 */
#ifndef RACESTART
#define RACESTART ([ \
    "human"  : "/secure/login/bootstrap_room", \
    "dwarf"  : "/secure/login/bootstrap_room", \
    "elf"    : "/secure/login/bootstrap_room", \
    "goblin" : "/secure/login/bootstrap_room", \
    "hobbit" : "/secure/login/bootstrap_room", \
    "gnome"  : "/secure/login/bootstrap_room", \
    ])
#endif

/*
 * DEFAULT_PLAYER_SOULS
 *
 * FluffOS PORT NOTE: std/player.lpc's setup_player() unconditionally
 * strips a mortal's ENTIRE cmdsoul_list on every single login ("Non
 * wizards should not have a lot of souls"), relying on something else
 * to grant the real, curated per-race set back -- in the original,
 * unported game this was almost certainly done by the (missing, see
 * \S6) race std files as part of embodying a player. With no race std
 * content in this repo at all, every mortal's cmdsoul_list stayed
 * permanently empty after this strip, so std/living/cmdhooks.lpc's
 * load_command_souls() (shared with NPCs) fell back to NPC_SOULS --
 * correct for an actual mobile, wrong for a player: it grants only
 * "/cmd/std/soul_cmd" (a real file) plus "/d/Genesis/cmd/misc" (missing
 * domain content, logged as "Yikes, baaad soul" on every command), and
 * omits every basic player verb soul (look/get/drop/inventory/say/
 * emote/etc.) entirely -- confirmed live: a freshly registered mortal
 * ("Tamsworth") could not even "look". Rather than invent a soul list,
 * this is taken directly from this repo's own shipped
 * raw/secure/proto_char.o (the original mudlib's new-character
 * template save), whose real cmdsoul_list is:
 * ({"/d/Genesis/cmd/soul_cmd_ghost","/d/Genesis/cmd/misc_cmd_ghost",
 * "/d/Genesis/cmd/double","/cmd/live/info","/cmd/live/items",
 * "/cmd/live/magic","/cmd/live/social","/cmd/live/speech",
 * "/cmd/live/state","/cmd/live/thief","/cmd/live/things"}) -- with the
 * three /d/Genesis/cmd/ ghost/double entries dropped (missing domain
 * content, and specific to the separate not-yet-embodied "ghost"
 * pre-race-selection phase this port's bootstrap skips entirely, see
 * secure/login/ghost_player.lpc) and the remaining eight real,
 * confirmed-present /cmd/live/ files kept as-is. One substitution:
 * "/d/Genesis/cmd/soul_cmd_ghost" -- per cmd/std/soul_cmd.lpc's own doc
 * comment ("the basic soul that is meant to be inherited by the
 * race-specific souls... contains the basic emotions for players") --
 * is a ghost-restricted wrapper around exactly the same base emote
 * soul NPC_SOULS already loads standalone for NPCs
 * ("/cmd/std/soul_cmd", confirming it works loaded directly); swapped
 * in here so embodied mortals keep basic emotes (smile, wave, etc.)
 * too, rather than losing them outright for want of the missing ghost
 * wrapper.
 */
#ifndef DEFAULT_PLAYER_SOULS
#define DEFAULT_PLAYER_SOULS ({ \
    "/cmd/std/soul_cmd", \
    "/cmd/live/info", \
    "/cmd/live/items", \
    "/cmd/live/magic", \
    "/cmd/live/social", \
    "/cmd/live/speech", \
    "/cmd/live/state", \
    "/cmd/live/thief", \
    "/cmd/live/things", \
    })
#endif

/*
 * RACESTATMOD
 *
 * FluffOS PORT NOTE: another missing domain-content mapping (per-race,
 * per-stat modifier applied by secure/finger_player.lpc's own
 * alternate acc_exp_to_stats() implementation -- note std/living/
 * stats.lpc's "real" acc_exp_to_stats(), used during actual play,
 * doesn't reference RACESTATMOD at all, so this only affects the
 * `finger` wizard command's offline stat approximation). Defined empty
 * like the other RACE* mappings above rather than invented; unlike
 * RACEATTR, this one call site has no existing "unknown race" guard,
 * so RACESTATMOD[race][stat] on an empty mapping (RACESTATMOD[race]
 * returns 0, then indexing that 0 by [stat]) would still error if the
 * finger command is ever actually invoked with no race content
 * configured -- a missing-content runtime gap left deferred and
 * documented here, consistent with this project's other
 * missing-domain-content gaps.
 */
#ifndef RACESTATMOD
#define RACESTATMOD ([ ])
#endif
