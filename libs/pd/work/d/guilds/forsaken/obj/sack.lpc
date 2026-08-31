#include <std.h>

inherit ARMOUR;
inherit BAG;

void init() {
  armour::init();
}

void create() {
    armour::create();
    bag_logic::create();
    set_name("websack");
    set_id( ({ "pack", "sack", "bag", "websack" }) );
    set_short("%^RESET%^%^RED%^S%^BOLD%^p%^BLACK%^i%^RESET%^de%^BOLD%^%^RED%^r%^RESET%^%^RED%^s W%^BOLD%^e%^BLACK%^b%^RESET%^sa%^BOLD%^%^RED%^c%^RESET%^%^RED%^k%^RESET%^");
    set_long("This sack has been sewn from the webbing of an acient Dire Spider.");
    set_mass(3);
    set_curr_value("gold", 50);
    set_max_internal_encumbrance(800);
    set_type("backpack");
    set_limbs( ({"torso"}) );
}

int wierd_move() {
    if(!query_worn()) return 0;
    message("info", "Try removing it first.", 
      environment());
    return 1;
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
