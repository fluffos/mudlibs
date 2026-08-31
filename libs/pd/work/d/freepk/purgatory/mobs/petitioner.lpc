#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("A Petitioner");
   set_short("A Petitioner");
   set_id(({"monster", "petitioner"}));
   set_long("As a citizen of Purgatory, this guy is trying to get the Lords and Ladies to approve his petitions for various things.");
    set_level(65+random(10));
   set("aggressive", 25);
   set_gender("male");
   set_race("human");
   set_moving(1);
   set_speed(8);
   set_skill("melee", 250);
   set_body_type("human");
   set_emotes(2,({ "A petitioner paces anxiously around the room.", "A petitioner mutters something about snooty Lords." }),0);
   set_money("gold", 500);
}
