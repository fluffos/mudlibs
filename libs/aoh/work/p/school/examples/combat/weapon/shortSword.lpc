/*
** A short sword
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/npc/human.c
*/

#include <combat.h>                       // weapontypes and damagetypes
#include <properties.h>                   // sizes
#include <combat.h>

inherit "/std/weapon";

void create()
{
  ::create();
  SetStandard(WT_SWORD,5,PSIZE_NORMAL);
    // every weapon should be initialized by a call to SetStandard. The
    //   parameters given are the weapontype, the weaponclass and the
    //   size of the weapon, in this case a sword of normal size (e.g.
    //   for humans or elves) with a WC of 5. SetStandard automatically
    //   sets the weapon's short and long description, id, value, weight
    //   and the number of hands needed to wield it. The weapontype also
    //   sets the damagetype.

  SetShort("a short sword");
  SetLong("This is a short sword made of steel.\n");
  AddAdjective("short");
    // after initializing the sword with SetStandard, we give it an
    //   individual description and an extra adjective.
}

// That's all there is to it!
