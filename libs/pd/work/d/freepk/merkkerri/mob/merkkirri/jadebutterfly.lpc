#include <mjungle.h>
#include <std.h>
inherit MONSTER;
int KillMe();
  
void create() {
::create();
set_name("butterfly");
set_short("jade butterfly");
set_long("Jade butterflies are magical creatures of an unknown origin.  They only inhabit the vast jungles of the Merkkirri region.  It is said when they die, they leave only their precious wings.");
set_id(({"butterfly", "jade butterfly", "bug"}));
set_level(25);
set_race("butterfly");
set_property("no_corpse", 1);
set_body_type("insctwgd");
set_gender("female");
new(MOB "stinger")->move(this_object());
command("wield stinger");
new(MOB "wings")->move(this_object());
set_die((: KillMe() :));

}               

int KillMe() {
   object ob;
   tell_room(environment(this_object()),
   "The jade butterfly disappears in a %^ORANGE%^flash%^RESET%^ of light leaving only its delicate wings behind.", ({ }));
  if (present("stinger", this_object())) {
      ob = present("stinger", this_object());
      catch ( ob->remove() );
   }
   return 1;
}
