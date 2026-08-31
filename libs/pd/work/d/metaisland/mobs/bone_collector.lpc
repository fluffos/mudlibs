#include <std.h>
#include <metallicana.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Bone Collector");
   set_id(({"bone ollector", "collector", "Bone Collector"}));
   set_short("Bone Collector");
   set_long("A relativly small giant, that has been sent on the "
       "errand of collecting bones for the Scarlett Claw to use.");
   set_gender("male");
   set_race("giant");
   set_body_type("human");
   set_level(37);
   new(WEP "bone_spear")->move(this_object());
   force_me("wield spear");
}
