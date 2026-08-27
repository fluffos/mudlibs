#include "senda.h"
#include "path.h"

varargs void comun(object ob)
{
   if (!ob) ob=this_object();    // Para hacerlo compatible con el inherit.
   
   ob->set_short("%^GREEN%^Senda en las Llanuras de "+LLANURAS+"%^RESET%^");
   ob->set_exit_color("white");
   ob->set_dark_long("Estas en una senda en la que apenas distingues nada.\n\n");
   ob->add_item("suelo", "Es una senda generada por el simple paso de las "
   "personas. Es simplemente la ausencia de vegetacion la que dibuja el "
   "camino.\n");
   ob->add_item(({"montanyas", "montanya"}), "Son unas montanyas que ves al fondo. Parece que "
   "la senda se dirige hacia ellas. Te preguntas que misterios se "
   "ocultaran detras de ellas.\n");
   ob->set_light(90);
}

varargs void npcs(int max, object ob)
{
   int n, i;
   
   n=random(max+1);
   
   for (i=0; i<max; i++)
   {
      switch(random(3))
      {
         case 0: ob->add_clone(NPC+"viajero", 1); break;
         case 1: ob->add_clone(NPC+"bandido", 1); break;
//         case 2: ob->add_clone(NPC+"conejo", 1); break;
      }
   }
}
