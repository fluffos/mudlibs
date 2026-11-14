// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/debug.h
// Description: Debug-Messages-Handling
// Author:      Francis
//
// $Log: debug.h,v $
// Revision 1.5  2001/08/30 08:28:58  freaky
// typos in der Doku gefixed.
//
// Revision 1.4  2001/08/28 01:49:58  gnomi
// Neue Defines DEBUGX und DEBUGTX mitsamt Dokumentation von Pulami eingebaut.
// Define DEBUG abgeaendert, so dass es send_message_to nutzt.
//
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef DEBUG_H
#define DEBUG_H 1
/*
 * debug.h
 *
 * Beispiel:
 *
 * #define DEBUGGER "francis"
 * #include "debug.h"
 *
 * ....
 *
 * DEBUG(object_name()+": soeinpechaberauch\n");
 *
 * ....
 *
 * Zum Ausschalten der Debugmeldungen einfach DEBUGGER auf 0 setzen.
 *
 */


#ifdef DEBUGGER

#include "message.h"

// So umgehen wir die extra-Abfrage ob find_player 0 ist,
// da Nullen im Array automatisch uebergangen werden...
#   define DEBUG(x)     ({find_player(DEBUGGER)})->send_message_to(\
				find_player(DEBUGGER), \
				MT_DEBUG, MA_UNKNOWN, \
				wrap(x));
#   define DEBUGX(x) \
    funcall((:\
        if($2)\
            $2->send_message_to($2,MT_DEBUG,MA_UNKNOWN,wrap(sprintf("x=%O",$1)));\
	return $1;\
        :),x,find_player(DEBUGGER))
#   define DEBUGTX(text,x) \
    funcall((:\
        if($2)\
            $2->send_message_to($2,MT_DEBUG,MA_UNKNOWN,wrap(sprintf("%s%O",text,$1)));\
	return $1;\
        :),x,find_player(DEBUGGER))
#else
#   define DEBUG(x) 	{}
#   define DEBUGX(x)    (x)
#   define DEBUGTX(text,x)    (x)
#endif

#endif // DEBUG_H

// --- Doku ---------------------------------------------------------------

/*
FUNKTION: DEBUG
DEKLARATION: void DEBUG(string text)
BESCHREIBUNG:
Debugging-Funktion, die wrap(text) an einen zuvor per #define DEBUGGER
definierten Programmierer per send_message_to() ausgibt.

Wenn DEBUGGER nicht vor #include "debug.h" definiert oder nicht anwesend
ist, macht DEBUG() nichts.


Beispiel:

#define DEBUGGER "francis"
#include "debug.h"

...

DEBUG(object_name()+": soeinpechaberauch\n");


Besonderheit: DEBUG() wird im Define schon mit einem Strichpunkt
abgeschlossen, man kann ihn also weglassen.
VERWEISE: DEBUGX, DEBUGTX
GRUPPEN: debugging
*/

/*
FUNKTION: DEBUGX
DEKLARATION: unknown DEBUGX(unknown expr)
BESCHREIBUNG:
Debugging-Funktion, die den Ausdruck expr berechnet und an einen zuvor per
#define DEBUGGER definierten Programmierer per send_message_to() ausgibt
und den berechneten Wert zurueckgibt.

Wenn DEBUGGER nicht vor #include "debug.h" definiert oder nicht anwesend
ist, liefert DEBUGX(expr) einfach nur expr.

Enthaelt expr Anfuehrungszeichen (" oder '), so bekommt man eine
Fehlermeldung. In diesem Falle kann man DEBUGTX() verwenden.

Beispiel:

--- Schnipp! --------------------------------------------------------------

// Das Define muss vor dem Include stehen!
#define DEBUGGER "pulami"
#include "debug.h"

void zaehle_hoch(int i)
{
    DEBUG("--- Neuer Aufruf von zaehle_hoch() ---");
    DEBUGX(i);
    if(DEBUGX(i<3))
        call_out("zaehle_hoch",DEBUGX(1+random(2)),i+1);
    else
    {
        if(DEBUGX(this_player()))
            this_player()->send_message_to(this_player(),MT_NOTIFY,MA_UNKNOWN,
					   "Fertig!\n");
        destruct(DEBUGX(this_object()));
    }
}

void create()
{
    zaehle_hoch(1);
}

--- Schnapp! --------------------------------------------------------------

Ergibt folgende Ausgabe:

--- Schnipp! --------------------------------------------------------------

--- Neuer Aufruf von zaehle_hoch() ---
i=1
i<5=1
1+random(2)=2
--- Neuer Aufruf von zaehle_hoch() ---
i=2
i<5=1
1+random(2)=1
--- Neuer Aufruf von zaehle_hoch() ---
i=3
i<3=0
this_player()=/obj/player#3 ("pulami")
Fertig!
this_object()=/w/pulami/test ("UID:w:pulami")

--- Schnapp! --------------------------------------------------------------

Dokumentiert man #define DEBUGGER "pulami" aus, dann erhaelt man nur eine
Zeile:
Fertig!
VERWEISE: DEBUG, DEBUGTX
GRUPPEN: debugging
*/

/*
FUNKTION: DEBUGTX
DEKLARATION: unknown DEBUGTX(string text, unknown expr)
BESCHREIBUNG:
Debugging-Funktion, die den Ausdruck expr berechnet und an einen zuvor per
#define DEBUGGER definierten Programmierer per send_message_to() ausgibt
und den berechneten Wert zurueckgibt.

Wenn DEBUGGER nicht vor #include "debug.h" definiert oder nicht anwesend
ist, liefert DEBUGTX(text, expr) einfach nur expr.

DEBUGTX() ist fuer den Fall gedacht, dass expr Anfuehrungszeichen (" oder ')
enthaelt und DEBUGX() eine Fehlermeldung erzeugen wuerde.

Kommentiertes Beispiel:

	fun(DEBUGX(query_name()+"!"));

sollte sowas wie

	query_name()+"!"="peter!"

ergeben, die Anfuehrungszeichen verhindern dies leider. Stattdessen kann man
bei DEBUGTX den Text bis einschliesslich dem "=" angeben:

	fun(DEBUGTX("query_name()+\"!\"=",query_name()+"!"));

liefert das gewuenschte, eher wird man wohl sowas wie

	fun(DEBUGTX("qn+!=",query_name()+"!"))

nehmen und

	qn+!="peter!"

erhalten.
VERWEISE: DEBUG, DEBUGX
GRUPPEN: debugging
*/
