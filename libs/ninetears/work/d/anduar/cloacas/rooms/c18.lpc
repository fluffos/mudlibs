// Ampliacion de las cloacas Errante'97, Aokromes'99

#include "../../path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo auxiliar%^RESET%^");
   set_long("Las paredes estan llenas de fango y moho seco. En la pared de "
   "enfrente, pegado a ella, un perro yace muerto, te preguntas como "
   "habra ido a parar a ese sitio. Encima de ti ves un agujero del tamanyo "
   "de un brazo por el que entra la luz con la que ves. \n");

   add_item("suelo", "El suelo esta completamente seco.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas."
   "\n");

   add_exit("sur", CLOACAS+"c17", "corridor");

   add_clone(CLOACABICHO+"rata",8);

   set_light(0);
}

void init()
{
 ::init();
 add_action("quitar_perro","quitar");
}

int quitar_perro(string str)
{
  if(str=="perro")
  {
  write("Sueltas el perro muerto de la pared y aparece una puerta oculta.\n");
  say(this_player()->query_cap_name()+" arranca el perro.\n");
  add_exit("trampilla",CLOACAS+"c27","door");
  renew_exits();
  return(1);
  }
  notify_fail("Quitar que?.\n");
  return(0);
}
