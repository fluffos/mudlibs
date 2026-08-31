#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("trooper");
   set_short("a Neo-Orog trooper");
   set_long("The Neo-Orog are a new breed of orcs, created by the "
     "Aciri for loyalty and strength, the Neo-Orogs are also much "
     "more durable than normal orcs. The troopers were the first "
     "of the Neo-Orogs.");
   set_level(40);
   set_id(({ "neo-orog", "trooper", "orc" }));
   set_auto(8);
   set_race("neo-orog");
   set_body_type("human");
  if (random(6) >= 3)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"hhelm");
   command("wear all");
}
