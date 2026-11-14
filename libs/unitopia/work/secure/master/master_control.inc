// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/master_control.inc
// Description: Funktionen zur Steuerung des Masterobjects
//
// $Log: master_control.inc,v $
// Revision 1.37  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.36  2015/07/27 19:13:20  gnomi
// Umbau wegen Driver-Leak
//
// Revision 1.35  2015/07/27 16:45:42  gnomi
// Arma wegen Speicher erst nach einem Tag.
//
// Revision 1.34  2015/04/28 17:28:42  gnomi
// LIMIT_EVAL auf 1000000 gesetzt.
//
// Revision 1.33  2013-03-16 15:57:17  gnomi
// DC_LONG_EXEC_TIME auf 0.5s hochgesetzt.
//
// Revision 1.32  2011-12-11 19:59:03  sorcerer
// DC_LONG_EXEC_TIME auf 200000 gesetzt
//
// Revision 1.31  2006/08/03 09:52:37  gnomi
// Mails an Admins, wenn der Speicher knapp wird (bei slow_shut_down).
//
// Revision 1.30  2006/07/28 16:21:12  gnomi
// slow_shut-Zeit auf 60 Minuten hochgesetzt, wir haben schliesslich einen
// Puffer von 128 MB.
//
// Revision 1.29  2005/11/05 02:30:06  gnomi
// Der Game-Driver plenkt.
//
// Revision 1.28  2004/07/19 21:32:55  gnomi
// Domains brauchen nicht mehr geladen werden.
//
// Revision 1.27  2003/01/17 01:48:56  gnomi
// Mudlib-Privilegien aus /static/adm/MUDLIB_PRIVILEGES einlesen.
//
// Revision 1.26  2002/10/19 01:23:35  gnomi
// notify_shutdown: Parameter crash_reason hinzugefuegt.
//
// Revision 1.25  2002/10/17 13:47:07  freaky
// Versionsabhaengigkeit entfernt
//
// Revision 1.24  2001/11/18 16:56:20  freaky
// an ldmud-3.2.9dev363 angepasst.
//
// Revision 1.23  2001/11/18 01:53:41  freaky
// typo fixed
//
// Revision 1.22  2001/10/01 17:52:56  freaky
// ab jetzt arbeitet UNItopia nur noch mit Drivern ohne deprecated Funktionen.
//
// Revision 1.21  2001/08/28 23:26:21  freaky
// Driver-Shutdown sollten alle mitbekommen -> efun::tell-object
//
// Revision 1.20  2001/08/28 23:21:25  freaky
// message-system jetzt default
//
// Revision 1.19  2001/08/28 19:53:36  freaky
// auf deprecated umgestellt
//
// Revision 1.18  2001/08/25 00:55:22  freaky
// *** empty log message ***
//
// Revision 1.17  2001/08/23 19:45:02  freaky
// Versionsabhaengigkeiten geloescht
//
// Revision 1.16  2001/08/12 11:36:22  freaky
// slow_shut_down: Typo gefixed und tell_object zu efun:: umgewandelt
//
// Revision 1.15  2001/07/26 15:56:28  freaky
// Doppelte Defines entfernt.
//
// Revision 1.14  2001/07/03 23:50:16  freaky
// default private erstmal nur im Testmud
//
// Revision 1.13  2001/07/02 02:31:52  freaky
// check auf Version korrigiert.
//
// Revision 1.12  2001/07/02 01:49:36  freaky
// Anpassungen fuer dev305
//
// Revision 1.11  2001/04/19 23:39:50  freaky
// room-autoloads nach /apps/room_autoload gemoved.
//
// Revision 1.10  2001/04/13 13:49:48  freaky
// UID-Handling ueberarbeitet.
//
// Revision 1.9  2001/03/16 02:47:23  freaky
// Kompatibiltaet zu ldmud-3.3 eingebaut.
//
// Revision 1.8  2001/03/15 23:52:48  freaky
// Speicherlimit Berechnung mit debug-info eingebaut.
//
// Revision 1.7  2001/03/13 22:53:22  freaky
// einige Funktionen protected machen.
//
// Revision 1.6  2001/03/12 22:42:56  freaky
// slow_shut_down() verbessert.
//
// Revision 1.5  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

protected void notify_shutdown(string crash_reason)
{
    /*
    if (previous_object() && previous_object() != this_object())
	return;
    */
#ifdef LOG_SHUTDOWN
    if(crash_reason)
	write_file("/log/sys/SHUT", "Crash: "+crash_reason+"\n");
    write_file("/log/sys/SHUT", "-- "+ctime(time())+"   "+__VERSION__+"\n");
#endif
    ERROR_DB->save_error_db();
}

protected void external_master_reload()
{
    filter(efun::users(),#'efun::tell_object,
	"\nGame-Driver bruellt: Maschinen-Reboot!\n\n");
    "/room/rathaus/div/shut"->shut(5);
}

protected void slow_shut_down(int minutes)
{
    /*
    if (previous_object() && previous_object() != this_object())
    {
	write_file("/log/sys/MASTER",
		sprintf("slow_shut_down: PO:%O TP:%O TO:%O min:%O\n",
		previous_object(),this_player(),this_object(),minutes));
	return;
    }
    */

    write_file("/log/sys/SHUT","Calling slow_shut_down: " + ctime() +
	    " (with argument: " + minutes + ")\n");
    filter(efun::users(),#'efun::tell_object,
	"\nGame-Driver bruellt: Der Speicher wird knapp!\n\n");
    "/room/rathaus/div/shut"->shut(minutes || 5);

    MAILD->send_to_admin("Shutdown in "+minutes+" Minuten",
	sprintf("Es wurde slow_shut_down(%d) aufgerufen.\n"
	        "%s wird daher um diese Zeit neu gestartet: %s\n\n"
	        "MAX_MALLOC_SIZE (Mudlib-Grenze): %d\n"
		"__MAX_MALLOC__  (Driver-Grenze): %d\n"
	        "Vom Betriebssystem allokiert:    %d\n"
                "In Verwendung:                   %d\n"
		"Frei:                            %d\n\n",
		minutes, MUD_NAME, ctime(time()+30*60),
		MAX_MALLOC_SIZE, __MAX_MALLOC__,
#if __EFUN_DEFINED__(driver_info)
		efun::driver_info(DI_SIZE_SYS_ALLOCATED_BLOCKS),
		efun::driver_info(DI_SIZE_MEMORY_USED) + efun::driver_info(DI_SIZE_MEMORY_OVERHEAD),
		efun::driver_info(DI_SIZE_MEMORY_UNUSED))
	+efun::driver_info(DI_STATUS_TEXT_MALLOC)+"\n"
	+efun::driver_info(DI_STATUS_TEXT_TABLES));
#else
		efun::debug_info(DINFO_DATA, DID_MEMORY, DID_MEM_SBRK_SIZE),
		efun::debug_info(DINFO_DATA, DID_MEMORY, DID_MEM_ALLOCATED),
		efun::debug_info(DINFO_DATA, DID_MEMORY, DID_MEM_TOTAL_UNUSED))
	+efun::debug_info(DINFO_STATUS,"malloc")+"\n"
	+efun::debug_info(DINFO_STATUS,"tables"));
#endif
}

#ifdef MAX_MALLOC_SIZE
void reset()
{
#if __EFUN_DEFINED__(driver_info)
    if (efun::driver_info(DI_SIZE_MEMORY_USED) >= MAX_MALLOC_SIZE)
#else
    if (efun::debug_info(DINFO_DATA, DID_MEMORY)[DID_MEM_ALLOCATED] >= MAX_MALLOC_SIZE)
#endif
	slow_shut_down(1440);
}
#endif

/*
 * Diese Funktion wird aufgerufen, wenn das Laden des neuen Masters nicht
 * funktioniert.
 * Das Flag ist gesetzt wenn die alten Variablen preserved sind
 * bzw. wenn der Master bereits auf der Liste der zerstoerten Objekte war.
 */
protected void reactivate_destructed_master(int flag) {}

void read_variables(string what)
{
    if (!what)
	return;
    switch (what)
    {
      case "all":
	get_light_descriptions();
	get_skills();
	get_valid_shells();
	get_debugfile_offset();
	get_privis();
	restore_object(MASTER_SAVE_FILE);
	break;
      case "skills":
	get_skills();
	break;
    }
}

/*
 * Diese Funktion wird aufgerufen sobald der Master als Master vom Driver
 * anerkannt wurde, d.h. wenn er alle Privilegien eines Masters hat
 */
protected void inaugurate_master(int i)
{

    // if (i==0 && previous_object()==this_object())
    if (i == 0)
    {
	if (!get_extra_wizinfo(0))
	{
	    set_extra_wizinfo(0,(["start":time()]));
#ifdef LOG_SHUTDOWN
	    write_file("/log/sys/SHUT","%% "+MUD_NAME+" started at "+
		ctime(time())+"   "+__VERSION__+"\n");
#endif
	}
	else
	{
	    write_file("/log/sys/MASTER","Called inaugurate_master illegally:"+
		sprintf("TI:%O:\n",this_interactive()));
	}
    }

    setup_driver_hooks();
    read_variables("all");
#if __VERSION__ > "3.5.0-3000"
    // 100 MB should be enough for everyone. ;-)
#if __EFUN_DEFINED__(set_limits)
    set_limits(LIMIT_MEMORY, 100000000);
    set_limits(LIMIT_EVAL, 1000000);
#else
    int* limits = ({LIMIT_KEEP}) * LIMIT_MAX;
    limits[LIMIT_MEMORY] = 100000000;
    limits[LIMIT_EVAL]   = 1000000;
    configure_driver(DC_DEFAULT_RUNTIME_LIMITS, limits);
#endif
    // Nach 0.1s loggen.
    configure_driver(DC_LONG_EXEC_TIME, 500000);
#endif
}
