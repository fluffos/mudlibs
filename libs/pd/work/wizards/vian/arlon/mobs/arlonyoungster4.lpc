#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon youngster");
    set_short("An earthy looking youngster");
    set_long("This human youngster looks to be about 14 or 15 years old.  He appears to be training to be a ranger, as he is dressed for the job.  His figure is almost toned, and he looks like he could be pretty tough in a few years.");
    set_id(({"arlon youngster", "youngster", "human youngster", "arlonyoungster4"}));
    set_level(1+random(3));
    set_race("human");
    set_body_type("human");
    set_gender("male");
   new(ARM"chainmailvest")->move(this_object());
     force_me("wear vest");
   new(WEP"thornedspear")->move(this_object());
     force_me("wield spear");
    set_class("fighter");
    set_subclass("ranger");
    add_money("gold", 5+random(30));
    set_spell_chance(10);   
    set_spells(({"impale"}));   
}


