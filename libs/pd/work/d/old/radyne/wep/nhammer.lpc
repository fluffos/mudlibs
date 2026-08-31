#include <std.h>
inherit WEAPON;

void create() {
   ::create();
   set_name("newbie mallet");
   set_id( ({ "hammer","mallet","newbie mallet" }) );
   set_short("Cartoonishly Over-Sized Mallet");
   set_long("A newbie hammer");
   set_mass(5);
   set_wc(2);
   set_hands(1);
   set_type("blunt");

}

int query_auto_load() { if(this_player()->query_level() < 5) return 1; }


