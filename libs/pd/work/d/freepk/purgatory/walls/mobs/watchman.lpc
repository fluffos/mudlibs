#include <std.h>
#include <castlewall.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Watchman");
   set_short("Purgatory Watchman");
   set_id(({"monster", "watchman", "purgatory watchman"}));
   set_long("These men are brave souls indeed, they dedicate their lives to protecting their city from the high perch of the castle walls.");
   set("aggressive", 25);
   set_gender("male");
   set_race("human");
   set_level(84+random(25));
   set_class("fighter");
   set_subclass("warrior");
   set_spell_chance(40);
   set_spells(({"entangle","slash"}));
   set_body_type("sacron");

new(EQ"mboots")->move(this_object());
force_me("wear boots");

new(EQ"mgloves")->move(this_object());
force_me("wear gloves");

new(EQ"marmour")->move(this_object());
force_me("wear armour");

new(WEAP"swhip")->move(this_object());
force_me("wield whip");

new(WEAP"claymore")->move(this_object());
force_me("wield sword");

}
