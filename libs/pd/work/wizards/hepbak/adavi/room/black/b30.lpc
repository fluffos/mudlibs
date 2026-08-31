#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
   set_properties( ([ "no teleport" : 1]) );
    set_property("mountain",1);
    set_short("Adavi Swamp");
    set_day_long(
      "Large pine trees grown close together forms a small "
      "path bearing north and south.  Looking west through "
      "a small opening, the sun glistens off the polished "
      "mountain walls.   Slowly, the mud sucks and pulls "
      "downward, which will make it harder to travel "
      "quickly through the forest.  To the east, a large "
      "jagged boulder pierces through the trees."
    );
    set_night_long(
      "Large pine trees grown close together forms a small "
      "path bearing north and south.  Looking west through "
      "a small opening, the moon glistens off the polished "
      "mountain walls.   Slowly, the mud sucks and pulls "
      "downward, which will make it harder to travel "
      "quickly through the forest.  To the east, a large "
      "jagged boulder pierces through the trees."
    );
    set_items(([
        "pine" : "A sweet smelling tree, that have needles for "     
                 "leaves.",
        "trees" : "It's a pine tree, they have grown so thick, "
                  "that the narrow path is the widest gap "
                  "inside this place.",
        "tree"  : "It's a type of pine tree, the needles on the "
                  "trees are very short and sturdy, which when "
                  "you touch it feels like little pins sticking "
                  "in your fingers.",
        "path" : "If you can call it a path, it is very narrow, and "
                 "the mud is so deep that following this path would "
                 "require all your energy to get through it.",
       "opening" : "Brillent light bounces off the mountain side, "
                   "almost looks like diamonds sparkling.",
       "mountain" : "Smoothed polished rocks towering high above "                        "you.",
       "mud" :  "This mud clings on, pulling you down, it is dark "                   "brown in color, almost black.  You pray that it "                    "doesn't suck you under.",
       "forest" : "Even though the mud is quite discouraging, the "            
"view inside this forest is almost breathtaking.  "
                  "The pine trees are a deep green in color, but "
                  "when the natures' light peeks through, a golden "
                  "hue flutters down and dissapates before touching "          
"the ground.",
       "boulder" : "It is unclimbable, trees grow very close to "
                   "this boulder so that nothing can go in between.",
          
    ]));
    set_smell("default", "A mixture of pine and wet earth scents the air.");
    set_exits( ([
"north" : BLACK "b29",
"south" : BLACK "b31",
"out" : BLACK "b40",
    ]) );
}
