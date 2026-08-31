#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon shopper");
    set_short("A slightly obese shopper");
    set_long("This short, plump woman is in the Arlon trade district, looking for some good shopping.");
    set_id(({"arlon shopper", "shopper", "human shopper", "arlonshopper2"}));
    set_level(1+random(3));
    set_race("human");
    set_body_type("human");
    set_gender("female");
   new(OBJ"shoppingbag")->move(this_object());
   new(ARM"silkdress")->move(this_object());
     force_me("wear dress");
    set_class("fighter");
    set_subclass("warrior");
    add_money("gold", random(200));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
}


