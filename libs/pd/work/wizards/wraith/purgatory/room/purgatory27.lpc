#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory27");
     set_short("Purgatory27");
     set_long("%^BOLD%^%^BLACK%^An old beaten path\n"
"%^BOLD%^%^WHITE%^This path follows the aged and beaten walls to the castle, "
"%^BOLD%^%^WHITE%^rats and other predators sometime prowl around here. ");
     set_night_long("%^BOLD%^%^BLACK%^An old beaten path\n"
"%^BOLD%^%^WHITE%^This path follows the aged and beaten walls to the castle, "
"%^BOLD%^%^WHITE%^rats and other predators sometime prowl around here. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"purgatory26", 
              "west" : ROOMS"purgatory28"]) );



}

void reset() {
 ::reset();
  if (!present("cockroach", this_object()))
    new(MOBS"cockroach" )->move(this_object());

 if (!present("cockroach 2", this_object()))
    new(MOBS"cockroach" )->move(this_object());

 if (!present("cockroach 3", this_object()))
    new(MOBS"cockroach" )->move(this_object());

 if (!present("cockroach 4", this_object()))
    new(MOBS"cockroach" )->move(this_object());

 if (!present("cockroach 5", this_object()))
    new(MOBS"cockroach" )->move(this_object());

 if (!present("cockroach 6", this_object()))
    new(MOBS"cockroach" )->move(this_object());

 if (!present("cockroach 7", this_object()))
    new(MOBS"cockroach" )->move(this_object());
}
