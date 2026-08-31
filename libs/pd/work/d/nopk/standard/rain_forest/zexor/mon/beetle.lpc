#include <std.h>
#include <zexor.h>
inherit MONSTER;

create() {
   ::create();
   set_name("beetle");
   set_short("A large beetle");
   set_long("This is a 5 foot beetle waving it's pincers menicingly");
   set_level(32);
   set_race("beetle");
   set_body_type("insctwgd");
   set_gender("female");
   new(WEA"pincers")->move(this_object());
   command("wield pincers");
}
