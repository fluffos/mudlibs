#include <std.h>
#include <roston.h>
 
inherit ROOM;
 
void create() {
 ::create();
   set_name("trash house");
   set_items(([             "trash" : "Trash covers the floor of this single room house.",
               ({"bed","mattress"}) : "The mattress is full of holes and looks uncomfortable.",
                           "candle" : "The candle is nearly burned down to the base."]));         
   set_properties((["light":2, "night light":2, "indoors":1]));
   set_short("A citizen's house");
   set_long("The inside of this house is very unkept.  Trash "
            "is everywhere underfoot.  A tattered mattress "
            "sits in one corner.  A single candle lights the "
            "place, casting wierd shadows over the room.");
   set_exits((["out": ROOMS "roston10"]));
}
 
void reset() {
   if(!present("townsman")){
      new(MOB "t_man")->move(this_object()); 
     }
} 
