#include <swamp.h>
#include <std.h>
inherit MONSTER;

int wraithgo();
void create() {
::create();
set_name("bog wraith");
set_short("bog wraith");
set_long("Shadowy creatures that haunt the swamp, bog wraiths stand nearly
seven feet tall and wear rotting black robes.  They have blood red eyes which
are the only distinguishable facial feature of the wraith.");
set("aggressive",  50);
set_id(({"bog wraith", "wraith"}));
set_class("mage");
set_subclass("sorceror");
set_alignment(-800);
set_skill("psionics", 200);
set_skill("conjuring", 200);
set_skill("healing", 200);
set_stats("intelligence", 100);
set_race("wraith");
set_body_type("human");
if(random(10) > 2) set_gender("male"); else set_gender("female");
set_spell_chance(35);
set_spells(({"solidify", "dissolve", "psistorm", "psidrain"}));
set_level(50);
set_property("no corpse", 1);
set_die("The wraith vanishes!");

}

int wraithgo() {
   tell_room(environment(this_object()),"The wraith vanishes!", ({ }));
this_object()->remove();

  return 1;
}
