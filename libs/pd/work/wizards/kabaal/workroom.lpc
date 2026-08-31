#include <std.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 4, "indoors" : 1]) );
    set_short("Kabaal's Workroom");
    set_long(
      "This is a small, yet elegant looking room.  The  "
      "curtains appear to be made up of a silky material. "
      "On the wall opposite the door stands a mirror.  You"
      "realize this must be Kabaal's Room O' Creation."
    );
    set_items(([
        "curtains" : "Made of silk.",
        "mirror" : "HAHAHA what a goofy looking SOB.", 
    ]));
    set_smell("default", "Pot smoke fills the air.  Woo, contact buzz!");
    set_listen("default", "Limp Bizkit echoes through the small room "  
"but you can't tell where it's coming from.");
    set_exits( ([ 
        "square" :  "/d/standard/square",
        "hall"  :  "/d/standard/adv_inner"
    ]) );
}
