#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("Large bugs are scattered throughout the cavern. The path twists "
          "and turns in the dark. The ground is wet here from snow dripping "
          "onto the rocks floor. ");
 set_listen("default", "Drip...Drip...Drip....");
    set_items(([
({"bugs", "walls"}) : "Some nasty looking bugs climb the walls making some wierd"
	" noises." 
	".",
    ]));
    set_exits( ([ 
       "northeast" :  "/wizards/smoke/mountain/rooms/2",
       "northwest" :  "/wizards/smoke/mountain/rooms/4"
    ]) );
}
void reset() {
    if(!present("eagle"))
        new("/wizards/smoke/mountain/monsters/eagle")->move(this_object());
        new("/wizards/smoke/mountain/monsters/eagle2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/eagle3")->move(this_object());
        new("/wizards/smoke/mountain/monsters/eagle3")->move(this_object());
}
