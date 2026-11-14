/*
***********************************************
** 0307t.c               *
** Taleingang - Tag            *
** date: 20-09-97 by Sargola@Silberland     *
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
//#include "tag.h"
#include "../../wald/room/wald.h"

      create()
      {
        ::create();

        SetProp( P_INT_SHORT, "Ein Waldweg" );
        SetProp( P_INT_LONG, 
      BS("Im Sueden endet ploetzlich der Wald und gibt Deinen Blick auf ein "
      	+"im Norden liegendes Tal frei. Ein schmaler, gewundener Weg fuehrt "
      	+"in das Tal. Es ist nur 10 oder 15 Meter tief und in der Mitte kannst "
      	+"Du einen weissen Stein entdecken. Um den Stein liegen 4 Huegel.") );
     
        SetProp( P_LIGHT, 1 );
        SetProp( P_INDOORS, 0 );

	AddDetail( ({"huegel","anhoehe"}), BS("Du kannst 4 Huegel erkennen, welche "
		+"sich alle 5 Meter vom Boden des Tales erheben. Auf ihnen "
		+"befindet sich etwas. Was, kannst Du nicht erkennen."));

	AddDetail("wald",
		"Im Sueden siehst Du die fuer den Kristallwald typischen "
		+"Kristalleichen.");
	
	AddDetail("tal", BS("Da stehst Du genau drin."));
	
	AddDetail( ({"hang","haenge"}),
		"Von der Talsenke aus steigen die Haenge zu Beginn sanft, "
		+"spaeter steiler an. Das letzte Stueck ist fast senkrecht, "
		+"an ein Rausklettern ist also nicht zu denken.");

	AddDetail( ({"kaesten","steinkaesten"}),
		"Du kannst von unten nicht genau erkennnen, was das wohl "
		+"fuer Kaesten sind.");


	
	STANDARD
	STANDARD1
	SS
	STEIN_UNTEN
	GRAB_UNTEN


	AddCmd( "oeffne","oeffne");
	AddCmd( ({"kratz","kratze"}), "schmutz");
	AddCmd( "schlafe","schlafen"),

        AddExit("sueden",ROOM+"0307t");	
	AddExit("nordosten",ROOM+"0405t");
	AddExit("nordwesten",ROOM+"0205t");	


      }


OEFFNE

SCHMUTZ_NOE

SCHLAFEN