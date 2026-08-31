#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_thornwrack(string str) {
    int dmg, x;
    object ob, tp, env;
    tp = this_player();
    env = environment(tp);
    if (!str) ob = tp->query_current_attacker();
    else ob = present(str, env);
    if (!ob) {
	if (str)
	    notify_fail("You do not see '"+str+"' here.\n");
	return 0;
    }
    if (!spell())
	return notify_fail("What?\n");
    if (tp->query_level() < 15)
	return notify_fail("You cannot cast this.\n");
    if (env->query_property("no attack") || env->query_property("no magic"))
	return notify_fail("Greater powers prevent your malice.\n");

    if (!living(ob))
	return notify_fail("Syntax: <thornwrack [living]>\n");
    if (this_player()->query_disable())
	return notify_fail("You are busy.\n");
    if (tp->query_skill("nature") < 55)
	return notify_fail("Your conjuring is not strong enough.\n");
    if (ob == tp)
	return notify_fail("Not quite your brightest idea yet...\n");
    if (tp->query_mp() < 75)
	return notify_fail("Your spell fails, due to lack of magic.\n");
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    dmg = tp->query_skill("nature")*2/3 + tp->query_stats("wisdom")/3;
    dmg += tp->query_skill("magic attack")/3,
    dmg -= ob->query_stats("wisdom")/2 + ob->query_skill("magic defense")/2;
    if (dmg < 1) {
	write("%^BLUE%^Your spell fails.");
	tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
	return 1;
    }
    x = tp->query_level()+tp->query_skill("nature")/2; 
    if (x < 1) return notify_fail("Your spell fails.\n");
    tell_room(env, ob->query_cap_name()+" screams as "+(string)x+" thorns rip out of "+possessive(ob)+" skin.", ({ ob, tp }));
    tell_object(ob, (string)x+" thorns suddenly rip out of your skin, then retract back into it!");
    write((string)x+" thorns rip out of "+ob->query_cap_name()+"'s skin, "
      "then retract back into it!");
    ob->damage(dmg+random(x/3)+random(x/3), "magic");
    tp->add_mp(-dmg/7);
    tp->add_skill_points("nature", (10 + random(15)));
    tp->set_disable();
    return 1;
}
void help() {
    write("
This powerful druid spell calls to the nature in all living things and
summons great thorns to attack from the inside out.
");
}
int spell() {
   object o;
   o = this_player();
  if (o && o->query_subclass() == "druid" && o->query_level() >= 15)
     if (o->query_skill("nature") >= 55)
     return 1;
}
