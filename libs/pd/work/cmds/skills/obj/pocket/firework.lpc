#include <std.h>
#include <rooms.h>
inherit OBJECT;
void removeme();
void create() {
  ::create();
  set_name("a small firework");
  set_short("a small firework");
  set_long("This is just a little old firework.  You can <light> the firework to shoot it into the sky.");
  set_weight(5);
  set_id( ({ "firework", "small firework", "little firework" }) );
  set_value(0);
  set_property("no auction", 1);
  set_property("juggle", 1);
}
void init() {
  ::init();
  add_action("light", "light");
}
int light(string str) {
  object tp = this_player();
  object *who = filter(users(), (: environment($1) && !(environment($1)->query_property("indoors")) :) );
  if (!str || present(str, tp) != this_object())
    return notify_fail("Light what?\n");
  if (environment(tp)->query_property("indoors"))
    return notify_fail("You can't light the firework while indoors!\n");
  message("firework", "%^BOLD%^A small firework %^YELLOW%^sparkles and fizzes%^WHITE%^ in the air.%^RESET%^", who);
  call_out("removeme", 0);
  this_object()->move(ROOM_CACHE);
  return 1;
}
void removeme() { this_object()->remove(); }
