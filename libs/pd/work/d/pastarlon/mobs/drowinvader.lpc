#include <std.h>
#include <pastarlon.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow invader");
    set_short("%^RESET%^%^BOLD%^invading %^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ warrior");
    set_long("This drow invader is one of the stronger guards of Zolenia, stationed in Arlon.  He is wearing what could be scavenged for an invading force.");
    set_id(({"drow", "invader", "drowinvader", "warrior", "warrior invader", "drow invader"}));
    set_level(49+random(4));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_alignment(-500);
    set_class("fighter");
    set_subclass("warrior");
   new(WEP"darkblade")->move(this_object());
     force_me("wield blade");
        new(WEP"darkknife")->move(this_object());
     force_me("wield knife");
   new(ARM"flamingshirt")->move(this_object());
     force_me("wear shirt");
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


