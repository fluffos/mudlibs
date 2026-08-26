#include <std.h>
#include <objects.h>
//at 41,44 on sea
inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create(){
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_short("The Serakii Docks");
    set_long("This is a dock that Loki will be describing.");
    set_listen("default","Gentle waves lap against the pier.");
    set_smell("default","It smells like too much fish.");
/*    set_exits(([
        "east" : "somewhere on Serekii",
    ] ));*/
    set_items(([
        "dock" : "It's a dock."
        ]));
}

