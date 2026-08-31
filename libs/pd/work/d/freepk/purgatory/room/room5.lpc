#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("A path to the graveyard");
     set_short("A path to the graveyard.");
     set_long("This desolate path has been worn thin by the many mourners "
"that have passed by in last few hundred years. All the sound in the area has "
"suddenly stopped, leaving an eerie silence in its place. A large building, "
"that sends a chill down most travelers spines, has appeared out of a thin "
"mist.");
     set_night_long("Shadows flitter around, making it seem like "
"there are many things out in the darkness. Looming shapes stand "
"closer to the path, making it hard to concentrate. A dark mist "
"clouds the view to the east.");
     set_properties(([
        "light"       : 1,
        "night light" : 0,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"room4", 
              "south" : ROOMS"room6",
              "west" : ROOMS"room3"]) );
 set_listen("default", "Deathly silence blankets this place.");
 set_smell("default", "The stench of burning flesh hangs in the air.");

    set_items( ([
            "building" : "This building looks like it was build hundreds of years ago when the town was still forming. The shapes and design of it are something never seen before, as if a being of another world crafted it from its own mind.",
            "path" : "Hard packed clay and dirt.",
            "stones" : "Large and small stones that have been beaten into the path",
      ]) );

}
