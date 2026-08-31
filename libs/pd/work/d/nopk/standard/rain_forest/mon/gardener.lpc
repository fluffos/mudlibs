#include <std.h>
#include <rain.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("elf");
   set_short("Pluon the gardener");
   set_patrol(120, ({ "south", "east", "north", "west"}));
   set_id(({"pluon", "elf", "gardener"}));
   set_long("Pluon is a gardener which loves his job. Pluon "
            "can be caught wandering around town singing.");
   set_level(3);
   set_gender("male");
   set_race("elf");
   set_heart_beat(1);
   set_body_type("human");
   new(WEA"rake")->move(this_object());
   this_object()->force_me("wield rake");
 }

void heart_beat()
{
 ::heart_beat();
 i++;
 if (i > 20) {
    i = 0;
    this_object()->force_me("whistle");
   }
}
