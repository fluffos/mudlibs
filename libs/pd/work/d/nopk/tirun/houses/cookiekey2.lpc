#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("cookie's key");
  set_short("Cookie's Master Key");
  set_id(({"key", "cookies key", "cookie_key_master"}));
  set_long("This golden key goes to the master bedroom of Cookie's house.");
  set_weight(1);
}

int query_auto_load() { if(this_player()->query_name() == "cookie") return 1;  if(wizardp(this_player())) return 1; return 0; }
