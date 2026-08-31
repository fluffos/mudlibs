#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "sword", "broadsword" }));
   set_name("broadsword");
   set_short("%^RESET%^%^ORANGE%^a "
"b%^BOLD%^%^WHITE%^roa%^RESET%^%^RED%^d%^BOLD%^%^WHITE%^"
"swo%^RESET%^%^ORANGE%^rd%^RESET%^");
set_long(
"%^RESET%^%^RED%^0%^ORANGE%^++++%^RED%^[%^BOLD%^%^WHITE%^=================="
"=====%^RESET%^%^RED%^>%^RESET%^");
   set_weight(15);
    set_curr_value("gold", 78);
   set_wc(6);
   set_type("blade");
}

int query_auto_load() { if (this_player()->query_level() >= 21) return 1; }
