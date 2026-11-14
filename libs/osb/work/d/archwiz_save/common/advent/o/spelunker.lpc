/* Advent - Spelunker Today -- Mateese, 23-Aug-96
 *
 * The 'Spelunker Today' magazine in Anteroom.
 * When dropped in Witt's End, the player is awarded 100 XP.
 */

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <search.h>
#include "advent.h"

inherit "/std/thing";
inherit ADVENT("i/advlib");

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "an issue of 'Spelunker Today'");
  Set(P_LONG, "A recent issue of the 'Spelunker Today' magazine.\n");
  Set(P_READ_MSG, "Unfortunately it's written in some obscure dwarvish.\n");
  Set(P_WEIGHT, 500);
  Set(P_VALUE, 10);
  AddId(({"spelunker", "spelunker today", "issue", "magazine"}));
  AddAdjective(({"issue", "of" }));
}

/*-----------------------------------------------------------------------*/
public int move (mixed dest, int method, mixed extra)
{
  int rc;
  rc = ::move(dest, method, extra);
  if (this_player() && ME_OK == rc && M_DROP == method
   && to_string(environment(this_object())) == ADVENT("r/wittsend")
     )
    this_player()->RegisterCmdFun("DroppedMag");
  return rc;
}

/*-----------------------------------------------------------------------*/
public void DroppedMag (int dummyarg, int goterror)
{
  if (goterror)
    return;
  if (!QueryFlag(F_WITSEND, this_player()))
  {
    write("You are really at wit's end.\n");
    this_player()->AddXP(100);
    SetFlag(F_WITSEND, this_player());
  }
}

/*************************************************************************/
