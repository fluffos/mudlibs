#include <std.h>
#include <purgatory.h>

inherit BEACH;

void create() {
    ::create();
    set_name("A black sandy beach");
    set_short("A black sandy beach");
    set_long("The %^BOLD%^%^BLACK%^black%^RESET%^ sand stretches to the " 
      "north, animal tracks lay scattered all around. The forest is a lot closer "
      "then it was before, animals can be seen through the leaves. Strange tracks "
      "run up and down the beach and deep into the forest. Odd looking shells have been scattered about.");
    set_night_long("Darkness envelops the area, making it hard to make out shapes "
      "that arent close by. Shapes move around in the cover of night, their tracks the only "
      "hint that anything has been here. ");
    set_properties(([
	"light"       : 1,
	"night light" : 0,
	"outdoors"    : 1, 
	"beach"       : 1,

      ]));
    set_listen("default","Waves crash against the shore, blowing mist into the air");
    set_smell("default","Saltwater and other smells of the sea permeate the air");
    add_pre_exit_function("northeast", "go_northeast");
    set_exits( ([
	"northeast" : ROOMS"landing",
	"northwest" : ROOMS"beach5"]) );


    set_items( ([
	"sand" : "%^BOLD%^%^BLACK%^The dark sandy beach runs out of sight to the north and south. Little bits of %^RESET%^white%^BOLD%^%^BLACK%^ shells have been scattered about the footprints.",
	"blood" : "Small amounts of sticky %^BOLD%^%^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^RESET%^ lies in pools near the graveyard.",
	"trees" : "Shadows flicker and move about the trees to the west. It would be best if you used a large amount of caution while exploring.",
	"beach" : "The beach is made out of %^BOLD%^%^BLACK%^ black sand %^RESET%^ and runs to the north and south.",
	"footprints" : "Many footprints have been embedded into the soft sands, leaving criss-crossing trails everywhere.",
      ]) );

}

void reset() {
    ::reset();
    if (!present("flea", this_object()))
	new(MOBS"flea" )->move(this_object());

}
int go_northeast() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
