#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"dagger", "dwarven battle dagger","dagger"}));
set_name("Dwarven Battle Dagger");
set_short("%^BOLD%^%^RED%^D%^RESET%^%^ORANGE%^w%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^v%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^n "
"%^BLUE%^B%^RED%^a%^BLUE%^t%^RED%^t%^BLUE%^l%^RED%^e "
"%^RED%^D%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^g%^RESET%^%^ORANGE%^g%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^r%^RESET%^");
set_long("This Dagger was formed from the powers of magic, it "
"carriers a special power that has never been found out.");
set("skill level", 200);
set_weight(15);
set_value(810);
set_wc(16);
set_ac(2);
set_type("knife");
set_hands(1);
set_wield("%^ORANGE%^A Magical Mist covers you.");
set_unwield("%^YELLOW%^The Mist seems to vanish.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 90) {
write("%^YELLOW%^Your dagger Impales your Foe's Neck!");
say("%^YELLOW%^  "+this_player()->query_cap_name()+"'s Dagger Impales his Foe's Neck!");
result=((300));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
