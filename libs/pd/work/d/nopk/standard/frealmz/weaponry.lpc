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

   set_long("Welcome to The Asgardian Weaponry! In the "
            "weaponry you will find all kinds of rare and "
            "expensive weapons for sale. Roger, the owner "
            "of the shop not only sells weapons, but will "
            "purchase any type of weapon from you! "
            "A small passageway leads north, into the "
            "storage room.");
  
  set_items(
	(["shop" : "You can buy and sell things here.",
	  "passage" : "Roger keeps the things he has for sale back there.",
	  "road" : "A small dirt road ouside the weaponry."]) );
    set_exits( 
	      (["out" : "/d/standard/frealmz/town3"]) );
}

void reset() {
  ::reset();
    if(!present("roger")) 
      new("d/standard/frealmz/mob/roger")->move(this_object());
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
    this_player()->move_player("/d/standard/frealmz/storage", "north");
    return 1;
}

