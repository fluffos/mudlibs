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
    set_short("The Roston general store");
    set_long("Welcome to the general store. If you "
         "need to buy or sell any supplys talk to "
         "Percivus, the shop owner. Pervivus will buy "
         "almost anything from anyone. A small door "
         "leads north, into the storage room.");
  set_items(
	(["shop" : "You can buy and sell things here."]));
    set_exits( 
	      (["down" : "/wizards/detach/roston/roston16"]) );
}

void reset() {
  ::reset();
    if(!present("percivus")) 
      new("/wizards/detach/roston/mob/percivus")->move(this_object());
}

int go_north() {
    if(!wizardp(this_player())) {
	message("my_action", "Percivus stops you.", this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " is stopped in their tracks by Percivus.", this_object(),
	  ({ this_player() }));
	return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
      " pushes Percivus out of the way, and goes north.", this_object(),
      ({ this_player() }));
    this_player()->move_player("/wizards/detach/roston/storage", "north");
    return 1;
}

