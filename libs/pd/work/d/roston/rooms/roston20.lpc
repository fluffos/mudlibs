#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();           
    reset ();  
    set_name("palace room");
    set_properties((["light":2, "night light":3]));
    set_short("A white palace entrance");
    set_long("The royal family had this palace built very large. "
      "The glow from the walls seems to light the entire room. "
      "There are flowers all over, and the path seems to "
      "fade into them.");
    set_items((["palace" : "A huge white palace",
	"snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));  

    set_exits( (["west"  : ROOMS "roston19",
	"south" : ROOMS "garden" ]));

}                                                          

void reset() {

    if(!present("royal guard"))
    {
	new(MOB "loyalknight")->move(this_object());
	new(MOB "royalguard")->move(this_object());
	new(MOB "prince")->move(this_object());
    }

}                                           

