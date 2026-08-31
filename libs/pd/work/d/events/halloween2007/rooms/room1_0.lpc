#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  ::create();
  set_short("a dark pumpkin maze");
  set_properties( ([ "light":0, "night light":0, "town":1, "plain":1, "indoors":0 ]) );
  set_listen("default", "Eerie howling sounds float above the fog.");
  set_long(
    "This is a dark corner of the pumpkin patch. "
    "Tall fences block off most movement, and several large "
    "pumpkins on the ground make walking difficult. "
    "The shadows here seem deeper and the air is cold."
  );
  set_items( ([
    "corner" : "A corner of the pumpkin patch.",
    "fences" : "Wooden fences about 7 feet tall that keep out "
      "some animals, as well as pumpkin thieves.",
    "pumpkins" : "Large orange squash-like vegetables.",
    "shadows" : "Just a bit of darkness."
  ]) );

  set_exits(([
    "south" : H2K7ROOMS "room1_1"
  ]));
}

