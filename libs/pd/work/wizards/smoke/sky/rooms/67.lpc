#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^A small break in the trees on the southern side of "
            "the path shows a small pond sitting there. The trees dominate "
            "the northern side of the path as well as the other side of the "
            "pond. Plants grow on both sides of the path.%^RESET%^");
   set_items(([
            "trees" : "There are plenty of trees on each side of the path. "
                        " They are all different sizes and varieties, "
                        "but they all have an exotic look to them.",
            "path" : "An old, worn dirt path leads through the jungle. "
                 "It gets hard to see sometimes because the plants are "
                 "so dense with all the plantlife.",
            "plants" : "All sorts of different plant species grow in the jungle"
                 ". Most of them are huge compared to more domesticated plants.",
            "pond" : "A small pond can be seen on the southern side of the "
                "path. Thick plants grow around the pond. The animals of the "
                "jungle probably get most of their water at this pond."
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "Loud birds can be heard talking to eachother "
                 "from the treetops.");
   set_exits( ([ 
        "northwest" :  ROOMS "23",
        "east" :  ROOMS "68"]));
}
