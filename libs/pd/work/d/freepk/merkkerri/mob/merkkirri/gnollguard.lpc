#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("guard");
    set_short("Merkkirri Guard");
    set_long("The Merkkirri gnolls make this part of the jungle their home.  These are the guards who keep an eye out for unwelcome visitors.  They use long spears that hook at the tip and are fairly well armored.  They aren't well known for their hospitality.");
    set_id(({"gnoll", "guard", "merkkirri", "merkkirri guard", "merkkirri gnoll"}));
    set_level(25);
    set_heart_beat(1);
    set_skill("projectile", 125);
    set_skill("attack", 75);
    set_race("gnoll");
    set_body_type("gnoll");
    set_gender("male");
    add_money("gold", (random(50)));
    add_money("electrum", (random(75)));
    set_emotes(10, ({"The guard grips his spear a bit tighter.", "The guard scans the jungle for intruders."}),0);
    set_spell_chance(40);
    set_spells(({"parry", "headbutt"}));
    new(MOB "banded")->move(this_object());
    command("wear armor");
    new(MOB "merkspear")->move(this_object());
    command("wield spear");
    set_languages("merkish");
    set_speech(10,"merkish",({"The Merkkirri must not fall!", "Death to our enemies!", "Intruder! Intruder!"}),1);
    set("alignment", -1000);
}
