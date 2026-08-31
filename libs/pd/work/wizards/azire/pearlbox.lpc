#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("pearl box");
  set_short("A little pearl box");
  set_long("This box is a little pearl box. Although it remains sealed shut, the lid is inscribed with the following: 'My heart is within this small vessel for you to carry with you always. -Azire'");
  set_id(({ "pearl box", "little pearl box" }));
  set_mass(1);
  set_curr_value("gold", 0);
}

int query_auto_load() {
  if(this_player()->query_name() == "nightshade")
    return 1;
  if(this_player()->query_name() == "azire")
    return 1;
}
