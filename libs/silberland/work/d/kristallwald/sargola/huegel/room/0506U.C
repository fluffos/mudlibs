/*
***********************************************
** 0506u.c               *
** 1. Grab - Tag            *
** date: 01-12-97 by Sargola@Silberland     *
** Email: a9504778@unet.univie.ac.at         *
***********************************************
**
** Updates:       :      
** Updates:       :      
** Updates:       :      
** 
*/

inherit "std/room";
#include <properties.h>
#include <language.h>
#include <moving.h>

#include "../def.h"
#include "gang.h"

int schlinge;
      create()
      {
        ::create();

        SetProp( P_INT_SHORT, "Unter einem Huegelgrab" );
        SetProp( P_INT_LONG, 
      BS("Du stehst in der Grube unter dem Grab. Erstaunlicherweise ist "
	+"es hier nicht eng oder stickig, wie Du angenommen hast. Im Gegen"
	+"teil. Es fuehrt ein breiter Gang unterirdisch nach Suedosten. "
	+"Oberhalb kannst Du die Kante des Steingrabes sehen, darueber "
	+"das Firmament.") );
     
        SetProp( P_LIGHT, 0 );
        SetProp( P_INDOORS, 1 );
	
	STANDARD
	SS
	UNDER_GRAVE

        AddExit("oben",ROOM+"0506n");
	AddExit("nordwesten",ROOM+"0405u");

      }


INNIT

HAND

SCHLINGE
