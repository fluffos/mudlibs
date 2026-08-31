#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a lions den");
 set_long("This part of the den is actually picked up aside from the "
          "fresh carcass lying on the ground. A pile of cloth lie on"
	  " the ground in the corner, which looks like a bed. ");
    set_items(([
({"den"}) : "This seems to be where Leo, the King of the Lions spends his day.",
({"cloth", "bed"}) : "The cloth is piled up in the northwest corner, making up a bed for"
	" Leo, the King of the Lions."
    ]));
    set_exits( ([ 
       "east" :  "/wizards/smoke/mountain/rooms/den5"
    ]) );
}
void reset() {
    if(!present("lion"))
        new("/wizards/smoke/mountain/monsters/leo")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion3")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion3")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion2")->move(this_object());
 new("/wizards/smoke/mountain/items/other/carcass")->move(this_object());
}
