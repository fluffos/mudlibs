#include <std.h>
#include <roston.h>

inherit "/std/police";

void create() {
::create();
    set_name("guard");
    set_short("Roston Guard");
    set_long("A town guard standing watch.");
    set_id(({"dwarf", "guard"}));
    set_level(25+random(5));
    new(WEP"axe")->move(this_object());
    force_me("wield axe");
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    add_money("gold", (25+random(30)));
}