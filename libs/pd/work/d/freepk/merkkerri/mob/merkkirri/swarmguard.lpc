#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("guard");
set_short("Tower Guard");
set_long("The Merkkirri tower guards are well trained fighters more than capable of defending the palace if needed.  They are excellent watchmen and usually fight first, ask questions later.");
set_id(({"gnoll", "tower guard", "guard", "merkkirri", "merkkirri guard", "merkkirri gnoll"}));
set_level(28);
set_swarm("guard");
set("aggressive", 20);
set_heart_beat(1);
set_skill("projectile", 145);
set_skill("attack", 140);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(50)));
add_money("electrum", (random(75)));
set_emotes(10, ({"The guard grips his spear a bit tighter.", "The guard shifts slightly."}),0);
set_class("fighter");
set_spell_chance(40);
set_spells(({"parry", "rush", "stun"}));
new(MOB "banded")->move(this_object());
command("wear armor");
new(MOB "merkspear")->move(this_object());
command("wield spear");
set_languages("merkish");
set_speech(10,"merkish",({"The Merkkirri must not fall!", "Death to our enemies!", "Intruder! Intruder!"}),1);
set("alignment", -1000);

}
