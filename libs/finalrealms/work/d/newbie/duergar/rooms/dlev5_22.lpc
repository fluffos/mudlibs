 //*This Room Re-worked by Ralkor*//

#include "path.h"
inherit "/std/underground";

object *npcs;
int mush;

void reset() {
int i;
   mush = 5;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dgoblin");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
   mush = 5;
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);

   set_short("Realm of the Duergar:  Racial Proving Grounds");

   set_long("\n  Realm of the Duergar:  Racial Proving Grounds.\n\n"
            "     In this corner of the cavern you notice several "
            "mushrooms growing along the base of the wall.  They appear "
            "to be the same kind of mushrooms that you were fed when "
            "still a child.  Carefully you contemplate whether to pick "
            "them or to leave them to grow freely."
	    "\n\n");

   add_item(({"wall", "walls"}),
	    "   Looking at the wall, you can see where various weapons "
	    "have left chip marks from wild swings and glancing blows."
	    "\n\n");

   add_item(({"mushroom", "mushrooms"}),
            "   Upon further inspection of the mushrooms you are "
            "positive that they are of the same type that you once "
            "ate in your childhood."
            "\n\n");

   add_exit("south",NEWBIE+"dlev5_28","path");
   add_exit("west",NEWBIE+"dlev5_21","path");
}

void init()
{
   ::init();
   add_action("pick_mushrooms","pick");
}
int pick_mushrooms(string str)
{
   if(str != "mushrooms")
   {
   return(0);
   }
   if(mush <= 0)
   {
      write("Sorry, there are no more mushrooms right now.\n");
      return 1;
   }
   {
     write("You pick some mushrooms from along the wall and "
          "consume them.  Mmm...those were good."
          "\n\n");
     this_player()->adjust_hp(random(3)+2);
   mush = mush -1;
     return(1);
   }
}
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
