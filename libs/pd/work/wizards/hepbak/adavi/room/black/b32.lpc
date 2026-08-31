#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("mountain",1);
    set_short("Adavi Swamp");
    set_day_long(
      "Where the three paths join, small tracks go around "
      "a small waterhole.  Along the west side, small "
      "amount of a rock wall peeks through the trunks of "
      "the trees.  Looking east, some trees thinned out to "
      "reveal a small ledge."
    );
    set_night_long(
      "Need to have a search water function to find a scale."
    );
    set_items(([
    "pine" : "A sweet smelling tree, that have needles for leaves.",
    "trees" : "It's a pine tree, they are grown so thick, that the "
              "narrow path is the widest gap inside this place.",
    "tree"  : "It's a type of pine tree, the needles on the tree "
              "are very short and sturdy, which when you touch it "
              "feels like little pins sticking in your fingers.",
   "path" : "If you can call it a path, it is very narrow, and "
            "the mud is so deep that following this path would "
            "require all your energy to get through it.",
  "opening" : "Brillent light bounces off the mountain side, almost "
              "looks like diamonds sparkling.",
  "mountain" : "Smoothed polished rocks towering high above you.",
  "mud" :  "This mud clings on, pulling you down, it is dark brown "
           "in color, almost black.  You pray that it doesn't suck "
           "you under.",
  "forest" : "Even though the mud is quite discouraging, the view "
             "inside this forest is almost breath taking  The pine "
            "trees are a deep green in color, but when the natures' "
            "light peeks through, a golden hue flutters down and "
            "dissapates before touching the ground.",
    ]));
    set_smell("default", "A mixture of pine and wet earth scents the air.");
    set_exits( ([
"north" : BLACK "b31",
"south" : BLACK "b33",

"east" : BLACK "b22",
    ]) );
}
