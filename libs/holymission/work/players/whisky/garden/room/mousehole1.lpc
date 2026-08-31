
#define TP this_player()
#define TPR TP->query_real_name()
 
inherit "room/room";
#include "../garden.h" 
 
void reset(int arg) 
{
  if (filter_live(TO) < 3)
  {
    CM("grasshopper");
    CM("grasshopper");
  }
   if (arg) return;
   set_light(0);
   short_desc = "In a mousehole";
   no_castle_flag = 0;
   long_desc =  BS(
        "This is a mousehole of Chantilly's beautiful garden. "
      + "It is under the big apple tree and it is a good place for "
      + "the mouse to gather apples or to eat some insects. "
      + "Be careful, the mouse doesn't like strange intruders. "
      + "The hole leads up to Chantilly's garden and to the north the "
      + "dark tunnel leads further.");

    dest_dir = 
        ({ ROOM+"/garden3","up",
           ROOM+"/mousehole2","north",
        });
}
