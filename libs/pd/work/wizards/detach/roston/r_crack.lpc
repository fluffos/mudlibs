#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Entrance to Crack");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("entrance to crack");
set_long("This is the entrance to a giant crack in the ground. The "
         "the ground seems to shack here, the giant crack seems to "
         "to go on forever and ever, you can enter it if you wish. ");

set_exits( ([ "out" : "/wizards/detach/roston/roston7",
              "down" : "/wizards/detach/roston/r_crack2" ]));
}
                                              


void reset() {
  ::reset();
     if(!present("bear"))
       {
       new("/wizards/detach/roston/m_bear")->move(this_object());
       new("/wizards/detach/roston/m_bear")->move(this_object());
       new("/wizards/detach/roston/m_bear")->move(this_object());  
   }
}
