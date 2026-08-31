#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
::create();
    set_name("Royal Knight");
    set_short("Royal Knight");
    set_long("The royal knight is here to protect the prince.");
    set_id(({"knight", "royal knight"}));
    set_level(38+random(5));
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
