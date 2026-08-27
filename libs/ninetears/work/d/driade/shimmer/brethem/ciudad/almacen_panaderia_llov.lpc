/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "/std/storeroom";

void setup()
{
	set_short("El Almacen de la Panaderia de Llov");
	set_long("Aqui e donde se guardan las provisiones de la panaderia de Llov.\n");
	add_exit("abajo", BRETHEM + "panaderia1", "door");
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
        
   i = sizeof(find_match("algas", this_object()));
   for (;i<3;i++)
   {
     ob=clone_object(BRETHEM + "items/pudding_algas")->move(this_object());
   }
   i = sizeof(find_match("kitche", this_object()));
   for (;i<4;i++)
   {
     ob=clone_object(BRETHEM + "items/kitche")->move(this_object());
   }
   i=sizeof(find_match("panes de viaje", this_object()));
   for (;i<20+random(10);i++)
   {
      ob=new(BRETHEM + "items/barra_cuarto")->move(this_object());
   }
   i=sizeof(find_match("grandes panes", this_object()));
   for (;i<18+random(8);i++)
   {
      ob=new(BRETHEM + "items/barra_medio")->move(this_object());
   }
}
