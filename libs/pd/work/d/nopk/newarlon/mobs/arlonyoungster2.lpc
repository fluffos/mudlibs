#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon youngster");
    set_short("A smart looking youngster");
    set_long("This human teenager looks to be about 11 or 12 years old.  He appears to be training to be a mage, as he is dressed for the job.  His figure is almost toned, and he looks like he could be pretty tough in a few years.");
    set_id(({"arlon youngster", "youngster", "human youngster", "arlonyoungster2"}));
    set_level(1+random(3));
    set_race("human");
    set_body_type("human");
    set_gender("male");
   new(ARM"silkrobe")->move(this_object());
     force_me("wear robe");
   new(ARM"platinumring")->move(this_object());
     force_me("wear ring");
    set_class("mage");
    set_subclass("pyromancer");
    add_money("gold", 5+random(30));
    set_spell_chance(10);   
    set_spells(({"missile"}));   
}


