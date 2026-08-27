#include "senda.h"

varargs void comun(object ob)
{
   if (!ob) ob=this_object();    // Para hacerlo compatible con el inherit.
   
   ob->set_short("%^ORANGE%^Colinas de "+COLINAS+"%^RESET%^");
   ob->set_exit_color("cyan");
   ob->set_dark_long("Estas en una senda en la que apenas distingues nada. "
   "El suelo tiene bastante pendiente.\n\n");
   ob->add_item("suelo", "Es una senda generada por el simple paso de las "
   "personas. Es simplemente la ausencia de vegetacion la que dibuja el "
   "camino.\n");
   ob->add_item(({"montanyas", "montanya"}), "No son muy altas, pero de una "
   "gran pendiente.\n");
   ob->set_light(70);
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