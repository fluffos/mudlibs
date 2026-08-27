// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Te estremeces de frio al notar una brisa congelada "
   "que te llega desde el fondo del corredor. El aire aqui esta "
   "enrarecido, con un ligero olor a podredumbre. Es el olor de la "
   "muerte, que puedes sentir a cada paso que das.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("norte",TN2"tn_b_15","road");
   add_exit("sur",TN2"tn_b_13","road");
   set_zone("tn");
}
