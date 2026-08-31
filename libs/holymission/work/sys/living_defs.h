/*
 * sys/living_defs.h -- reconstructed.
 *
 * Found completely EMPTY (0 bytes) in the preserved archive, despite
 * being #include'd by doc/lib/living.lpc (the "living" base class --
 * see /sys/living.lpc and NOTES.md) as "the general defines". Every
 * identifier reconstructed below is verified real archive content,
 * cross-referenced against other still-intact files in this same
 * mudlib (not invented):
 *   - NUM_STATS, TO: players/kryll/tmp/sys/player.h and
 *     players/kryll/tmp/sys/player_defs.h (real personal-workroom
 *     copies of this exact header family, same recovery technique as
 *     sys/include/sys_levels.h's L_ and WL_ level constants).
 *   - GM: the mudlib-wide "/guild/master" convention (include/defs.h
 *     and dozens of other real files).
 *   - SHARE: obj/armour.lpc's own #define SHARE "obj/share" (identical
 *     value repeated verbatim across dozens of real files/wizard
 *     copies).
 *   - SIZES: obj/armour.h's #define SIZES value, exploded into the
 *     array form doc/lib/living.lpc actually assigns
 *     (`nosave string *sizes = SIZES;` requires an array, not the
 *     slash-delimited string armour.h's own SIZES is -- both real,
 *     just used differently in each place).
 */

#ifndef __LIVING_DEFS_H__
#define __LIVING_DEFS_H__

#define TO		this_object()
#define GM		"/guild/master"
#define SHARE		"obj/share"

// Real, verbatim convention from doc/lib/player.lpc (a real, intact
// sibling file in this same archive -- see NOTES.md).
#define CName		(this_object()->query_name())
#define TName		(this_object()->query_name_true())
#define IName		"Someone"
#define SM		"/obj/skill_master"
#define SKILL_MASTER	"/masters/skills"
#define SPELL_MASTER	"/spells/master"
#define ABILITY_MASTER	"/abilities/master"
#define NO_OF_LANG	3
#define QR		"room/quest_room"
#define ARENA		"/players/patience/arena/prep_room"
#define KILL_NEUTRAL_ALIGNMENT	10
#define ADJ_ALIGNMENT(al)	((-(al) - KILL_NEUTRAL_ALIGNMENT)/4)

// Str/Max_sp: capitalized aliases used verbatim (including the "Max_sp"
// typo/capitalization, confirmed identical across multiple independent
// wizard copies -- e.g. players/waldo/liv.lpc) throughout doc/lib/
// living.lpc's display code. players/kryll/tmp/sys/player.h has the
// real Str/Dex/Con/Int/Wis/Chr = (TO->query_stats(N)) convention;
// this class already has its own local query_str() so use that
// directly rather than the call_other form.
#define Str		(query_str())
#define Max_sp		max_sp
#define Dex		(query_dex())
#define Con		(query_con())
#define Int		(query_int())
#define Wis		(query_wis())
#define Chr		(query_chr())

// nr_str..nr_chr: stats[] index constants (used as switch/case labels,
// which require real compile-time constants, not variables) --
// consistent with players/kryll/tmp/sys/player.h's own
// Str/Dex/Con/Int/Wis/Chr = query_stats(0..5) ordering.
#define nr_str		0
#define nr_dex		1
#define nr_con		2
#define nr_int		3
#define nr_wis		4
#define nr_chr		5

// NUMBER_OF_SIZES: SIZES above has 6 entries (any,tiny,small,medium,
// large,x-large); set_size(i) is documented as "1 and NUMBER_OF_SIZES"
// (doc/lib/living.lpc's own comment), i.e. excluding index 0 ("any").
#define NUMBER_OF_SIZES	5

// WEIGHT_SIZE: a slash-delimited per-size weight table
// (explode(WEIGHT_SIZE,"/")[real_size], real_size 0..5) -- no surviving
// real values anywhere in the archive. Placeholder, roughly-doubling
// scale (in this mudlib's own weight units, whatever those originally
// were) rather than an invented "balanced" table -- adjust freely if
// real intent ever resurfaces.
#define WEIGHT_SIZE	"0/1/5/20/80/300"

#define NUM_STATS	6

#define SIZES		({ "any", "tiny", "small", "medium", "large", "x-large" })

// NAME_OF_GHOST: real value, verbatim from 3 independent wizard copies
// (players/ted/living.h, players/topaz/angmar/living.h,
// players/mangla/gal/qclxxiv/leaf5/qmonster.lpc all agree, modulo
// case -- kept as players/kryll's capitalized "Some mist").
#define NAME_OF_GHOST	"Some mist"

// INVNAME: the "you can't see who this is" display name shown when
// query_name_info() can't identify the looker to the target (invisible-
// to-them case). No surviving real value found anywhere in the archive;
// doc/lib/player.lpc's own #define IName "Someone" is the closest
// same-purpose real precedent in this same mudlib, reused here.
#define INVNAME		"Someone"

// RING_NUM: how many rings a living can wear simultaneously. No
// surviving real value anywhere in the archive -- a conservative,
// clearly-a-placeholder guess (2, one per hand) rather than an invented
// "balance" number; adjust freely if real intent ever resurfaces.
#define RING_NUM	2

#endif // __LIVING_DEFS_H__
