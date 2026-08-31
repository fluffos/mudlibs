#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Jack's Shop");
     set_short("Jack's Shop");
     set_long("%^BOLD%^%^CYAN%^Jack's Shop.%^RESET%^\n"
"%^BOLD%^%^BLACK%^Through a smoke filled %^WHITE%^haze%^BLACK%^, Jack the storekeeper can be seen "
"%^BOLD%^%^BLACK%^with his back to the door. Barely noticible on the walls "
"%^BOLD%^%^BLACK%^through the %^WHITE%^smoke%^BLACK%^ hang various parts to different animals. A "
"%^BOLD%^%^BLACK%^rather large counter sits at the back of the store, it looks "
"%^BOLD%^%^BLACK%^to be made of old %^RESET%^%^ORANGE%^bones%^BOLD%^%^BLACK%^..... A small sign rests "
"%^BOLD%^%^BLACK%^off to the side. ");
     set_properties(([
        "light"       : 2,
"no attack"   : 1,
        "no bump"     : 1,
        "indoors"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["south" : ROOMS"purgatory5", ]) );


    set_items( ([
        "counter"  : "The counter has been made from the discarded bones of Jacks victims.",
        ({"wall", "walls"}) : "The walls are covered with the dried limbs of unfortunate travelers and animals.",
        "haze" : "A dense haze of smoke fills the room.",
        "door" : "The inside of the door has been adorned with the teeth of all Jack's victims."
      ]) );

}

void reset() {
 ::reset();
  if (!present("jack", this_object()))
    new(MOBS"jack" )->move(this_object());
}
