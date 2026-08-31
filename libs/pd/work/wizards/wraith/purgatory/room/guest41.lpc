#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("guest41");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^This room has been taken over by the Warmaster of The "
"%^ORANGE%^Barbarians. Not many people, including the Warmaster's own, "
"%^ORANGE%^make it out of this room alive. Bodies of the slain opponents "
"%^ORANGE%^lay around like so much trash. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["west" : ROOMS"guest24"]) );

    set_items( ([
         "bodies" : "These bodies have been mutilated and ripped apart so bad they are unrecognizable."
      ]) );


}

void reset() {
 ::reset();
  if (!present("barbarian", this_object()))
    new(MOBS"warmaster" )->move(this_object());
}
