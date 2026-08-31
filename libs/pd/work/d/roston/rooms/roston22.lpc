#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();                     

    set_name("east of town square");
    set_items((["dirt"  : "A light brown mixture ",
	"church"  : "The large white church glows with holiness"])); 
    set_properties((["light":2 ,"night light":3]));
    set_short("A dirt path");
    set_long("This is the front of a large white church.  Snow is nowhere to be "
      "found.  The whole church is bathed in a white light.");

    set_exits( ([ "enter" : ROOMS "Church",
	"west" :  ROOMS "roston21" ]));
}                                             
