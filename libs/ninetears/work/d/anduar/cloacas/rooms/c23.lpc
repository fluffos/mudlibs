// Cloaca. C23.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo terciario%^RESET%^");
   set_long("Estas en un sitio muy extranyo, las paredes estan muy destrozadas, "
            "tienen muchos cortes y agujeros, parece que este sitio es mas pequenyo, "
            "pero solo lo parece; en realidad es mas grande que los demas. Notas que " 
            "este sitio es mas calido. \n");

   add_item("suelo", "Sabes que hay suelo por que lo tocas no por que lo ves. \n");
   add_item("pared", "Las paredes estan llenas de grietas y agujeros, parece "
                     "que no vayan a resistir el peso del techo. \n");

   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");
   add_clone(CLOACABICHO+"masa",4);

   add_exit("norte", CLOACAS+"c22", "corridor");
   add_exit("sur", CLOACAS+"c24", "corridor");

   set_light(40);
}
