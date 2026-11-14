/*
***********************************************
** Hose fuer Schwarzkutten      *
**                   *
** aendert das align pro defend, man greift sich selbst an
** dafuer haelt sie gut schlaege im dunkeln ab...
**
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
  AddId (({"schwarzhose", "hose"}));
  SetProp (P_SHORT, "Eine schwarze Hose");
  SetProp (P_LONG, BS("Eine schwarze, schwere Hose aus weichem Stoff. "
	+"Sie ist ziemlich weit geschnitten, bildet grosse Falten und "
	+"ist angenehm zu tragen.\n"));
  AddDetail("stoff",
	"Du glaubst, dass es Samt ist.");
  AddDetail("samt",
	"Der Stoff fuehlt sich zumindest genau wie Samt an.");
  AddDetail("falten",
	"Beim Tragen faellt der Stoff in wallenden Falten herab.");
  SetProp(P_INFO, BS(
    "Du fuehlst eine boese Aura um die Hose.") );
  SetProp (P_NAME, "Schwarzhose");
  SetProp (P_GENDER, FEMALE);
  SetProp (P_WEIGHT, 850);
  SetProp (P_VALUE, 600);

  SetProp (P_ARMOUR_TYPE, AT_TROUSERS);
  SetProp (P_AC, 8);

}

