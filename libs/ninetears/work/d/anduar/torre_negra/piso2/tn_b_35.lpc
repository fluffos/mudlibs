// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("El pasadizo se hace mas estrecho a medida que avanzas "
   "por la %^BLACK%^BOLD%^Torre Negra%^RESET%^. El silencio que "
   "antes te acompanyaba es sustituido por los lamentos de miles "
   "de almas, martirizadas durante milenios en estos corredores.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("norte",TN2"tn_b_34","road");
   add_exit("sur",TN2"tn_b_36","road");
   set_zone("tn");
}
