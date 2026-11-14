/*
***********************************************
** Fetzenhemd      *
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
  AddId (({"hemd", "fetzenhemd"}));
  SetProp (P_SHORT, "Ein Fetzenhemd");
  SetProp (P_LONG, BS("Das Hemd besteht nur aus dreckigen Fetzen.\n"));
  AddDetail("fetzen",
	"Die lohnen sich kaum zu untersuchen.");

  SetProp (P_NAME, "Fetzenhemd");
  SetProp (P_GENDER, NEUTER);
  SetProp (P_WEIGHT, 700);
  SetProp (P_VALUE, 250);

  SetProp (P_ARMOUR_TYPE, AT_ARMOUR);
  SetProp (P_AC, 10);

}

 
