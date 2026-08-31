#include <std.h>
inherit WEAPON;

void create() {
   ::create();
   set_name("newbie sword");
   set_id( ({ "sword","newbie sword","rapier","newbie rapier","tin foil","foil" }) );
   set_short("Tin Foil Rapier");
   set_long("A newbie sword.");
   set_mass(5);
   set_wc(2);
   set_hands(1);
   set_type("blade");
}

int query_auto_load() { if(this_player()->query_level() < 5) return 1; }

