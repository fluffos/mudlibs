/*
***********************************************
** Dreck von Steinrille					*
** 				                *
** date: 19-09-97 by Sargola@Silberland        *
** Email: a9504778@unet.univie.ac.at         *
***********************************************
**
** Updates:       :      
** Updates:       :      
** Updates:       :      
** 
*/

inherit "std/thing";
#include <properties.h>
#include "../def.h"


void create()
{
   if (!is_clone(this_object())) return;
   ::create();

   SetProp(P_SHORT, "Ein Haufen Dreck");
   SetProp(P_LONG,
	"Ein kleiner Haufen Dreck - was Du daran nur finden kannst....");
   SetProp(P_GENDER, MALE);
   SetProp(P_ARTICLE, 1);
   SetProp(P_NAME, "Haufen Dreck");
   AddId(({ "dreck","haufen","haufen dreck"}));
   SetProp(P_WEIGHT, 50);
   SetProp(P_VALUE, 30);
     
}

