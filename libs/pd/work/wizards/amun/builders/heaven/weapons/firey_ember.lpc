#include <std.h>
#include <amun.h>
inherit WEAPON;                                                         
void create() {
    ::create();                                                             
    set_name("Firey Ember");
    set("id", ({ "firey ember", "ember", "flail" }) );
    set("short", "%^BOLD%^%^BLACK%^Fi%^RESET%^%^RED%^re%^ORANGE%^y E%^RED%^mb%^BOLD%^%^BLACK%^er%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This %^RESET%^%^ORANGE%^em%^RED%^b%^BOLD%^%^BLACK%^er was made in the underworld and given to its servents. It looks as though it could bust with fire any second.%^RESET%^" );
    set_type("flail");
    set_weight(10);
    set_curr_value("gold", 75);
    set_wc(6);
    set_type("flail");
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
      this_player()->query_skill("flail") >= 115)
    {
	write("%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^em%^RED%^b%^BOLD%^%^BLACK%^er feels unnaturally cool on your hand.%^RESET%^");
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
	write("%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^em%^RED%^b%^BOLD%^%^BLACK%^er burns your hand!%^RESET%^");
	say((string)this_player()->query_cap_name() + " screams and drops the ember and clutches their burnt hand!");
	this_player()->force_me("drop ember");
    }
}
