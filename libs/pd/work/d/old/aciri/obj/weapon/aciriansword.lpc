//Weapon made using Nightshade's builder

#include <std.h>
#include <aciri.h>

inherit WEAPON;

void create() {
    ::create();
    set_id( ({"sword","acirian sword"}) );
    set_name("acirian sword");
    set_short("an acirian sword");
    set_long("The Acirian Sword is pretty plain.  It has a golden hilt and silver blade, mined from the Acirian mines.  It does not look very reliable.");
    set_mass(9);
    set_value(10);
    set_wc(5);
    set_type("blade");
}

int query_auto_load() {
    if(this_player()->query_level() < 30) return 0;
    return 1;
}

