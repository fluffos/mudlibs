#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("This is more or less just a crevass in the wall. It definately "
          "looks like something lives here by the random bones of lizards,"
          " rats, birds and other animals that reside within this mountain.");
 set_smell("default", "The rotten meat off the bones creates an awful stench.");
    set_items(([
({"bones"}) : "Bones from various animals have been mostly stripped of the meat"
         " and tossed aside."
    ]));
    set_exits( ([ 
       "north" :  "/wizards/smoke/mountain/rooms/2_32",
       "west" :  "/wizards/smoke/mountain/rooms/2_34"
    ]) );
}
void reset() {
    if(!present("willy"))
        new("/wizards/smoke/mountain/monsters/lizard2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/lizard2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/lizard")->move(this_object());
}
