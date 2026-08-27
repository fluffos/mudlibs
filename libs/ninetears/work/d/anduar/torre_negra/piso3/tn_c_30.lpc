// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("Miras a tu alrededor en un intento de hallar un "
   "resquicio de luz, pero es imposible, el pasillo es totalmente "
   "oscuro, de un negro malevolo y terrorifico que te hiela la "
   "sangre. El suelo y las paredes son totalmente negros, y son "
   "frios al tacto, tan frios como la carne de algunos seres, cuyas "
   "historias recuerdas ahora, cuando parece que estas cerca de ellos.\n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("oeste",TN3"tn_c_29","road");
   add_exit("este",TN3"tn_c_31","road");
   set_zone("tn");   
}
