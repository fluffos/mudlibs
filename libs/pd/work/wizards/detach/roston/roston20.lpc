#include <std.h>
inherit ROOM;

void create() {
  ::create();           
reset ();  
set_name("palace room");
set_properties((["light":2, "night light":3]));
set_short("A white palace entrance");
set_long("The white palace is hudge, its built for a  "
         "royal family. The glow from the place lights "
         "the hole room the path seems to fade away "
         "there are flowers all over.");
set_items((["palace" : "A hudge white palace",
            "snow"   : "A very deep white snow",
             "dirt"  : "A light brown mixture"]));  
   
set_exits( (["west" : "/wizards/detach/roston/roston19",
             "south" : "wizards/detach/roston/garden" ]));

}                                                          

void reset() {

     if(!present("royal guard"))
       {
       new("/wizards/detach/roston/loyalknight")->move(this_object());
       new("/wizards/detach/roston/royalguard")->move(this_object());
       new("/wizards/detach/roston/prince")->move(this_object());
       }

}                                           

