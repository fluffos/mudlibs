#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("This birds nest is high above this portion of the cave, howe"
          "ver it's too dark to see anywhere but down. The nest is compos"
          "ed of a ridiculous amount of twigs, brush and cloth.");
 set_listen("default", "An annoying chirping can be heard from above.");
    set_items(([
({"twigs", "nest", "brush", "cloth"}) : "The nest is composed of twigs, " 
         "brush and cloth. " ]));
    set_exits( ([ 
       "down" :  "/wizards/smoke/mountain/rooms/2_3"
    ]) );
}
void reset() {
    if(!present("eagle"))
        new("/wizards/smoke/mountain/monsters/eagle")->move(this_object());
        new("/wizards/smoke/mountain/monsters/eagle2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/eagle3")->move(this_object());
        new("/wizards/smoke/mountain/monsters/eagle3")->move(this_object());
}
