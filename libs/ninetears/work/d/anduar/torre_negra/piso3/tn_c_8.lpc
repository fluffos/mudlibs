// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("Restos humanos, cada paso hacia el interior de esta "
   "maligna torre te acerca mas a las oscuras y temidas manos de "
   "la muerte. Cadaveres horriblemente mutilados adornanan lo que "
   "es la unica companyia que tienes en estos pasillos.\n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("norte",TN3"tn_c_7","road");
   add_exit("sur",TN3"tn_c_9","road");
   set_zone("tn");
}
