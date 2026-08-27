// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("Deduces que has dado una media vuelta al primer piso "
   "por lo que pronto tendrias que encontrar la salida al mundo "
   "exterior, te empiezas a dar prisa, no sea que a algun zombie le "
   "entre hambre.\n");
   
   add_clone(TN"npcs/zombie",random(2-1));
   
   add_exit("norte",TN1"tn_a_35","road");
   add_exit("sur",TN1"tn_a_33","road");
   set_zone("tn");   
}
