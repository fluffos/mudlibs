// Ampliacion de las cloacas. C44.
// Errante'97, Aokromes'99

#include "../../path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Ciudad de anduar: Pasadizo secreto%^RESET%^");
   set_long("Bajo tus pies ya no hay insectos y no hay agua, por fin el "
   "pasillo parece ampliarse, esto ya no parece ser una cloaca, tal vez sea "
   "un pasadizo secreto de algun ricachon de la ciudad hecho para huir en caso "
   "de alguna emergencia. \n");

   add_item("suelo", "Ves el suelo totalmente seco.\n");
   add_item("pared", "La pared esta echa con mucho esmero, desde luego el que "
   "hizo tubo mucho cuidado de que fuese perfecto, ya que la manufactura "
   "parece ser enana.\n");
   add_smell("cloaca","el hedor de las cloacas ha desaparecido totalmente.\n");

   add_clone(CLOACABICHO+"rata",1);
   add_exit("este", CLOACAS+"c45", "corridor");
   add_exit("southwest", CLOACAS+"c43", "corridor");
   set_light(30);
}
