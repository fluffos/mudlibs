#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Dark Archer");
   set_short("%^BOLD%^%^BLACK%^Dark Archer%^RESET%^");
   set_id(({"monster", "archer"}));
   set_long("One of the band of %^BOLD%^%^BLACK%^Dark Archers%^RESET%^ summoned by the royal magician to defend the walls of Purgatory.");
   set_level(45+random (35));
   set("aggressive", 55);
   set_gender("male");
   set_race("human");
   set_heart_beat(1);
   set_skill("attack", 480);
   set_skill("defense", 400);
   set_skill("double wielding", 400);
   set_skill("melee", 400);
   set_skill("dicipline", 400);
   set_skill("murder", 80);
   set_skill("perception", 320);
   set_skill("stealth", 240);
   set_skill("projectile", 400);
   set_skill("ranged", 480);
   set_skill("nature", 440);
   set_skill("blade", 400);
   set_skill("magic defense", 400);
   set_class("fighter");
   set_subclass("ranger");
   set_body_type("raknid");
   set_spell_chance(39);
   set_spells(({"slash", "mudthrow"}));

new(EQ"quiver")->move(this_object());
force_me("wear quiver");

new(WEAP"longbow")->move(this_object());
force_me("wield bow");

}
