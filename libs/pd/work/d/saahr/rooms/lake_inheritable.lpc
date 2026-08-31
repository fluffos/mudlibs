
#include <std.h>
#include <saahr.h>

inherit ROOM;
inherit SWIM_CODE;

string query_long();

void create() {
  room::create();
  set_properties((["water":1, "indoors":0, "light":2, "night light":0]));
  set_short("a lake");
}

void init() {
  room::init();
  swim_code::init();
}

string query_long() { return "%^CYAN%^"+(room::query_long())+"%^RESET%^"; }

