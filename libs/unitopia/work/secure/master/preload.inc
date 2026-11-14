// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/preload.inc
// Description:
//
// $Log: preload.inc,v $
// Revision 1.6  2008/03/04 11:00:22  gnomi
// Unterstuetzung fuer verteiltes LOAD_AT_STARTUP.
//
// Revision 1.5  2006/01/22 01:09:23  gnomi
// Flags bei debug_message angeben.
//
// Revision 1.4  2001/03/13 22:53:22  freaky
// einige Funktionen protected machen.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

/*
 * Load an Object at Startup.
 */
#define DMSG_PRELOAD (DMSG_STDOUT | DMSG_LOGFILE)
protected void preload(string file)
{
    mixed *us, us2;
    int t1, ev;
    string err;

    if (file[0] == '!')
    {
	// Einfach Meldungen ausgeben...
	debug_message(file[1..]+"\n", DMSG_PRELOAD);
	return;
    }

    if (file[<2..] == ".c")
	file = file[0..<3];
    if (file_size(file + ".c") == -1)
    {
	debug_message("Preloading: File '" + file + "' not found.\n", DMSG_PRELOAD);
	return;
    }

    debug_message(sprintf("Preloading: %-49s",file), DMSG_PRELOAD);
    ev = get_eval_cost();
    us = rusage();
    err = catch(load_object(file));
    us2 = rusage();
    if (err)
	debug_message("\nGot error " + err + " while loading " + file, DMSG_PRELOAD);
    t1 = us2[0] + us2[1] - us[0] - us[1];
    debug_message(sprintf(" %4d ms %6d ev\n",t1,ev - get_eval_cost()), DMSG_PRELOAD);
    // Damit der Offset stimmt fuer den ersten Fehler.
    get_debugfile_offset();
}
