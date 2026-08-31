#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("hat");
   set_short("%^BOLD%^%^CYAN%^a b%^BLUE%^lu%^CYAN%^e sm%^BLUE%^u%^CYAN%^rf's "
     "h%^BLUE%^a%^CYAN%^t%^RESET%^");
   set_id(({ "hat", "smurf's hat", "blue hat" }));
   set_long("This well crafted, light and comfortable hat was made for a small "
     "head, but could be made to stretch to fit just about anybody.. One size "
     "fits all!");
   set_weight(3);
    set_curr_value("silver", 425);
   set_type("helmet");
   set_limbs(({ "head" }));
   set_ac(1);
}

int query_auto_load() { if (this_player()->query_level() >= 3) return 1; }
