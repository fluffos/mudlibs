#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon teenager");
    set_short("A tough looking teenager");
    set_long("This human teenager looks to be about 17 or 18 years old.  He appears to be training to be a warrior or guard, as he is dressed for the job.  His figure is very toned, and he looks pretty tough.");
    set_id(({"arlon teenager", "teenager", "human teenager", "arlonteenager"}));
    set_level(3+random(3));
    set_race("human");
    set_body_type("human");
    set_gender("male");
   new(WEP"sharpsword")->move(this_object());
     force_me("wield sword");
   new(ARM"chainmailhelm")->move(this_object());
     force_me("wear helm");
   new(ARM"chainmailvest")->move(this_object());
     force_me("wear vest");
    set_class("fighter");
    set_subclass("warrior");
    add_money("gold", 5+random(40));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
}


