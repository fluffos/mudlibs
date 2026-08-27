#include "/d/turkhun/path.h"
inherit "/obj/monster";
 
string color,colores;
void setup()
{
     int i;
      i=random(4);
      switch(i)
        { case 0: 
        	color="pardo"; 
        	colores="pardos"; 
          break;
          case 1: 
          	color="negro";
          	colores="negros";
          break;
          case 2:
          	color="blanco";
          	colores="blancos";
          break;
          case 3:
          	color="cobrizo";
          	colores="cobrizo";
          break;
        }	
     set_name("raton");
     set_short("Raton "+color);
     add_alias("raton");
     set_al(0);
     set_gender(random(1));
     set_main_plural("Ratones "+colores);
     add_plural("ratones");
     set_level(5+random(3));
     set_random_stats(18,20);
     set_dex(25);
     set_race_ob("/std/races/animal");
     set_race("animal");
     set_long("Debido a la practicamente inexistencia de drepredadores, los ratones "
     	       +colores+" proliferan en esta zona mas que en ningun otro sitio.\n");
     load_chat(20,
     ({
        1, ":corretea de un lado a otro.",
        1, ":se arrima a olisquearte.",
     }));
   set_move_after(random(5)+1,5+random(15));
   set_kill_xp(50);
}
