#include <lost.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("dromaeosaurus");
set_short("Dromaeosaurus");
set_long("A small dinosaur, with sharp claws on its feet. It looks swift and dangerous.");
set("aggressive",  40);
set_id(({"dinosaur", "dromaeosaurus"}));
set_class("fighter");
set_subclass("warrior");
set_alignment(0);
set_race("dinosaur");
set_body_type("dinosaur");
if(random(5) > 2) set_gender("male"); else set_gender("female");
set_spell_chance(30);
set_spells(({"rush"}));
set_level(30);

set_skill("charging", 350);

}
