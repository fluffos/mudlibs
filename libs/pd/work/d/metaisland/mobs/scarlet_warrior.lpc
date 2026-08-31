#include <std.h>
#include <metallicana.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Scarlett Warrior");
   set_id(({"Scarlett Warrior", "warrior"}));
   set_short("A Warrior of the Scarlett Claw");
   set_long("The warrior stands tall not budging an inch. He glowers at you "
       "sa he cracks his knuckles. He wants a good fight, and you seem to "
       "be his apponent.");
   set_gender("male");
   set_race("giant");
   set_body_type("human");
   set_level(37);
   new(WEP "serrated_bone_sword")->move(this_object());
   force_me("wield sword");
   new(ARM "bone_platemail")->move(this_object());
   force_me("wear platemail");
}
