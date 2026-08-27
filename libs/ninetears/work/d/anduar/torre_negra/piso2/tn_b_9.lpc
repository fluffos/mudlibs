// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("El pasillo en el que te encuentras esta "
   "debilmente iluminado por las antorchas, provocando "
   "la aparicion de espantosas sombras a tu alrededor. El "
   "frio que sientes te hiela la sangre y congela tus sentidos. "
   "Te preguntas si podras escapar de aqui... con vida.\n");

   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("norte",TN2"tn_b_10","road");
   add_exit("sur",TN2"tn_b_8","road");
   set_zone("tn");
}
