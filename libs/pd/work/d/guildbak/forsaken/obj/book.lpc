#include <std.h>
inherit WEAPON;

create() {
    ::create();
    set_id(({"book"}));
    set_name("%^ORANGE%^Book of Spells%^RESET%^");
    set_short("%^ORANGE%^Book of Spells%^RESET%^");
    set_long( "This is an old ancient tome with many spells written inside.");
    set_mass(10);
    set_curr_value("gold", 2000);
    set_wc(10);           
    set_ac(1);
    set_type("blunt");
    set_hands(2);
    set_wield("It takes you a few atemps but you finally lift up the book.");
    set_unwield("As you drop the book it falls on your foot, %^BOLD%^%^RED%^OUCH!%^RESET%^.");
    set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit() {
    int result;
    object ob;
    ob=(object)this_player()->query_current_attacker();
    if(random(100) > 85) {
	write("%^CYAN%^You say:%^RESET%^ Ub rhak zraah.\n%^BOLD%^%^BLUE%^A blue stream of energy flows from them into you.%^RESET%^");
	say((string)this_player()->query_cap_name()+
	  " mutters some words from the book.\n%^BOLD%^%^BLUE%^A blue stream of energy flows into them.%^RESET%^");
	result=(random(55+random(50)-random(50))*((this_player()->query_level()/20)+1));
	result=random(result)+20;
	this_player()->add_mp(result);
	return result;
    }
}


void init() {
    ::init();
    if(this_player()->is_player() && environment(this_object()) == this_player()) set_short(this_player()->query_cap_name()+"'s %^ORANGE%^Book of Spells%^RESET%^");
    else set_short("%^ORANGE%^Book of Spells%^RESET%^");
}
