#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("brown robes");
    set("id", ({ "robe", "robes", "brown robes", "brown robe" }) );
    set("short", "%^RESET%^%^ORANGE%^brown robes%^RESET%^");
    set("long",
      "%^RESET%^%^ORANGE%^These robes were made by the monks in the sky temple. "
      "They offer little protection.%^RESET%^"
    );
    set_type("robes");
    set_ac(1);
    set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
    set_weight(25);
    set_curr_value("gold", 60); 
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
