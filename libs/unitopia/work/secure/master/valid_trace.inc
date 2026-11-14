// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/valid_trace.inc
// Description:	Ueberprueft, ob this_interactive() die Funktion trace()
//		benutzen darf.
// Author:	Freaky (10.07.1999)
//
// $Log: valid_trace.inc,v $
// Revision 1.5  2001/03/03 14:39:29  freaky
// Variable who aus dem Debugging rausgenommen.
//
// Revision 1.4  2001/02/28 00:38:14  freaky
// angepasst an neuen Driver ldmud-3.2.9dev260
//
// Revision 1.3  2001/02/11 04:18:58  sissi & gnomi
// Neues Levelsystem
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

varargs int valid_trace(string what, mixed arg)
{
    object who;

#if 1
    if (find_player("freaky"))
    	tell_object(find_player("freaky"),sprintf("TRACE: What:%O Arg:%O\n",what,arg));
#endif

    who = this_interactive();

    if (!who || !playerp(who))
	return 0;

    write_file("/log/sys/PRIVI",sprintf("Special-CMD: %s %O\n",what,who));
    switch(what)
    {
	case "trace":
	case "traceprefix":
	    return adminp(who);
	default:
	    return 0;
    }
}
