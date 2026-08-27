// Panaderia. Gestur '97

#include "/d/abarrach/path.h"

inherit "/std/shop";

object panadero;

void setup()
{
   set_short("%^BOLD%^BLACK%^Abarrach: %^YELLOW%^Panaderia.%^RESET%^");
   set_long("Has entrado en un panaderia. El olor de pan recien hecho "
            "y dulces te abre enormemente el apetito. Sientes la necesidad "
            "de comer algo y rapido. Los comandos son:\n\n"
            "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
            "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
            "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver "
            "cuanto vale.\n");
   set_light(60);
   add_exit("fuera", CIUDAD"as1916", "door");
   set_store_room(VARIOS+"almacen3");
   set_open_condition("holas"); // ->condicion de abierto  ;)
   sell_only();
}

void reset()
{
   ::reset();
   if (!panadero)
   {
      panadero=new(NPCGE"panadero");
      panadero->move(this_object());
   }
}

void dest_me()
{
   if (panadero) panadero->dest_me();
   ::dest_me();
}

int holas()
{  
   object *Pelea;
   int i;
   if(!panadero) return 0; 
   else{ 
         Pelea=panadero->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(panadero))
          return 0;
   } 
   return 1;
}

