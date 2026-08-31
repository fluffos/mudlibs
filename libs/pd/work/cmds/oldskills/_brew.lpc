//      /bin/user/_brew.c
//      ranger ability to create tea
//      created by Nightshade 11-10-01

#include <std.h>

inherit DAEMON;

int abil();

int cmd_brew(string str) {
    object ob;

    if (this_player()->query_subclass() != "ranger") {
	write("What?\n");
	return 1;
    }
    if(!str) {
	notify_fail("Brew what?\n");
	return 0;
    }
    if(this_player()->query_disable()) {
	write("You are too busy doing something else!");
	return 1;
    }
    if(!present("brewpot",this_player())) {
	notify_fail("You do not have anything to brew in!\n");
	return 0;
    }
    if(!present("campfire",environment(this_player()))) {
	notify_fail("You have no way to cook it!\n");
	return 0;
    }
    if(!present(str,this_player())) {
	notify_fail("You do not have that!\n");
	return 0;
    }
    if(str[0..3] != "herb")
        return notify_fail("You cannot brew tea from that!\n");
    write("You sit down and brew yourself some tea.");
    say(this_player()->query_cap_name()+" sits down and begins brewing
something.");
    ob = new("/d/nopk/standard/obj/misc/forage/tea");
    ob->set_type(present(str,this_player())->query_type());
    if(this_player()->query_skill("nature") > 40) {
        ob->set_short("A tea of "+present(str,this_player())->query_type());
        ob->set_long("Some warm tea with
"+present(str,this_player())->query_type()+" properties.");
    }
    else {
        ob->set_short("An unknown tea.");
        ob->set_long("This tea looks good, but who knows what it does.");
    }
    ob->move(this_player());
    present(str,this_player())->remove();
    return 1;
}

void help() {
    write("Syntax: <brew [herb]>\n\n"
      "Rangers can use herbs that they have foraged for to\n"
      "brew potent teas with different effects.\n"
    );
}

int abil() {
    if(this_player()->query_subclass() != "ranger") return 0;
    if(this_player()->query_skill("nature") < 80) return 0;
    return 1;
}

