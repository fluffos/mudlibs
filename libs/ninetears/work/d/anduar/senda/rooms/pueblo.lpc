#include "senda.h"
#include "path.h"

varargs void comun(object ob)
{
   if (!ob) ob=this_object();    // Para hacerlo compatible con el inherit.
   
   ob->set_short("%^BOLD%^Poblado de "+POBLADO+" al pie de las colinas de "+
   COLINAS+"%^RESET%^");
   ob->set_exit_color("white");
   ob->set_dark_long("Estas en lo que parece una especie de poblado.\n\n");
   ob->add_item("suelo", "Es un suelo natural desprovisto de vegetacion "
   "debido a que este es pisado con frecuencia.\n");
   ob->add_item(({"montanyas", "montanya"}), "Son unas colinas. La senda "
   "va hacia ellas. Te preguntas que misterios se "
   "ocultaran detras de ellas.\n");
   ob->set_light(70);
}

varargs void npcs(int max, object ob)
{
   int i, n;
   
   n=random(max+1);
   
   if (!ob) ob=this_object();
   
   for (i=0; i<n; i++)
   {
      ob->add_clone(NPC+"hab_eloras", 1);
   }
}
