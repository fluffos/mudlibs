#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Barbarian");
   set_short("Barbarian");
   set_id(({"monster", "barbarian"}));
   set_long("This barbarian is of the lowest rank, just having joined the Horde, he has not had time to achieve any honor. He is constantly in search of new foes to conquer.");
   set_level(35+random(10));
   set("aggressive", 25);
   set_gender("male");
   set_race("human");
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("human");
   set_spell_chance(35);
   set_spells(({"slash"}));
   set_emotes(2,({ "The Barbarian grumbles something about honor." }),0);

new(WEAP"battleaxe")->move(this_object());
force_me("wield axe");

new(WEAP"battleaxe")->move(this_object());
force_me("wield axe");
}
