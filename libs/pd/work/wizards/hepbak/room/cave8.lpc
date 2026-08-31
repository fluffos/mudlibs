#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "cracks" : "A huge hole in the ground",
               "vapors" : "A wired looking mist,with a tint of red",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("This is a part of the cave where Elder creatures "
            "come to rest after there long days. There is tons "
            "of bones all over the floor. The vapors seem to be "
            "a red color");

   set_exits( (["west"  : "/wizards/detach/roston/cave/cave6"]));  
  
}



   void reset() {

     if(!present("Elder Bear"))
           {
       new("/wizards/detach/roston/cave/e_bear")->move(this_object());
      }              

}
