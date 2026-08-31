#include <std.h>
#include <rain.h>
inherit MONSTER;
create() {
   ::create();
   set_name("butler");
   set_id(({"butler","monster", "a butler"}));
   set_short("A butler");
   set_long("This butler seems mysterious. She walks around the cas"
            "tle, with nothing apparent to do, even though he's a "
            "butler.");
if(random(2)) set_gender("male");
else set_gender("female");
   set_level(5);
   set_class("rogue");
   set_race("human");
   set_body_type("human");
   set_spells(({"jab"}));
   set_spell_chance(25);
   new(WEA"cane")->move(this_object());
   this_object()->force_me("wield cane");
}
