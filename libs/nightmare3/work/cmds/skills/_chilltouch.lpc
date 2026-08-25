//	chill touch
//	Kataan ability
//	partially cloned from _freeze.c by Bohemund
//	94-Nov-06 Aleas

#include <std.h>

inherit DAEMON;

int cmd_chilltouch(string str) {
    object tp, ob;
    int faith, wisdom, i, level;
    string what, *strengths, *weaknesses;
    object *inv;

    tp = this_player();
    tp->set_magic_round();
    if(tp->query_casting()) return 1;
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if((string)tp->query_class() != "kataan") {
	message("my_action","No demon will ever support you!" ,tp);
	message("other_action",tp->query_cap_name()+" mumbles in confusion.", 
		environment(tp),tp);
	return 1;
    }
    if(environment(tp)->query_property("no magic")) {
	notify_fail("The demons don't hear you.\n");
	return 0;
    }
    if((int)tp->query_mp() < 35) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!str) {
  	ob = (object)tp->query_current_attacker();
	if(!ob) {
	    notify_fail("Strike what?\n");
	    return 0;
	}
    } else {
	ob = present(str, environment(tp));
        if(!ob) ob = parse_objects(environment(tp), str);
        if(!ob) {
		notify_fail("No "+str+" here!\n");
		return 0;
	}
    }
    if(!living(ob)) {
	notify_fail(ob->query_cap_name()+" is not alive!\n");
	return 0;
    }
    if(ob == tp) {
	notify_fail("Not a very clever thing to do.\n");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
	notify_fail("You cannot attack link-dead players.\n");
	return 0;
    }
    if((string)ob->query_class() == "kataan") {
        notify_fail(sprintf("%s laughs at you!\n", 
          ob->query_cap_name()));
        return 0;
    }
    if(!ob->kill_ob(tp, 0)) return 1;
    faith = (int)tp->query_skill("faith");
    wisdom = (int)ob->query_stats("wisdom")/2;
    faith -= wisdom;
    weaknesses = (string *)ob->query_property("weakness");
    if (!pointerp(weaknesses)) weaknesses = ({});
    strengths = (string *)ob->query_property("strengths");
    if (!pointerp(strengths)) strengths = ({});
    if(member_array("cold", weaknesses) != -1)
	faith += random( faith );
    else if(member_array("cold", strengths) != -1)
	    faith -= random(wisdom+5);
    if(member_array("magic", weaknesses) != -1)
	faith += random( (faith/2) + 2 );
    else if(member_array("magic", strengths) != -1)
	    faith -= random(wisdom + 10);
    if(faith < 1) faith = 1;
    message("my_action","%^RESET%^%^BLACK%^%^BOLD%^You strike "+
	    ob->query_cap_name()+ " with horror!",tp);
    message("other_action","%^RESET%^%^BLACK%^%^BOLD%^"+
	    tp->query_cap_name()+ " mutters some demonical words.",
	    environment(tp), ({ ob, tp }));
    message("other_action","%^RESET%^%^BLACK%^%^BOLD%^"+
	    "A chill of horror strikes you as "+
	    tp->query_cap_name()+ " mutters some demonical words!",ob);
    tp->set_casting( ((faith + faith)/40 ) * 15 );
    tp->add_skill_points( faith * 3 );
    tp->add_mp(-(35 + random(35)) );
    return 1;
}

void help() {
    message("help","Syntax: <chilltouch [(living)]>\n\n"
	"Uses your faith in the demons of the underworld to cause a "
	"chill of horror to strike the living object named, or, "
	"if in battle and no arguments are used, "
	"your current opponent.",this_player());
}
