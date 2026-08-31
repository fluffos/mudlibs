#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("%^BLACK%^%^BOLD%^N%^WHITE%^i%^BLACK%^n%^WHITE%^j%^BLACK%^a %^WHITE%^M%^BLACK%^a%^WHITE%^s%^BLACK%^k%^RESET%^");
    set("id", ({"ninja", "mask", "ninja mask", "visor"}) );
    set("short","%^BLACK%^%^BOLD%^N%^WHITE%^i%^BLACK%^n%^WHITE%^j%^BLACK%^a %^WHITE%^M%^BLACK%^a%^WHITE%^s%^BLACK%^k%^RESET%^"); 
    set("long", "%^BLACK%^%^BOLD%^A simple black cloth that ties behind your head and covers your mouth.%^RESET%^");
    set_weight(6);
    set_type("mask");
    set_limbs(({"head"}));
    set_ac(2);
    set_curr_value("gold",300);
    set_wear("%^BLACK%^%^BOLD%^You tie the mask around your face... The air is cleaner, your voice softer and you feel a lot less visible.%^RESET%^");
    set_remove("%^BLACK%^%^BOLD%^You cough as you remove the mask and once again breathe the tainted air around you.%^RESET%^");

}
int query_auto_load() {
    if (this_player()->query_guild()=="AoD") return 1;

}

