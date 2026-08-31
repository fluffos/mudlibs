#include <std.h>
#include <castlewall.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Patrol Commander");
   set_short("Patrol Commander");
   set_id(({"monster", "commander", "patrol commander"}));
   set_long("A rather huge person, the Patrol Commander looks like he is not a person to be messed with.");
   set_level(50+random(25));
   set_swarm("");
   set_gender("male");
   set_race("human");
   set_class("fighter");
   set_subclass("warrior");
   set_spell_chance(40);
   set_moving(1);
   set_speed(3);
   set_spells(({"slash"}));
   set_body_type("sacron");

new(EQ"battlearmour")->move(this_object());
force_me("wear armour");

new(EQ"boneleggings")->move(this_object());
force_me("wear leggings");

new(EQ"pbracers")->move(this_object());
force_me("wear bracers");

new(EQ"light")->move(this_object());
force_me("wear light");

new(EQ"vest")->move(this_object());
force_me("wear vest");

new(EQ"medallion")->move(this_object());
force_me("wield medallion");

new(WEAP"rapture")->move(this_object());
force_me("wield sword");

new(WEAP"broadsword")->move(this_object());
force_me("wield sword");

new(WEAP"cblade")->move(this_object());
force_me("wield blade");
}
