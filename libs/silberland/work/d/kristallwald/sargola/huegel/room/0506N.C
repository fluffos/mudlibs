/*
***********************************************
** 0405n.c               *
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

inherit "/std/room";
#include <properties.h>
#include <language.h>
#include <moving.h>

#include "../def.h"
#include "nacht.h"
#define GRAVUR_TEXT "testtestsst"

int schmutz;
int schmutz(string str);

     create()
      
      {
        ::create();
	
	
        SetProp( P_INT_SHORT, "Im Tal der Huegelgraeber" );
        SetProp( P_INT_LONG, 
      BS("Du stehst in der Senke des Tales und um Dich herum steigen lang"
	+"sam die mit fast farbloser Wiese bedeckte Haenge an. Du kannst "
	+"vier Huegel entdecken, auf denen sich bedrohlich "
	+"wirkende, niedrige Graeber befinden. Genau in der Mitte des "
	+"Tales siehst Du einen hohen, hinkelsteinfoermigen Stein. Das Tal "
	+"liegt unter einer dichten Schichte mit Nebel.") );

	AddDetail(({"talsenke","senke"}),
		"Du befindest Dich ganau in der Senke des Tales.\n");
	AddDetail("tal",
		"Viel kannst Du von dem Tal nicht erkennen, denn es ist "
		+"Nacht.");
		
	STANDARD
	STANDARD1
	SS
	GRAB_UNTEN
	STEIN_UNTEN

	AddItem(NPC+"mleiche", REFRESH_DESTRUCT);
	AddCmd("oeffne","oeffne");
	AddExit("nordwesten",ROOM+"0405n");	
      }

SCHMUTZ


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
	   AddExit("unten", ROOM+"0506u");				
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
	   AddExit("unten", ROOM+"0506u");				
	   return 1;						
	}								
	return 0;							
}
