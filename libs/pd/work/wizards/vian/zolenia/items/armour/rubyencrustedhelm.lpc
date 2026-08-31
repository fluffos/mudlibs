#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("helm");
   set_short("%^RED%^ruby %^RESET%^encrusted %^BLACK%^%^BOLD%^helm%^RESET%^");
   set_long("This helm is constructed from the finest onyx in the land, encrusted all the way around with small rubies..");
   set_id(({ "helm", "ruby encrusted helm", "rubyencrustedhelm", "ruby helm"}));
   set_weight(30);
   set_limbs(({"head"}));
   set_type("helmet");
    set_curr_value("gold", 600);
   set_ac(12);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
