#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_name("Tainted Sword");
    set_short("%^RED%^T%^BOLD%^%^BLACK%^ain%^%^RESET%^%^RED%^t%^BOLD%^BLACK%^ed%^RESET%^ %^RED%^S%^BOLD%^%^BLACK%^word%^RESET%^");
    set_long("This blade looks different to all the other blades you have seen. It has a short %^BOLD%^BLACK%^black hilt%^RESET%^ and a long soft glowing %^RED%^red blade%^RESET%^. It glows as if it has been bleesed by the Demon's of the Realm.");
    set_id(({"sword", "tainted sword"}));
    set_mass(39);
    set_curr_value("gold", 2100);
    set_type("blade");
    set_wc(12);
    set_hands(1);
    set_element("fire", 21);
    set_wield("%^BOLD%^%^WHITE%^You feel an urge to cause Havoc and Pain.%^RESET%^");
    set_unwield("%^BOLD%^%^WHITE%^You feel more relaxed.%^RESET%^");
    set_hit((:this_object(),"weapon_hit":));
    set_ac(1);
}

int weapon_hit() {
    int result;
    object ob;
    ob=(object)this_player()->query_current_attacker();
     if(random(100) > 80) {
	result=((this_player()->query_stat("strength")+this_player()->query_skill("blade"))-((this_player()->query_current_attacker()->query_stat("constitution")+this_player()->query_current_attacker()->query_skill("defense"))/2));
	write("%^BOLD%^%^WHITE%^Your %^RESET%^%^RED%^T%^BOLD%^%^BLACK%^ain%^%^RESET%^%^RED%^t%^BOLD%^BLACK%^ed%^RESET%^ %^RED%^S%^BOLD%^%^BLACK%^word%^RESET%^ %^BOLD%^WHITE%^slices into "+this_player()->query_current_attacker()->query_cap_name()+" causeing them great pain!%^RESET%^", this_player());
        this_player()->add_hp(result/5);
	return result;
    }
}

int wield() {
    if (this_player()->query_guild() == "forsaken") return 1;
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
