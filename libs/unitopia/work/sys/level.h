// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/level.h
// Description: Include fuer alles, was mit dem Spielerlevel zu tun hat
// Author:	Garthan (29.12.93)
// Modified:	Freaky (21.01.94) wizp lordp adminp ...
//		Freaky (30.05.94) learnerp ...
//		Freaky (25.10.1999) LVL_D_* eingebaut
//              Sissi  (11.02.2001) Anpassungen fuer neues Levelsystem
//
// $Log: level.h,v $
// Revision 1.13  2014/12/19 16:35:43  myonara
// neues define wizplayerp inkl. Dokuanpassungen.
//
// Revision 1.12  2009-06-17 08:04:37  gnomi
// testplayerp umfasst auch Gruppen-Testies.
//
// Revision 1.11  2008-04-26 18:13:20  gnomi
// NEWBIE_AGE im Test-MUD auf 0 setzen.
//
// Revision 1.10  2004-07-19 21:40:27  gnomi
// Domain-Infos vom Master nach /apps/domains umgezogen.
//
// Revision 1.9  2004/04/14 22:03:03  gnomi
// Neuer Vorstand...
//
// Revision 1.8  2002/11/20 04:13:03  gnomi
// Define gouvp ausgebaut.
//
// Revision 1.7  2001/11/12 03:56:29  gnomi
// Doku von Pulami eingebaut.
//
// Revision 1.6  2001/08/21 21:57:44  freaky
// bei newbiep auch auf wizp abpruefen fuer neue Zweitie-Goetter
//
// Revision 1.5  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LEVEL_H
#define LEVEL_H 1

#include "/sys/config.h"

#define LVL_SPIEL   1
#define LVL_RAETSEL 2
#define LVL_GILDE   4

#ifdef TestMUD
#define NEWBIE_AGE  0
#else
#define NEWBIE_AGE  86400
#endif


#define LVL_PLAYER	 1
#define LVL_HLP		10
#define LVL_WIZ		20
#define LVL_LEARNER	LVL_WIZ
#define LVL_GESELLE	21
#define LVL_VOGT	25
#define LVL_LORD	25
#define LVL_GOUV	25
#define LVL_ADMIN	25
// Groesster einzunehmender Level, alles darueber wird von
// von /apps/banishd als 'gebanished' betrachtet.
#define LVL_MAX_LEVEL	LVL_ADMIN

#define newbiep(x)  (playerp(x) && ({int})(x)->query_age()<NEWBIE_AGE && !wizp(x))
#define hlpp(x)     (playerp(x) && ({int})(x)->query_level() == LVL_HLP)
#define wizp(x)     (playerp(x) && ({int})(x)->query_wiz_level())
#define guestp(x)   (playerp(x) && LOGIN_OB->guest(x))
#define learnerp(x) (wizp(x)>=LVL_LEARNER)
#define gesellep(x) (wizp(x)>=LVL_GESELLE)
#define vogtp(x)    (wizp(x)>=LVL_VOGT)
#define lordp(x)    (wizp(x)>=LVL_VOGT && \
    (sizeof(({string*}) "/apps/domains"->query_domains_of(({string})x->query_real_name())) || \
     member(({string*}) "/apps/filed"->query_all_auth(), ({string})x->query_real_name()) >= 0 || \
     adminp(x)))
#define adminp(x)   (wizp(x)>=LVL_ADMIN && member(ADMINS,({string})(x)->query_real_name())!=-1)
#define testplayerp(x) ("/apps/second"->is_testplayer_or_special(x))
#define wizplayerp(x)  ("/secure/player_reader"->query_wiz_level(x))
#define spielerratp(x) ("/apps/spielerrat"->is_spielerrat(x))
#define LEVEL_LISTER "/secure/level_lister"

// Defines fuer query_level_dates()
#define LVL_D_LEVEL	0
#define LVL_D_DATE	1
#define LVL_D_AGE	2
#define DATUM_KONV_VOLLST_LEBENSLAEUFE  940716000

#endif // LEVEL_H

/*
FUNKTION: newbiep
DEKLARATION: int newbiep(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob um einen
Newbie handelt, sonst 0. Newbies sind Spieler mit einem Alter kleiner als
NEWBIE_AGE aus /sys/level.h (z.Zt. 1 Echtzeit-Tag).
Goetter sind keine Newbies.
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp,
          adminp, testplayerp, spielerratp
GRUPPEN: level
*/

/*
FUNKTION: hlpp
DEKLARATION: int hlpp(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob um einen Engel
(hlp=High Level Player) handelt, sonst 0.
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp,
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: wizp
DEKLARATION: int wizp(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob um einen Gott
handelt, sonst 0. wizplayerp macht dies mit Objekt oder Realnamen.
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp, 
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: wizplayerp
DEKLARATION: int wizplayerp(string rname|object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob um einen Gott
oder bei dem String um den Realnamen eines Gottes handelt, sonst 0. 
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp, 
          adminp, testplayerp, spielerratp
GRUPPEN: level
*/

/*
FUNKTION: guestp
DEKLARATION: int guestp(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob um einen Gast
handelt, sonst 0.
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp, 
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: learnerp
DEKLARATION: int learnerp(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob mindestens um
einen Lehrling handelt, sonst 0. Dies entspricht also wizp(ob).
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp, 
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: gesellep
DEKLARATION: int gesellep(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob mindestens um
einen Gesellen handelt, sonst 0. (Aus vogtp(ob) folgt also auch gesellep(ob).)
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp,
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: vogtp
DEKLARATION: int vogtp(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob mindestens um
einen Vogt handelt, sonst 0. (Aus lordp(ob) folgt also auch vogtp(ob).)
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp, 
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: lordp
DEKLARATION: int lordp(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob mindestens um
einen Lord handelt, sonst 0. (Aus adminp(ob) folgt also auch lordp(ob).)
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp,
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: adminp
DEKLARATION: int adminp(object ob)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob um einen Admin
handelt, sonst 0.
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp,
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: testplayerp
DEKLARATION: string testplayerp(object ob|string name)
BESCHREIBUNG:
Wenn es sich bei dem Objekt ob bzw. dem Spieler mit dem Namen name um den
Test-Zweitcharakter (Testplayer) eines Gottes handelt, liefert testplayerp()
den real_name dieses Gottes, sonst 0. Bei Gruppentesties, die offline sind,
liefert es den Gruppennamen. Siehe fuer Goetter auch bei wizplayerp.
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp,
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/

/*
FUNKTION: spielerratp
DEKLARATION: int spielerratp(object ob|string name)
BESCHREIBUNG:
Liefert einen Wert ungleich 0, wenn es sich bei dem Objekt ob bzw. dem Spieler
mit dem Namen name um ein Mitglied des Spielerrates handelt, sonst 0.
VERWEISE: newbiep, hlpp, wizp, guestp, learnerp, gesellep, vogtp, lordp,
          adminp, testplayerp, spielerratp, wizplayerp
GRUPPEN: level
*/
