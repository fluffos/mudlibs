#include <std.h>
#include <daemons.h>
#define FAIL(s) return notify_fail(s);
#define BALANCE3_D "/daemon/balance3_d"

inherit DAEMON;

int spell() {
    object tp=this_player();
    if (tp && tp->query_skill("necromancy") >= 180)
	return 1;
    return 0;

}

int ok_cast(object tp, object tgt) {

    if (environment(tp)->query_property("no attack"))
	FAIL("You cannot do that here.\n");

    if (!tgt)
	FAIL("You don't see that here.\n");

    if (!living(tgt))
	FAIL("Silly! That is not alive!\n");

    if (tp == tgt)
	FAIL("Get a noose..it's faster.\n");

    if (!tp->kill_ob(tgt))
	FAIL("That cannot be attacked by you yet.\n");

    return 1;
}

int cmd_deathgrip(string str) {
    object tp=this_player();
    object tgt;
    int cost, dmg, rank;


    if (!spell()) return 0;

    if (tp->query_disable()) return 1;

    if (!str) tgt=tp->query_current_attacker();
    else tgt=present(str,environment(tp));

    if (!ok_cast(tp,tgt)) return 0;

    if (tp->query_skill("necromancy") >= 240) rank=2;
    else rank=1;

    dmg=BALANCE3_D->get_damage(tp, tgt, rank, ({"necromancy", "necromancy", "conjuring"}), ({"wisdom", "wisdom", "intelligence"}) );

    if (dmg > 150) dmg=150+random(tp->query_level()*2);

    cost=dmg/10;

    if (tp->query_mp() < cost)
	FAIL("Your magics are too low to concentrate.\n");

    tp->set_disable(1);
    tp->add_mp(-(cost+random(cost/10)));

    if (dmg < 30) {
	message("combat","%^BOLD%^%^RED%^You attempt to use the souls of the undead to hold "+tgt->query_cap_name()+ "down, but the underworld ignores your call.%^RESET%^", tp);

	message("combat",tp->query_cap_name()+" %^BOLD%^%^RED%^attempts to use the souls of the undead to hold "+tgt->query_cap_name()+ " down, but the underworld ignores your call.%^RESET%^", environment(tp), ({ tp, tgt}) );

	message("combat",tp->query_cap_name()+" %^BOLD%^%^RED%^attempts to use the souls of the undead to hold you down, but the underworld ignores your call.%^RESET%^", tgt);
    }
    else {
	message("combat","%^BOLD%^%^RED%^You %^BLACK%^call %^WHITE%^upon %^RED%^the %^BLACK%^souls %^WHITE%^of %^RED%^the %^BLACK%^undead %^WHITE%^to %^RED%^hold %^BLACK%^"+tgt->query_cap_name()+" %^WHITE%^down %^RED%^in %^BLACK%^a %^WHITE%^grasp %^RED%^to %^BLACK%^the %^WHITE%^earth.%^RESET%^", tp);

	message("combat",tp->query_cap_name()+" %^BOLD%^%^BLACK%^calls %^WHITE%^upon %^RED%^the %^BLACK%^undead %^WHITE%^to %^RED%^crawl %^BLACK%^up %^WHITE%^from %^RED%^the %^BLACK%^earth %^WHITE%^and %^RED%^hold %^BLACK%^you %^WHITE%^down %^RED%^in %^BLACK%^a %^WHITE%^tight %^RED%^grasp.%^RESET%^", tgt);

	message("combat",tp->query_cap_name()+ "%^BOLD%^%^BLACK%^calls %^WHITE%^upon %^RED%^the %^BLACK%^undead %^WHITE%^to %^RED%^crawl %^BLACK%^up %^WHITE%^from %^RED%^the %^BLACK%^earth %^WHITE%^and %^RED%^hold%^BLACK%^" +tgt->query_cap_name()+ "%^WHITE%^down %^RED%^in %^BLACK%^a %^WHITE%^tight %^RED%^grasp.%^RESET%^", environment(tp), ({ tp, tgt }) );

	tgt->do_damage(tgt->return_target_limb(), dmg);
	if(tp->query_current_attacker()) {
	    if(random(100) > 60) {    
		tp->query_current_attacker()->set_paralyzed(2, "You are unable to move right now!");
	    }

	    return 1;
	}
    }
}

void help() {
    message("help","\n"
      "Syntax: <deathgrip [living]>\n\n"
      "A high mortal spell.\n"
      "This spell is used to call upon the undead to come up from the earth and strap down their vitcims in a death grip.",
      this_player());
}
#include <std.h>
#include <daemons.h>
#define FAIL(s) return notify_fail(s);
#define BALANCE3_D "/daemon/balance3_d"

inherit DAEMON;

int spell() {
    object tp=this_player();
    if (tp && tp->query_skill("necromancy") >= 180)
	return 1;
    return 0;

}

int ok_cast(object tp, object tgt) {

    if (environment(tp)->query_property("no attack"))
	FAIL("You cannot do that here.\n");

    if (!tgt)
	FAIL("You don't see that here.\n");

    if (!living(tgt))
	FAIL("Silly! That is not alive!\n");

    if (tp == tgt)
	FAIL("Get a noose..it's faster.\n");

    if (!tp->kill_ob(tgt))
	FAIL("That cannot be attacked by you yet.\n");

    return 1;
}

int cmd_deathgrip(string str) {
    object tp=this_player();
    object tgt;
    int cost, dmg, rank;


    if (!spell()) return 0;

    if (tp->query_disable()) return 1;

    if (!str) tgt=tp->query_current_attacker();
    else tgt=present(str,environment(tp));

    if (!ok_cast(tp,tgt)) return 0;

    if (tp->query_skill("necromancy") >= 240) rank=2;
    else rank=1;

    dmg=BALANCE3_D->get_damage(tp, tgt, rank, ({"necromancy", "necromancy", "conjuring"}), ({"wisdom", "wisdom", "intelligence"}) );

    if (dmg > 150) dmg=150+random(tp->query_level()*2);

    cost=dmg/10;

    if (tp->query_mp() < cost)
	FAIL("Your magics are too low to concentrate.\n");

    tp->set_disable(1);
    tp->add_mp(-(cost+random(cost/10)));

    if (dmg < 30) {
	message("combat","%^BOLD%^%^RED%^You attempt to use the souls of the undead to hold "+tgt->query_cap_name()+ "down, but the underworld ignores your call.%^RESET%^", tp);

	message("combat",tp->query_cap_name()+" %^BOLD%^%^RED%^attempts to use the souls of the undead to hold "+tgt->query_cap_name()+ " down, but the underworld ignores your call.%^RESET%^", environment(tp), ({ tp, tgt}) );

	message("combat",tp->query_cap_name()+" %^BOLD%^%^RED%^attempts to use the souls of the undead to hold you down, but the underworld ignores your call.%^RESET%^", tgt);
    }
    else {
	message("combat","%^BOLD%^%^RED%^You %^BLACK%^call %^WHITE%^upon %^RED%^the %^BLACK%^souls %^WHITE%^of %^RED%^the %^BLACK%^undead %^WHITE%^to %^RED%^hold %^BLACK%^"+tgt->query_cap_name()+" %^WHITE%^down %^RED%^in %^BLACK%^a %^WHITE%^grasp %^RED%^to %^BLACK%^the %^WHITE%^earth.%^RESET%^", tp);

	message("combat",tp->query_cap_name()+" %^BOLD%^%^BLACK%^calls %^WHITE%^upon %^RED%^the %^BLACK%^undead %^WHITE%^to %^RED%^crawl %^BLACK%^up %^WHITE%^from %^RED%^the %^BLACK%^earth %^WHITE%^and %^RED%^hold %^BLACK%^you %^WHITE%^down %^RED%^in %^BLACK%^a %^WHITE%^tight %^RED%^grasp.%^RESET%^", tgt);

	message("combat",tp->query_cap_name()+ "%^BOLD%^%^BLACK%^calls %^WHITE%^upon %^RED%^the %^BLACK%^undead %^WHITE%^to %^RED%^crawl %^BLACK%^up %^WHITE%^from %^RED%^the %^BLACK%^earth %^WHITE%^and %^RED%^hold%^BLACK%^" +tgt->query_cap_name()+ "%^WHITE%^down %^RED%^in %^BLACK%^a %^WHITE%^tight %^RED%^grasp.%^RESET%^", environment(tp), ({ tp, tgt }) );

	tgt->do_damage(tgt->return_target_limb(), dmg);
	if(tp->query_current_attacker()) {
	    if(random(100) > 60) {    
		tp->query_current_attacker()->set_paralyzed(2, "You are unable to move right now!");
	    }

	    return 1;
	}
    }
}

void help() {
    message("help","\n"
      "Syntax: <deathgrip [living]>\n\n"
      "A high mortal spell.\n"
      "This spell is used to call upon the undead to come up from the earth and strap down their vitcims in a death grip.",
      this_player());
}
