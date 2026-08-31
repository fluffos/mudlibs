#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                
int weapon_hit(object atk);
void create() {
    ::create();                                                                    
    set_name("Pumpkin");
    set("id", ({ "pumpkin" }) );
    set("short", 
      "%^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^This pumpkin is lit with fire.  The Headless horeseman will surely want it back some day." );
    set_type("projectile");
    set_weight(10);
    set_curr_value("gold", 75);
    set_wc(6);
    set_type("projectile");
    set("skill level", 115);
    set_wield("%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^cackles as you wield it.%^RESET%^");
    set_unwield("%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^stops cackling as you release it.%^RESET%^");
    set_hit( (: weapon_hit :) );

}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
int can_wield() {
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("projectile") >= 145)
    {
	write("%^BOLD%^%^BLACK%^The pumpkin lights you hand on fire, and yet you don't feel a thing.");
    }
    return 1;
}

int weapon_hit(object atk) 
{
    int result;
    int num;
    if (this_player()->query_class() != "fighter"  || 
      this_player()->query_skill("projectile") < 115)
    {
	write("The pumpkin lights your hand on fire causing it to burn.");
	say((string)this_player()->query_cap_name() + " screams and drops the pumpkin and clutches thier burt hand!");
	this_player()->force_me("drop pumpkin");
    }
    num = random(200);
    //    write("Num: "+num+"");
    if(num > 100)
    {
	write("%^BOLD%^%^BLACK%^You throw the %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^into "+ atk->query_cap_name() +"'s face, setting them on %^RED%^fire%^BLACK%^!%^RESET%^");
	say((string)this_player()->query_cap_name() + " %^BOLD%^%^BLACK%^throws the %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^into " + atk->query_cap_name() + "'s face setting them on %^RED%^fire%^BLACK%^!%^RESET%^");
	result = 10 +random(50);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
    num = random(200);
    if(num >150)
    {
	write("%^BOLD%^%^BLACK%^You notice the %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^jumps to life and lunges at "+ atk->query_cap_name() +"'s causing them to %^RED%^engulf in flames%^BLACK%^!%^RESET%^");
	say((string)this_player()->query_cap_name() + " %^BOLD%^%^BLACK%^notices the %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^jump to life and lunge at " + atk->query_cap_name() + " causing them to %^RED%^engulf in flames%^BLACK%^!%^RESET%^");
	result = 10 +random(50);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
} 
