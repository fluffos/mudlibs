#include "../DEFS.h"

status disappeared;
status peeking;

int not_here();

int id(string str)
{
    object other_door;
    if(str == "plaque")
	return 1;
    if(peeking || (str != "door" && str != "shimmering door"))
	return 0;
    peeking = 1;
    if(catch(other_door = present("door", environment())))
	other_door = 0;
    peeking = 0;
    if(other_door || environment()->id("door"))
	return 0;
    return 1;
}

string query_name() { return "shimmering door"; }

string short()
{
    if(disappeared)
	return "There is no longer a shimmering door here";

    return "There is a shimmering door here";
}

void long(string str)
{
    if(not_here())
	return;

    if(str == "plaque")
	this_player()->tell_me("\n\t\tRinzewynde's  shoppe of\n"+
	  "\t\t  majiik curiousities\n");
    else
	this_player()->tell_me("There is a worn plaque on the door.");
}

void init() {
    add_action("open", "open");
    add_action("enter", "enter");
    add_action("read", "read");
}

status open(string str) {
    if(!id(str))
	return 0;
    if(not_here())
	return 1;
    this_player()->tell_me("This is a magic door! It is always open and "+
      "always closed, whichever is required of it. Pretty neat, huh?\n");
    return 1;
}

status enter(string str)
{
    if(!id(str))
	return 0;
    if(not_here())
	return 1;
    this_player()->move_player("through the door#"+TRAV_SHOP);
    return 1;
}

int fade() { disappeared = 1; }

int not_here()
{
    if(disappeared)
	this_player()->tell_me("You mean the one that is not here?");
    return disappeared;
}

status read(string str)
{
    if(str != "plaque")
	return 0;
    long(str);
    return 1;
}
