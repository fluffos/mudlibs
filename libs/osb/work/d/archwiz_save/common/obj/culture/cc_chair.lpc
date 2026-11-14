/*
** The Chair of Steven Spielberg
** Author: Thragor@Nightfall, 04apr97
** Update:
** Cloned by: /d/archwiz/common/room/culture/movieroom
*/

#include <search.h>
#include <config.h>
#include <properties.h>

#define P_SIT "ChairSit"
#define P_FOLD "ChairFolded"

#define TP this_player()
#define ME this_object()

inherit "/std/thing";

private void TestSit()
{
  object pl;
  if (   (pl = Query(P_SIT))
      && environment(pl)!=environment()
     )
    Set(P_SIT,0);
}

public string QueryLong()
{
  string res;
  object pl;
  TestSit();
  if (Query(P_FOLD))
    return ("This is a folded chair like Steven Spielberg use it.\n"
	    "The frame is made of black iron and the seat is made "
	    "of flax. There's something written on the back of the "
	    "chair.\n");
  res = ("This is a folding chair like Steven Spielberg use it.\n"
	 "The frame is made of black iron and the seat is made "
	 "of flax. There's something written on the back of the "
	 "chair.\n");
  if (pl = Query(P_SIT))
    {
      if (pl==TP)
	res+=("It's very comfortable to sit on this chair.\n");
      else if (pl->QueryInvis())
	res+=("Someone seems to sit on the chair but you can't "
	      "see anyone.\n");
      else
	res+=(capitalize(pl->QueryName())+" sits on the chair.\n");
    }
  else
    res+="Perhaps you could sit down on the chair.\n";
  return res;
}

public void create()
{
  (::create());
  SetShort("a folding chair");
  Set(P_FOLD,0);
  SetHelpMsg("You can\n"
	     "- take a seat\n"
	     "- stand up\n"
	     "- fold chair\n"
	     "- unfold chair\n");
  AddId(({"chair","chair of steven spielberg"}));
  AddAdjective(({"folded","folding"}));
  SetWeight(1000);
  SetValue(43);
  AddSubDetail("frame","It is made of black iron.\n");
  AddSubDetail(({"black iron","iron"}),"The chair is made of it.\n");
  AddSubDetail("seat","It's made of flax. You may take a seat.\n");
  AddSubDetail("back","There's something writton on it.\n");
  AddSubReadMsg("back","STEVEN SPIELBERG\n");
  SetInfo("This is the chair of Steven SPielberg.\n");
}

public void init()
{
  (::init());
  if (Query(P_SIT)==TP)
    Set(P_SIT,0);
  add_action("cmd_sit","sit");
  add_action("cmd_take","take");
  add_action("cmd_fold","fold");
  add_action("cmd_unfold","unfold");
  add_action("cmd_stand","stand");
  add_action("cmd_leave","leave");
}

public string QueryNoGet()
{
  if (!Query(P_FOLD))
    return ("You should fold the chair first. Otherwise it would take "
	    "too much space in your backpack.\n");
  return 0;
}

private int stand_up()
{
  if (Query(P_SIT)!=TP)
    return notify_fail("You're not sitting on the chair.\n",
		       NOTIFY_NOT_VALID),0;
  write("You stand up.\n");
  if (TP->QueryInvis())
    show("The chair inside here changed somehow.\n");
  else
    show(capitalize(TP->QueryName())+" stands up from the chair.\n");
  Set(P_SIT,0);
  return 1;
}

public int cmd_stand(string str)
{
  if (!str || !TP)
    return notify_fail("Stand up?\n",NOTIFY_NOT_OBJ),0;
  if (!sizeof(regexp(({lower_case(str)}),"\\<up\\>")))
    return notify_fail("Stand up?\n",NOTIFY_NOT_OBJ),0;
  return stand_up();
}

public int cmd_leave(string str)
{
  if (!str || !TP)
    return notify_fail("Leave what?\n",NOTIFY_NOT_OBJ),0;
  if (ME != search(TP,str,SEARCH_ENV_INV|SM_OBJECT|SM_IGNLIGHT))
    return notify_fail("You can't leave that.\n",
		       NOTIFY_NOT_OBJ),0;
  return stand_up();
}

private status check_sight(object pl)
{
  int cantsee;
  if (!pl) return 0;
  if (pl->Query(P_BLIND))
    return notify_fail("You're blind. You can't see it.\n",
		       NOTIFY_NOT_VALID),0;
  if (!cantsee = pl->CantSee())
    return 1;
  if (cantsee<0)
    return notify_fail("It's too dark. You can't see it.\n",
		       NOTIFY_NOT_VALID),0;
  return notify_fail("It's too bright. You can't see it.\n",
		     NOTIFY_NOT_VALID),0;
}

public int cmd_fold(string str)
{
  if (!TP || !str)
    return notify_fail("What do you want to fold?\n",
		       NOTIFY_NOT_OBJ),0;
  if (!check_sight(TP)) return 0;
  if (ME != search(TP,str,SEARCH_ENV_INV|SM_OBJECT))
    return notify_fail("You can't fold "+str+".\n",
		       NOTIFY_NOT_OBJ),0;
  if (Query(P_FOLD))
    return notify_fail("The chair is already folded.\n",
		       NOTIFY_NOT_VALID),0;
  write("You fold the chair.\n");
  if (TP->QueryInvis())
    show("The chair folds itself.\n");
  else
    show(capitalize(TP->QueryName())+" folds the chair.\n");
  Set(P_FOLD,1);
  return 1;
}

public int cmd_unfold(string str)
{
  if (!TP || !str)
    return notify_fail("What do you want to unfold?\n",
		       NOTIFY_NOT_OBJ),0;
  if (!check_sight(TP)) return 0;
  if (ME != search(TP,str,SEARCH_ENV_INV|SM_OBJECT))
    return notify_fail("You can't unfold "+str+".\n",
		       NOTIFY_NOT_OBJ),0;
  if (!Query(P_FOLD))
    return notify_fail("The chair is already unfolded.\n",
		       NOTIFY_NOT_VALID),0;
  if (environment(TP)!=environment())
    return notify_fail("You can unfold the chair only when it is "
		       "lying in front of you.\n",
		       NOTIFY_NOT_VALID),0;
  write("You unfold the chair.\n");
  if (TP->QueryInvis())
    show("The chair unfolds itself.\n");
  else
    show(capitalize(TP->QueryName())+" unfolds the chair.\n");
  Set(P_FOLD,0);
  return 1;
}

private int sit_down()
{
  object opl;
  TestSit();
  opl = Query(P_SIT);
  if (opl==TP||!TP)
    return notify_fail("You are already sitting on the chair.\n",
		       NOTIFY_NOT_VALID),0;
  if (!check_sight(TP)) return 0;
  if (opl)
    return notify_fail("There is already someone sitting on the "
		       "chair.\n",NOTIFY_NOT_VALID),0;
  if (environment(TP)!=environment())
    return notify_fail("The chair has to stand in front of you before "
		       "you can take a seat.\n",
		       NOTIFY_NOT_VALID),0;
  if (Query(P_FOLD))
    return notify_fail("The chair is folded. You have to unfold it first "
		       "before you can sit down on it.\n",
		       NOTIFY_NOT_VALID),0;
  Set(P_SIT,TP);
  write("You sit down on the chair. You feel like Steven Spielberg.\n");
  if (TP->QueryInvis())
    show("The chair somehow looks different.\n");
  else
    show(capitalize(TP->QueryName())+" takes a seat on a chair.\n");
  return 1;
}

public int cmd_take(string str)
{
  if (!TP || !str) return 0;
  if (!sizeof(regexp(({lower_case(str)}),"\\<seat\\>")))
    return 0;
  return sit_down();
}

public int cmd_sit(string str)
{
  if (!TP || !str)
    return notify_fail("Where do you want to sit on?\n",
		       NOTIFY_NOT_OBJ),0;
  if (!sizeof(regexp(({lower_case(str)}),("(\\<down\\>)|"
					  "(\\<on\\>.*\\<chair\\>)"))))
    return notify_fail("Where do you want to sit on?\n",
		       NOTIFY_NOT_OBJ),0;
  return sit_down();
}
