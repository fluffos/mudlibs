#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ring");
   set_short("%^BOLD%^%^YELLOW%^a gold and %^WHITE%^diamond %^YELLOW%^encrusted ring%^RESET%^");
   set_long("This ring was made with love from Vian to Yun, a ring asking for his hand in marriage..");
   set_id(({ "ring", "wedding ring", "gold ring"}));
   set_weight(5);
   set_limbs(({"right hand", "left hand"}));
   set_type("ring");
   set_ac(1);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 1);
}

