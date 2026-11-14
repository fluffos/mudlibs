/*
***********************************************
** Fetzenhose      *
**                   *
** date: 24-09-97 by Sargola@Silberland     *
** Email: a9504778@unet.univie.ac.at         *
***********************************************
**
** Updates:       :      
** Updates:       :      
** Updates:       :      
** 
*/

inherit "std/armour";

#include <properties.h>
#include <language.h>
#include <combat.h>
#include <new_skills.h>
#include "../def.h"

create()
{
  if (!is_clone(this_object()))
     return;
  ::create();
  AddId (({"hose", "fetzenhose"}));
  SetProp (P_SHORT, "Eine Fetzenhose");
  SetProp (P_LONG, BS("Die Hose ist eigentlich nur mehr eine Ansammlung "
	+"von Fetzen. Sie traegt ihren Namen nicht umsonst.\n"));
  AddDetail("fetzen",
	"Die Hose wurde aus vielen Fetzen zusammengestueckelt.");
  AddDetail("namen",
	"Dies ist offensichtlich eine Fetzenhose.");
  SetProp (P_NAME, "Fetzenhose");
  SetProp (P_GENDER, FEMALE);
  SetProp (P_WEIGHT, 800);
  SetProp (P_VALUE, 300);

  SetProp (P_ARMOUR_TYPE, AT_TROUSERS);
  SetProp (P_AC, 3);

}

 
