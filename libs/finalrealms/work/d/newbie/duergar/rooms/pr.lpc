/*  Text alterations and additions by Grimbrand 2-3-96                   */

#include "path.h"
inherit "/std/underground";

void init() {
   ::init();
   add_action("pickstuff", "pick");
   add_action("pickstuff","swing");
   if((!this_player()->query_property("no_pick"))&&
      (!this_player()->query_property("pick")))
	this_player()->add_property("pick");
}

int pickstuff(string arg) {
   object *it;
   int xp,pick;


   if(!arg) return 0;

   if((int)this_player()->query_property("no_pick")==1)
      return 0;

   if((arg == "rock") || (arg == "rocks") || (arg == "wall") || 
      (arg == "walls") || (arg == "floor") || (arg == "boulder") || 
      (arg == "boulders")) 
     {
      pick=this_player()->query_property("pick");

   if(!present("pick", this_player()))
     {
      return 0;
     }
   
   it = find_match("skiepick",this_player());
   if(!sizeof(it)) return 0; // taniwha
 
   if((int)it[0]->query_property("PICKUSED")!=1)
     {
      write("   You need to hold the pick first.\n\n");
      return 1;
     }

   if(pick <= 25) 
     {
      write("   As you swing the pick, your aim is a little off "
	    "and all you do is knock a chip off the rock.\n"
	    "\n");
      xp = (16 + random(5));
      this_player()->adjust_xp(xp);
      pick = pick+1;
      this_player()->add_property("pick",pick); 
      return 1;
     }
    else 
      if(pick <= 50) 
	{
	 write("   With a more controlled approach, you take aim, and "
	       "swing your pick.  You are able to knock off a fair "
	       "sized chunk of rock, but it is shapeless, and not "
	       "very useable.\n"
	       "\n");
	 xp = (18 + random(5));
	 this_player()->adjust_xp(xp);
	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}  

    else 
      if(pick <= 75) 
	{
	 write("   With a steady hand, you swing the pick with more "
	       "confidence knocking a piece of the rock off making a "
	       "fairly flat surface.\n"
	       "\n");
	 xp = (22 + random(5));
	 this_player()->adjust_xp(xp);
	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}

    else 
      if(pick <= 100) 
	{
	 write("   You size up the rock with a quick look, and with a "
	       "few expert swings of your trusty pick, you make short "
	       "work of the rock transforming it into a useful block "
	       "for building.\n"
	       "\n");
	 xp = (24 + random(5));
	 this_player()->adjust_xp(xp);
	 pick = pick+1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}
   
   if(pick = 100) 
     {
      this_player()->remove_property("pick");
      this_player()->add_property("no_pick",1);
      write("   As you look at your pick you notice a large crack "
	    "running the length of the handle.  There is no way you "
	    "can use it now.\n"
	    "\n");
      it[0]->dest_me();
      return 1;
     }
   return 1;
}

   if((arg == "stalagmite") || (arg == "stalagmites") || 
      (arg == "stalagtite") || (arg == "stalagtites")) 
     {
      pick = this_player()->query_property("pick");
      
      if(!present("pick", this_player()))
	{
	 return 0;
	}
   
      it = find_match("skiepick",this_player());
      if((int)it[0]->query_property("PICKUSED")!=1)
	{
	 write("   You need to hold the pick first.\n\n");
	 return 1;
	}

      if(pick <= 25) 
	{
	 write("   You wildly swing your pick only glancing your "
	       "blow off the rock formation.  What a wimp!\n"
	       "\n");
	 xp = (18+random(10));
	 this_player()->adjust_xp(xp);
	 pick = pick + 1;
	 this_player()->add_property("pick",pick);
	 return 1;
	}
      else 
	 if(pick <=50) 
	   {
	    write("   You take a more controlled approach at working the "
		  "rock knocking off a fair sized piece.  It is rather "
		  "shapeless and not very useable though.\n"
		  "\n");
	    xp = (19+random(10));
	    this_player()->adjust_xp(xp);
	    pick = pick +1;
	    this_player()->add_property("pick",pick);
	    return 1;
	   }
	 else 
	    if(pick <= 75) 
	      {
	       write("   With a steady hand, you swing your pick with "
		     "confidence knocking a piece of rock off with a "
		     "fairly flat surface on it.\n"
		     "\n");
	       xp = (20+random(10));
	       pick = pick + 1;
	       this_player()->add_property("pick",pick);
	       this_player()->adjust_xp(xp);
	       return 1;
	      }
	    else 
	       if(pick < 100) 
		 {
		  write("   You size up the rock formation with a quick "
			"glance, and with a few expert swings of your "
			"trusty pick, you make short work of the rock "
			"formation transforming it into a useable block "
			"for building.\n"
			"\n");
		  xp = (21+random(10));
		  this_player()->adjust_xp(xp);
		  pick = pick + 1;
		  this_player()->add_property("pick",pick);
		  return 1;
		 }
	       else 
		  if(pick = 100) 
		    {
		     this_player()->remove_property("pick");
		     this_player()->add_property("no_pick",1);
		     write("   As you look at your pick, you notice a "
			   "large crack running the length of the "
			   "handle.  There is no way that you can use "
			   "this pick now.\n"
			   "\n");
		     it[0]->dest_me();
		     return 1;
		    }
     }

   if(arg != "xyxyxy") 
     {
      write("   You pick your nose.\n\n");
      return 1;
     }
return 0;
}
