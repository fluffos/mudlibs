#include <std.h>
#include <tirun.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_west", "west");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Xor's Weaponry");
    set_long(
      "%^MAGENTA%^Xor's Weapon Shop.%^RESET%^\n"
      "Xor's weaponry is the only weapon shop in all of Tirun.  The "
      "walls are lined with shelves that are piled with boxes of different "
      "weapons.  Xor delivers and buys all types of weapons, provided "
      "they have a retail value."
      );
    set_items(([
        "shelves" : "A wooden structure for holding goods.",
        "weapons" : "Most of the weapons are packed away ready for delivery."
      ]));
    set_exits(([
        "out" : ROOMS"square8"
      ]));
}

void reset() {
    ::reset();
    if(!present("xor")) 
        new(MOB"xor")->move(this_object());
}

int go_west() {
    if(!wizardp(this_player())) {
        message("my_action", "Xor holds you back.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " is held back from going west.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS"wstorage", "west");
    return 1;
}

