#include <std.h>
inherit DAEMON;
int spell();
int cmd_scorch(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i;
    string what;
    object *inv;
    if (!spell()) {
	write("What?\n");
	return 1;
    }
    this_player()->set_magic_round();
    tp = this_player();
    if(tp->query_ghost()) {
	/*notify_fail("Your voice is hollow.\n"); */
	return 0;
    }
    if((string)tp->query_class() != "mage" ){
	notify_fail("You mumble in confusion.\n");
	return 0;
    }
    if(tp->query_level() < 10) {
	notify_fail("You are not sufficiently trained in the "
	  "magical arts to cast this spell.\n");
	return 0;
    }
    if (this_player()->query_disable())
	return notify_fail("You are busy.\n");
    if(environment(tp)->query_property("no magic")) {
	notify_fail("Something seems to be blocking your concentration.\n");
	return 0;
    }
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 50) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!str) {
	ob = (object)tp->query_current_attacker();
	if(!ob) {
	    notify_fail("Scorch what?\n");
	    return 0;
	}
    }
    else {
	ob = present(str, environment(tp));
	if(!ob) {
	    sscanf(str, "%s %d", what, which);
	    inv = all_inventory(environment(tp));
	    for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
		if(inv[i]->id(what)) {
		    skip++;
		    if(skip == which) ob = inv[i];
		}
	    }
	    if(!ob) {
		notify_fail("You do not see "+str+" here.\n");
		return 0;
	    }
	}
    }
    if(!living(ob)) {
	notify_fail(ob->query_cap_name()+" is not a living thing!\n");
	return 0;
    }
    if(ob==tp) {
	notify_fail("The gods laugh at you and take a picture for "
	  "blackmail.\n");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
	notify_fail("You cannot attack link-dead players.\n");
	return 0;
    }
    attack = (int)tp->query_skill("magic attack")*3/2 + (int)tp->query_stats("wisdom")*3/2;
    wisdom = (int)ob->query_stats("wisdom")/2 + (int)ob->query_skill("magic defense")/3;
    attack = (attack - wisdom);
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    write("You %^BOLD%^%^RED%^scorch %^RESET%^your enemy!");
    tell_room(environment(tp), "%^RED%^An increadible heat fills the "
      +"room as flame engulfs "
      +(string)ob->query_cap_name()+"!%^RESET%^", 
      ({ ob, tp }));
    tell_object(ob, "%^RED%^"+tp->query_cap_name()+
      " scorches you!%^RESET%^");
    tp->set_casting(attack + random(tp->query_level()/2));
    tp->add_skill_points("magic attack", attack/30 + 2);
    tp->add_mp(-attack/7);
    tp->set_disable();
    return 1;
}
void help() {
    write("Syntax: <scorch [(living)]>\n"
      "This spell sends a powerful burst of flame against the caster's "
      "enemy. It is only granted to pyromancers through their "
      "benefactor, %^RED%^Inferno%^RESET%^.\n");
}
int spell() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_level() < 10) return 0;
    if (o->query_class() != "mage") return 0;
    if (o->query_subclass() != "pyromancer" && o->query_subclass() != "wizard")  return 0;
    return 1;
}
