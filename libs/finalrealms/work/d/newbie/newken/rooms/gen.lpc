inherit "/std/outside";
#include "path.h"

int j,k;
int stocked;

void my_setup()
{

    if(!stocked)
    {
	stocked = 1;
	j=random(6);
	for(k=0;k<j;k++)
	{
	    int i;
	    i=random(100);
	    switch(i)
	    {
	    case 0..19:
		add_clone(NPCS+"deer",1);
		break;
	    case 20..29:
		add_clone(NPCS+"gnoll",1);
		break;
	    case 30..39:
		add_clone(NPCS+"rabbit",1);
		break;
	    case 40..49:
		add_clone(NPCS+"minotaur",1);
		break;
	    case 50..59:
		add_clone(NPCS+"frog",1);
		break;
	    case 60..69:
		add_clone(NPCS+"wasps", 1);
		break;
	    case 70..79:
		add_clone(NPCS+"birdie",1);
		break;
	    case 80..99:
		add_clone(NPCS+"mutt",1);
		break;
	    }
	}
    }
} /*setup*/
