#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("armour");
   set_short("%^RESET%^%^CYAN%^Ar%^BOLD%^%^WHITE%^mo%^CYAN%^ur "
	"%^RESET%^of %^BOLD%^%^RED%^so%^BLUE%^uls%^RESET%^");
   set_long("This suit of souls has been collected by some cruel old "
	"hag. It has only the finest of souls gathered including those "
	"of some players who have got in the way of the force behind "
	"this armour.");
   set_weight(14);
   set_id(({ "souls", "armour" }));
   set_type("armour");
   set_limbs(({ "torso", "left arm", "right arm", "left leg",
	"right leg" }));
   set_ac(7);
   set_value(0);
}

int query_auto_load() {
   if (this_player()->query_level() >= 5)
     return 1;
}
