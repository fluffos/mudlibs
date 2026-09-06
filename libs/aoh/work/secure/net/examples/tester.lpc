virtual inherit "std/thing/description";
virtual inherit "std/thing/moving";
virtual inherit "std/base";

#include <moving.h>
#include <thing_p.h>

#define ME this_object()

void create() {
  base::create();
  description::create();
}

/*int query_prevent_shadow() { return 1; }*/

void init()
{
	add_action("do_ping","ping");
}
do_ping(mudname) {
    if (INETD->send_udp(mudname, ([
	REQUEST: "ping"
    ]), 1))
	write("Message transmitted.\n");
    return 1;
}


/*
tell(str) {
    string who, msg;
    if (ghost)
	write("You fail.\n");
    else if (spell_points < 0)
	write("You are low on power.\n");
    else if (!str || sscanf(str, "%s %s", who, msg) != 2)
	write("Tell what ?\n");
    else {


	object ob;
	int i;
	string mudname, user;
	if (sscanf(who, "%s@%s", user, mudname) == 2) {
	    if (INETD->send_udp(mudname, ([
		REQUEST: "tell",
		RECIPIENT: user,
		SENDER: name,
		DATA: msg
	    ]), 1))
		write("Message transmitted.\n");
	    return 1;


	}
	if (!(ob = find_player(lower_case(who))) || !interactive(ob) ||
	ob->query_invis() > 1 && level < DEMIGOD) {
	    write("No player with that name.\n");
	    return 1;
	} else {
	    string from;
	    if (ob->query_level() < GOD) {
		from = cap_name;
		if (level < DEMIGOD)
		    spell_points -= 5;
	    }
	    else
		from = capitalize(name);
	    tell_object(ob, "\n");
	    tell_object(ob, wrap(from + " tells you: " + msg, 1) + "\n");
	}
	write(echoback ? wrap("You tell " + capitalize(who) + ": " +
	msg, 1) + "\n" : "Ok.\n");
    }
    return 1;
}

*/
