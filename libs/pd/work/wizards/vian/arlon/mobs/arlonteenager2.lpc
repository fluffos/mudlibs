#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon teenager");
    set_short("A smart looking teenager");
    set_long("This human teenager looks to be about 16 or 17 years old.  She appears to be training to be a mage, as she is dressed for the job.  Her figure is very toned, and she looks pretty tough.");
    set_id(({"arlon teenager", "teenager", "human teenager", "arlonteenager2"}));
    set_level(3+random(4));
    set_race("human");
    set_body_type("human");
    set_gender("female");
   new(ARM"dragonhidegloves")->move(this_object());
     force_me("wear gloves");
   new(ARM"leatherboots")->move(this_object());
     force_me("wear boots");
   new(ARM"silkrobe")->move(this_object());
     force_me("wear robe");
   new(ARM"platinumring")->move(this_object());
     force_me("wear ring");
    set_class("mage");
    set_subclass("pyromancer");
    add_money("gold", 5+random(40));
    set_spell_chance(10);   
    set_spells(({"missile"}));   
}


