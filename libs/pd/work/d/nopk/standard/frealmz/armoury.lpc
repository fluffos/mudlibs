#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The Asgardian Weaponry");

   set_long("You have entered the Asgardian armoury. "
           "The armoury used to be an old blacksmith, but "
           "was reformed into a shop when Anathar retired. "
           "He now sells the armour that he once made. "
           "A door on the north wall leads into the storage "
           "room, where Anathar keeps everything for sale.");
  
  set_items(
	(["shop" : "You can buy and sell things here.",
	  "passage" : "Roger keeps the things he has for sale back there.",
	  "road" : "A small dirt road ouside the armoury."]) );
    set_exits( 
	      (["out" : "/d/standard/frealmz/town6"]) );
}

void reset() {
  ::reset();
    if(!present("anathar")) 
      new("d/standard/frealmz/mob/anathar")->move(this_object());
}

int go_north() {
    if(!wizardp(this_player())) {
	message("my_action", "You dare not.", this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " advances towards the door, then steps back.", this_object(),
	  ({ this_player() }));
	return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
      " swings open the back door and heads north.", this_object(),
      ({ this_player() }));
    this_player()->move_player("/d/standard/frealmz/arm_stor", "north");
    return 1;
}

