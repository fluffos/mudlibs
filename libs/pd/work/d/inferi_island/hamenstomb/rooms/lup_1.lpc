#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^RESET%^%^YELLOW%^There are writings on the walls that are glowing with a %^RESET%^%^RED%^deep red%^BOLD%^%^YELLOW%^. This seems to be a little nook made for those who wanted to get away from the hustle and bustle of the city. There are small animals passing through searching for their scraps of food, but as they look over toward the wall with the writing they turn around and run away. There must be something significant about these writings.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'."]) );
    set_exits( ([ "north" : ROOMS+"hamen_tomb_13", "south" : ROOMS+"hamen_tomb_5" ]) );
}
