// Cloaca. C10.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Cruce pasillo secundario%^RESET%^");
   set_long("Parece ser que te encuentras en medio de un cruce. \n");

   add_item("suelo", "Solo ves agua. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"ho_rata",1);
   
   add_exit("este", CLOACAS+"c9", "corridor");
   add_exit("oeste", CLOACAS+"c19", "corridor");
   add_exit("norte", CLOACAS+"c16", "corridor");
   add_exit("sur", CLOACAS+"c11", "corridor"); 
   set_light(0);
}
