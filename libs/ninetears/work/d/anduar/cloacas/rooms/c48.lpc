// Cloaca.

#include "../../path.h"	

inherit CLOACAS+"bichos";

void setup()
{
   set_short("%^BLUE%^Cloacas de Anduar: Pasillo principal%^RESET%^");
   set_long("Tus pies chapotean en el agua cenagosa de debajo de tus pies, "
   "casi cubriendo tu calzado. Un olor nauseabundo penetra por tu nariz.\n" 
   "Las paredes estan llenas de fango y moho por los cuales bajan chorros de "
   "agua mezclada con bichos en avanzado estado de descomposicion, ademas un "
   "pequenyo riachuelo de distintos colores, compuesto a saber por que "
   "materia circula lentamente por debajo de ti. Del techo cuelgan largos "
   "hilos de porqueria.\n");
   add_item("suelo", "El suelo es cochambroso.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");
   add_exit("east", CLOACAS+"c47", "corridor");
   add_exit("northwest", CLOACAS+"c49", "corridor");
   set_light(20);
   crea_bichos();
}
