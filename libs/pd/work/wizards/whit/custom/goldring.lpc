#include <std.h>
inherit ARMOUR;

int counter;
string owner = "sasayaki";

void create() {
    ::create();
    set_name("ring");
    set_short("%^BOLD%^%^YELLOW%^Gold Ring%^RESET%^");
    set_long("This plain gold ring contains the spirit of Sasayaki's Demon self. It is inseparable from his being, and was a personal gift from the Gods themselves.");
    set_id(({"ring", "gold ring"}));
    set_ac(3);
    set_mass(1);
    set_properties(([
	"no_steal" : 1,
      ]));
    set_value(0);
    set_type("ring");
    set_limbs(({"left hand", "right hand", "first hand",
	"second hand", "third hand", "fourth hand"}));
    set_heart_beat(1);
    counter = 100;
}


void heart_beat() 
{

    if (environment(this_object()) != find_player(owner) && environment(this_object()))
    {
	message("say", "%^BOLD%^%^YELLOW%^Your ring slips back into your inventory.", find_player(owner));
	this_object()->move(find_player(owner));
    }

    if (find_player(owner)->query_hp() < find_player(owner)->query_max_hp())
    {
	find_player(owner)->add_hp(random(find_player(owner)->query_level())+5);
    }

    if (find_player(owner)->query_sp() < find_player(owner)->query_max_sp())
    {
	find_player(owner)->add_sp(random(find_player(owner)->query_level())+5);
    }
    if (counter < 75){counter++;}

}

void init() 

{
    ::init();
    add_action("rub", "rub");

}

int rub(str) {

    if (str != "ring") {return 0;}

    if (counter >= 70) 
    {

	write("%^BOLD%^%^YELLOW%^You rub the ring.%^RESET%^");

	write("%^BOLD%^%^YELLOW%^Healing energies rush over you.%^RESET%^");

	counter = 0;

	this_player()->set_hp(this_player()->query_max_hp());
	this_player()->set_sp(this_player()->query_max_sp());

	return 1;
    }
    else
    {
	write("%^BOLD%^%^BLUE%^The ring's energies are not fully recharged yet.%^RESET%^");
	return 1;
    }

}


mixed query_auto_load() {
    if(this_player()->query_name() == owner)
	return ({base_name(this_object()), ({})});
}

int drop() { return 0;}
int sell() { return 0;}
int bury() { return 0;}
int steal() { return 0;}
