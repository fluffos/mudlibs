// Cloaca. C5.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo secundario%^RESET%^");
   set_long("Te cuesta mucho mantener el equilibrio debido a que el suelo "
            "comienza a ser peligrosamente resbaladizo, ademas el agua empieza "
            "cubrirte hasta los tobillos. \n");

   add_item("suelo", "Te cuesta distingir el fondo. \n");
   add_item("pared", "Las paredes estan llenas de grietas, parece que no vayan "
                     "a resistir el peso del techo. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"desuellamentes",2);

   add_exit("norte", CLOACAS+"c4", "corridor");
   add_exit("sur", CLOACAS+"c6", "corridor");

   set_light(40);
}
