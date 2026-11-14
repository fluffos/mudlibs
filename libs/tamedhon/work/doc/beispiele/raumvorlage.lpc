/* <NAME DES RAUMS>
 * <magiername>@tamedhon.at
 */
#include <properties.h>
#include <moving.h>
#include <combat.h>
#include "../def.h"

inherit "std/room";

int einraumkommando(string str)
{
    notify_fail("<Syntaxfehlermeldung>\n");
    if(str == "wort1" ||
       str == "wort")
    {
	/* Kommando ausfuehren */
	return 1;
    }
    
    return 0;
}

void reset()
{
    ::reset();
    
    /* Code, der beim Reset ausgefuehrt wird */
}

void init()
{
    ::init();
    
    /* Code, der beim Init ausgefuehrt wird */
}

void create()
{
    ::create();
    
    SetProp(P_LIGHT, 1);		// hell soll es sein
    SetProp(P_INDOORS, 0);		// innen oder frische Luft?
    SetProp(P_ENVIRONMENT,
	([ENV_TEMPERATURE: 14+random(3), // Temperatur setzen
	  ENV_TERRAIN: TT_FOREST]));	 // Welches Terrain (environment.h)

    SetProp(P_INT_SHORT, "");		// Kurzbeschreibung des Raums
    SetProp(P_INT_LONG, break_string(	// Langbeschreibung des Raums
	""));

    /* Raumkommando definieren */	
    AddCmd("kommando", "einraumkommando");
    
    /* Ausgaenge definieren */
    AddExit("richtung", "<zielraum>");    
	
    /* ----------------------------------------------------------- */
    
    /* Raumdetails */
    AddDetail("boden", break_string(
	""));
    AddDetail("decke", break_string(
	""));
    AddDetail("wand", break_string(
	""));
    AddDetail("waende", break_string(
	""));
    AddDetail("himmel", break_string(
	""));
	
    /* ----------------------------------------------------------- */
    /* Gerueche */
    AddDetail(DEFAULT_SMELL, break_string(
	""));
	
    /* ----------------------------------------------------------- */
    /* Gerueche und so */
    AddDetail(DEFAULT_SOUND, break_string(
	""));
	
    /* ----------------------------------------------------------- */
    /* NPCs, Objekte die im Raum sind */
    AddItem("<dateinamedesobjektes>", REFRESH_DESTRUCT);
}


