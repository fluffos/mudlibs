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
   "Torre Negra%^RESET%^. \n"
   "Te preguntas quien debio ser el que construyo e ideo esta torre "
   "ya que no sabrias decir, si te encuentras en el primer piso, en "
   "el segundo, o quiza tal vez en el quinto, ya que las paredes, el "
   "suelo, todo, exactamente todo es igual, nada cambia, solo tu miedo.\n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("sur",TN3"tn_c_22","road");
   add_exit("norte",TN3"tn_c_24","road");
   set_zone("tn");   
}
