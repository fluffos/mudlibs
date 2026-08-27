// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("La oscuridad aqui parece tener vida propia, tienes "
   "la sensacion de que miles de seres invisibles corretean a tu "
   "alrededor susurrando frases de lamentos e ira, influyendote  "
   "temor. Hay varios esqueletos tirados de cualquier manera por "
   "el suelo, y ninguno de ellos conserva el craneo ni las extremidades "
   "superiores. Te preguntas angustiado si quizas esas partes les "
   "fueron arrancadas cuando aun estaban conscientes y te estremeces "
   "de horror ante esa idea.\n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("sur",TN3"tn_c_23","road");
   add_exit("norte",TN3"tn_c_25","road");
   set_zone("tn");
}
