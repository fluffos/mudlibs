//Weapon made using Nightshade's builder

#include <std.h>
#include <aciri.h>

inherit ARMOUR;

void create() {
    ::create();
    set_id( ({"armor","acirian armor"}) );
    set_name("acirian armor");
    set_short("a suit of acirian armor");
    set_long("The acirian armor is a heavy, chain/platemail hybrid.  It offers adequate protection.");
    set_mass(50);
    set_value(12);
    set_type("body armor");
    set_limbs( ({"torso","right arm","left arm","left leg","right leg"}) );

}

int query_auto_load() {
    if(this_player()->query_level() < 30) return 0;
    return 1;
}

