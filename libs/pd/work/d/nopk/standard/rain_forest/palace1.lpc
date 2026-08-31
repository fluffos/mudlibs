#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Inside the palace");
   set_long("A magnificent elven palace. There "
            "are gold decerations along the walls, and many othe"
            "r ornaments. Off to the south is the throne and to the e"
            "ast and west are hallways.");
   set_exits((["north" : ROOMS"pentrance",
               "south" : ROOMS"palace2",
               "east" : ROOMS"palace3",
               "west" : ROOMS"palace5"]));
}

void reset() {
   ::reset();
   if(!present("butler"))
   new(MOB"butler")->move(this_object());
}
