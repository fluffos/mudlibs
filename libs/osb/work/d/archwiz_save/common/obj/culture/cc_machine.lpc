/*
** The Nightfall-Machine
** Item of the Culture Center Quest
** Author: Thragor@Nightfall, 03apr97
** Update:
** Cloned by: /d/archwiz/common/room/culture/culture
*/

#define TP this_player()
#define P_ON "MachineOn"
#define SF(x) #'x //'

#include <config.h>

inherit "/std/thing";

public void create()
{
  (::create());
  SetShort("a strange cube");
  SetLong("The cube looks somehow familiar to you. But it doesn't fit into "
	  "this world. Ah yes. Now you got it. It's a computer! The first "
	  "machine Nightfall ran on.\n"
	  "The cube is made entirely of white marble. Only a red button "
	  "looks somehow strange to you.\n");
  AddId(({"cube","machine","computer"}));
  AddAdjective("strange");
  AddSubDetail(({"button","red button"}),
	       "Buttons exist to be pressed, don't they?\n");
  SetInfo("The first machine Nightfall ran on was "
	  "taurus.tat.physik.uni-tuebingen.de.\n");
  SetMagic("A strange magic holds this thing-that-must-not-be in this "
	   "world.\n");
  SetValue(42);
  SetWeight(2000);
}

public string CCQuest()
{
  return "machine";
}

public void init()
{
  (::init());
  add_action("cmd_press","press");
}

public void do_hum()
{
  object pl;
  object env;
  while(remove_call_out(SF(do_hum))!=-1);
  if (!Query(P_ON) || !env = environment()) return;
  
  if (living(env))
    {
      pl = env;
      env = environment(pl);
    }
  if (pl)
    {
      tell_object(pl,"The cube hums.\n");
      if (pl->QueryInvis())
	tell_room(env,"You hear a soft humming from somewhere.\n",
		  ({pl}));
      else
	show_room(env,({"You hear a soft humming out of "+
			add_gen(pl->QueryName())+" backpack.\n",
			"You hear a soft humming from somewhere.\n"}),
		  ({pl}) );
    }
  else
    show_room(env,({"The cube inside here hums.\n",
		    "You hear a humming from somewhere.\n"}) );
  call_out(SF(do_hum),30+random(30));
}

public string QueryNoise()
{
  if (!Query(P_ON)) return 0;
  return "The cube hums.\n";
}

public int cmd_press(string str)
{
  if (   !TP
      || (str = lower_case(str||""))==""
      || !sizeof(regexp(({str}),"\\<button\\>"))
     )
    return notify_fail("Press what?\n",NOTIFY_NOT_OBJ),0;
  if (!sizeof(regexp(({str}),"(\\<machine\\>)|(\\<computer\\>)|"
                             "(\\<cube\\>)")))
    return notify_fail("Press the button on the cube?\n",
		       NOTIFY_NOT_VALID),0;
  if (Query(P_ON))
    return notify_fail("The cube is already activated and somehow you "
		       "can't stop it by pressing the button again.\n",
		       NOTIFY_NOT_VALID),0;
  write("You press the red button and suddenly the cube starts to hum.\n");
  if (TP->QueryInvis())
    if (environment()!=TP)
      show(({"Suddenly the strange cube starts to hum.\n",
	     "Suddenly you hear a strange humming sound.\n"}) );
    else
      say("Suddenly you hear a strange humming sound.\n");
  else
    if (environment()!=TP)
      show(({capitalize(TP->QueryName())+" presses a button at the strange "
	     "cube and suddenly it starts to hum.\n",
	     "Suddenly you hear a strange humming sound.\n"
	   })
	  );
    else
      show(({capitalize(TP->QueryName())+" does something with "+
	     TP->QueryPossessive()+" backpack and suddenly you hear "
	     "a strange humming sound.\n",
	     "Suddenly you hear a strange humming sound.\n"}));
  Set(P_ON,1);
  environment(TP)->CheckQuest(TP);
  call_out(SF(do_hum),30+random(30));
  return 1;
}

public void reset()
{
  if (Query(P_ON) && environment())
    {
      if (living(environment()))
	{
	  tell_object(environment(),
		      "Suddenly the cube stops to hum.\n");
	  if (environment(environment()))
	    tell_room(environment(environment()),
		      "The humming sound stops.\n",({environment()}));
	}
      else
	show_room(environment(),
		  ({"The cube stops to hum.\n",
		    "The humming sound stops.\n"}) );
    }
  Set(P_ON,0);
}

public int remove()
{
  while(remove_call_out(SF(do_hum))!=-1);
  return (::remove());
}
