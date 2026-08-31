#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("white robes");
    set("id", ({ "robe", "robes" }) );
    set("short", "%^BOLD%^%^WHITE%^white robes%^RESET%^");
    set("long",
      "%^BOLD%^%^WHITE%^These robes were created out of the goodness "
      "of the temple in the sky. A %^CYAN%^soft%^WHITE%^ blue lace "
      "lines the neckline of these light, but durable, robes.%^RESET%^"
    );
    set_type("robes");
    set_ac(2);
    set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
    set_weight(25);
    set_curr_value("gold", 110); 
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
