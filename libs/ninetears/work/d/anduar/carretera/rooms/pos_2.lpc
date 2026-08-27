// Panaderia. Gestur '97

#include "path.h"

inherit "/std/shop";

object panadero;

void setup()
{
   set_short("%^YELLOW%^Panaderia grupo comercial Comellas%^RESET%^");
   set_long("Has entrado en un panaderia. El olor de pan recien hecho "
            "y dulces te abre enormemente el apetito. Sientes la necesidad "
            "de comer algo y rapido. Los comandos son:\n\n"
            "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
            "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
            "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver "
            "cuanto vale.\n");
   set_light(60);
   add_exit("este", CARRETERA"pos_5", "door");
   set_store_room(CARRETERA+"almacen3");
   sell_only();
}

void reset()
{
   ::reset();
   if (!panadero)
   {
      panadero=clone_object(CARRETERA+"npcs/panadero");
      panadero->move(this_object());
   }
}

void dest_me()
{
   if (panadero) panadero->dest_me();
   ::dest_me();
}

