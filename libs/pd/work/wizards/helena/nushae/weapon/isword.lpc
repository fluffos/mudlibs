#include <std.h>

inherit WEAPON;

void create() {
  ::create();
    set_id(({ "sword", "iron sword" }));
    set_name("iron sword");
    set_short("%^BOLD%^%^BLACK%^an iron sword%^RESET%^");
    set_long("Roughly fashioned from %^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^ %^BOLD%^%^BLACK%^Iron%^RESET%^, the sword is suitable for any volatile occasion.");
    set_weight(20);
    set_curr_value("gold", 130-random(30));
    set_wc(10);
    set_type("blade");
}

int query_auto_load() {
    if (this_player()->query_level() >=15) return 1;
}
