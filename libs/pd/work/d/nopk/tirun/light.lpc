#include <std.h>
#include <tirun.h>
inherit ROOM;

void init() {
 ::init();
   add_action("go_west", "west");
}

void create() {
 ::create();
   set_properties(([
     "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1
   ]));
   set_short("Morian's house of light");
   set_long(
      "%^MAGENTA%^Morian's House of Light%^RESET%^\n"
      "Welcome to the lighting store. This is the inside of a small, "
     "darkened one-room shop. Guessing from the run down nature of this "
     "building, one would assume the business does not make quite a lot of "
     "money, but due to the shop's age, must make enough for Morian to live "
     "comfortably. Through a small window on the eastern wall, West Road can "
     "be seen.");
   set_items(([
     "road" : "The old dirt road is viewable through the window.",
     "window" : "Just a small window, barely large enough to get a good view "
                "outside.",
     "shop" : "The shop is old and run down."
   ]));
   set_exits(([
     "out" : ROOMS"sveros3"
   ]));
}

void reset() {
  ::reset();
    if(!present("morian")) 
      new(MOB"morian")->move(this_object());
}

int go_west() {
    if(!wizardp(this_player())) {
	message("my_action", "Morian stops you.", this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " is stopped by Morian from going west.", this_object(),
	  ({ this_player() }));
	return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
      " pushes Morian out of the way and leaves west.", this_object(),
      ({ this_player() }));
    this_player()->move_player(ROOMS"lights", "west");
    return 1;
}
