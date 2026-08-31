#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("black shirt");
    set("id", ({ "shirt", "black shirt" }) );
    set("short", "%^BOLD%^%^BLACK%^black shirt%^RESET%^");
    set("long",
      "%^BOLD%^%^BLACK%^This shirt was specially made for the priests "
      "in the sky temple. It is light in weight, "
      "yet tough as scales.%^RESET%^"
    );
    set_type("shirt");
    set_ac(2);
    set_limbs( ({ "right arm", "left arm", "torso" }) );
    set_weight(15);
    set_curr_value("gold", 200);  
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
