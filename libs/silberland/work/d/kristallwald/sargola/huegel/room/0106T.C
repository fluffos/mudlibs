/*
***********************************************
** 0103.c               *
** 3. Grab - Tag            *
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
#include "tag.h"

#define GRAVUR_TEXT "Du liest: \"Hier liegt Noma Langbart, Zwerg\""
int enemy_anz;

      create()
      {
        ::create();
	enemy_anz = 1;
        SetProp( P_INT_SHORT, "Bei einem Huegelgrab" );
        SetProp( P_INT_LONG, 
      BS("Du stehst auf einer kleinen Anhoehe und kannst das ganze Tal "
	+"schoen ueberblicken. Neben Dir befindet sich ein dunkles, un"
	+"heimlich wirkendes Huegelgrab, welches ziemlich klein wirkt "
	+"und aus schwarzem Stein. Es fuehrt "
	+"ein duenner Weg im Gras hier herauf.") );
     
        SetProp( P_LIGHT, 1 );
        SetProp( P_INDOORS, 0 );
	AddDetail( ({"huegel","anhoehe"}), BS("Du kannst 4 Huegel erkennen, welche "
		+"sich alle 5 Meter vom Boden des Tales erheben."));

	AddDetail("tal", BS("Das Tal liegt ein wenig unter Dir und wirkt "
		+"unwirklich farblos. Irgendwie fuehlst Du Dich hier "
		+"nicht sicher."));
	
	AddDetail("weg",
		"Der Weg ist schwer zu sehen, weil er nicht sehr breit "
		+"und schon laenger nicht mehr benutzt wurde.");

	
	AddRoomMessage( ({
		"Du vernimmst ein leiese Klopfen vom Grabdeckel.\n",
		"Du denkst . o 0 (Was mag sich wohl im Grab befinden?).\n",
		"Es stinkt aus der Ritze des Grabdeckels.\n"}), 40);
	
	STANDARD
	STANDARD1
	SS
	GRAB_OBEN
	GRAB_OBEN1
	STEIN_OBEN

        AddCmd( ({"oeffne"}),"oeffne");
        AddCmd( ({"schau","schaue","blick","blicke"}), "schaue");
        AddExit("nordosten",ROOM+"0205t");


      }

reset()
{
	::reset();
	enemy_anz = 1;
}

OEFFNE

SCHAUE