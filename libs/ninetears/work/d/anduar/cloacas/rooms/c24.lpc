// Cloaca. C24.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Giro pasillo terciario%^RESET%^");
   set_long("Aqui notas un extranyo frio en los pies y puedes ver mejor, "
            "hecho que te extranya. Ves una pared bastante extranya cubierta por "
            "matorrales y hierbajos.\n");


   add_item("suelo", "Se ve un pequenyo resplandor. \n");
   add_item("pared", "Es una pared marron distinta a las demas.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_exit("norte", CLOACAS+"c23", "corridor");
   add_exit("este", CLOACAS+"c25", "corridor");

   set_light(0);
}
void init()
{
 ::init();
   add_action("empujar_pared","empujar");

}

int empujar_pared(string str)
{
  if(str=="pared")
  {
   write("Empujas la pared y detras de ella se abre un agujero del tamanyo "
         "de un hombre. Sin pensartelo te metes por el.\n");
   say(this_player()->query_cap_name()+" de repente desaparece por algun "
   "sitio.\n");
   this_player()->move(CATACUMBAS+"c1");
   this_player()->look_me();
   return(1);
  }
  notify_fail("empujar que?.\n");
  return(0);      
}             
