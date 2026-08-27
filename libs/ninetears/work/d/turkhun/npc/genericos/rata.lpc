#include "/d/turkhun/path.h"
inherit "/obj/monster";
 
void setup()
{
     set_name("rata");
     set_short("rata");
     add_alias("rata");
     set_al(0);
     set_gender(random(1));
     set_main_plural("Ratas");
     add_plural("ratas");
     set_level(25+random(3));
     set_random_stats(12,16);
     set_dex(20);
     set_race_ob("/std/races/animal");
     set_race("animal");
     set_long("Es una rata grande y peluda, casi ciega de vivir aqui dentro, se mueve "
     	"agilmente de un lado a otro buscando migajas que llevarse a la boca.\n");
     load_chat(20,
     ({
        1, ":corretea de un lado a otro.",
        1, ":se arrima a olisquearte.",
     }));
     add_property("bando",1);
   add_move_zone("cueva");
   set_move_after(random(5)+1,5+random(15));
   set_kill_xp(10);
}
