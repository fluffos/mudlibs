/*
***********************************************
** Kutte fuer Schwarzkutten      *
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

object wer;

create()
{
  if (!is_clone(this_object()))
     return;
  ::create();
  AddId (({"schwarzkutte", "kutte"}));
  SetProp (P_SHORT, "Eine schwarze Kutte");
  SetProp (P_LONG, BS("Eine schwarze, schwere Kutte aus weichem Stoff. "
	+"Sie ist ziemlich weit geschnitten und bildet grosse Falten.\n"));
  AddDetail("stoff",
	"Vielleicht ist es Samt?");
  AddDetail("samt",
	"Der Stoff fuehlt sich genau wie Samt an.");
  AddDetail("falten",
	"Beim Tragen faellt der Stoff in wallenden Falten herab.");
  SetProp(P_INFO, BS(
    "Du fuehlst eine boese Aura um die Kutte.") );
  SetProp (P_NAME, "Kutte");
  SetProp (P_GENDER, FEMALE);
  SetProp (P_WEIGHT, 1050);
  SetProp (P_VALUE, 800);

  SetProp (P_ARMOUR_TYPE, AT_CLOAK);
  SetProp (P_AC, 6);
  SetProp (P_DEFEND_FUNC, TO);
  SetProp (P_WEAR_FUNC, TO);
}

int WearFunc()
{
	wer = TP;
	return 1;
}

 
int DefendFunc(mixed dam_type, int spell, object enemy)
{
	wer->QueryProp(P_ALIGN, wer->QueryProp(P_ALIGN) - 1 );

	if(random(30) == 1)
	{
	   tell_object(wer,
		"Du fuehlst ploetzlich einen fuerchterlichen Hass auf "
		"Dich.\n");
	   wer->do_damage(20);
	   return 0;
	}

	if(environment(wer)->QueryProp(P_INDOORS) == 1)
	{
	   if(environment(wer)->QueryProp(P_LIGHT) == 0)
	   {
		tell_object(wer, enemy->QueryProp(P_NAME)
		   +" kann Dich mit der Kutte fast nicht sehen.");
		return 8;
	   }
		tell_object(wer, enemy->QueryProp(P_NAME)
		   +" erkennt Dich mit der Kutte nicht so gut.");
	   return 5;
	}
	return 0;
}