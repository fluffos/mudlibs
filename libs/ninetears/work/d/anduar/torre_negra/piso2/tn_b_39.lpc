// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Las antorchas del pasadizo proyectan aqui malignas "
   "sombras de mil y una formas diferentes, provocando evocadoras "
   "imagenes de almas maltratadas, de muertes y de sufrimientos "
   "que duran milenios... el ambiente aqui parece cargado de pura "
   "magia, dado que te parece notar olas de crepitante energia "
   "saltando de pared en pared.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("este",TN2"tn_b_40","road");
   add_exit("oeste",TN2"tn_b_38","road");
   set_zone("tn");
}
