// _causticblood.c
// Vampire ability
// Written by Daos on 10/31/07

#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define FAIL(s) return notify_fail(s+"\n");

int spell() {
    object tp = this_player();
    if (tp->query_class() == "vampire" && tp->query_level() >= 15) return 1;
    if (tp->query_skill("necromancy") >= 15 * 5) return 1;
    return 0;
}

string type() { return "attack"; }

int can_cast(object tp, object targ) {
    object env = environment(tp);

    if (!tp) return 0;

    if (env->query_property("no magic") || env->query_property("no attack")) 
	FAIL("You are unable to concentrate.");


    if (tp->query_busy()) 
	FAIL("You are busy.");


    if (tp->query_ghost()) 
	FAIL("You are unable to do that.");


    if (!targ) 
	FAIL("Soulfire whom");


    if (!living(targ)) 
	FAIL("That is not a living object.");


    if(userp(targ) && interactive(targ)) 
	FAIL("You may not attack link-dead players.");


    if (!tp->kill_ob(targ)) 
	FAIL("You cannot attack "+targ->query_objective()+".");

    return 1;
}

int cmd_soulfire(string str) 
{
    object tp = this_player();
    object env = environment(tp);
    object targ;
    int i, dmg, cost;

    if (!spell())
	return 0;

    if (str) 
	targ = present(str, env);
    else 
	targ = tp->query_current_attacker();

    if (!can_cast(tp, targ)) return 0;

    dmg = BALANCE3_D->get_damage(tp, targ, 2, 
      ({"necromancy"}), ({"intelligence"}), );

    cost = to_int(dmg / 8.5);

    tp->add_mp(-(cost + random(cost / 12)));
    tp->set_casting(dmg);
    tp->set_disable();

    message("magic", "You burn "+targ->query_cap_name()+".", tp);
    message("magic", tp->query_cap_name()+" burns you.", targ);
    message("magic", tp->query_cap_name()+" burns "+targ->query_cap_name()+
      ".", env, ({tp, targ}) );

    return 1;
}       
