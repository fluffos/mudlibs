#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
    set_long("A giant anthill dominates the area. The area is covered with "
             "trees. The path splits to the "
             "northwest and southwest.");
    set_short("A forest");
    set_items((["trees": "All the trees are green and none of them"
                         " appear to be brown. There are old trees, and"
                         " little sapplings, all the trees have vines on"
                         " them",
                "leaves": "Most of the leaves are rotting",
                "anthill" : "This ant hill is made from top to bot"
                             "tom out of"
                             " sand and there is a huge hole in the"
                             " top."]));
set_exits((["east" : ROOMS "dirt3",
                "northwest" : ROOMS"termite",
                "southwest" : ROOMS"antlion"]));
    

  }
void reset() {
  ::reset();
   
      if (!present("ant")) {
        
      new(MOB"ant")->move(this_object());
      new(MOB"ant")->move(this_object());
      new(MOB"ant")->move(this_object());        
      new(MOB"ant")->move(this_object());
      new(MOB"ant")->move(this_object());
      }
}

