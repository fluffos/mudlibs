// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zsysinfo.inc
// Description:	Zeigt System-Informationen des Drivers an
// Author:	Freaky (1998)
// Modified by:	Freaky (20.09.2000) in den Zauberstab integriert.
//
// $Log: zsysinfo.inc,v $
// Revision 1.5  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.4  2015/07/04 12:12:11  myonara
// neuer Befehl zobst
//
// Revision 1.3  2001/11/12 13:27:18  freaky
// Driver-Version eingebaut
//
// Revision 1.2  2000/09/25 00:07:36  freaky
// Berechnung der Objektzahl rausgenommen.
//
// Revision 1.1  2000/09/20 12:27:14  freaky
// vom ftool in den Zauberstab eingebaut
//

#pragma strict_types

private string format_ms(int i)
{
    string ret;

    // Tausenstel Sekunden
    ret = sprintf("%03d",i % 1000);
    if (i /= 1000)
    {
	// Sekunden
	ret = sprintf("%02d.%s",i % 60,ret);
	if (i /= 60)
	{
	    // Minuten
	    ret = sprintf("%02d.%s",i % 60,ret);
	    if (i /= 60)
	    {
		// Stunden
		ret = sprintf("%d:%s",i,ret);
	    }
	}
    }
    return ret;
}

int z_obst(string str)
{
    SECURE;
    HELP("zobst");
    
    "/apps/object_db"->start_menu();
    
    return 1;
}

int z_sysinfo(string str)
{
    int *us;

    SECURE;
    HELP("zsysinfo");

    if (str)
	return 0;

    us = rusage();
    W(sprintf("Driver-Version: %28s\n",__VERSION__));
    W(sprintf("CPU-User:                         %10d ms   %13s\n",
		us[0],format_ms(us[0])));
    W(sprintf("CPU-System:                       %10d ms   %13s\n",
		us[1],format_ms(us[1])));
    W(sprintf("CPU gesamt:                       %10d ms   %13s    (%.2f %%)\n",
		us[0] + us[1],format_ms(us[0] + us[1]),
		to_float(us[0] + us[1])/to_float(query_up_time()*10)));
    W(sprintf("CPU-Auslastung (5 Minuten):       %10.2f %%\n",
		to_float(({int})"/apps/statistik"->query_five_time())/3000.0));
    W(sprintf("Load-Average:                              %s\n",
		query_load_average()));
    W(sprintf("Max-Mem-Size (resident):          %10d kb\n",us[2]));
    W(sprintf("integral shared text memory size: %10d\n",us[3]));
    W(sprintf("integral unshared data size:      %10d\n",us[4]));
    W(sprintf("integral unshared stack size:     %10d\n",us[5]));
    W(sprintf("page reclaims: (ohne I/O)         %10d\n",us[6]));
    W(sprintf("page faults:   (mit I/O)          %10d\n",us[7]));
    W(sprintf("swaps:                            %10d\n",us[8]));
    W(sprintf("block input operations:           %10d\n",us[9]));
    W(sprintf("block output operations:          %10d\n",us[10]));
    W(sprintf("messages sent:                    %10d\n",us[11]));
    W(sprintf("messages received:                %10d\n",us[12]));
    W(sprintf("signals received:                 %10d\n",us[13]));
    W(sprintf("voluntary context switches:       %10d\n",us[14]));
    W(sprintf("involuntary context switches:     %10d\n",us[15]));

#if __EFUN_DEFINED__(driver_info)
    {
	W(sprintf("Anzahl Objekte:                   %10d (%10d)\n",
	        efun::driver_info(DI_NUM_OBJECTS_IN_LIST),
	        efun::driver_info(DI_NUM_OBJECTS)));
    }
#else
    {
        int *sysinfo = efun::debug_info(DINFO_DATA,DID_STATUS);
	W(sprintf("Anzahl Objekte:                   %10d (%10d)\n",
		sysinfo[DID_ST_OBJECTS_LIST],sysinfo[DID_ST_OBJECTS]));
    }
#endif

    W(sprintf("Anzahl Spieler:                   %10d (total: %2d)\n",
	sizeof(users()),sizeof(efun::users())));

    PRINT;
    return 1;
}
