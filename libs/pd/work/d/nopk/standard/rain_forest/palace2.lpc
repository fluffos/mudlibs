#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("In the palace");
   set_long("A long hallway in the palace. There is a suit of armour with wea"
            "pons in it's hands leaning against the wall. This corr"
            "idor breaks off to the southeast and the west.");
   set_items((["armour" : "This is a large suit of platemail "
               "leaning up against the wall with weapons jammed into"
               " the gauntlets.",
               "weapons" : "These are two long royal swords jammed i"
               "nto a pair of gauntlets."]));
   set_exits((["east" : ROOMS"palace7",
               "west" : ROOMS"palace11",
               "north" : ROOMS"palace1"]));
}

void reset() {
   ::reset();
   if(!present("guard"))
   new(MOB"guard3")->move(this_object());
}
