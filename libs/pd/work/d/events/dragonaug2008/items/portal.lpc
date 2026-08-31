#include <std.h>
inherit OBJECT;

string dest;

void set_destination(string str)
{
    dest = str;
}

void create() {
    ::create();
    set_id( ({"portal", "white portal"}) );
    set_name("portal");
    set_short("%^BOLD%^A magical white portal%^RESET%^");
    set_long("Ice crystals hang down from the edges of the portal.");
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
	write("You enter the portal and land in a place covered with snow.");
	this_player()->move_player(dest, "into the portal");
	return 1;
    }
}

int get() { return 0; }

