#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon warehouse worker");
    set_short("A burly looking warehouse worker");
    set_long("This large burly man is very tall and muscular.  He has dark brown hair and facial hair.  His largeness makes him seem scary, but he has boyish features and a nervous smile.");
    set_id(({"arlon warehouse worker", "warehouse worker", "worker", "arlonwarehouseworker"}));
    set_level(6+random(2));
    set_race("human");
    set_body_type("human");
    set_gender("male");
   new(ARM"blueoveralls")->move(this_object());
     force_me("wear overalls");
   new(ARM"mageweaveshirt")->move(this_object());
     force_me("wear shirt");
    set_class("wanderer");
    set_subclass("swashbuckler");
    add_money("gold", 25+random(75));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
}


