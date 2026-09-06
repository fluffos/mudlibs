/*
** A leather armour
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/npc/human.c
*/

#include <combat.h>                          // armourtypes
#include <properties.h>                      // sizes

inherit "/std/armour";

void create()
{
  ::create();
  SetStandard(AT_MAIL,2,PSIZE_NORMAL);
    // every armour should be initialized by a call to SetStandard. The
    //   parameters given are the armourtype, armourclass, and the size
    //   of the armour, in this case a body armour of normal size (e.g.
    //   for humans or elves) with an AC of 2. SetStandard automatically
    //   sets the armour's short and long description, id, value and
    //   weight. In case of shields it also sets a number of hands needed
    //   to wear it.

  SetShort("a leather armour");
  SetLong("This is a simple armour made of leather.\n");
  AddId("leather armour");
  AddAdjective("simple");
    // after initializing the armour with SetStandard we give it an
    //   individual description and an extra id and adjective.
}

// That's all there is to it.

