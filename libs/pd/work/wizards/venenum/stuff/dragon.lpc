
#include <std.h>
#include <sakura.h>
inherit MONSTER;

int riddle = 1;

void create() {
    ::create();
    set_name("quex'trilixil");
    set_short("Quex'trilixil the Red");
    set_id(({"quextrilixil", "red", "dragon"}));
    set_level(200);
    set_race("dragon");
    set_body_type("dragon");
    set_class("dragon");
    set_subclass("red");
    set_gender("female");
     set_long("No desc.");
    set_max_hp(query_max_hp()*4);
    set_hp(query_max_hp());

    set_spells( ({ "breathe", "roar" }) );

    set_die( (: call_other, this_object(), "death_func":) );

    set_spell_chance(33);

    set_alignment(-200);
    set_money("platinum", 20000+random(10000));
    set_money("gold", 900000+random(100000));
    set_money("electrum", 20000+random(20000));
    set_money("silver", 20000+random(10000));
    set_money("copper", 40000+random(20000));

    set_properties(([
        "no steal" : 1,
        "no bump" : 1,
        "no magic" : 1,
      ]));

}

int death_func() {
return 1;
}
