// New potions by Chopin. 2/7/1997

#include <drink.h>
#include <player_defs.h>

#define MIN_HEAL 20
#define MAX_HEAL 40
#define MAX_AMOUNT 6

void create_drink() {
    set_name("potion of heal fp and hp");
    set_long("A fine crystal bottle with some writing on it.");
    set_id( ({"potion"}) );
    set_liquid("magic potion");
    set_soft(1);
    set_strength(1);
    set_no_heal(1);
    set_max_full(MAX_AMOUNT);
    set_drinker_mess("You finish quaffing the potion and feel much more vigorous!");
    set_full(MAX_AMOUNT);
    set_read("The label says: Drink this potion if you want more fatigue and hit points.");
    set_container_value(18);
    set_cost(660);
    set_weight(1);
}

void extra_drink() {
    int effect;

    effect = random(MAX_HEAL - MIN_HEAL + 1) + MIN_HEAL;
    this_player()->add_fp(effect);
    this_player()->add_hp(effect);
}
