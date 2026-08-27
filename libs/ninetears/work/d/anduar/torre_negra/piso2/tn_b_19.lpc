// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("En este tramo del pasillo sientes mas que nunca "
   "la opresion y el terror que provoca la %^BOLD%^BLACK%^Torre "
   "Negra%^RESET%^: toda esperanza por salir de aqui desaparece "
   "al observar los esqueletos esparcidos por aqui. Caes en la "
   "cuenta de que la mayoria de ellos carecen de craneo. Te "
   "preguntas si la cabeza les fue arrancada en vida, y un "
   "escalofrio recorre tu cuerpo al pensar en ello.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("oeste",TN2"tn_b_20","road");
   add_exit("este",TN2"tn_b_18","road");
   set_zone("tn");
}
