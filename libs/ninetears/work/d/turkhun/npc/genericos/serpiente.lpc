#include "/d/turkhun/path.h"
inherit "/obj/monster";
 
void setup()
{
     set_name("serpiente");
     set_short("Serpiente");
     add_alias("serpiente");
     set_al(100);
     set_gender(1);
     set_main_plural("Serpientes");
     add_plural("serpientes");
     set_level(34+random(6));
     set_random_stats(12,18);
     set_dex(20);
     set_race_ob("/std/races/animal");
     set_race("animal");
     set_long("Es una serpiente de gran tamanyo, negra como el carbon, anda por la mina "
     	"acechando ratas, es muy susceptible y agresiva.\n");
     add_hated("bando",({2,3}));
     set_aggressive(5);
     load_a_chat(20,
     ({
        1, ":te detecta por tu temperatura corporal.",
        1, ":se mueve sigilosa entre las rocas.",
     }));
     add_property("bando",1);
   add_move_zone("cueva");
   set_move_after(random(5)+1,5+random(15));
   set_kill_xp(10);
}
