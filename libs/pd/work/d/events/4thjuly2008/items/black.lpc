#include <std.h>
inherit OBJECT;

string dest;

void set_destination(string str)
{
    dest = str;
}

void create() {
    ::create();
    set_id( ({"portal", "black portal"}) );
    set_name("portal");
    set_short("%^BOLD%^A magical black portal%^RESET%^");
    set_long("Echoes resonate through the portal.");
}

int init()
{
    ::init();
    add_action("enter", "enter");
}

int enter(string str)
{
    if (!str)
    {
	write("Enter what?");
	return 1;
    }

    if (str == "portal")
    {
	write("You enter the portal and land in a dark and ominous place.");
	this_player()->move_player(dest, "into the portal");
	return 1;
    }
}

int get() { return 0; }

