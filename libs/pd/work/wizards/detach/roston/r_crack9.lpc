#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Crack to Roston");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("Crack in roston");
set_long("This is a great opening in the ground it semes to "
         "to lead all around the under the earth, it looks like "
         "giant mountains are peeking up from the surface, the "
         "mountains are beging to fall threw the roof, as light "
         "seeks threw the roof. You now have to crouch to walk threw "
         "the crack. ");

set_exits( ([ "up" : "/wizards/detach/roston/r_crack8",
              "down" : "/wizards/detach/roston/r_crack10" ]));
}                                          
void reset() {
  ::reset();
     if(!present("hunter"))
       {
       new("/wizards/detach/roston/hunter")->move(this_object());
   }
}     
