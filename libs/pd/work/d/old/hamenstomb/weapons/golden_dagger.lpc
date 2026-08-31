#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Golden Dagger");
    set("id", ({ "dagger" }) );
    set("short", "%^BOLD%^%^YELLOW%^Golden Dagger");
    set("long", "%^BOLD%^%^BLACK%^With a black leather handle and a %^YELLOW%^dagger made of solid gold%^BLACK%^, the Magi gave this %^BOLD%^dagger %^BLACK%^to the King as it shows greatness, like the King they serve." );
    set_type("dagger");
    set_weight(30);
    set_curr_value("gold", 500);
    set_wc(14);
    set_type("knife");
    set_element("element", 30);
    set_wield("%^BOLD%^%^YELLOW%^You feel royal as you wield this weapon.");
    set_unwield("%^BOLD%^%^YELLOW%^You feel the roalty leave your senses.");
    set("skill level", 200);
}
int can_wield() 
{
    if (this_player()->query_class() != "rogue"  ||
      this_player()->query_skill("sword") >= 200)
    {
	write("%^BOLD%^%^BLACK%^You feel the need to KILL!");

    }
    return 1;
}

int weapon_hit() 
{
    int result;
    object atk;
    int num;
    if (this_player()->query_class() != "rogue"  ||
      this_player()->query_skill("blade") < 200)
    {
	write("%^BOLD%^%^RED%^The dagger jabs your hand as you attempt to wield it.");
	say((string)this_player()->query_cap_name() + "screams and drops the dagger clutching thier bloody hand!");
	this_player()->force_me("drop dagger");
    }
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num < 100)
    {
	write("%^BOLD%^%^RED%^Your dagger %^BLACK%^MUTILATES %^RED%^"+ atk->query_cap_name() +"!");
	say((string)this_player()->query_cap_name() + " %^BLACK%^MUTILATES %^RED%^" + atk->query_cap_name() + "'s gut, ripping it open!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num >200)
    {
	write("%^BOLD%^%^BLACK%^Your dagger slides its way through"+ atk->query_cap_name() +"'s waist almost cutting them in half!!");
	say((string)this_player()->query_cap_name() + " slides thier sword through " + atk->query_cap_name() + "'s waist almost cutting you in half!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
} 

int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
