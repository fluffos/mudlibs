/*---------------------------------------------------------------------------
** obj/weapon/longsword
**
** Standard longsword.
** TODO: Modify the values in Setup() approbiately
**
** 15-Jan-1994  [Mateese]
**---------------------------------------------------------------------------
*/

#include "/neu/sys/combat.h"

inherit "/neu/obj/weapon";

//---------------------------------------------------------------------------
public void SetUp (int class)

// Setup the longsword.

{
  SetType(CS_SWORD, class);
  SetShort("a longsword");
  SetLong("An ordinary longsword.\n");
  AddId("longsword");
}

//---------------------------------------------------------------------------

public void create() {
  ::create();
  SetMinClass(30/CLASS_SCALE);  // == SetMinClass(6);
  SetMaxClass(60/CLASS_SCALE);  // == SetMaxClass(12);
  SetUp(50/CLASS_SCALE);        // == SetUp(10);
}

/***************************************************************************/
