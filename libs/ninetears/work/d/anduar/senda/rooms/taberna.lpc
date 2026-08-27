
inherit "std/pub";
#include "pub.h"
#include "path.h"
#include "senda.h"

object comellas, globo, tablon;

//nombre.tipo.coste.heal.volumen.intox

void setup()
{
   add_menu_item("Licor del Montanyero", ALCOHOL, 300, 10, 30, 100,
      "bebes un licor muy fuerte", "se bebe un licor y seguidamente se le "
      "suben los colores a la cara");
   
   add_menu_item("Cerveza Negra", ALCOHOL, 150, 5, 20, 50,
      "bebes con gusto una fria cerveza negra", "se bebe con gusto una "
      "fria cerveza negra");
      
   add_menu_item("Cochinillo Asado", FOOD, 1750, 35, 50, 0,
      "comes tranquilamente un cochinillo asado entero", "se come un "
      "apetitoso cochinillo asado");
   add_menu_item("Pollo Hervido", FOOD, 1000, 20, 30, 0,
      "comes un pollo hervido con verduras", "se come un pollo hervido "
      "con verduras");
    
   add_menu_alias("licor", "Licor del Montanyero");
   add_menu_alias("cerveza", "Cerveza Negra");
   add_menu_alias("cochinillo", "Cochinillo Asado");
   add_menu_alias("pollo", "Pollo Hervido");

   set_short("%^BLUE%^BOLD%^Hostal del Montanyero%^RESET%^");
   set_long("Estas en el Hostal del Montanyero, el unico hostal que hay "
            "en el poblado de "+POBLADO+". Aqui descansan y reponen fuerzas "
            "los exploradores y aventureros que quieren escalar las montanyas "
            "de "+COLINAS+". Es un sitio rustico adornado casi todo con "
            "articulos hechos de madera. Puedes ver una larga barra donde "
            "se sirve la comida.\n");
   
   add_exit("out", SENDA+"p3");
   set_light(60);
   
   add_item("barra", "Es una larga barra por la cual se sirven las bebidas "+
                     "o comidas que los clientes piden.\n");	
  
   add_clone("/obj/misc/globe", 1);
   add_clone(NPC+"aguelo", 1);
   add_clone(NPC+"hab_eloras", 2);
}
