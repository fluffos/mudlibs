
#include <guild.h>
#include <std.h>
#include <daemons.h>

inherit BEACH;
#include <ocean.h>

void create() {
    ::create();
    set_short("Illuminati beach");
    set_day_long("You are standing on a short stretch "
      "of beach on the north side of a tiny island. The sun beats down on you from on "
      "high. To the south a huge tower looms up out of the ground, reaching all the "
      "way to the clouds. This must surely be the Tower of Light, where it is said "
      "that the great Order of the Illuminati resides.");
    set_night_long("You are standing on a short stretch of beach on the "
      "north side of a tiny island. The starry night sky stretches out above you. To "
      "the south a huge tower looms up out of the ground, reaching far into the sky. "
      "This must surely be the Tower of Light, where it is said that the great Order "
      "of the Illuminati resides.");
    set_property("beach", 1);
    set_listen("default", "Waves crash onto the sand.");
    set_no_clean(1);
    set_properties((["light" : 1, "night light" : 0,]));
    set_exits(([
	"south": ROOMS"illuminati/new/entrance",

      ]));
    set_letter("k");
}
