#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow master priest");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ master %^WHITE%^priest");
    set_long("This drow priest is very strong, looking deep in prayer.  He is the direct disciple of Lloth.");
    set_id(({"drow", "priest", "master", "drowmasterpriest", "drow master priest", "drowpriest", "drow priest"}));
    set_level(90+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_class("clergy");
    set_alignment("-1000");
    set_subclass("cleric");
   new(ARM"darkrobes")->move(this_object());
     force_me("wear robes");
   new(ARM"darkring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(400));
    set_spell_chance(25);   
    set_spells(({"lifewarp", "shield"}));   
}

