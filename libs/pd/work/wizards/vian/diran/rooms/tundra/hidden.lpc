#include <std.h>
#include <diran.h>

inherit "/std/vault";

void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
set_long("This is a small hidden spot behind a bush, and before a part of the tundra that is blocked off by fallen snow.  There is nothing of importance here, save a small wooden shack.");
    set_short( "a snowy tundra" );
set_exits(([ "northwest" : ROOMS"tundra/62",
             "enter" : ROOMS"tundra/hiddenshack"]));
    set_door("door", ROOMS"tundra/hiddenshack", "enter", "shackkey");  
    set_locked("door", 1);
    set_open("door", 0);
    
    set_smell("default",  "The dry arctic wind carries little scent.");
    set_listen("default", "The sound of animals and humanoids fighting can be heard throughout the tundra.");
    }
    int pick_lock(string str) { return 0; }
void reset() {
    ::reset();
    set_open("door", 0);
    set_locked("door", 1);
    ROOMS"tundra/hiddenshack"->set_open("door", 0);
}
