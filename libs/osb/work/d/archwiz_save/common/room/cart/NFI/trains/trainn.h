
/*
 *	A C.A.R.T. underground train.
 *	standard C.A.R.T. train include file
 */

#define MOVE_PLAYER(str1, str2) call_other(this_player(), \
  "move_player", str1+"#"+str2); \
  return 1

string stationnames;
int numstations;

int doors_open;
int stationnr, maxstation;
int state;
string station, name, alias;

reset(arg)
	{
	if (arg)
		return;
	set_light(1);
	doors_open = 0;
	stationnr = 1;
	buildnames();
	maxstation = numstations*2-2;
	state = 1;
	name = COLOR+" "+ALIAS; alias = ALIAS;
	call_out("arrive", 1);
	}

id(str) {
	return (str == name || str == alias || str == "sign" || str == "graffiti");
	}

short() {
	return name;
	}

long(str) {
	if (str == "sign" || str == "graffiti") 
		return read(str);
	if (present(this_player(),this_object()))
		{
		write("You are inside a "+COLOR+" C.A.R.T. train.\n");
		write("There is a sign and some graffiti on the walls.\n");
		if (doors_open)
			write("The sliding doors are open.\n");
		else
			write("The sliding doors are closed.\n");
		}
	else
		{
		write("This is a C.A.R.T. train of the "+COLOR+" line.\n");
		if (doors_open)
			write("The sliding doors are open.\n");
		else
			write("The sliding doors are closed.\n");
		write("A lighted sign reads: "+get_direction(stationnr)+".\n");
		}
	}

read(str) {
	if (str == "sign") {
		if (present(this_player(),this_object())) {
			write(get_stationlist());
			return 1;
			}
		return 0;
		}
	if (str == "graffiti") {
		if (present(this_player(),this_object())) {
			write("Colorful pseudonyms - You can read 'Star Frontiers', 'ECA', 'HQC', '1103'.\n");
			return 1;
			}
		return 0;
		}
	return 0;
	}

query_value() { return 10000; }

get() {
	return 0;
	}

init() {
	add_action("train_enter"); add_verb("enter");
	add_action("train_exit"); add_verb("exit");
	add_action("train_exit"); add_verb("leave");
	add_action("read"); add_verb("read");
	}

train_enter(str) {
	if (!id(str))
		return 0;
	if (present(this_object(), environment(this_player())))
		{
		if (!doors_open) {
			write("The doors are closed!\n");
			return 1;
			}
		write("You enter the "+COLOR+" train.\n");
		MOVE_PLAYER("into "+COLOR+" train", "room/trains/"+COLOR+"_train");
		/*
		move_object(this_player(), this_object());
		*/
		return 1;
		}
	else
		{
		write("You are already in it!\n");
		}
	return 1;
	}

train_exit() {
	if (present(this_player(), this_object()))
		{
		if (!doors_open) {
			write("The doors are closed!\n");
			return 1;
			}
		write("You leave the train.\n");
		MOVE_PLAYER("out", get_stationname(stationnr));
		return 1;
		}
	return 0;
	}

depart() {
	station = get_stationname(stationnr);
	tell_room(environment(this_object()), 
		"From somewhere you here a blowing whistle.\n"+
		"The "+COLOR+" train accelerates fast and leaves the station.\n");
	tell_room(this_object(), 
		"From somewhere you here a blowing whistle.\n"+
		call_other(station, "look_depart"));
	move_object(this_object(), "room/trains/travelling");
	stationnr = stationnr + 1;
	if (stationnr > maxstation) stationnr = 1;
	call_out("arrive", 6);
	}

arrive() {
	station = get_stationname(stationnr);
	move_object(this_object(), station);
	tell_room(environment(this_object()), 
		"With a squeaky sound a "+COLOR+" C.A.R.T. train comes to a stop.\n"+
		"A lighted sign reads: "+get_direction(stationnr)+".\n");
	tell_room(this_object(), call_other(station, "look_arrive"));
	call_out("opendoors", 1);
	}

opendoors() {
	doors_open = 1;
	tell_room(environment(this_object()), "With a hissing sound the doors of the "+name+" slide open.\n");
	tell_room(this_object(), "With a hissing sound the doors slide open.\n");
	call_out("closedoors", 6);
	}

closedoors() {
	doors_open = 0;
	tell_room(environment(this_object()), "With a THUD the doors of the "+name+" slide shut.\n");
	tell_room(this_object(), "With a THUD the doors slide shut.\n");
	call_out("depart", 1);
	}


get_stationname(nr) {
	if (nr > numstations)
		return(stationnames[numstations*2-nr-1]);
	else
		return(stationnames[nr-1]);
	}

