// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("El pasillo esta hecho de obsidiana negra, un material muy "
   "preciado en todo el mundo, no ves ningun tipo de iluminacion, toda "
   "la luz que puedes apreciar proviene de la misma piedra negra, supones "
   "que tiene algun influjo magico.\n");
   
   add_clone(TN"npcs/zombie",random(2-1));
   add_exit("norte",TN1"tn_a_8","road");
   add_exit("sur",TN1"tn_a_10","road");
   set_zone("tn");
}
