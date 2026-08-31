#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "indoors":1, "night light" : 1, ]) );
    set_short( "an entrance" );
    set_long("A path leads down the inside of the mountain towards the city of Duergar.  Torches line the path but the smoke ventilation is slow, and the air is very thin.  Sounds of commotion echo across the walls, although it's not clear how far away it is coming from.  A light shines farther down the path.");
set_exits(([ "down" : ROOMS"mountainpath/68",
"up" : ROOMS"mountainpath/66",
]));
    set_items( ([
({"torches"}):"The torches seem to be lit with a magical flame that doesn't flicker or go out.",
"smoke":"The smoke is thick due to lack of ventilation.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");

        if(!present("dguard"))
          new(MOB "dguard")->move(this_object());
          new(MOB "dguard")->move(this_object());

}
