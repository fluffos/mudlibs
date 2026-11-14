// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/valid_snoop.inc
// Description: Snoop-Checks
// Author:	Freaky
//
// $Log: valid_snoop.inc,v $
// Revision 1.7  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.6  2005/02/02 22:30:23  gnomi
// Neue Beobachtungsregeln.
//
// Revision 1.5  2002/09/14 01:50:05  gnomi
// valid_query_snoop: Dort erlauben, wo man auch eine Meldung erhalten wuerde.
//
// Revision 1.4  2001/05/27 18:28:00  sissi
// "Du fuehlst Dich von einem Gott beobachtet" statt "Du fuehlst Dich
// beobachtet".
//
// Revision 1.3  2001/02/11 04:18:58  sissi & gnomi
// Neues Levelsystem
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

int valid_snoop(object snooper, object victim) {
    int snooper_level;
    int betreut;
    string vname, sname;

    if(!snooper)
	return 0;
    if(!victim)
	return 1;
    // Admins duerfen immer
    if(adminp(snooper))
        return 1;
    snooper_level = query_real_player_level(snooper);
    // Nicht-Voegte duerfen nie
    if(snooper_level < LVL_VOGT)
	return 0;
    // Wenn der, der das victim schon snoopt ein Admin ist -> NO
#if __EFUN_DEFINED__(query_snoop)
    if(adminp(query_snoop(victim)))
#else
    if(adminp(efun::interactive_info(victim, II_SNOOP_NEXT)))
#endif
	return 0;

    vname = ({string})victim->query_real_name();
    sname = ({string})snooper->query_real_name();
    
    betreut = !(({string})GOETTER_REGISTER->query_lehrmeister(vname, 2)) &&
	member(({string *})GOETTER_REGISTER->query_lehrmeisters(vname),
	    sname) >= 0;
    if(betreut || victim->query_allow_snoop(snooper))
    {
	if(!betreut)
	    if(wizp(victim))
		tell_object(victim, "Du wirst von "+
		    capitalize(sname)+" beobachtet.\n");
	    else
		tell_object(victim, "Du fuehlst Dich von einem Gott beobachtet.\n");
	write_file("/var/adm/SNOOP", 
	    sprintf("[%s] %s beobachtet %s.\n",
		ctime(), capitalize(sname), capitalize(vname)));
	return 1;
    }
    return 0;
}

int valid_query_snoop(object wiz) {
    int lev, sn_lev, betreut;
    string vname, sname;
    object snooper;
#if 0
    if (find_player("freaky"))
        tell_object(find_player("freaky"),sprintf("VAL_Q_SNOOP:%O: "+
		"TP:%O: TI:%O: PO:%O:\n",wiz,this_player(),this_interactive(),
		previous_object()));
#endif
    if(adminp(this_interactive()))
	return 1;
    lev=query_real_player_level(this_interactive());
#if __EFUN_DEFINED__(query_snoop)
    snooper = query_snoop(wiz);
#else
    snooper = efun::interactive_info(wiz, II_SNOOP_NEXT);
#endif
    sn_lev=query_real_player_level(snooper);
    
    // Wenn man beobachtet, darf man rausbekommen
    if ((snooper==this_interactive()) ||
	(lev>LVL_WIZ && lev>query_real_player_level(wiz) && lev>sn_lev))
	    return 1;

    if (wiz!=this_interactive() || previous_object()!=this_interactive() ||
	!snooper || adminp(snooper))
	    return 0;

    vname = ({string})wiz->query_real_name();
    sname = ({string})snooper->query_real_name();

    betreut = !(({string})GOETTER_REGISTER->query_lehrmeister(vname, 2)) &&
	member(({string *})GOETTER_REGISTER->query_lehrmeisters(vname),
	    sname) >= 0;

    return betreut?0:1;
}
