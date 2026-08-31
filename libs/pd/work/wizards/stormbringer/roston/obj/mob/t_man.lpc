#include <std.h>
#include <roston.h>

inherit MONSTER;

void create() {
::create();
    set_name("townsman");
    set_short("Townsman");
    set_long("A Rostonian out hunting for wood.");
    set_id(({"townsman", "dwarf"}));
    set_level(25+random(5));
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    new(WEP"axe")->move(this_object());
    force_me("wield axe");
    add_money("gold", (25+random(30)));
}                                    

                                   
