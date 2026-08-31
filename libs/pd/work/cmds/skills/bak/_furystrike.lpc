// a dungeonware.net copy -00.09.21-
// coded for Primal Darkness by Asmodeus
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_furystrike(string str) {
    int dmg, hits, hitsl, hitsm, hitsn, hitso;
    object ob, tp, env;
    tp = this_player();
    env = environment(tp);
    if(!abil()) return 0;
    if (!str) ob = tp->query_current_attacker();
    else ob = present(str, env);
    if (!ob) {
	if (str)
	    notify_fail("You do not see "+str+" here.\n");
	return 0;
    }
    if (tp->query_subclass() != "monk")
	return notify_fail("What?\n");
    if (tp->query_level() < 5)
	return notify_fail("You cannot do this.\n");
    if (tp->query_ghost())
	return notify_fail("You try, but realize you're dead.\n");
    if (env->query_property("no attack") || env->query_property("no magic"))
	return notify_fail("Greater powers prevent your malice.\n");
    if (!living(ob))
	return notify_fail("Your target is dead.");
    if (tp->query_busy())
	return notify_fail("You are busy.\n");
    if (ob == tp)
	return notify_fail("That is not wise.\n");
    if (tp->query_sp() < 20) 
	return notify_fail("You are too tired.\n");
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    tp->set_disable();
    dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "attack", "melee" }),
      ({ "strength" }) );
    if (dmg < 10) {
	write("You miss!");
	return 1;
    }
    write("%^BOLD%^WHITE%^You strike "+ob->query_cap_name()+" with your palm!");
    tell_object(ob, tp->query_cap_name()+" strikes "+tp->query_title_gender()+" with an open palm!");
    tell_room(env, "%^BOLD%^WHITE%^"+tp->query_cap_name()+" strikes "+ob->query_cap_name()+" with an open palm!", ({ob, tp}));
    tp->add_sp(- (10 + random(dmg/10)));
    ob->damage(dmg);
    
    if ((tp->query_level()) > 29 && random(20) < 10) {
	hitsl = BALANCE_D->get_damage( tp, ob, 2, ({ "attack", "melee" }),
	  ({ "strength" }) );
	hitsl = hitsl / 2;
	write("You sneak in another punch!");
	tell_object(ob, tp->query_cap_name()+" hits you with another punch!");
	tell_room(env, tp->query_cap_name()+" hits "+ob->query_cap_name()+" with
another punch!", ({ob,tp}));
tp->add_sp(-(10 + random(hitsl/40)));
ob->damage(hitsl);
}
if ((tp->query_level()) > 39 && random(20) < 12) {
hitsm = BALANCE_D->get_damage( tp, ob, 3, ({ "attack", "melee" }),
                                   ({ "strength" }) );
hitsm = hitsm / 3;
write("You sneak in another punch!");
tell_object(ob, tp->query_cap_name()+" hits you with another punch!");
tell_room(env, tp->query_cap_name()+" hits "+ob->query_cap_name()+" with
another punch!", ({ob,tp}));
tp->add_sp(-(10 + random(hitsm /30)));
ob->damage(hitsm);
}
if ((tp->query_level()) > 49 && random(20) < 14) {
hitsn = BALANCE_D->get_damage( tp, ob, 3, ({ "attack", "melee" }),
                                   ({ "strength" }) );
hitsn = hitsn / 4;
write("You sneak in another punch!");
tell_object(ob, tp->query_cap_name()+" hits you with another punch!");
tell_room(env, tp->query_cap_name()+" hits "+ob->query_cap_name()+" with
another punch!", ({ob,tp}));
tp->add_sp(-(10 + random(hitsn /20)));
ob->damage(hitsn);
}
if ((tp->query_level()) > 59 && random(20) < 16) {
hitso = BALANCE_D->get_damage( tp, ob, 4, ({ "attack", "melee" }),
                                   ({ "strength" }), ({ "strength", "dexterity" }) );
hitso = hitso / 5;
write("You hit your opponent in the head!");
tell_object(ob, tp->query_cap_name()+" hits you in the head!");
tell_room(env, tp->query_cap_name()+" hits "+ob->query_cap_name()+" in the head!",({ob,tp}));
tp->add_sp(-(10 + random(hitso /10)));
ob->damage(hitso);
}
return 1;
}
void help() {
write("
Syntax: <furystrike [victim]>
Allows a monk to strike their opponent multiple times.
");
}
int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() < 20) return 0;
   if (o->query_subclass() != "monk") return 0;
     return 1;
}
