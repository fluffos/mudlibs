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
      "A small clearing in the trees reveals a massive monument "
      "which looks like three giant steps that leads up into the "
      "heavens.  Some vines cling onto the wall of the first step.  "
      "A small path leads around this monument and back west."
    );
    set_night_long(
      "A small clearing in the trees reveals a massive monument "
      "which looks like three giant steps that leads up into the "
      "heavens.  Some vines cling onto the wall of the first step.  "
      "A small path leads around this monument and back west."
    );
    set_items(([
        "clearing" : ".",
        "trees" : ".",
        "monument" : ".",
        "steps"  : ".",
        "heavens"   : ".",
        "vines"  : ".",
        "wall"   : ".",
        "path" : ".",
        "step" : ".",
    ]));
    set_smell("default", "A fresh crisp cold air fills your lungs.");
    set_exits( ([
"north" : BLACK "b21",
"south" : BLACK "b23",
"west" : BLACK "b32",
    ]) );
}

