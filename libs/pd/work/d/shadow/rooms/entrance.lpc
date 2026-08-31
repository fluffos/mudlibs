#include <std.h>;
#include <daemons.h>
#include <shadow.h>;

inherit PIER;

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 0);
    set_property("night light", 0);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
  set("short","Pathway to city");
  set("long","The pier here leads to a rocky shore.  This entire "
    "area looks very creepy.  The sky to the east is dark... more "
    "than your average night.  Something very strange has happened to "
    "this land.  The dock leads to the land eastward.");
  set_smell("default","The smell of the sea is here.");
  set_listen("default","The water occasionally crashes on the rocks.");
  set_items((["sky":"The sky seems to darken as you head east.",
    "dock":"The sturdy dock takes you to the land eastward.",
    "rocks":"If it weren't for this dock, it'd be impossible to land here"]));
  set_exits((["east":ROOMS "landing"]));
}

int *query_coords() { return OCEAN_D->query_coord_from_letter("d"); }
