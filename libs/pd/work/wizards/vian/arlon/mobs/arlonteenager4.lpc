#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon teenager");
    set_short("An earthy looking teenager");
    set_long("This human teenager looks to be about 15 or 16 years old.  She appears to be training to be a ranger, as she is dressed for the job.  Her figure is very toned, and she looks pretty tough.");
    set_id(({"arlon teenager", "teenager", "human teenager", "arlonteenager4"}));
    set_level(3+random(4));
    set_race("human");
    set_body_type("human");
    set_gender("female");
   new(ARM"dragonhidegloves")->move(this_object());
     force_me("wear gloves");
   new(ARM"leatherboots")->move(this_object());
     force_me("wear boots");
   new(ARM"chainmailvest")->move(this_object());
     force_me("wear vest");
   new(WEP"thornedspear")->move(this_object());
     force_me("wield spear");
    set_class("fighter");
    set_subclass("ranger");
    add_money("gold", 5+random(40));
    set_spell_chance(10);   
    set_spells(({"impale"}));   
}


