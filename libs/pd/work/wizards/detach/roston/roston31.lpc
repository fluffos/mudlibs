#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));
   set_properties((["light":2, "night light":2]));
   set_short("A snow path");                        
   set_long("Your on the peek of a giant mountain. "
            "The snow is very deep here, from up here "
            "you can see the hole town of Roston.");
   
   set_exits( ([ 
              "south" : "/wizards/detach/roston/roston30",
              "west"  : "/wizards/detach/roston/roston32",
              "east" : "/wizards/detach/roston/roston33"]));
 
}
 void reset() {

     if(!present("snake"))
       {
       new("/wizards/detach/roston/snake")->move(this_object());
       }

}                                                                                       
