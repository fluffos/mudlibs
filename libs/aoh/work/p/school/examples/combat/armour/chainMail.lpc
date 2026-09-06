/*
** A chain mail
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/npc/orc.c
*/

#include <properties.h>
#include <combat.h>

inherit "/std/armour";

void create()
{
  ::create();
  SetStandard(AT_MAIL,3,PSIZE_NORMAL);
  SetShort("a chain mail");
  SetLong("This is a chain mail. It offers good protection against "
    "slashing and bludgeoning weapons but lousy protection against "
    "piercing attacks.\n");
  AddId(({"mail","chain mail"}));
  SetDefence(DT_PIERCE,-2);
    // using SetDefence, you may add an offset to the protection offered by
    //   this armour against a certain damagetype. In this case, the chain
    //   mail protects with an AC of 3-2=1 agains piercing attacks (by
    //   knives, spears etc.) but with an AC of 3 against all other damage
    //   types. You may set defences for as many damagetypes as you want,
    //   but try not to set too many different defences, they'd only work
    //   to confuse the player.

    // Note: Both the average of all defences and the average of all
    //       conventional defences (DT_SLASH, DT_PIERCE and
    //       DT_BLUDGEON) have to be 0 or negative. Armours that don't
    //       meet this rule may not be brought into play unless approved
    //       by the department of defence.
}
