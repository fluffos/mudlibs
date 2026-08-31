#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("marsh",1);
    set_short("Mystic Marsh.");
    set_day_long(
      "A muddied path traces around a small pond that is "
      "surrounded by tall trees.  Roots from the trees are "
      "exposed above the pond making it hard to enter the "
      "water."
          );
    set_night_long(
      "A faint glow of the moon reveals a path that traces "
      "around a small pond.  Along the outskirts of the pond, "
      "tall trees seem to huddle together.  Roots from the "
      "trees are exposed above the pond making it hard to "
      "enter the water."
);
    set_items(([
        "water" : "Mixture of blue and brown.",
        "pond" : "It seems very hard to enter it, maybe there is "
                 "another way.",
        "path" : "It's very muddy and well traveled.",
        "trees" : "They grow closely together, forming a wall.  "
                  "It seems as thoug
 they are hiding something.",
        "roots" : "Are tangled up and nasty looking.  You feel "
                  "that there must be a better way to enter the pond.",
    ]));
    set_listen("default", "Tiny air bubbles pops on the pond's surface.");
    set_exits( ([
"west" : MARSH "mar4",
"north" : MARSH "mar7",
    ]) );
}
