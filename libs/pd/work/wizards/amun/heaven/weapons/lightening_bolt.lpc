#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Lightening Bolt");
    set("id", ({ "lightening bolt", "bolt", "spear" }) );
    set("short", "%^BOLD%^%^YELLOW%^L%^BLACK%^i%^YELLOW%^ght%^BLACK%^e%^YELLOW%^n%^BLACK%^i%^YELLOW%^ng B%^BLACK%^o%^YELLOW%^lt%^RESET%^");
    set("long", "%^BOLD%^%^YELLOW%^This bolt of lightening was forged in Heaven. It has a small handel on the end for the wielder to hold and changes shapes as you look at it.%^RESET%^" );
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
    if (this_player()->query_level() >= 36)
	return 1;
}
int can_wield() {
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("projectile") >= 115)
    {
	write("%^BOLD%^%^YELLOW%^Your hand is engulfed in a bright %^WHITE%^light%^YELLOW%^.%^RESET%^");
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
	write("%^BOLD%^%^YELLOW%^The bolt of lightening flashes causing your hand to burn with fire.%^RESET%^");
	say((string)this_player()->query_cap_name() + " screams and drops the pumpkin and clutches thier burnt hand!");
	this_player()->force_me("drop bolt");
    }
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num < 100)
    {
	write("You throw a bolt of lightening into "+ atk->query_cap_name() +"'s face, setting them on fire!");
	say((string)this_player()->query_cap_name() + " throws a bolt of lightening into " + atk->query_cap_name() + "'s face setting them on fire!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num >200)
    {
	write("The bolt of lightening flashes in "+ atk->query_cap_name() +"'s eyes burning them!");
	say((string)this_player()->query_cap_name() + " notices The bolt of lightening flash in " + atk->query_cap_name() + " eyes causing them to burn!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
} 
