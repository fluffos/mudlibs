#include <std.h>
inherit ROOM;

void create() {
  ::create();      
reset ();
set_name("two south of town square");
set_properties((["light":2, "night light":3]));
set_short("A dirt path");
set_long("The scent of leather has grown stronger. There "
         "seems to a blanket on the ground. On the side "
         "of the path you can see patches of snow ");
set_items((["blanket" : "A large red blanket ",
            "snow"    : "A deep white snow ",
            "dirt"    : "A light brown mixture"]));

set_exits( ([ "north" : "/wizards/detach/roston/roston3",
              "south" : "/wizards/detach/roston/roston7" ]));
}                                    

void reset() {

     if(!present("man"))
       {
        new("/wizards/detach/man")->move(this_object());
       }

}                                                             
