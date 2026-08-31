// Druid spell -Slinker

#include <std.h>
inherit DAEMON;
int spell();

int cmd_vine whip(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i;
    string what;
    object *inv;

   if (!spell()) {
      write("Your magic skills are not what they used to be.");
      return 1;
   }
    this_player()->set_magic_round();
    tp = this_player();
    if(tp->query_ghost()) {
        /*notify_fail("Your voice is hollow.\n"); */
        return 0;
    }
       (string)tp->query_class() != "druid") {
	notify_fail("You mumble in confusion.\n");
	return 0;
     }
    if(tp->query_level() < 15) {
      notify_fail("You are not sufficiently trained in the "
		  "magical arts to cast this spell.\n");
      return 0;
    }
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
	    notify_fail("Whip who?\n");
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
	notify_fail("The gods laugh at you!\n");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
	notify_fail("You cannot attack link-dead players.\n");
	return 0;
    }
    attack = (int)tp->query_skill("magic attack");
    wisdom = (int)ob->query_stats("wisdom");
    attack = (attack + wisdom);
    if(attack < 1) attack = 1;
    if(!tp->kill_ob(ob, 0)) return 1;
    write("You summon up %^BOLD%^%^GREEN%^Vines%^RESET%^to whip "
          "your opponent.");
    tell_room(environment(tp), "+ chants magical words as vines whip "
              "out of the ground and hit there opponent"
	      +(string)ob->query_cap_name()+"!%^RESET%^", 
	      ({ ob, tp }));
    tell_object(ob, "+tp->query_cap_name()+
		" whips you with magical %^BOLD%^%^GREEN%^Vines!");
    tp->set_casting(attack + random(50));
    tp->add_skill_points("magic attack", attack/30 + 2);
    tp->add_mp(-random(this_player()->query_level() + 65));
    return 1;
}

void help() {
    write("Syntax: <scorch [(living)]>\n"
        "This spell summons up powerful %^BOLD%^%^GREEN%^vines%^RESET%^ "
        "from the ground and whips your opponent");
}

int spell() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_level() < 15) return 0;
   if (o->query_class() != "druid") return 0;
   return 1;
}
