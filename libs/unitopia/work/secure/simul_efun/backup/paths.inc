// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/paths.inc
// Description: Path-Handling routinen
// Author:	Monty
// Modified by: Freaky (16.09.94) Optimierung von abs_path
//
// $Log: paths.inc,v $
// Revision 1.15  2006/08/03 09:54:00  gnomi
// Indexing past string end...
//
// Revision 1.14  2006/04/13 06:58:37  gnomi
// Indexing past string end...
//
// Revision 1.13  2003/10/18 15:09:49  sissi
// Bugfix file_path: Liefert jetzt bei Map-Raeumen, die von "der Map"
// erzeugt werden und keinen existierenden Dateinamen haben, auch den
// korrekten Pfad.
//
// Revision 1.12  2003/06/05 00:44:17  gnomi
// set_this_object-Problem mittels bind_lambda umgangen.
//
// Revision 1.11  2002/06/16 22:00:22  gnomi
// Typo in Doku zu abs_path.
//
// Revision 1.10  2002/02/26 07:04:21  gnomi
// Neue Funktion valid_file_name.
//
// Revision 1.9  2002/02/22 08:42:57  gnomi
// search_file: Weiterer Parameter, um bestimmte Dateien auszuschliessen.
//
// Revision 1.8  2002/02/22 03:08:49  gnomi
// Neue Simul-Efun: search_file eingebaut.
//
// Revision 1.7  2001/11/26 22:48:53  gnomi
// Typo.
//
// Revision 1.6  2001/03/12 01:16:54  gnomi
// Typo in Doku zu abs_path
//
// Revision 1.5  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
#pragma save_types

/*
FUNKTION: file_path
DEKLARATION: string file_path([object file])
BESCHREIBUNG:
file_path liefert das Directory zurueck, in dem das File von ob steht. Wenn
ob nicht angegeben wird, dann wird this_object() genommen. Sollte ob ein 
Raum einer Subdomain sein, wird der richtige Pfad der Subdomain errechnet.
VERWEISE: object_name, abs_path
GRUPPEN: simul_efun, file
*/
varargs string file_path(object ob)
{
    string dir;

    if (!ob)
	ob = previous_object();
    dir = (dir = map2domain(object_name(ob),1)) ? dir : object_name(ob);
    return implode(explode(dir, "/")[0..<2], "/");
}

/*
FUNKTION: abs_path
DEKLARATION: string abs_path(string path, [string absolute_path])
BESCHREIBUNG:
abs_path liefert den absoluten Pfad zu dem relativen Pfad path, bezogen auf 
den absoluten Pfad absolute_path zurueck. Hmmm, kompliziert ausgedrueckt...
Wenn absolute_path nicht mit angegeben ist, wird der Pfad genommen, in dem
this_object() steht.

Beispiel: 
    abs_path("../../obj") 
	liefert "/d/Vaniorh/obj", wenn es von einem Objekt in 
	/d/Vaniorh/monty/obj aufgerufen wird.
    abs_path("../../obj","/w/monty/zeug/krempel")
	liefert /w/monty/obj. Vorsicht, der relative Pfad darf nicht 
	mit einem "/" anfangen, wenn abs_path etwas machen soll,
    abs_path("/room/rathaus", "scheiss/egal/was")
	liefert /room/rathaus!

Es wird keinerlei Pruefung auf das Vorhandensein des Pfades gemacht!

VERWEISE: file_path, object_name, search_file
GRUPPEN: simul_efun, file
*/
varargs string abs_path(string path, string absolute)
{
    string *abs, *rel;
    int i;

    if (!path || (absolute && (!sizeof(absolute) || absolute[0] != '/')))
	return 0;
    if (sizeof(path) && path[0] == '/') 
	return path;
    abs = explode(absolute ? absolute : file_path(), "/") - ({".",""});
    rel = explode(path,"/") - ({".",""});
    while(sizeof(rel) > i && rel[i] == "..")
	i++;
    return "/" + implode(abs[0..<i + 1] + rel[i..],"/");
}

/*
FUNKTION: search_file
DEKLARATION: varargs string search_file(string path[, string absolute[, string subdir[, string extension, [string *exclude]]]])
BESCHREIBUNG:
search_file sucht nach der im ersten Parameter 'path' angegebenen Datei.

 - path kann ein absolute Dateiname sein. Dazu muss er mit einem
   Schraegstrich beginnen.

 - path kann ein relativer Dateiname sein. Hierbei sind '../' nur am
   Anfang erlaubt.

 - Beginnt path mit einem '%' so wird vom lokalen Verzeichnis ausgehend in
   allen uebergeordneten Verzeichnissen nach dieser Datei gesucht. Wurde
   der Parameter subdir angegeben, so muss diese Datei im Unterverzeichnis
   subdir liegen.
   
Der Parameter absolute gibt das lokale Verzeichnis an. Wurde er weggelassen
oder ist er 0, so wird das Verzeichnis des Objektes, welches diese simul-efun
aufruft, genommen.
Die Erweiterung extension wird sofern nicht schon in path vorhanden,
automatisch angehaengt.

In exclude kann man absolute Dateinamen (mit Endung) angeben, welche
von der Suche ausgeschlossen werden.

search_file liefert den gefundenen Dateinamen zurueck, sofern diese
Datei wirklich existiert, ansonsten 0.

Beispiele: 

    search_file("../../../map.c")
	liefert "/d/Vaniorh/map.c", wenn es von einem Objekt in 
	/d/Vaniorh/Tadmor/Stadtwache/room aufgerufen wird.

    search_file("../../../map", 0, 0, ".c")
        liefert das gleiche wie oben, hier duerfte man nur das .c
	im Dateinamen weglassen.

    search_file("%map.c")
        schaut ausgehend von /d/Vaniorh/Tadmor/Stadtwache/room nach folgenden
	Dateien:
	  /d/Vaniorh/Tadmor/Stadtwache/room/map.c
	  /d/Vaniorh/Tadmor/Stadtwache/map.c
	  /d/Vaniorh/Tadmor/map.c
	  /d/Vaniorh/map.c
	wo es schliesslich fuendig wird und letzteres zurueckliefert.

    search_file("%master", "/d/Vaniorh/Tadmor/Stadtwache", "apps", ".c")
        sucht nach folgenden Dateien:
	  /d/Vaniorh/Tadmor/Stadtwache/apps/master.c
	  /d/Vaniorh/Tadmor/apps/master.c
	  /d/Vaniorh/apps/master.c
	  /d/apps/master.c
	  /apps/master.c
	und liefert den ersten gefundenen Dateinamen oder 0.

    search_file("/room/church.c","/scheiss/egal/was")
        liefert /room/church.c

VERWEISE: file_path, object_name, abs_path
GRUPPEN: simul_efun, file
*/
varargs string search_file(string path, string absolute, string subdir, string extension, string* exclude)
{
    //object to;
    string file;
    closure fsize_cl;

    if(!stringp(path))
	return 0;
	
    if(!absolute)
	absolute = file_path();

    fsize_cl = bind_lambda(#'file_size, previous_object());
    // Damit die file_size-Abfragen auf das Konto des Aufrufenden gehen.
    // (file_size darf nicht ueberall (z.B. nicht in /var/adm) lesen.)
    
    if(path[0] == '%')
    {
	string tmp, *co;

	path = path[1..<1];
	if(path[<strlen(extension)..<1]!=(extension||""))
	    path += extension;
	path = (strlen(subdir)?("/"+subdir):"") + "/" + path;

	co = explode(absolute,"/");

	for (int i=sizeof(co); i--; )
	    if (funcall(fsize_cl,tmp = implode(co[0..i],"/") + path) >= 0 &&
		!(exclude && member(exclude,tmp)>=0) )
	    {
		file = tmp;
		break;
	    }
    }
    else
    {
	file = abs_path(path, absolute);
	if(file[<strlen(extension)..<1]!=(extension||""))
	    file += extension;
	    
	if(exclude && member(exclude, file)>=0)
	    return 0;

	file = (funcall(fsize_cl, file)>=0) && file;
    }

    return file;
}

/*
FUNKTION: valid_file_name
DEKLARATION: int valid_file_name(string name)
BESCHREIBUNG:
Liefert 1, wenn name ein gueltiger Dateiname ist, sonst 0.
Dabei wird geprueft, ob dieser Name nur gueltige Zeichen enthaelt und ob
das Verzeichnis, in welchem diese Datei sein sollte, existiert.
VERWEISE: abs_path, search_file
GRUPPEN: simul_efun, file
*/
int valid_file_name(string name)
{
    if(!MASTER_OB->valid_file_name(name))
	return 0;

    // file_size fuehrt zu valid_read-Aufrufen, welche zu Lasten
    // von previous_object() gehen sollen.
    return funcall(bind_lambda(#'file_size, previous_object()),
	    implode(explode(name,"/")[0..<2],"/"))==FSIZE_DIR;
}
