#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon youngster");
    set_short("A tough looking youngster");
    set_long("This human youngster looks to be about 13 or 14 years old.  She appears to be training to be a warrior or guard, as she is dressed for the job.  Her figure is almost toned, and she looks like she could be pretty tough in a few years.");
    set_id(({"arlon youngster", "youngster", "human youngster", "arlonyoungster"}));
    set_level(1+random(3));
    set_race("human");
    set_body_type("human");
    set_gender("female");
   new(WEP"sharpsword")->move(this_object());
     force_me("wield sword");
   new(ARM"chainmailhelm")->move(this_object());
     force_me("wear helm");
    set_class("fighter");
    set_subclass("warrior");
    add_money("gold", 5+random(30));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
}


