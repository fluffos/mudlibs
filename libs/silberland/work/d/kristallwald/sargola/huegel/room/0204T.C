/*
***********************************************
** 0104.c               *
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

inherit "std/room";
#include <properties.h>
#include <language.h>
#include <moving.h>

#include "../def.h"
#include "tag.h"
#define GRAVUR_TEXT "dfasd"
int enemy_anz;
int schmutz(string str);


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
     
        SetProp( P_LIGHT, 1 );
        SetProp( P_INDOORS, 0 );

	

	AddDetail( ({"huegel","anhoehe"}), BS("Du kannst 4 Huegel erkennen, welche "
		+"sich alle 5 Meter vom Boden des Tales erheben."));

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

	AddItem(NPC+"mleiche");

        AddExit("sueden",ROOM+"0205t");	
	AddExit("nordosten",ROOM+"0303t");
	AddExit("nordwesten",ROOM+"0103t");	
	AddCmd( "oeffne","oeffne");
	AddCmd( ({"kratz","kratze"}), "schmutz");
	AddCmd("schlafe","schlafen");
      }


OEFFNE

SCHMUTZ_NOE


SCHLAFEN