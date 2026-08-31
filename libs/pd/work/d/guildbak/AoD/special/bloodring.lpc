# include <std.h>
inherit ARMOUR;
int extra_worn();
void create() {
    ::create();

    set_name("Blood Ring");

    set_short("%^BOLD%^%^RED%^Bl%^RESET%^%^RED%^o%^BOLD%^o%^RESET%^%^RED%^d %^BOLD%^R%^RESET%^%^RED%^in%^BOLD%^g%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Only those who have joined the ranks of the Army
of Darkness may bear this ring upon their finger. 
Embedded in a mithril setting sits a stone the
color of freshly spilt blood.  Warmth spreads
from the ring to your hand.%^RESET%^");
    set_id(({"ring", "blood_ring" }));
    set_ac(2);            
    set_weight(1);
    set_curr_value("gold", 150);
    set_type("ring");  
    set_wear( (: extra_worn :) );
    set_limbs(({ "right hand" , "left hand" }));
}
int extra_worn() {
    if((int)this_player()->query_level() < 20) {
        write("Spikes jut from the inside of the ring!");
        say(this_player()->query_cap_name()+" curses loudly as the ring draws blood!.");
        return notify_fail("You are not worthy enough to bare this ring.");
  
    }
    write("%^RED%^Blood pours from the stone, dripping to the floor in sticky streams.");
say(this_player()->query_cap_name() + " raises " + this_player()->query_possessive() + " head to the sky and roars as bloodlust fills " + this_player()->query_possessive() + " veins.");
    return 1;
}
    int query_auto_load() { if (this_player()->query_guild() == "AoD" ) return 1; }
