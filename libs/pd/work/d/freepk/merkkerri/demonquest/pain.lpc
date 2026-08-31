#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("pain");
set_short("A winged demon");
set_long("%^BOLD%^BLACK%^The demon is tall and slender with charcol black skin and glistening black teeth and claws.  This demon bears the mark of pain upon its chest.%^RESET%^");
set("aggressive", 0);
set_id(({"pain", "winged demon", "demon of pain", "demon"}));
set_class("fighter");
set_subclass("antipaladin");
set_alignment(-1000);
set_race("demon");
set_body_type("demon");
set_gender("neuter");

set_spell_chance(30);
set_spells(({"rush", "stun"}));
set_speech(50,"demonish",({"My lord will have less mercy on you than I...", "Death will be the most pleasurable part of your fate!", "Feel the powers of Hell upon you!"}),1);
set_level(70);
}
