#include "path.h";

inherit FORESTROOM;
object Geldon;
string *free_object;



void init ()
{
 add_action ("free_elf", "free");
 :: init ();
}


int free_elf (string ob)
{
 object *stuff;
 int i, j, check;

 stuff = all_inventory (this_player ());
 check = 0;

   Geldon = present("geldon");
   if(!ob || !Geldon)
 {
  write ("Free whom?\n");
 }
 else
 {
  if ((ob != "elf") && (ob != "geldon"))
  {
   write ("Sorry, you can not free that.\n");
  }
  else
  {
   for (i = 0; i < sizeof (stuff); i ++)
   {
    free_object = explode ((stuff [i] -> query_short ()), " ");

    for (j = 0; j < sizeof (free_object); j ++)
    {
     if ((free_object [j] == "Dark key") || (free_object [j] == "Dark"))
     {
			write("You use your key to free this poor elf.\n");
      stuff[i] -> dest_me ();
      check = 1;
				if(!this_player()->query_property("elf_free"))
			{	
				this_player()->add_property("elf_free", 1);
// Taniwha NO XP quests in the newbie areas
                              this_player()->adjust_money(5,"platinum");
				write("Geldon says: Thank you for freeing "
					"me from that evil priest.\n"
                    "Geldon says: Here are a few coins for your trouble.\n"
					"Geldon waves and dissapears into "
					"the forest.\n\n");
                           if(Geldon) Geldon->dest_me();
			}
			else {
			write("Geldon says: You remind me of someone who came "
				"earlier and tried to free me.\n");
			}
	return 1;
     }
    }
   }
   if (check == 0)
   {
		write ("Hmmm, you are going to need a key to free him.\n");
   }
  }
 }
 return 1;
}

