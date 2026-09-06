// 20-Dec-96 / Graah: Now takes a little fatigue too. Disguised non-coders
//		      do show their name when shouting. It's so loud.
// 15-jan-96 / Necros: Earmuffs support added.

#include <cmd.h>
#include <coder_levels.h>
#include <macros.h>
#include <room_defs.h>
#include <std_lib>
#include <tell_me.h>
#include <conditions.h>

#define NAME ((string)me->query_name())
#define LEVEL ((int)me->query_level())
#define CODERLVL ((int)me->query_coder_level())


varargs nomask int
shout_cmd(string str, object me)
{
    string msg, n;
    status hidename;

    if (!me && !(me = this_player())) return 0;
    if (!me->is_npc())
	if (me != this_player() && interactive(me) && me->query_coder_level())
	    return 0;

	/* Can't patch coders to shout... */
    if (!str) {
	notify_fail("Shout what?\n");
	return 0;
    }

    /* Stop "The XXXmud is best" shouts from 1st level jerks */
    if (LEVEL < 2 && !IS_CODER(CODERLVL)) {
	me -> tell_me("Your feeble voice doesn't carry very far. \
You should use 'tell' instead until you get to level 2.");
	return 1;
    }

    if (sizeof(str) > 320) { /* //Starbyt */
	me->tell_me("Your throat is too sore to shout that much at one time!");
	return 1;
    }

    if (!IS_CODER(CODERLVL)) {
	if ((int)me->query_sp() < 20) {
	    //	    me -> tell_me("You don't have enough spell points (min. 20)!");
	    me -> tell_me("You are too tired mentally to do that (min. 20 SP)!");
	    return 1;
	}
	if ((int)me->query_fp() < 20) {
	    //	    me -> tell_me("You don't have enough fatigue points (min. 20)!");
	    me -> tell_me("You are too tired to do that (min. 20 FP)!");
	    return 1;
	}
	me->add_sp(-20);
	me->add_fp(-20);
    }

    if (!me->query_can_move()) {
	me->tell_me("Your shout sounded more like a whisper in your condition.");
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

    hidename = (IS_CODER(CODERLVL) || (int)me->query_level() >= 60);

    if (!hidename)
	msg = sprintf("%s shouts: %s",
	  capitalize((string)me->query_real_name()), str);
    else
	msg = sprintf("%s shouts: %s", NAME, str);

    if (environment(me)->query_prevent_shout() ||
      environment(me)->query(ROOM_ISOLATED)) {
	me->tell_me("You have a feeling that your shout didn't carry very far.");
	environment(me)->tell_here(msg, me);
    } else {
	object *u;
	int i;
	u = users();
	for (i = 0; i < sizeof(u); i++) {
	    if (u[i] == me) continue;
	    if (u[i]->listen_shout() >= LEVEL) continue;
	    // Deaf players can't hear shouting! //Chopin
	    if(u[i]->query_condition(C_DEAF)) continue;
	    if(environment(u[i]))
		if(environment(u[i])->query(ROOM_ISOLATED)) continue;
	    if (!hidename || u[i]->query_coder_level())
		n = capitalize((string)me->query_real_name());
	    else
		n = NAME;

	    if (environment(me) == environment(u[i]))
		u[i]->tell_me(n + " shouts in this room: " + str, 0, TELL_TYPE_SHOUT, 0, 0, 0);
	    else
		u[i]->tell_me(n + " shouts: " + str, 0, TELL_TYPE_SHOUT, 0, 0, 0);
	}

	me->tell_me("You shout: "+str, 0, TELL_TYPE_SHOUT, 0, 0, 0);
	log_file("SHOUT", capitalize((string)me->query_real_name()) + ": " + str + "\n");
    }

    return 1;
}
