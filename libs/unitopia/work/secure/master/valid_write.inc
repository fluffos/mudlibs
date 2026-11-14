// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/valid_write.inc
// Description: valid_write
// Author:	Freaky
// Modified by:	Freaky (01.03.96) /open gibt es nicht mehr
// Modified by:	Freaky (29.04.97) /z/ fragt jetzt nur noch FILED
//                                /d/<dom>/<Projekt>/<name> eingebaut
//              Sissi (31.07.97)  access.c und WRITE in /p/
//                                z_sub_write noch inaktiv.
//              Sissi (28.12.98)  Zugriffsrechte via ACLs werden
//                                parallel verwendet, Unterschiede
//                                geloggt
//              Sissi (04.01.99)  Objekte mit x:y - UID duerfen nur
//                                dann etwas, wenn sie explizit via
//                                ACL die Erlaubnis dazu haben.
//              Sissi (08.01.99)  Anpassung fuer FTP - Server, bis
//                                der angepasst ist
//              Sissi (17.01.99)  Unterschiede werden nun in unterschiedlichen
//                                Dateien geloggt, je nach Zugriffsziel.
//              Sissi (18.01.99)  Map - Raeume koennen nun auch ACL - Rechte
//                                bekommen.
//              Sissi (05.02.99)  rename nimmt jetzt die direkt vorhergehende
//                                Anfrage, um zu ermitteln, ob es sich um
//                                eine Datei oder ein Verzeichnis handelt,
//                                das umbenannt werden soll.
//              Sissi (05.04.99)  ACLs gewinnen.
//		Freaky (07.01.1999) valid_syslog rausgeschmissen
//			valid_write_acl: den map2domain-Aufruf verbessert.
//		Freaky (06.11.1999) copy_file, rename_from, rename_to rein
//              Sissi  (06.11.1999) rename_from und rename_to nutzen jetzt
//                                  ihr spezielles Wissen darueber aus,
//                                  um was fuer eine Operation es sich
//                                  handelt.
//		Freaky (23.11.1999) dumpallobj eingebaut
//		Freaky (07.06.2000) "do_rename" auskommentiert
//		Freaky (17.06.2000) in Orbit werden Files nach
//				    /save/ORBIT_WRITE geschriebenm damit in
//				    UNItopia die Files nicht zerstoert werden
//
//
// $Log: valid_write.inc,v $
// Revision 1.39  2016/03/21 12:41:47  gnomi
// strlen -> sizeof
//
// Revision 1.38  2016/01/23 17:50:22  myonara
// /var/schiffsmoebel ergaenzt.
//
// Revision 1.37  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.36  2009/04/15 13:43:45  gnomi
// log/save-Gebrauch mitloggen.
//
// Revision 1.35  2009-01-15 09:21:41  gnomi
// Workomat udn Spendeanzeige nutzen nun /var-Savefile.
// (Auch, wenn sie nicht aktiv sind.)
//
// Revision 1.34  2008-04-04 13:33:36  gnomi
// Fehlermeldung, wenn jemand direkt in /d versucht zu schreiben, rausgenommen.
//
// Revision 1.33  2007/12/05 11:16:45  gnomi
// Orbit-Schreibzugriffe nach /var/spool besser nach /var/adm/ORBIT_WRITE
// umleiten. Orbit-Markierungen im /var-Verzeichnis zum Debuggen mit Trace
// versehen.
//
// Revision 1.32  2007/02/04 22:03:01  gnomi
// Sonderbehandlungen fuer Levitanis.
//
// Revision 1.31  2006/12/30 00:58:15  gnomi
// DEST_OBJ_DUMP auch zulassen.
//
// Revision 1.30  2006/08/29 22:36:20  gnomi
// Orbit: Merken, wenn eine Datei geloescht wird (damit sie beim naechsten
// Zugriff nicht mehr aus UNI kopiert wird).
//
// Revision 1.29  2006/08/03 09:53:21  gnomi
// Schattenverzeichnisse fuer Orbit.
//
// Revision 1.28  2005/12/18 21:36:06  gnomi
// sl_open aufgenommen.
//
// Revision 1.27  2005/10/24 20:52:14  gnomi
// Umleitung nach ORBIT_WRITE abschalten, wenn UnionFS definiert ist.
//
// Revision 1.26  2005/02/02 22:30:00  gnomi
// /pub/incoming-Rechte wie beim anonymous-Zugang festgelegt.
//
// Revision 1.25  2004/07/04 00:21:15  gnomi
// Statt in /log/sys/INVALID_WRITE zu schreiben wird ein Fehler geworfen.
//
// Revision 1.24  2003/05/13 02:03:27  menaures
// Behandlung fuer neues /var/intern eingebaut
//
// Revision 1.23  2002/11/07 01:12:43  gnomi
// Umbenennungen nicht vorhandener Dateien/Verzeichnisse werden nicht
// abgelehnt, da Objekte dies teilweise auf Verdacht (z.B. fuer Backups)
// machen. Der Driver wird die Umbenennung dann schon selbst ablehnen.
//
// Revision 1.22  2002/10/20 16:15:16  sissi
// In /w/<gottname>/.pfadkuerzel duerfen bereits bei Lehrmingen die
// Pfadkuerzel abgespeichert werden.
//
// Revision 1.21  2002/02/24 06:36:55  gnomi
// Bei 'zern -t' umbenannte Objekte erhalten die gleichen Rechte, wie die
// Originale.
//
// Revision 1.20  2002/02/01 08:15:22  gnomi
// Playerob darf nach /var/players/debug schreiben.
//
// Revision 1.19  2001/12/20 22:32:33  gnomi
// Schreibzugriff auf /log/grep verbieten.
//
// Revision 1.18  2001/07/03 11:28:49  gnomi
// In Orbit wird nach INVALID_WRITE.ORBIT geloggt.
//
// Revision 1.17  2001/05/30 10:55:59  freaky
// write in /w/.../save und log zulassen
//
// Revision 1.16  2001/04/22 22:29:33  gnomi
// write_bytes zulassen.
//
// Revision 1.15  2001/04/06 22:30:31  gnomi
// Player duerfen nur save_object in /var/players nutzen.
// (Damit man im Player ein paar Funktionen fuer Goetter einbauen kann.)
//
// Revision 1.14  2001/04/06 22:24:51  gnomi
// /apps/offline_appreciations rausgenommen: ist umgezogen und hat UID "Root".
//
// Revision 1.13  2001/03/13 11:22:32  freaky
// dumpallobj wieder freigegeben.
//
// Revision 1.12  2001/03/13 00:40:52  freaky
// dumpallobj sichern
//
// Revision 1.11  2001/02/16 23:57:16  sissi
// Offline Wuerdigungen eintragen.
//
// Revision 1.10  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

static int last_to_rename_was;
#define LAST_TO_RENAME_WAS_FILE 1
#define LAST_TO_RENAME_WAS_DIR 2
#define LAST_TO_RENAME_WAS_NOTHING 0

/*
 * This is the function called from the game driver when it wants to know
 * if it has permission to write in file 'file_name' with effective user
 * 'eff_user'. The return value is simply true or false.
 */


/*
 * Function name:   valid_write
 * Description:     Checks if a certain user has the right to write a file
 * Arguments:       file - File name of the file to be written
 *                  eff_user - Name of the wizard responsible for the write.
 *		    func - The calling function.
 * Returns:         True if write is allowed.
 */

mixed valid_write_acl(string file, string eff_user, string func, object caller)
{
    string *path, mapname, logfile;
    int filesize, acl_mask;

#if 0
    if (find_player("freaky"))
	tell_object(find_player("freaky"),"WRITE:File name:"+file+", effective user:"+
	  eff_user+",\nfunc:"+func+", caller:"+(caller?object_name(caller):0)+".\n"+sprintf("PO:%O\n",previous_object()));
#endif

    if (!file || !eff_user || file[0] != '/' ||
    		strstr(file,"//") >= 0 || strstr(file,"/./") >= 0)
	return 0;

    path = explode(file[1..],"/");

    if (sizeof(path) < 2)
    {
	// fuer 'dumpallobj'
	if (func == "objdump" &&
	    (file == "/OBJ_DUMP" || file=="/DEST_OBJ_DUMP"))
	{
	    if (this_interactive() && wizp(this_interactive()) &&
	       	previous_object() == this_interactive() &&
		this_player() == this_interactive() &&
		caller == this_interactive())
		return "/log/sys"+file;
	    if (object_name(caller) == "/room/rathaus/div/shut")
		return "/log/sys"+file;
	}
	return 0;
    }

    switch(path[0])
    {
        case "map":
	    return eff_user==ROOT_UID;
        case "var":
	    if (eff_user==ROOT_UID || eff_user==APPS_UID)
#if defined(Orbit) && !defined(UnionFS)
	    {
		if (path[1] == "spool")
		    return "/var/adm/ORBIT_WRITE";
	        return 1;
	    }
#else
	        return 1;
#endif
            if(sizeof(path) == 3 && path[1] == "intern" &&
               object_name(caller) == "/room/rathaus/div/leo")
               return 1;
	      
	    if(sizeof(path) == 2 && !strstr(path[1], "workomat") &&
		object_name(caller) == "/room/rathaus/traegerkreis/touch/worko")
		return 1;

	    if(sizeof(path) == 2 && !strstr(path[1], "spende") &&
		object_name(caller) == "/room/rathaus/traegerkreis/obj/spende")
		return 1;
#ifdef UNItopia
            if (sizeof(path)==3 && path[1] == "schiffsmoebel" &&
                  object_name(caller) == "/p/Schiffe/Moebel/apps/moebel")
                return 1;
#endif

	    return (sizeof(path)==4 && path[1] == "players" &&
                    playerp(previous_object()) &&
		    (func == "save_object" ||
		    (func=="write_file" && sizeof(path)==4 && path[2]=="debug")) &&
		    !wizardshellp(previous_object()));
        case "d":
        case "z":
        case "p":
            switch (func)
	    {
                case "mkdir":
                    acl_mask = ACL_MKDIR;
		    break;
                case "rmdir":
                    acl_mask = ACL_RMDIR;
		    break;
                case "remove_file":
                    acl_mask = ACL_REMOVE;
		    break;
                case "write":
                case "write_file":
                case "write_bytes":
                case "ed_start":
                case "write_test":
		case "copy_file":
		case "sl_open":
                    // ed_start wird nicht beim starten von ed
                    // benutzt, sondern beim schreiben via ed,
                    // und zwar egal, ob die Datei existiert
                    // oder nicht.
                    if ((filesize = file_size (file)) >= 0)
                        // existierende Datei schreiben
                        acl_mask = ACL_WRITE;
                    else if (filesize == -1)
                         // nicht vorhandene Datei schreiben
                        acl_mask = ACL_CREATE;
                    else if (filesize == -2)
                        // Sonderbehandlung FTP - Server, bis der an
                        // die ACLs angepasst ist
                        if (previous_object() && 
                            (object_name(previous_object()) == "/secure/udp/ftpserv"))
                            acl_mask = ACL_CREATE | ACL_WRITE | ACL_REMOVE;
                        else
                            return 0; // Verzeichnisse werden nicht geschrieben.
                    else // kann eigentlich nicht passieren.
                        return 0;
                    break;
                case "rename_from":
                    if ((filesize = file_size (file)) >= 0) {
			// es ist eine Datei, die bewegt werden soll
                        acl_mask = ACL_REMOVE;
                        last_to_rename_was = LAST_TO_RENAME_WAS_FILE;
                    }
                    else if (filesize == -2) {
			// ein Verzeichnis soll umbenannt werden:
                        acl_mask = ACL_RMDIR;
                        last_to_rename_was = LAST_TO_RENAME_WAS_DIR;
                    }
                    else if (filesize == -1) {
                        // die Datei existiert nicht, wie um Himmels
			// Willen soll sie dann umbenannt werden?
                        last_to_rename_was = LAST_TO_RENAME_WAS_NOTHING;
			// sowas geht natuerlich nicht, aber wir schmettern es
			// nicht ab, da diverse Tools wegen Backups Umbenennungen
			// auf Verdacht durchfuehren. Der Driver wird es ablehnen.
			return 1;
                    }
                    break;
                case "rename_to":
                    if ((filesize = file_size (file)) >= 0) {
                        // die Datei existiert bereits, also soll eine
                        // bestehende Datei durch eine andere Datei
                        // ueberschrieben werden, daher:
                        acl_mask = ACL_REMOVE | ACL_WRITE;
                    }
                    else if (filesize == -2) {
                        // ein bestehendes Verzeichnis soll duch ein
			// neues Verzeichnis ueberschrieben werden...
			// geht sowas ueberhaupt? Egal, die ACLs dafuer
			// stehen in jedem Falle fest:
                        acl_mask = ACL_RMDIR | ACL_MKDIR;
                    }
                    else if (filesize == -1) {
                        // die Datei existiert nicht. In Last_to_rename_was steht,
                        // ob es eine Datei oder ein Verzeichnis war.
                        if (last_to_rename_was == LAST_TO_RENAME_WAS_DIR)
                            acl_mask = ACL_MKDIR;
                        else if (last_to_rename_was == LAST_TO_RENAME_WAS_FILE)
                            acl_mask = ACL_CREATE;
                        else acl_mask = ACL_CREATE | ACL_MKDIR;
                            // wenn wirs nicht wissen, gehen wir auf Nummer sicher
                    }
                    last_to_rename_was = LAST_TO_RENAME_WAS_NOTHING;
                    break;
#if 0
                case "do_rename":
                    // Das ist boese: do_rename wird fuer den Ursprungspfad
                    // und fuer den Zielpfad aufgerufen, aber es ist jetzt
                    // nicht klar, ob der Aufruf fuer den Urpsungs- oder
                    // fuer den Zielpfad erfolgt...
                    // Es ist an dieser Stelle nichtmal klar, ob es sich um
                    // eine Datei oder ein Verzeichnis handelt.
                    // Dies merkt ich mir mit last_to_rename_was, aber wehe,
                    // in einem zukuenftigen Driver wird die Abfragereihen-
                    // folge mal geaendert, dann muss man hier was tun.
                    // Wobei es total komplett unlogisch waere, die
                    // Reinenfolge zu aendern.
                    if ((filesize = file_size (file)) >= 0) {
                        // die Datei existiert bereits, also muss es sich
                        // um die Ausgangsdatei handeln, oder sie wird
                        // eine andere Datei ueberschrieben; und es ist
                        // kein Verzeichnis, daher:
                        acl_mask = ACL_REMOVE | ACL_WRITE;
                        last_to_rename_was = LAST_TO_RENAME_WAS_FILE;
                    }
                    else if (filesize == -2) {
                        // die Datei existiert bereits, also muss es sich
                        // um die Ausgangsdatei handeln oder um das Ziel;
                        // und es ist ein Verzeichnis, daher:
                        acl_mask = ACL_RMDIR | ACL_MKDIR;
                        last_to_rename_was = LAST_TO_RENAME_WAS_DIR;
                    }
                    else if (filesize == -1) {
                        // die Datei existiert nicht, also muss es sich um
                        // das Ziel handeln. In Last_to_rename_was steht,
                        // ob es eine Datei oder ein Verzeichnis war.
                        if (last_to_rename_was == LAST_TO_RENAME_WAS_DIR)
                            acl_mask = ACL_MKDIR;
                        else if (last_to_rename_was == LAST_TO_RENAME_WAS_FILE)
                            acl_mask = ACL_CREATE;
                        else acl_mask = ACL_CREATE | ACL_MKDIR;
                            // wenn wirs nicht wissen, gehen wir auf Nummer sicher
                        last_to_rename_was = LAST_TO_RENAME_WAS_NOTHING;
                    }
                    break;
#endif
                case "save_object":
                    // erstmal bei Clones den #1234 - Teil abschneiden:
                    if (!caller || !objectp (caller)) return 0;
                    eff_user = object_name(caller);
                    if (strstr (eff_user,"#") != -1)
                        eff_user = implode (explode (eff_user,"#")[0..<2],"#");
		    // Bei 'zern -t' den umbenannten Objekten die
		    // gleichen Rechte einraeumen, wie den Originalen.
		    eff_user = regreplace(eff_user, "\\$(.*)\\$[0-9]*$", "\\1", 0);
                    acl_mask = ACL_SAVE;
                    break;
                    // restore_object geht an valid_read
		default:
		    write_file("/log/sys/MASTER","Unbekannter Write-Aufruf: '" + func + "'\n");
            } // switch (func)
	    
#ifdef UNItopia
	    if(!strstr(file, "/d/Levitanis/") && sizeof(path)>3)
	    {
		if(path[2]=="wiz")
		{
		    if((acl_mask & ACL_SAVE) || path[3]!=eff_user ||
			!GOETTER_REGISTER->query_lehrmeister(eff_user,2)) // Ein Vogt?
			    return 0;
		    return 1;
		}
		else if(path[2]=="public")
		{
		    if(acl_mask & ACL_SAVE)
			return 0;
		
		    if(!GOETTER_REGISTER->query_lehrmeister(eff_user,2))
			return 0;
			
		    if(file[<4..<1]==".log")
			return 0;
		    
		    if((acl_mask&(ACL_WRITE|ACL_CREATE|ACL_REMOVE)) && func != "write_test")
		    {
			string logname;
			int logsize;
			string timestamp;
			string previous;
			
			logname = (file[<2..<1]==".c"?file[0..<3]:file) + ".log";
			logname[12..11] = "/log";

			while((logsize=strstr(logname,"/",logsize+1))>=0)
			    if(file_size(logname[0..logsize-1])==FSIZE_NOFILE)
				mkdir(logname[0..logsize-1]);
			
			logsize = file_size(logname);
			
			// Wenn das Logfile ein Verzeichnis ist, dann halt nicht.
			if(logsize == FSIZE_DIR)
			    return 0;
			
			timestamp = funcall(symbol_function("shorttimestr"),time());
			
			if(logsize >= 50)
			    previous = trim(lower_case(read_bytes(logname, logsize-11, 10)));
			
			if(previous==eff_user)
			    write_bytes(logname, logsize-30, timestamp);
			else
			    write_file(logname, sprintf("%s - %s: %-10s",
				timestamp,timestamp,capitalize(eff_user))+"\n");
			
			GROUP_MASTER->add_group_member(eff_user, "Levitanis:Goetter");
			
		    }
		    return 1;
		}
	    }
#endif

            // Objekte aus /p, /z oder /d haben in Zukunft keine Rechte mehr
            // auf Grund ihrer effektiven UserID sondern nur noch auf Grund
            // der explizit fuer sie bei den ACLs eingetragenen Rechte.
            // Daher wird bei diesen Objekten nicht ihre effektive UserID
            // sondern ihr Dateinamen verwendet.
            // Spaeter, wenn das alte System nicht mehr parallel laeuft,
            // bietet es sich an, allen Objekten aus /p /d /z als
            // effektive UserID ihren Dateinamen zu setzen, dadurch wird
            // das hier alles dann viel einfacher... Bis dahin:

            // Im Fall von ACL_SAVE ist schon alles getan.
            if ((acl_mask != ACL_SAVE) && (strstr(eff_user,":") != -1)) {
                if (!caller || !objectp(caller)) return 0;
                eff_user = object_name(caller);
                if (strstr (eff_user,"#") != -1)
                    eff_user = implode(explode(eff_user,"#")[0..<2],"#");
		// Bei 'zern -t' den umbenannten Objekten die
		// gleichen Rechte einraeumen, wie den Originalen.
		eff_user = regreplace(eff_user, "\\$(.*)\\$[0-9]*$", "\\1", 0);
            }
            // Wenn es ein Map-Raum ist, dann muessen wir map2domain
            // darauf anwenden und das abschliessende .c wegschneiden.
	    // Freaky: map2domain kann auch 0 liefern. Deswegen besser
	    // ueberpruefen. Ausserdem muss ja auch /map/xxx moeglich sein.
	    if (eff_user[0..3] == "/map")
	    {
		mapname = funcall(symbol_function("map2domain"),eff_user,1);
		if (mapname)
		    eff_user = mapname[0..<3];
	    }
#if defined(Orbit) && !defined(UnionFS)
            if(query_access(path,eff_user,acl_mask))
	    {
                if(func == "write_test")
                {
                    // Kopie erst bei tatsaechlichem Schreibzugriff erstellen.
                    return 1;
                }

		string destfile = "/var"+file;
		
		if(file_size(destfile+".__mark__")<0 &&
		   file_size(destfile)<0)
		{
		    string fulldir="/var";
		    foreach(string dir: path[0..<2])
		    {
			fulldir += "/" + dir;
			mkdir(fulldir);
		    }
		
		    if(file_size(file)>=0)
			copy_file(file, "/var"+file);
		}

                // In __mark__ zusaetzlich noch einen Trace schreiben,
                // um mysterioese Schreibzugriffe nachvollziehen zu koennen.
                write_file(destfile+".__mark__",
                    sprintf("time: %d, file: %s, eff_user: %s, " 
                            "func: %s, caller: %O\n",
                            time(),file,eff_user,func,caller)+
#if __EFUN_DEFINED__(driver_info)
                    efun::driver_info(DI_TRACE_CURRENT_AS_STRING)+"\n");
#else
                    efun::debug_info(DINFO_TRACE,DIT_STR_CURRENT)+"\n");
#endif
		
		return destfile;
	    }
	    else
		return 0;
#else
            return query_access(path,eff_user,acl_mask);
#endif
        case "log":
	    //return eff_user==ROOT_UID || (path[1]!="sys" && path[1]!="grep" && func!="mkdir");
	    if(path[1]=="sys" || path[1]=="grep" || func=="mkdir")
		return eff_user==ROOT_UID;
	
	    // FALLTHROUGH
	    logfile = "/log/sys/LOGFILES";
        case "save":
	    logfile ||= "/log/sys/SAVEFILES";
	    
	    if(func != "write_test")
    		write_file(logfile,
		    sprintf("[%s] File name: %s, func: %s, caller: %O\n",
			ctime(),
			to_string(file),to_string(func),caller));
	    return 1;
	case "pub":
	    if (sizeof(path)>2 && path[1]=="incoming")
		return 1;
	    return 0;
        case "w":
	    // unter /w/<name>/.../log/ und /save/ duerfen auch Objekte
	    // mit UID w:<name> schreiben.
	    if (member(path,"log") > 1 || member(path,"save") > 1)
		if (eff_user == ("w:" + path[1]))
		    return 1;
            // Ausnahme fuer /w/<gottname>/.pfadkuerzel:
            if (eff_user == "Learner" && sizeof(path) == 3
                && playerp (caller) && ({string})caller->query_real_name()==path[1]
                && path[2] == ".pfadkuerzel")
                return 1;
	    return path[1]==eff_user || eff_user==ROOT_UID;
    }
}

mixed valid_write(string file, string eff_user, string func, object caller)
{
    int permission;
    string logziel;

#if 0
    if (find_player("sissi"))
	tell_object(find_player("sissi"),"WRITE:File name:"+file+
		", effective user:"+ eff_user+",\nfunc:"+func+", caller:"+
		(caller?object_name(caller):0)+".\n" +
		sprintf("PO:%O\n",previous_object()));
#endif

    // der Master darf alles
    if (caller == this_object())
	return 1;

    permission = valid_write_acl(file, eff_user, func, caller);

    if (!permission && (func != "write_test"))
    {
        if (!file || !stringp(file) || !sizeof(file))
	    logziel = 0;
	else if (file [0..2] == "/p/")
	    logziel = "/p";
	else if ((file [0..2] == "/d/") || (file [0..2] == "/z/"))
	    logziel = implode(explode(file,"/")[0..2],"/");

        if (logziel && file_size(logziel) == -2)
#if defined(Orbit) && !defined(UnionFS)
        	write_file(logziel + "/INVALID_WRITE.ORBIT",
#else
        	write_file(logziel + "/INVALID_WRITE",
#endif
		    sprintf("%s File name: %s, effective user: %s\n    "
			"func: %s, caller: %O\nPO: %O\n\n",
			ctime(),
			to_string(file),to_string(eff_user),to_string(func),
			caller,previous_object()));
    }
    return permission;
}
