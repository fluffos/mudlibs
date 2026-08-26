#include <mudlib.h>

inherit WEAPON;

void create() {
    set("id", ({ "dagger", "fork" }) );
    set("short", "A fork");
    set("long", @PicklE
This is the most leathal weapon in all of Foodsburg. It's feared 
throughout the land as steel death.
PicklE
    );
    set("name", "fork");
    set_weapon_type("dagger");
    set_verbs(({ "slash", "stab", "cut" }));
    set("value", 10);
}
int hit_func (object attacker, int damage) {
   if (attacker->query("race") == "dessert") damage *=2;

return damage;
}
