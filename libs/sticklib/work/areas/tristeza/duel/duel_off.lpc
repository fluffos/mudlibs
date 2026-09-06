/*********************************************************
 NAME:    duel_office.c

 PURPOSE: Arrange duels from this room.

 AUTHOR:  Tron
 *********************************************************/

#include <room.h>
#include "dueld.h"
#include <areas.h>

#include "../DEFS.h"

#define DUELD AREA_TRISTEZA "duel/dueld"
#define HELP_FILE AREA_TRISTEZA "duel/duel.help"

#define	DUEL_AREA	AREA_TRISTEZA "duel/virtual/world/rooms/"

#define START_ROOMS ({\
DUEL_AREA "100_0",\
DUEL_AREA "100_2",\
DUEL_AREA "100_4",\
DUEL_AREA "100_6",\
DUEL_AREA "100_8",\
DUEL_AREA "102_1",\
DUEL_AREA "102_3",\
DUEL_AREA "102_5",\
DUEL_AREA "102_7",\
DUEL_AREA "102_9",\
DUEL_AREA "104_0",\
DUEL_AREA "104_2",\
DUEL_AREA "104_4",\
DUEL_AREA "104_6",\
DUEL_AREA "104_8",\
DUEL_AREA "106_1",\
DUEL_AREA "106_3",\
DUEL_AREA "106_5",\
DUEL_AREA "106_7",\
DUEL_AREA "106_9",\
DUEL_AREA "108_0",\
DUEL_AREA "108_2",\
DUEL_AREA "108_4",\
DUEL_AREA "108_6",\
DUEL_AREA "108_8" })


#define START_ROOMS2 ({\
DUEL_AREA "200_0",\
DUEL_AREA "200_2",\
DUEL_AREA "200_4",\
DUEL_AREA "201_1",\
DUEL_AREA "201_3",\
DUEL_AREA "202_0",\
DUEL_AREA "202_2",\
DUEL_AREA "202_4",\
DUEL_AREA "203_1",\
DUEL_AREA "203_3",\
DUEL_AREA "204_0",\
DUEL_AREA "204_2",\
DUEL_AREA "204_4" })

#define START_ROOMS3 ({\
DUEL_AREA "300_0",\
DUEL_AREA "300_1",\
DUEL_AREA "300_2",\
DUEL_AREA "301_0",\
DUEL_AREA "301_1",\
DUEL_AREA "301_2",\
DUEL_AREA "302_0",\
DUEL_AREA "302_1",\
DUEL_AREA "302_2",\
})

#define START_ROOMS4 ({\
DUEL_AREA "400_0",\
DUEL_AREA "400_1",\
DUEL_AREA "401_0",\
DUEL_AREA "401_1",\
})

nomask private status arranged;
nomask private string dtype;
nomask private int    dtime;
nomask private int arena_size;
nomask private string *startrooms;

nomask private string *teams;
nomask private mixed  *players;


nomask void
create_room() {

    set(NO_PK);	// Added 04-mar-95 -+ Doomdark +-
    set_outdoors(WD_INDOORS);
    set_light_level(LT_LIGHTS);

    set_short("Dueling office");
    set_long("This is the hiring office of brave gladiators of our time. "+
      "The office is part of the huge arena and the arena can only "+
      "be entered from here. You won't be able to enter the arena "+
      "before the match is arranged in this very office. There is a "+
      "large stone board on the wall with the instructions. You"+
      " also notice somekind of a list nailed on the wall.");

    add_item(({"board", "instructions"}), "It's a large stone board "+
      "with writing on it. You could read it.");

    add_item("list", "It's top gladiator list, you could read it.");

    add_exit("south", CITY_DIR+"S4_1");

    arena_size = 1;
    startrooms = START_ROOMS4;
    dtime = 5;
}

nomask void
init_room() {

    add_action("arrange", "arrange");
    add_action("join", "join");
    add_action("time", "time");
    add_action("size", "size");
    add_action("start", "start");
    add_action("reset_me", "reset");
    add_action("view", "view");

}

nomask status
size(string s) {
    int siz;

    if(!s) {
	notify_fail("size <1-4>\n");
	return 0;
    }

    if(sscanf(s, "%d", siz)) {
	if((siz < 1) || (siz > 4)) {
	    notify_fail("Arena size is from 1 to 4.\n");
	    return 0;
	}
	arena_size = siz;
	switch(arena_size) {
	case 1: startrooms = START_ROOMS4;
	    break;
	case 2: startrooms = START_ROOMS3;
	    break;
	case 3: startrooms = START_ROOMS2;
	    break;
	case 4: startrooms = START_ROOMS;
	    break;
	}
	tell_room(this_object(), "Arena size is now "+siz+".\n");
	return 1;
    }
    else {
	notify_fail("Need number from 1 to 4 as argument.\n");
	return 0;
    }

    return 0;
}

nomask status
read_cmd(string s) {

    int i;

    if(!s) return 0;

    if(s == "board") {
	this_player()->more(HELP_FILE);
    }
    else if(s == "list") {
	DUELD->dueld_show_list();
    }
    else if(sscanf(s, "list %d", i)) {
	DUELD->dueld_show_list(i);
    }
    else return 0;


    return 1;
}

nomask status
arrange(string s) {

    if(!s) {
	notify_fail("Usage: arrange <dueltype>\n");
	return 0;
    }

    if(arranged) {
	notify_fail("The duel is arranged already.\n"+
	  "Use 'view' to view settings or do 'reset'.\n");
	return 0;
    }

    s = lower_case(s);
    if(s != "single" && s != "team" && s != "multi") {
	notify_fail("Choose duel type to single, team or multi.\n");
	return 0;
    }

    dtype = s;
    arranged = 1;

    tell_room(this_object(), "The duel type is set to: "+s+"\n");

    return 1;
}

nomask status
join(string s) {
    string team;
    string name;
    string Name;
    int i;

    if(!arranged) {
	notify_fail("Duel is not arranged yet.\n");
	return 0;
    }

    if(s) {
	if(dtype != "team") {
	    notify_fail("Duel type is not 'team'. Can't join to any team.\n");
	    return 0;
	} else team = lower_case(s);
    }
    else {
	if(dtype == "team") {
	    notify_fail("Duel type is 'team'. Team name required.\n");
	    return 0;
	}
    }

    if(!teams) teams = ({});
    if(!players) players = ({});

    name = (string)this_player()->query_real_name();
    Name = (string)this_player()->query_name();

    if(name == "guest") {
	notify_fail("Sorry, no guests allowed here.\n");
	return 0;
    }
    if((int)this_player()->query_level() < 5) {
	notify_fail("Sorry, you are still too young for this.\n");
	return 0;
    }


    if(!team) team = name;

    if(dtype != "team") {
	if(dtype == "single") {
	    if(sizeof(teams) > 1) {
		notify_fail("Sorry, duel type is single and gladiators have "+
		  "joined already.\n");
		return 0;
	    }
	}
	if(member(teams, team) != -1) {
	    notify_fail("You have already joined!\n");
	    return 0;
	}
	teams += ({team});
	players += ({this_player()});
	tell_room(this_object(), Name+" joined.\n");
    }
    else { //Type team.
	i = sizeof(players);
	if(i) 
	    while(i--) {
		if(member(players[i], this_player()->query_real_name()) != -1) {
		    notify_fail("You have already joined, sorry.\n");
		    return 0;
		}
	    }
	if((i = member(teams, team)) != -1) {
	    players[i] += ({this_player(), name});

	    tell_room(this_object(), Name+" joined team: "+team+".\n");
	}
	else {
	    teams += ({team});
	    players += ({ ({this_player(), name }) });

	    write("You join team "+team+".\n");
	    tell_room(this_object(), Name +
	      " created a new team called '"+team+"'.\n");
	}
    }

    return 1;
}


nomask status
time(string s) {
    int t;

    notify_fail("Usage: time <minutes>\n");
    if(!s) return 0;
    if(!sscanf(s, "%d", t)) return 0;
    if(t < 0) return 0;

    dtime = t;
    tell_room(this_object(), "Duel time is set to "+s+" minutes.\n");

    return 1;
}


nomask status
reset_me() {

    arranged = 0;
    players = 0;
    teams = 0;

    dtime = 5;
    dtype = 0;

    startrooms = START_ROOMS4;
    arena_size = 1;

    tell_room(this_object(), "Settings are cleared.\n");
    return 1;
}


nomask status
view() {
    int type;
    int i, j;
    string tmp;

    if(!arranged) {

	write("Duel has not been arranged.\n");
	return 1;
    }

    write("Duel type is:    "+capitalize(dtype)+"\n");
    write("Duel time is:    "+dtime+"\n");
    write("Duel Arena size: "+ arena_size +"\n");

    if(!teams || !(j = i = sizeof(teams))) {
	write("No teams or gladiators.\n");
	return 1;
    }

    tmp = "";
    write("Gladiators are:\n\n");
    while(i--) {
	if(dtype == "team") {
	    tmp = "Team "+teams[i]+": ";
	    j = sizeof(players[i]);
	    if(!j) tmp += "<No members>";
	    else {
		while(j--) {
		    if(stringp(players[i][j])) {
			tmp += capitalize(players[i][j]);
			tmp += " ";
		    }
		}

	    }
	    this_player()->tell_me(tmp);
	    tmp = 0;
	}
	else tmp += "Gladiator "+(j-i)+": "+capitalize(teams[i])+"\n";
    }
    if(tmp) write(tmp);


    return 1;
}


nomask status

start() {
    int type;
    string winner;

    if(DUELD->query_dueld_dueling()) {
	if(!(winner = (string)DUELD->query_dueld_winner()))
	{
	    write("Duel can't be started yet."+
	      " The Arena is reserved at the moment.\n");
	    return 1;
	}
	else DUELD->dueld_end(winner);
    }

    if(!arranged) {
	write("Duel is not arranged.\n");
	return 1;
    }
    if(!dtime) {
	write("Duel time is zero.\n");
	return 1;
    }
    if(!teams) {
	write("No teams or gladiators.\n");
	return 1;
    }

    switch(dtype) {
    case "single": type = DUELD_DUELTYPE_SINGLE;
	break;
    case "team":   type = DUELD_DUELTYPE_TEAM;
	break;
    case "multi":  type = DUELD_DUELTYPE_MULTI;
	break;
    }

    DUELD->set_dueld_startrooms(startrooms);
    DUELD->set_dueld_mode(type);
    DUELD->set_dueld_endroom(
      AREA_TRISTEZA "duel/generate_cool_off");
    DUELD->set_dueld_dueltime(dtime * 60);

    if(!DUELD->set_dueld_duelists(teams, players)) {
	write("Settings are not right, check them.\n");
	DUELD->dueld_rawreset();
	return 1;
    }
    else {
	DUELD->set_dueld_start();
	tell_room(this_object(), "The Gladiators started the duel.\n");
    }

    reset_me();

    return 1;
}
