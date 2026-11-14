/*
***********************************************
** 0103n.c               *
** 1. Grab - Tag            *
** date: 04-02-97 by Sargola@Silberland     *
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
	
	AddDetail("grube",
		"Die Grube ist groesser, als es das Grab von oben vermuten "
		+"lassen wuerde. Du kannst gemuetlich darin stehen. Ausser"
		+"dem geht ein breiter Weg richtung Suedosten weg.");
	AddDetail("grab",
		"Du kannst von hier unten nur mehr die Steinwaende des "
		+"Grabes sehen.");
	AddDetail("steinkante",
		"Die Kante hebt sich gegen das dunkelblaue Firmament des "
		+"Himmels ab.");
	AddDetail(({"himmel","firmament"}),
		"Das Firmament leuchtet dunkelblau ueber Dir. Einige "
		+"schwach leuchtende Sterne kannst du auch noch entdecken.");
	AddDetail("sterne",
		"Die Sterne sind ziemlich klein und Du kannst sie nur schwer "
		+"mit freiem Auge erkennen.");
	AddDetail("auge",
		"Du hast blaue Augen, vermutest Du wenigstens...");
	AddDetail( ({"gang","weg"}),
		"Der Weg fuehrt nach Suedosten. Er gaehnt wie ein schwarzes "
		+"Loch und Du verspuerst nicht unbedingt den Drang, dorthin "
		+"zu gehen.");
	AddDetail("loch",
		"Es ist absolut unsicher, was Dich dort in dem Gang erwartet. "
		+"Ueberleg es Dir besser nocheinmal...");
	AddDetail("drang",
		"Du denkst . o 0 (Ich sollte gleich wieder aus dem Grab steigen).");
	
	AddDetail("boden",
		"Der Boden besteht aus festgetretener Erde. Vor Dir scheinen "
		+"schon einige Abentuerer (oder waren es Druiden?) diesen "
		+"Platz betreten zu haben. Auf jeden Fall bist Du nicht der "
		+"erste, der hier seine Fussabdruecke hinterlaesst.");
	AddDetail("erde",
		"Die "); 




	STANDARD
	SS

        AddExit("oben",ROOM+"0103n");


      }


INNIT

HAND

SCHLINGE