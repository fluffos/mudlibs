// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/ueberfall.h
// Description:	Makro UEBERFALL(angreifer,opfer), damit man nicht diesen
//		Riesenwust von Sissi in jeden Angriff einbauen muss :).
// Author:	Monty Fri Mar 15 09:15:00 MET 1996
//
// $Log: ueberfall.h,v $
// Revision 1.3  2003/06/22 02:08:04  gnomi
// Doku korrigiert.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef UEBERFALL_H
#define UEBERFALL_H 1

#include "config.h" 	// Geht immer, da config.h in #ifndef CONFIG_H ..
			// #endif eingeschachtelt ist.

/*
FUNKTION: ueberfall
DEKLARATION: void ueberfall(object angreifer, object opfer, string fill1, string fill2)
BESCHREIBUNG:

ACHTUNG: Der Ueberdall-Kanal ist derzeit deaktiviert. Daher hat die
         Nutzung des Defines derzeit keine Wirkung.

ueberfall ist ein Define und steht nach einem #include "ueberfall.h" 
zur Verfuegung. Es erzeugt im Ueberfall-Kanal eine Meldung:
'Info: Ueberfall: <name_angreifer> fill1 <name_opfer> fill2.'

BEISPIEL:
    ueberfall(ob1, ob2, "schuettet Saeure ueber", 0);
erzeugt
    Info: Ueberfall: Monty schuettet Saeure ueber Sissi.
bei allen, die den entsprechenden Kurierkanal angeschaltet haben. Dabei muss
allerdings ob1 ein Objektzeiger auf Monty und ob2 ein Objektzeiger auf Sissi
sein.
VERWEISE: notify_attack
GRUPPEN: kampf
*/
#define UEBERFALL(angreifer,opfer,fill1,fill2)\
	if (playerp(angreifer) && playerp(opfer) && \
	  !environment(opfer)->query_type("arena"))\
	    EVENT_MASTER->event("Ueberfall", angreifer, "Info: Ueberfall: "+\
		capitalize(angreifer->query_real_name())+" "+\
		(fill1?fill1+" ":"")+\
		capitalize(opfer->query_real_name())+\
		(fill2?" "+fill2:"")+".\n");

#endif // UEBERFALL_H
