#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Black Sword");
    set("id", ({ "sword", "blade", "black sword", "black" }) );
    set("short", "%^BOLD%^%^BLACK%^Black Sword%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This sword was made by the She raknid, It is well crafted having been done by a spider.%^RESET%^" );
    set_weight(40);
    set_curr_value("gold", 200);
    set_wc(14);
    set_type("blade");
    set_decay_rate(5000);
    set("skill level", 250);
    set_hit((:this_object(),"weapon_hit":));
}
int can_wield() {
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("blade") >= 249)
    {
	write("%^BOLD%^%^BLACK%^The sword forms to your hand as if it were made for you.%^RESET%^");
    }
    return 1;
}
int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 90) {
	write("%^BOLD%^%^BLACK%^Your sword %^RED%^s%^BLACK%^l%^RED%^a%^BLACK%^s%^RED%^h%^BLACK%^e%^RED%^s %^BLACK%^deep into "+atk->query_cap_name()+"'s face!%^RESET%^");
	say((string)this_player()->query_cap_name()+" %^BOLD%^%^RED%^s%^BLACK%^l%^RED%^a%^BLACK%^s%^RED%^h%^BLACK%^e%^RED%^s%^BLACK%^ " + atk->query_cap_name() +"'s %^BOLD%^%^BLACK%^face open, making %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^d %^BLACK%^s%^RED%^p%^BLACK%^l%^RED%^u%^BLACK%^r%^RED%^t %^BLACK%^everywhere!%^RESET%^");
	result=(random(50))+((this_player()->query_level())*2/3);
	if(random(100) > 74) {
	    write("%^BOLD%^%^BLACK%^Your sword %^RED%^g%^BLACK%^u%^RED%^t%^BLACK%^s "+atk->query_cap_name()+"'s stomach!%^RESET%^");
	    say((string)this_player()->query_cap_name()+" %^BOLD%^%^RED%^g%^BLACK%^u%^RED%^t%^BLACK%^s "+atk->query_cap_name()+"'s stomach, %^BOLD%^%^RED%^r%^BLACK%^i%^RESET%^%^RED%^p%^BOLD%^%^BLACK%^p%^BOLD%^%^RED%^i%^BLACK%^n%^RESET%^%^RED%^g %^BOLD%^%^BLACK%^out their insides!%^RESET%^");
	    atk->set_paralyzed(random(2));
	    result = 150 +random(30);
	    this_player()->add_sp(result);
	    return result;
	}
    }
}
int query_auto_load() {
    if (this_player()->query_level() >= 60)
	return 1;
}
