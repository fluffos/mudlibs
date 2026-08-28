//    A forge.
#include <move.h>
#include <daemons.h>

inherit "/std/Object";
inherit "/std/locker_logic";

void create() {
  ::create();
  set_property("no save", 1);
  set_id( ({ "forge" }) );
  set_name("forge");
  set_short("A forge");
  set_long(
  "This forge is extremely hot, and may be used to forge weapons and armour.");
  set_weight(1300);
  set_value(15034);
  return;
}

int register_num() { return 1; }
string query_storage_key() { return "null"; }

int query_is_locker() { return 1; }
string query_my_file() { return "null"; }

int move(mixed dest) {
  
  if(query_property("no get") && objectp(dest) && living(dest))
    return MOVE_NOT_ALLOWED;
  return ::move(dest);

}

int restore_locker(string null) {
  return 1;
}
