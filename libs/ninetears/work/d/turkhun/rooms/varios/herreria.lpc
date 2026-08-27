// Herreria. Gestur '97

#include "/d/abarrach/path.h"

inherit "/std/shop";

object herrero;

void reset()
{ 
   if(!herrero)
   {
      herrero=clone_object(NPCGE+"herrero");
      herrero->move(this_object());
   }
   ::reset();
}
   
void setup()
{
  set_short("%^BOLD%^%^CYAN%^Herreria de Abarrach%^RESET%^");
  set_long("Por la cantidad de artilugios dedicados a forjar metales que "
  "hay aqui deduces que estas en una herreria. Hay un gran surtido "
  "de armas y armaduras por aqui. Quizas encuentres la mas apropiada "
  "para ti aqui.\n\n  Los comandos son:\n\n"
  "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
  "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
  "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n\n");

   set_light(60);
   add_exit("fuera", CIUDAD+"f0608", "door");
   set_store_room(VARIOS+"almacen4");
   add_property("smithy", 1); 
   sell_only();
   set_open_condition("holas"); // ->condicion de abierto  ;)
   
}
int holas()
{  
   object *Pelea;
   int i;
   if(!herrero) return 0; 
   else{ 
         Pelea=herrero->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(herrero))
          return 0;
   } 
   return 1;
}
