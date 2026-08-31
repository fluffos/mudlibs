#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Pumpkin");
    set("id", ({ "pumpkin" }) );
    set("short", "%^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^This pumpkin is lit with fire.  The Headless horeseman will surely want it back some day." );
    set_type("projectile");
    set_weight(10);
    set_curr_value("gold", 75);
    set_wc(6);
    set_type("projectile");
    set("skill level", 115);
    set_element("fire", 20);
    set_element("ice", -20);
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
int can_wield() {
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("projectile") >= 115)
    {
	write("%^BOLD%^%^BLACK%^The pumpkin lights you hand on fire, and yet you don't feel a thing.");
    }
    return 1;
}

int weapon_hit() 
{
    int result;
    object atk;
    int num;
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("projectile") < 115)
    {
	write("The pumpkin lights your hand on fire causing it to burn.");
	say((string)this_player()->query_cap_name() + " screams and drops the pumpkin and clutches thier burt hand!");
	this_player()->force_me("drop pumpkin");
    }
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num < 100)
    {
	write("You throw the pumpkin into "+ atk->query_cap_name() +"'s face, setting them on fire!");
	say((string)this_player()->query_cap_name() + " throws the pumpkin into " + atk->query_cap_name() + "'s face setting them on fire!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num >200)
    {
	write("You notice the pumpkin jumps to life and lunges at "+ atk->query_cap_name() +"'s causing them to engulf in flames!");
	say((string)this_player()->query_cap_name() + " notices the pumpkin jumps to life and lunges at " + atk->query_cap_name() + " causing them to engulf in flames!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
} 

