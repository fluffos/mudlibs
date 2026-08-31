#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Lazy guard");
   set_short("Lazy guard");
   set_id(({"monster", "guard"}));
   set_long("What a lazy little slacker this guy is!");
    set_level(75+random(10));
   set("aggressive", 28);
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_class("fighter");
   set_subclass("antipaladin");
   set_spell_chance(40);
   set_spells(({"slash"}));
   set_emotes(2,({ "Heavy snoring can be heard." }),0);

new(EQ"dgauntlets")->move(this_object());
force_me("wear gauntlets");

new(EQ"dazzlingleggings")->move(this_object());
force_me("wear leggings");

new(EQ"dazzlingboots")->move(this_object());
force_me("wear boots");

new(WEAP"dazzlingblade")->move(this_object());
force_me("wield blade");

new(WEAP"dazzlingblade")->move(this_object());
force_me("wield blade");

new(EQ"dazzlingarmour")->move(this_object());
force_me("wear armour");

}


