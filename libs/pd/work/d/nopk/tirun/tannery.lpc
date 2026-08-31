#include <std.h>
#include <tirun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_west", "west");
}
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1 ]));
    set_short("Garon's Tannery.");
    set_long(
      "Garon's Tannery.\n"
      "Skins lie in piles around the shop in different stages of tanning. Large vats "
      "behind the counter in the back of the shop sit, boiling, atop large fires. "
      "Here in front of the counter, different hides and skins are on display for sale." 
      );
    set_items(([
        "vats" : "Large couldrans used in tanning.",
        "skins" : "Skins of different types and sizes.  Most have not not been tanned."
      ]));
    set_exits(([
       "out" : ROOMS"sganthus2"
      ]));
    set_smell("default", "The stech of the tannery vats is almost overpowering.");
    set_listen("default", "The roaring of the fires is is loud.");
}
void reset() {
    ::reset();
    if(!present("garon")) 
        new(MOB"garon")->move(this_object());
}
int go_west() {
    if(!wizardp(this_player())) {
        message("my_action", "Garon holds you back.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " is held back from going west.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS"skinstorage", "west");
    return 1;
}
