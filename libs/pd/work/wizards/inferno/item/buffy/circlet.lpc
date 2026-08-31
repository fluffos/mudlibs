#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("circlet");
   set_short("%^RESET%^%^GREEN%^Cir%^YELLOW%^c%^BOLD%^%^GREEN%^let "
	"%^RESET%^of %^BOLD%^%^BLACK%^Tho%^BLUE%^rns%^RESET%^");
   set_long("This circlet has taken years to make and comes from the "
	"finest of rose thorns. The owner of this has gone through a "
	"lot of pain and anguish placing all the thorns in the correct "
	"places.");
   set_weight(6);
   set_ac(2);
   set_id(({ "thorns", "circlet" }));
   set_value(0);
   set_limbs(({ "head" }));
   set_type("helmet");
}

int query_auto_load() {
   if (this_player()->query_level() >= 5)
     return 1;
}
