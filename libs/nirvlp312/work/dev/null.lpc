#pragma strong_types

#include <light.h>

inherit "complex/room";

void configure() {
  room::configure();
  set_short("the bit-bucket", "in");
  set_long("This room has the shape of a large funnel, narrowing downwards.\n");
  set_light(LIGHT_LAMP);
  set_exits(({ ({ "room/void", "up" }),
               ({ "room/church", "down" })
           }));
  set_items(({ }));
}
