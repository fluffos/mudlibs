#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
   set_properties( ([ "no teleport" : 1]) );
    set_property("mountain",1);
    set_short("Nogard ledge");
    set_day_long(
      "A small tree growing out of a small crack in the "
      "mountan, clings onto a small patch of dirt.  Looking "
      "below, the passage way through the mountains cuts into "
      "rock, like a dried up riverbed.  Loose pebbles along this "
      "ledge blows in circular motion as a light breeze passes "
      "through.  The sun's rays dances brillently along the steep "
      "mountain walls."
    );
    set_night_long(
      "A small tree growing out of a small crack in the "
      "mountan, clings onto a small patch of dirt.  Looking "
      "below, the passage way through the mountains cuts into "
      "rock, like a dried up riverbed.  Loose pebbles along this "
      "ledge blows in circular motion as a light breeze passes "
      "through.  The
moon's rays dances brillently along the steep "
      "mountain walls."
    );
    set_items(([
        "tree" : "You find it amazing that the tree still exists.  "
                  "Very little dirt is left to fortify it, and "
                  "sways viciously when the breeze passes.  "
                  "As you look away, something shiny catches your "
                  "eye",
        "crack" : "A small opening within the rock about four "
                  "inches wide.  A small, but tough tree thrives "
                  "inside the tree.  Looking deeper into the "
                  "crack, darkness presides here.",
        "dirt" : "Not much left of it, some of the exposed roots "
                   "of the tree clings onto it.",
        "patch"  : "Nothing noteworthy about this dirt.",
        "passage" : "On either side of the path, two mountains "
                   "are smoothly carved.  The path is very "
                   "rocky, and there is no signs of life.",
        "mountains"   : "The walls of these mountains seems to "
                   "be protecting something.  Someone has gone "
                   "through great lengths to cave in the passage.",
        "pebbles"  : "Small round rocks that gathered up here on "
                   "the ledge.  Every time the breeze blows "
                   "through here, it picks them up and swirls "
                   "before being dropped again on the ledge.",
        "wall"   : "You don't know who carved this wall so "
                   "smoothly.",
        "roots" : "The roots clings along the wall, holding "
                    "whatever is left of the dirt to protect "
                    "itself from the harsh climate.",
    ]));
    set_smell("default", "A fresh crisp cold air fills your lungs.");
    set_exits( ([
"down" : BLACK "b43",
    ]) );
}
void init()
{
 ::init();
 add_action("Fdown", "down");
}
int Fdown()
{
 write("%^BOLD%^RED%^You slip and slide all the way down.");
 return 0;
}
