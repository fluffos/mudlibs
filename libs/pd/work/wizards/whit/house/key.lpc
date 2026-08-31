//  Whits House

#include <std.h>
#include <daemons.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("whits house");
    set_short("a quarts and crystal key");
    set_long("The key looks very precious and fragile.  You could "
      "probally insert it into a keyhole.\n");
    set_id(({ "key" }));
}

void init() {
    ::init();
    add_action("out", "out");
    add_action("ins", "insert");
}

int ins(string s) {
    string what, obj;
    if(sscanf(s, "%s into %s", obj, what)!=2) return 
	notify_fail("Insert what into where?\n");
    if(!id(obj)) return 0;
    if( (what != "pedistal" && what != "keyhole") ||
      environment(this_player()) != find_object("/wizards/whit/house/room2")) 
	return 0;
    write("You insert the key into the pedistal.\nWhich way would you like to turn it: ");
    say(this_player()->query_cap_name()+" inserts "+possessive(this_player())+
      " key into the "+what);
    input_to("turn");
    return 1;
}

int turn(string s) {
    int st;
    st="/wizards/whit/house/room1"->query_open();
    switch(lower_case(s)) {
    case "right":
    case "r":
	if(!st) {
	    write("You turn the key to the right, but nothing happens.\n");
	    say(this_player()->query_cap_name()+" turns the key to the "
	      "right, but nothing happens.");
	    return 1;
	}
	message("", "The door swings closed.\n", environment(this_player()));
	if(find_object("/wizards/whit/house/room1"))
	    message("", "The door swings closed.\n", find_object("/wizards/whit/house/room1"));
	"/wizards/whit/house/room1"->set_open(0);
	"/wizards/whit/house/room1"->remove_exit("north");
	environment(this_player())->remove_exit("south");
	return 1;
	break;
    case "left":
    case "l":
	if(st) {
	    write("You turn the key to the left, but nothing happens.\n");
	    say(this_player()->query_cap_name()+" turns the key to the "
	      "left, but nothing happens.");
	    return 1;
	}
	message("", "The door swings open.\n", environment(this_player()));
	if(find_object("/wizards/whit/house/room1"))
	    message("", "The door swings open.\n", find_object("/wizards/whit/house/room1"));
	"/wizards/whit/house/room1"->set_open(1);
	"/wizards/whit/house/room1"->add_exit("/wizards/whit/house/room2","north");
	environment(this_player())->add_exit("/wizards/whit/house/room1", "south");
	return 1;
	break;
    }
    write("You decide not to turn the key and remove it from the pedistal.\n");
    say(this_player()->query_cap_name()+" removes the key from the pedistal.\n");
    return 1;
}

