/*---------------------------------------------------------------------------
** obj/armour/platemail
**
** A heavy-duty platemail.
** TODO: Modify the values in Setup() approbiately.
**
** 27-Oct-1994  [Mateese]
**---------------------------------------------------------------------------
*/

#include "/neu/sys/combat.h"

inherit "/neu/obj/armour";

//---------------------------------------------------------------------------
public void SetUp (int class)

// Setup the mail. It is heavier and more valuable than a normal mail,
// but also allows greater class settings.

{
  SetType(AT_MAIL, class);
  SetValue(2*QueryValue());
  SetWeight(2*QueryWeight());
  SetShort("a heavy platemail");
  SetLong("A heavy platemail.\n");
  AddId("platemail");
}

//---------------------------------------------------------------------------

public void create() {
  ::create();
  SetMinClass(30/CLASS_SCALE);
  SetMaxClass(60/CLASS_SCALE);
  SetUp(50/CLASS_SCALE);
}

/***************************************************************************/
