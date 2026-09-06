/* obj/race/darkelf
*/

#include <races.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <stdrooms.h>

inherit RACEOBJ;

/*-------------------------------------------------------------------------*/

public void create()
{
  (::create());
  SetAlign(-200); /* Dark-Elves are NOT nice */
  SetFood(100);
  SetDrink(100);
  SetAlc(100); /* Didn't know what else to set here. */
  SetWeight(60000); /* Not as heavy as light-elves */
  SetSize(PSIZE_NORMAL);
  SetDef(1);
  AddHand("right hand", 1);
  SetHome(STARTROOM);
  AddHand("left hand", 1); /* Dark-Elves have two hands */
  AddAttr("MagicDefence",30);
  AddStat(A_CON,-4); /* Elves have bad constitution */
  AddStat(A_DEX,4); /* more dexterity than elves */
  AddStat(A_INT,3); /* but not as intelligent as light elves */
  AddStat(A_STR,-3); /* but not strong */
  AddStat(A_IVISION, -(2*MAX_SUNBRIGHT));  /* can see in the darkness */
  AddStat(A_UVISION, ND_REL_STATE(ND_LATE_MORNING, MAX_SUNBRIGHT));
  SetPlural("darkelves");
  SetPlural("darkelves");
  SetLong(
    "@@Pl_Name@@ is a dark-elf. @@Pl_Poss@@ skin is deadly pale. \n");
  SetDesc("The Dark-Elves are close relatives to the Elves who in ancient"
  "times were persecuted by the latter since they worshipped evil. They found "
  "refuge from their persecutors in caves, in the darkness of which they could "
  "continue to worship the evil powers. Subsequently their appearance "
  "changed:  While they are as slender as the elves, they are smaller, and "
  "their skin is pale like chalk. Since their Goddess does not encourage "
  "independent thinking, they are not born as intelligent as their "
  "light-elven relatives, but their dexterity is better developed than "
  "theirs. They are usually dark-haired, and they have red eyes which enable "
  "them to see in the dark, but which are over-sensitive to light.\n");
  AddEquipment("sunglasses", "/obj/sunglasses", 0, 0, ({ "glasses" }));
}

/***************************************************************************/
