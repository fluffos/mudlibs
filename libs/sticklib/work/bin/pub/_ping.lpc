// PING!!!  Bull, Tue May 1997
//
// Sends audible bell to the poor victim.



#include "/sys/interactive_info.h"

#include <cmd.h>
#include <invis_levels.h>

varargs nomask status
ping_cmd(string s, object me) {
    object target;

    if (!me && !(me = this_player())) return 0;

    // Let's prevent dummy newbies from spamming with this --Haw
    if((int)me->query_level() < 2)
	return notify_fail("You can't do that yet.\n"),0;

    if (!s) return notify_fail("Ping who?\n"), 0;
    if (!(target = find_player(lower_case(s))) ||
      (!me->query_coder_level() &&
	target->query_invis() >= IL_TOTALLY_INVISIBLE) )
	return notify_fail("I can't find such a player in here. Can you?\n"), 0;
    if (!(interactive(find_player(lower_case(s)))))
	return notify_fail("That person is currently linkdead. Try again later.\n"), 0;
    /*
      if (!me->query_coder_level() &&
	  target->query_invis() >= IL_TOTALLY_INVISIBLE )
	return notify_fail("I can't find such a player in here. Can you?\n"), 0;
    */

    if( me == target ) {
	target->binmsg("\a");
	target->tell_me("Whee! Pinging oneself is big fun! Beep beep!");
	return 1;
    }

    // Let's try to prevent some of the abuse... --Haw
    if((interactive_info(target, II_IDLE) < 120) && // 2min idle
      !me->query_coder_level())
	return notify_fail("Why, (s)he isn't even idle?\n"),0;

    // Check ignoration
    if (target->query_is_ignoring((string)me->query_real_name()) ||
      target->query_is_ignoring_level(me->query_level())) {
	me->tell_me(sprintf("You can't! %s is IGNORING you!",
	    capitalize((string)me->query_real_name())));
	return 1;
    }
    // Check 'ignoration' the other way --Kieve
    if (me->query_is_ignoring((string)target->query_real_name()))
    {
	me->tell_me(sprintf("Not while you're ignoring %s!",
	    target->query_objective()));
	return 1;
    }

    me->tell_me("PING! You ping "+capitalize(s)+".");
    target->binmsg("\a");
    target->tell_me("PING! "+capitalize((string)me->query_real_name())+" pings you.");
    return 1;
}
