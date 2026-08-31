#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
::create();
    set_name("Royal Guard");
    set_short("Prince's Royal Guard");
    set_long("The royal guard is here to protect the prince.");
    set_id(({"guard", "royal guard"}));
    set_level(35+random(8));
    add_money("gold", (25+random(25)));
    new(WEP"battleaxe")->move(this_object());
    force_me("wield axe");
    new(WEP"battleaxe")->move(this_object());
    force_me("wield axe 2");
    set_race("dwarf");
    set_body_type("human");
    set_swarm("Prince");
    set_gender("male");
}                                       
