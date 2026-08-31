#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("utility belt");
    set("id", ({"belt", "utility", "utilitybelt", "batbelt"}) );
    set("short","%^BLACK%^%^BOLD%^U%^WHITE%^t%^BLACK%^i%^WHITE%^l%^BLACK%^i%^WHITE%^t%^BLACK%^y %^WHITE%^B%^BLACK%^e%^WHITE%^l%^BLACK%^t%^RESET%^"); 
    set("long", "%^BLACK%^%^BOLD%^This handy gadget has more to the eye than you would think. There
are compartments for vials of %^RED%^BOLD%^blood%^RESET%^, %^BLACK%^%^BOLD%^s%^GREEN%^k%^BLACK%^u%^GREEN%^l%^BLACK%^l%^GREEN%^s%^RESET%^,%^BLACK%^%^BOLD%^ daggers, garote wire, you name it and it holds it%^RESET%^.");
set_weight(18);
set_type("belt");
set_limbs(({"torso"}));
set_ac(2);
set_curr_value("gold",300);
set_wear("%^WHITE%^%^BOLD%^*click*%^BLACK%^ The belt snaps into a secure position around your waist%^RESET%^.");
set_remove("%^WHITE%^%^BOLD%^*click*%^BLACK%^ You unlatch the utility belt and put it aside%^RESET%^.");

}
int query_auto_load() {
        if (this_player()->query_guild()=="AoD") return 1;
}

