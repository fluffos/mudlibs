#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"sword", "demon slayer","slayer"}));
set_name("Demon Slayer");
set_short("%^RESET%^%^RED%^D%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^m%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^n "
"%^RESET%^%^RED%^S%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^y%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^");
set_long("This Sword was given to the holy people of this land, from "
"there god for proection against the evil demons.");
set("skill level", 75);
set_weight(19);
    set_curr_value("gold",150+random(40));
set_wc(10);
set_ac(2);
set_type("blade");
set_hands(1);
set_wield("%^BOLD%^%^WHITE%^The hate for demons fills your body.");
set_unwield("%^BOLD%^%^BLUE%^The hate vanish's.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^YELLOW%^Your Slayers burns through your Foe's skin!");
say("The %^RESET%^%^RED%^S%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^y%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r burns through its Foe's skin!"); 
result=(random(50))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
