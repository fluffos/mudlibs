// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Te es virtualmente imposible ver nada en este trecho "
   "del camino: Todo es negro sobre negro. Solo se distingue el brillo "
   "de miles de pequenyos ojos rojos observandote, esperando tu muerte "
   "para alimentarse de ti.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("norte",TN2"tn_b_28","road");
   add_exit("sur",TN2"tn_b_30","road");
   set_zone("tn");
}
