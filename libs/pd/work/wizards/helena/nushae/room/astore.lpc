#include <std.h>
#include <nushae.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_west", "west");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 2, "indoors" : 1, "no bump" : 1, "no attack" :1, "no magic" : 1 ]));
    set_short("Artos' Store");
    set_long(
      "%^ORANGE%^A%^MAGENTA%^rto%^ORANGE%^s' Armour Shop.%^RESET%^\n"
      "Artos sells and makes the best armour in all of NuShae.  The "
      "room is full of wearable items, fashionable and not, with a couple of things "
      "for sale on the hooks. He is always willing to buy and sell."
      );
    set_items(([
        "hooks" : "A wall of hooks displays and hangs the items for sale.",
        "items" : "From heavy armour to light fashion items, all made by the skilled armoursmiths of NuShae."
      ]));
    set_exits(([
        "east" : ROOMS"coral1"
      ]));
}

void reset() {
    ::reset();
    if(!present("artos")) 
        new(MOB"artos")->move(this_object());
}

int go_west() {
    if(!wizardp(this_player())) {
        message("my_action", "Artos holds you back.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " is held back from going west.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS"wstorage", "west");
    return 1;
}
