#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ring");
   set_short("%^BOLD%^%^YELLOW%^a gold and %^RED%^ruby %^YELLOW%^encrusted ring%^RESET%^");
   set_long("This absolutely beautiful ring was made with love by Vian.  It is surely invaluable.");
   set_id(({ "ring", "ruby ring", "gold ring"}));
   set_weight(5);
   set_limbs(({"right hand", "left hand"}));
   set_type("ring");
   set_ac(1);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 1);
}

