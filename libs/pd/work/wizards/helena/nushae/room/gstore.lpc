#include <std.h>
#include <nushae.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 2, "indoors" : 1, "no bump" : 1, "no attack" :1, "no magic" : 1 ]));
    set_short("Sanya's Store");
    set_long(
      "%^BOLD%^%^BLUE%^S%^WHITE%^any%^BLUE%^a's General Store.%^RESET%^\n"
      "Sanya's store is the only general store in NuShae.  The "
      "room is neat and tidy, with only a few things for sale on the counter. "
      "Food and drink is for sale here as well."
      );
    set_items(([
        "counter" : "A wooden structure for holding goods.",
        "goods" : "Food and drinks are amoung the goods, Sanya's way of making an extra bit of money."
      ]));
    set_exits(([
        "south" : ROOMS"t3"
      ]));
}

void reset() {
  ::reset();
    if(!present("sanya")) 
        new(MOB"sanya")->move(this_object());
}

int go_north() {
    if(!wizardp(this_player())) {
        message("my_action", "Sanya holds you back.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " is held back from going north.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS"nstorage", "north");
    return 1;
}
