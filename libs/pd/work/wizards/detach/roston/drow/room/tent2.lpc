#include <std.h>
#include <roston.h>
inherit ROOM;
void init() {
    ::init();

add_action("leap_portal" , "leap");
}
void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("%^BOLD%^%^YELLOW%^This is the room of the Evil Pyromancer. "
       "He stays in this room all day and all night, he wont leave "
       "till the war starts. There is a glowing yellow aura around "
     "the pyromancer.");

set_exits( ([ "out" : DROWROOM"tent1" ]));
}                                                             
void reset() {
 

  ::reset();
     if(!present("evil pyromancer"))
       {
       new(DROWMOB"pyro")->move(this_object());
   }
}

int leap_portal(string what) {
  if (what != "portal") return 0;
this_player()->move_player("/wizards/detach/roston/guild/room1");
    return 1;
}


