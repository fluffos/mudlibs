/* By Shimmer*/


inherit "/obj/monster";
#include "unarmed_combat.h"
string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(4))
  
  {
    case 0:
      set_name("espectro de Orco");
      set_short("espectro de Orco");
      set_long("Es el espectro de uno de los orcos caidos en la gran batalla, lo tienes levitando delante de ti y cuando te"+
	       "fijas en el un escalofrio recorre todo tu cuerpo, puedes ver atraves de el "
               "debido a que es un ser etereo.\n");
      add_alias("espectro");
      add_alias("orco");
      add_alias("orcos"); 
      set_main_plural("espectros de Orcos");
      add_plural("espectros");
      add_plural("orcos");
      set_gender(1);
      set_level(30+random(10));
      set_aggressive(1);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/hacha_espectral",1);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/armadura_espectral",1);
      ::init_equip();  
    break;
    case 1:
            set_name("espectro de hahniano");
      set_short("espectro de hahniano");
      set_long("Es el espectro de habitante de Hahn, lo tienes levitando delante de ti y cuando te"+
	       "fijas en el un escalofrio recorre todo tu cuerpo, puedes ver atraves de el "
               "debido a que es un ser etereo.\n");
      add_alias("espectro");
      add_alias("hahniano");
      add_alias("hahnianos"); 
      set_main_plural("espectros de hahnianos");
      add_plural("espectros");
      add_plural("hahnianos");
      set_gender(1);
      set_level(15+random(10));
      set_aggressive(1);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/daga_espectral",2);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/cuero_espectral",1);
      ::init_equip();
      break;
    case 2:
      set_name("espectro de Guardia de Hahn");
      set_short("espectro de Guardia de Hahn");
      set_long("Es el espectro de Guardia de Hahn, lo tienes levitando delante de ti y cuando te"+
	       "fijas en el un escalofrio recorre todo tu cuerpo, puedes ver atraves de el "
               "debido a que es un ser etereo.\n");
      add_alias("espectro");
      add_alias("guardia");
      add_alias("guardias"); 
      set_main_plural("espectros de Guardias de Hahn");
      add_plural("espectros");
      add_plural("guardias");
      set_gender(1);
      set_level(35+random(10));
      set_aggressive(1);      
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/armadura_espectral",1);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/espada_espectral",2);      
      ::init_equip();  
      break;
    case 3:
            set_name("espectro de Capitan Orco");
      set_short("espectro de Capitan Orco");
      set_long("Es el espectro de Guardia de Hahn, lo tienes levitando delante de ti y cuando te"+
	       "fijas en el un escalofrio recorre todo tu cuerpo, puedes ver atraves de el "
               "debido a que es un ser etereo.\n");
      add_alias("espectro");
      add_alias("capitan");
      add_alias("capitanes"); 
      set_main_plural("espectros de Capitanes Orcos");
      add_plural("espectros");
      add_plural("capitanes");
      set_gender(1);
      set_level(35+random(10));
      set_aggressive(1);      
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/armadura_espectral",1);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/hacha_espectral",2);      
      ::init_equip(); 
      break;

  }
  set_random_stats(14,17);
  set_al(0);
  set_wimpy(10);

} 