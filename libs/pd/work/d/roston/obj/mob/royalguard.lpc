#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("Guard");
    set_short("Prince's Royal Guard");
    set_long("The prince's Royal guard is here to protect "
      "the prince from anyone who trys to kill him.");
    set_id(({"guard", "royal guard"}));
    set_level(35);
    new(WEP"battleaxe")->move(this_object());
    new(WEP"battleaxe")->move(this_object());
    set_race("dwarf");
    set_body_type("human");
    set_swarm("Prince");
    set_gender("male");
    this_object()->force_me("wield axe");
    this_object()->force_me("wield axe 2");
} 
