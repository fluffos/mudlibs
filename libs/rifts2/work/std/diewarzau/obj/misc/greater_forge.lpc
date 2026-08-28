//    A forge.
#include <move.h>
#include <daemons.h>

inherit "/std/Object";
inherit "/std/locker_logic";

void create() {
  ::create();
  set_property("no save", 1);
  set_id( ({ "greater forge", "forge" }) );
  set_name("forge");
  set_short("A greater forge");
  set_long(
  "This forge is extremely hot, and may be used to forge weapons and armour.");
  set_weight(1300);
  set_value(100034);
  return;
}

int register_num() { return 2; }
string query_storage_key() { return "null"; }

int query_is_locker() { return 1; }
string query_my_file() { return "null"; }

int move(mixed dest) {
  
  if(query_property("no get") && objectp(dest) && living(dest))
    return MOVE_NOT_ALLOWED;
  return ::move(dest);
}


int restore_locker(string null) {
  set_property("no get", 1);
  return 1;
}

