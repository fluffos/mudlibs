//Aziraphale

#include <std.h>
inherit ROOM;

string *players;

void create() {
    room::create();
    set_properties(([ "light" : 2, "indoors" : 1]));
    set_short("Sign Up For The Hunt!");
    set_long("%^BOLD%^WHITE%^We Want You To Join In!\n%^RESET%^This "
      "is the sign up centre for the various special events.  Scattered "
      "about the room are several desks, each with a roll of parchment, "
      "ink bottle, and quill.  When an event is scheduled, all kinds "
      "of adventurers come to %^CYAN%^<sign up>%^RESET%^ for it.");
    set_exits(([
	"east" : "/d/tirun/nwganthus2",
      ]));
    restore_object("/d/events/hunt/signup");
}

void init() {
    ::init();
    add_action("jarmony", "sign");
    add_action("chufrue", "playerlist");
    add_action("removin", "clear");
}


int jarmony(string str) {
    int ok, i;
    ok = 1;

    if(!players) players = ({});

    if (str == "up") {
	for (i=0; i < sizeof(players); i++) {
	    if (players[i] == this_player()->query_name())
		ok = 0;
	}
	if (ok == 1) {
	    players += ({ this_player()->query_name() });
	    write("\nYou have succesfully signed up for the Treasure Hunt.");
	    save_object("/d/events/hunt/signup");
	    return 1;
	}
	else {
	    write("\nYou have already signed up for this event.");
	    return 1;
	}
    }
    write("You need to %^CYAN%^<sign up> %^RESET%^for the hunt.");
    return 1;
}

int chufrue() {
    string writing;
    int i;
    if (!wizardp(this_player()))
	return 0;
    writing = ("\n%^YELLOW%^Players signed up:%^RESET%^\n");
    for (i=0; i < sizeof(players); i++) {
	writing += capitalize((string)players[i])+"\n";
    }
    write(writing);
    return 1;
}

int removin(string str) {
    if (!wizardp(this_player()))
	return 0;
    if (str == "list") {
	players = ({});
	save_object("/d/events/hunt/signup");
	write("\nYou have reset the player's list of the Treasure Hunt.\n\n "
	  "Players will need to sign up again for the next hunt.");
	return 1;
    }
    write("\nYou must %^CYAN%^<clear list> %^RESET%^*if* you are sure.");
    return 1;
}
