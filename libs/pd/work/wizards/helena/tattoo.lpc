#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("AoD Tattoo");
    set("id", ({"tat", "tattoo", "AoD", "necklace"}) );
    set("short","AoD Tattoo"); 
    set("long", "A tattoo given to all new members of the Army Of Darkness. It
is simple and to the point, 3 letters -AoD- scrawled onto the wearers neck.");
    set_weight(15);
    set_type("necklace");
    set_limbs(({"torso"}));
    set_ac(2);
    set_curr_value("gold",300);
    set("dragon wear", 1);
    set_wear("Ouch! Those tattoo needles hurt but now you're AoD for life!");
    set_remove("Your tattoo fades away!");

}
int query_auto_load() {
    if (this_player()->query_guild()=="AoD") return 1;

}
