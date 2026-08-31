#include <std.h>
#include <metallicana.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("warrior");
   set_id(({"warrior", "Ka'karl Warrior"}));
   set_short("Ka'Karl Warrior");
   set_long("A large man, keeps watchs over the area. He is on watch, protecting from enemys..");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_level(39);
   new(ARM "steel_breastplate")->move(this_object());
   force_me("wear breastplate");
   new(WEP "broadsword")->move(this_object());
   force_me("wield sword");
}
