#include <std.h>
#include <zexor.h>
inherit MONSTER;

create() {
   ::create();
   set_name("amazon");
   set_short("A jungle amazon");
   set_long("This is an amazon warrior covered from head to toe in mud. "
       "The amazon is just staring at you with his spear at ready.");
   set_race("human");
   set_level(35);
   set_gender("male");
   set_body_type("human");
   set_class("fighter");
   set_spell_chance(10);
   set_spells(({"impale"}));
   new(WEA"spear")->move(this_object());
   command("wield spear");
}
