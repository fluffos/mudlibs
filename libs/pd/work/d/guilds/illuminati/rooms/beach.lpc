#include <std.h>
#include <illuminati.h>
#include <daemons.h>

inherit DOCKS;

void create() {
   ::create();
     set_short("Illuminati Docks");
     set_day_long("%^BOLD%^WHITE%^You are standing upon the docks of a small island. Several boats are tied up here and he sun beats down from on high. To the south a huge tower looms up out of the ground, reaching all the way to the clouds. This must surely be the Tower of Light, where it is said that the great Order of the Illuminati resides.%^RESET%^");
     set_night_long("%^CYAN%^You are standing upon the docks of a small island. The night sky stretches out above you, the stars illuminating a few ships tied up here. To the south a huge tower looms up out of the ground, reaching far into the sky. This must surely be the Tower of Light, where it is said that the great Order of the Illuminati resides.%^RESET%^");
     set_property("beach", 1);
     set_listen("default", "Waves crash against the docks.");
     set_properties((["light" : 1, "night light" : 0,]));
     set_exits(([
                //"south": ILROOM"entrance",
		]));
set_letter("k");
}
