// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /secure/simul_efun/notify_fail.inc
// Description: notify_fail - Handling fuer die Prioritaeten
// Author:      Gnomi (13.07.2001)
//
// $Log: notify_fail.inc,v $
// Revision 1.15  2012-09-12 21:11:38  sorcerer
// Typo in Doku
//
// Revision 1.14  2006/08/29 22:37:18  gnomi
// 0 als notify_fail-Closure-Ergebnis verkraften.
//
// Revision 1.13  2004/04/19 22:20:11  gnomi
// Typ der Argumente ueberpruefen (sofern sicherheitstechnisch erforderlich).
//
// Revision 1.12  2003/11/06 23:11:06  gnomi
// Goetteranzeige: Closures werden als solche markiert.
//
// Revision 1.11  2003/11/06 04:02:16  gnomi
// Closures werden fuer Goetter jetzt auch richtig behandelt.
//
// Revision 1.10  2003/09/24 01:14:14  gnomi
// Goetter koennen sich alle notify_fails ausgeben lassen.
//
// Revision 1.9  2002/03/23 19:41:46  sissi
// notifyfail doku geaendert
//
// Revision 1.8  2001/11/19 19:19:25  freaky
// weiteres Flag, mit dem man bestimmen kann, ob bestehende notify-fails
// ueberschrieben werden sollen oder nicht.
//
// Revision 1.7  2001/11/18 01:10:05  gnomi
// Doku korrigiert.
//
// Revision 1.6  2001/07/20 21:35:43  gnomi
// Bugfix: Prio-Array ordentlich initialisieren.
//
// Revision 1.5  2001/07/13 21:56:13  gnomi
// command_start auch fuer Lebewesen aktivieren.
//
// Revision 1.4  2001/07/13 00:34:08  gnomi
// notify_fail mit Prioritaeten eingefuehrt.
//

#pragma strict_types
#pragma save_types

#include <notify_fail.h>

int *prios = ({});

void command_start()
{
    if(!extern_call() || living(previous_object()))
    {
        int csd;
        csd=efun::command_stack_depth();
        if(sizeof(prios)>=csd)
            prios=prios[0..csd-2]+({FAIL_NOT_CMD});
        else
            prios=prios+({FAIL_NOT_CMD})*(csd-sizeof(prios));
    }
}

varargs int notify_fail(mixed fail, int priority, int dont_overwrite)
{
    int csd;
    
    if(wizp(this_player()) && this_player()->query_show_all_fails())
    {
	mixed str = query_notify_fail() || "";
	string ps;
	
	if(!stringp(fail) && !closurep(fail))
	    raise_error("Bad argument 1 to  notify_fail()\n");
	
	if(fail==str || (stringp(fail) && stringp(str) && !strstr(str,fail)))
	    return 0;
	
	switch(priority)
	{
	    case FAIL_NOT_CMD: ps="(FAIL_NOT_CMD"; break;
	    case FAIL_NOT_OBJ: ps="(FAIL_NOT_OBJ"; break;
	    case FAIL_WRONG_ARG: ps="(FAIL_WRONG_ARG"; break;
	    case FAIL_INTERNAL: ps="(FAIL_INTERNAL"; break;
	    default: ps=sprintf("(%d",priority); break;
	}
	if(dont_overwrite)
	    ps+=", dont_overwrite)";
	else
	    ps+=")";
	
	if(closurep(fail) || closurep(str))
	    return efun::notify_fail(
		lambda(({'cg}),
		    ({#'+, ({#'funcall, str, 'cg}),
		      ({#'wrap_say,
		         (previous_object()==this_object())?
			    (object_name(previous_object(1))+" (parse_com, Closure):"):
			    (object_name(previous_object())+" (Closure):"),
			 ({#'+,
			   ({#'regreplace, ({#'||, ({#'funcall, fail, 'cg}), "0"}), "\n", " ", 1}),
			   ps
		     })})})));

	return efun::notify_fail(str+wrap_say(
	    (previous_object()==this_object())?
		(object_name(previous_object(1))+" (parse_com):"):
		(object_name(previous_object())+":"),
	    regreplace(fail, "\n", " ", 1) + ps));
    }

    csd=efun::command_stack_depth();
    if(csd)
    {
        if(sizeof(prios)<csd)
#ifdef TestMUD        
            raise_error("Prioritaeten wurden nicht korrekt initialisiert.\n");
#else
            command_start();
#endif
	if (dont_overwrite)
	{
	    if (prios[csd-1] >= priority)
		return 0;
	}
	else
	{
	    if (prios[csd-1] > priority)
		return 0;
	}
        prios[csd-1]=priority;
    }
    set_this_object(previous_object());
    return efun::notify_fail(fail);
}

/*
FUNKTION: notify_fail
DEKLARATION: varargs int notify_fail(mixed fail, int priority, int dont_overwrite)
BESCHREIBUNG:
Mit notify_fail() wird eine Fehlermeldung gesetzt, die der Spieler
anstelle der Standardmeldung "Wie bitte?" bekommt, wenn die Ausfuehrung
eines seiner Kommandos fehlschlaegt.

Anstatt eines Strings kann auch eine Closure benutzt werden. Diese wird 
ausgewertet, unmittelbar bevor der Spieler die Meldung erhaelt.
Sie erhaelt den Befehlsgeber als Argument.

In priority gibt man die Prioritaet der Meldung an. Dafuer gibt es folgende
Konstanten in notify_fail.h:

  FAIL_NOT_CMD:   Dieses Objekt definiert dieses Kommando eigentlich gar nicht,
                  hat aus technischen Gruenden dies Aktion aber trotzdem oder
                  will einfach nur dafuer sorgen, dass kein "Wie bitte?" kommt:
                  Beispiel: "oeffne brot"

  FAIL_NOT_OBJ:   Das Objekt definiert zwar dieses Kommando ist aber
                  offensichtlich nicht gemeint. (Dies ist die Voreinstellung)
                  Beispiel: "trink tee", wenn das Objekt aber Wein ist.

  FAIL_WRONG_ARG: Das Objekt definiert dieses Kommando, koennte auch gemeint
                  sein, die Argumente stimmen aber nicht.
                  Beispiel: "schliesse tuer mit brot auf"

  FAIL_INTERNAL:  Die Argumente stimmen, aber aus internen Gruenden
                  funktioniert es nicht.
                  Beispiel: "schliesse tuer mit schluessel auf", die Tuer
                            ist aber schon offen.

Es wird die zuletzt gesetzte Meldung mit der hoechsten Prioritaet ausgegeben.

Nach Moeglichkeit sollte ein Kommando
        notify_fail(meldung); return 0;
    anstatt von
        write(meldung); return 1;
    benutzen, da dann andere Objekte das Kommando auch noch auswerten koennen.

notify_fail() liefert immer 0 als Returnwert. Man kann also auch schreiben:
    return notify_fail(meldung);

Hinweis: Obwohl notify_fail mit notify_ anfaengt, ist es kein Controller.

VERWEISE: add_action, query_verb, query_notify_fail
GRUPPEN: simul_efun, grundlegendes, player
*/
