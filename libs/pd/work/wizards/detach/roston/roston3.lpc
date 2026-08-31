#include <std.h>
inherit ROOM;

void create() {
  ::create();    

   set_name("south of town square");
   set_items((["snow"   : "A very deep white snow",
               "dirt"  : "A light brown mixture"]));         
   set_properties(([ "light":2, "night light":3 ]));
   set_short("A dirt path");
   set_long("The scent of leather gets stronger. The ground seems "
            "to be coverd with foot prints, as you look around "
            "you notice patches off snow on the side of the path.");
   set_exits( (["south" : "/wizards/detach/roston/roston6",
                "north" : "/wizards/detach/roston/roston"]));
}
void reset() {

     if(!present("man"))
       {
        new("/wizards/detach/roston/t_man")->move(this_object());
       }

}
                                   
