#include <std.h>
#include <amun.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("Fangs");
    set_id( ({ "fang", "fangs" }) );
    set_short("%^RESET%^%^GREEN%^F%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^n%^RESET%^%^ORANGE%^g%^GREEN%^s%^RESET%^");
    set_long("%^RESET%^%^GREEN%^These fangs came from the mouth of a serpent.%^RESET%^" );
    set_type("knife");
    set_weight(2);
    set_curr_value("gold", 10);
    set_wc(3);
    set("skill level", 20);
}
int query_auto_load() {
    if(this_player()->query_level() < 5) return 0;
    return 1; 
}
