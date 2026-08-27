// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Te encuentras en el segundo nivel de la "
   "%^BOLD%^%^BLACK%^Torre Negra%^RESET%^, nada cambia al nivel "
   "anterior, solo cambia tu miedo, alertado por tu subsconciente "
   "el cual te berrea incesantemente...vas a morir. \n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("norte",TN2"tn_b_14","road");
   add_exit("sur",TN2"tn_b_12","road");
   set_zone("tn");
}
