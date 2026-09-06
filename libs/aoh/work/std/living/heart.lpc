/*--------------------------------------------------------------------------
 * std/living/heart.c
 *
 * Copyright (C) 1994 by Nightfall.
 * Copyright (C) 1998 by One Step Beyond.
 * All Rights reserved. Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <driver/object_info.h>
#include <living.h>

#define NETDEAD (!this_object() || (!interactive(this_object()) && query_once_interactive(this_object())))

public void ValidizeHeart(); // forward

private mixed * pHooks;     // Registered heartbeat hooks */
private nosave int bHbFun;  // TRUE if there is a rogue heart_beat().
private int     pHeart;     // TRUE if the default 'heart' is on.

//--------------------------------------------------------------------------

public void create() {
  pHooks = ({});
  bHbFun = (__FILE__ != function_exists("heart_beat", this_object()));
  if (bHbFun && -1 != member(object_name(this_object()), '#'))
    pHeart = 1;
  else
    pHeart = 0;
}

//--------------------------------------------------------------------------

public int QueryHeart() { return pHeart; }
public int SetHeart (int value) {
  pHeart = bHbFun && value;
  if (pHeart)
    ValidizeHeart();
  return pHeart;
}

//--------------------------------------------------------------------------

public mixed * QueryHbHooks()           { return pHooks; }
public mixed * SetHbHooks(mixed * new)  {
  pHooks = new - ({ 0 });
  ValidizeHeart();
  return pHooks;
}

private int find_hook (mixed hook)
{
  int i;
  string s;

  if (stringp(hook))
    return member(pHooks, hook);
  s = to_string(hook);
  for (i = sizeof(pHooks); i--; )
    if (to_string(pHooks[i]) == s)
      return i;
  return -1;
}

public void AddHeart (mixed hook)
{
  if (!stringp(hook) && !closurep(hook))
    raise_error(sprintf("Illegal value %O to AddHbHook\n", hook));
  if (-1 == find_hook(hook))
    pHooks += ({ hook });
  ValidizeHeart();
}

public void RemoveHeart (mixed hook)
{
  int i;
  if (stringp(hook) || closurep(hook))
  {
    i = find_hook(hook);
    if (i != -1) {
      pHooks[i..i] = ({});
    }
  }

  if (!sizeof(pHooks) && !bHbFun)
    set_heart_beat(0);
}

public int CheckHeart (mixed hook)
{
  return -1 != find_hook(hook);
}

public void ValidizeHeart()
{
//  set_heart_beat(0);
  if ((sizeof(pHooks) || pHeart) && !NETDEAD)
    set_heart_beat(1);
}

//--------------------------------------------------------------------------

public void heart_beat()
{
  int i, rc;
  mixed * hooks;

  hooks = pHooks + ({});
  /* This copy of pHooks allows the hook functions to remove itself
   * without disturbing this call.
   */
  for (i = sizeof(hooks); i--; )
  {
    if (!hooks[i])
      continue;
    if (stringp(hooks[i]))
      rc = ({int})call_other(this_object(), hooks[i]);
    else
      // TODO: Possible security breach here.
      rc = funcall(hooks[i]);
    if (!rc)
      RemoveHeart(hooks[i]);
  }
  pHooks -= ({ 0 });

  if (!sizeof(pHooks) && !pHeart)
    set_heart_beat(0);
}

public int set_heart(int i) { return set_heart_beat(i); }

/*==========================================================================*/
