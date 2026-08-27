// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("Despues de torcer por la derecha del pasillo, del "
   "cual tienes serias dudas de que lleve a algun sitio, ves que "
   "este es el doble de largo del que acabas de dejar, tan largo "
   "y tan mortal como el mismo corazon de Oskuro. \n");
   
   add_clone(TN"npcs/zombie",random(2-1));
   add_exit("norte",TN1"tn_a_7","road");
   add_exit("sur",TN1"tn_a_9","road");
   set_zone("tn");
}
