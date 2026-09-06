/*
** A cross to scare vampires with
**
** Author: Thragor@Nightfall, 24jan97
** Update:
*/

#include <magic.h>
#include <combat.h>
#include <config.h>
#include <secure/wizlevels.h>
#include <search.h>

#define TP this_player()

inherit "/std/thing";

public void create()
{
  (::create());
  SetShort("a silver cross");
  SetLong("This cross is rather old. It's already black at many places. "
	  "It is said, that you can scare vampires with crosses although "
	  "you heard that it depends if the vampire still believes in god. "
	  "An emerald is in the middle of the cross and seems to emit some "
	  "green light.\n");
  SetIds(({"symbol","cross"}));
  SetAds(({"holy","silver"}));
  SetLight(5);
  SetMagic("The emerald in the middle of the cross got blessed by a god "
	   "as it seems.\n");
  SetInfo("The emerald in the middle of the cross seems to be magic.\n");
  SetWeight(250);
  SetValue(100);
}

public void init()
{
  (::init());
  add_action("cmd_scare","scare");
}

public int cmd_scare(string str)
{
  object vic;
  if (!TP||!str)
    return notify_fail("Whom do you want to scare with this cross?\n",
		       NOTIFY_NOT_OBJ),0;
  if (TP->CantSee())
    return notify_fail("You can't see your victim.\n",
		       NOTIFY_NOT_VALID),0;
  if (!vic = search(TP,str,SM_OBJECT|SEARCH_ENV))
    return notify_fail(capitalize(str)+" is not here.\n",
		       NOTIFY_NOT_VALID),0;
  if (!living(vic))
    return notify_fail(capitalize(vic->QueryShort())+" can't be scared.\n",
		       NOTIFY_NOT_VALID),0;
  if (strstr(vic->QueryRace()||"","vampire")==-1)
    return notify_fail("As "+vic->QueryName()+" is no vampire "+
		       vic->QueryPronoun()+" can't be scared with a cross.\n",
		       NOTIFY_NOT_VALID),0;
  if (IS_IMMORTAL(vic))
    return notify_fail(capitalize(vic->QueryName())+" pats you on the head.\n",
		       NOTIFY_NOT_VALID),0;
  write("You show the cross to "+vic->QueryName()+".\n");
  tell_object(vic,capitalize(TP->QueryName())+" shows a cross to you.\n");
  show(capitalize(TP->QueryName())+" shows a cross to "+
       vic->QueryName()+".\n",vic);
  if (   vic->Resistance(ST_PSYCHO)>50
      || (   sizeof(vic->QueryDefences())>=DT_PSYCHO
	  && vic->QueryDefences()[DT_PSYCHO]>50
         )
     )
    {
      show_room(environment(TP),capitalize(vic->QueryName())+
		" seems to take no notice of the cross.\n",({vic}));
      tell_object(vic,"Nice cross, isn't it? It's of pure silver.\n");
      return 1;
    }
  show_room(environment(TP),capitalize(vic->QueryName())+" looks scared.\n",
	    ({vic}));
  tell_object(vic,"You are scared and your legs try to run away with you.\n");
  vic->GoAway();
  return 1;
}
