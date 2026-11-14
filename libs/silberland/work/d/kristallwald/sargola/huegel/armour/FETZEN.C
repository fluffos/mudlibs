/*
***********************************************
** Ein Fetzen fuer den Untoten		*
** 				            *
** date: 12-06-97 by Sargola@Silberland        *
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
#include <food.h>
#include <combat.h>


void create()
{
   if (!is_clone(this_object())) return;   ::create();

   SetProp(P_SHORT, "Ein Fetzen");
   SetProp(P_LONG,
      "Ein ausgerissenener, dreckiger, abgeschnuddelter, zerfetzter Fetzen, den man "
	+"sich zur Not um den Oberkoerper wickeln kann.\n");

   SetProp(P_NAME, "Fetzen");
   AddId(({ "fetzen"}));
   SetProp(P_WEIGHT, 300);
   SetProp(P_VALUE, 100);
   SetProp(P_ARMOUR_TYPE, AT_ARMOUR );
   SetProp(P_AC, 2);  

   SetProp(P_GENDER, MALE);
   SetProp(P_VALUE, 100);
   SetProp(P_ARMOUR_TYPE, AT_HELMET );
   SetProp(P_AC, 2);  
}
