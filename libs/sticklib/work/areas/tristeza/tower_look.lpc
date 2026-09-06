// This module is used to add views from the city towers.
// Version 1.0 19-feb-95 by Doomdark.

#include "DEFS.h"

void add_command(string a, string b);
string *tower_look;

void
add_tower_look(string *x)
{
    tower_look = x;
    add_command("l", "look_cmd");
    add_command("look", "look_cmd");
}

int
look_cmd(string str)
{
    if (!str) return 0;
    (sscanf(str, "at %s", str) || sscanf(str, "to %s", str));
    // Let's skip 'at' or 'to' if present in string.

    if (tower_look && member(tower_look, str) >= 0) {
	this_player()->tell_me(read_file(CITY_DIR+str));
	return 1;
    }

    if (str != "north" && str != "east" && str != "south" && str != "west")
	return 0;

    this_player()->tell_me("You can't see that way from this tower.");
    return 1;
}
