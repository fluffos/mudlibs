#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "sword", "shortsword" }));
   set_name("shortsword");
   set_short("%^RESET%^%^RED%^a s%^BOLD%^%^WHITE%^ho%^RESET%^%^ORANGE%^rt"
     "s%^BOLD%^%^WHITE%^wo%^RESET%^%^RED%^rd%^RESET%^");
   set_long(
"%^RESET%^%^RED%^0%^ORANGE%^++++%^RED%^(%^BOLD%^%^WHITE%^==========="
"===%^RESET%^%^RED%^>%^RESET%^");
   set_weight(12);
    set_curr_value("gold", 60);
   set_wc(6);
   set_type("blade");
}

int query_auto_load() { if (this_player()->query_skill("blade") >= 25) return 1; }
