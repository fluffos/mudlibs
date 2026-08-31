#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "sword", "broadsword", "brand", "silver brand" }));
   set_name("broadsword");
   set_short(
"%^BOLD%^%^GREEN%^a si%^WHITE%^lver w%^YELLOW%^rou%^WHITE%^ght "
"br%^GREEN%^and%^RESET%^");
set_long(
"%^BOLD%^%^GREEN%^<>%^YELLOW%^++++%^GREEN%^[%^WHITE%^=================="
"=====%^GREEN%^>%^RESET%^");
   set_weight(13);
    set_curr_value("gold", 45);
   set_wc(5);
   set_type("blade");
}

int query_auto_load() { if (this_player()->query_level() >= 17) return 1; }
