
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("outfit");
   set_id( ({"bunny outfit","outfit","suit","bunny suit"}) );
   set_short("A sleek bunny suit");
   set_long(
     "A sleek, shiny bunny outfit cut in all the right places. "
     "It resembles black lingerie that stops at the bust and the thighs. "
     "There is a little, fuzzy, white ball attached to the back to "
     "serve as a cotton-tail. It's really cute."
   );
   set_ac(5);
   set_mass(10);
   set_value(30);
   set_type("shirt");
   set_limbs( ({ "torso" }) );
}

 int query_auto_load() {if(this_player()->query_race() =="nymph") return 1;}

