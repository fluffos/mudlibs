// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("Estas en uno de los niveles que componen la fortaleza conocida "
   "como %^BOLD%^%^BLACK%^La Torre Negra%^RESET%^, una ancestral construccion "
   "de origen desconocido, aunque viejas leyendas elficas aseguran que fue "
   "levantada por el mismisimo Oskuro. \n");
   
   add_clone(TN"npcs/zombie",random(2-1));
   add_exit("norte",TN1"tn_a_10","road");
   add_exit("sur",TN1"tn_a_12","road");
   set_zone("tn");
}
