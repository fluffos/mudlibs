#include "senda.h"

varargs void comun(object ob)
{
   if (!ob) ob=this_object();    // Para hacerlo compatible con el inherit.
   
   ob->set_short("%^ORANGE%^Llanuras de Ostigurth, cerca de las Colinas de "
   +COLINAS+"%^RESET%^");
   ob->set_exit_color("cyan");
   ob->set_dark_long("Estas en una senda en la que apenas distingues nada.\n\n");
   ob->add_item("suelo", "Es una senda generada por el simple paso de las "
   "personas. Es simplemente la ausencia de vegetacion la que dibuja el "
   "camino.\n");
   ob->add_item(({"montanyas", "montanya"}), "Son unas montanyas. La senda "
   "se dirige hacia ellas. Te preguntas que misterios se ocultaran detras de "
   "ellas.\n");
   ob->set_light(80);
}

varargs void npcs(int max, object ob)
{
   return;
/*
   int i, n, tipo;
   
   n=random(max+1);
   
   if (!ob) ob=this_object();
*/      
}