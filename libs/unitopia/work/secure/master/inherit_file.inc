// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/inherit_file.inc
// Description:	Regelt den Filenamen bei inherit "..."
// Author:	Freaky (01.12.1999)
// Modified by:	Freaky (13.01.2000) rel_path, search_file eingebaut.
//
// $Log: inherit_file.inc,v $
// Revision 1.26  2012-09-11 12:56:52  sorcerer
// Erben generell nur aus Verzeichnissen mit /i/ im Pfad
//
// Revision 1.25  2012-09-11 09:24:28  sorcerer
// Erben nur aus /i/ fuer diverse Bereiche
//
// Revision 1.24  2012-08-19 18:37:34  sorcerer
// Metamorpher (ver)erben jetzt auch korrekt
//
// Revision 1.23  2011-12-29 17:12:38  sorcerer
// Fehler loggen, wenn noch nicht-i-Erbaktionen erfolgen
//
// Revision 1.22  2011-11-25 22:23:45  sorcerer
// Bardengilde erbt und vererbt nur via i/
//
// Revision 1.21  2010-11-07 12:54:30  sorcerer
// Campus und Midgard erben jetzt auch nur aus /i/
//
// Revision 1.20  2010-10-30 14:25:57  sorcerer
// einige neue gute Inheritors
//
// Revision 1.19  2009-11-19 10:48:09  sorcerer
// Ausnahmen geprueft statt Regelkonformitaet (GOOD_*->BAD_*)
//
// Revision 1.18  2009-11-19 09:32:54  sorcerer
// Gallien ist GOOD_INHERITEE
//
// Revision 1.17  2009-11-18 20:34:19  sorcerer
// P ist GOOD_INHERITEE
//
// Revision 1.16  2009-11-13 12:46:59  sorcerer
// Gallien ist GOOD_INHERITOR
//
// Revision 1.15  2009-11-10 13:12:09  sorcerer
// P ist GOOD_INHERITOR
//
// Revision 1.14  2009-09-07 22:08:19  gnomi
// Schaerfere Bedingungen fuer einige Bereiche.
//
// Revision 1.13  2001/08/10 18:25:07  freaky
// NO_*-logging ausgebaut.
//
// Revision 1.12  2001/07/21 12:43:43  freaky
// Path-Restrictions aktiviert.
//
// Revision 1.11  2001/03/23 13:19:20  freaky
// Files aus /w duerfen nur von Files aus /w inherited werden.
//
// Revision 1.10  2001/03/21 11:02:07  freaky
// do-log-error: weiteren Parameter eingefuerhrt, mit dem keine Meldung
// an Spieler erzeugt wird.
//
// Revision 1.9  2001/03/21 10:40:57  freaky
// Fehlermeldungen bei illegalen Files verbessert.
//
// Revision 1.8  2001/03/21 10:35:11  freaky
// auch no_load_file() ueberpruefen.
// Fehlermeldung bei illegalem inherit eingebaut.
//
// Revision 1.7  2000/07/19 22:33:43  freaky
// inherit aus .../obj/... zulassen.
//
// Revision 1.6  2000/06/20 00:37:35  freaky
// Es war zu restriktiv, deswegen nicht nur /i/ bzw. /obj/ zulassen
//
// Revision 1.5  2000/06/19 19:03:19  freaky
// no_inherit_file verbessert.
//
// Revision 1.4  2000/06/19 18:11:46  freaky
// no*file-Handling verbessert
//
// Revision 1.3  2000/06/19 17:51:14  freaky
// no_*_file eingebaut
//
// Revision 1.2  2000/06/19 14:16:57  freaky
// Logging fuer inherit .../obj/... eingebaut
//

int no_inherit_file(string file, string compiled_file)
{
    if (no_load_file(file))
	return 1;
    // Files aus /w duerfen nur von Files aus /w inherited werden.
    if (file[0..2] == "/w/" && compiled_file[0..2] != "/w/")
	return 1;
    // /secure/ darf alles (sicherheitshalber).
    if (compiled_file[0..7] == "/secure/")
	return 0;
    // Nur aus /i/ darf man inheriten.
    return strstr(file,"/i/") < 0;
}

mixed inherit_file(string file, string compiled_file)
{
    string ret;

    if (file[0] == '%')
    {
	if (file[1] == '/')
	    ret = file;
	else
	    // Wenn die Klasse mit einem '%' anfaengt, dann suchen.
	    ret = search_file("/i/" + file[1..] + ".c",compiled_file) || file;
    }
    else
	// Sonst relativen Pfad berechnen
	ret = rel_path(file,compiled_file);

    if (no_inherit_file(ret,compiled_file))
	return 1;

    return ret;
}
