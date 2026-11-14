// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/parse_com.h
// Description: Defines fuer parse_com()
// Author:	Francis
//
// $Log: parse_com.h,v $
// Revision 1.13  2015/04/13 19:03:42  gnomi
// Unterstuetzung fuer V-Item-Properties aktiviert.
//
// Revision 1.12  2014/09/12 17:16:11  myonara
// bugfix vom 05.04.2013 wahrsch von Gnomi.
//
// Revision 1.11  2013-04-02 22:23:55  gnomi
// QUERY: Unterstuetzung fuer V-Item-Properties.
//
// Revision 1.10  2013-03-16 16:09:48  gnomi
// QUERY() fragt auch Properties ab.
//
// Revision 1.9  2007/10/24 22:00:03  gnomi
// Doku: Klarstellung zur Typdeklaration der Parameter.
//
// Revision 1.8  2006/06/07 20:37:47  gnomi
// Weniger Einschraenkungen durch Dunkelheit.
//
// Revision 1.7  2005/08/28 00:20:54  gnomi
// Neues Count-Ob-Handling.
//
// Revision 1.6  2003/03/13 23:19:33  gnomi
// QUERY, QUERY_PARS: Variablenclosures keine Parameter uebergeben.
//
// Revision 1.5  2003/02/20 01:09:07  gnomi
// Flag, um invis-15-Sachen zu parsen.
//
// Revision 1.4  2002/12/17 03:48:11  gnomi
// Neues Define HAS_ID, um zu testen, ob ein Objekt/V-Item eine bestimmte Id
// hat.
//
// Revision 1.3  2002/01/14 04:14:38  gnomi
// QUERY: Uebergibt das V-Item als 1. Parameter bei Ausfuehrung einer Closure
// QUERY_PARS: Wie QUERY, erlaubt nur weitere Parameter
// Beide Defines sind nun auch dokumentiert.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef PARSE_COM_H
#define PARSE_COM_H 1

/*
 * Von parse_com zurueckgegebene Return-Codes.
 */

#define PARSE_OK           0	// Alles klar
#define PARSE_NO_ARG       1	// Es wurde nichts uebergeben
#define PARSE_NO_OB        2	// Objekt nicht gefunden
#define PARSE_NO_ALL_OB    3	// Wie 2, aber "alles" war angegeben
#define PARSE_NO_MY_OB     4	// Wie 2, aber "mein" war angegeben
#define PARSE_NO_ALL_MY_OB 5	// Wie 2, aber "mein" und "alles" war angegeben
#define PARSE_WRONG_ID     6	// Unvollstaendige/falsche Objekt-Id angegeben
#define PARSE_NOT_SEARCHED 7	// Nicht gesucht
#define PARSE_NOT_ENOUGH   8    // Countob: Nicht genuegend Elemente da.
#define PARSE_CANT_SEE     9	// "alle" wurde verwendet, kann aber nix sehen.

/*
 * Die einzelnen Felder des Return-Wertes:
 */
#define PARSE_NUM_OBS		0
#define PARSE_OBS		1
#define PARSE_REST		2
#define PARSE_RET_CODE		3
#define PARSE_ID		4
#define PARSE_TRENNER		5
#define PARSE_BEYOND_TRENNER	6

/*
 * Steuer-Flags
 */

// Ist im Kommando kein Zahlwort angegeben
// (1. 2. ..), sollen ALLE passenden Objekte
// zurueckgegeben werden, nicht nur das erste.
#define PARSE_ALL_MATCHES		0x01

// Keine Virtuellen Objekte suchen
#define PARSE_NO_V_ITEMS		0x02

#define PARSE_AFTER_TRENNER		0x04

#define PARSE_NOT_WITHOUT_TRENNER	0x08

#define PARSE_NOSHIMMER_INVIS		0x10

#define PARSE_DONT_SPLIT		0x20

/*
 * Fuer virtuelle Objekte
 */

/*
FUNKTION: QUERY
DEKLARATION: QUERY(string what, object ob|mapping vitem)
BESCHREIBUNG:
Fragt die Eigenschaft what des Objektes ob oder V-Items vitem ab.
Beim Objekt wird ob->query_<what>() aufgerufen, beim V-Item wird
vitem[what] ausgewertet. Falls letzteres eine Closure ist, so wird
sie mit dem V-Item als 1. Parameter ausgefuehrt und dessen Ergebnis geliefert.

Die als Objekt uebergebene Variable muss vom Typ mixed sein, ansonsten gibt
es einen Compile-Fehler.
VERWEISE: QUERY_PARS, query_v_item, parse_com
GRUPPEN: virtuell
*/
// Variablenclosures moegen keine Parameter... :-(
#define QUERY(x,ob) (mappingp(ob)								\
	?((closurep((ob)[x])&&get_type_info((ob)[x],1)==2)					\
	    ?funcall((ob)[x]):member((x),':')>=0						\
	        ?(ob)["v_item_master"]->query_v_item_property((ob),(x)):funcall((ob)[x],ob))	\
	:(call_other(ob,"query_"+(x)) || call_other(ob, "query", (x))))
/*
FUNKTION: QUERY_PARS
DEKLARATION: QUERY_PARS(string what, object ob|mapping vitem, mixed *parameter)
BESCHREIBUNG:
Fragt die Eigenschaft what des Objektes ob oder V-Items vitem ab.
Beim Objekt wird ob->query_<what>(parameter) aufgerufen, wobei die Elemente aus
parameter als einzelne Parameter uebergeben werden. Beim V-Item wird
vitem[what] ausgewertet. Falls letzteres eine Closure ist, so wird
sie mit dem V-Item als 1. Parameter und den Elementen aus parameter als weitere
Parameter ausgefuehrt und dessen Ergebnis geliefert.

Die als Objekt uebergebene Variable muss vom Typ mixed sein, ansonsten gibt es
einen Compile-Fehler.
VERWEISE: QUERY, query_v_item, parse_com
GRUPPEN: virtuell
*/
// Variablenclosures moegen keine Parameter... :-(
#define QUERY_PARS(x,ob,pars) (mappingp(ob)									\
	?((closurep((ob)[x])&&get_type_info((ob)[x],1)==2)							\
	    ?funcall((ob)[x]):member((x),':')>=0									\
	        ?(ob)["v_item_master"]->query_v_item_property((ob),(x),(pars)):apply((ob)[x],(ob),(pars)))	\
	:(apply(#'call_other,ob,"query_"+(x),(pars)) || apply(#'call_other,ob,"query",(x),(pars))))

/*
FUNKTION: HAS_ID
DEKLARATION: int HAS_ID(object ob|mapping vitem, string id)
BESCHREIBUNG:
Liefert 1 zurueck, wenn das Objekt ob bzw. das V-Item vitem auf die ID id
reagieren, ansonsten 0. Die als Objekt uebergebene Variable muss vom Typ
mixed sein, ansonsten gibt es einen Compile-Fehler.
VERWEISE: id, QUERY, QUERY_PARS, query_v_item, parse_com
GRUPPEN: virtuell
*/
#define HAS_ID(ob,x) (mappingp(ob)?(member((ob)["id"]||({(ob)["name"]}),x)>=0):(ob)->id(x))

/*
 * Synonyme fuer "alle"
 */
#define ALLES ({"alle","alles","allem","allen","jeder","jede","jedes","jedem","jeden"})

#endif // PARSE_COM_H
