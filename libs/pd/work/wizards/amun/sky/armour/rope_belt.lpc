#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("rope belt");
    set("id", ({ "belt", "rope belt", "rope" }) );
    set("short",
      "%^RESET%^%^ORANGE%^r%^RESET%^o%^ORANGE%^p%^RESET%^e "
      "%^ORANGE%^b%^RESET%^e%^ORANGE%^l%^RESET%^t"
    );
    set("long",
      "%^RESET%^%^ORANGE%^This belt was made to help "
      "hold robes in place.%^RESET%^"
    );
    set_type("belt");
    set_ac(1);
    set_limbs( ({ "torso" }) );
    set_weight(5);
    set_curr_value("gold", 50);
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
