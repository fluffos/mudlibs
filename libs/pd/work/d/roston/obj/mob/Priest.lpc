#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
  mapping inv;
  ::create();
  set_name("priest");
  set_short("Holy Priest");
  set_long("The Priest is a very holy man, he loves "
   "all people. He is very wise, and strong. "
   "The priest lives in the Church, he will die "
   "over protecting his church.");
  set_id(({"priest", "wise priest"}));
  set_level(40);
  set_race("dwarf");
  set_alignment(1500);
  set_class("clergy");
  set_subclass("cleric");
  set_spell_chance(20);
  set_spells( ({"paralyze"}) );
  set_skill("healing", 100);
  set_body_type("human");
  set_gender("male");
  inv = ([
   ARM"shield" : "wear shield",
   ARM"helmet" : "wear helmet",
   WEP"staff" : "wield staff",
  ]);
  if (random(200) > 190)
    inv += ([ "/wizards/daboura/arm/dull_brass_chest_plate" : "wear plate" ]);
  set_inventory(inv);
}                                             
