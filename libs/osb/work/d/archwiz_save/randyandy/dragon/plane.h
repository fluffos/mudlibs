
/*
 *  This is the standard include file of the
 *  Nightfall Flightdragon Airways (C) Randyandy@Nightfall 1992
 */
 
/* The definitions are included from planevar.h  


Take a look at a dragon.c file for correct including!
I'm sorry but I had to split the .h file because you have to define the 
functions you wish to call in create() BEFORE defining create().
Here: get_stationlist() and buildnames().
*/

doors() {
	if(doors_open)
	    return "The doors are open.\n";
	else 
	    return "The doors are closed.\n";
}
no_kill() {
	write("An officer says: Sorry, no fights allowed here!\n");
	return 1;
}

window() {
	string view;
	view="You take a look out of the window:\n";
	view+=environment(this_object())->QueryIntLong();
	return view;
}

void create() {
	string long, intlong;
        "restrictions"::create();
	room::create();
	name = COLOR+" "+ALIAS; alias = ALIAS;
	SetIntShort("Inside the "+name);
	SetIntLong(
"You are inside a gondola which is carried by a "+name+". The animal doesn't "+
"look horrible from the inside, it must be quite friendly. However you notice "+
"a small poster next to your seat. There's also a window next to you. "+
"You can 'leave' if the dragon is on the ground.\n");
        this_object()->SetShort(name);
        this_object()->SetLong("This is a "+name+" of the Nightfall Flightdragon Airways.\n"+
                "It carries a gondola which you can enter.\n");
        SetIndoors(1);
        SetWeight(1000000);
        AddDetail("gondola", "The gondola is carries safely by the dragon.\n");
        signtext="Welcome on board of the "+COLOR+" flying dragon.\n"+
                 get_stationlist()+"\nWe wish you a good flight!\n"+
                 "The team from the Nightfall Flightdragon Airways Incorp.\n";
        AddDetail("poster",signtext);
        AddRoomCmd("enter", "plane_enter");
        AddRoomCmd("exit", "plane_exit");
        AddRoomCmd("leave", "plane_exit"); 
        AddRoomCmd("kill",  "no_kill");
        AddRoomCmd("read", "read");
        AddRoomCmd("open", "open");
        AddDetail("doors", #'doors); 
        AddDetail("window", #'window);
        Set(P_TRANSPARENT,0);
        doors_open = 0;
        stationnr = 1;
        buildnames();
        maxstation = numstations*2-2;
        state = 1;
        call_out("arrive", 1);
}

read(str) {
  if ((str!="sign") && (str!="poster")) return 0;
	write(signtext);
	return 1;
}

id(string str) { return str == "dragon"; }

open(str) {
        if(!(str=="door" || str=="doors")) {
              return 0;
	}
        if(doors_open)
            return "The doors are open.\n";
        else
            return "You can't open the doors.\n";
}

get() {
	return 0;
	}

plane_enter(str) {
	if ((str!=ALIAS) && (str!="gondola"))
		return 0;
	if (present(this_object(), environment(this_player())))
		{
		if (!doors_open) {
			write("The doors are closed!\n");
			return 1;
			}
		if(QuerySomeonesValue(this_player())<PRIZE) {
			write("The stewardess holds you back.\nShe tells you: You don't have enough money. \nThe flight costs "+PRIZE+" copper coins.\n");
			return 1;
		}
		PayValue(this_player(),PRIZE);
		log_file("randyandy/dragonflight", ctime(time())+" "+this_player()->QueryName()+" enters the "+COLOR+" dragon.\n");
		write("The stewardess takes "+PRIZE+" copper coins from you.\n");
		write("Then you enter the gondola of the "+COLOR+" dragon.\n");
		MOVE_PLAYER("into the gondola of the "+COLOR+" dragon", "/d/archwiz/randyandy/dragon/"+COLOR+"_dragon");
		return 1;
		}
	else
		{
		write("You are already in it!\n");
		}
	return 1;
	}

plane_exit() {
	if (present(this_player(), this_object()))
		{
		if (!doors_open) {
			write("The doors are closed!\n");
			return 1;
			}
		write("You leave the dragon.\n");
		MOVE_PLAYER("out", get_stationname(stationnr));
		return 1;
		}
	return 0;
	}

depart() {
	object air;
	station = get_stationname(stationnr);
	tell_room(environment(this_object()), 
		"An officer shows a sign to the dragon.\n"+
		"The "+COLOR+" dragon takes a last look and then lifts up into the air.\n");
	tell_room(this_object(), 
		"A sign lights up: Fasten your seat-belts!\n"+
		call_other(station, "look_depart"));
        air = "/d/archwiz/randyandy/dragon/travelling";
	move_object(this_object(),air);
	stationnr = stationnr + 1;
	if (stationnr > maxstation) stationnr = 1;
	call_out("arrive", SPEED);
	}

arrive() {
	station = get_stationname(stationnr);
	move_object(this_object(),station);
	tell_room(environment(this_object()), 
		"With a roaring sound a "+COLOR+" dragon flies in and lands.\n"+
		"A lighted sign reads: "+get_direction(stationnr)+".\n");
	tell_room(this_object(), call_other(station, "look_arrive"));
	call_out("opendoors", 1);
	}

opendoors() {
	doors_open = 1;
	tell_room(environment(this_object()), "A stewardess opens the door of the "+name+"'s gondola.\n");
	tell_room(this_object(), "A stewardess opens the door.\n");
	call_out("closedoors", 15);
	}

closedoors() {
	doors_open = 0;
	tell_room(environment(this_object()), "A stewardess closes the door of the "+name+"'s gondola .\n");
	tell_room(this_object(), "A stewardess closes the door.\n");
	call_out("depart", 1);
	}


get_stationname(nr) {
	if (nr > numstations)
		return(stationnames[numstations*2-nr-1]);
	else
		return(stationnames[nr-1]);
	}

