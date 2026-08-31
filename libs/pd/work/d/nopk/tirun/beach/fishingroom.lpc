#include <std.h>

inherit VMAPROOM;
inherit "/std/room/fishing";

void init() {
  vmaproom::init();
  fishing::init();
}

varargs void create(object map, int x, int y, int z) {
  vmaproom::create(map, x, y, z);
  fishing::create();
}

void reset() {
  vmaproom::reset();
  fishing::reset();
}
