#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Tibinus");
    set_short("%^BOLD%^%^YELLOW%^Tibinus, the Newbie Trainer");
    set_long("Tibinus is a very old man, who looks both wise and strong.  He has long white hair, and half-moon glasses.  He wields a sword and a staff, and is wearing robes.  He looks like he is very wise about all sorts of things.");
    set_id(({"tibinus"}));
    set_level(100+random(100));
    set_race("human");
    set_body_type("human");
    set_gender("male");
   new(WEP"sharpsword")->move(this_object());
     force_me("wield sword");
   new(WEP"woodenstaff")->move(this_object());
     force_me("wield staff");
   new(ARM"silkrobe")->move(this_object());
     force_me("wear robe");
   new(ARM"platinumring")->move(this_object());
     force_me("wear ring");
    add_money("gold", random(200));  
}


