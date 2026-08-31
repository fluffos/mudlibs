#include <std.h>
#include <rain.h>
inherit VAULT;

create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("The entrance to the Palace");
   set_long("The gates of the palace. "
            "There are a few guards standing along the hallway gau"
            "rding some doors. Unlike the outside village this pal"
            "ace is very nice. There are many things made out of g"
            "old.");
   set_exits((["north" : ROOMS"pgate",
               "south" : ROOMS"palace1"]));
    set_door("gate", ROOMS"pgate", "north", "gate key");
   set_items((["gold" : "These golden objects were finely crafted"]));
}
