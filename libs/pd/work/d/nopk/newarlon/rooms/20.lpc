#include <std.h>
#include <arlon2.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_east", "east");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no steal" : 1, "no magic" : 1 ]));
    set_short("Geda's Armour Shop.");
    set_long("The armour shop is very neat and tidy.  There are pieces of armour with price signs under them.  A sign hangs on the countertop where Geda, the shopkeeper stands.  This is a very polished looking shop.");
    set_items(([
        "sign" : "A sign hanging on the countertop reads, 'All sales are final, although we buy items back at a lower price'.",
        "armour" : "Pieces of various armour sold to the shop are hanging on the walls and on racks.",
      ]));
    set_exits(([
        "out" : ROOMS "23"
      ]));
}

void reset() {
    ::reset();
    if(!present("geda")) 
        new(MOB"geda")->move(this_object());
}

int go_east() {
    if(!wizardp(this_player())) {
        message("my_action", "The storeroom isn't meant for players to visit.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " begins to leave east then thinks better of it.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS "armstore", "east");
    return 1;
}

