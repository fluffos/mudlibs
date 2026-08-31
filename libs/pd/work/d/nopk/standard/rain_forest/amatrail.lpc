#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
    set_property("forest", 1);
    set_properties( ([ "light" : 3, "night light" : 1]) );
   set_name("amazon trail");
   set_long("There are many trees and shrubs around. The forest is thin here."
          " Off to the south there looks like there is a village of a sort."
          " The path also leads back northwest.");
   set_short("amazon trail");
   set_items((["trees" : "There are many different types of trees around you",
               "bushes" : "There are a few bushes and some have fruits on them."]));
   set_exits((["northwest" : ROOMS"dirtse",
               "north" : ROOMS"corinthor/rooms/entry1"]));
  }
