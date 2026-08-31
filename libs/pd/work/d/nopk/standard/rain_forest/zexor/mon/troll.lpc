#include <std.h>
#include <zexor.h>
inherit MONSTER;

create() {
   ::create();
   set_name("troll");
   set_short("a hunting troll");
   set_long("This is a large hunting troll who is wandering around, "
       "trying to catch a deer. He keeps brandishing his club as if "
       "ready to pound something at any moment.");
   set_level(36);
   set_race("troll");
   set_body_type("human");
   set_gender("male");
   set_id(({"troll", "hunting troll"}));
   set_class("fighter");
   set_subclass("warrior");
   set_spells(({"rush"}));
   set_spell_chance(10);
   new(WEA"club")->move(this_object());
   command("wield club");
}
