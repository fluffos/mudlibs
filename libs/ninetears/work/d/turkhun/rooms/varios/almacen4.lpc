inherit "/std/storeroom";
#include "/d/abarrach/path.h"

setup()
{
	set_short("El almassen");
	set_long("Aqui e donde se guardan los objetos.\n");
	add_exit("south", VARIOS+"tienda", "door");
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
        
   i=sizeof(find_match("chainmails", this_object()));
   for (;i<3;i++)
   {
      ob=new("/baseobs/armours/chainmail");
      ob->move(this_object());
      ob->set_value(100);
   }
   i=sizeof(find_match("short swords", this_object()));
   for (;i<2;i++)
   {
      ob=new("/baseobs/weapons/short_sword");
      ob->move(this_object());
      ob->set_value(30);
   }
   i=sizeof(find_match("medium shields", this_object()));
   for (;i<2;i++)
   {
      ob=new("/baseobs/armours/med_shield");
      ob->move(this_object());
      ob->set_value(5);
   }
   i=sizeof(find_match("small shields", this_object()));
   for (;i<2;i++)
   {
      ob=new("/baseobs/armours/sma_shield");
      ob->move(this_object());
      ob->set_value(5);
   }
   i=sizeof(find_match("long swords", this_object()));
   for (;i<2;i++)
   {
      ob=new("/baseobs/weapons/long_sword");
      ob->move(this_object());
      ob->set_value(8);
   }
   i=sizeof(find_match("helmet", this_object()));
   for (;i<5;i++)
   {
      ob=new("/baseobs/armours/helmet");
      ob->move(this_object());
      ob->set_value(4);
   }
}
