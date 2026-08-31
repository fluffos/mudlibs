#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("cookie's key");
  set_short("Cookie's Key");
  set_id(({"key", "cookies key", "cookie_key"}));
  set_long("This small metal key goes to the locks of Cookie's house.");
  set_weight(1);
}

int query_auto_load() { if(this_player()->query_name() == "cookie") return 1;  if(wizardp(this_player())) return 1; return 0; }
