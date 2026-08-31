#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("black gate key");
    set_long("This large key is made of a black metal alloy.");
    set_id(({ "key", "black key", "gate key" }));
    set_short("a black gate key");
}
int query_auto_load()  { 
  if(this_player()->query_level() < 20) return 0;
  return 1; }

