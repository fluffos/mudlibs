#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("Honor Guard");
   set_short("Honor Guard");
   set_id(({"monster", "guard"}));
   set_long("The Royal Honor Guards are here to protect the King from any and all harm.");
   set_level(45);
   set("aggressive", 25);
   set_class("fighter");
   set_subclass("berserker");
   set_skill("attack", 300);
   set_skill("defense", 250);
   set_skill("double wielding", 250);
   set_skill("melee", 300);
   set_skill("rage", 250);
   set_skill("riding", 250);
   set_skill("murder", 50);
   set_skill("perception", 150);
   set_skill("stealth", 150);
   set_skill("blade", 250);
   set_skill("stealing", 50);
   set_skill("axe", 250);
   set_spell_chance(39);
   set_gender("male");
   set_race("raknid");
   set_heart_beat(1);
   set_body_type("raknid");
   set_spells(({"slash"}));

new(WEAP"godblade")->move(this_object());
force_me("wield blade");

new(WEAP"godblade")->move(this_object());
force_me("wield blade");

new(WEAP"bloodyaxe")->move(this_object());
force_me("wield axe");

new(WEAP"bloodyaxe")->move(this_object());
force_me("wield axe");


}

