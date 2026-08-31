// seeker
#include <sindarii.h>
#include <std.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the rain forest");
   set_long("You have climbed up into the large trees. Rain "
           "patters down against your shoulders. The sun has become "
           "visible, although still not very bright. Monkeys climb about, "
           "playing in the trees, swinging from tree to tree. You could "
           "pretty easily make it to the next tree from here..");
set_items( 
          ([ "vines" : "The vines go from tree to tree.",
             "trees" : "The trees tower over you.",
             "ground": "You can hardly see it from here.",
             "monkeys" : "They seem to be moving quickly." ]) );

set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals squeeking.");
set_exits( (["down" : ROOMS"rain_forest/puddle",
              "south" : ROOMS"rain_forest/canopy_s1"]) );

}

void reset()
{
 if (!present("gorilla"))
    new(MOB"gorilla")->move(this_object());
      present("gorilla")->force_me("wield spear");
}
   
