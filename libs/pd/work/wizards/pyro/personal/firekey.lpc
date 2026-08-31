#include <std.h>
inherit OBJECT;

void create() {
 ::create();
  set_name("key");
  set_short("%^RESET%^%^RED%^a key of pure fire");
  set_long("A key made out of pure fire. Its form slowly shifts and shapes, it seems like it could fit into any door.");
  set_weight(1);
  set_id( ({ "key", "fire key", "MUD_Master_Key" }) );
}

int query_auto_load() { return wizardp(this_player()); }
