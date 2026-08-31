#include <std.h>
#include <zexor.h>
inherit MONSTER;

create() {
   ::create();
   set_name("wasp");
   set_short("A dangerous wasp");
   set_long("This is a wasp who seems to be angered and is "
       "flying at you with its stinger infront of it");
   set_race("wasp");
   set_body_type("human");
   set_id(({"dangerous wasp", "wasp"}));
   set_level(20);
   set("aggressive", 42);
   set_swarm("wasp");
   new(WEA"stinger")->move(this_object());
   command("wield stinger");
}
