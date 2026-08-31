// baxe platemail2
#include <std.h>
#include <rain.h>
inherit MONSTER;

create() {
   ::create();
   set_name("guard");
   set_short("Strong elven guard");
   set_long("This guard is described by one word \"strong\". He "
            "stands 6 feet 2 inches from the ground. He is wie"
            "lding a huge battle axe, and wearing jeweled encr"
            "usted platemail.");
   set_id(({"guard", "elven guard", "elf"}));
   set_level(11);
   set_race("elf");
   set_gender("male");
   set_body_type("human");
   set_class("fighter");
   set_spells(({"headbutt"}));
   set_spell_chance(23);
   new(WEA"baxe")->move(this_object());
   new(ARM"platemail2")->move(this_object());
   this_object()->force_me("wear platemail");
   this_object()->force_me("wield axe");
}
