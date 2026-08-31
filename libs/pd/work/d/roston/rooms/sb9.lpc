#include <std.h>
#include <roston.h>
inherit ROOM;
void create() {
    ::create();
    set_name("west of roston square");
    set_properties((["light":2,"nightlight":3]));
    set_short("secret building");   
    set_long("");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"])); 
    set_exits((["south" : ROOMS "sb10", "down" : ROOMS "sb8"]));
}                                                     
void reset() {
    ::reset();
    if(!present("abominable")) 
	new(MOB"abominable")->move(this_object());
}  
