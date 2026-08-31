#include <std.h>
inherit ARMOUR;

void create() {
    :: create();

    set_name("leather");
    set_short("Leather Dominatrix Suit");
    set_long("This is basically a suit of black-leather armour modified to have spikes around the collar and sleeves. It has straps and buckles everywhere, lined with studs and all sorts of other nasty things.");
    set_id(({"leather", "suit", "dominatrix suit", "leather suit"}));
    set_ac(1);
    set_mass(15);
    set("value",0);
    set_type("vest");
    set_limbs(({"torso"}));
}
int query_auto_load() { if (this_player()->query_name() == "azire") return 1; }
