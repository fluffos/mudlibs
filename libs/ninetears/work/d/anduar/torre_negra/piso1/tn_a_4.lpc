// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("Las paredes y el suelo estan resbaladizos, despues de mirar "
   "un buen rato, te das cuenta que estan recubiertos de un musgo de color "
   "negro, seguramente venenoso, que parece irradiar una luz, que no sabes "
   "si es negra o blanca, lo unico que sabes es que rezuman maldad en todos "
   "sus sentidos. \n");
   add_clone(TN"npcs/zombie",random(2-1));
   add_exit("oeste",TN1"tn_a_3","road");
   add_exit("este",TN1"tn_a_5","road");
   set_zone("tn");
}

