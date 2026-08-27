// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Restos humanos... cada paso hacia el interior de la "
   "%^BLACK%^BOLD%^Torre Negra%^RESET%^ te acerca mas a las "
   "oscuras y temidas manos de la muerte. Cadaveres horriblemente "
   "mutilados son tu unica companyia en el angosto corredor en "
   "que ahora te encuentras.  Aunque este algo iluminado en este "
   "tramo, la luz que puedes ver es  mortecina, palida y debil, "
   "arrastrando tras de si todas tus esperanzas de salir con vida.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("este",TN2"tn_b_5","road");
   add_exit("oeste",TN2"tn_b_3","road");
   set_zone("tn");
}
