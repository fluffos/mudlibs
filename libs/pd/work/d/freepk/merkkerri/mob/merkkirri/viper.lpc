#include <mjungle.h>
#include <std.h>
inherit MONSTER;
int KillMe();
  
void create() {
::create();
set_property("no_corpse", 1);
set_name("viper");
set_short("speckled viper");
set_long("Speckled vipers are quite common throughout the Merkkirri region.  They are a primary food source for the native gnoll population and the venom is sometimes used to coat the weapons of the warriors before battle.");
set_id(({"viper", "speckled viper"}));
set_level(25);
set_race("snake");
set_body_type("snake");
set_gender("female");
add_limb("mouth", "", 100, 0, 4);
set_wielding_limbs(({"mouth"}));
new(MOB "fang")->move(this_object());
command("wield fang");
set_die((: KillMe() :));
}               

int KillMe() {
   object ob;
   tell_room(environment(this_object()),
     "The viper slithers off, %^RED%^half dead%^RESET%^.", ({ }));
   if (present("fang", this_object())) {
      ob = present("fang", this_object());
      catch ( ob->remove() );
   }
   return 1;
}
