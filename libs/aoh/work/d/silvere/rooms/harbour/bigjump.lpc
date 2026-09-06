/* Bigjump.c */

// pattern: magictcs Falling.c 
// changed by taurec - 5.6.'97 

#include <macros.h>
#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <silvere.h>
inherit HARBOUR_BASEROOM;

mixed msges =
({
	"The fishermen set a course to the harbour of Silvere.\n",
	"You gasp for breath when seeing some fishermen laughing happily at you.\n",
	"Lucky you! Suddenly, something pulls you up again!\n",
	"Oxygen-deficiency blurs your sight - You feel death approaching.\n",
	"Sea-horses and lots of fish examine you with big, amazed eyes.\n",
	"The water-masses close above you.\n",
	"With a loud splash, you plunge into the profound sea.\n",
	"You see the surface of the ocean coming closer and closer !!!\n",
        "Seagulls and other birds are passing by.\n",
	"You gather up speed.\n",
	"You jump through a hole in the fog.\n",
});

varargs void create()
{
	::create();
	Set(P_INT_SHORT, "Uuuaaaahhhhhhh! *SPLASH*");
        Set(P_INT_LONG, "");
	Set(P_INDOORS,0);
	AddDetail(({"wall","walls"}),
		"Walls ?!? What walls ? There's only blue everywhere... "
        "blue water, blue sky extending 'til it meets horizon.\n");
}

void init()
{
	::init();
	call_out ("fall_msg",1,sizeof(msges)-1);
}

void fall_msg(int count)
{
	if (!TP || environment(TP)!=this_object())
	{  /* victim somehow escaped... or quit */
		return 0;
	}
	if (count > 0)
	{
		count--;
		write(msges[count]);
		call_out("fall_msg",4,count);
	}

	else
	{
         TP->move(SIL_HARBOUR("quay1_2"),M_SPECIAL,
			({"climbs aboard a fisherboat below you",
			  "is dropped here by some fishermen",
			  "are dropped at the harbour of Silvere"}));
	}
}

