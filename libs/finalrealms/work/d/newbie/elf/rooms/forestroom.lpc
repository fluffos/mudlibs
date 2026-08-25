inherit "std/outside";
#include "path.h"

int j,k;
int stocked;

void reset()
{
   add_property("no_undead",1);
   if(!stocked)
   {
      stocked = 1;
	j=random(6);
	for(k=0;k<j;k++)
	{
	int i;
	i=random(7);
      switch(i)
      {
         case 0:
         add_clone(CHAR+"rabbit",1);
         break;
         case 1:
         add_clone(CHAR+"squirrel",1);
         break;
         case 2:
         add_clone(CHAR+"birdie",1);
         break;
         case 3:
         add_clone(CHAR+"deer",1);
         break;
         case 4:
         add_clone(CHAR+"boar",1);
         break;
         case 5:
         add_clone(CHAR+"sprite",1);
         break;
         case 6:
         add_clone(CHAR+"forlarren",1);
         break;
      }
    }
   }
   ::reset();
}
