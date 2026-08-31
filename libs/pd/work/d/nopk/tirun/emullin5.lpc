#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("East Mullin Road.");
    set_long(
      "Mullin Road is lightly traveled.  The city wall stands south of here.  "
      "Houses line the road to the north.  The ancient stones underfoot running "
      "The ancient stones underfoot running northwest and east make the road easy "
);
    set_night_long(
      "Running east and west through the southeast section of Tirun, "
      "Mullin Road is peaceful at night.  Shadows to the north show themselves "
      "to be buildings.  The city wall looms as a ominous shadow to the south.  "
      "The stones underfoot are hard to make out in the darkness. "
);
    set_exits( 
              (["west" : ROOMS"emullin4",
                "northeast" : ROOMS"sparthos6",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
