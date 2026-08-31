//        /bin/user/_summon.c
//      from the Nightmare/Carnage mudlib
//      a kataan spell for summoning demons
//      a dungeonware.net collaberation with
//      -(Inferno)-
#include <std.h>
int spell();
inherit DAEMON;
string type() { return "faith"; }
int cmd_summon(string str) {
    string list;
    object tp, ob, mon;
    int con, wis, sum;
    if (!spell()) {
	notify_fail("What?\n");
	return 0;
    }
    if(!str) {
	notify_fail("Syntax: summon <demon>\n");
	return 0;
    }
    if (this_player()->query_arena()==1)
	return notify_fail("The gods frown upon this in the arena.\n");
    if(this_player()->query_ghost()) return 0;
    tp = this_player();
    lower_case(str);
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("Something prevents you from using your powers.\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 45) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    con = (int)this_player()->query_skill("summoning");
    if(con < 40) {
	notify_fail("Your summoning is too weak to control a demon.\n");
	return 0;
    }
    if(this_player()->query_current_attacker()) return notify_fail("Your mind is too busy with other matters.\n");
    if (present("abyss demon", environment(this_player())))
	return notify_fail("Your mind cannot control more than one demon at a time.\n");
    wis = (int)this_player()->query_stats("wisdom");
    // -----------------------------------------------------------------
    //                     Demons below this line
    // -----------------------------------------------------------------
    if (str == "list") {
	list = "%^RESET%^%^BOLD%^  Known Demons\n%^BLUE%^+=+=+=+=+=+=+=+=%^RESET%^\n";
	if(con >= 40)
	    list += "  Nightmare\n";
	if(con >= 50)
	    list += "  Imp\n";
	if(con >= 60)
	    list += "  Messenger\n";
	if(con >= 70)
	    list += "  Carrier\n";
	if(con >= 80)
	    list += "  Assassin\n";
	write(list);
	return 1;
    } else
    if (str == "nightmare" && tp->query_mp() >= 35 && con >= 40) {
	sum = 35;
	if (random(sum) > random(con)) {
	    write("Your call was either not heard or ignored.\n");
	    return 1;
	}
	if (find_living(str+" "+this_player()->query_name()))
	    return notify_fail("Your mind cannot control more than one "+str+" at a time.\n");
	mon = new("/d/nopk/standard/abyss/mob/"+str);
	mon->set_name(str+" "+this_player()->query_name());
	mon->move(environment(tp));
    } else
    if (str == "imp" && tp->query_mp() >= 50 && con >= 50) {
	sum = 50;
	if (random(sum) > random(con)) {
	    write("Your call was either not heard or ignored.\n");
	    return 1;
	}
	if (find_living(str+" "+this_player()->query_name()))
	    return notify_fail("Your mind cannot control more than one "+str+" at a time.\n");
	mon = new("/d/nopk/standard/abyss/mob/"+str);
	mon->set_name(str+" "+this_player()->query_name());
	mon->move(environment(tp));
    } else
    if (str == "messenger" && tp->query_mp() >= 60 && con >= 60) {
	sum = 60;
	if (random(sum) > random(con)) {
	    write("Your call was either not heard or ignored.\n");
	    return 1;
	}
	if (find_living(str+" "+this_player()->query_name()))
	    return notify_fail("Your mind cannot control more than one "+str+" at a time.\n");
	mon = new("/d/nopk/standard/abyss/mob/"+str);
	mon->set_name(str+" "+this_player()->query_name());
	mon->move(environment(tp));
    } else
    if (str == "carrier" && tp->query_mp() >= 60 && con >= 70) {
	sum = 60;
	if (random(sum) > random(con)) {
	    write("Your call was either not heard or ignored.\n");
	    return 1;
	}
	if (find_living(str+" "+this_player()->query_name()))
	    return notify_fail("Your mind cannot control more than one "+str+" at a time.\n");
	mon = new("/d/nopk/standard/abyss/mob/"+str);
	mon->set_name(str+" "+this_player()->query_name());
	mon->move(environment(tp));
    } else
    if (str == "assassin" && tp->query_mp() >= 90 && con >= 80) {
	sum = 90;
	if (random(sum) > random(con)) {
	    write("Your call was either not heard or ignored.\n");
	    return 1;
	}
	if (find_living(str+" "+this_player()->query_name()))
	    return notify_fail("Your mind cannot control more than one "+str+" at a time.\n");
	mon = new("/d/nopk/standard/abyss/mob/"+str);
	mon->set_name(str+" "+this_player()->query_name());
	mon->move(environment(tp));
    }  else
    {
	write("Syntax: <summon [demon_name]>\n");
	return 1;
    }
    // ---------------------------------------------------------------
    //                    Demons above this line
    // ---------------------------------------------------------------
//    ob = present(str, environment(tp));
    ob = mon;
    write("You summon forth a demon from the abyss!");
    say(this_player()->query_cap_name()+" summons forth a demon from the abyss!", ob);
    ob->set_owner(tp);
    ob->set_property("no monster", 1);
    ob->set_id( (ob->query_id() || ({})) - ({ "monster" }) + ({ "demon" }) );
    this_player()->add_mp(-sum);
    this_player()->add_skill_points("faith", random(sum));
    return 1;
}
void help() {
    write("Syntax: <summon [demon_name]>\n\n");
    write("This spell allows the a kataan to summon a demon from "
      "the Abyss. The name of the demon to be summoned must "
      "be known. If the mage is strong enough, the conjured "
      "demon will be under the complete control of the caster. "
      "<command [demon] to reveal powers> will tell you what "
      "available powers the summoned demon has. (eg. <command "
      "imp to reveal powers>). If you wish to summon a Demon "
      "Lord, you must know it's specific name.<summon list> can be used "
      "to see what demons may be summoned.");
}
int spell() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() != "kataan") return 0;
    if (o->query_skill("summoning") < 40) return 0;
    if (o->query_level() < 8) return 0;
    return 1;
}

