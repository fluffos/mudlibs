
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("bunny ears");
   set_id( ({"ears","bunny ears"}) );
   set_short("a set of bunny ears");
   set_long(
     "A set of long white bunny ears attached to a thin metal band "
    "to keep it on a person's head. They look really cute."
   );
   set_ac(2);
   set_mass(4);
   set_value(10);
   set_type("helmet");
   set_limbs( ({ "head" }) );
}

int query_auto_load() {
      if(this_player()->query_race() == "nymph")
   return 1;
}

