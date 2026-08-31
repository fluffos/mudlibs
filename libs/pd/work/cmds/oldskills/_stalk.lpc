//	stormy
#include <std.h>
inherit DAEMON;
int abil();
int cmd_stalk(string str) {
    object ob, tp;
    int stealth, resist;
    if (!abil()) {
	write("What?\n");
	return 1;
    }
    if(!str) {
	notify_fail("Correct syntax: <stalk [who]>\n");
	return 0;
    }
    tp = this_player();
    ob = present(lower_case(str), environment(this_player()));
    if(!ob) {
	notify_fail("No one by that name around here.\n");
	return 0;
    }
    if(ob == tp) {
	notify_fail("You cannot stalk yourself!\n");
	return 0;
    }
    stealth = (int)tp->query_skill("stealth");
    resist = (int)ob->query_stats("dexterity")-random(5);
    stealth -= resist;
    if(stealth <5) {
	write("You utterly fail in your attempt to stalk "+ob->query_cap_name()+".");
	tell_object(ob, "You catch "+tp->query_cap_name()+" trying to follow you!");
	tell_room(environment(tp), "You notice "+tp->query_cap_name()+" trying to follow "+ob->query_cap_name()+"!", ({ ob, tp }));
	return 1;
    }
    ob->add_follower(tp);
    write("You are now stalking "+capitalize(str)+".");
    tp->add_skill_points("stealth", stealth/2);
    return 1;
}
int abil() {
    object o;
    o = this_player();
    if (!o) return 0;
    if (o->query_subclass() != "assassin") return 0;
    if (o->query_level() < 5) return 0;
    if (o->query_skill("stealth") < 14) return 0;
    return 1;
}
void help() {
    write("Syntax: <stalk [name]>\n\
 Allows an assassin to stalk a player in secret.\n" );
}
