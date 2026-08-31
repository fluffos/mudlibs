#include <std.h>

inherit ROOM;

void create() {
 ::create();
   set_name("north of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));         
   set_properties((["light":2, "night light":2]));
   set_short("A dirt path");
   set_long("This is a dirt path that seems to be leading "
            "to a giant white palace. There are foot prints "
            "all over the ground. On the side of the path "
            "you can see patches of snow.");

set_exits((["south":"/wizards/detach/roston/roston",
            "west" :"/wizards/detach/roston/roston23",
            "north":"/wizards/detach/roston/roston14"]));
}

  void reset() {

     if(!present("man"))
       {
       new("/wizards/detach/roston/t_man")->move(this_object()); 
       }

}                                                 
