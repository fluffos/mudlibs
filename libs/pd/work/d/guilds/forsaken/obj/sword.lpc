#include <std.h>
#include <damage_types.h>

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
    set_wc(1);
    set_hands(1);
    set_damage_type(DAMAGE_SLASH | DAMAGE_FIRE);
    set_wield("%^BOLD%^%^WHITE%^You feel an urge to cause Havoc and Pain.%^RESET%^");
    set_unwield("%^BOLD%^%^WHITE%^You feel more relaxed.%^RESET%^");
    set_ac(1);
}

int wield() {
    if (this_player()->query_guild() == "forsaken") return 1;
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
