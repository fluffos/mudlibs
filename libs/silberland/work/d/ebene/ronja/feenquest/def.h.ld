//=========================================================================
//
// File:    def.h
// Created by Ronja@SL
//
// Project: Feen
//
//=========================================================================

#pragma strong_types

#include <defines.h>
#include <moredef.h>

#include <properties.h>
#include <moving.h>
#include <combat.h>
#include <wizlevels.h>
#include <new_skills.h>
#include <class.h>
#include <mnpc.h>

#include <verben.h>
#include <guard.h>


#define FEENQUESTNAME "Mitternachtstanz der Feen"
#define FEENQUESTLOG "/log/quests/feenquest"
#define AMAQUEST "Amaltheas Ring"

#define MAGIERNAME "ronja"
#define REGION "ebene"
#define GEBIET "feenquest"

#ifndef NPC
#define NPC  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/npc/"
#endif

#ifndef OBJ
#define OBJ   "/d/" REGION "/" MAGIERNAME "/" GEBIET "/obj/"
#endif

#ifndef ROOM
#define ROOM  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/room/"
#endif

#ifndef LABY
#define LABY  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/lab/"
#endif

#ifndef LOG
#define LOG   "/d/" REGION "/" MAGIERNAME "/" GEBIET "/log/"
#endif

#ifndef SAVEDIR
#define SAVEDIR  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/save/"
#endif

#ifndef ARMOUR
#define ARMOUR  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/armour/"
#endif

#ifndef WEAPON
#define WEAPON  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/weapon/"
#endif

#ifndef FMASTER
#define FMASTER  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/master"
#endif

#ifndef RINGMASTER
#define RINGMASTER  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/ringmaster"
#endif

#ifndef DB
#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),(x))
#endif

#define LW(x) (sizeof(x)==1 ? x[0] : implode(x[0..<2],", ")+" und "+x[<1])

#define APATH "/d/ebene/ronja/feenquest/"
#define ALOG APATH "log/"
#define FEENLIB APATH "npc/feen.lib"

#define TELLPLAYER(x) tell_object(TP,x)
#define TELLOTHERS(x) tell_room(ENV(TP),x,({TP}))

#define WRITELOG(x) write_file(ALOG "feen.log",ctime()+":"+x+".\n")
#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())

/* Himmelsrictungen ***************************************************/

#define NORDEN 0
#define OSTEN 1
#define SUEDEN 2
#define WESTEN 3

/* Raum unten fuer Seilsturz ******************************************/

#define P_RAUMUNTEN "raumunten"

/* Bresche ************************************************************/

#define P_BRESCHE "breschenzustand"
#define BRESCHE_ZU 1
#define BRESCHE_AUF 2

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

