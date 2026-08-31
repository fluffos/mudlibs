#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("guard");
set_short("Merkkirri Guard");
set_long("The Merkkirri gnolls make this part of the jungle their home.  These are the guards who keep an eye out for unwelcome visitors.  They use long spears that hook at the tip and are fairly well armored.  However, these particular guards seem to have been disturbed in their sleep and are unequipped.");
set_id(({"gnoll", "guard", "merkkirri", "merkkirri guard", "merkkirri gnoll"}));
set_level(25);
set_heart_beat(1);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(50)));
add_money("electrum", (random(75)));
set_emotes(5, ({"The guard growls as his sleep is disturbed.", "The guard lazily prepares for battle."}),0);
set_spell_chance(40);
set_spells(({"choke"}));
command("wear armor");
command("wield spear");
set_languages("merkish");
set_speech(20,"merkish",({"The Merkkirri must not fall!", "Death to our enemies!", "Intruder! Intruder!"}),1);
set("alignment", -1000);
}
