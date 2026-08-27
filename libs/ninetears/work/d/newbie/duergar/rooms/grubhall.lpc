/*  Text alterations and additions by Grimbrand 2-3-96                   */

inherit "/std/pub";
#include "path.h"
#include "pub.h"
 
object countertop;
object stove;
object oven;
object *npcs;
int isguarding = 0;
 
void setup() {
   npcs=allocate(1);
   set_short("Reinado Duergar:  Cantina de la academia.");
   add_property("no_undead",1); set_light(55);
   set_long("\n   Reinado Duergar:  Cantina de la academia.\n\n"
	    "     Entras a la cantina, y lo primero que notas es "
	    "un OLOR a estofado y otros guisos.  Una esquina al fondo ha "
	    "sido adaptada para montar una cocina, en ella una  "
	    "vieja duergar esta preparando algun plato, la ves "
	    "moverse desenvuelta  entre una estufa y un horno. los "
	    "unicos muebles son una mesa y dos bancos.\n"
	    "\n");

   add_item("mesa",
	    "   Es una gran mesa hecha de madera que obviamente ha  "
	    "sido usada muchas veces.  La tabla superior esta "
	    "ligeramente quemada y gastada por tanto uso.  Es un "
	    "testimonio de todos los duergar que han pasado antes "
	    "que tu por la academia.\n"
	    "\n");

   add_item(({"banco", "bancos"}),
	    "   Los bancos estan tan gastados como la mesa.  Fue un "
	    "sabio duergar quien decidio hacerlos de piedra en vez de "
	    "madera.  Solo en piedra podrian resistir los golpes "
	    "y el mal uso de incontables duergar entrando y saliendo "
	    "de la cantina.\n"
	    "\n");

   add_smell("cuarto",
	     "   huele a comida que se esta haciendo en algun lado.\n\n");
   
   add_smell("cantina",
              "	 huele a comida que se esta haciendo en algun lado.\n\n");	    

   add_smell("estofado",
	     "   Huele que alimenta!  tal vez te puedas "
	     "\"servir\" un poco sin pagar!\n\n");
 
   add_exit("sur", NEWBIE+"main02", "door");

   add_menu_item("Sidra", ALCOHOL, 30, 15, 15, 15,
                 "te escancias unos culinos",
                 "se escancia unos culinos de sidra");

   add_menu_item("Jugo de carne", FOOD, 100, 100, 100, 0,
                 "tomas una buena racion de jugo con tropezones",
                 "se toma una racion de jugo de carne");

   add_menu_item("Te", SOFTDRINK, 5, 0, 1, 0,
                 "tomas una taza de te caliente",
                 "toma una taza de te humenate");

   add_menu_item("Cafe", SOFTDRINK, 10, 1, 3, 0,
                 "tomas un tazon de cafe vigorizante",
                 "toma un tazon de cafe con deleite");

   add_menu_alias("sidra", "Sidra");
   add_menu_alias("sidrina", "Sidra");
   add_menu_alias("sidruca", "Sidra");
   add_menu_alias("jugo de carne", "Jugo de carne");
   add_menu_alias("Jugo", "Jugo de carne");
   add_menu_alias("jugo", "Jugo de carne");
   add_menu_alias("carne", "Jugo de carne");
   add_menu_alias("jugo carne", "Jugo de carne");
   add_menu_alias("te", "Te");
   add_menu_alias("cafe", "Cafe");

   set_zone("pub");
   add_clone(ITEMS+"countertop",1);
   add_clone(ITEMS+"oven",1);
   add_clone(ITEMS+"stove",1);
   add_clone(DNPC+"dlady",1);
} /* setup */
 
