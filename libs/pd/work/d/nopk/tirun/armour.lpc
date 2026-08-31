#include <std.h>
#include <tirun.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_east", "east");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("The Tirun Armoury.");
    set_long(
      "%^MAGENTA%^The Tirun Armoury.%^RESET%^\n"
      "The shop is clean and orderly. Shelves and hooks hold goods that "
      "are for sale, primarily shields and sets of armour.  A counter "
      "along the north wall looks to be where all business transactions are "
      "completed.  All the goods appear to be armour.  A wooden sign hangs on "
      "the front of the counter.  The floor of the armoury is made of polished "
      "grey stone."
    );
    set_items(([
        "stone" : "Polished grey stone. It makes the armoury look very clean.",
        "sign" : "The sign reads: Propety of the Tirun Government. All goods approved and commissioned for sale.",
        "shelves" : "A wooden structure made for holding goods.",
        "counter" : "An old used and worn wooden counter.",
      ]));
    set_exits(([
        "out" : ROOMS"square8"
      ]));
}

void reset() {
    ::reset();
    if(!present("drendun")) 
        new(MOB"official")->move(this_object());
}

int go_east() {
    if(!wizardp(this_player())) {
        message("my_action", "That would surely be against the law.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " begins to leave east then thinks better of it.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS"astorage", "east");
    return 1;
}


