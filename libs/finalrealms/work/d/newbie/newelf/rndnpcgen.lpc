inherit "/std/outside";
#include "path.h"

int j,k;
int stocked;

void my_setup()
{

    if(!stocked)
    {
	stocked = 1;
	j=random(3);
	for(k=0;k<j;k++)
	{
	    int i;
	    i=random(100);
	    switch(i)
	    {
	    case 0..19:
		add_clone(NPCS+"deer",1);
		break;
	    case 20..39:
		add_clone(NPCS+"kendtown",1);
		break;
	    case 40..49:
		add_clone(NPCS+"kendgard",1);
		break;
	    case 50..59:
		add_clone(NPCS+"rabbit", 1);
		break;
	    case 60..99:
		add_clone(NPCS+"wolf", 1);
		break;
	    }
	}
    }
} /*setup*/
