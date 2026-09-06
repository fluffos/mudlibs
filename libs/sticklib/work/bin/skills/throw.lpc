/*
 * Throw skill command, which can be used in combat or just to
 * throw things around.
 *
 * NOTE: Skill commands can NOT use notify_fail()!
 *
 * This throw will replace _ALL_GUILD_THROWING_SKILLS_ (tth, nth, ...)
 *

TODO:
How to handle extra effects when the thrown thing strikes? Like
contact poison or some icky goo which fills target's eyes?
Something like "extra_throw(thrower, target)" in the object?
Nope. It's a critical, use extra_critical(). See /bin/daemons/
criticalsd.c (coming up) for more information.

 *
 * Copyright (c) 1993 The Stickmud Project,
 * All rights reserved.
 *
 */
#include <cmd.h>

inherit "/lib/find_name";

nomask int
throw_cmd(string arg) {
    int t, sk;
    object item, target, env;
    string myname, iname, tname, what, targid;

    if (!CHECK) return 0;

    /* TODO: If we are in combat, we assume that we throw
       things automatically at our opponent. */

    if (!arg) {
	write("Throw what? And perhaps, at whom?\n");
	return 0;
    }

    /* TODO: parse_command... */

    /* 'throw money away'? */
    if (sscanf(arg, "%s away", what) == 1) {
	targid = 0;
    } else {
	/* 'throw caterpillar at christmas-tree monster'? */
	if (sscanf(arg, "%s at %s", what, targid) != 2) {
	    what = arg;
	    targid = 0;
	}
    }

    item = present(what, TP);
    if (targid) target = present(targid, environment(TP));

    if (!item) {
	write("You aren't carrying any \"" + what + "\".\n");
	return 0;
    }

    if (targid && !target) {
	write("You can't see anything called \"" + targid +
	  "\" around here.\n");
	return 0;
    }

    env = environment(TP);

    if (!env) return 0; /* No environment??? Impossible! */

    myname = find_name(TP, 1);
    iname = find_name(item, 0);

    if (item->drop())
    {
	TP->tell_me("You can't throw " + iname + "!\n");
	return 1;
    }

    /* No target, we just throw a thing away. Equal to drop command,
       except that it might damage the item, and we don't have all the
       extra functions with throw, like 'throw all' or 'throw 4 coins'
       etc. but who cares. */
    if (!target)
    {
	TP->tell_me("You throw " + iname + " away.\n");
	tell_room(env, myname + " throws " + iname + " away.\n", ({ TP }));
	TP->add_weight(-((int)item->query_weight()));

	/* Todo: fragile things may break here. */

	move_object(item, env);
	return 1;
    }

    tname = find_name(target, 1);

    if (environment(target) != env)
    {
	TP->tell_me("You can't see " + tname + " around here.\n");
	return 1;
    }

    TP->tell_me("You throw " + iname + " at " + tname + "!\n");
    env->tell_here(myname + " throws " + iname + " at " + tname + "!\n",
      ({ TP, target }), 0);
    target->tell_me(myname + " throws " + iname + " at you!\n");

    /* Get the 0..100000 value */
    sk = (int)TP->query_skill_value("throw");

    /* TODO:
       make skill roll
       did we fumble, fail, hit, hit critically or what?
       EXTREMELY LONG LIST of different messages for hitting, missing,
       fumbling and criticals! (Coming soon to /bin/daemons/criticalsd.c!)
       A HUGE AMOUNT of different fumbles and criticals!
       how much damage?
       what extra effects?
     */

    /* Skill advance roll */
    TP->advance_skill("throw", 0);
    /* Replace 0 with bonus or penalty (range -50000..50000) to learning
       changes. Failure should give a bonus (?) */

    return 1;
}
