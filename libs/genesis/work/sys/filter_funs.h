/*
 * /sys/filter_funs.h
 *
 * A set of functions often used by filter.
 */

#ifndef FILTER_DEF
#define FILTER_DEF

/*
 * returns all livings in array x.
 */
#define FILTER_LIVE(x) \
    filter((x), living)

/*
 * returns all livings in array x without this_player().
 */
#define FILTER_OTHER_LIVE(x) \
    (FILTER_LIVE((x) - ({ this_player() }) ))

/*
 * returns all interactive players in array x.
 */
#define FILTER_PLAYERS(x) \
    filter((x), interactive)

/*
 * returns all non-living objects in array x.
 */
#define FILTER_DEAD(x) \
    filter(((x) - ({ 0 }) ), (: !(living($1)) :))

/*
 * returns all elements in array x that are present in the environment of
 * this_player().
 *
 * Caveat: This filter is _not_ forgiving when 0 is in the array.
 */
#define FILTER_PRESENT(x) \
    filter((x), (: (environment(this_player())) == (environment($1)) :))

/*
 * returns all livings in array x that are present in the environment of
 * this_player().
 */
#define FILTER_PRESENT_LIVE(x) \
    filter(FILTER_LIVE(x),     \
        (: (environment(this_player())) == (environment($1)) :))

/*
 * returns all objects in array x that are of gender g.
 */
#define FILTER_GENDER(x, g) \
    filter((x), (: (g) == (($1)->query_gender()) :))

/*
 * returns all objects in array x that are of race r.
 */
#define FILTER_RACE(x, r) \
    filter((x), (: (r) == (($1)->query_race_name()) :))

/*
 * returns all objects in array x that are a wizard.
 */
#define FILTER_IS_WIZARD(x) \
    filter((x), (: ($1)->query_wiz_level() :))

/*
 * returns all objects in array x that are a mortal player,
 * or rather, that are not a wizard.
 */
#define FILTER_IS_MORTAL(x) \
    filter((x), (: !(($1)->query_wiz_level()) :))

/*
 * returns all objects in array x that can see in the room.
 */
#define FILTER_CAN_SEE_IN_ROOM(x) \
    filter((x), (: ($1)->can_see_in_room() :))

/*
 * returns all objects in array x that can be seen by living l.
 */
#define FILTER_CAN_SEE(x, l) \
    filter((x), (: ($1)->check_seen(l) :))

/*
 * returns all objects in array x that can see [living/object] l.
 */
/* FluffOS PORT NOTE: was `filter((x), (l)->check_seen)` -- see
 * check_seen_bound() in secure/simul_efun.c for why. */
#define FILTER_IS_SEEN(l, x) \
    filter((x), (: check_seen_bound, (l) :))

/*
 * returns all objects in array x that can be seen, ie that aren't no_show.
 */
#define FILTER_SHOWN(x) \
    filter((x), (: !(($1)->query_no_show()) :))

/* no definitions beyond this line. */
#endif FILTER_DEF
