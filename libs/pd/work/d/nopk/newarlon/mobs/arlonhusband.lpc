#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon husband");
    set_short("A tall and attractive looking husband");
    set_long("Standing before you is a very attractive and tall man.  His hair is short, dark brown, and cleanly cut.  His facial hair is a short stubble, and his mouth is open to show a perfect smile of pearly white teeth.");
    set_id(({"arlon husband", "husband", "human husband", "arlonhusband"}));
    set_level(6+random(2));
    set_race("human");
    set_body_type("human");
    set_gender("male");
   new(ARM"leatherboots")->move(this_object());
     force_me("wear boots");
   new(ARM"silkshirt")->move(this_object());
     force_me("wear shirt");
   new(ARM"platinumring")->move(this_object());
     force_me("wear ring");
    set_class("fighter");
    set_subclass("ranger");
    add_money("gold", 50+random(80));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
}


