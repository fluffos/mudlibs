/************************************************
**  Feder vom Schnabler            *
**                   *
** date: 15-01-97 by Sargola@Silberland     *
** Email: a9504778@unet.univie.ac.at         *
*************************************************
** Updates:       :      
** Updates:       :      
** Updates:       :      
** 
*/

inherit "std/thing";
#include <properties.h>
#include <combat.h>
#include <language.h>
#include "../def.h"

      create()      
{        if (!is_clone(this_object()))           return;
        ::create();
             AddId (({"feder"}));
        SetProp (P_SHORT, "Eine Onyxschnablerfeder");
        SetProp (P_LONG, BS("Die Feder ist onyxfarben und 15 cm lang.\n"));
        SetProp (P_NAME, "Feder");
        SetProp (P_GENDER, FEMALE); 
        SetProp (P_WEIGHT, 50);
        SetProp (P_VALUE, 90);
	SetProp (P_MATERIAL, ({MAT_FEATHER }));

        
}  
