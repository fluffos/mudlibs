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
	AddExit("nordosten",ROOM+"0205n");
      }

reset()
{
	::reset();
	enemy_anz = 1;
}


SCHAUE

int oeffne(string str)							
{									
	notify_fail("Was moechtest Du oeffnen?\n");			
	if(!str && str!="grab") return 0;				
									
	notify_fail("Du muehst Dich ziemlich ab, bekommst das Grab aber nicht auf.\n");						
									
	if(present("weihwasser"))					
	{								
	   tell_object(TP, "Als Du Dich dem Grab naeherst, merkst Du, "	
	   +"dass Du die Gestalten im Grab durch das Weihwasser auf"	
	   +"regst. Sie geraten komplett in Rage und brechen das Grab "	
	   +"auf...\n\n");						
	   clone_object(NPC+"untoter")->move(TO, M_GO);			
	   if(random(3)==1)						
	   	clone_object(NPC+"untoter")->move(TO,M_GO);		
	   AddExit("unten", ROOM+"0103u");				
	   return 1;							
	}								
									
									
	if(TP->QueryProp(P_ALIGN)>700)					
	{								
	   tell_object(TP, "Als Du Dich dem Grab naeherst, merkst Du, "	
	   +"dass durch Deinen Gegenwart die Gestalten im Grab boese "	
	   +"werden und das Grab oeffnen...\n\n");			
	   clone_object(NPC+"untoter")->move(TO, M_GO);			
	   if(random(4)==1)						
	   	clone_object(NPC+"untoter")->move(TO,M_GO);		
	   AddExit("unten", ROOM+"0106u");				
	   return 1;						
	}								
	return 0;							
}
