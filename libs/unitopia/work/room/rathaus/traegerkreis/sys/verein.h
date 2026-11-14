/* File: /d/Vaniorh/fizban/i/verein.h
   Autor: Fizban
   Datum: 21.05. 1996
   Bemerkung: Headerfile fuer die wichtigsten Funktionen des Vereins
   Modified:
     Tiberian, 01.06.2008: Umzug nach Root
*/

// Diese Includes werden eh immer gebraucht,
// also warum nicht gleich hier einbinden? :)
#include <more.h>
#include <config.h>
#include <misc.h>

// Eine Liste der Gruendungsmitglieder:
#define GRUENDER ({"grisu","yoda","fizban","monty","freaky","sissi", "kickaha", \
                   "arthax","khan","ixxi","undine","jadawin","pulami"})
// Die Pfade fuer den Verein:
#define VEREIN_PFAD "/room/rathaus/traegerkreis/"
#define NPC_PFAD VEREIN_PFAD+"npc/"
#define OBJ_PFAD VEREIN_PFAD+"obj/"
#define RAUM_PFAD VEREIN_PFAD+"room/"

// Die Defines fuer die Satzung:
#define SATZUNG_ID "satzung#verein"
#define SATZUNG_OBJ OBJ_PFAD+"satzung"
#define SATZUNG_NAME "/room/rathaus/div/satzung.txt"
#define SATZUNG_TEXT TP->more(SATZUNG_NAME,0,0,M_AUTO_END); return "";

// Die Defines fuer das Mitloggen einer Sitzung:
#define LOGFILE         "SITZUNG"
#define LOG(x)          sys_log(LOGFILE, x)

// Anschluss des Vereins an Magyra
#define AUSGANG "/room/rathaus/foyer"

// Ein paar nuetzliche Abkuerzungen:
//#define TP this_player()
//#define TO this_object()
//#define ENV(x) environment(x)
//#define CAP(x) capitalize(x)
#undef FAIL
#define FAIL(x) notify_fail(x); return 0;
#define HIER ENV_TO
//#define RN(x) x->query_real_name()

// Damit laesst sich testen, ob ein Spieler ein
// Mitglied des Vorstandes oder des Beirats ist.
#define CHEF(x) (member(VORSTAND,RN(x))>=0) \
             || (member(ADMINS,RN(x))>=0)

// Die etwas merkwuerdigen Bezeichnungen sind noetig,
// damit es keine Probleme mit den anderen Defines gibt!
#define CHEF_NAMEN liste(map(VORSTAND,#'capitalize))
#define FUFFI_NAMEN liste(map(ADMINS,#'capitalize))
#define GRUENDER_NAMEN liste(map(GRUENDER,#'capitalize))

