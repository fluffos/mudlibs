#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("There isn't much to this cave. It is fairly dark, damp "
          "and it smells terrible!");
    set_exits( ([ 
       "west" :  "/wizards/smoke/mountain/rooms/2_18"
    ]) );
}
void reset() {
    if(!present("dragon"))
        new("/wizards/smoke/mountain/monsters/dragon")->move(this_object());
}
