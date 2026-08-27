
#include "/w/barthleby/path.h"

inherit "/std/shop";

object herrero;

void reset()
{ 
   if(!herrero)
   {
      herrero=clone_object(NPC+"herrero");
      herrero->move(this_object());
   }
   ::reset();
}
   
void setup()
{
  set_short("%^BOLD%^%^CYAN%^Herreria de Noella%^RESET%^");
  set_long("El calor de este lugar te hace pensar que la forja, que el "
   "herrero usa para fundir los metales, nunca descansa. En este lugar "
   "se puede conseguir una gran variedad de objetos artesanales."
           "\n\n  Los comandos son:\n\n"
           "  <%^RED%^listar%^RESET%^>   para listar\n"
           "  <%^RED%^comprar%^RESET%^>  para comprar\n"
           "  <%^RED%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n"
           "  <%^RED%^valorar%^RESET%^>  para valorar un objeto antes de venderlo.\n\n");

   set_light(60);
   add_exit("fuera", DOM+"nivel1/m11", "door");
   set_store_room(PRINCIPALES+"almacen");
   add_property("smithy", 1);
   add_property("no_undead", 1);
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

