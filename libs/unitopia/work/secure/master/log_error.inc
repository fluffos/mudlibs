// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/log_error.inc
// Description: Loggt Runtime-Errors mit
// Author:	Freaky	(23.12.93)
// Modified by: Garthan	(02.09.94) Generalueberholung
// 		Freaky	(23.12.94) System-Fehler nach /log/sys/...
//		Monty	(27.05.95) log_fehler_new fuer das neue Fehler-
//				   Handling.
//		Freaky  (12.09.95) komplettes rewrite fuer die ERROR_DB
//		Freaky  (23.09.95) query_debugger() angepasst
//		Freaky	(18.11.95) call-out bei runtime_error wenn keine evals
//		Freaky  (13.05.97) ERROR_DB bekommt jetzt direkt die Debugger
//              Sissi   (31.07.97) access.c und WRITE in /p/
//              Tucita  (26.11.97) /p Gouverneur als Debugger
//		Freaky  (17.12.97) query_debugger erweitert um <typ>:<name>
//				   fuer z.B. 'Gilden:Abenteurergilde'
//		Freaky  (21.01.98) Bugfix in get_debugfile_offset()
//              Copper  (24.06.98) Bugfix fuer /p fuer Tucita eingebaut
//              Sissi   (07.02.99) query_debugger an ACLs und Gruppen angepasst
//              Sissi   (05.04.99) ACLs fuer query_debugger freigegeben
//              Parsec  (06.04.99) Doppelte Root-Debugger bei 'fehler mich' raus
//              Parsec  (04.05.99) Bugfix in query_debugger_new
//                                 Dateien ohne .c gehen jetzt auch
//              Rompler (16.08.99) Typo/Lob eingefuehrt
//              Parsec  (10.02.00) V-Item Nummer int Fehler anzeigen
//		Freaky  (12.05.2000) add_slash() eingebaut
//              Sissi   (19.05.2000) query_program_info modifiziert, sodass
//                                   es den ACLs bei Player-Objekten (die
//                                   haben ne Sonderbehandlung) und bei
//                                   obj - Objekten ne Chance laesst,
//                                   wenn es extra ACLs gibt (und nur dann).
//
// $Log: log_error.inc,v $
// Revision 1.75  2016/03/21 12:41:29  gnomi
// Klammerung bei Abfrage der Debug-Infos korrigiert.
//
// Revision 1.74  2016/02/21 11:42:57  myonara
// Bei RTE's TP und ENV als RTE_TP-debuginfo anzeigen
//
// Revision 1.73  2016/02/05 17:23:18  myonara
// Neue abgesicherte Funktion update_obj_error,
// Beruecksichtigung von Property P_DEBUG_GROUP bei RTE und fehler-Befehlen
//
// Revision 1.72  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.71  2015/02/02 16:03:57  gnomi
// Noch ein Bugfix zum vorherigen Patch.
//
// Revision 1.70  2015/01/31 19:55:29  myonara
// bug fix zu vorherigem patch
//
// Revision 1.69  2015/01/31 11:17:00  myonara
// P_DEBUG_INFO als Zusatz zu query_debug_info implementiert.
//
// Revision 1.68  2014/10/19 19:18:08  myonara
// Zauberstabfehler auch an Zauberstabeigentuemer geben.
//
// Revision 1.67  2014/03/12 20:18:13  myonara
// Rewrite der FDB.
//
// Revision 1.66  2013-05-14 17:38:38  myonara
// log_fehler_new neuer Parameter mapping dinfo2 als Ergaenzung Debuginfo
//
// Revision 1.65  2013-03-16 15:56:57  gnomi
// Renewal: Wenn das neue Objekt existiert, trotz Fehler mit Renewal
// fortfahren.
//
// Revision 1.64  2008/01/16 09:47:55  gnomi
// "nummer"-Eintrag von V-Items besser behandeln.
//
// Revision 1.63  2007/12/05 11:15:27  gnomi
// Fehler beim finish_renewal besser behandeln.
//
// Revision 1.62  2007/02/04 22:03:01  gnomi
// Sonderbehandlungen fuer Levitanis.
//
// Revision 1.61  2006/12/30 00:57:51  gnomi
// creator/first_room nur bei Clones zum Debuggersuchen beachten.
//
// Revision 1.60  2006/08/03 09:51:44  gnomi
// finish_renewal auch im Fehlerfalle aufrufen lassen.
//
// Revision 1.59  2006/06/25 00:18:13  gnomi
// Bei Warnungen Trace ins debug.log schreiben.
//
// Revision 1.58  2006/02/21 21:32:54  gnomi
// Runtime-Warnings verarbeiten.
//
// Revision 1.57  2005/04/10 01:30:50  gnomi
// Fehler im finish_renewal abfangen.
// "Failed to load object"-Fehler fuer VCs nicht mehr in der FDB ablegen.
// query_file_name beachten.
//
// Revision 1.56  2005/01/05 21:48:38  gnomi
// In Orbit das Umleiten von Compile-Fehlern ermoeglichen.
//
// Revision 1.55  2004/05/12 20:57:45  gnomi
// /p-Objekte: Nur bei Clones den Creator in Betracht ziehen.
//
// Revision 1.54  2004/04/19 22:19:18  gnomi
// log_error fuers /p: Bei Zauberstaeben die jeweiligen Goetter mit reinnehmen.
//
// Revision 1.53  2004/04/17 02:25:50  gnomi
// Bei P-Objekten geht der Fehler auch an den Creator.
//
// Revision 1.52  2003/11/06 04:03:15  gnomi
// DIT_UNCAUGHT_ERROR -> DIT_ERROR
// (Da auch catch-publish-Fehler dort landen.)
//
// Revision 1.51  2003/07/27 21:05:58  menaures
// V-Item "nummer"-Erkennung um pointerp()-Abfrage erweitert
//
// Revision 1.50  2003/02/18 01:29:59  gnomi
// log_fehler_new: Mit einer Breite von 79 umbrechen, weil der Editor des
// fehler-Befehls das auch mit dieser Breite macht.
//
// Revision 1.49  2003/02/01 02:49:34  gnomi
// query_program_info: V-Item-"nummer"-Eintrag besser auswerten.
//
// Revision 1.48  2003/01/26 04:06:14  gnomi
// fehler/idee: Bei /p-Objekten nach dem first_room forschen.
//
// Revision 1.47  2003/01/25 04:39:20  gnomi
// query_debugger_new: Kleiner Bugfix zum /w-Falle.
//
// Revision 1.46  2003/01/13 02:05:31  gnomi
// TLEs von /apps/cron bei /apps/cron absetzen (dort gibt es Debuginfos dazu).
//
// Revision 1.45  2002/12/17 03:52:52  gnomi
// Goetter koennen sich einstellen, dass sie selbstausgeloeste Fehler in die
// FDB haben wollen. (Praktisch fuer Tester.)
//
// Revision 1.44  2002/11/24 22:40:59  gnomi
// Fehler bei Objekten aus dem /p erhalten wie bei Objekten aus /obj auch
// die Debugger des first_rooms als Zustaendige.
//
// Revision 1.43  2002/10/29 01:48:34  gnomi
// Bei Laufzeitfehlern: In prg haben Includes jetzt den vollstaendigen Pfad.
// Ausserdem sagt previous_object nichts aus, daher wird der Trace von
// debug_info herangezogen.
//
// Revision 1.42  2002/10/28 03:03:39  gnomi
// Hinweis auf do_idee/do_fehler eingebaut.
//
// Revision 1.41  2002/09/30 23:53:28  gnomi
// Warnungen sind nicht mehr Abbruchgrund fuer eine Erneuerung.
// regreplace-Anweisungen vereinfacht und in ein Define ausgelagert.
//
// Revision 1.40  2002/07/27 02:11:39  gnomi
// abort_renewal loeschte das falsche Objekt.
//
// Revision 1.39  2002/03/07 08:35:00  gnomi
// Bugfixes zum Zernen.
//
// Revision 1.38  2002/02/24 06:36:31  gnomi
// Kleinen Typo behoben.
//
// Revision 1.37  2002/02/24 03:18:06  gnomi
// Unterstuetzung fuers 'zern -t' eingebaut.
//
// Revision 1.36  2002/02/22 05:30:35  gnomi
// Debug-Infos abfragen.
//
// Revision 1.35  2002/01/25 21:27:25  gnomi
// Fehlermeldungen, wenn ein Objekt nicht geladen werden kann, haben sich klein
// wenig geaendert...
//
// Revision 1.34  2002/01/21 03:17:03  gnomi
// "Failed to load"-Meldungen gehen in die FDB, weil es dazu keine zugehoerigen
// Compile-Errors gibt.
//
// Revision 1.33  2002/01/12 03:53:34  gnomi
// Gnomi hat eine if-Bedingung falsch geklammert.
//
// Revision 1.32  2001/12/27 01:00:32  gnomi
// Feedback: Zum Ort auch die Domain angeben.
// Runtime: Kurze Behandlung von Fehlern von /map/map auch bei clone_object.
//
// Revision 1.31  2001/12/14 23:58:29  gnomi
// Falls Zauberstab Fehler verursachte, ihn als Objekt angeben.
//
// Revision 1.30  2001/12/13 09:21:34  gnomi
// Wenn schon nach mappingp abgefragt wird, dann auch ["name"] anstatt
// ->query_name() nehmen. ;-)
//
// Revision 1.29  2001/12/09 12:10:32  sissi
// Kommentar hinzugefuegt
//
// Revision 1.28  2001/12/05 23:44:55  freaky
// keine simul-efuns verwenden.
//
// Revision 1.27  2001/12/02 16:53:35  sissi
// Klartextmeldung, zu was ein Fehler abgesetzt wurde, versucht.
//
// Revision 1.26  2001/11/13 03:24:05  gnomi
// EV_LIMIT_ERROR erhoeht, damit 2 verschachtelte  catches funktionieren.
//
// Revision 1.25  2001/10/07 18:25:35  freaky
// log_error ist jetzt protected
//
// Revision 1.24  2001/08/21 21:57:14  freaky
// limited-Aufrufe verbessert
//
// Revision 1.23  2001/05/30 16:03:08  freaky
// Versionabhaengigkeiten rausgeworfen.
//
// Revision 1.22  2001/05/30 14:41:55  freaky
// Beim Laden der simul-efun keine weiteren Lade-Versuche unternehmen.
//
// Revision 1.21  2001/05/14 21:23:23  gnomi
// Kein Timestamp bei Ausgabe des Trace im debug.log.
//
// Revision 1.20  2001/05/13 22:17:18  gnomi
// Fehlermeldung an Zauberstaeben explizit an den Besitzer des Zauberstabes
// absetzen.
//
// Revision 1.19  2001/04/11 18:20:14  gnomi
// Fehlerweiterleitung auch bei Objekten aus /obj an den Aufrufer.
// Zauberstabfehler an den Besitzer weiterleiten.
//
// Revision 1.18  2001/04/11 12:37:37  gnomi
// Das Feature mit den Error-Traces gibt es erst ab dev263.
//
// Revision 1.17  2001/04/09 20:04:47  gnomi
// Heart-Beat-Fehlerhandling mittels Parameter in runtime_error.
// Fehlermeldungen zur simul_efun an das aufrufende Objekt haengen.
//
// Revision 1.16  2001/03/21 11:02:07  freaky
// do-log-error: weiteren Parameter eingefuerhrt, mit dem keine Meldung
// an Spieler erzeugt wird.
//
// Revision 1.15  2001/03/15 23:52:58  freaky
// includes rausgenommen.
//
// Revision 1.14  2001/03/08 18:15:55  gnomi
// Bei DINFO_TRACE anstatt 1 DIT_STR_CURRENT angeben.
//
// Revision 1.13  2001/02/24 16:04:40  freaky
// member_array nach member umgebaut.
//
// Revision 1.12  2001/02/20 21:08:46  gnomi
// query_debugger: Die Firstroom-Debugger nur dann nehmen, wenn sie keine
// leere Menge sind.
//
// Revision 1.11  2001/02/06 20:46:39  gnomi
// \r bei Compilerfehlern rausfiltern.
//
// Revision 1.10  2001/01/23 10:37:24  freaky
// an neues debug_message() angepasst,
// Aufgeraeumt.
//
// Revision 1.9  2001/01/06 00:52:36  gnomi
// Bei do_error's wird der Trace ins Log geschrieben und endsprechend in der
// error_db vermerkt. (Ist zum Beispiel enorm hilfreich bei Grammatikfehlern.)
//
// Revision 1.8  2000/12/07 20:13:28  gnomi
// Root nur dann als Debugger eines RTE eintragen, wenn es keinen anderen
// Debugger gibt.
//
// Revision 1.7  2000/10/07 15:17:19  sissi
// Gnomi: Fehlermeldungen auch an eingeloggte Debugger; ausserdem
// wird jetzt /apps/groups zur Aufloesung verwendet.
//
// Revision 1.6  2000/08/29 14:27:23  freaky
// file_name() nach object_name() umgebaut.
// filter_array() nach filter() umgebaut.
// map_array() nach map() umgebaut.
// (also alles an die neuen Efuns angepasst)
//
// Revision 1.5  2000/07/03 11:50:37  freaky
// bei clone_object-Fehlern wieder Fehler werfen.
//
// Revision 1.4  2000/06/26 21:27:09  freaky
// Im Error-Handling Fehler von simul_efun::clone_object() nur in Kurzform
// behandeln.
//


#pragma strict_types

// #define VERB(x) (x)?to_string(({string})(x)->query_command()):""
#define VERB(x) (query_command() || "")
#define FIRST_ROOM(x) ((x)&&find_object(x))?({string})find_object(x)->query_first_room():0

#define ROOT_DEB ({ROOT_UID})

#define DEF_MSG "Da hat sich wohl ein Loch im Raum-Zeit-Gefuege aufgetan.\n"
#define LINE "------------------------------------------------------------------------------\n"

#define REST_MASTER_EVAL 5000
// EV_LIMIT_ERROR muss groesser sein, als catch-reserved-cost
// Und wir packen noch etwas drauf, damit auch ein 2. catch
// funktioniert.
#define EV_LIMIT_ERROR 150000

// Die momentane Laenge des Debug-Files
static private int debugfile_offset;

// Diese Funktionen werden vom zerneuere-Befehl mit der Option -t/-T
// benoetigt. Der Master verwaltet die umbenannten Dateien und
// benennt sie bei Fehlern gleich wieder zurueck.
static string *objects_to_renew;
static object object_to_destruct;

#define BACKUP_OBJ_NAME(name) regreplace(name,"/([^/]*)$","/$\\1$", 0)

#if ! __EFUN_DEFINED__(reverse)
#define reverse(arr) sort_array((arr),(:1:))
#endif

private void abort_renewal(string err_ob)
{
    if(object_to_destruct)
        destruct(object_to_destruct);

    if(sizeof(objects_to_renew))
    {
	if(err_ob && member(objects_to_renew, err_ob)>=0)
	{
	    object ob = find_object(err_ob);
	    if(ob)
	    	destruct(ob);
	}
	    
	foreach(string name:objects_to_renew)
	{
	    object ob, nob;

	    if(sscanf(name,"%~s#%~d")<2)
	    {
		// Das alte (gesicherte) Objekt
		ob = find_object(BACKUP_OBJ_NAME(name));
		// Das neue Objekt
		nob = find_object(name);
	    }
	    else
		ob = find_object(name);

	    if(ob)
	    {
	        objects_to_renew -= ({name});
		if(nob)	// Das wurde geschafft
		{
		    object_to_destruct = ob;
		    
		    ob->finish_renewal(nob);
		    if(ob)
			destruct(ob);
		}
		else
		{
		    if(sscanf(name,"%~s#%~d")<2)
			rename_object(ob, name);
		    ob->abort_renewal();
		}
	    }
	}
    }
}

void save_objects_for_renewal(string *names)
{
    object ob;
    
    if(strstr(object_name(previous_object()),"/obj/zauberstab#") ||
#if __EFUN_DEFINED__(driver_info)
	efun::driver_info(DI_TRACE_CURRENT)[<2][TRACE_PROGRAM] !=
#else
	efun::debug_info(DINFO_TRACE, DIT_CURRENT)[<2][TRACE_PROGRAM] !=
#endif
	    "i/zauberstab/zauberstab.c (/i/zauberstab/zmarker.inc)")
	return;

    object_to_destruct = 0;
    objects_to_renew = ({});
    foreach(string name:names)
	if(ob=find_object(name))
	{
	    ob->prepare_renewal();
	    if(sscanf(name,"%~s#%~d")<2)
		rename_object(ob, BACKUP_OBJ_NAME(name));
	    objects_to_renew += ({name});
	}
}

void finish_renewal(int failure, object new_clone)
{
    if(strstr(object_name(previous_object()),"/obj/zauberstab#") ||
#if __EFUN_DEFINED__(driver_info)
	efun::driver_info(DI_TRACE_CURRENT)[<2][TRACE_PROGRAM] !=
#else
	efun::debug_info(DINFO_TRACE, DIT_CURRENT)[<2][TRACE_PROGRAM] !=
#endif
	    "i/zauberstab/zauberstab.c (/i/zauberstab/zmarker.inc)")
	return;
	
    if(failure)
    {
	abort_renewal(0);
	return;
    }

    if(sizeof(objects_to_renew))
    {
	foreach(string name:objects_to_renew)
	{
	    object ob, nob;

	    if(sscanf(name,"%~s#%~d")<2)
	    {
		ob = find_object(BACKUP_OBJ_NAME(name));
		nob = find_object(name);
	    }
	    else
	    {
		ob = find_object(name);
		nob = new_clone;
	    }

	    if(ob)
	    {
	        objects_to_renew -= ({name});
	
		if(nob)
		{
		    object_to_destruct = ob;
		    
		    ob->finish_renewal(nob);
		    if(ob)
			destruct(ob);
		}
		else
		{
		    if(sscanf(name,"%~s#%~d")<2)
			rename_object(ob, name);
		    ob->abort_renewal();
		}
	    }
	}
    }
    
    object_to_destruct = 0;
}

// Wird auch vom Preload aufgerufen.
private int get_debugfile_offset()
{
#ifdef UNItopia
    debugfile_offset = file_size("/UNItopia.debug.log");
#else
    debugfile_offset = file_size("/" __HOST_NAME__ ".debug.log");
#endif
    return debugfile_offset;
    
}

private string get_debugfile_text()
{
    int old_offset = debugfile_offset;
    int new_offset = get_debugfile_offset();
    
    return read_bytes(
#ifdef UNItopia
	"/UNItopia.debug.log",
#else
	"/" __HOST_NAME__ ".debug.log",
#endif
	old_offset, new_offset-old_offset);
}

// Mischt 2 Arrays ineinander, ohne doppelte Eintraege
private string *merge_array(string *a, string *b)
{
    return a + (b - a);
}

// Wrapperfunktion fuer limited mit weniger als den normalen Evals
private mixed limited_eval(closure c, int evals, varargs mixed* arg)
{
    return limited( (: apply(#'limited, $1,({$2}), $3) :),
	    ({LIMIT_UNLIMITED}), c, evals, arg);
}

string *expand_debugger(string *debugger)
{
    return ({string *}) limited_eval(
	symbol_function("expand_groups",GROUP_MASTER),
	EV_LIMIT_ERROR, debugger);
}

string *query_debugger_acl(string *path);

private string *query_debugger_new(string file)
{
    string *path, write, *deb, *lords, wiz;
    int x, y;
    object ob;
    mixed tmp;

    if (!stringp(file))
    	return ROOT_DEB;

    path = explode(file[1..],"/");

    // bei dateiname#objektnummer den # und die objektnummer wegschnippeln
    tmp = path [sizeof(path)-1];
    if (strstr (tmp,"#") != -1)
        tmp = implode (explode (tmp,"#")[0..<2],"#");
    path [sizeof(path)-1] = tmp;
    switch(path[0])
    {
      case "d":
      case "z":
        // Hierfuer sind die ACLs zustaendig
	if((ob=find_object(file)) && !catch(tmp=({string})ob->query_file_name()) && stringp(tmp))
	    deb = query_debugger_acl( explode(tmp[1..],"/"));
	else
	    deb = query_debugger_acl (path);

#ifdef UNItopia
	if(!strstr(file,"/d/Levitanis/wiz/"))
	    deb += ({ path[3] });
#endif

        if (sizeof (deb)) return deb;
        break;
      case "p":
        // Sowohl die ACLs beachten, als auch den creator || first_room auswerten
	// Wenn es ein Autoloader ist, soll nicht first-room ueberprueft werden
	if ((ob = find_object(file)) && !ob->query_auto_load() &&
	    member(object_name(ob),'#')>0 &&
	    tmp = (({string})ob->query_creator() || ({string})ob->query_first_room()))
        {
	    tmp = trim(explode(tmp,"(")[0]);
	    if(!strstr(tmp, "/obj/zauberstab#"))
	    {
		if(ob = find_object(tmp))
		    deb = merge_array(({geteuid(ob)}), query_debugger_acl(path))-ROOT_DEB;
		else
		    deb = query_debugger_acl(path)-ROOT_DEB;
	    }
	    else
	    {
		tmp = explode(tmp,"#")[0];
		deb = merge_array(
		    query_debugger_new(tmp),
		    query_debugger_acl(path))-ROOT_DEB;
	    }
            if(sizeof(deb))
		return deb;
        }
	else
	{
    	    deb = query_debugger_acl (path);
    	    if (sizeof (deb))
		return deb;
	}
        break;
      case "map":
	// Fehler in der Map: man suche nach der passenden Domain,
	// sonst an Admin.
	if (sscanf(file, "/map/m%d_%d",x,y) == 2 &&
	    (tmp = ({string})MAP_OB->query_map_file_name(x, y)) != file)
	    return query_debugger_new(tmp);
	break;
      case "w":
	if (sizeof(path)>1 && GOETTER_REGISTER->is_wiz(path[1]))
            return path[1..1];
        break;
      case "obj":
	// Wenn es ein Autoloader ist, soll nicht first-room ueberprueft werden
	if (!(ob = find_object(file)) || ob->query_auto_load())
	    break;
	// Player sollen nicht auf first-room ueberprueft werden
	if (ob && playerp(ob))
	    break;
	if (strstr(file, "/obj/zauberstab#") && efun::clonep(ob) &&
	    tmp = (({string})ob->query_creator() || ({string})ob->query_first_room()))
        {
	    tmp = query_debugger_new(trim(explode(tmp,"(")[0]))+query_debugger_acl(path)-ROOT_DEB;
            if(sizeof(tmp)) return tmp;
        }
	wiz = explode(getuid(ob),":")[<1];
	if (!GOETTER_REGISTER->is_wiz(wiz))
	    wiz = 0;
    }
    // Fehler konnte nicht zugeordnet werden, er geht
    // an Root und, falls wiz gesetzt ist, an wiz.
    // ACLs abfragen.
    deb = query_debugger_acl (path);
    if (wiz)
        return sizeof (deb) ? deb + ({wiz}) : ROOT_DEB + ({wiz});
    return sizeof (deb) ? deb : ROOT_DEB;
}

string *query_debugger(string file)
{
    if (!stringp(file))
    	return ROOT_DEB;

    return limited_eval(#'query_debugger_new, EV_LIMIT_ERROR, file);
}

// private // wird vom Zauberstab aufgerufen, daher nicht private.
string add_slash(string str)
{
    if (str && str[0] != '/' && str[0] != '#' && str[0] != '<')
	return "/" + str;
    return str;
}

private void add_error(mapping error)
{
    string ca_msg;
    
    m_add(error, EDB_E_DATE, time());
    if(!member(error, EDB_E_PLAYER))
    {
	object pl = this_interactive() || this_player();
	if(playerp(pl))
	    m_add(error, EDB_E_PLAYER, pl->query_real_name());
    }
    if(!member(error, EDB_E_WHO))
    {
	mixed *stack;
	
	if(this_interactive())
	    catch(m_add(error, EDB_E_WHO, sprintf("this_interactive(): %O",
		this_interactive())); reserve 10000);
	else if(this_player())
	    catch(m_add(error, EDB_E_WHO, sprintf("this_player(): %O",
		this_player())); reserve 10000);
	else if(pointerp(stack=error["__stack"]) && sizeof(stack)>1)
	{
	    mixed ob = stack[<2];
	    if(stringp(ob))
		ob = find_object(add_slash(ob));
	    if(objectp(ob))
		catch(m_add(error, EDB_E_WHO, sprintf("previous_object(): %O",
		    ob)); reserve 10000);
	}
    }
    
    m_delete(error, "__stack");
    
    ca_msg = catch(ERROR_DB->add_error(error); reserve 2000);
    if (ca_msg)
        write_file("/log/sys/ERROR_DB",time()
            +": Fehler bei add_error: ("+get_eval_cost()+") "+ca_msg);
}

private mapping update_obj_error(mapping error, object ob)
{
    string * dbg,*propdbg;
    if(ob)
    {
        m_add(error, EDB_E_USER_INFO,
            (error[EDB_E_USER_INFO]||([]))
            +((({mapping})ob->query(P_DEBUG_INFO))||([]))
            +((({mapping})ob->query_debug_info())||([])));
        m_add(error, EDB_E_FIRSTROOM, ob->query_first_room());
        propdbg = ob->query(P_DEBUG_GROUP)||({});
        if (sizeof(propdbg))
        {
            dbg = error[EDB_E_DEBUGGER];
            m_add(error, EDB_E_DEBUGGER, merge_array(dbg,propdbg));
        }
    }
    return error;
}

private void add_obj_error(mapping error)
{
    object ob = error[EDB_E_OBJ] && find_object(error[EDB_E_OBJ]);

    if (ob)
        catch(error = update_obj_error(error,ob); reserve 5000);
        // call others ueber catch absichern.
    
    add_error(error);
}

private string online_error_message(object target, string prg, int line,
				    string curobj, string err, int prev);
private string channel_error_message(object target, string prg, int line,
				     string curobj, string err, object prevobj);

private void add_runtime_error(mapping error)
{
    object target = this_interactive() || this_player();
    string target_wiz_name;
    string *curobj_debugger, *prg_debugger,*curprop_debugger,
           *exp_curobj_debugger, *exp_prg_debugger,
	   *zus;

    // target_wiz_name wird gesetzt, wenn target ein wiz ist
    if (target && wizp(target))
	target_wiz_name=({string})target->query_real_name();

    // Jetzt bekommt derjenige, der den Fehler erzeugt hat, noch eine
    // direkt eine Meldung auf den Bildschirm.
    if (target && (!error[EDB_E_WARNING] || target_wiz_name))
	tell_object(target, target_wiz_name ?
	       online_error_message(target,
	          error[EDB_E_FILE], error[EDB_E_LINE],
		  error[EDB_E_OBJ], error[EDB_E_ERROR], 0) :
	    	(target==error["__culprit"]) ? "" : DEF_MSG);

    
    if (playerp(error["__culprit"]))
	tell_object(error["__culprit"],
	    "Der Game-Driver redet zu dir: Dein Herz ist stehengeblieben!\n");
    m_delete(error, "__culprit");
    
    // Root ist erstmal nie Debugger...
    curobj_debugger = query_debugger(error[EDB_E_OBJ]) - ({"Root"});
    prg_debugger = query_debugger(error[EDB_E_FILE]) - ({"Root"});

    if(pointerp(error[EDB_E_DEBUGGER]))
	curobj_debugger = merge_array(error[EDB_E_DEBUGGER], curobj_debugger);

    // ... Es sei denn, es findet sich sonst niemand.
    if(!sizeof(curobj_debugger+prg_debugger))
        curobj_debugger=({"Root"});

    exp_curobj_debugger = expand_debugger(curobj_debugger);
    exp_prg_debugger = expand_debugger(prg_debugger);

    // Die zustaendigen Wizzes bekommt eine Meldung ueber den Kurier/Runtime
    // falls sie anwesend sind und der Erzeuger nicht dafuer zustaendig ist.
    zus = merge_array(exp_curobj_debugger,exp_prg_debugger);
    if (member(zus,target_wiz_name) < 0)
    {
	string msg;

	foreach(string wiz: zus)
	{
	    object wiz_ob = find_player(wiz);
	    
	    if(wiz_ob && interactive(wiz_ob))
	    {
		if(!msg)
		{
		    mixed stack = error["__stack"];
		    mixed prev_ob;
		    if(pointerp(stack) && sizeof(stack)>1)
		    {
			prev_ob = stack[<2];
			if(stringp(prev_ob))
			    prev_ob = find_object(add_slash(prev_ob));
		    }
		    
		    msg = channel_error_message(target, 
	        	error[EDB_E_FILE], error[EDB_E_LINE],
			error[EDB_E_OBJ], error[EDB_E_ERROR],
			prev_ob);
		}
		catch(EVENT_MASTER->talk(wiz_ob, "Runtime", target, msg);
		    reserve 20000);
	    }
	}
    }

    // Start: Filelogging

    // Falls derjenige, der den Fehler auf den Bildschirm bekommt
    // einer der Debugger fuer BEIDE Files ist, wird der Fehler nicht geloggt
    if(target_wiz_name && error[EDB_E_FILE] != sprintf("/w/%s/LPC_zst.c", target_wiz_name))
    {
	object z = present_clone("/obj/zauberstab", target);
	if(z && z->get_own_rtes())
	    target_wiz_name = 0;
    }
    
    if (target_wiz_name && interactive(target) &&
	(!sizeof(exp_curobj_debugger) ||
	 member(exp_curobj_debugger,target_wiz_name) >= 0) &&
	(!sizeof(exp_prg_debugger) ||
         member(exp_prg_debugger,target_wiz_name) >= 0))
    	return;

    m_add(error, EDB_E_DEBUGGER, merge_array(curobj_debugger,prg_debugger));
    m_add(error, EDB_E_TYPE, EDB_RUNTIME);
    if(!member(error, EDB_E_TRACE))
	m_add(error, EDB_E_TRACE, get_debugfile_text());
    m_add(error, EDB_E_COMMAND, query_command());
    if (playerp(target))
    {
        mapping dinfo = error[EDB_E_USER_INFO] ||([]);
        dinfo["RTE_TP"] = sprintf("%Q in %Q",target,environment(target));
        m_add(error,EDB_E_USER_INFO,dinfo);
    }

    add_obj_error(error);
}

// ============ COMPILE TIME ERROR ============================================
//
// The error occured in the object 'file', giving the error message 'message'.

// Bei einem Syntax-Fehler in einem File
protected void log_error(string file, string message, int warn)
{
    object target;
    int no_tell;
    string *debugger;
    file = add_slash(file);

    target = this_interactive();
    if (!target)
	target = this_player();

    message -= "\r";  // Bei Windows-Dateien

    if (warn)
	message = "Warning: " + message;

#ifdef Orbit
    // Fuer Tools, die Verzeichnisse in Orbit durchladen.
    // Sie koennen damit die Fehler abfangen.
     if(CONTROL->forbidden("compile_error",file,message,warn))
        return;
#endif

    if (target && wizp(target))
    {
	tell_object(target, message);
	if(file != sprintf("/w/%s/LPC_zst.c", target->query_real_name()))
	{
	    object z = present_clone("/obj/zauberstab", target);
	    if(z && z->get_own_rtes())
		no_tell = 1;
	}
    }
    else
	no_tell = 1;

    // Fuer den Fall, dass es ein Fehler waehrend des Ladens der simul-efun
    // war, sollte hier kein Objekt geladen werden. Deswegen lieber raus.
    if (loading_simul_efun)
	return;

    debugger = query_debugger(file);
    if (no_tell || member(expand_debugger(debugger),
			  ({string})target->query_real_name()) < 0)
    {
	int line;
	
	sscanf(message,"%!s line %d%!s",line);
	
	add_error(([
	    EDB_E_TYPE: EDB_COMPILE,
	    EDB_E_WARNING: warn,
	    EDB_E_ERROR: message,
	    EDB_E_DEBUGGER: debugger,
	    EDB_E_FILE: file,
	    EDB_E_LINE: line,
	    "__stack": caller_stack(),
	]));
    }

    if(!warn) abort_renewal(0);
}

// ============ RUN TIME ERROR ================================================

mixed include_file(string file, string compiled_file, int sys_include);

//Die Meldung, die TI/TP bekommt, wenn er ein Gott ist.
//Ist prev==0, so wird die Zeile im Quelltext angezeigt.
private string online_error_message(object target, string prg, int line,
				    string curobj, string err, int prev)
{
    string str, context, main, incl, file;

    str = LINE +
       	"File:   " + prg + "  Zeile: " + line + "\n"
	"Objekt: " + curobj + "\n";

    // Show Context
    if (!prev)
    {
	if (prg && (sscanf(prg,"%s (%s)",main,incl) == 2))
	{
	    file = include_file(incl,main,0);
	    if (!stringp(file))
		file = 0;
	}
	else
	{
	    file = prg;
	}
	if (!stringp(file))
	    write_file("/log/sys/LOG_ERR",sprintf("PRG: %O\n",prg));

	if (file && !catch(context = read_file(file,line - 1,3)) && context)
	    str += "\n" + context + "\n";
    }

    if(strstr(err, "Warning: "))
	str += "Fehler: " + err + LINE;
    else
	str += "Warnung: " + err[9..<1] + LINE;
    return str;
}

// Die Meldung, die an die eingeloggten Goetter gehen soll.
private string channel_error_message(object target, string prg, int line,
				     string curobj, string err, object prevobj)
{
    return
	"RUNTIME-ERROR:\nWer:    " +
       	sprintf("%O", target ? target : prevobj) +
	"   Command: '" + VERB(target) +
	"'\nFile:   " + prg + "   Zeile: " + line +
       	"\nObjekt: " + curobj + 
	(strstr(err,"Warning: ")?("\nFehler: " + err):("\nWarnung: " + err[9..<1]));
}

// The error 'err' occured in the object 'curobj', file 'prg', line 'line'.
// Wird von runtime_error aufgerufen
private void log_runtime_error(string err, string prg, string curobj,
			      int line, mixed* stack, mixed culprit, int caught, int warn)
{
    if(warn)
#if __EFUN_DEFINED__(driver_info)
	debug_message(efun::driver_info(DI_TRACE_CURRENT_AS_STRING), DMSG_STDOUT | DMSG_LOGFILE | DMSG_STAMP);
#else
	debug_message(efun::debug_info(DINFO_TRACE,DIT_STR_CURRENT),
	    DMSG_STDOUT|DMSG_LOGFILE);
#endif

    // Sonderbehandlung bei touch(), clone_object(), oder create_map()
    // Diese Fehler werden nur in Kurzform an den Erzeuger geschickt,
    // sonst versinken wir in Fehlermeldungen...
    if ((!strstr(err,"Error in loading object: ") 

    // Diese 'failed to load file'-Meldungen muessen in die FDB, weil
    // es keine Compile-Fehler dazu gibt.
    //	|| !strstr(err,"Failed to load file: ")
	
	) &&
	    ((prg == SIMUL_EFUN" (/secure/simul_efun/map.inc)") ||
	     (prg == MASTER_OB".c (/secure/master/compiler_control.inc)") ||
	     (prg == SIMUL_EFUN" (/secure/simul_efun/clone_object.inc)" ||
	      prg == "/map/map.c") &&
	      curobj == "/map/map"))
    {
	object target = this_interactive() || this_player();
	int wiz = wizp(target);

	if(target && (!warn || wiz))
	    tell_object(target, wiz ? err : DEF_MSG);
	abort_renewal(curobj);
	return;
    }

    if (warn && strstr(err, "Warning:"))
	err = "Warning: " +err;

    // Bei Fehlern in der simul-efun oder /obj/-Dateien das aufrufende
    // Objekt suchen, da diese meist daran Schuld haben
    if(!warn && curobj && (curobj + ".c" == SIMUL_EFUN || curobj[0..4] == "/obj/"))
    {
#if __EFUN_DEFINED__(driver_info)
	mixed* error_trace = efun::driver_info(DI_TRACE_LAST_ERROR);
#else
	mixed* error_trace = efun::debug_info(DINFO_TRACE, DIT_ERROR);
#endif
	string new_obj;
	object z_ob;
	int i;

        if((i=sizeof(error_trace))>1)
            for(;--i;) // i=0 darf nicht auftreten.
                if((new_obj=add_slash(error_trace[i][TRACE_OBJECT])) + ".c" !=SIMUL_EFUN &&
                   new_obj[0..4] != "/obj/")
                {
                    curobj = new_obj;
                    break;
                }
                else if(new_obj[0..15] == "/obj/zauberstab#" &&
                        (z_ob=find_object(new_obj)) && 
                        geteuid(z_ob)!="Learner")
                {
		    curobj = new_obj;
                    //curobj_debugger=({geteuid(prg_wiz)});
                    break;
                }
    }
    else if(!warn && (curobj == object_name() || curobj == "/apps/control"))
    {
#if __EFUN_DEFINED__(driver_info)
	mixed* error_trace = efun::driver_info(DI_TRACE_LAST_ERROR);
#else
	mixed* error_trace = efun::debug_info(DINFO_TRACE, DIT_ERROR);
#endif
	
	// Besondere Behandlung bei cron-jobs, um die Debuginfos
	// von /apps/cron mitzubekommen.
	if(sizeof(error_trace)>1 &&
	    add_slash(error_trace[1][TRACE_OBJECT])=="/apps/cron" &&
	    error_trace[1][TRACE_NAME]=="job")
		curobj = "/apps/cron";
    }

    add_runtime_error(([
	EDB_E_SUBTYPE: (intp(culprit) && culprit<0) ? EDB_RUN_RUNTIME : EDB_RUN_HB,
	EDB_E_WARNING: warn,
	EDB_E_ERROR: err,
	EDB_E_OBJ: curobj,
	EDB_E_FILE: prg,
	EDB_E_LINE: line,
	"__culprit": culprit,
	"__stack": stack,
    ]));

    if(!warn)
	abort_renewal(curobj);
}

// Wird bei einem Runtime-Fehler aufgerufen
protected void runtime_error(string err, string prg, string curobj, int line, mixed culprit, int caught)
{
    limited_eval(#'log_runtime_error, EV_LIMIT_ERROR,
	err, add_slash(prg), add_slash(curobj), line,
#if __EFUN_DEFINED__(driver_info)
	reverse(map(efun::driver_info(DI_TRACE_LAST_ERROR)[1..<1],#'[,TRACE_OBJECT)),
#else
	reverse(map(efun::debug_info(DINFO_TRACE, DIT_ERROR)[1..<1],#'[,TRACE_OBJECT)),
#endif
	culprit, caught, 0);
}

protected void runtime_warning(string err, string curobj, string prg, int line, int caught)
{
    limited_eval(#'log_runtime_error, EV_LIMIT_ERROR,
	err, add_slash(prg), add_slash(curobj), line,
	caller_stack(), -1, caught, 1);
}


// ============ HEART BEAT ERROR ==============================================
//
int heart_beat_error(object ob, string err, string prg, string curobj, int line)
{
    return 0; /* Don't restart */
}


// ============ FEHLER LOGGING fuer do_error ==================================
//
// Hiermit werden Fehler geloggt, die mit do_error() aus <error.h> erzeugt
// wurden. ("userdefined errors")
// (eine entschaerfte Version von runtime_error())

void do_log_error(string err, string prg, string curobj, int line, string *debugger, int no_msg)
{
    // Filegroesse neu berechnen.
    get_debugfile_offset();
    if (!stringp(err) || !stringp(curobj) || !stringp(prg))
	return;
    
    debug_message("do_error: " + err,DMSG_STDOUT|DMSG_LOGFILE|DMSG_STAMP);
    debug_message("program: " + prg + ", object: " + curobj + " line " +
	    line + "\n",DMSG_STDOUT|DMSG_LOGFILE|DMSG_STAMP);
#if __EFUN_DEFINED__(driver_info)
    debug_message(efun::driver_info(DI_TRACE_CURRENT_AS_STRING),
	    DMSG_STDOUT | DMSG_LOGFILE);
#else
    debug_message(efun::debug_info(DINFO_TRACE,DIT_STR_CURRENT),
	    DMSG_STDOUT|DMSG_LOGFILE);
#endif

    if (!pointerp(debugger))
	debugger = 0;
    else
    {
	string *tmps = map(debugger,"valid_debugger",ERROR_DB) - ({0});
	debugger = ({});
	foreach(string deb: tmps)
	    if(member(debugger,deb) == -1)
		debugger += ({deb});
    }

    add_runtime_error(([
	EDB_E_SUBTYPE: EDB_RUN_USER_DEFINED,
	EDB_E_WARNING: no_msg,
	EDB_E_ERROR: err,
	EDB_E_OBJ: curobj,
	EDB_E_FILE: prg,
	EDB_E_LINE: line,
	EDB_E_DEBUGGER: debugger,
	"__stack": caller_stack(),
    ]));
}

// ============ FEHLER LOGGING fuer das 'fehler' Kommando =====================
//
// Alle Fehler die durch das 'fehler' Kommando des players gemeldet werden,
// werden hier verarbeitet.


// findet die debugger fuer beliebige Objekte und v_items
private mapping query_program_info(mixed ob, object who)
{
    string *programmers, *lords, name, env_name, *path, write, tmp;
    mapping res;
    int x, y;

    if (stringp(ob))
	return (["debugger":query_debugger(ob),"name":ob,"info":""]);

    if (mappingp(ob))
    {
	// Hat wohl einer einen Fehler in einem VItem gefunden:
	// geht an den passenden Raum oder das passende Objekt
	res = query_program_info(ob["environment"] ? ob["environment"] :
	    environment(who), who);
	return ([
            "debugger" : res["debugger"],
            "name"     : res["name"],
            "info"     : res["info"]+"V-Item    : "+
			 (!pointerp(ob["nummer"])
			  ?(((ob["nummer"]) ? ob["nummer"]+". " : "")+ob["name"])
			  :(sizeof(ob["nummer"])>1)
			  ?((ob["id"] && (x=member(ob["id"], ob["name"]))>=0)
			    ?(ob["nummer"][x]?ob["nummer"][x]+". ":"")+ob["name"]
			    :(ob["nummer"][0]?ob["nummer"][0]+". ":"")+ob["name"])
			  :((ob["nummer"][0]?ob["nummer"][0]+". ":"")+ob["name"]))
			 +"\n"
            ]);
    }
    if (objectp(ob))
    {
	// Objekte:
        if ( playerp(ob) && environment(ob) )
        {
            res = query_program_info(environment(ob), ob);
            res["debugger"] = (res["debugger"] - ROOT_DEB) 
                + query_debugger(object_name(ob)) ;

            if (wizp(ob) && member(res["debugger"],
                    ob->query_real_name()) == -1)
                res["debugger"] += ({ ob->query_real_name() }) ;
            res["info"] = sprintf("%sObjekt    : %O\n", res["info"], ob);
            // Achtung: Sollte obiger Text / Formatierung jemals geaendert
            // werden, so muss sie auch in /i/zauberstab/zfehler.inc beim
            // Fehlerfeedback angepasst werden, einfach nach Objekt   suchen
            return res ;
        }
	path = explode(object_name(ob),"/")-({""});
	if ((path[0]=="obj" || (path[0]=="p" && member(path,"obj")>0)) &&
	    !ob->query_auto_load() && ob->query_first_room())
	{
	    // Die Objekte unter /obj werden fast immer nur geclont und
	    // in einem Raum angepasst, also an den erschaffenden Raum. Bei
	    // Autoloadern liegt das anders, da sollte der Fehler an
	    // Admin gehen.
	    res = query_program_info(explode(({string})ob->query_first_room(),
	    	"(")[0], who);
            // WENN es ACLs fuer die /obj/ - Datei gibt, DANN sollen die
            // AUCH zum Zug kommen.

            res["debugger"] = query_debugger(object_name(ob)) ;
	    return (["debugger":res["debugger"], "name":res["name"],
		"info":sprintf("%sObjekt    : %O\n",res["info"],ob) ]);
	}
        res =  query_program_info(object_name(ob), who);
	if(member(path,"obj")>=0)
	    res["info"]=sprintf("%sObjekt    : %O\n",res["info"],ob);
	return res;
    }
    if (environment(who))
  	return query_program_info(environment(who), who);
    return (["debugger":ROOT_DEB,"name":name,"info":""]);
}

// TODO: nach log_fehler umbenennen.
// (Wird sowohl vom /i/player/fehler als auch von Defines in error.h aufgerufen.)
void log_fehler_new(string text, mixed what, object who, int flag, mapping dinfo2)
{
    mapping res, dinfo;
    string wozu,*propdbg=({});
    int i;

    // Die Debugger ermitteln:
    res = query_program_info(what, who);

    // wozu ermitteln:
    if (objectp (what)) 
    {
        if (what->query_room() && what->query_short())
            wozu = "Ort: "+what->query_short()
            + (what->query_room_domain()?" ("+what->query_room_domain()+")":"");
        else if (what->query_gender() && what->query_name())
            wozu = living(what)
                ? "Lebewesen: "+what->query_name()
                : "Gegenstand: "+what->query_name();
        dinfo = (({mapping})what->query(P_DEBUG_INFO)||([]))
              + ((({mapping})what->query_debug_info())||([]));
        if (sizeof(dinfo)==0) dinfo = 0;
        propdbg = what->query(P_DEBUG_GROUP)||({});
    }
    else if (mappingp (what)) {
        mixed env;

        if (what["gender"] && what ["name"])
            wozu = "Detail: "+what["name"];

        env = what;
        while(mappingp(env) && !dinfo)
        {
            dinfo = funcall(env["debug_info"],env);
            env = env["environment"];
        }
        if (objectp(env))
            propdbg = env->query(P_DEBUG_GROUP)||({});
        if(!dinfo && objectp(env))
        {
            dinfo = ({mapping}) env->query_debug_info();
            if (mappingp(dinfo))
            {
                dinfo += ({mapping})env->query(P_DEBUG_INFO)||([]);
            }
            else
            {
                dinfo = ({mapping})env->query(P_DEBUG_INFO);
                if (!sizeof(dinfo))
                {
                    dinfo = 0;
                }
            }
        }
    }
    if (mappingp(dinfo2)) {
        if (mappingp(dinfo)) {
            dinfo = dinfo + dinfo2;
        } else {
            dinfo = dinfo2;
        }
    }
    if (sizeof(propdbg))
    {
        res["debugger"] = merge_array(res["debugger"],propdbg);
    }

    // Monty: Fehlerlogging fuer Idee (vorlaeufig)
    ERROR_DB->add_error( ([
	EDB_E_TYPE: flag,
	EDB_E_FILE: res["name"],
	EDB_E_ERROR: res["info"] + sprintf("%-=79s\n",text),
	EDB_E_DATE: time(),
	EDB_E_DEBUGGER: res["debugger"],
	EDB_E_PLAYER: who->query_real_name(),
	EDB_E_ROOM: object_name(environment(who)),
	EDB_E_OBJ_DESC: wozu,
	EDB_E_USER_INFO: dinfo
    ]) );
}
