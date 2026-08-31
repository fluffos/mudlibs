#include <std.h>
#include <pastarlon.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow invader");
    set_short("%^RESET%^%^BOLD%^Master %^RESET%^%^BLACK%^%^BOLD%^Drow%^RESET%^ Invader");
    set_long("This drow invader seems a bit bigger than the rest.  He has an aura of power around him, as if he is in charge of something.");
    set_id(({"drow", "invader", "master invader", "master", "masterdrowinvader", "master drow invader", "drow invader"}));
    set_level(144+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_alignment(-500);
    set_class("fighter");
    set_subclass("antipaladin");
    new("/wizards/vian/event/blackshard")->move(this_object());
    new(WEP"deathbringer")->move(this_object());
     force_me("wield deathbringer");
   new(ARM"bloodyboots")->move(this_object());
     force_me("wear boots");
   new(ARM"dragonscalegloves")->move(this_object());
     force_me("wear gloves");
   new(ARM"tatteredrags")->move(this_object());
     force_me("wear rags");
   new(ARM"dragonscalering")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(1000));
    set_spell_chance(25);   
    set_spells(({"flog", "whip"}));   
}
