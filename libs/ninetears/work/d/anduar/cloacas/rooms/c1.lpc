// Cloaca.
// Errante'97

// Cambia las descripciones

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Cloacas de Anduar%^RESET%^");
   set_long("Tus pies chapotean en el agua cenagosa de debajo de tus pies. Un "
            "olor nauseabundo penetra por tu nariz.\n" 
            "Las paredes estan llenas de fango y moho, ademas un pequenyo "
            "riachuelo de distintos colores circula lentamente por debajo de ti. "
            "Del techo cuelgan largos hilos de porqueria.\n");

   add_item("suelo", "El suelo es cochambroso.\n");

   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");
   add_exit("fuera", ANDUAR+"precipicio2523", "door");
   add_exit("sur", CLOACAS+"c2", "corridor");

   set_light(20);
}
