#include <std.h>
#include <guild.h>
inherit ARMOUR;
inherit BAG;

void init() {
    armour::init();
}

void create() {
    armour::create();
    bag_logic::create();
    set_id( ({"skull", "pack", "bag", "bloody skull", "a bloody skull"}) );
    set_name("bloody skull");
    set_short("%^BOLD%^%^BLACK%^A %^RED%^B%^RESET%^%^RED%^l%^BOLD%^%^RED%^oody %^BLACK%^Skull%^RESET%^");
    set_weight(20);
    set_long("%^BOLD%^%^BLACK%^As you look at this large %^WHITE%^s%^RED%^k%^WHITE%^ull %^BLACK%^you see %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood %^BLACK%^still dripping off of it. You could probably put something in the skull.");
    set_curr_value("gold", 100);
    set_max_internal_encumbrance(400);
    set_possible_to_close(1);
    set_type("backpack");
    set_limbs( ({"torso"}) );

}

int query_auto_load() {
    if(this_player()->query_original_guild() == "unholy")
	return 1;
}
