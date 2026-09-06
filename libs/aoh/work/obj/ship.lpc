/*--------------------------------------------------------------------------
 *  /obj/ship.c --  Ship Object
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 *  Works with /room/port.
 *  The movement of the ship is done via call_outs, while the time to
 *  wait at a harbour is done via heart_beats; this way, lagging people
 *  at least a chance to enter the ship.
 */

inherit "/obj/lib/ship";
inherit "/std/thing";

public varargs int clean_up(int refcount)
{
  if (!can_clean_up()) return 1;
  return (thing::clean_up(refcount));
}

public void create()
{
  blueprint()->RegisterMe();
  (::create());
  SetShort("a ship");
  SetLong("A seafaring vessel to sail the high seas.\n");
  SetIds(({"ship","boat"}));
  SetNoGet("Not a chance.\n");
  "/obj/lib/register"->Register(this_object(),"SHIP");
  if (!clonep()) return;
  set_heart_beat(1); // when created it will first wait in the harbour
}

public void init()
{
  (::init());
  add_action("cmd_enter","enter"); // enter the ship
  add_action("cmd_enter","board");
}
