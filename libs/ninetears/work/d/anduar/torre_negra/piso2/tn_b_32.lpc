// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Las negras paredes aparecen aqui muy erosionadas, "
   "debido a las grandes corrientes de pura magia maligna que "
   "han recorrido durante generaciones estos pasillos. El silencio "
   "a tu alrededor es total, cosa que hace que aun te inquietes mas "
   "de lo que ya estabas.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("norte",TN2"tn_b_31","road");
   add_exit("sur",TN2"tn_b_33","road");
   set_zone("tn");
}
