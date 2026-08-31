#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon youngster");
    set_short("A sketchy looking youngster");
    set_long("This human teenager looks to be about 12 or 13 years old.  She seems like a sketchy kid, perhaps a rogue.  Her figure is almost toned, and she looks like she could be pretty tough in a few years.");
    set_id(({"arlon youngster", "youngster", "human youngster", "arlonyoungster3"}));
    set_level(1+random(3));
    set_race("human");
    set_body_type("human");
    set_gender("female");
   new(ARM"silkshirt")->move(this_object());
     force_me("wear shirt");
   new(WEP"twisteddagger")->move(this_object());
     force_me("wield dagger");
    set_class("rogue");
    set_subclass("assassin");
    add_money("gold", 5+random(30));
    set_spell_chance(10);   
    set_spells(({"stab"}));   
}


