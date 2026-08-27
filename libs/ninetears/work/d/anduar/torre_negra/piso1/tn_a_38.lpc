// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("En el suelo puedes ver fragmentos de armaduras y armas "
   "lo que deduces que estos zombies tambien comen alguna que otra "
   "vez. \n");
   
   add_clone(TN"npcs/zombie",random(2-1));
   
   add_exit("norte",TN1"tn_a_39","road");
   add_exit("sur",TN1"tn_a_37","road");
   set_zone("tn");   
}
