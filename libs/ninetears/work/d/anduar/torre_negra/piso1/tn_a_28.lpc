// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("La unica salida que has visto era por el mismo sitio "
   "por donde antes entraste y la que acabas de pasar hace un rato "
   "empiezas a dudar si no era buena idea haber subido al siguiente "
   "piso y enfrentarte con lo que sea, que siempre sera mejor que "
   "seguir con la sensacion de opresion en tu alma.\n");
   
   add_clone(TN"npcs/zombie",random(2-1));
   
   add_exit("este",TN1"tn_a_27","road");
   add_exit("oeste",TN1"tn_a_29","road");
   set_zone("tn");   
}
