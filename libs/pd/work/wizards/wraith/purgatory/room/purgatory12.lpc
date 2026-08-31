#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory12w");
     set_short("Purgatory12w");
     set_long("%^BOLD%^%^WHITE%^West Mortis Road\n"
"%^BOLD%^%^BLACK%^Traveling along Mortis Road, children are playing alongside "
"%^BOLD%^%^BLACK%^the gutters. The townspeople keep an eye out for their "
"%^BOLD%^%^BLACK%^charges. A large statue can be seen to the east, with open "
"%^BOLD%^%^BLACK%^road to the west.");
     set_night_long("%^BOLD%^%^WHITE%^West Mortis Road\n"
"%^BOLD%^%^BLACK%^Traveling along Mortis Road, only the dumber children and "
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
 set_exits( (["west" : ROOMS"purgatory13", 
              "east" : ROOMS"purgatory7"]) );



}
void reset() {
 ::reset();
  if (!present("child", this_object()))
    new(MOBS"pchild" )->move(this_object());

  if (!present("child 2", this_object()))
    new(MOBS"pchild" )->move(this_object());

  if (!present("child 3", this_object()))
    new(MOBS"pchild" )->move(this_object());

  if (!present("child 4", this_object()))
    new(MOBS"pchild" )->move(this_object());

  if (!present("child 5", this_object()))
    new(MOBS"pchild" )->move(this_object());
}
