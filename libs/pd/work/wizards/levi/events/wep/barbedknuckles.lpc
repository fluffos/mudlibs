#include <std.h>
inherit WEAPON;

void create() {
  ::create();           

  set_id(({"knuckles","barbed knuckles"}));
  set_name("barbed knuckles");
  set_short("Barbed Knuckles");
set_long("These knuckles are nothing more than large sheets of brass, held on "
	"with straps and covered in barbed wire.");
  set_mass(20);
  set_wc(1);           
  set_type("melee");
  set_hands(2);
}
int query_auto_load() {
   if (this_player()->query_level() > 50) return 1;
}
