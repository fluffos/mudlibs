#include <std.h>

inherit ROOM;

void reset() {
  return;
}

void init() {
    ::init();
}

void create() {
    ::create();
    set("short", "Square");
    set("long", "You're in the city center square. East is the post office");
    set_exits(
      ([ "east" : "/d/standard/post"]));
    add_exit("/d/damned/virtual/room_15_15.world","world");
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set_property("no steal", 1);
    set_property("no castle", 1);
    set_property("no spell", 1);

}

