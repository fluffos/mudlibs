#include <std.h>
inherit OBJECT;

void create() {
 ::create();
  set_name("key");
  set_short("A key");
  set_long("A blank key");
  set_weight(1);
  set_id( ({ "key", "blank key" }) );
}

int query_auto_load() { return 0; }

void initialize_key(string id) {
  set_short("A key");
  set_long("A key.\nID: "+id);
  set_id( ({ "key", "blank key", id }) );
}
