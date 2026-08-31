#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("A path to the graveyard");
     set_short("A path to the graveyard.");
     set_long("This desolate path has been worn thin by the many mourners "
"that have passed by in the last few hundred years. A horrible wailing "
"echoes in from the east followed by the stench of death. Some small "
"stones can be seen set into the path. A large building can be seen "
"looming distantly in the east.");
     set_night_long("Shadows flitter around, making it seem like "
"there are many things out in the darkness. Looming shapes stand "
"closer to the path, making it hard to concentrate. An old man "
"mutters fitfully in his sleep near the road where he lies.");
     set_properties(([
        "light"       : 1,
        "night light" : 0,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"room2", 
              "west" : ROOMS"purgatory32"]) );


    set_items( ([
            "path" : "Hard packed clay and dirt.",
            "stones" : "Large and small stones that have been beaten into the path",
      ]) );

}

void reset() {
 ::reset();
  if (!present("caretaker", this_object()))
    new(MOBS"caretaker2" )->move(this_object());
}
