#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "cracks" : "A huge hole in the ground",
               "vapors" : "A wired looking mist",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");
   set_long("This is the entrance of a giant cave. The cracks "
            "in the ground seem to have vapors pooring out of "
            "them. This Cave is for the elder creatures of this "
            "land, know as the mountains of roston.");

   set_exits( (["north"  : "/wizards/detach/roston/cave/cave2",
                "south"  : "/wizards/detach/roston/cave/cave20",
                "east"   : "/wizards/detach/roston/cave/cave15",
                "west"   : "/wizards/detach/roston/roston53"]));
}                           


    
   void reset() {
::reset();

     if(!present("bear"))
       {
       new("/wizards/detach/roston/g_bear")->move(this_object());
       }

}                  
