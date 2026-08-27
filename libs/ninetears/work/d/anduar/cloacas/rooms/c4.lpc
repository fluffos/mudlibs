// Cloaca. C4.
// Errante'97 Ampliacion Aokromes'99

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Cruce Pasillo principal%^RESET%^");
   set_long("Te apartas levemente porque por tu derecha, una corriente de "
       "aire frio te hiela, eso te hace suponer que el pasillo es largo. "
       "Y hacia el sur el pasillo continua con su negrura abrumadora. Hacia "
       "el este una verja a traves de la cual se precipitan las aguas "
      "fecales hacia la grieta del olvido\n");

   add_item("suelo", "La fuerza del agua es mucho mayor debido al cruce. \n");
   add_item("verja", "Una verja de resistente acero, que evita que cualquiera "
   "que baje a las cloacas se caigan al fondo de la grieta. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"ho_rata",1);

   add_exit("norte", CLOACAS+"c3", "corridor");
   add_exit("sur", CLOACAS+"c5", "corridor");
   add_exit("oeste", CLOACAS+"c8", "corridor");

   set_light(35);
}
