#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon merchant");
    set_short("A rich merchant");
    set_long("This merchant peddles in the shopping district of Arlon, trying to buy items for much cheaper than he would sell them for.  Poor newbies...");
    set_id(({"arlon merchant", "merchant", "human merchant", "arlonmerchant"}));
    set_level(1+random(3));
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_class("rogue");
   new(ARM"leatherboots")->move(this_object());
     force_me("wear boots");
   new(ARM"silkshirt")->move(this_object());
     force_me("wear shirt");
    set_subclass("thief");
    add_money("gold", 50+random(200));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
}


