#include <std.h>
#include <lodos.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_down", "down");
}

void create() {
 ::create();
   set_properties((["light" : 1, "indoors" : 1, "town" : 1, "light": 2,
     "no attack" : 1, "no bump" : 1, "no steal" : 1, "building" : 1 ]));
   set_short("The Masters Weaponry");
   set_long("The inside of the weaponry has been fasioned like the inside "
     "of a cave, and through the dim lighting is the most breathtaking "
     "cave immaginable. Old lights line the walls, sheding just enough "
     "light to see. Weapons sit on shelves against the walls. There is "
     "a trapdoor near the counter.");
   set_items(
	(["shop" : "You can buy and sell things here.",
          "trapdoor":"It is probably where Gimli stores everything.",
	  "lights" : "They are of dwarven make.",
           "counter": "Gimli sits behind the counter.",
          "cave" : "The shop greatly resembles a cave.",
          "weapons" : "Many weapons, great and small.",
          "shelves" : "A variety of weapons lies upon these shelves."
   ]));
   set_exits(([
     "north": ROOMS"wroad1",
     "east" : ROOMS"stown1"]));
}

void reset() {
  ::reset();
    if(!present("gimli")) 
      new(MOB"gimli")->move(this_object());
}

int go_down() {
    if(!wizardp(this_player())) {
	message("my_action", "You dare not.", this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " advances towards the trapdoor, then steps back.", this_object(),
	  ({ this_player() }));
	return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
      " climbs into the trapdoor.", this_object(),
      ({ this_player() }));
    this_player()->move_player(ROOMS"wep_stor", "down");
    return 1;
}

