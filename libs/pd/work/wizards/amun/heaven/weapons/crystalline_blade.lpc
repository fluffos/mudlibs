#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Crystalline Blade");
    set("id", ({ "sword", "blade", "crystalline blade" }) );
    set("short", "%^BOLD%^%^WHITE%^Cr%^CYAN%^y%^WHITE%^st%^CYAN%^a%^WHITE%^ll%^CYAN%^i%^WHITE%^n%^CYAN%^e %^WHITE%^Bl%^CYAN%^a%^WHITE%^d%^CYAN%^e%^RESET%^");
    set("long", "%^BOLD%^%^CYAN%^This blade was made by the Father of Heaven for his gods and goddesses.%^RESET%^");
    set_weight(40);
    set_curr_value("gold", 200);
    set_wc(14);
    set_type("blade");
    set_decay_rate(200);
    set("skill level", 250);
}
int query_auto_load() {
    if (this_player()->query_level() >= 55)
	return 1;
}
int can_wield() {
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("sword") >= 118)
    {
	write("%^BOLD%^%^CYAN%^The blade shimmers as you wield it.");
    }
    return 1;
}

int weapon_hit() 
{
    int result;
    object atk;
    int num;
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("blade") < 118)
    {
	write("The blade grows dull and heats up.");
	say((string)this_player()->query_cap_name() + " screams and drops the sword clutching thier hot hand!");
	this_player()->force_me("drop sword");
    }
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num < 100)
    {
	write("Your blade slashes deep into"+ atk->query_cap_name() +"'s face!");
	say((string)this_player()->query_cap_name() + " slashes " + atk->query_cap_name() + "'s face open makeing blood splurt everywhere!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
    num = random(200);
    atk = (object)this_player()->query_current_attacker();
    if(num >200)
    {
	write("Your blade guts"+ atk->query_cap_name() +"'s stomach!");
	say((string)this_player()->query_cap_name() + " guts " + atk->query_cap_name() + "'s stomach, ripping out its insides!");
	result = 10 +random(30);
	this_player()->add_sp(result);
	return result;
    }
    return 0; 
} 
