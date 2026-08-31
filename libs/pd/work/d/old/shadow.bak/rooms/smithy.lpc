#include <std.h>
#include <shadow.h>
inherit ROOM;


void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_property("no gate", 1);
    set_property("no attack", 1);
    set_property("no magic", 1);
    set("short", "Geften's Smithy");
    set("long","This is Geften's Smithy.  Geften is standing "
        "at the counter, waiting for your requests.  The store "
        "is nicely lit from the back room where the furnace of "
        "the smithy is.  A warm breeze blows past from the back "
        "room.");
  set_items(
        (["shop" : "You can buy and sell things here.",
          "counter" : "The counter is a simple wooden counter."]) );
    set_exits( (["out" : ROOMS"tene17"]) );
}
