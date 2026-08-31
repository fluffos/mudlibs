#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory22s");
     set_short("Purgatory22s");
     set_long("%^BOLD%^%^WHITE%^South Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, the gatehouse ccan be seen to the "
"%^BOLD%^%^BLACK%^south. A couple guards can usually be seen taking a break on "
"%^BOLD%^%^BLACK%^this side of the gates. The Purgatory square is visible to "
"%^BOLD%^%^BLACK%^the north. A pair of strange looking gates stand here to lock "
"%^BOLD%^%^BLACK%^everyone in.");
     set_night_long("%^BOLD%^%^WHITE%^South Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, A pair of Obsidian gates stand in "
"%^BOLD%^%^BLACK%^the way.  Everything is shrouded in darkness." );
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"purgatory19", 
              "gates" : ROOMS"gatehouse"]) );



}

void reset() {
 ::reset();
  if (!present("skeleton", this_object()))
    new(MOBS"skeleton" )->move(this_object());

 if (!present("skeleton 2", this_object()))
    new(MOBS"skeleton" )->move(this_object());


}
