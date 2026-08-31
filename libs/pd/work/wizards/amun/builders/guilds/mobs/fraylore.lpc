#include <std.h>
#include <guild.h>
#include <boat.h>
#include <daemons.h>
inherit "/std/vendor";
void create() {
    ::create();
    set_name("fraylore");
    set_id(({ "monster", "mob", "fraylore", "fray" }));
    set_short("Fraylore, the Weapon's Master");
    set("aggressive", 0);
    set_level(30);
    set_long("Fraylore stands at an amazing 7 feet tall and has a large scar stretching from his right eye down to the base of his neck. He is usually making sure his weapons are spotless and ready to be sold to anyone who is worthy.");
    set_type(({ "weapon" }));
    set_gender("male");
    set_alignment(-100);
    set("race", "human");
    add_money("gold", random(300));
    set_exp(1);
    set_body_type("human");
    set_currency("gold");
    set_storage_room("/wizards/amun/builders/guilds/rooms/wepstorage");
    set_skill("melee", 100);
    set_skill("bargaining", 75);
    set_property("no bump", 1);
}
