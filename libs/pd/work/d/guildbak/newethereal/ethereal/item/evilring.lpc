#include <std.h>
#include <ether.h>
inherit ARMOUR;
int align;

void create() {
    ::create();
    set("id", ({"satanic","satanic ring","ring"}) );
    set_name("ring");
    set_short("%^RED%^Sa%^BOLD%^ta%^BLACK%^nic %^RED%^Ri%^RESET%^%^RED%^ng%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^This ring has been relinquished from the depths of hell.  It will eat away at all that is holy.%^RESET%^");
    set_type("ring");
    set_limbs( ({"left hand","right hand"}) );
    set_ac(1);
    set_mass(5);
    set_curr_value("gold",195+random(55));
    set_wear("%^BLACK%^%^BOLD%^You feel an %^CYAN%^evil%^BLACK%^ presence taking ahold of you as you slip on the %^RESET%^%^RED%^Sa%^BOLD%^ta%^BLACK%^nic %^RED%^Ri%^RESET%^%^RED%^ng%^RESET%^");
    set_remove("%^BOLD%^%^BLACK%^You tremble as the %^CYAN%^evil%^BLACK%^ radiating from the %^RESET%^%^RED%^Sa%^BOLD%^ta%^BLACK%^nic %^RED%^Ri%^RESET%^%^RED%^ng%^RESET%^%^BOLD%^%^BLACK%^ vanishes.  Your soul is now free.");
    set_heart_beat(1);


}
int query_auto_load() { 
    if(this_player()->query_level() < 36) return 0;
    return 1;
}


