#include <daemons.h>
inherit DAEMON;
int abil();

int cmd_whip(string str)
{
    int a,b, i, clear, fl;
    string target_thing;
    object ob, tp;
    object *wield;
    if (!abil()) {
	write("What?\n");
	return 1;
    }
    tp = this_player();
    if ((!str || str=="") && !tp->query_current_attacker())
    {
	write("Syntax: <whip [living]>");
	return 1;
    }
    if (environment(tp)->query_property("no attack"))
    {
	write("Greater powers prevent your malice.");
	return 1;
    }

    if(!b=sizeof(wield=(object *)tp->query_wielded())) {
	notify_fail("You must be wielding a weapon to do this.\n");
	return 0;
    } 
    i = sizeof(wield);
    clear = 0;
    while (i--) {
	if (wield[i]->query_type() == "flail") {
	    clear = 1; fl = i; }
	if(wield[i]->query_type() == "axe") return notify_fail("You can't whip with an axe type weapon wielded!\n");

	if(wield[i]->query_type() == "blunt") return notify_fail("You can't whip with a blunt weapon wielded!\n");

	if(wield[i]->query_type() == "projectile") return notify_fail("You can't whip with a projectile weapon wielded!\n");

	if(wield[i]->query_type() == "knife") return notify_fail("You can't whip with a knife type weapon wielded!\n");

	if(wield[i]->query_type() == "blade") return notify_fail("You can't whip with a blade weapon wielded!\n");

    }
    if (!clear) return notify_fail("You must be wielding a flail type "
	  "weapon to whip.\n");

    if (tp->query_current_attacker() && !str) 
	ob = tp->query_current_attacker();
    else {
	ob = present(str, environment(tp));
	if (!ob)
	{
	    write("You dont see that here.");
	    return 1;
	}
	if (ob==tp)
	{
	    write("Attack yourself?");
	    return 1;
	}
    }
    if (tp->query_sp() < 50) 
    {
	write("You are too tired.");
	return 1;
    }
    if(tp->query_disable()) return notify_fail(
	  "You're too busy to be whipping people!\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    tp->set_disable();
    if (b > 1)
	if (this_player()->query_skill("attack") < random(70))
	    b = 1;
    while(b--) {

	a = this_player()->query_skill("attack")*2/3 +
	this_player()->query_stats("strength")*2/3 -
	ob->query_stats("dexterity")*2/3 +
	this_player()->query_skill("flail")*4/3 -
	ob->query_skill("defense")/2 +
	wield[b]->query_wc()*3;

	if (a < 0) {
	    write("You attempt to whip "+ob->query_cap_name()+", but "
	      "miss!");
	    message("info", this_player()->query_cap_name()+" attempts "
	      "to whip you, but misses.", ob);
	    message("info", this_player()->query_cap_name()+" attempts "
	      "to whip "+ob->query_cap_name()+" with "+
	      a_or_an(wield[fl]->query_name())+" "+
	      wield[fl]->query_name()+", but misses.",
	      environment(ob), ({ tp, ob }));
	    return 1;
	}
    }
    message("info", "With a quick stroke, you whip "
      +ob->query_cap_name()+" with your "+
      wield[fl]->query_name()+".", tp);
    message("info", "With a quick stroke, "+tp->query_cap_name()+
      "whips "+ob->query_cap_name()+" with "+tp->query_posessive()+
      wield[fl]->query_name()+"!", environment(tp), ({ tp, ob }));
    message("info", "With a quick stroke,"+tp->query_cap_name()+
      " whips you with "+tp->query_posessive()+" "+
      wield[fl]->query_name()+"!", ob);
    target_thing = (string)ob->return_target_limb();
    ob->do_damage(target_thing, a*2/3);
    ob->check_on_limb(target_thing);                            
    tp->add_sp(-(a/7));
    tp->add_skill_points("flail", (a/30));
    return 1;
}

int abil() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() != "warrior") return 0;
    if (o->query_skill("flail") >= 10)
	return 1;
}


void help() {
    write("
Syntax: <whip [living]>
By use of this ability, one uses a flail type weapon to
whip at a living opponent.
");
}

