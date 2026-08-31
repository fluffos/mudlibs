#include <std.h>
#include <rain.h>
inherit ARMOUR;

create() {
    ::create();
    set_name("spiked platemail");
    set_short("Spiked platemail");
    set_long("This is %^BOLD%^BLACK%^black%^RESET%^ platemail "
      "with vicious spikes protruding from the armour at the "
      "chest area, and the shoulders.");
    set_ac(7);
    set_weight(58);
    set_type("body armour");
    set_limbs(({"right arm", "left arm", "right leg", "left leg", "torso"}));
    set_curr_value("gold", 112);
    set_id(({"platemail", "spiked platemail"}));
}

int query_auto_load() { if (this_player()->query_level() >= 13) return 1; }
