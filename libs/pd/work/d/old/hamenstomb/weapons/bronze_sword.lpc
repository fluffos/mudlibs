#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Bronze Sword");
    set("id", ({ "sword" }) );
    set("short", "%^ORANGE%^Bronze %^WHITE%^Sword");
    set("long", "%^ORANGE%^This sword is used by those who protect the %^WHITE%^King, %^ORANGE%^it is sharpened and slices through enemies easily." );
    set_weight(25);
    set_curr_value("gold", 175);
    set_wc(10);
    set_type("blade");
    set_element("element", 30);
    set_decay_rate(5000);
    set_hit( (: this_object(), "weapon_hit" :) );
    set("skill level", 250);
    set_wield((:can_wield:));
}


int can_wield() 
{
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("sword") >= 250)
    {
	write("You feel the need to hunt");

    }
    return 1;
}

int weapon_hit() 
{
    int result;
    object atk;
    int num;
    if (this_player()->query_class() != "figther"  ||
      this_player()->query_skill("blade") < 250)
    {
	write("The sword slices your hand as you attempt to wield it.");
	say((string)this_player()->query_cap_name() + " screams and drops the sword clutching thier bloody hand!");
	this_player()->force_me("drop sword");
    }
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num < 100)
    {
	write("Your sword slices into"+ atk->query_cap_name() +"'s gut!");
	say((string)this_player()->query_cap_name() + " slices " + atk->query_cap_name() + "'s gut, ripping it open!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num >200)
    {
	write("Your sword slides its way through"+ atk->query_cap_name() +"'s waist almost cutting them in half!!");
	say((string)this_player()->query_cap_name() + " slides thier sword through " + atk->query_cap_name() + "'s waist almost cutting you in half!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
} 

int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
