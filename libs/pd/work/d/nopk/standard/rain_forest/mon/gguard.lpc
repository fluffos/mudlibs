#include <std.h>
#include <rain.h>
inherit MONSTER;

int oi=0;

create() {
 ::create();
   set_name("guard");
   set_short("a gate guard");
   set_long("This guard's duty is to guard the gate. He is tall "
            "and strong for an elf. He stands still watching eve"
            "ryone pass. He has a steel helmet, some platemail a"
            "nd a very large and deadly scimitar.");
   set_id(({ "guard", "gate guard", "elf" }));
   set_race("elf");
   set_body_type("human");
   set_gender("male");
   set_level(10);
   set_class("fighter");
   set_spell_chance(25);
   set_spells(({"whirl", "rush", "slash"}));
   new(WEA"scimitar")->move(this_object());
this_object()->force_me("wield scimitar");
   new(ARM"platemail")->move(this_object());
this_object()->force_me("wear platemail");
   new(ARM"shelm")->move(this_object());
this_object()->force_me("wear helmet");
   new(OBJ"bkey")->move(this_object());
}
