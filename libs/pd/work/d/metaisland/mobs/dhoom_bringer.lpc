#include <std.h>
#include <metallicana.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Dhoom Bringer");
   set_id(({"dhoom bringer"}));
   set_short("A Dhoom Bringer");
   set_long("The giant stands about 30 feet tall. He looks consumed "
       "in something, he wares a grim smile of determine. You had better "
       "not get in his way.");
   set_gender("male");
   set_race("giant");
   set_body_type("human");
   set_level(39);
   new(WEP "dhoom_bringer_halberd")->move(this_object());
   force_me("wield halberd");
   new(ARM "bone_platemail")->move(this_object());
   force_me("wear platemail");
   new(ARM "bone_greaves")->move(this_object());
   force_me("wear greaves");
}
