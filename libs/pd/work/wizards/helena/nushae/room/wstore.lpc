#include <std.h>
#include <nushae.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_east", "east");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 2, "indoors" : 1, "no bump" : 1, "no attack" :1, "no magic" : 1 ]));
    set_short("Pelekko's Store");
    set_long(
      "%^BOLD%^%^BLACK%^Pelekko's Weapons Store.%^RESET%^\n"
      "Pelekko's store is the best weapons store in NuShae.  The "
      "room is full of clutter and half finished items, yet only a few things"
      "for sale on the rack. He is always willing to buy and sell."
      );
    set_items(([
        "rack" : "A strong wooden structure for holding weapons.",
        "weapons" : "Made by the finest weaponsmiths NuShae has."
      ]));
    set_exits(([
        "west" : ROOMS"t4"
      ]));
}

void reset() {
    ::reset();
    if(!present("pelekko")) 
        new(MOB"pelekko")->move(this_object());
}

int go_east() {
    if(!wizardp(this_player())) {
        message("my_action", "Pelekko holds you back.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " is held back from going east.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS"estorage", "east");
    return 1;
}
