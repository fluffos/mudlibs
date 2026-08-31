#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("An old beaten path");
     set_short("An old beaten path");
     set_long("%^BOLD%^%^BLACK%^An old beaten path\n"
"%^BOLD%^%^WHITE%^This path follows the aged and beaten walls to the castle, "
"%^BOLD%^%^WHITE%^rats and other predators sometime prowl around here. Off to "
"%^BOLD%^%^WHITE%^the east a large cairn can be seen surrounded by several "
"%^BOLD%^%^WHITE%^tombstones.");
     set_night_long("%^BOLD%^%^BLACK%^An old beaten path\n"
"%^BOLD%^%^WHITE%^This path follows the aged and beaten walls to the castle, "
"%^BOLD%^%^WHITE%^rats and other predators sometime prowl around here. An eerie "
"%^BOLD%^%^WHITE%^sense of death can be felt to the east.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"room1", 
              "west" : ROOMS"purgatory31"]) );



}

void reset() {
 ::reset();
  if (!present("rat", this_object()))
    new(MOBS"rat" )->move(this_object());

 if (!present("cougar", this_object()))
    new(MOBS"cougar" )->move(this_object());
}
