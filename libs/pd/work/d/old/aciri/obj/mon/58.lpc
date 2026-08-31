#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("shadow");
   set_short("a nether shadow");
   set_long("A being of the nether void, come from the depths of hell to taunt "
     "and slay the living. The nether shadow's form is black and crimson mist. "
     "The only light piercing the shadow's evil body are two glowing silver "
     "eyes.");
   set_level(45);
   set_id(({ "shadow", "nether shadow", "spirit" }));
   set_auto(8);
   set_class("fighter");
   set_race("shadow");
   set_body_type("human");
  if (random(2) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"shaxe");
   command("wield axe");
}
