#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("North Rigor Road");
     set_short("North Rigor Road");
     set_long("%^BOLD%^%^WHITE%^North Rigor Road.\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, children are playing alongside "
"%^BOLD%^%^BLACK%^the gutters. The townspeople keep an eye out for their "
"%^BOLD%^%^BLACK%^charges. A large statue can be seen to the south, with open "
"%^BOLD%^%^BLACK%^road to the north.");
     set_night_long("%^BOLD%^WHITE%^North Rigor Road.\n"
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
 set_exits( (["north" : ROOMS"purgatory11", 
              "south" : ROOMS"purgatory1"]) );



}

void reset() {
 ::reset();
  if (!present("man", this_object()))
    new(MOBS"townsman" )->move(this_object());

  if (!present("child", this_object()))
    new(MOBS"pmalechild" )->move(this_object());
}

