#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "dagger", "well crafted dagger" }));
   set_name("dagger");
   set_short(
"%^RESET%^%^BLUE%^a we%^BOLD%^%^WHITE%^ll cr%^YELLOW%^aft%^WHITE%^ed "
"da%^RESET%^%^BLUE%^gger%^RESET%^");
set_long(
"%^RESET%^%^BLUE%^0%^YELLOW%^++%^RESET%^%^BLUE%^[%^BOLD%^%^BLACK%^======="
"%^RESET%^%^BLUE%^>%^RESET%^");
   set_weight(11);
    set_curr_value("gold", 25);
   set_wc(3);
   set_type("knife");
}

int query_auto_load() { if (this_player()->query_skill("knife") >= 25) return 1; }
