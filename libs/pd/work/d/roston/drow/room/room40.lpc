#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "tent"  :"This tent is very the army comes to rest",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston the town to the south. There is members of the "
        "of the drow army all around, you can hear voices to the "
       "west, The Drows seem to just laying in the tents talking. ");

set_exits( ([ "east" : DROWROOM"room39",
              "north" : DROWROOM"room42",
              "south" : DROWROOM"room41",
              "west" : DROWROOM"room43" ]));
}                                                
void reset() {
 

  ::reset();
     if(!present("archer"))
       {

new(DROWMOB"archer")->move(this_object());

new(DROWMOB"archer")->move(this_object());
   }
}
