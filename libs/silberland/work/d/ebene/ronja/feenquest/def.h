//=========================================================================
//
// File:    def.h
// Created by Ronja@SL
//
// Project: Feen
//
//=========================================================================

#define GEBIET "feenquest"

#include "../def.h"

#define FEENQUESTNAME "Mitternachtstanz der Feen"
#define FEENQUESTLOG "/log/quests/feenquest"
#define AMAQUEST "Amaltheas Ring"

#ifndef LABY
#define LABY  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/lab/"
#endif

#ifndef FMASTER
#define FMASTER  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/master"
#endif

#ifndef RINGMASTER
#define RINGMASTER  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/ringmaster"
#endif

#ifndef FEENLIB
#define FEENLIB  NPC "/feen.lib"
#endif

/* Himmelsrichtungen ***************************************************/

#define NORDEN 0
#define OSTEN 1
#define SUEDEN 2
#define WESTEN 3

/* Raum unten fuer Seilsturz ******************************************/

#define P_RAUMUNTEN "raumunten"

/* Hecke   ************************************************************/

#define P_HECKE "heckenzustand"
#define HECKE_NICHT_DA 0
#define HECKE_IST_DA 1
#define HECKE_TORBOGEN 2
#define HECKE_BRESCHE_ZU 3
#define HECKE_BRESCHE_AUF 4

/* Feenhut ************************************************************/
#define P_HUTZUSTAND "hutzustand"
#define P_QUESTVERLAUF "questverlauf"

/* Mausefalle *********************************************************/
#define P_MAUSEFALLE "fuellung"

/* Pferde *************************************************************/

#define Z_NICHTS         0
#define Z_AUFGELEGT      1
#define Z_FESTGESCHNALLT 2
#define Z_UEBERGESTREIFT 3

#define S_NICHTS         0
#define S_AUFGELEGT      1
#define S_FESTGESCHNALLT 2
#define S_STEIGBUEGEL    3

#define P_TEMPERAMENT "temperament" // daemlich brav feurig
#define P_FARBE "fellfarbe"   // schwarz weiss braun fuchs gescheckt
#define P_GESCHLECHT "pgeschlecht" // hengst stute wallach
#define P_SATTEL "sattel_zustand"
#define P_ZAUMZEUG "zuegel_zustand"

#define T_BRAV 2
#define T_DAEMLICH 1
#define T_FEURIG 0

#define T_HENGST         0
#define T_WALLACH        1
#define T_STUTE          2
#define T_FOHLEN         3

#define T_RAPPE          0
#define T_SCHIMMEL       1
#define T_BRAUNER        2
#define T_FUCHS          3
#define T_GESCHECKT      4

#define CUSTOMIZE previous_object()->CustomizeObject()

