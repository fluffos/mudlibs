#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("renegade");
set_short("Blacktooth Renegade");
set_long("The Blacktooth Renegades are a band of outcasts who secretly plot the "
"takeover of the Merkkirri.  Their numbers are small but their members are "
"cunning and powerful.");
set_id(({"gnoll", "blacktooth", "renegade", "outcast"}));
set_level(35);
set("aggressive", 20);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(50)));
add_money("electrum", (random(75)));
set_emotes(10, ({"The renegade snarls as he grips his hammer.", "The blacktooth spits at you.", "The renegade eyes you intently."}),0);
set_spell_chance(40);
set_spells(({"whirl", "rush"}));
new(MOB "scalemail")->move(this_object());
force_me("wear armor");
new(MOB "bthammer")->move(this_object());
force_me("wield hammer");
set_languages("merkish");
set_speech(25, "merkish", ({"I will impail you with my hammer!", "You've not met an opponent as ruthless as I!"}),1);
set_alignment(0);
}
