/*
 * /sys/filter_funs.c
 *
 * A set of functions often used by filter
 */

#pragma no_clone
#pragma no_inherit
#pragma resident
#pragma save_binary
#pragma strict_types

#include <macros.h>

/*
 * Function name: filter_living
 * Description  : This filter is used to see which objects in an array
 *                are living.
 * Arguments    : object ob - the object to test.
 * Returns      : int 1/0   - true if the object is living.
 */
public nomask int
filter_living(object ob)
{
    return living(ob);
}

/*
 * Function name: filter_dead
 * Description  : This filter is used to see which objects in an array
 *                are not living.
 * Arguments    : object ob - the object to test.
 * Returns      : int 1/0   - true if the object is not living.
 */
public nomask int
filter_dead(object ob)
{
    return !living(ob);
}

/*
 * Function name: filter_shown
 * Description  : This filter is used to see which objects in an array
 *                can be seen at all, ie, which objects are not marked
 *                no_show.
 * Arguments    : object ob - the object to test.
 * Returns      : int 1/0   - true if the object can be seen.
 */
public nomask int
filter_shown(object ob)
{
    return !(ob->query_no_show());
}

/*
 * Function name: filter_present_live
 * Desciption   : This filter is used to see which objects in an array
 *                are living and in the environment of this_player().
 * Arguments    : object ob - the object to test.
 * Returns      : int 1/0   - true if the object is living and in the
 *                            environment of this_player().
 */
public nomask int
filter_present_living(object ob)
{
    return (living(ob) && (environment(this_player()) == environment(ob)));
}

/*
 * Function name: filter_can_see
 * Description  : This filter is used to see which objects in an array
 *                can be seen by a certain other object.
 * Arguments    : object ob     - the object to check.
 *                object looker - the object that wants to see them.
 * Returns      : int 1/0       - true if the object can be seen by looker.
 */
public nomask int
filter_can_see(object ob, object looker)
{
    return CAN_SEE(looker, ob);
}

/*
 * Function name: filter_is_seen
 * Description  : This filter is used to see which objects in an array
 *                can see a certain object.
 * Arguments    : object ob     - the object to check.
 *                object target - the object to be seen.
 * Returns      : int 1/0       - true if looker can be seen by target.
 */
public nomask int
filter_is_seen(object ob, object target)
{
    return CAN_SEE(ob, target);
}

/*
 * Function name: filter_interactive
 * Description  : This filter is used to see which objects in an array
 *                are interactive players.
 * Arguments    : object ob - the object to check.
 * Returns      : int 1/0   - true if the object is an interactive player.
 */
public nomask int
filter_interactive(object ob)
{
    return interactive(ob);
}

/*
 * Function name: filter_gender
 * Description  : This filter is used to see which object in an array
 *                are of a certain gender.
 * Arguments    : object ob     - the object to check.
 *                int    gender - the gender wanted.
 * Returns      : int 1/0       - true if 'ob' is of gender 'gender'.
 */
public nomask int
filter_gender(object ob, int gender)
{
    return (ob->query_gender() == gender);
}

/*
 * Function name: filter_race_name
 * Description  : This filter is used to see which object in an array
 *                are of a certain race.
 * Arguments    : object ob   - the object to check.
 *                string race - the race wanted.
 * Returns      : int 1/0     - true if 'ob' is of race 'race'.
 */
public nomask int
filter_race_name(object ob, string race)
{
    return (ob->query_race_name() == race);
}

/*
 * Function name: map_fun
 * Description  : This map is used to call a specific function in all objects
 *                in an array and return an array or mapping containing the
 *                values returned by the called function.
 * Arguments    : mixed ob   - the object to call.
 *                string fun - the function to call in the object.
 * Returns      : mixed      - the return value of the function.
 */
mixed
map_fun(mixed ob, string fun)
{
    return call_other(ob, fun);
}
