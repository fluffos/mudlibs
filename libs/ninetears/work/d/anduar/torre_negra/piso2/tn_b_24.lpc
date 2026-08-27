// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Te sientes rodeado... miles de sombras parecen estar al "
   "acecho de tu muerte... oyes sonidos fantasmagoricos, en idiomas "
   "totalmente desconocidos, pero intuyes que las voces se refieren "
   "a muerte, a miedo, a sed de sangre y destruccion...\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("oeste",TN2"tn_b_25","road");
   add_exit("este",TN2"tn_b_23","road");
   set_zone("tn");
}
