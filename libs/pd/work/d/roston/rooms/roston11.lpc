#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();      

set_name("west of town square");
set_items((["snow"   : "Broken bottles lie in the snow.",
            "bottles"  : "They have been smashed."]));     
set_properties ((["light":2, "night light":3]));
set_short("A dirt path");
set_long("The sound of banging metal grows louder. You "
         "notice broken bottles in the snow along the side "
         "of the path. This seems to be a well traveled, "
         "and often used, road.");

set_exits((["east":ROOMS"roston",
            "west":ROOMS"roston13"]));
}                                                         
void reset() {

     if(!present("man"))
       {
        new(MOB "t_man")->move(this_object());
       }

}
                                   
