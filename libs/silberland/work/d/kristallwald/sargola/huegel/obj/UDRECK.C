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

   SetProp(P_SHORT,0);

   AddId(({ "\ndreck"}));
   SetProp(P_WEIGHT, 0);
   SetProp(P_NODROP,1);
    
}

_query_extralook()
{
	string msg;
	msg = " hat sich Dreck wie ein Indianer ins Gesicht geschmiert.\n";

	return (TP->QueryProp(P_GENDER)==1 ? "Er"+msg : "Sie"+msg);

}