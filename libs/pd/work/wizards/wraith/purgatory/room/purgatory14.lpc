#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory14s");
     set_short("Purgatory14s");
     set_long("%^BOLD%^%^WHITE%^South Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, another batch of those strange "
"%^BOLD%^%^BLACK%^children poke along the gutter looking for something to play "
"%^BOLD%^%^BLACK%^with. The Purgatory square is visible to the north.");
     set_night_long("%^BOLD%^%^WHITE%^South Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, only the dumber children and "
"%^BOLD%^%^BLACK%^parents have stayed out to this late hour. Everything is "
"%^BOLD%^%^BLACK%^shrouded in darkness.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"purgatory9", 
              "south" : ROOMS"purgatory19"]) );



}

void reset() {
 ::reset();
  if (!present("man", this_object()))
    new(MOBS"townsman" )->move(this_object());

 if (!present("man 2", this_object()))
    new(MOBS"townsman" )->move(this_object());

 if (!present("man 3", this_object()))
    new(MOBS"townsman" )->move(this_object());

}
