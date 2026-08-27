// Cloaca.

#include "../../path.h" 

inherit CLOACAS+"bichos";

void setup()
{
   set_short("Cloacas de Anduar");
   set_long("Tus pies chapotean en el agua cenagosa de debajo de tus pies, "
   "llegando hasta las rodillas. Un olor nauseabundo similar al de un cadaver "
   "en descomposicion penetra por tu nariz, dandote arcadas y ganas de "
   "vomitar, por todos lados multitud de insectos se mueven, saltando entre "
   "las fangosas aguas.\n" 
   "Las paredes estan llenas de fango y moho por los cuales bajan chorros de "
   "agua mezclada con bichos en avanzado estado de descomposicion, ademas un "
   "pequenyo riachuelo de distintos colores, compuesto a saber por que "
   "materia circula lentamente por debajo de ti. Del techo cuelgan largos "
   "hilos de porqueria.\n");
   add_item("suelo", "El suelo es cochambroso.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas."
   "\n");
   add_exit("oeste", CLOACAS+"c66", "corridor");
   add_exit("este",  CLOACAS+"c68", "corridor");
   set_light(20);
   crea_bichos();
}
