#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Honor Guard");
   set_short("Honor Guard");
   set_id(({"monster", "guard"}));
   set_long("The Royal Honor Guards are here to protect the King from any and all harm.");
    set_level(75+random(10));
   set("aggressive", 25);
   set_class("fighter");
   set_subclass("berserker");
   set_spell_chance(39);
   set_gender("male");
   set_race("raknid");
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

