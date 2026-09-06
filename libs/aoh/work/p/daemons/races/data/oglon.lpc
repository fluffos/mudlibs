/* obj/race/oglon
**
** The Oglons are based on a note in E.E.Smith's "Grey Lensmen", in which
** they are described as cat-shaped creatures, roughly the size of a lion,
** but with the wings and claws of an eagle. They are overly aggressive
** and hostile towards any other lifeform.
** As I introduced Oglons first in NF just to have an example race which is not
** of the boring elven/dwarf cliche, I have no deeper intentions with them.
** Do with them what you seem to fit. I just ask that you please follow
** the caracter outline given above and in the body description (see below).
**    [Mateese]
**
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

  SetAlign  (0);
  SetFood   (75);
  SetDrink  (75);
  SetAlc    (80);
  SetSize(PSIZE_NORMAL);
  SetWeight (50000);
  SetDef    (1);
  SetHome   (STARTROOM);
  AddHand   ("right hand", 3);
  AddHand   ("left hand", 3);
  AddAttr("MagicDefence",15);
  AddStat   (A_CON, -2);
  AddStat   (A_DEX,  3);
  AddStat   (A_INT,  1);
  AddStat   (A_STR, -2);
  AddStat   (A_IVISION, ND_REL_STATE(ND_NIGHT, MAX_SUNBRIGHT));
  AddStat   (A_UVISION, (5 * MAX_SUNBRIGHT) / 2);
  SetLong   ( 
 "@@Pl_Name@@ is an oglon. @@Pl_Poss@@ cat-shaped body is completely covered\n"
+"with tight fur. A pair of wings might provide the ability to fly.\n"
+"The sinewy muscles betray the ferocious fighter under the agreeable look.\n"
            );
  SetDesc (
 "Oglons are a strange, uncommon race in OSB of unknown, but possibly\n"
+"feline origin. Rumors go that their ancestors came from outer space many\n"
+"years ago.\n"
+"Smaller than humans, oglons lack human strength and constitution. But\n"
+"their higher intelligence and dexterity, and their good natural weapons\n"
+"make them fierce fighters, silent in their stalk, and mighty magicians.\n"
  );
  AddEquipment("torch", "/obj/torch", 0, 0, ({ "lamp", "lantern" }));
}

/***************************************************************************/
