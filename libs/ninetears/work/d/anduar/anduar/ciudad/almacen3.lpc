inherit "/std/storeroom";
#include "../path.h"

setup()
{
	set_short("El almassen");
	set_long("Aqui e donde se guardan los objetos.\n");
	add_exit("south", ANDUAR+"panaderia", "door");
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
        
   i = sizeof(find_match("fresas", this_object()));
   for (;i<3;i++)
   {
     ob=clone_object(OBJETOS+"tarta_fresa")->move(this_object());
   }
   i = sizeof(find_match("rons", this_object()));
   for (;i<4;i++)
   {
     ob=clone_object(OBJETOS+"tarta_ron")->move(this_object());
   }
   i=sizeof(find_match("panes de viaje", this_object()));
   for (;i<20+random(10);i++)
   {
      ob=new(OBJETOS+"barra_cuarto")->move(this_object());
   }
   i=sizeof(find_match("grandes panes", this_object()));
   for (;i<18+random(8);i++)
   {
      ob=new(OBJETOS+"barra_medio")->move(this_object());
   }
}
