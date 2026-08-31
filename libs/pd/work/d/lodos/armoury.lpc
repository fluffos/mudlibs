#include <std.h>
#include <lodos.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
 ::create();
   set_property("light", 1);
   set_property("indoors", 1);
   set_property("town", 1);
   set_property("light", 2);
   set_property("no attack", 1);
   set_property("no bump", 1);
   set_property("no steal", 1);
   set_property("building", 1);
   set_short("The Lodosian armoury");
   set_long("You have wandered into the Lodosian armoury. "
            "Syphon will buy and sell any type of armour. "
            "In the past, they armoury has handled some of "
            "the rarest armour in the lands. Through the window "
            "you can see a dirt road.");
   set_smell("default", "The smell of hot steal fills the air.");
   set_items(
	(["shop" : "You can buy and sell things here.",
	  "road" : "A small dirt road ouside the armoury."]) );
    set_exits(([
	        "south" : ROOMS"town1",
                "west" : ROOMS"town4"]));
}

void reset() {
  ::reset();
    if(!present("syphon")) 
      new(MOB"syphon")->move(this_object());
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
    this_player()->move_player(ROOMS"arm_stor", "north");
    return 1;
}

