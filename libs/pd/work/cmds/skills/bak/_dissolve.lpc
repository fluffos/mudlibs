#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

string type() { return "attack"; }

int cmd_dissolve(string str) {
    int dmg;
    object ob, tp, env;
    tp = this_player();
    env = environment(tp);
    if (!str) ob = tp->query_current_attacker();
    else ob = present(str, env);
    
    if(!spell()) return 0;
    
    if (!ob) {
	notify_fail("You do not see that here.\n");
	return 0;
    }
    if (tp->query_subclass() != "sorceror")
	return notify_fail("What?\n");
    if (tp->query_skill("psionics") < 25)
	return notify_fail("You cannot cast this.\n");
    
    if (this_player()->query_busy())
	return notify_fail("You are busy.\n");
    
    if (env->query_property("no attack") || env->query_property("no magic"))
	return notify_fail("Greater powers prevent your malice.\n");
    
    if (!living(ob))
	return notify_fail("Syntax: <dissolve [living]>\n");
    
    if (ob == tp)
	return notify_fail("Attack yourself?\n");
    
    if (tp->query_mp() < 55) 
	return notify_fail("Your spell fails, due to lack of magic.\n");
    
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    if (tp->query_skill("psionics"))
	dmg = BALANCE_D->get_damage( tp, ob, 1, ({ "psionics" }),
	  ({ "wisdom", "intelligence" }) );
    if (dmg < 10) {
	write("%^CYAN%^Your spell fails.");
	tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
	return 1;
    }
    tell_room(env, "%^BOLD%^%^CYAN%^"+tp->query_cap_name()+" trys to dissolve "
      +ob->query_cap_name()+"!%^RESET%^",
      ({ ob, tp }));
    write("%^BOLD%^%^CYAN%^You try to dissolve "
      +ob->query_cap_name()+"!%^RESET%^");
    tell_object(ob, "%^BOLD%^%^CYAN%^"+tp->query_cap_name()+
      " just tried to dissolve you!%^RESET%^");
    tp->add_mp(-dmg/7);
    tp->set_casting(dmg);
    tp->set_disable();
    return 1;
}

void help() {
    write("
Syntax: <dissolve [living]>
When casting dissolve, the sorceror trys to dissolve their
opponent using the force of their mind.
");
}

int spell() {
   object o;
   o = this_player();
   if (o->query_subclass() == "sorceror")
   if (o->query_skill("psionics") >= 25)
   if (o->query_level() > 1) return 1;
     return 0;
}


