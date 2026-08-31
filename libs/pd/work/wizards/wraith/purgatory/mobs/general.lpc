#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Barbarian General");
   set_short("Barbarian General");
   set_id(({"monster", "barbarian", "general"}));
   set_long("The Generalis an impressive sight. Double headed and with more arms then usual, his muscles ripple under his armour, tell of a well worn warrior that would be hard pressed to lose to any opponent. He has led his troops here to conquer the Castle of Purgatory.");
   set_level(55);
   set("aggressive", 45);
   set_gender("male");
   set_race("raknid");
   set_heart_beat(1);
   set_body_type("raknid");
   set_class("fighter");
   set_subclass("warrior");
   set_skill("attack", 330);
   set_skill("defense", 275);
   set_skill("double wielding", 330);
   set_skill("melee", 275);
   set_skill("discipline", 275);
   set_skill("perception", 220);
   set_skill("stealth", 165);
   set_skill("axe", 330);
   set_skill("blade", 300);
   set_skill("murder", 55);
   set_spell_chance(38);
   set_spells(({"rush", "slash", "hack"}));
   add_limb("second head", "FATAL", 4, 0, 1);   
   add_limb("horse torso", "FATAL", 4, 0, 1);
   set_lang_prof("annarian", 10);
   set_speech(50,"annarian",({"You shall perish for intruding!!",
"The tortures of hell will feel like paradise when I'm done!", "For the HORDE!!"}),1);

new(EQ"leatherplate")->move(this_object());
force_me("wear armour");

new(EQ"platedleggings")->move(this_object());
force_me("wear leggings");

new(WEAP"waraxe")->move(this_object());
force_me("wield axe");

new(WEAP"waraxe")->move(this_object());
force_me("wield axe");

new(WEAP"waraxe")->move(this_object());
force_me("wield axe");

new(WEAP"waraxe")->move(this_object());
force_me("wield axe");
}

