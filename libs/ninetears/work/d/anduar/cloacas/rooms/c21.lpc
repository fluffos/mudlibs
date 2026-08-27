// Cloaca. C21.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo principal%^RESET%^");
   set_long("Parece ser que has llegado al fondo del pasillo principal. "
            "A tu izquierda se abre un oscuro camino hacia las profundidades de "
            "las laberinticas cloacas de Anduar. \n");

   add_item("suelo", "El agua ha disminuido considerablemente. \n");
   add_item("pared", "La pared tiene marcas de como si alguien pasase muy "
                     "a menudo por ahi");
     add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");


   add_clone(CLOACABICHO+"murcielago",2);
   add_clone(CLOACABICHO+"ho_rata",1);

   add_exit("west", CLOACAS+"c46", "corridor");
   add_exit("este", CLOACAS+"c20", "corridor");
   add_exit("sur", CLOACAS+"c22", "corridor");

   set_light(0);
}
