#include "/d/turkhun/path.h"
inherit "/obj/monster";
 
string color,colores;
void setup()
{
     int i;
      i=random(4);
      switch(i)
        { case 0: 
        	color="%^BOLD%^CYAN%^Azul%^RESET%^"; 
        	colores="%^BOLD%^CYAN%^Azules%^RESET%^"; 
          break;
          case 1: 
          	color="%^BOLD%^GREEN%^Verde%^RESET%^";
          	colores="%^BOLD%^GREEN%^Verdes%^RESET%^";
          break;
          case 2:
          	color="%^BOLD%^YELLOW%^Amarilla%^RESET%^";
          	colores="%^BOLD%^YELLOW%^Amarillas%^RESET%^";
          break;
          case 3:
          	color="%^BOLD%^WHITE%^Blanca%^RESET%^";
          	colores="%^BOLD%^WHITE%^Blancas%^RESET%^";
          break;
        }	
     set_name("mariposa");
     set_short("Mariposa "+color);
     add_alias("mariposa");
     set_al(0);
     set_gender(random(1));
     set_main_plural("Mariposas "+colores);
     add_plural("mariposas");
     set_level(5+random(3));
     set_random_stats(18,20);
     set_dex(25);
     set_race_ob("/std/races/animal");
     set_race("animal");
     set_long("Es una bonita mariposa de color "+color+" intenso que revolotea feliz los campos"
     	      "libando de flor en flor.\n");
     load_chat(20,
     ({
        1, ":corretea de un lado a otro.",
        1, ":se arrima a olisquearte.",
     }));
   set_move_after(random(5)+1,5+random(15));
   set_kill_xp(100);
}
