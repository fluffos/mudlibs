#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Lava Dagger");
    set("id", ({ "dagger" }) );
    set("short", "%^RESET%^%^ORANGE%^L%^RED%^a%^ORANGE%^v%^RED%^a %^ORANGE%^D%^RED%^a%^ORANGE%^gg%^RED%^e%^ORANGE%^r%^RESET%^");
    set("long", "%^BOLD%^%^ORANGE%^This dagger was made in the depths of hell.  The blade seems to be made from multing rock.%^RESET%^" );
    set_type("dagger");
    set_weight(40);
    set_curr_value("gold", 300);
    set_wc(12);
    set_type("knife");
    set_element("fire", 20);
    set_element("ice", -20);
    set_decay_rate(200);
    set("skill level", 200);
}
int query_auto_load() {
    if (this_player()->query_level() >= 45)
	return 1;
}
int can_wield() {
    if (this_player()->query_class() != "rogue"  ||
      this_player()->query_skill("sword") >= 200)
    {
	write("The Lava forms over your hand allowing you a firm grip.");
    }
    return 1;
}

int weapon_hit() 
{
    int result;
    object atk;
    int num;
    if (this_player()->query_class() != "rouge"  ||
      this_player()->query_skill("blade") < 200)
    {
	write("The dagger stabs your hand as you attempt to wield it.");
	say((string)this_player()->query_cap_name() + " screams and drops the dagger clutching thier bloody hand!");
	this_player()->force_me("drop dagger");
    }
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num < 100)
    {
	write("Your dagger plunges into"+ atk->query_cap_name() +"'s back!");
	say((string)this_player()->query_cap_name() + " plunges " + atk->query_cap_name() + "'s back!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num >200)
    {
	write("Your dagger slides through"+ atk->query_cap_name() +"'s jaw!");
	say((string)this_player()->query_cap_name() + " slides thier dagger through " + atk->query_cap_name() + "'s jaw, causing it to break!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
} 
