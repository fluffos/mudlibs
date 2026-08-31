#include <std.h>
inherit ARMOUR;
void create() {
  ::create();
  set_name("boots");
  set_id( ({ "boots", "fire boots", "boots of fire" }) );
  set_short("%^RESET%^%^RED%^boots of fire%^RESET%^");
  set_long("They look pretty spiffy.");
  set_weight(6);
  set_curr_value("gold", 0);
  set_type("boots");
  set("read", "Why are you wasting your life trying to read fire?");
}

int query_auto_load() { return wizardp(this_player()); }
