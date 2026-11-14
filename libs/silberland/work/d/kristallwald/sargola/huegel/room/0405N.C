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

	AddExit("suedosten",ROOM+"0506n");
	AddExit("norden",ROOM+"0404n");
	AddExit("suedwesten",ROOM+"0306n");
      }

SCHMUTZ