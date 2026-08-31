#include <std.h>
#include <rain.h>

inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no steal", 1);
    set_short("General store");
    set_long("This is a small general store. Around you see small "
             "trinkets.  Mauder attends to little items, making them look nice.");
    set_smell("default","The smell of various food goods fills the air.");
    set_listen("default","Sounds of forest animals elves talking comes from outside the store.");
    set_items((["trinkets" : "Small things like broken blades and "
              "other useless stuff."]));
    set_exits((["west" : ROOMS"mpath5"]));
}

void reset() {
  ::reset();
    if(!present("mauder")) 
      new(MOB"mauder")->move(this_object());
}

int go_north() {
    if(!wizardp(this_player())) {
        message("my_action", "Mauder stops you.", this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " is stopped in their tracks by Mauder.", this_object(),
          ({ this_player() }));
        return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
      " pushes Mauder out of the way, and goes north.", this_object(),
      ({ this_player() }));
    this_player()->move_player(ROOMS"storage3", "north");
    return 1;
}
