/* Air Room when falling down the tower of the palace in Silvere */

// created by Taurec [26-May-1998]
// last changed:

#include <macros.h>
#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <silvere.h>
#include <regions.h>
#include <coordinates.h>
inherit BASEROOM;

void fall_msg(int count, object pl);

mixed msges =
({
   "Oh, this tower really looks nice from the outside!\n",
   "You enjoy the wonderful view over the country.\n",
   "Then you look down to your feet and you realize...\n",
   "THERE'S NO GROUND BENEATH YOUR FEET!!!\n",
   "Just as you get this idea, the laws of physics begin "
   "to work and you gather up speed.\n",
   "You try to cling to the frame of the window, but too late!\n",
   "The time seems to slow down...\n",
   "Birds are passing by and chirp happily.\n",
   "Your whole life starts to pass before your eyes.\n",
   "The surface of the palace place comes closer and closer!\n",
   "Fidgeting wildly, you finally close your eyes and wait for "
   "the impact on hard cobblestones.....\n",
   "You already hear a hollow voice saying: COME WITH ME, "
   "MORTAL! LOOKS LIKE YOU.....\n",
   "But lucky you, you plummet directly in one of those thorny bushes!\n",
   "You stand up, knock off dust and leaves from your clothes and "
   "pick all those nasty thorns out of your skin.\n"
});

varargs void create()
{
  (::create());
  Set(P_INT_SHORT, "Uuuaaaahhhhhhh! *BONK*");
  Set(P_INT_LONG, "");
//    "You're in midair. To your west, there's a tower "
//    "of the palace. Deep down below you, there's the hard surface "
//    "of the palace place. Surely not the best place to do a belly "
//    "landing.\n");
  Set(P_INDOORS,0);
  AddDetail(({"wall","walls"}),
   "Walls ?!? What walls ? There's only air everywhere...\n");
  AddDetail(({"window"}),
   "You can not reach the window any more. It's high beyond.\n");
   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -10,20,10 }), C_SILVERE }) );
}

void notify_enter(string oldenv, int method, mixed extra){
	::notify_enter(oldenv,method,extra);
	call_out ("fall_msg",1,0,PO);
}

void fall_msg(int count, object pl)
{
   if (!pl || environment(pl)!=this_object())
   {
 	return 0;
   }
   if (count < sizeof(msges))
   {
      tell_object(pl,msges[count]);
      count++;
      call_out("fall_msg",3,count,pl);
    }
    else
    {
       pl->DoDamage(5);
       pl->move(SIL_CENTER("palplace4"),M_SPECIAL,
         ({"plummets to the ground down below you",
           "suddenly falls screaming loudly right out "
           "of the sky, fidgeting wildly. Luckily, "+CAP(HESHE(pl))+
           " plummets directly into a thorny bush",
	   "wipe the sweat from your forehead and grin happily"}));
	}
}
