
inherit "/room/room";
#include "defs.h" 

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         short_desc = "In a dark passage";
         long_desc = BS(
         "You are standing in a dark, wet passage. The ruined "+
         "walls are covered with fouly moss. There is a strange "+
         "sweet smell in the air.");

         items = 
         ({
           "moss","Grey fouly moss",
         });

         dest_dir =
         ({
            PATH+"cellar_passage1","south",
            PATH+"cellar_passage3","north",
         });
     }
}


