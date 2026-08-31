#include <std.h>
#include <h2k7.h>

inherit PUMPKINROOM;

void create() {
  set_server(H2K7SERVER1);
  ::create();

  set_exits(([
    "north" : H2K7ROOMS "room6_17",
    "northeast" : H2K7ROOMS "room7_17",
    "west" : H2K7ROOMS "room5_18",
    "out" : load_object(H2K7D)->query_entrance()
  ]));
}
