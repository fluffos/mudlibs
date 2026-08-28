//    A storage locker for PC shops.  Used to store items over a reboot.
//    DarkeLIB 0.1
//    -Diewarzau 8/7/95
//    Long descriptions revised by Duridian 4/1/96
 
#include <std.h>
 
inherit LOCKER;
 
int query_storage_locker() { return 1; }
 
void create() {
  ::create();
    set_name("locker");
    set_id( ({ "locker", "storage locker" }) );
    set_long("It is a storage locker in which you can store items.\n");
    set_closed_long("It is a closed storage locker in which you can store items.\n");
    set_open_long("It is an open storage locker in which you can store items.\n");
    set_value(100000);
    set_weight(1200);
    set_short("A large storage locker");
    set_max_items(25);
    set_max_internal_encumbrance(15000);
    return;
}
 
