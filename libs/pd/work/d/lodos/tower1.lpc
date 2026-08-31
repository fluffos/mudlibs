#include <lodos.h>
#include <std.h>
inherit VAULT;
void look_door();

void create() {
 ::create();
   set_short("At the foot of a large tower");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_property("light", 2);
   set_long("The large tower reaches into the sky, towering "
            "above you. The walls have been well made, and "
            "a thin, wooden door leads west, back into the street.");
   set_listen("default", "The sounds of work and muttering can be heard.");
   set_exits(([ "up" : ROOMS"tower2",
                "west" : ROOMS"ntown5"]));
   set_items(([ "door" : (: look_door() :) ]));
   set_door("door", ROOMS"ntown5", "west", "");
}

void look_door() {
    if(query_open("door")) write("It is open.");
    else write("It has been closed.");
}
