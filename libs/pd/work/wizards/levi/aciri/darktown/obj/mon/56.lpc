#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("prophet");
   set_short("a black prophet");
   set_long("A prophet of evil, preaching the word of death and evil to any who "
     "stop a moment to listen. The prophet has gone mad from the tower, and "
     "stands here mumbling gibberish.");
   set_level(46);
   set_id(({ "black prophet", "prophet" }));
   set_auto(6);
   set_class("fighter");
   set_race("elf");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"profrobes");
   command("wear robes");
}
