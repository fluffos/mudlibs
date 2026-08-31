#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("open_door", "open");
}
void create() {
    ::create();
     set_name("guest23");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^The hallway in this part of the Guest Quarters looks like a "
"%^ORANGE%^battle was just finished. Bloodstains and a small amount of "
"%^ORANGE%^gore decorate the walls. A shoddily build door leans on its "
"%^ORANGE%^hinges to the east. The walkway leads to the north and south.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["south" : ROOMS"guest22", 
              "north" : ROOMS"guest24"]) );

    set_items( ([
        "walls" : "The entrails of a servant have dried to the wall",
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters, years of use have polished the stone to a high sheen."
      ]) );


}

int open_door(string str) {
    if(!str) {
        notify_fail("open what?\n");
        return 0;

    }
    if(str != "door") {
        notify_fail("You can't open that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" opens a door.", this_object(), ({ this_player() }));
    message("info", "You open a door.", this_player());
    add_exit(ROOMS"guest40", "enter");
    call_out("go_hole", 60);
    return 1;
}

void go_hole() {
    message("info", "The door slams shut by itself.",
all_inventory(this_object()));
    remove_exit("enter");
}

void reset() {
 ::reset();
  if (!present("barbarian", this_object()))
    new(MOBS"barbarian" )->move(this_object());

  if (!present("barbarian 2", this_object()))
    new(MOBS"barbarian" )->move(this_object());

  if (!present("barbarian 3", this_object()))
    new(MOBS"barbarian" )->move(this_object());
  if (!present("barbarian 4", this_object()))
    new(MOBS"barbarian" )->move(this_object());
  if (!present("barbarian 5", this_object()))
    new(MOBS"barbarian" )->move(this_object());

  if (!present("guard", this_object()))
    new(MOBS"barguard" )->move(this_object());
  if (!present("guard 2", this_object()))
    new(MOBS"barguard" )->move(this_object());

}
