/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "/std/storeroom";

void setup()
{
	set_short("El Almacen de la Tienda de Aura");
	set_long("Aqui e donde se guardan las provisiones de la Tienda de Aura.\n");
	add_exit("abajo", BRETHEM + "floristeria1", "door");
	set_light(80);
}

void reset()
{
	call_out("af_reset", 0);
}

void af_reset()
{
   int i, j;
   object ob;
        
   i = sizeof(find_match("blanca", this_object()));
   for (;i<3-random(2);i++)
   {
     ob=clone_object(BRETHEM + "items/planta_blanca")->move(this_object());
   }
   i = sizeof(find_match("verde", this_object()));
   for (;i<3-random(2);i++)
   {
     ob=clone_object(BRETHEM + "items/planta_verde")->move(this_object());
   }
   i=sizeof(find_match("panes de viaje", this_object()));
   for (;i<3+random(3);i++)
   {
      ob=new(BRETHEM + "items/barra_cuarto")->move(this_object());
   }
   i=sizeof(find_match("bolsita", this_object()));
   for (;i<2-random(2);i++)
   {
      ob=new(BRETHEM + "items/bolsita_marihuana")->move(this_object());
   }
}
