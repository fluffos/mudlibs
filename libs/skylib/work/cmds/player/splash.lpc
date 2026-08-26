/* make command for making snowballs and snowmen. Moved from /global/pweath.c
 * by Ceres 24/3/96
 */
inherit COMMAND_BASE;
#include <weather.h>

mixed cmd(object *obs) {
    object env, ob;
    string str;

    env = environment(TP);

    if ( !env->query_baths() ) {
        if ((string)env->query_property("location") == "inside")
            return notify_fail("You must be outside to do that.\n");

        if (!WEATHER->query_raining(env))
            return notify_fail("It must be raining to splash someone.\n");
    }

    foreach(ob in obs) {
        ob->add_effect("/std/effects/other/wetness", 2 + random(4));
        if(ob == this_player())
            continue;

        tell_object(ob, (string)TP->a_short()+" splashes "+
          query_multiple_short(obs - ({ ob }) + ({ "you" }))+".\n");
    }


    str = query_multiple_short(obs);
    write("You splash "+str+".\n");
    say(TP->a_short()+" splashes "+str+".\n", obs);
    return 1;
} /* cmd() */

mixed *query_patterns() {
    return ({ "<indirect:living>",(: cmd($1) :) });
} /* query_patterns() */
