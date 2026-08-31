// War chief wielding a mace
#include <std.h>
#include <rain.h>
inherit MONSTER;

create() {
   ::create();
   set_name("chief");
   set_short("The chief of war");
   set_level(15);
   set_id(({"chief", "war chief", "chief of war", "war"}));
   set_long("This elf controls all war in the elven nation. He "
            "orders people to attack or not. He is large and is"
            " wielding a large mace. He wears strong chainmail "
            "upon his elven body");
   set_class("fighter");
   set_race("elf");
   set_body_type("human");
   set_gender("male");
   set_spells(({"rush"}));
   set_spell_chance(15);
   new(WEA"mace")->move(this_object());
   new(ARM"gchain")->move(this_object());
   this_object()->force_me("wield mace");
   this_object()->force_me("wear chainmail");
}
