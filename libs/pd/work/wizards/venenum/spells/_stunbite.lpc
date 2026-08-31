// Based off Paralyze, created by Venenum.

#include <std.h>
inherit DAEMON;
int spell();
int cmd_stunbite(string str) {
    object ob;
    int death, illusion, dam, def, time;
    if (!spell()) {
	return notify_fail("Huh?\n");
    }
    if(environment(this_player())->query_property("no magic") &&
      !wizardp(this_player())) {
	notify_fail("This place is devoid of magic.\n");
	return 0;
    }
    if(!str) ob = (object)this_player()->query_current_attacker();
    else ob = present(lower_case(str), environment(this_player()));
    if(!ob && str) ob = parse_objects(environment(this_player()), lower_case(str));
    if(!ob) {
	notify_fail("Stunbite who...?\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail("It's not going anywhere. Trust me.\n");
	return 0;
    }
    if(this_player()->query_ghost()) {
	notify_fail("Oro?\n");
	return 0;
    }
    if(ob->query_race() == "vampire" || ob->query_race() == "lich") {
	notify_fail("The undead are immune to your poison, as are you.\n");
	return 0;
    }
    if(!this_player()->ok_to_kill(ob)) {
	notify_fail("You may not prey upon them.\n");
	return 0;
    }
    if (this_player()->query_disable())
	return notify_fail("You are busy.\n");
    if(this_player()->query_casting()) {
	notify_fail("One thing at a time.\n");
	return 0;
    }
    dam = (int)this_player()->query_skill("illusion") + (int)this_player()->query_stats("charisma") - (int)ob->query_stats("charisma")-1;

    if (dam < 10) def = 2; else
    if (dam < 55) def = 3; else
    if (dam < 110) def = 4; else
    if (dam < 165) def = 5; else
    if (dam < 220) def = 6; else
    if (dam >= 220) def = 7;
    time = 3+random(def);
    if (def = 0) {
	write("You are not frightening enough to them.");
	return 1;
    }
    if((int)this_player()->query_mp() < 130) {
	notify_fail("Not enough magical power resides inside you.\n");
	return 0;
    }
    if(ob->query_paralyzed()) {
	write("Your magic misfires upon you and the poison flows back into your body!");
	this_player()->set_paralyzed(time*2);
	return 1; 
    }
    this_player()->add_mp(-(95+(random(50))));
    this_player()->set_disable();
    if(random(time)>2) {
	ob->set_paralyzed(time);
	this_player()->add_skill_points("illusion", dam/25);
	write("You rear up and sink your fangs into "+ob->query_cap_name()+"'s face.\n");
	say(this_player()->query_cap_name()+" rears up and sinks "+this_player()->query_possessive()+" fangs into "+ob->query_cap_name()+"'s face.\n", ob);
	tell_object(ob, this_player()->query_cap_name()+" sinks "+this_player()->query_possessive()+" fangs into your face!\n");
    }
    else {
	write("You cannot seem to find an opening.");
    }
    return 1;
}
void help() {
    write("Syntax: <stunbite [enemy]>\n\n"
      "Injects the target with a special, paralytic poison a Vampire possesses.\n"
    );
}
int spell() {
    object j;
    j = this_player();
    if
    (!j) return 0;
    if (j->is_monster()) return 1;
    if (wizardp(this_player())) return 1;
    if (j->query_subclass() != "vampire") return 0;
    if (j->query_level() < 10) return 0;
    if (j->query_skill("illusion") < 60) return 0;
    return 1;
}

