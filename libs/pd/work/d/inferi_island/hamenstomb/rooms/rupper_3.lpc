#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^RESET%^%^ORANGE%^This tower was built so the Watchers could make sure no harm comes to the King of the tomb. From the tops of these towers, the whole tomb can be seen, making it easy for the arrows to fly from one end of the pyramid to the other with haste. The ground is made of stone and the walls are positioned nicely to stay hidden. There is a hole in the ceiling allowing the sunlight to dance off the walls.\n");
    set_exits( ([ "east" : ROOMS+"rupper_1", "west" : ROOMS+"rupper_5" ]) );
}
void reset() {
    ::reset();
    if (!present("vulture", this_object()))
	new(MON+"black_vulture")->move(this_object());
    if (!present("watcher", this_object()))
	new(MON+"watcher")->move(this_object());
}
