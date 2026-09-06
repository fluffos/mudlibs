/*
   This is the new object which will be moved to the player
   if he eats something of the McDonalds. It only appears
   once, as it is checked if the object allready exists.
*/

inherit "/std/thing";
#include <properties.h>
#define PL this_player()

mixed *actions;
int maxmsg;
int sicklevel;

create()
{
    if(::create()) return 0;

    Set(P_IDS,({"uebelkeit"}));

    /* patched by Sique */
    SetShort(0);
    /* end of patch */
    actions=allocate(5);

    actions[0]=({"You feel lightly sick, it should be over very soon...\n",
	       "You feel not so good, your stomach still rumbles...\n",
	       "You feel really sick, but not too much...\n",
	       "You feel damned sick, right before pucking...\n",
	       "You feel so sick that you hardly can move...\n",
	       "You feel like dying. You puke all over and over...\n"});


    actions[1]=({0,
		 0,
		 0,
		 0,
		 1,
		 2});

    sicklevel=0;
    maxmsg=sizeof(actions[0]);
}


SetSickLevel(wert) {return (sicklevel = wert);}
AddSickLevel(wert) {return (sicklevel = sicklevel + wert);}
QuerySickLevel() {return sicklevel;}

sick_msg()
{
    int index;
    int plhp;

    if (!PL)
    {
      remove();
      return;
    }

    if(sicklevel<0)
    {
	write("You have recovered from your Mc sickness. You feel good again.\n");
	this_object()->remove();
	return 1;
    }

    index=sicklevel/(PL->QueryCon()+5);

    if(index>=maxmsg)
	index=maxmsg-1;

    write(actions[0][index]);

    sicklevel = sicklevel - (PL->QueryCon()/3) - 1;

    if(actions[1][index]>0)
	write("You even loose hitpoints, so bad do you feel!!!\n");

    plhp=PL->QueryHP() - actions[1][index];

    if(plhp<1)
        plhp = 1;

    PL->SetHP(plhp);

    call_out("sick_msg",20);
    return 1;
}
