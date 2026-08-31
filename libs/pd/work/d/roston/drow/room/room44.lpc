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
        "of the drow army all around, the members seem to have very "
      "strange looks on there face. ");

set_exits( ([ "east" : DROWROOM"room43",
              "north" : DROWROOM"room46",
              "south" : DROWROOM"room45",
              "west" : DROWROOM"room47" ]));
}                                                
void reset() {
 

  ::reset();
     if(!present("archer"))
       {

new(DROWMOB"archer")->move(this_object());

new(DROWMOB"calvary")->move(this_object());
   }
}
