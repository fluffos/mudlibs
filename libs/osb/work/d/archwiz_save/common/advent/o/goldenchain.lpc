/* Advent - Golden Chain -- Mateese, 28-Aug-96
 *
 * The Golden Chain used to chain the Cave Bear in the Barren Room.
 * To unlock it, one needs the Set of Keys from the Subterranean Well.
 * Furthermore, the bear must be tamed first by feeding it.
 * If the chain is opend, the lfun ChainOpen() is called in the bear.
 */

#include <config.h>
#include <properties.h>
#include <lock.h>
#include "advent.h"

inherit "/std/lock";
inherit ADVENT("o/treasure");

/*-----------------------------------------------------------------------*/
public int CheckLockstate()

/* Check and update the lockstate depending on whether the bear
 * is here or not.
 */

{
  int state;
    
  state = Query(P_LOCKSTATE);
  if (LOCK_LOCKED != state 
   || !environment(this_object())
   || this_object() != present(ADV_CHAIN, environment(this_object()))
     )
    return state;
  if (!present(ADV_BEAR, environment(this_object())))
  {
    state = LOCK_OPEN;
    Set(P_LOCKSTATE, state);
  }
  return state;
}

/*-----------------------------------------------------------------------*/
/* Modify the (already modified) description with the lock description.
 */

public varargs string InvShort(string what)
{
  return ModifyInvShort(::InvShort(what));
}

public string LongExtra()
{
  string msg;
  int state;
  state = CheckLockstate();
  if (LOCK_OPEN != state)
    msg = "It holds back the bear";
  else
    msg = "It is quite heavy"; 
      /* "It lies in coils on the ground" doesn't fit always. */
  if (IsTreasure(this_player()))
    msg += " and ";
  else
    msg += ".\n";
  return msg+ModifyLong(lower_case(::LongExtra()));
}

public string QueryNoGet()
{
  int state;
  object tamer;
  string adj;
    
  state = CheckLockstate();
  adj = "ferocious";
  if (environment(this_object()))
  {
    tamer = present(ADV_BEAR, environment(this_object()));
    if (tamer && tamer->Query(P_TAMER))
      adj = "friendly";
  }
    
  if (LOCK_LOCKED == state)
    return "The chain is locked to the "+adj+" bear.\n";
  if (LOCK_CLOSED == state)
    return "The chain is bound to the "+adj+" bear.\n";
  return ::QueryNoGet();
}

/*-----------------------------------------------------------------------*/
public void create()
{
  "treasure"::create();
  "lock"::create();

  Set(P_SHORT, "a golden chain");
  Set(P_LONG, "A solid golden chain, strong enough to bind a bear.\n");
  Set(P_WEIGHT, 5000);
  Set(P_VALUE, 2000);
  Set(P_LOCKSTATE, LOCK_LOCKED);
  Set(P_PICK_CHANCE, 20);
  Set(P_KEYIDS, ({ "key", "keyring", "keys" }));
  Set(P_KEYCODE, ADV_GRATE_KEYCODE);
  AddId(({ "chain", ADV_CHAIN }));
  AddAdjective(({"golden", "solid" }));
  Set(P_TREASURE, F_CHAIN);
  Set(P_XP, 1600);
  Set(ADV_CHAIN, 1);
}

/*-----------------------------------------------------------------------*/
public void Aloha (int flags)

/* Lock the chain on every reset if the bear is in the vicinity.
 */

{
  Set(P_LOCKSTATE, LOCK_LOCKED);
  CheckLockstate();
}

/*-----------------------------------------------------------------------*/
public void IsLockOpen (object bear, int goterror)

/* The lock might have been opened. If yes, free the bear.
 */

{
  if (!goterror && bear && LOCK_OPEN == Query(P_LOCKSTATE))
    bear->ChainOpen();
}

/*-----------------------------------------------------------------------*/
public mixed DoActionFor (int action, int type, object *keys, int kix)

/* Intercept the manipulations on the lock and disable them according
 * to the state of the bear.
 */

{
  object bear, tamer;
  int prime, rc;
    
  if (environment(this_object()))
  {
    bear = present(ADV_BEAR, environment(this_object()));
    if (bear)
      tamer = bear->Query(P_TAMER);
  }
      
  if (type == LOCK_ACT_LOCK || type == LOCK_ACT_OPEN)
  {
    switch (action)
    {
      case LOCK_DO_CLOSE:
	write("The chain can't be closed anymore.\n");
	return 1;
      case LOCK_DO_LOCK:
	write("The chain can't be locked anymore.\n");
	return 1;
      case LOCK_DO_OPEN:
	if (bear && tamer != this_player())
        {
	  write("The bear doesn't let you get near the chain.\n");
	  return 1;
        }
        if (bear && tamer)
	  this_player()->RegisterCmdFun("IsLockOpen", bear);
        break;
      case LOCK_DO_UNLOCK:
	if (bear && bear->Query(P_TAMER) != this_player())
        {
	  write("The bear doesn't let you get near the chain.\n");
	  return 1;
        }
        break;
    }
  }
  return ::DoActionFor(action, type, keys, kix);
}

/*************************************************************************/
