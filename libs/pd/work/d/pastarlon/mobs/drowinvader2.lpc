#include <std.h>
#include <pastarlon.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow invader");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ invader");
    set_long("This drow invader is one of the stronger guards of Zolenia, stationed in Arlon.  He is wearing what could be scavenged for an invading force.");
    set_id(({"drow", "invader", "drowinvader", "drow invader"}));
    set_level(49+random(4));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_alignment(-500);
    set_class("clergy");
    set_subclass("monk");
   new(ARM"spikedgloves")->move(this_object());
     force_me("wear gloves");
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
    set_spells(({"slash", "warblade"}));   
}


