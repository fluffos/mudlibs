#include <std.h>
inherit WEAPON;

void create() {
  ::create();
    set_id(({ "knife", "nushae knife" }));
    set_name("knife");
    set_short("%^BOLD%^%^BLACK%^M%^RED%^u%^WHITE%^r%^BLACK%^i%^RESET%^ %^BOLD%^%^BLACK%^K%^RED%^n%^BLACK%^if%^WHITE%^e%^RESET%^");
    set_long("Made from the ways of ancient times, the %^BOLD%^%^BLACK%^M%^RED%^u%^WHITE%^r%^BLACK%^i%^RESET%^ %^BOLD%^%^BLACK%^K%^RED%^n%^BLACK%^if%^WHITE%^e%^RESET%^ is one used only by those of dark intentions.");
    set_type("knife");
    set_wc(5);
    set_weight(15);
    set_curr_value("gold", 10+random(30));
}

int query_auto_load(){
    if (this_player()->query_level() >= 15) return 1;
    return 0;
}
