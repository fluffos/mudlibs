#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("A path to the graveyard");
     set_short("A path to the graveyard.");
     set_long("This desolate path has been worn thin by the many mourners "
"that have passed by in last few hundred years. The sounds of tortured souls "
"has grown to an ear shattering high. A large building can be seen "
"looming over the eastern horizion.");
     set_night_long("Shadows flitter around, making it seem like "
"there are many things out in the darkness. Looming shapes stand "
"closer to the path, making it hard to concentrate. ");
     set_properties(([
        "light"       : 1,
        "night light" : 0,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["northeast" : ROOMS"room4", 
              "east" : ROOMS"room5",
              "southeast" : ROOMS"room6",
              "west" : ROOMS"room2"]) );
 set_listen("default", "Wailing can be heard all around.");
 set_smell("default", "The stench of burning flesh hangs in the air.");

    set_items( ([
            "path" : "Hard packed clay and dirt.",
            "stones" : "Large and small stones that have been beaten into the path",
      ]) );

}

