/*
***********************************************
** 0204n.c               *
** Tal - Tag            *
** date: 04-02-97 by Sargola@Silberland     *
** Email: a9504778@unet.univie.ac.at         *
***********************************************
**
** Updates:       :      
** Updates:       :      
** Updates:       :      
** 
*/

inherit "/d/kristallwald/sargola/huegel/room/untennacht";
#include <properties.h>
#include <language.h>
#include <moving.h>

#include "../def.h"
#include "nacht.h"
#define GRAVUR_TEXT "testtestsst"

     create()
      
      {
        ::create();

        SetProp( P_INT_SHORT, "Bei einem Huegelgrab" );
        SetProp( P_INT_LONG, 
      BS("Du stehst in der Senke des Tales und um Dich herum steigen lang"
	+"sam die mit fast farbloser Wiese bedeckte Haenge an. Du kannst "
	+"4 Huegel entdecken, auf denen bedrohlich wirkende, niedrige "
	+"Steinkaesten stehen. Genau in der Mitte des Tales siehst Du "
	+"einen hohen, hinkelsteinfoermigen Stein.") );

	AddItem(NPC+"mleiche");

        AddExit("sueden",ROOM+"0205t");	
	AddExit("nordosten",ROOM+"0303t");
	AddExit("nordwesten",ROOM+"0103t");	
      }
