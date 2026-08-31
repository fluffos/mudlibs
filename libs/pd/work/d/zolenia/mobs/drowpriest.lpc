#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("drow priest");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^drow%^RESET%^ %^WHITE%^priest");
    set_long("This drow priest isn't weak looking, nor strong.  He is deep in prayer, a disciple of Lloth.");
    set_id(({"drow", "priest", "drowpriest", "drow priest"}));
    set_level(59+random(6));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_gender("male");
    set_class("clergy");
    set_alignment(-500);
    set_subclass("cleric");
   new(ARM"darkrobes")->move(this_object());
     force_me("wear robes");
   new(ARM"darkring")->move(this_object());
     force_me("wear ring");

    add_money("gold", random(400));
    set_spell_chance(25);   
    set_spells(({"lifewarp", "unknit"}));   
}

