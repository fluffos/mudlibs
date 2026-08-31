#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Barbarian Warrior");
   set_short("Barbarian Warrior");
   set_id(({"monster", "warrior", "barbarian", "barbarian warrior"}));
   set_long("This barbarian is one of the many who have mastered the weapons of their choice. He is a very dangerous foe in combat.");
   set_swarm("");
   set_level(85+random(15));
   set("aggressive", 30);
   set_gender("male");
   set_race("human");
   set_class("fighter");
   set_subclass("warrior");
   set_body_type("human");
   set_spell_chance(30+random(10));
   set_spells(({"slash"}));

new(WEAP"longsword")->move(this_object());
force_me("wield sword");

new(WEAP"longsword")->move(this_object());
force_me("wield sword");

}
