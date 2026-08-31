#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
    set_long("This trail in the forest has little squirrel size rodents"
             " running and jumping around the trees. The path continues"
             " west.");
    set_short("lemur forest");
    set_items((["trees": "All the trees are green and none of them"
                         "appear to be brown. There are old trees, and"
                         "little sapplings, all the trees have vines on"
                         "them",
                "leaves": "Most of the leaves are rotting",
                "rodents": "There are many small rodents running around"
              ]));
 set_exits((["west" : ROOMS"dirt3",
             "east" : ROOMS"hlemur"]));

}

void reset() {
   ::reset();
   if (!present("lemur"))
   new("/d/nopk/standard/rain_forest/mon/lemur")->move(this_object());
          }
