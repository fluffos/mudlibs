#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
int extra_worn();
void create() {
::create();
  
    set_name("%^BOLD%^%^BLACK%^Cl%^BOLD%^%^WHITE%^oa%^BOLD%^%^BLACK%^k %^BOLD%^%^WHITE%^of %^BOLD%^%^BLACK%^th%^BOLD%^%^WHITE%^e %^BOLD%^%^BLACK%^Dea%^BOLD%^%^WHITE%^d%^RESET%^");
    
    set_short("%^BOLD%^%^BLACK%^Cl%^BOLD%^%^WHITE%^oa%^BOLD%^%^BLACK%^k %^BOLD%^%^WHITE%^of %^BOLD%^%^BLACK%^th%^BOLD%^%^WHITE%^e %^BOLD%^%^BLACK%^Dea%^BOLD%^%^WHITE%^d%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Thi%^BOLD%^%^WHITE%^s c%^BOLD%^%^BLACK%^loa%^BOLD%^%^WHITE%^k is fa%^BOLD%^%^BLACK%^shi%^BOLD%^%^WHITE%^ion%^BOLD%^%^BLACK%^ed o%^BOLD%^%^WHITE%^ut of %^BOLD%^%^BLACK%^the vi%^BOLD%^%^WHITE%^ctim%^BOLD%^%^BLACK%^s of %^RESET%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^h.%^RESET%^"
             "%^BOLD%^%^WHITE%^ Ar%^BOLD%^%^BLACK%^ms, l%^BOLD%^%^WHITE%^egs %^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^d fac%^BOLD%^%^WHITE%^es c%^BOLD%^%^BLACK%^an b%^BOLD%^%^WHITE%^e se%^BOLD%^%^BLACK%^en sti%^BOLD%^%^WHITE%^cking %^BOLD%^%^BLACK%^ou%^BOLD%^%^WHITE%^t of %^BOLD%^%^BLACK%^the cl%^BOLD%^%^WHITE%^oak.%^RESET%^");
    set_id(({"cloak"}));
    set_ac(14);            
    set_mass(95);
    set_type("cloak");
    set_curr_value("gold", 0);  
    set_wear( (: extra_worn :) );
    set_remove("%^BOLD%^CYAN%^A sense of relief spills across you.%^RESET%^");
    set_limbs(({ "head", "right arm", "left arm", "torso" 
}));
}
int extra_worn() {
    if((int)this_player()->query_level() < 89) {
        write("%^BOLD%^%^RED%^You are an fool to think you can wear a cloak that Death himself made.%^RESET%^");
        say(this_player()->query_cap_name()+" strips off all their clothes and starts running around the room like someone posessed.");
        notify_fail("%^BOLD%^%^RED%^You are an fool to think you can wear a cloak that Death himself made.%^RESET%^");
        return 0;
    }
    write("%^BOLD%^%^BLACK%^Th%^BOLD%^%^WHITE%^e ch%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^ll of %^BOLD%^%^BLACK%^Dea%^BOLD%^%^WHITE%^th%^BOLD%^%^BLACK%^ see%^BOLD%^%^WHITE%^ps i%^BOLD%^%^BLACK%^nto y%^BOLD%^%^WHITE%^our b%^BOLD%^%^BLACK%^on%^BOLD%^%^WHITE%^es.%^RESET%^");
    say(this_player()->query_cap_name() + " %^BOLD%^%^BLACK%^gat%^BOLD%^%^WHITE%^ther%^BOLD%^%^BLACK%^s %^BOLD%^%^WHITE%^dea%^BOLD%^%^BLACK%^th ar%^BOLD%^%^BLACK%^ound %^BOLD%^%^WHITE%^the%^BOLD%^%^BLACK%^m li%^BOLD%^%^WHITE%^ke a %^BOLD%^%^BLACK%^cl%^BOLD%^%^WHITE%^oa%^BOLD%^%^BLACK%^k.%^RESET%^");
    return 1;

}
 int query_auto_load() { if (this_player()->query_level() > 89) return 1; }
