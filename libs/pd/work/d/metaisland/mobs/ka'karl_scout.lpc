#include <std.h>
#include <metallicana.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("scout");
   set_id(({"scout", "Ka'karl Scout"}));
   set_short("Ka'Karl Scout");
   set_long("A small man, scouting the area for enemys.");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_level(37);
   new(ARM "ragged_pants")->move(this_object());
   force_me("wear pants");
   new(WEP "weak_dagger")->move(this_object());
   force_me("wield dagger");
}
