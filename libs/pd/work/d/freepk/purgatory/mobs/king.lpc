#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("King Rakthellios");
   set_short("King Rakthellios");
   set_id(({"monster", "king", "rakthellios", "Rakthellios"}));
   set_long("The current King of Purgatory, he keeps his town in an iron grip of sheer power");
    set_level(90);
   set_gender("male");
   set_race("sauran");
   set_body_type("sauran");
   set_class("mage");
   set_subclass("necromancer");
   set_spell_chance(40);
   set_alignment(-800);
   set_spells(({"deathtouch", "soulburn"}));
   set_emotes(2,({ "The King shifts slightly on his throne. ", "Then King gives the Queen an appraising look." }),0);



new(WEAP"deadlygauntlets")->move(this_object());
force_me("wield gauntlets");

new(EQ"royalarmour")->move(this_object());
force_me("wear armour");

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
