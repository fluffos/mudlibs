#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "javelin", "knights javelin" }) );
   set_name("javelin");
   set_short("%^RESET%^%^CYAN%^a "
      "%^BOLD%^l%^RESET%^%^CYAN%^o%^BOLD%^n%^RESET%^%^CYAN%^g "
      "%^RESET%^%^CYAN%^j%^BOLD%^a%^RESET%^%^CYAN%^v%^BOLD%^e"
      "%^RESET%^%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^n%^RESET%^");
   set_long("A sharp knife-like blade attached to a long handel.");
   set_weight(2);
    set_curr_value("gold", 45);
   set_hands(1);
   set_wc(4);
   set_type("projectile");
}

int query_auto_load() { if (this_player()->query_level() >= 9) return 1; }
