#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "sword", "shortsword" }));
   set_name("shortsword");
   set_short(
"%^RESET%^%^BLUE%^a ro%^CYAN%^yal f%^BOLD%^%^BLACK%^enci%^RESET%^%^CYAN%^ng "
"sw%^BLUE%^ord%^RESET%^");
   set_long(
"%^RESET%^%^BLUE%^o%^RESET%^%^CYAN%^====%^RESET%^%^BLUE%^<%^BOLD%^%^BLACK%^"
"----------------------%^RESET%^");
   set_weight(7);
    set_curr_value("gold", 30);
   set_wc(5);
   set_type("blade");
}

int query_auto_load() { if (this_player()->query_skill("blade") >= 35) return 1; }
