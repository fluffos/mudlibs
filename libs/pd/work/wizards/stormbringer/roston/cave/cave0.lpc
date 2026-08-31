#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["snow"   : "A very deep white snow",
	"cracks" : "A huge hole in the ground",
	"vapors" : "A weird looking mist",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A snow path");
    set_long("This room is the hotest place you have ever been "
      "hot vapors rush up from under neath you, and warm "
      "your body up.");

    set_exits( (["down"  :ROSTON"cave/cave0"]));  
}
