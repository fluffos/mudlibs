// Cloaca. C22.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo terciario%^RESET%^");
   set_long("El suelo esta completamente seco y notas como si estuvieses "
            "en una posicion mas elevada. El suelo esta lleno de insectos pero "
            "huyen como si te tuviesen miedo. \n");

   add_item("suelo", "Seco y repleto de bichos. \n");
   add_item("pared", "Tiene muchas senyales de que han traido cosas mas grandes "
                     "que el pasillo por aqui. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");
                      
   add_clone(CLOACABICHO+"desuellamentes",1);

   add_exit("norte", CLOACAS+"c21", "corridor");
   add_exit("sur", CLOACAS+"c23", "corridor");
   
   set_light(40);
}

