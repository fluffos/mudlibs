#include <std.h>
#include <daemons.h>
#define FAIL(s) return notify_fail(s);
#define BALANCE3_D "/daemon/balance3_d"
inherit DAEMON;
int spell() {
    object tp=this_player();
    if (tp && tp->query_skill("necromancy") >= 210)
	return 1;
    return 0;

}

int ok_cast(object tp, object tgt) {

    if (environment(tp)->query_property("no attack"))
	FAIL("You cannot do that here.\n");

    if (!tgt)
	FAIL("You don't see that here.\n");

    if (!living(tgt))
	FAIL("You cannot kill things that are not living!\n");

    if (tp == tgt)
	FAIL("Are you emo?\n");

    if (!tp->kill_ob(tgt))
	FAIL("That cannot be attacked by you yet.\n");

    return 1;
}

int cmd_soulsurge(string str) {
    object tp=this_player();
    object *tgts = filter(all_inventory(this_player()), (: $1->is_living() :) )-({this_player()});
    foreach (object tgt in tgts) {
	int cost, dmg, rank;

	if (!spell()) return 0;

	if (tp->query_disable()) return 1;

	if (!str) tgt=tp->query_current_attacker();
	else tgt=present(str,environment(tp));

	if (!ok_cast(tp,tgt)) return 0;

	if (tp->query_skill("necromancy") >= 320) rank=2;
	else rank=1;

	dmg=BALANCE3_D->get_damage(tp, tgt, rank, ({"necromancy", "necromancy", "conjuring"}), ({"wisdom", "wisdom", "intelligence"}) );

	if (dmg > 400) dmg=400+random(tp->query_level()*2);

	cost=dmg/10;

	if (tp->query_mp() < cost)
	    FAIL("Your magics are too low to concentrate.\n");

	tp->set_disable(1);
	tp->add_mp(-(cost+random(cost/10)));

	if (dmg < 30) {
	    message("combat","%^BOLD%^%^RED%^You attempt to raise souls from the underworld to attack "+tgt->query_cap_name()+", but the underworld ignores your call.%^RESET%^", tp);

	    message("combat",tp->query_cap_name()+" %^BOLD%^%^RED%^attempts to raise souls from the underworld to attack "+tgt->query_cap_name()+ "but the underworld ignores their call.%^RESET%^", environment(tp), ({ tp, tgt}) );

	    message("combat",tp->query_cap_name()+" %^BOLD%^%^RED%^attempts to raise souls from the underworld to kill you, but the underworld ignores their call.%^RESET%^", tgt);
	}
	else {
	    message("combat","%^BOLD%^%^BLACK%^You %^RESET%^%^RED%^raise %^BOLD%^%^BLACK%^your %^RESET%^%^RED%^hands %^BOLD%^%^BLACK%^to %^RESET%^%^RED%^call %^BOLD%^%^BLACK%^upon %^RESET%^%^RED%^the %^BOLD%^%^BLACK%^undead %^RESET%^%^RED%^souls %^BOLD%^%^BLACK%^of %^RESET%^%^RED%^the %^BOLD%^%^BLACK%^underworld %^RESET%^%^RED%^to %^BOLD%^%^BLACK%^kill %^RESET%^%^RED%^"+tgt->query_cap_name()+"%^BOLD%^%^BLACK%^.%^RESET%^", tp);

	    message("combat",tp->query_cap_name()+" %^BOLD%^%^BLACK%^raises %^RESET%^%^RED%^their %^BOLD%^%^BLACK%^hands %^RESET%^%^RED%^towards %^BOLD%^%^BLACK%^you %^RESET%^%^RED%^shooting %^BOLD%^%^BLACK%^undead %^RESET%^%^RED%^souls %^BOLD%^%^BLACK%^towards %^RESET%^%^RED%^your %^BOLD%^%^BLACK%^chest, %^RESET%^%^RED%^making %^BOLD%^%^BLACK%^your %^RESET%^%^RED%^body %^BOLD%^%^BLACK%^cringe %^RESET%^%^RED%^and %^BOLD%^%^BLACK%^your %^RESET%^%^RED%^lifeforce %^BOLD%^%^BLACK%^drain.%^RESET%^", tgt);

	    message("combat",tp->query_cap_name()+ "%^BOLD%^%^BLACK%^raises %^RESET%^%^RED%^their %^BOLD%^%^BLACK%^hands %^RESET%^%^RED%^towards%^BOLD%^%^BLACK%^" +tgt->query_cap_name()+ "%^RESET%^%^RED%^shooting %^BOLD%^%^BLACK%^undead %^RESET%^%^RED%^souls %^BOLD%^%^BLACK%^towards %^RESET%^%^RED%^their %^BOLD%^%^BLACK%^chest, %^RESET%^%^RED%^making %^BOLD%^%^BLACK%^their %^RESET%^%^RED%^body %^BOLD%^%^BLACK%^cringe %^RESET%^%^RED%^and %^BOLD%^%^BLACK%^their %^RESET%^%^RED%^lifeforce %^BOLD%^%^BLACK%^drain.%^RESET%^", environment(tp), ({ tp, tgt }) );

	    tgt->do_damage(tgt->return_target_limb(), dmg);
	}

	return 1;
    }

}

void help() {
    message("help","\n"
      "Syntax: <soulsurge>\n\n"
      "A area spell for high moral Necromancers.\n"
      "This spell is used to attack multiple targets at once.",
      this_player());
}
