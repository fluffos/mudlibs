inherit "/std/storeroom";
#include "path.h"

setup()
{
	set_short("The storeroom");
	set_long("The storeroom.\n");
	add_exit("south", ROOM+"korbus", "door");
	set_light(100);
}

void reset()
{
	call_out("af_reset", 0);
}

void af_reset()
{
   int i, j;
   object ob, torch;
        
   i = sizeof(find_match("buckets", this_object()));
   for (;i<3;i++)
   {
     ob = clone_object("/std/container");
     j = random(3);
     ob->set_max_volume(1000+j*2000);
     ob->set_max_weight(10+j*20);
     ob->set_name("bucket");
     ob->set_short(({ "small", "medium", "large" })[j]+" bucket");
     ob->set_main_plural(({ "small", "medium", "large" })[j]+" buckets");
     ob->add_adjective( ({ "small", "medium", "large" })[j]);
     ob->add_plural("buckets");
     ob->set_value(60+j*23);
     ob->set_long("A metal bucket, it is not very shiny.\n");
     ob->move(this_object());
     ob->set_weight(4+j*3);
   }
   i = sizeof(find_match("torches", this_object()));
   for (;i<4;i++)
   {
     torch = clone_object("/obj/misc/torch");
     torch->move(this_object());
   }
}
