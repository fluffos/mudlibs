// Cloaca. C7.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Final pasillo secundario%^RESET%^");
   set_long("Parece ser que has llegado al fondo del pasillo secundario. "
            "A tu derecha se abre un oscuro camino hacia las profundidades de "
            "las laberinticas cloacas de Anduar. \n");

   add_item("suelo", "El agua sube ligeramente por la pared. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"ho_rata",1);

   add_exit("norte", CLOACAS+"c6", "corridor");
   add_exit("oeste", CLOACAS+"c15", "corridor");

   set_light(0);
}
