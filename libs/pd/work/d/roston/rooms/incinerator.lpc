#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
 ::create();
   set_name("a house");
   set_items((["trash"   : "Trash covers the floor of this single room house.",
               ({"bed","mattress"}) : "The mattress is full of holes.  It would probably be easier to sleep on the floor.",
               "candle"  : "The candle is nearly burnt down to the base."]));         
   set_properties((["light":2, "night light":2]));
   set_short("A citizen's house");
   set_long("The inside of this house is very unkempt.  It "
            "would make someone wonder what kind of rodents "
            "are hidden in this trash heap.  A tattered mattress "
            "sits in one corner as a bed.  A candle lights the "
            "room, casting shadows that just make the room look dirtier.");

set_exits((["out": ROOMS "roston10"]));
 
}

  void reset() {

     if(!present("man"))
       {
       new(MOB "t_man")->move(this_object()); 
       }

} 
