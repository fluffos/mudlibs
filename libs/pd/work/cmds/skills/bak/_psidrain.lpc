//   baesd on /bin/user/_absorb.c
//   a dungeonware.net production

#include <std.h>
#include <daemons.h>

inherit DAEMON;
int spell(); 
string type() { return "healing"; }
int cmd_psidrain (string str) {
    object ob;
    int ma, psi, damage, def;
    
    if (!spell()) {
	return 0;
    }
    
    if(!str) {
	ob = (object)this_player()->query_current_attacker();
	if(!ob) {
	    notify_fail("Psidrain what?\n");
	    return 0;
	}
    }
    
    else ob = present(str, environment(this_player()));
    if(!ob) ob = parse_objects(environment(this_player()), str);
    if(!ob || !living(ob)) {
	notify_fail("Look again.\n");
	return 0;
    }
    if (this_player()->query_busy())
	return notify_fail("You are busy.\n");
    if(environment(this_player())->query_property("no magic") ||
      environment(this_player())->query_property("no attack")) {
	notify_fail("A magic force prevents your use of magic here.\n");
	return 0;
    }
    if(!psi=(int)this_player()->query_skill("psionics")) {
	notify_fail("You do not have the mental abilities for this.\n");
	return 0;
    }
    if(!ma=(int)this_player()->query_skill("magic attack")) {
	notify_fail("Your magic is not yet strong enough for this spell.\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 30) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(this_player()->query_ghost()) {
	notify_fail("Your voice is hollow.\n");
	return 0;
    }
    if(this_player()->query_casting()) return 1;
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    if(environment(this_player())->query_property("no attack")) {
	notify_fail("A magic force prevents you from casting your spell.\n");
	return 0;
    }
    write("%^BOLD%^You drain the mental strength of "+(string)ob->query_cap_name()+" and "
      "feel stronger.%^RESET%^");
    tell_room(environment(this_player()), this_player()->query_cap_name()+ 
      " suddenly looks stronger.", ({ob, this_player()}));
    damage = BALANCE3_D->get_damage( this_player(), ob, 2, ({ "magic attack", "psionics" }),
      ({ "wisdom" }) );
    damage = damage*2/3;
    this_player()->set_disable();
    this_player()->set_casting(damage);
    this_player()->add_hp(damage/3);
    this_player()->add_mp(-damage/7);
    tell_object(ob,
      this_player()->query_cap_name()+
      " invades your mind sapping your mental strength!");
    return 1;
}

void help() {
    write("Syntax: <psidrain [enemy]>\n\n"
      "Using their mental attributes, sorcerors drain mental "
      "energy from the target.\n"
    );
}
int spell() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_subclass() != "sorceror") return 0;
    if (tp->query_skill("psionics") < 100) return 0;
    if (tp->query_level() < 20) return 0;
    return 1;
}
