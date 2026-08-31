#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ring");
   set_short("%^BOLD%^a %^YELLOW%^gold%^WHITE%^ ring with a %^RED%^ruby rose%^RESET%^");
   set_long("This ring was made with love from Vian to Sugarcandy.  It is a beautiful golden ring with a ruby carved into the shape of a rose on it.");
   set_id(({ "ring", "rose ring", "gold ring"}));
   set_weight(5);
   set_limbs(({"right hand", "left hand"}));
   set_type("ring");
   set_ac(1);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 1);
}

