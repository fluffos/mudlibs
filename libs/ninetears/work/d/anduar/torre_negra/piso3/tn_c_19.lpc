// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("El silencio mortal que reina en esta parte del pasillo "
   "te inquieta intensamente. El fuego de unas pocas antorchas "
   "semiconsumidas parece mirarte con expresiones de ira y de odio "
   "proyectando sombras de diferentes formas sobre las oscuras "
   "paredes. En el suelo yacen cadaveres y esqueletos de lo que "
   "antanyo debieron ser grandes y valerosos guerreros.\n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("este",TN3"tn_c_18","road");
   add_exit("oeste",TN3"tn_c_20","road");
   set_zone("tn");   
}
