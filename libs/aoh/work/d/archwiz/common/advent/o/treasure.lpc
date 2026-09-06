/* Advent - Standard Treasure -- Mateese, 04-Aug-96
 *
 * The standard treasure object. It extends the /std/thing by functions
 * which check if this object is a treasure for the player or not.
 * Each treasure deposited will award the player with P_XP experience
 * points.
 * TODO: Add Id 'treasure' if it is a treasure? Will be expensive, though.
 */

#include <config.h>
#include <properties.h>
#include <rooms.h>
#include "advent.h"

inherit "/std/thing";
inherit ADVENT("i/advlib");

/*-----------------------------------------------------------------------*/
public object QueryOwner()

/* Return the current owner of the treasure, or 0 if there is none.
 */

{
  object env;
  
  env = this_object();
  while (env = environment(env))
    if (env->Query(P_IS_PLAYER))
      return env;
  return 0;
}

/*-----------------------------------------------------------------------*/
public varargs int IsTreasure (object player, int nocheck)

/* Return TRUE if this object is a treasure for <player>.
 * If <player> is not given, the treasure's owner is taken.
 */

{
  object *inv;
  int i, myflag;
    
  myflag = Query(P_TREASURE);

  if (!player)
    player = QueryOwner();
  if (!player || QueryFlag(myflag, player))
    return 0;

  /* Make sure this object is the first treasure of it's kind for the player. 
   */
  if (!nocheck)
  {
    inv = deep_inventory(player);
    for (i = 0; i < sizeof(inv); i++)
      if (inv[i]->Query(P_TREASURE) == myflag)
        return inv[i] == this_object();
  }
  return 1;
}

/*-----------------------------------------------------------------------*/
/* Extension of the description if the object is a treasure for the
 * viewer.
 */

public varargs string InvShort(string what)
{
  string sh;
  sh = ::InvShort(what);
  if (!what && sh && strlen(sh) && IsTreasure(this_player()))
    return sh+"!";
  return sh;
}

public string LongExtra()
{
  if (IsTreasure(this_player()))
    return "It's quite a treasure.\n";
  return "";
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a default treasure");
  Set(P_LONG, "This is a wanna-be treasure for Advent.\n");
  
  SetExtraEntry("treasure extra long", P_LONG, #'LongExtra);
 
  Set(P_TREASURE, F_NONE);
  Set(P_XP, 1400);
}

/*************************************************************************/
