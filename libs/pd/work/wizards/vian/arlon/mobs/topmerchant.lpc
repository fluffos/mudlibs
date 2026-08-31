#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Top arlon merchant");
    set_short("A very rich merchant");
    set_long("This is the merchant of all merchants.  He is dressed to impress, and looks a bit scarier than the others.");
    set_id(({"arlon merchant", "merchant", "human merchant", "topmerchant", "arlonmerchant"}));
    set_level(4+random(3));
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_class("rogue");
   new(ARM"silkshirt")->move(this_object());
     force_me("wear shirt");
        new(ARM"platinumring")->move(this_object());
     force_me("wear ring");
    set_subclass("thief");
    add_money("gold", 100+random(200));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
}


