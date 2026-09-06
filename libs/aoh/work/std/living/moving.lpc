/*--------------------------------------------------------------------------
** std/living/moving.c
**
** The basic moving and removing mechanism for livings.
** A moving for players and advanced npcs should add a verbose move().
**
** 28-Oct-93 [Mateese]
**--------------------------------------------------------------------------
*/

#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <lock.h>
#include <living.h>

inherit "/std/thing/moving";

#define THIS  this_object()
#define TP    this_player()
#define ENV   environment

public mixed Query(string name);           // std/base
public int QueryStunned();                 // std/living/actions
#ifdef USE_HBHOOK
mixed SetHBHook(mixed data);               // std/living/heart
mixed QueryHBHook();                       // std/living/heart
#endif

//--------------------------------------------------------------------------

private nosave string lastexit;
private nosave int lastenvc;
private nosave int aGoChance;
private nosave int wimpy_move;
private nosave int aAllowedRegions;

//--------------------------------------------------------------------------

public int QueryAllowedRegions() { return aAllowedRegions; }
public int SetAllowedRegions(int a) { return aAllowedRegions = a; }

//--------------------------------------------------------------------------

public varargs int GoAway (int wimpygo) {
  mixed map;
  string *exits;
  int i, s, t;
  object door, lastenv;

  exits = ({});
  if (lastenv = ENV())
    map = ({mixed})ENV()->QueryExitsDest();
  if (!map)
    return 0;

  exits = m_indices(map);

  wimpy_move = wimpygo;

  if (   lastexit
      && member(exits, lastexit) >= 0
      && random(7) < (5-lastenvc)
      && command(lastexit)
     )
   {
    if (ENV() == lastenv)
      lastenvc++;
    else
      lastenvc = 0;
    return 1;
   }

  map = ({mixed})ENV()->QueryExitsData();
  s = sizeof(exits);
  for (i = random(s), t = s; t--; i = (i + 1) % s)
  {
    mixed eobj, ehidden, echeck, extra;
    if (    sizeof(map)
         && m_contains(&eobj, &door, &ehidden, &echeck, &extra, map, exits[i])
         && door && ({int})door->Query(P_LOCKSTATE) != LOCK_OPEN
       )
        continue;
    if (command(exits[i]))
    {
      lastexit = exits[i];
      if (ENV() == lastenv)
        lastenvc++;
      else
        lastenvc = 0;
      return 1;
    }
  }

  lastexit = 0;
  lastenvc = 0;
  return 0;
}

//--------------------------------------------------------------------------

public void Wimpy() {
  int stun;
  if (stun = QueryStunned()) {
    if (random(100) > 30+stun*10)
    {
      tell_object(THIS, "You can't escape ...\n");
      return;
    }
    tell_object(THIS, "Unconsciously you move your feet ...\n");
  }
  else
    tell_object (THIS, "Your feet try to run away with you ...\n");
  if (!GoAway(1)) tell_object (THIS, "... but they find no exit.\n");
}

//--------------------------------------------------------------------------
public void OneStep(int justSched)

// If it's time, go one step and restart call_out.

{
  int delay;

  while (remove_call_out("OneStep") != -1);
  if (!aGoChance)
    return;
  if (aGoChance && !justSched)
    GoAway();
  delay = random(10000/aGoChance) + 2;
  call_out("OneStep", delay, 0);
}

//--------------------------------------------------------------------------

public int QueryGoChance () { return aGoChance; }
public int SetGoChance (int i) {
  aGoChance = i;
  OneStep(1);
  return aGoChance;
}

//--------------------------------------------------------------------------

// Tell the living that it entered the room (some NPCs might fubarily
// depend on this).

public varargs int move(mixed dest, int method, mixed extra) {
  int err;
#ifdef USE_HBHOOK
  mixed hook;
#endif

  if (   !wimpy_move && QueryStunned() && THIS == TP
      && (method == M_TELEPORT || method == M_GO))
    return ME_NO_LEAVE;

#ifdef USE_HBHOOK
  hook = QueryHBHook(); SetHBHook(0);
#endif

  if (!objectp(dest))
      dest = load_object(dest);

  err = Query(P_ALLOWED_REGIONS);
  if (method != M_NOCHECK && err && !(err & ({int})dest->Query(P_REGION)))
      return ME_NO_ENTER;

  wimpy_move  = 0;
  err = moving::move(dest, method, extra);

  if(ME_OK != err) {
    if(err == ME_TOO_HEAVY)
      tell_object(THIS, "Sorry, but you are too heavy to enter the room.\n");
#ifdef USE_HBHOOK
    if (hook) SetHBHook(hook);
#endif
    return err;
  }

  switch(method) {
  case M_SPECIAL:
  case M_TELEPORT:
    if(pointerp(extra) && sizeof(extra) > 2) extra = extra[2];
    if (stringp(extra))
      tell_object(THIS, "You " + extra +".\n");
  case M_GO:
    THIS->LookAfterMove(method, extra);
  }
  return ME_OK;
}

//--------------------------------------------------------------------------

public varargs int remove () {
  if (interactive()) tell_object(THIS, "Good bye! Come back soon!\n");
  destruct (THIS);
  return 1;
}

/****************************************************************************/
