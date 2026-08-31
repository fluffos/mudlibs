#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
int extra_worn();
void create() {
::create();
  
    set_name("%^ORANGE%^Tatt%^BOLD%^%^BLACK%^ere%^RESET%^ORANGE%^d bo%^BOLD%^%^BLACK%^ots%^RESET%^");
    
    set_short("%^ORANGE%^Tatt%^BOLD%^%^BLACK%^ere%^RESET%^ORANGE%^d bo%^BOLD%^%^BLACK%^ots%^RESET%^");
    set_long("%^ORANGE%^Thes%^BOLD%^%^BLACK%^e bo%^RESET%^%^ORANGE%^ots lo%^BOLD%^%^BLACK%^ok lik%^RESET%^%^ORANGE%^e they a%^BOLD%^%^BLACK%^re a m%^RESET%^%^ORANGE%^illi%^BOLD%^%^BLACK%^on ye%^RESET%^%^ORANGE%^ars ol%^BOLD%^%^BLACK%^d.%^RESET%^"
             "%^RESET%^%^ORANGE%^ Worm ri%^BOLD%^%^BLACK%^dden a%^RESET%^%^ORANGE%^nd torn%^BOLD%^%^BLACK%^ it do%^RESET%^%^ORANGE%^sent l%^BOLD%^%^BLACK%^ook li%^RESET%^%^ORANGE%^ke they w%^BOLD%^%^BLACK%^ou%^RESET%^%^ORANGE%^ld%^BOLD%^%^BLACK%^ giv%^RESET%^%^ORANGE%^e much %^BOLD%^%^BLACK%^prot%^RESET%^%^ORANGE%^ection.%^RESET%^");
    set_id(({"boots"}));
    set_ac(12);            
    set_mass(195);
    set_type("boots");
    set_curr_value("gold", 0); 
    set_wear( (: extra_worn :) ); 
    set_remove("%^RED%^You shake the festering maggots off your feet.%^RESET%^");
    set_limbs(({ "left foot", "right foot" 
}));
}
int extra_worn() {
    if((int)this_player()->query_level() < 89) {
        write("%^BOLD%^%^RED%^You wouldnt dare put your foot in that!%^RESET%^");
        say(this_player()->query_cap_name()+" isnt smart enought to realize that they shouldnt put their foot in something that is decomposing.");
        notify_fail("%^BOLD%^%^RED%^You wouldnt dare put your foot in that!%^RESET%^");
        return 0;
    }
    write("%^ORANGE%^You s%^BOLD%^%^BLACK%^lip%^RESET%^%^ORANGE%^ you%^BOLD%^%^BLACK%^r fo%^RESET%^%^ORANGE%^ot thro%^BOLD%^%^BLACK%^ugh y%^RESET%^%^ORANGE%^ears of %^BOLD%^%^BLACK%^dirt %^RESET%^ORANGE%^and gr%^BOLD%^%^BLACK%^im%^RESET%^%^ORANGE%^e.%^RESET%^");
    say(this_player()->query_cap_name() + " gets a strange look on their face as they stick their foot into a bootfull of maggots.");
    return 1;

}
 int query_auto_load() { if (this_player()->query_level() > 89) return 1; }
