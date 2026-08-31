#include <std.h>
#include <lodos.h>
inherit ROOM;
void create() {
    ::create();
    set_name("west of lodos square");
    set_properties((["light":2,"nightlight":3]));
    set_short("secret building");   
    set_long("");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"])); 
    set_exits((["east" : ROOMS "s11", "south" : ROOMS "s13", "north" : ROOMS "s14", "west" : ROOMS "s15"]));
}    
