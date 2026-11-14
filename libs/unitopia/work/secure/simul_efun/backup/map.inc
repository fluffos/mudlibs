// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/map.inc
// Description:	Map-Handling Funktionen
// Author:	Freaky, Francis
// Modified by:	Freaky (16.06.1998) rename_allowed eingebaut
// $Log: map.inc,v $
// Revision 1.19  2014/01/15 21:50:10  gnomi
// domain2map: Vorher pruefen, ob das wirklich ein Map-Dateiname sein kann.
//
// Revision 1.18  2012-11-16 18:02:35  gnomi
// touch() bei Goettern mit 500.000 Evals ausfuehren.
//
// Revision 1.17  2009-01-15 09:22:10  gnomi
// Typo.
//
// Revision 1.16  2007/12/05 11:20:36  gnomi
// write() via call_other aufrufen, damit sefun-Ueberlagerung greift.
//
// Revision 1.15  2003/05/30 12:22:46  freaky
// Hilfs-Funktionen eingefuehrt fuer das set_this_ob Problem
//
// Revision 1.14  2002/06/16 21:08:19  gnomi
// Typo.
//
// Revision 1.13  2002/06/15 16:00:19  gnomi
// is_direction: Behandlung von DIR_NUR_HIMMELSRICHTUNG korrigiert.
//
// Revision 1.12  2002/05/20 13:30:02  sissi
// Da MAP_OB->get_map_file_name mittlerweile ein .c an den Dateinamen
// dranhaengt, muss domain2map diesen nun wieder entfernen.
//
// Revision 1.11  2002/03/25 21:59:51  gnomi
// Enzy-Doku opposite_direction: Deklaration korrigiert.
//
// Revision 1.10  2002/02/26 07:04:06  gnomi
// Neue Hilfsfunktionen zur Verarbeitung von Richtungsangaben eingebaut.
//
// Revision 1.9  2001/08/16 23:23:18  gnomi
// Hinweis: Misserfolg: 0
//
// Revision 1.8  2001/08/10 21:33:37  gnomi
// Flags von touch dokumentiert.
//
// Revision 1.7  2000/12/28 05:00:48  gnomi
// touch("/") liefert nun 0 (und keinen RTE).
//
// Revision 1.6  2000/12/13 21:03:13  gnomi
// Beschreibung von map2domain (Bedeutung des flags) korrigiert.
//
// Revision 1.5  2000/08/29 14:27:26  freaky
// file_name() nach object_name() umgebaut.
// filter_array() nach filter() umgebaut.
// map_array() nach map() umgebaut.
// (also alles an die neuen Efuns angepasst)
//
// Revision 1.4  2000/06/18 16:20:52  freaky
// touch: set_this_object() wurde nicht rueckgaengig gemacht
//
// Revision 1.3  2000/06/18 16:05:03  freaky
// Das virtual-compiler Zeugs wird jetzt einfach im Master aufgerufen
// master::compile_object() regelt das jetzt vollstaendig
//

#pragma strict_types
#pragma save_types

/*
FUNKTION: domain2map
DEKLARATION: string domain2map(string file_name)
BESCHREIBUNG:
Ein Map-Raum innerhalb einer Domain ist durch seine lokalen
Koordinaten gekennzeichnet:

/d/Domain/mx_y
/d/Domain/mitglied/mx_y
/d/Domain/mitglied/bereich/mx_y

Sobald sie in der Map geladen werden, bekommen sie einen File-Namen mit
absoluten Koordinaten:

/map/mx_y

Mit dieser Routine kann der Map-File-Name eines Domain-Files erfragt werden.

Beispiel:
    domain2map("/d/Arktis/uluji/schelfweg/m0_4") --> "/map/m3_1024"

GRUPPEN: simul_efun, map
VERWEISE: map2domain
*/
string domain2map(string name)
{
    string sTemp;
    if (name && regmatch(name, "^/d/.*/m[-0-9]*_[-0-9]*(\\.c|)$"))
    {
        sTemp = ({string})MAP_OB->get_map_file_name(name);
        if (sTemp && (sTemp[<2..] == ".c"))
            return sTemp[..<3];
        else
            return sTemp;
    }
}

/*
FUNKTION: map2domain
DEKLARATION: string map2domain(string file_name, int flag)
BESCHREIBUNG:
Ein Map-Raum innerhalb einer Domain ist durch seine lokalen
Koordinaten gekennzeichnet:

/d/Domain/mx_y
/d/Domain/mitglied/mx_y
/d/Domain/mitglied/bereich/mx_y

Sobald sie in der Map geladen werden, bekommen sie einen File-Namen mit
absoluten Koordinaten:

/map/mx_y

Mit dieser Routine kann der Domain-File-Name eines Map-Files erfragt werden.
Gibt es die Datei nicht, so wird 0 zurueckgegeben, es sei denn flag==1, 
dann wird naemlich der berechnete Dateiname zurueckgeliefert.

Beginnt der Dateiname nicht mit einem /, so wird das Ergebnis auch nicht
mit einem ebensolchen beginnen.

Beispiel:
    map2domain("/map/m3_1024")   --> "/d/Arktis/uluji/schelfweg/m0_4.c"
    map2domain("map/m3_1024")    --> "d/Arktis/uluji/schelfweg/m0_4.c"
    map2domain("/map/m3_1025")   --> 0
    map2domain("/map/m3_1025",1) --> "/d/Arktis/m503_25.c"

GRUPPEN: simul_efun, map
VERWEISE: domain2map
*/
varargs string map2domain(string name, int flag)
{
    int x, y, noslash;
    string file;

    if (sscanf(name,"/map/m%d_%d",x,y) != 2)
	if (sscanf(name,"map/m%d_%d",x,y) != 2)
	    return 0;
	else
	{
	    noslash = 1;
	    // sys_log("MAP",sprintf("map2domain: no-slash: name:%O flag:%O PO:%O PO2:%O\n",name,flag,previous_object(),previous_object(2)));
	}
    file = ({string})MAP_OB->query_map_file_name(x,y);
    if (flag || (file && file_size(file) > 0))
	return (noslash && file) ? file [1..] : file;
}

/*
FUNKTION: map_object
DEKLARATION: int map_object(string file_name)
BESCHREIBUNG:
Liefert 1, wenn es sich bei dem Raum 'file_name' um einen Map-Raum handelt.
(z.B. bei /map/m1_1 oder auch bei /d/Doerrland/m0_0)
GRUPPEN: simul_efun, map
VERWEISE: 
*/
int map_object(string str)
{
    string *path;
    int x,y;

    path = explode(str,"/")-({""});
    return ((path[0] == "d" || path[0] == "map") &&
	    sscanf(path[<1],"m%d_%d",x,y) == 2);
}

// Damit das set_this_object wieder vorbei ist nach dem load_object
private object load_object_set_this_object(string ob, object po)
{
    set_this_object(po);
    return load_object(ob);
}

/*
FUNKTION: touch
DEKLARATION: object touch(string|object ob [,int flag] )
BESCHREIBUNG:
Laedt einen File und gibt bei Erfolg einen Pointer darauf zurueck,
bei Misserfolg 0.

Im Prinzip macht load_object(file) dasselbe, jedoch kann
damit im Gegensatz zum touch() kein Map-Raum geladen werden!

Folgende Flags sind in /sys/touch.h definiert und koennen
mittels | (binaeres Oder) kombiniert werden:

  NO_LOG     Es gibt keinen Eintrag in der FDB, wenn diese Datei
             nicht geladen werden konnte.
  NO_WRITE   Es gibt keine Meldung an this_player, wenn diese Datei
             nicht geladen werden konnte.

Beispiel:
        touch("/d/Vaniorh/uluji/jetty");
        touch("/map/m24_644");

GRUPPEN: simul_efun, objekt
VERWEISE: clone_object
*/
private object limited_touch(string ob, int flag, object previous)
{
    object ret, to;
    string *path;
    int x, y;

    path = explode(ob,"/") - ({""});

    if (!sizeof(path))
        return 0;

    /* Map-Raum */
    if ((path[0] == "d" || path[0] == "map") &&
	    sscanf(path[<1],"m%d_%d",x,y) == 2)
	if (path[0] == "map" && (ret=find_object(ob)))
	    return ret;
	else
	    return ({object})MAP_OB->create_map_object(ob);

    if (ret = find_object(ob))
	return ret;

    if (path[<1][<2..] != ".c")
	path[<1] += ".c";
    ob = "/" + implode(path,"/");

#if 0
    if (find_player("freaky"))
	tell_object(find_player("freaky"),sprintf("@@ Touch:ob:%O:\n",ob));
#endif

    if (file_size(ob) > 0)		/* Normales Objekt */
    {
	/*
	to = this_object();
	set_this_object(previous_object());
	ret = load_object(ob);
	set_this_object(to);
	return ret;
	*/
	return funcall(#'load_object_set_this_object,ob,previous);
    }
    else if (sizeof(path) > 1)		/* Virtual-Compiler starten */
    {
	ret = ({object})MASTER_OB->compile_object(ob);
	if (ret)
	{
	    // Freaky: damit es keinen Aerger gibt :(
	    if ((object_name(ret) + ".c") != ob)
		rename_object(ret,ob);
	    return ret;
	}
    }

    /* Objekt wurde nicht geladen */

    if (!(flag & NO_LOG) && !wizp(this_player()))
    {
	if (this_player() && environment(this_player()))
	    MASTER_OB->do_log_error("touch: "+ob+" nicht gefunden in "+
		object_name(environment(this_player()))+".\n",
		__FILE__,
		object_name(environment(this_player())),__LINE__);
	else if (previous)
	    MASTER_OB->do_log_error("touch: "+ob+" nicht gefunden. caller: "+
		object_name(previous)+".\n",
		__FILE__,
		object_name(previous),__LINE__);
	else
	    MASTER_OB->do_log_error("touch: "+ob+" nicht gefunden. Kein "
		"this_player() und kein previous_object().\n",
		__FILE__,__FILE__,__LINE__);
    }

    if (!(flag & NO_WRITE))
	if (this_player())
	    if (wizp(this_player()))
		this_object()->write("touch: "+ob+" nicht gefunden.\n"); 
	    else
		this_object()->write("Da hat sich wohl ein Loch im Raum-Zeit-Gefuege "
		      "aufgetan.\n");
}

varargs object touch(mixed ob, int flag)
{
    // Wird vom Move meist uebergeben
    if (objectp(ob))
	return ob;

    // Wird wohl auch oft mit '0' aufgerufen :(
    if (!stringp(ob))
	return 0;

    // Wir lassen nur Filenamen zu.
    if (ob[0] != '/')
	return 0;

    if(playerp(this_player()) && this_player()->query_wiz_level() &&
       get_eval_cost() > 500000)
        return limited(#'limited_touch, ({500000}), ob, flag, previous_object());
    else
        return limited_touch(ob, flag, previous_object());
}

static mapping DIRS = ([
    "n" : "norden",
    "no": "nordosten",
     "o": "osten",
    "so": "suedosten",
    "s" : "sueden",
    "sw": "suedwesten",
     "w": "westen",
    "nw": "nordwesten",
    "h" : "hoch",
    "r" : "runter",
    "a" : "ausgang",
    ]);

static string *OPP = ({"suedwesten", "nordosten", "westen", "osten",
                       "nordwesten", "suedosten", "norden", "sueden",
		       "hoch", "runter", "rein", "raus",
		       "ausgang", "betrete", });
#define HIMMELSRICHTUNGEN	8

/*
FUNKTION: expand_direction
DEKLARATION: varargs string expand_direction(string dir, int flags)
BESCHREIBUNG:
Loest Abkuerzungen von Richtungen auf (z.B. expand_direction("no") liefert
"nordosten".) Falls diese Abkuerzung unbekannt ist, wird 0 zurueckgeliefert.
Der zweite Parameter flags kann eine Oder-Kombination aus folgenden
Konstanten (definiert in simul_efuns.h) sein:

    DIR_NUR_HIMMELSRICHTUNGEN   Nur Himmelsrichtungen erweitern.
    DIR_ALS_DEFAULT             Wenn nichts gefunden wurde, dir zurueckliefern.
				
VERWEISE: is_direction, opposite_direction
GRUPPEN: simul_efun, ausgaenge
*/
varargs string expand_direction(string dir, int flags)
{
    return ((!(flags&DIR_NUR_HIMMELSRICHTUNGEN) ||
	                 member(OPP, DIRS[dir])<HIMMELSRICHTUNGEN) && DIRS[dir]) ||
	((flags&DIR_ALS_DEFAULT) && dir);
}
 
/*
FUNKTION: is_direction
DEKLARATION: varargs int is_direction(string dir, int flags)
BESCHREIBUNG:
Liefert 1, wenn der erste Parameter dir eine Richtung ist, sonst 0.
Der zweite Parameter flags kann eine Oder-Kombination aus folgenden
Konstanten (definiert in simul_efuns.h) sein:

    DIR_NUR_HIMMELSRICHTUNGEN   Nur Himmelsrichtungen beachten
				
VERWEISE: expand_direction, opposite_direction
GRUPPEN: simul_efun, ausgaenge
*/
varargs int is_direction(string dir, int flags)
{
    return (flags&DIR_NUR_HIMMELSRICHTUNGEN)
	?(member(OPP,dir) < HIMMELSRICHTUNGEN && member(OPP,dir) != -1)
	:(member(OPP,dir) != -1);
}
 
/*
FUNKTION: opposite_direction
DEKLARATION: varargs string opposite_direction(string dir, int flags)
BESCHREIBUNG:
Liefert die Richtung, welcher der Richtung im ersten Parameter dir
entgegengesetzt ist. Ist diese Richtung unbekannt, so wird 0 zurueckgeliefert.
Der zweite Parameter flags kann eine Oder-Kombination aus folgenden
Konstanten (definiert in simul_efuns.h) sein:

    DIR_NUR_HIMMELSRICHTUNGEN   Nur bei Himmelsrichtungen beachten.
    DIR_ALS_DEFAULT             Anstatt 0 dir zurueckliefern.
				
VERWEISE: expand_direction, is_direction
GRUPPEN: simul_efun, ausgaenge
*/
varargs string opposite_direction(string dir, int flags)
{
    int i;
    if (((i = member(OPP,dir)) >= 0) &&
	(!(flags&DIR_NUR_HIMMELSRICHTUNGEN) || i<HIMMELSRICHTUNGEN))
        return OPP[i^1];
    return (flags&DIR_ALS_DEFAULT)?dir:0;
}
