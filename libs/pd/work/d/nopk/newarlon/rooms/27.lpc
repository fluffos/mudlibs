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
    set_short("Murlen's Supply Shop.");
    set_long("The supply shop is a very mysterious room, with many small tables that have incense burning and items for sale.  This shop seems to be for everything from bags and packs to magical items.  There is a sign hanging on the counter where Murlen seems to handle transactions.");
    set_items(([
        "sign" : "A sign hanging on the countertop reads, 'All sales are final, although we buy items back at a lower price.'",
        "tables" : "The tables all have bright and vibrant tablecloths.",
        "incense" : "The smoke from the incense can be seen throughout the shop.",
        ]));
    set_exits(([
        "out" : ROOMS "23"
      ]));
}

void reset() {
    ::reset();
    if(!present("murlen")) 
        new(MOB"murlen")->move(this_object());
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
    this_player()->move_player(ROOMS "supstore", "east");
    return 1;
}

