/*
 * /sys/filter_funs.h
 *
 * A set of functions often used by filter.
 */

#ifndef FILTER_DEF
#define FILTER_DEF

/* FluffOS PORT NOTE: the whole file originally used the CD-driver's
 * `&operator(OP)(args)` / `@` function-composition-and-partial-
 * application syntax and bare `&->funcname(args)` partial application --
 * both entirely unsupported by this driver. Converted throughout to
 * `(: expr :)` closures (using `$1` for the filter callback's implicit
 * argument), matching the fix already proven on the sibling `genesis`
 * port of this same engine family. `filter((x), living)`/
 * `filter((x), interactive)` (a bare REAL EFUN name, not a user LPC
 * function) are left as-is -- unlike add_action()'s bare-function-value
 * bug, a bare efun name passed as a filter()/map() callback works fine
 * on this driver.
 */

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
    filter(((x) - ({ 0 }) ), (: !living($1) :))

/*
 * returns all livings in array x that are present in the environment of
 * this_player().
 */
#define FILTER_PRESENT_LIVE(x) \
    filter(FILTER_LIVE(x),     \
	(: environment(this_player()) == environment($1) :))

/*
 * returns all objects in array x that are of gender g.
 *
 * FluffOS PORT NOTE: "g" is a macro parameter that can resolve to a
 * real enclosing-function local at a given call site, which an inline
 * closure can't capture -- routed through a bound-argument helper (see
 * query_gender_eq_bound() in secure/simul_efun.lpc) instead, same as
 * FILTER_IS_SEEN below.
 */
#define FILTER_GENDER(x, g) \
    filter((x), (: query_gender_eq_bound, (g) :))

/*
 * returns all objects in array x that are of race r.
 *
 * FluffOS PORT NOTE: same "r" capture issue as FILTER_GENDER's "g" above.
 */
#define FILTER_RACE(x, r) \
    filter((x), (: query_race_eq_bound, (r) :))

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
    filter((x), (: !($1)->query_wiz_level() :))

/*
 * returns all objects in array x that can see in the room.
 */
#define FILTER_CAN_SEE_IN_ROOM(x) \
    filter((x), (: ($1)->can_see_in_room() :))

/*
 * returns all objects in array x that can be seen by living l.
 *
 * FluffOS PORT NOTE: "l" is a macro parameter that can resolve to a
 * real enclosing-function local at a given call site (confirmed live:
 * cmd/live/social.lpc's FILTER_CAN_SEE(odbiorcy, przedstawiany),
 * "Illegal to use local variable in functional"), which an inline
 * closure can't capture -- routed through a bound-argument helper (see
 * check_seen_bound2() in secure/simul_efun.lpc) instead, same as
 * FILTER_IS_SEEN below.
 */
#define FILTER_CAN_SEE(x, l) \
    filter((x), (: check_seen_bound2, (l) :))

/*
 * returns all objects in array x that can see [living/object] l.
 */
/* FluffOS PORT NOTE: was `filter((x), (l)->check_seen)` -- a bare
 * `ob->funcname` (no parens) "function value from another object"
 * reference, a different (and here, unsupported) mechanism from the
 * `&->funcname(args)` partial-application syntax fixed elsewhere in this
 * file. `(l)` is a macro PARAMETER, so the closure needs the bound-
 * argument-helper pattern (see check_seen_bound() in
 * secure/simul_efun.lpc), not an inline `(: ($1)->check_seen(l) :))` --
 * a bare closure can't capture a macro parameter reliably at every
 * expansion site the way it can capture a real local variable. */
#define FILTER_IS_SEEN(l, x) \
    filter((x), (: check_seen_bound, (l) :))

/*
 * returns all objects in array x that can be seen, ie that aren't no_show.
 */
#define FILTER_SHOWN(x) \
    filter((x), (: !($1)->query_no_show() :))

/* no definitions beyond this line. */
#endif FILTER_DEF
