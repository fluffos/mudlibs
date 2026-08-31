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
    set_long("This is a great place in the cave. It is where the "
      "Polar Bears rest during the long winter. Most Polar "
      "Bears just stay here to have there babies then leave "
      "but some come to sleep to let the winter pass. The "
      "vapors here seem to be changing to a red color.");

    set_exits( (["north"  : ROSTON"cave/cave5",
	"south"  : ROSTON"cave/cave2",
	"east"   : ROSTON"cave/cave10",
	"west"   : ROSTON"cave/cave4"]));
}



void reset() {
    ::reset();

    if(!present("bear"))                    
    {
	new(MOB"p_bear")->move(this_object());
    }

}      
