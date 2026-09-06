inherit "std/room";
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "path.h"

#define DOWNROOM (WHITEHOUSE("cellar"))

// special variables for this room 
int rug_rolled;
int trap_open;
int sword;

QueryIntLong()
{
	return (
"You are in the living room. There is a doorway to the north and "
"a wooden door with strange gothic lettering to the west.\n"+
	describe_floor()+(sword ? "On hooks above the mantlepiece hangs an elvish sword of great antiquity.\n" : ""));
}

//
// several special descriptions.
//
describe_sword() {
	return (sword ? "It is long and sharp.\n" : 0);
}
describe_floor() {
	if (rug_rolled) {
		if (trap_open)
			return("An open trap door is at your feet.\n");
		else
			return("A closed trap door is at your feet.\n");
	}
	else
		return("A large oriental rug lies in the center of the room.\n");
}
describe_rug() {
  	return ("It's very heavy, but it appears not to be attached to the floor.\n");
}
describe_trap() {
	if (!rug_rolled)
		return 0;
  	if (trap_open)
		return("The heavy trap door is open.\n");
	else
		return("The heavy trap door is closed.\n");
}


//
// main creation.
//
create(arg)
{
	::create(arg);
	SetIntShort("Living Room");

	AddDetail("mantlepiece","I don't know what it is used for.\n");
	AddDetail("lettering","You can make out some letters:\n"+
"WI H N TH SE  AL S  IV S TH  ON  EY D\n");
	AddDetail("sword",#'describe_sword);
	AddDetail("floor",#'describe_floor);
	AddDetail("rug",#'describe_rug);
	AddDetail("lock","In fact, the keyhole looks like the mouth of a skull.\n");
	AddDetail(({"trap","trap door","trapdoor"}),#'describe_trap);

	AddExit("north","./whkitchen");
	AddDoor("west","./cyclops_room","wooden door",
		"There is some gothic lettering on the door.\n",
		"cyclops key",DOOR_STATUS_LOCKED);

	AddRoomCmd("roll","roll_rug");
	AddRoomCmd("unroll","roll_rug");
	AddRoomCmd("move","vain");
	AddRoomCmd("pull","vain");
	AddRoomCmd("push","vain");
	AddRoomCmd("get","vainget");
	AddRoomCmd("take","vainget");
	AddRoomCmd("down","move_down");
	AddRoomCmd("open","cmd_open");
	AddRoomCmd("close","cmd_close");

	AddItem(OBJ("lamp"),REFRESH_REMOVE);
	// BEGONE AddItem("/obj/magazine",REFRESH_REMOVE);
/*
	AddItem(OBJ("instawiz"),REFRESH_REMOVE);
*/
	reset();
}

//
// Trapdoor Manipulation open/close.
//
int cmd_open(string str)
{
	if (!str || -1 == member(({"trap","trap door","trapdoor"}), str))
		return 0;
	if (!rug_rolled)
		return 0;
	if (trap_open) {
		write("The trap door is already open!\n");
		return 1;
	}
	else {
		write("You open the trap door. It is hard work, as the trap door is very heavy.\n");
		show(capitalize(this_player()->QueryName())+" opens the trap door.\n",this_player());
		DOWNROOM->tell_all("Someone opens the trap door above.\n");
		if (find_call_out("fall_shut") != -1)
			remove_call_out("fall_shut");
		call_out("fall_shut", 60);
                trap_open = 1;
		return 1;
	}
   
}

int cmd_close(string str)
{
	if (!str || -1 == member(({"trap","trap door","trapdoor"}), str))
		return 0;
	if (!rug_rolled)
		return 0;
	if (!trap_open) {
		write("But the trap door is closed!\n");
		return 1;
	}
	else {
		write("You close the trap door. THUMP!\n");
		show(capitalize(this_player()->QueryName())+" closes the trap door. THUMP!\n",this_player());
		trap_open = 0;
		DOWNROOM->tell_all("Someone closes the trap door above. THUMP!\n");
		if (find_call_out("fall_shut") != -1)
			remove_call_out("fall_shut");
		return 1;
	}
   
}

void fall_shut() 
{
	tell_room(this_object(),"The trap door falls shut. THUMP!\n");
	trap_open = 0;
	DOWNROOM->tell_all("The trap door above falls shut. THUMP!\n");
}
	
//
// trap door status return function, for query by the cellar.
//
int trap_status()
{
	return trap_open;
}

int roll_rug(string str) {
	if (str != "rug")
		return 0;
	if (query_verb() == "unroll" && !rug_rolled) {
		write("But it is not rolled!\n");
		return 1;
	}
	if (!rug_rolled) {
		write("Easily, you roll the rug to one side of the room.\n");
		write("Surprise! A trap door was hidden under the rug.\n");
		rug_rolled = 1;
	}
	else {
		if (trap_open) {
			write("You can't, because the trap door is open!\n");
		}
		else {
			write("You roll the rug back over the trap door. It is now invisible as before.\n");
			rug_rolled = 0;
		}
	}
	return 1;
}

int vain(string str) {
	if (!str || str != "rug")
		return 0;
	write("The rug is simply too heavy to manipulate it in that way.\n");
	return 1;
}

int vainget(string str) {
	object ob;

	if (!str)
		return 0;
	if (str == "sword")
	{
		if (sword == 0) return 0;
		ob = clone_object(WEAPON("whsword"));
		ob->move(this_object(),M_SILENT);
		switch (ob->move(this_player(),M_GET)) {
		  case ME_OK:
			write("You take the sword.\n");
			sword = 0;
			break;
		  case ME_TOO_HEAVY:
			write("It is too heavy for you to carry.\n");
			ob->remove();
			break;
		  default:
			write("You can't take the sword.\n");
			ob->remove();
			break;
		}
		return 1;
	}
	if (str == "rug") {
		write("The rug is simply too heavy to take.\n");
		return 1;
	}
	return 0;
}

//
// In reset, initialize all things again 
// Roomitems will be handled by the std/room code
//
void reset() {
	::reset();
	rug_rolled = 0;
	trap_open = 0;
	sword = 1;
}

int move_down() {
  	if (trap_open)
		this_player()->move(DOWNROOM,M_GO,"down");
	else
		if (rug_rolled)
			write("The trap door is closed!\n");
		else
			return 0;
	return 1;
}

