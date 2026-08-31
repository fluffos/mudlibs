#include <std.h>
#include <zexor.h>
inherit MONSTER;

create() {
   ::create();
   set_name("elf");
   set_short("a forest elf");
   set_level(40);
   set_long("This is an elf with blonde hair. He is standing "
       "straight tall and is wielding a huge blade. He keeps "
       "muttering about how he will slay the wurm and "
       "take revenge on the wurm for killing his family.");
   set_gender("male");
   set_race("elf");
   set_id(({"elf", "forest elf"}));
   set_body_type("human");
   set_exp(210000);
   set_class("fighter");
   set_subclass("paladin");
   set_spells(({"godspeed"}));
   set_spell_chance(25);
   new(WEA"falchion")->move(this_object());
   command("wield blade");
}
