//	/bin/user/_follow.c
//	from the Nightmare mudlib
//	allows players to follow one another
//	created by Descartes of Borg 15 february 1993

#include <std.h>

inherit DAEMON;

int cmd_follow(string str) {
    object ob;
    string who;

    if(!str) {
	notify_fail("Correct syntax: <follow allow [who]> or <follow [who]>\n");
	return 0;
    }
    if(sscanf(str, "allow %s", who) == 1) {
	if(!find_player(who)) {
	    notify_fail("No "+capitalize(who)+" in our reality.\n");
	    return 0;
   	}
	write("You invite "+capitalize(who)+" to follow you.\n");
	this_player()->follow_allow(lower_case(who));
	tell_object(find_player(who), "You have been invited to follow "+
	    this_player()->query_cap_name()+".\n");
	return 1;
    }
    ob = present(lower_case(str), environment(this_player()));
    if(!ob) {
	notify_fail("No one by that name around here.\n");
	return 0;
    }
    if(ob == this_player()) {
	notify_fail("You cannot follow yourself!\n");
	return 0;
    }
    if(!ob->can_follow((string)this_player()->query_name())) {
	notify_fail("You cannot follow "+capitalize(str)+"!\n");
	return 0;
    }
    if(!ob->add_follower(this_player())) {
	notify_fail("You cannot follow someone who is following you!\n");
	return 0;
    }
    write("You are now following "+capitalize(str)+".\n");
    tell_object(ob, this_player()->query_cap_name()+" is now following you.\n");
    return 1;
}

void help() {
    write("Syntax: <follow [name]>\n\
        <follow allow [name]>\n\n\
<follow allow> allows the player named to follow you.\n\
<follow> allows you to follow a player who has allowed you.\n"
"See also: party, kill\n"
);
}
