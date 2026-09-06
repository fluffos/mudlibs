/* Advent - Black Rod -- Mateese, 15-Aug-96
 *
 * Does anybody notice that it looks like the archetypical fairy staff?
 * The black rod to create the crystal bridge over the fissure (r/westfissure,
 * r/eastfissure). It is found in the Debris Room (r/debrisroom).
 */

#include <config.h>
#include <properties.h>
#include <search.h>
#include "advent.h"

inherit "/std/thing";

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a black rod");
  Set(P_LONG, 
"It is a three foot black rod with a rusty star on an end.\n"
     );
  Set(P_HELP_MSG, "Use your fantasy...\n");
  Set(P_VALUE, 50);
  Set(P_WEIGHT, 1500);
  Set(ADV_BLACKROD, 1);
  AddId(({ "rod", ADV_BLACKROD }));
  AddAdjective("black", "wicker");
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  add_action("fwave", "wave");
}

/*-----------------------------------------------------------------------*/
public int fwave (string arg)

/* Wave the rod to create/remove the crystal bridge.
 */

{
  object obj;
  string msg;
    
  notify_fail("Wave what?\n", NOTIFY_NOT_CMD);
  if (!arg || wsearch_inv(arg) != this_object())
    return 0;

  /* Only rooms which react on waving the rod have a function WaveRod(),
   * all others will return 0.
   */
  show(this_player()->QueryName()+" waves "+Short()+".\n");
  if (!environment(this_player())->WaveRod())
    write("Nothing happens.\n");

  return 1;
}

/*************************************************************************/
