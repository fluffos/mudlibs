#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("King Rakthellios");
   set_short("King Rakthellios");
   set_id(({"monster", "king", "rakthellios", "Rakthellios"}));
   set_long("The current King of Purgatory, he keeps his town in an iron grip of sheer power");
   set_level(100);
   set("aggressive", 45);
   set_gender("male");
   set_race("lich");
   set_heart_beat(1);
   set_body_type("lich");
   set_class("mage");
   set_subclass("necromancer");
   set_spell_chance(35);
   set_alignment(-800);
   set_skill("attack", 250);
   set_skill("defense", 250);
   set_skill("murder", 100);
   set_skill("conjuring", 1000);
   set_skill("magic attack", 900);
   set_skill("magic defense", 900);
   set_skill("necromancy", 900);
   set_skill("melee", 250);
   set_skill("faith", 900);
   set_skill("healing", 450);
   set_spells(({"shadowburst", "chaoswave", "annihilate", "disease"}));
   set_emotes(2,({ "The King shifts slightly on his throne. ", "Then King gives the Queen an appraising look." }),0);



new(WEAP"deadlygauntlets")->move(this_object());
force_me("wield gauntlets");

new(EQ"royalarmour")->move(this_object());
force_me("wear armour");

new(EQ"royalsocks")->move(this_object());
force_me("wear socks");

new(EQ"royalpants")->move(this_object());
force_me("wear pants");

new(EQ"royalboots")->move(this_object());
force_me("wear boots");

new(EQ"royalshield")->move(this_object());
force_me("wear shield");

new(EQ"royalgloves")->move(this_object());
force_me("wear gloves");

new(EQ"royalcloak")->move(this_object());
force_me("wear cloak");
}
