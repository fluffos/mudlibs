#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("magician");
   set_short("a holy warmage");
   set_long("One of the defenders of the temple, should it come under "
     "attack. The holy warmage is a cross between a mage and a priest. "
     "Her training is mainly in battle.");
   set_id(({ "mage", "magician", "holy magician" }));
   set_alignment(random(100));
   set_level(38);
   set_race("human");
   set_body_type("human");
   set_gender("female");
   set_class("mage");
   set_subclass("conjurer");
   set_spells(({ "liquify", "solidify" }));
   set_skill("magic attack", 100);
   set_skill("conjuring",100);
   set_skill("faith", 90);
   set_spell_chance(15);
   make(ARM"gwcloak");
   make(ARM"wboots");
   command("wear cloak");
   command("wear gloves");
   command("wear boots");
}
