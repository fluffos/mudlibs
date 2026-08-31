#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon teenager");
    set_short("A sketchy looking teenager");
    set_long("This human teenager looks to be about 18 or 19 years old.  He seems like a sketchy kid, perhaps a rogue.  His figure is very toned, and he looks pretty tough.");
    set_id(({"arlon teenager", "teenager", "human teenager", "arlonteenager3"}));
    set_level(3+random(4));
    set_race("human");
    set_body_type("human");
    set_gender("male");
   new(ARM"dragonhidegloves")->move(this_object());
     force_me("wear gloves");
   new(ARM"leatherboots")->move(this_object());
     force_me("wear boots");
   new(ARM"silkshirt")->move(this_object());
     force_me("wear shirt");
   new(WEP"twisteddagger")->move(this_object());
     force_me("wield dagger");
    set_class("rogue");
    set_subclass("assassin");
    add_money("gold", 5+random(40));
    set_spell_chance(10);   
    set_spells(({"stab"}));   
}


