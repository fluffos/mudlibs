// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("Dudas que haya muchos mas pisos, ya que habiendo "
   "visto la torre desde fuera, imaginas que como mucho habra "
   "otro mas, pero esa no es la preocupacion que te asalta ahora "
   "mismo, sino que es, que misterios oculta la %^BOLD%^%^BLACK%^"
   "Torre Negra%^RESET%^. \n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("este",TN3"tn_c_19","road");
   add_exit("oeste",TN3"tn_c_21","road");
   set_zone("tn");   
}
