#include <room.h>
#include <areas.h>

void
create_room() {

    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_OUTDOORS);

    set_short("Dark forest");
    set_long("You are on a trail in a dark forest. The forest is getting"+
      " dense in the west.");

    add_exit("east", AREA_WEST+"plains/deep_forest1");
    add_exit("west", AREA_TRISTEZA "duel/virtual/world/rooms/8_0");

}
