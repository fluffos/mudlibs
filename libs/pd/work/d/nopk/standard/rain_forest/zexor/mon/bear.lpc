#include <std.h>
#include <zexor.h>
inherit MONSTER;

create() {
   ::create();
   set_name("bear");
   set_short("a large brown bear");
   set_long("This is a large brown bear. It has a very sleek "
       "and shiny coat. It has muscles bulging from every part "
       "of his body");
   set_gender("male");
   set_id(({"bear", "brown bear", "monster"}));
   set_race("bear");
   set_body_type("human");
   set_level(35);
   set_class("fighter");
   set_spells(({"rush"}));
   set_spell_chance(35);
   new(WEA"claw")->move(this_object());
   command("wield claw");
}
