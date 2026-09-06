/*---------------------------------------------------------------------------
** obj/armour/combatboots
**
** Standard combat boots.
** TODO: Modify the values in Setup() approbiately.
**
** 15-Jan-1994  [Mateese]
**---------------------------------------------------------------------------
*/

#include "/neu/sys/combat.h"

inherit "/neu/obj/armour";

//---------------------------------------------------------------------------
public void SetUp (int class)

// Setup the boots.

{
  SetType(AT_BOOTS, class);
  SetShort("a pair of combat boots");
  SetLong("A pair of combat boots.\n");
  AddAdjective("combat");
}

//---------------------------------------------------------------------------

public void create() {
  ::create();
  SetMaxClass(20/CLASS_SCALE); // == SetMaxClass(4);
  SetUp(10/CLASS_SCALE);       // == SetUp(2);
}

/***************************************************************************/
