
#include <std.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Suluial's Thinking Room");
    set_long(
      "A wonderfully colored room.  There are purples, "
      "greens, reds, yellows, blues, and oranges "
      "everywhere!  There is a large thinking cap "
      "sitting on a rosewood table.  It seems like a "
      "wiz works here."
    );
    set_items(([
        "room" : "The room's colors are dazzeling.",
        "colors" : "The colors are constantly swirling together, forming "              "images of whatever Daer is thinking.",
        "images" : "Suluial seems to have quite an active imagination!",
        "imagination" : "We won't go there :D ",
        ({"table", "rosewood table"}):
              "It is made of a very nice looking rosewood.",
        ({"cap", "thinking cap"}):
              "Suluial needs to use that to think up new ideas."
    ]));
    set_smell("default", "An odd smell of burning water is in the air.");
    set_listen("default", "The sound of a frustrated wiz beating his "              "code is here");
    set_exits( ([ 
        "square" :  "/d/standard/square",
        "hall"  :  "/d/standard/adv_inner"
    ]) );
    
}
