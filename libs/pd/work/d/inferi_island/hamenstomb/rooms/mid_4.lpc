#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^RESET%^%^YELLOW%^The stairs in this area are not as steep as the ones before, but still make it hard to maneuver. The walls of the pyramid are cracking, showing thier age. Water continues to flow down these cracks as if it is a small waterfall. It is even more active as the next platform approaches. \n");
    set_exits( ([ "southeast" : ROOMS+"mid_2", "northwest" : ROOMS+"mid_5", "north" : ROOMS+"rup_2" ]) );
}
void reset() {
    ::reset();
    if (!present("wearied", this_object()))
	new(MON+"wearied_one")->move(this_object());
    if (!present("child", this_object()))
	new(MON+"child_of_the_sun")->move(this_object());
    if (!present("wearied", this_object()))
	new(MON+"wearied_one")->move(this_object());
    if (!present("child", this_object()))
	new(MON+"child_of_the_sun")->move(this_object());
}
