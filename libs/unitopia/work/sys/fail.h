// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/fail.h
// Description: Nuetzliche Makros fuer die Befehlsbearbeitung.
// Author:      Pulami (14.01.2003)
//
// $Log: fail.h,v $
// Revision 1.5  2013/06/26 19:06:21  sorcerer
// Singular/Plural bei FAIL_FAR
//
// Revision 1.4  2008/01/15 07:43:41  gnomi
// FAIL_FAR von Pulami eingebaut.
//
// Revision 1.3  2005/08/28 21:14:14  gnomi
// FAIL_CANNOT_SEE: temporaere Variablen umbenannt, um die "Variable shadows
// previous declaration"-Warnungen zu vermeiden.
//
// Revision 1.2  2005/04/10 01:32:46  gnomi
// Typo.
//
// Revision 1.1  2003/01/17 01:48:11  gnomi
// Defines von Pulami.
//

#ifndef FAIL_H
#define FAIL_H

#include "notify_fail.h"
#include "parse_com.h"

/*
FUNKTION: FAIL_GHOST
DEKLARATION: FAIL_GHOST(string text)
BESCHREIBUNG:
Bricht die Befehlsbearbeitung mit dem notify_fail()-Text text ab, wenn TP
ein Geist ist.

Ist text==0, so wird statt dessen "Als Geist ist dir das leider nicht
moeglich." verwendet.

Beispiele:

    FAIL_GHOST(0)
        -> "Als Geist ist dir das leider nicht moeglich."

    FAIL_GHOST("Nicht als Geist!")
        -> "Nicht als Geist!"
VERWEISE: FAIL_CANNOT_SEE, FAIL_FAR, FAIL_FREE_HANDS, FAIL_GHOST, FAIL_NOT_IN_TP, FAIL_NOT_ME
GRUPPEN: befehle
*/
#define FAIL_GHOST(text)\
    do {\
	if(this_player()->query_ghost())\
    	    return notify_fail(wrap(text ||\
        	"Als Geist ist dir das leider nicht moeglich."\
        	), FAIL_INTERNAL); \
    } while(0)

/*
FUNKTION: FAIL_FREE_HANDS
DEKLARATION: FAIL_FREE_HANDS(int anzahl, string text)
BESCHREIBUNG:
Bricht die Befehlsbearbeitung mit dem notify_fail()-Text text ab, wenn TP
nicht mindestens anzahl freie Haende hat.

Ist text==0, so wird statt dessen "Dazu brauchst du "+anzahl+" freie
Hand/Haende." verwendet.

Beispiele:

    FAIL_FREE_HANDS(1, 0)
        -> "Dazu brauchst du eine freie Haende."

    FAIL_FREE_HANDS(2, "Zwei Griffel solltest du dafuer schon frei haben.")
        -> "Zwei Griffel solltest du dafuer schon frei haben."
VERWEISE: FAIL_CANNOT_SEE, FAIL_FAR, FAIL_FREE_HANDS, FAIL_GHOST, FAIL_NOT_IN_TP, FAIL_NOT_ME
GRUPPEN: befehle, haende
*/
#define FAIL_FREE_HANDS(anzahl, text)\
    do { \
	if(this_player()->query_num_free_hands()<anzahl)\
    	    return notify_fail(wrap(text ||\
        	"Dazu brauchst du "+\
        	(anzahl==1 ? "eine freie Hand." : anzahl+" freie Haende.")\
        	), FAIL_INTERNAL); \
    } while(0)
		

/*
FUNKTION: FAIL_NOT_ME
DEKLARATION: FAIL_NOT_ME(mixed mxd, string text)
BESCHREIBUNG:
Bricht die Befehlsbearbeitung mit dem notify_fail()-Text text ab, wenn
mxd!=TO ist.

Ist text==0, so wird statt dessen "Das geht mit "+einem(mxd)+" nicht."
verwendet.

Beispiele:

    FAIL_NOT_ME(mxd, 0)
        mxd ist eine Axt -> "Das geht mit einer Axt nicht."

    FAIL_NOT_ME(mxd, "Wie willst du das mit "+einem(mxd)+" machen?")
        mxd ist eine Axt -> "Wie willst du das mit einer Axt machen?"
VERWEISE: FAIL_CANNOT_SEE, FAIL_FAR, FAIL_FREE_HANDS, FAIL_GHOST, FAIL_NOT_IN_TP, FAIL_NOT_ME
GRUPPEN: befehle
*/
#define FAIL_NOT_ME(mxd, text)\
    do { \
	if(mxd!=this_object())\
    	    return notify_fail(wrap(text ||\
        	"Das geht mit "+einem(mxd)+" nicht."\
        	), FAIL_NOT_OBJ); \
    } while(0)

/*
FUNKTION: FAIL_NOT_IN_TP
DEKLARATION: FAIL_NOT_IN_TP(mixed mxd, string text)
BESCHREIBUNG:
Bricht die Befehlsbearbeitung mit dem notify_fail()-Text text ab, wenn mxd
ein Objekt und ENV(mxd)!=TP ist.

Ist text==0, so wird statt dessen "Du musst "+den(mxd)+" erst nehmen."
verwendet.

Beispiele:

    FAIL_NOT_IN_TP(mxd, 0)
        mxd ist eine Axt -> "Du musst die Axt erst nehmen."

    FAIL_NOT_IN_TP(mxd, "Nimm "+den(mxd)+" doch erstmal.")
        mxd ist eine Axt -> "Nimm die Axt doch erstmal."
VERWEISE: FAIL_CANNOT_SEE, FAIL_FAR, FAIL_FREE_HANDS, FAIL_GHOST, FAIL_NOT_IN_TP, FAIL_NOT_ME
GRUPPEN: befehle
*/
#define FAIL_NOT_IN_TP(mxd, text)\
    do { \
	if(objectp(mxd) && environment(mxd)!=this_player())\
    	    return notify_fail(wrap(text ||\
        	"Du musst "+den(mxd)+" erst nehmen."\
        	), FAIL_INTERNAL); \
    } while(0)

/*
FUNKTION: FAIL_CANNOT_SEE
DEKLARATION: FAIL_CANNOT_SEE(mixed mxd, string text)
BESCHREIBUNG:
Bricht die Befehlsbearbeitung mit dem notify_fail()-Text text ab, wenn TP
mxd nicht sehen kann.

Ist text==0, so wird statt dessen der Rueckgabewert von TP->cannot_see()
verwendet.

Beispiele:

    FAIL_CANNOT_SEE(mxd, 0)
        Z. B. "Es ist zu dunkel."

    FAIL_CANNOT_SEE(mxd, "Dunkelheit umgibt Deine Augen.")
        "Dunkelheit umgibt Deine Augen."
VERWEISE: FAIL_CANNOT_SEE, FAIL_FAR, FAIL_FREE_HANDS, FAIL_GHOST, FAIL_NOT_IN_TP, FAIL_NOT_ME
GRUPPEN: befehle
*/
#define FAIL_CANNOT_SEE(mxd, text)					\
    do {								\
        mixed _fail_h_ob=mxd;						\
	string _fail_h_str; 						\
        while(mappingp(_fail_h_ob))					\
            _fail_h_ob=_fail_h_ob["environment"];			\
        _fail_h_str=this_player()->cannot_see(_fail_h_ob);		\
        if(_fail_h_str)							\
            return notify_fail(wrap(text || _fail_h_str), FAIL_INTERNAL);\
    } while(0)

/*
FUNKTION: FAIL_FAR
DEKLARATION: FAIL_FAR(mixed mxd, string text)
BESCHREIBUNG:
Bricht die Befehlsbearbeitung mit dem notify_fail()-Text text ab, wenn mxd
zu weit entfernt ist.

Ist text==0, so wird statt dessen der entsprechende Rueckgabewert von 
"far" bzw. query_far(), sofern dies eine Zeichenkette ist, ansonsten 
Der(mxd)+" ist viel zu weit weg." verwendet.

Beispiele:

    FAIL_FAR(mxd, 0)
        mxd ist ein Stern -> "Der Stern ist viel zu weit weg."

    FAIL_FAR(mxd, Der(mxd)+" ist viel zu weit weg, um "+ihn(mxd)+
        " zu nehmen")
        mxd ist ein Stern
            -> "Der Stern ist viel zu weit weg, um ihn zu nehmen."
VERWEISE: FAIL_CANNOT_SEE, FAIL_FAR, FAIL_FREE_HANDS, FAIL_GHOST, FAIL_NOT_IN_TP, FAIL_NOT_ME
GRUPPEN: befehle
*/
#define FAIL_FAR(mxd, text)\
    do {\
        mixed _fail_h_far=QUERY("far", mxd);\
        if(_fail_h_far)\
            return notify_fail(wrap(\
                text ||\
                (stringp(_fail_h_far) ? _fail_h_far : 0) ||\
                Der(mxd)+" "+ist(mxd)+" viel zu weit weg."\
                ), FAIL_INTERNAL);\
    } while(0)

#endif // FAIL_H
