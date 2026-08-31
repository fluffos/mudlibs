#include <std.h>
#include <castlewall.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Dark Archer");
   set_short("%^BOLD%^%^BLACK%^Dark Archer%^RESET%^");
   set_id(({"monster", "archer"}));
   set_long("One of the band of %^BOLD%^%^BLACK%^Dark Archers%^RESET%^ summoned by the royal magician to defend the walls of Purgatory.");
   set_level(50+random (25));
   set("aggressive", 55);
   set_swarm("");
   set_gender("male");
   set_race("human");
   set_class("fighter");
   set_subclass("ranger");
   set_body_type("raknid");
   set_spell_chance(39);
   set_spells(({"slash"}));

new(EQ"quiver")->move(this_object());
force_me("wear quiver");

new(WEAP"longbow")->move(this_object());
force_me("wield bow");

new(WEAP"shortsword")->move(this_object());
force_me("wield sword");

new(EQ"darkarmour")->move(this_object());
force_me("wear armour");

new(EQ"spiderleggings")->move(this_object());
force_me("wear leggings");
}
