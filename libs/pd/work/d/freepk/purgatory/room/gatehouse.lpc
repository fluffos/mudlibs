#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     add_pre_exit_function("gates","go_stairs");
     set_name("Southern Gatehouse");
     set_short("Southern Gatehouse");
     set_long("%^BOLD%^%^WHITE%^The Gatehouse.\n"
"%^BOLD%^%^BLACK%^A huge cast iron gate is housed in its tracks in this "
"%^BOLD%^%^BLACK%^gatehouse. One guard sits at his desk filling out forms while "
"%^BOLD%^%^BLACK%^the others poke fun at each other. To the left is a small "
"%^BOLD%^%^BLACK%^stairway that leads up into the gatehouse. Rigor Road can be "
"%^BOLD%^%^BLACK%^seen through the gates.");
     set_night_long("%^BOLD%^%^WHITE%^The Gatehouse.\n"
"%^BOLD%^%^BLACK%^A huge cast iron gate is housed in its tracks in this "
"%^BOLD%^%^BLACK%^gatehouse. One guard sits at his desk filling out forms while "
"%^BOLD%^%^BLACK%^the others poke fun at each other. To the left is a small "
"%^BOLD%^%^BLACK%^stairway that leads up into the gatehouse. Rigor Road can be "
"%^BOLD%^%^BLACK%^seen through the gates.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["stairs" : ROOMS"gatehouseup", 
              "gates" : ROOMS"purgatory22",
              "south" : "/d/freepk/purgatory/pforest/room/200"]) );



}

void reset() {
 ::reset();
  if (!present("guard", this_object()))
    new(MOBS"regguard" )->move(this_object());

  if (!present("guard 2", this_object()))
    new(MOBS"regguard" )->move(this_object());

  if (!present("guard 3", this_object()))
    new(MOBS"regguard" )->move(this_object());

  if (!present("guard 4", this_object()))
    new(MOBS"regguard" )->move(this_object());

  if (!present("sign", this_object()))
    new(ITEMS"sign" )->move(this_object());
}
int go_stairs() {
  if (this_player()->query_level() < 35) return 0;
 return 1;}
