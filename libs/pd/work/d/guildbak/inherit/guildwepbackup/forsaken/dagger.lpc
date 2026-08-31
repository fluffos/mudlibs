#include <std.h>
inherit WEAPON;

create() {
    ::create();
    set_id(({"dagger", "knife"}));
    set_name("forsaken dagger");     set_short("%^RESET%^%^BOLD%^%^BLUE%^For%^RESET%^%^WHITE%^sa%^BOLD%^%^BLUE%^ken %^BLACK%^Dagger%^RESET%^");
    set_long("With a nine inch serrated blade, %^BOLD%^%^BLUE%^blue %^YELLOW%^f%^RED%^la%^YELLOW%^mes%^RESET%^ spiral around the hilt. Definitely, a creation of the %^BOLD%^%^BLUE%^For%^RESET%^sa%^BOLD%^%^BLUE%^ken.%^RESET%^");
    set_mass(10);              
    set_curr_value("gold", 2000);
    set_wc(10);                
    set_ac(1);                 
    set_type("knife");         
    set_hands(1);              
    set_wield("As you grip the hilt, %^YELLOW%^f%^RED%^la%^YELLOW%^mes%^RESET%^ burst around your arm up to your shoulder.");
    set_unwield("The %^YELLOW%^f%^RED%^la%^YELLOW%^mes%^RESET%^ dissipate as you sheath the dagger.");
    set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit() {
    int result;
    object ob;
    ob=(object)this_player()->query_current_attacker();
    if(random(100) > 85) {
	write("You plunge the dagger into "+this_player()->query_current_attacker()->query_cap_name()+"'s chest.\n%^BOLD%^%^RED%^The blood from the dagger seeps into your wounds.%^RESET%^");
	say((string)this_player()->query_cap_name()+
	  " plunges "+this_player()->query_possessive()+" dagger into "+this_player()->query_current_attacker()->query_cap_name()+"'s chest.%^RESET%^");
        result=(random(50) + 10 + (this_player()->query_level()/5));
	result=random(result)+20;
	this_player()->add_hp(result);
	return result;
    }

}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
