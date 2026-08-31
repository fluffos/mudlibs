#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("West Mullin Road.");
    set_long(
      "Mullin Road is lightly traveled. The city wall stands south of here.  "
      "Houses line the road to the north. The ancient stones underfoot running "
      "east and west make the road easy to follow. "
);
    set_night_long("Running east and west through the southwest section of Tirun, "
"Mullin Road is peaceful at night.  Shadows to the north show "
"themselves to be buildings.  The city walls looms as a "
"ominous shadow to the south.  The stones underfoot are hard "
"to make out in the darkness.");
    set_exits( 
              (["west" : ROOMS"wmullin6",
                "east" : ROOMS"wmullin4",
       "enter house" : ROOMS"hhouse/1",
]) );
add_exit_alias("enter house", "house");
add_exit_alias("enter house", "enter");
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
    new("/d/nopk/tirun/obj/houses/hhouse")->move(this_object());
}
