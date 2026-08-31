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
    set_short("Shirley's Weapons Shop.");
    set_long("The weapons shop is home to some very shiny looking weapons. Counters and wall mounts hold an assortment of the things that Shirley buys for her shop.  There is a sign hanging on the counter where Shirley does her business.");
    set_items(([
        "sign" : "A sign hanging on the countertop reads, 'All sales are final, although we buy items back at a lower price'.",
        "counters" : "Counters are all around the shop, with weapons that Shirley has for sale on them.",
        "wall mounts" : "Wall mounts hold up the finest of the weaponry.",
        ]));
    set_exits(([
        "out" : ROOMS "23"
      ]));
}

void reset() {
    ::reset();
    if(!present("shirley")) 
        new(MOB"shirley")->move(this_object());
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
    this_player()->move_player(ROOMS "wepstore", "east");
    return 1;
}
