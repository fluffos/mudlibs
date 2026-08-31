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
      "Bits and pieces of the rocky mountain wall pokes through the "
      "thinning trees along the west side.  The trees along the east, "
      "are still tightly packed together, allowing no passage through.  "
      "Soft golden rays of sun light filters through the tree tops, help "
      "guides the way through.  The ground seems a little bit more firmer "
      "than before."
    );
    set_night_long(
      "Bits and pieces of the rocky mountain wall pokes through the "
      "thinning trees along the west side.  The trees along the east, "
      "are still tightly packed together, allowing no passage through.  "
      "Soft rays of moon light filters through the tree tops, help "
      "guides the way through.  The ground seems a little bit more firmer "
      "than before."
    );
    set_items(([
        "trees" : ".",
        "mountain" : ".",
        "ground"  : ".",
        "path"   : ".",

    ]));
    set_smell("default",
"A fresh crisp cold air fills your lungs.");
    set_exits( ([
"north" : BLACK "b25",
"south" : BLACK "b27",
    ]) );
}

