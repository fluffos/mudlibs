// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("Unos pequenyos y rabiosos ojos rojos, son toda la "
   "iluminacion que hay en esta habitacion. El frio que te llega "
   "desde la lejana oscuridad del pasillo hace que te estremezcas "
   "a cada paso que das.\n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("norte",TN3"tn_c_10","road");
   add_exit("sur",TN3"tn_c_12","road");
   set_zone("tn");
}
