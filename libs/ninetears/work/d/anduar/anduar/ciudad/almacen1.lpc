inherit "/std/storeroom";
#include "../path.h"

setup()
{
	set_short("El almassen");
	set_long("Aqui e donde se guardan los objetos.\n");
	add_exit("south", ANDUAR+"tienda", "door");
	set_light(80);
}

void reset()
{
	call_out("af_reset", 0);
}

void af_reset()
{
   int i, j;
   object ob, torch;
        
   i = sizeof(find_match("monederos", this_object()));
   for (;i<3;i++)
   {
     ob = clone_object("/std/container");
     j = random(3);
     ob->set_max_volume(1000+j*2000);
     ob->set_max_weight(10+j*20);
     ob->set_name("bote");
     ob->set_short("bote "+({ "pequenyo", "mediano", "grande" })[j]);
     ob->set_main_plural("botes "+({ "pequenyos", "medianos", "grandes" })[j]);
     ob->add_adjective( ({ "pequenyo", "mediano", "grande" })[j]);
     ob->add_plural("botes");
     ob->set_value(60+j*23);
     ob->set_long("Un recipiente "+({ "pequenyo","mediano","grande"})[j]+
     ". Sirve para meter pequenyas cosas en el.\n");
     ob->move(this_object());
     ob->set_weight(4+j*3);
     ob->set_genero(0);
   }
   i = sizeof(find_match("torches", this_object()));
   for (;i<4;i++)
   {
   torch = clone_object("/obj/misc/torch");
   torch->move(this_object());
   }
   i = sizeof(find_match("quarterstaves", this_object()));
   for (;i<2;i++)
   {
   ob = clone_object("/baseobs/weapons/twohanded_staff");
   ob->move(this_object());
   }
}
