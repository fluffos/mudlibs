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
      "The mountain curves and dissappears in to the "
      "tree line. The trees along the east are tightly "
      "grown, allowing no short cut through."
    );
    set_night_long(
      "The mountain curves and dissappears in to the "
      "tree line. The trees along the east are tightly "
      "grown, allowing no short cut through."
    );
    set_items(([
        "mountain" : ".",
        "tree" : ".",
        "trees" : ".",
        "path"   : ".",
        "wall"   : ".",
    ]));
    set_smell("default","A fresh crisp cold air fills your lungs.");
    set_exits( ([
"north" : BLACK "b33",
    ]) );
}
