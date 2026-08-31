#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("An underground tunnel.");
     set_short("An underground tunnel.");
     set_long("It looks like a nest of some unfriendly people have "
"made a tunnel into the castle. The earth walls seem stifling, as if " 
"they are about to cave in. Small worms stick their heads out of the "
"ground to look at any travelers. The tunnel continues on to the west.");
     set_night_long("It is far too dark to see anything at night in the tunnel.");
     set_properties(([
        "light"       : 1,
        "night light" : -2,
        "no bump"     : 1,
        "underground"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["west" : ROOMS"room85", 
              "southeast" : ROOMS"room83",
]) );
 set_listen("default", "Deathly silence blankets this place.");
 set_smell("default", "An earthy smell hangs around.");

    set_items( ([

            "wall" : "Hard packed clay and dirt.",
            "stones" : "pebbles packed into the walls and ceiling",
      ]) );

}
