#include <std.h>
#include <purgatory.h>
inherit MONSTER;

int i;

void create() {
    object money;
 ::create();
   set_name("A Petitioner");
   set_short("A Petitioner");
   set_id(({"monster", "petitioner"}));
   set_long("As a citizen of Purgatory, this guy is trying to get the Lords and Ladies to approve his petitions for various things.");
   set_level(35+random(25));
   set("aggressive", 25);
   set_gender("male");
   set_race("human");
   set_heart_beat(1);
   set_moving(1);
   set_speed(8);
   set_skill("melee", 250);
   set_body_type("human");
   set_emotes(2,({ "A petitioner paces anxiously around the room.", "A petitioner mutters something about snooty Lords." }),0);
    money = new("std/obj/coins");
    money->set_money("platinum", 9);
    money->set_money("gold", 884);
    money->move(this_object());
}

