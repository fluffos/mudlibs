#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "indoors":1, "night light" : 1, ]) );
    set_short( "an entrance" );
    set_long("The mountain has an entrance here, and it is the last passable way to go.  There are torches burning on either side of the entrance.  It looks like the mountain goes on hollow for quite a while on the inside.  Smoke comes out of the cave in billows, as if it is one of the few openings to the mountain's insides.");
set_exits(([ "down" : ROOMS"mountainpath/67",
"south" : ROOMS"mountainpath/65",
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
        if(!present("dscout"))
          new(MOB "dscout")->move(this_object());

}
