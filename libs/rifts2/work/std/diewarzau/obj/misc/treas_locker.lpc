//    A storage locker for PC shops.  Used to store items over a reboot.
//    DarkeLIB 0.1
//    -Diewarzau 8/7/95

#include <std.h>
#include <move.h>

inherit LOCKER;

int query_storage_locker() { return 1; }

void create() {
  ::create();
    set_name("locker");
    set_id( ({ "locker", "storage locker" }) );
   set_long("It is a closed storage locker.");
    set_closed_long("It is a closed storage locker.");
    set_open_long("It is an open storage locker.");
    set_value(100000);
    set_weight(1200);
    set_short("A large storage locker");
    set_max_items(25);
    set_max_internal_encumbrance(30000);
    return;
}

int move(mixed dest) {
  if(!objectp(dest)) return ::move(dest);
  if(living(dest) && !wizardp(dest)) return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

