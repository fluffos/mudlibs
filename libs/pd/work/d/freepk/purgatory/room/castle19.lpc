#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle19");
     set_short("The Purgatory Castle");
     set_long("%^CYAN%^Bustling servants glide through this small hallway running "
"%^CYAN%^errands for their Lords or Ladies.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["northeast" : ROOMS"castle10",
              "southwest" : ROOMS"castle16",
              "northwest" : ROOMS"castle25",
              "southeast" : ROOMS"castle11"]) );


}


void reset() {
    ::reset();
     if (children(MOBS"ghost")==({})||
         sizeof(children(MOBS"ghost"))<30)
            new(MOBS"ghost")->move(this_object());
        
}
