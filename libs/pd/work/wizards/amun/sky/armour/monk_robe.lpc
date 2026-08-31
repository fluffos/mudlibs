#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("monk robes");
    set("id", ({ "robe", "robes", "monk", "monk robes" }) );
    set("short",
      "%^RESET%^M%^ORANGE%^o%^RESET%^n%^ORANGE%^k "
      "%^RESET%^R%^ORANGE%^o%^RESET%^b%^ORANGE%^e%^RESET%^s"
    );
    set("long",
      "%^RESET%^%^ORANGE%^These robes were created out of the "
      "goodness of the temple in the sky. They offer little protection, "
      "but show where the wearer's allegiance lies.%^RESET%^"
    );
    set_type("robes");
    set_ac(2);
    set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
    set_weight(25);
    set_curr_value("gold", 100); 
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
