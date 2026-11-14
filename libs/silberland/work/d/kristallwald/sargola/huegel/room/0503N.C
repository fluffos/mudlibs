/*
***********************************************
** grabnacht.c  -  inherit-file               *
**  Grab - Nacht            *
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

int enemy_anz;
int schaue(string str);

#define GRAVUR_TEXT "Du liest: Hier liegt Noam Langbart, Zwerg"

#include "../def.h"
#include "nacht.h"

      create()
      {
        ::create();
 	enemy_anz = 1;
        SetProp( P_INT_SHORT, "Bei einem Huegelgrab" );
        SetProp( P_INT_LONG, 
      BS("Du stehst auf einer kleinen Anhoehe und kannst das ganze Tal "
	+"unter Dir unter einer Schicht Nebel erkennen. Neben Dir befindet "
	+"sich ein dunkles, unheimlich wirkendes Huegelgrab, welches "
	+"aus schwarzem Stein besteht. Es fuehrt ein duenner Weg im Gras "
	+"hier herauf.") );
     
        SetProp( P_LIGHT, 1 );
        SetProp( P_INDOORS, 0 );


	STANDARD
	STANDARD1
	SS
	GRAB_OBEN
	STEIN_OBEN
	
	AddDetail("tal", BS("Das Tal liegt ein wenig unter Dir und wird "
		+"durch eine Schicht Nebel verdeckt."));
		
	AddDetail( ({"decke","schicht","nebel"}),
		"Der Nebel liegt wie ein Meer aus weissem Dunst im Tal.");
		
	AddDetail("meer",
		"Das Meer aus Nebel ist weisslich und verdeckt die ganze "
		+"Talsenke.");
		
	AddDetail("dunst",
		"Der Dunst ist nicht mit dem Auge zu durchdringen.");
		
	AddDetail("spitzen",
		"Sie erheben sich ueber die Decke aus Nebel und auf ihnen "
		+"kannst du dunkle Kaesten erkennen.");
	
	AddDetail("kaesten",
		"Die Kaesten scheinen Graeber zu sein.");
	
	
	
	AddDetail("weg",
		"Der Weg windet sich nach unten und verschwindet bald "
		+"im Nebel.");
		
	AddRoomMessage( ({
		"Du hoerst ein leises Geraeusch aus dem Grab.\n",
		"Hast Du nicht gerade was gehoert?\n",
		"Du fuehlst Dich in der Naehe des Grabes nicht wohl.\n"}), 40);

	AddCmd( ({"oeffne"}), "oeffne");
        AddCmd( ({"schau","schaue","blicke","blick"}), "schaue");
	AddExit("suedwesten",ROOM+"0404n");
      }

reset()
{
	::reset();
	enemy_anz = 1;
}


SCHAUE

OEFFNE_NO