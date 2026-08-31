#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^YELLOW%^The air seems damp and thin in this room.  No torches line the walls that seem to be glowing on their own, it is as if walls of this tomb are made of gold. There is a picture of a Sphinx on left wall and more writing is placed under it.  There is a loud noise in the distance.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'.", "sphinx" : "%^YELLOW%^The Sphinx's eyes seem to watch you as you move around the room." ]) );
    set_exits( ([ "east" : ROOMS+"hamen_tomb_4", "west" : ROOMS+"hamen_square", "northwest" : ROOMS+"middle_1" ])
    );
}
