/*
 * belongs to the inner townwall
 * a spicer which weaving some cobwebs
 *
 * last changes:
 * [m] 26 jan 98 - first version
 */

#include <properties.h>
#include <npc.h>
#include <sykorath.h>

inherit "/std/npc";

//*******
// create
//*******
create() {
  if (::create()) return;
  SetName("spider");
  SetRace("spider");
  SetShort("a small spider");
  SetLong(
    "A small spider which is weaving some new sobwebs. Be carefully "
    "- maybe the spider spits poison?\n");
  SetGoChance(0);                  // don't go away
  SetLevel(3);
  SetGender(GENDER_NEUTER);

  InitChats( 5 , ({
    "The spider weaves some new parts of the web.\n",
    "The spider waits for a new victim.\n",
    "The spider doesn't move.\n",
    "The cobwebs swings to the left and then back to the right.\n",
    }) );

  AddId(({"spider"}));
  SetAds(({"small"}));

  SetShrugMsg("The spider crawls away.\n");
}

