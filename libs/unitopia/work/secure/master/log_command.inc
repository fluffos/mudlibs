// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/log_command.inc
// Description:	Loggt Wiz-Commands
// Author:	
// Modified by:	
//
// $Log: log_command.inc,v $
// Revision 1.9  2004/07/19 21:24:02  menaures
// Genauere Zeitangabe, Format leserlicher gestaltet.
//
// Revision 1.8  2003/11/11 03:14:04  gnomi
// Logging auch vom FTP-Server aus erlauben.
//
// Revision 1.7  2003/01/25 04:39:57  gnomi
// Funktion fuer den Mailreader, um zu testen, ob ein Newbie an mudadm einen
// Brief schreiben darf (wenn Puffer abgespeichert wurde).
//
// Revision 1.6  2002/03/10 01:16:00  gnomi
// Puffer erst nach 17 Tagen loeschen, damit sind sie auf jeden Fall immer in
// einem Backup enthalten.
//
// Revision 1.5  2001/03/03 14:40:09  freaky
// auf file_time() verzichten, da es eine simul-efun ist.
//
// Revision 1.4  2001/02/27 10:58:53  sissi
// Admins duerfen log_puffer benutzen.
//
// Revision 1.3  2001/02/27 03:23:12  gnomi
// Authentische Logs mit log_puffer().
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

#define COMMAND_FILE 	  "/var/adm/logfiles/"+(ob->query_real_name()||name)+".log"
#define PUFFER_FILE(ob,i) "/var/adm/puffer/"+ob->query_real_name()+".puffer"+i

void log_command(string str, string name)
{
    object ob;
    int * t, * ut;
    ob = previous_object();

    if ((!playerp(ob) || ob!=this_interactive()) &&
        (object_name(ob)!=FTP_SERVER || !name))
        return;

    ut = utime();
    t = localtime(ut);

    write_file(COMMAND_FILE, 
        sprintf("%3s %3s %'0'2d %4d %'0'2d:%'0'2d:%'0'2d.%'0'2d\n"
	        "    %-=74s\n",
            ({"Sun","Mon","Tue","Wed","Thu","Fri","Sat"})[t[TM_WDAY]],
            ({"Jan","Feb","Mar","Apr","May","Jun",
              "Jul","Aug","Sep","Oct","Nov","Dec"})[t[TM_MON]],
            t[TM_MDAY], t[TM_YEAR],
            t[TM_HOUR], t[TM_MIN], t[TM_SEC], ut[1]/10000,
            str));
}

void clean_puffer()
{
    int tim;
    mixed *dir;

    dir = get_dir("/var/adm/puffer/",GETDIR_NAMES|GETDIR_DATES);
    tim = time();
    for (int i = 0; i < sizeof(dir); i += 2)
    {
	if ((dir[i + 1] + 1468800) < tim)
	    rm("/var/adm/puffer/" + dir[i]); //Nach 17 Tagen loeschen
    }
}

int log_puffer(string *str)
{
    object ob;
    int i;
    clean_puffer();
    ob = previous_object();
    if (!playerp(ob) ||
        (ob!=this_interactive() && !adminp(this_interactive())))
	return 0;
    for(i=1;i<11;i++)
	if(file_size(PUFFER_FILE(ob,i))<0) break;
    if(i==11) return 0;
    write_file(PUFFER_FILE(ob,i), implode(str,""));
    return 1;
}

int may_write_to_mudadm()
{
    return load_name(previous_object())=="/obj/mailreader" &&
	sizeof(get_dir(PUFFER_FILE(environment(previous_object()),"*"))) && 1;
}
