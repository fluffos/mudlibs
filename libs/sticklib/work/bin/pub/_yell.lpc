#include <cmd.h>
#include <coder_levels.h>
#include <macros.h>
#include <room_defs.h>
#include <stats.h>
#include <std_lib>

#define NAME ((string)me->query_name())
#define LEVEL ((int)me->query_level())
#define CODERLVL ((int)me->query_coder_level())


varargs nomask int
yell_cmd(string str, object me)
{
    string *p1, *p2, n;

    if (!me && !(me = this_player())) return 0;
    if (me != this_player() && interactive(me) && me->query_coder_level())
	return 0;

    /* Can't patch coders to shout... */
    if (!str) {
	notify_fail("Yell what?\n");
	return 0;
    }

    /* Stop "The XXXmud is best" shouts from 1st level jerks */
    if (LEVEL < 2 && !IS_CODER(CODERLVL)) {
	me -> tell_me("Your feeble voice doesn't carry very far. \
You should use 'tell' instead until you get to level 2.");
	return 1;
    }

    if (sizeof(str) > 160) { /* //Starbyt */
	me->tell_me("Your throat is too sore to yell that much at one time!");
	return 1;
    }

    if (!IS_CODER(CODERLVL)) {
	if ((int)me->query_sp() < 10) {
	    me -> tell_me("You don't have enough spell points (min. 10)!");
	    return 1;
	}
	if ((int)me->query_fp() < 5) {
	    me -> tell_me("You don't have enough fatigue points (min. 5)!");
	    return 1;
	}
	me->add_sp(-10);
	me->add_fp(-5);
    }

    if (!me->query_can_move()) {
	me->tell_me("Your yell sounded more like a whisper in your condition.");
	return 1;
    }

    if (me->query_ghost()) {
	me->tell_me("Your ghastly scream is absorbed by the ethereal plane.");
	return 1;
    }

    //   if (me->dump_esc(str)) return 1;

    if (!me->query_frog()) {
	if (me->query_intoxication())
	    str = (string)me->mumble(str);
    } else
	str = ({ "Hriibit! Hrriiibit!", "Quack! Croak!" })[random(2)];

    p1 = explode(object_name(environment(me)), "/");
    if (sizeof(p1) < 2)
    {
	me->tell_me("You are in so weird a place that yelling is not possible.");
	return 1;
    }

    if (environment(me)->query_prevent_shout() ||
      environment(me)->query(ROOM_ISOLATED)) {
	me->tell_me("You have a feeling that your yell didn't carry very far.");
	environment(me)->tell_here(NAME + " yells in this room: " + str, me);
    } else {
	object *u;
	int i, x;
	u = users();
	for (i = x = 0; i < sizeof(u); i++) {
	    if (u[i] == me || !environment(u[i])) continue;

	    p2 = explode(object_name(environment(u[i])), "/");

	    if (sizeof(p2) < 2) continue;

	    if ((p1[0] != p2[0]) || (p1[1] != p2[1])) continue;

	    if ((me->query_invis() || me->query_disguised()) &&
	      u[i]->query_coder_level())
		n = capitalize((string)me->query_real_name());
	    else n = NAME;

	    if (environment(me) == environment(u[i]))
		u[i]->tell_me(n + " yells in this room: " + str);
	    else
		u[i]->tell_me(n + " yells: " + str);

	    x++;
	}

	me->tell_me("You yell: "+str);

	if (random(80) < (int)me->query_stat(ST_INT))
	{
	    if (x < 1) me->tell_me("You feel lonely. No one heard you.");
	    else if (x < 2) me->tell_me("You think someone heard you.");
	    else if (x < 5) me->tell_me("You think a few people heard that.");
	    else me->tell_me("Many people heard that!");
	}
    }

    return 1;
}
