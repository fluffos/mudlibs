#include "/players/whisky/genesis/sys/filter_live.h"
/* moved out take break_text :)
#include "/players/whisky/genesis/sys/break_string.h"
 */
#define WIZ "players/whisky/"
#define OBJ "players/whisky/tree/obj/"
#define MONST "players/whisky/tree/monster/"
#define PATH "players/whisky/tree/room/"
#define BS(x) break_text(x+"\n",60)

void random_clone()
{
  switch(random(11))
  {
   case 0:
     move_object(clone_object(MONST+"ant"),this_object());
   break;
   case 1:
     move_object(clone_object(MONST+"beetle"),this_object());
   break;
   case 2:
     move_object(clone_object(MONST+"butterfly"),this_object());
   break;
   case 3:
     move_object(clone_object(MONST+"caterpillar"),this_object());
   break;
   case 4:
     move_object(clone_object(MONST+"grasshopper"),this_object());
   break;
   case 5:
     move_object(clone_object(MONST+"louse"),this_object());
   break;
   case 6:
     move_object(clone_object(MONST+"pheasant"),this_object());
   break;
   case 7:
     move_object(clone_object(MONST+"sparrow"),this_object());
   break;
   case 8:
     move_object(clone_object(MONST+"swarm"),this_object());
   break;
   case 9:
     move_object(clone_object(MONST+"swarm"),this_object());
   break;
   case 10:
     move_object(clone_object(MONST+"bubbleworm"),this_object());
   break;
   }
}

void init()
{ 
     ::init();
     add_action("fcn_pick","pick");
}

int fcn_pick(string arg)
{
    object ob;
    if (!arg)
       return 0;
 
    if (strstr(arg,"apple",0)!=-1)
    {
       if (transfer(ob = clone_object(OBJ+"apple"),this_player()))
       {
          write("You can't carry that much weight.\n");
          destruct(ob);
          return 1;
       }
       write("You picked an apple from the apple tree.\n");
      return 1;
    }
   return 0;
}
     
   
    
