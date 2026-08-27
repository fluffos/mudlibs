// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("El corredor en que te encuentras esta un poco mas iluminado "
   "que en tramos anteriores. Ante ti ves restos de esqueletos, antiguos "
   "aventureros que algun dia intentaron entrar y acabaron pereciendo. "
   "Tendras tu mejor suerte que ellos?\n"); 
      add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("norte",TN2"tn_b_13","road");
   add_exit("sur",TN2"tn_b_11","road");
   set_zone("tn");
}
