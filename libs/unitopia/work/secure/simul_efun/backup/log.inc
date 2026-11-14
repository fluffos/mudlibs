// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/log.inc
// Description:	Funktionen zum Logging
// Author:	Freaky
// Modified by: Freaky (08.02.1999) sys_log: check eingebaut
//		Freaky (14.04.2000) log_file: auch volle Filenamen zulassen
//
// $Log: log.inc,v $
// Revision 1.12  2015/08/26 21:40:30  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.11  2004/07/04 00:21:55  gnomi
// Statt in /log/sys/SYSLOG zu schreiben wird ein Fehler geworfen.
//
// Revision 1.10  2002/07/27 23:58:14  gnomi
// sys_log auch aus Mudlib-Inherits zulassen, die ausserhalb der Mudlib genutzt
// werden.
//
// Revision 1.9  2001/05/30 15:04:38  freaky
// log-file auf file-path umgestellt.
//
// Revision 1.8  2001/05/30 11:12:53  freaky
// prototype eingefuehrt.
//
// Revision 1.7  2001/05/30 09:43:09  freaky
// log-file laesst jetzt auch lokale Pfade zu.
//
// Revision 1.6  2001/04/26 20:53:23  sissi
// call out - simul efun hinzugefuegt.
//
// Revision 1.5  2001/04/20 13:15:41  freaky
// log_file(): logging nur noch in log-Verzeichnise
//
// Revision 1.4  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
#pragma save_types

varargs string abs_path(string path, string absolute);
varargs string file_path(object ob);

/*
FUNKTION: log_file
DEKLARATION: int log_file(string file_name, string message)
BESCHREIBUNG:
Haengt den String <message> an das File <file_name> an.
Wenn man keinen vollstaendigen Filenamen angibt, wird in das File
/log/<file_name> geschrieben.
Ein vollstaendig angegebener Filename muss '.../log/...' beinhalten,
sonst wird nicht gelogged.
Man kann auch lokale Pfade angeben. Diese muessen aber mindestens
einen '/' enthalten, sonst wird nach /log/<file_name> gelogged.
Die Datei wird, wenn sie groesser als 50000 Bytes wird, nach <file_name>.old
umbenannt.
Ist fuer Debuggingzwecke oder zum Mitloggen.
Rueckgabewert: 1 wenn das Schreiben geklappt hat, sonst 0

Beispiele:
    log_file("testlog","Meldung\n");	logged nach /log/testlog
    log_file("/d/Doerrland/log/testlog","Meldung\n");
    log_file("../log/testlog","Meldung\n");
    log_file("log/testlog","Meldung\n");
GRUPPEN: simul_efun, file
VERWEISE: write_file
*/
int log_file(string file, string mess)
{
    int size, ret;
    object to;

    if (file[0] != '/')
    {
	if (member(file,'/') < 0)
	    file = "/log/" + file;
        else if (strstr(file,"/log/") != -1 || strstr(file,"log/") == 0)
	    file = abs_path(file,file_path(previous_object()));
	else
	    return 0;
    }
    else if (strstr(file,"/log/") == -1)
    {
	return 0;
    }

    size = file_size(file);

    to = this_object();
    set_this_object(previous_object());

    if (size > 50000)
    {
	if (rename(file,file + ".old"))
	    return 0;
	size = -1;
    }

    if (size < 5)
	write_file(file,sprintf("PO:%O  UID:%s\n",this_object(),getuid()));
    
    ret = write_file(file,mess);
    set_this_object(to);
    return ret;
}

/*
FUNKTION: sys_log
DEKLARATION: void sys_log(string file_name, string message)
BESCHREIBUNG:
Haengt den String 'message' an das file /log/sys/<file_name> an.
Ist fuer Debuggingzwecke oder zum Mitloggen von Systemdaten.
Steht nicht fuer normale Objekte zur Verfuegung.
GRUPPEN: simul_efun, file
VERWEISE: write_file, log_file
*/
void sys_log(string fil, string mess)
{
    string dir;
    
    dir = explode(object_name(previous_object()),"/")[1];
    if (!extern_call() || member(({"obj","secure","apps","room"}),dir) >= 0)
    {
	write_file("/log/sys/"+fil,mess);
	return;
    }
    else
    {
#if __EFUN_DEFINED__(driver_info)
	mixed trace = efun::driver_info(DI_TRACE_CURRENT);
#else
	mixed trace = efun::debug_info(DINFO_TRACE,DIT_CURRENT);
#endif
	string prog = trace[<2] && trace[<2][TRACE_PROGRAM];
	if(stringp(prog) && member(({"i","obj"}), explode(prog,"/")[0])>=0)
	{
	    write_file("/log/sys/"+fil, mess);
	    return;
	}

	switch(fil)
	{
	    case "set_weight":
	    case "shop_teuer":
		write_file("/log/sys/"+fil,mess);
	    	return;
	    default:
		do_error(sprintf("Invalid syslog '%s':\n%s",fil,mess));
		break;
	}
    }
}
