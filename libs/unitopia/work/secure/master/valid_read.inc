// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/valid_read.inc
// Description: valid_read
// Author:	Freaky
// Modified by: Kurdel (04.11.97) Admin-Verzeichnisse fuer Domains
//		Freaky (29.03.1999) in /tar/Gilden/ duerfen die Gildenadmins
//			alles lesen.
//
// $Log: valid_read.inc,v $
// Revision 1.32  2013/12/21 17:08:04  myonara
// file=="" RTE abgefangen.
//
// Revision 1.31  2013/11/03 14:09:19  myonara
// Gildenhelfer LEserecht auf /z/Gilden/<gilde>/Admin geben.
//
// Revision 1.30  2013-03-16 15:58:36  gnomi
// Unterstuetzung fuer FTP via RPC.
//
// Revision 1.29  2009-03-20 08:16:52  gnomi
// READs im /w koennen nun auch Rechte fuer Unterverzeichnisse geben.
// Via FTP die gleichen Rechte wie beim Zugriff im Mud geben.
// Bei LVL_LEARNER den echten Namen heranziehen.
//
// Revision 1.28  2007/08/20 18:21:36  gnomi
// Bessere Orbit-Simulation fuer file_size und bei Beachtung geloeschter
// Dateien.
//
// Revision 1.27  2006/08/03 09:53:08  gnomi
// Schattenverzeichnisse fuer Orbit.
//
// Revision 1.26  2005/02/02 22:31:08  gnomi
// /pub/incoming-Rechte wie beim anonymous-Zugang festgelegt.
//
// Revision 1.25  2004/07/19 21:33:11  gnomi
// Domain-Infos vom Master nach /apps/domains umgezogen.
//
// Revision 1.24  2004/04/14 22:03:22  gnomi
// exports.tar.gz darf jeder lesen.
//
// Revision 1.23  2003/12/14 00:25:14  gnomi
// /../ darf innerhalb eines Pfades nicht auftauchen (sollte normalerweise auch
// nicht vorkommen, nur sicherheitshalber).
//
// Revision 1.22  2003/05/13 10:25:43  menaures
// Bugfix zum letzten Patch
//
// Revision 1.21  2003/05/13 02:04:56  menaures
// Behandlung fuer neues /var/intern eingebaut
//
// Revision 1.20  2003/01/29 03:20:25  gnomi
// Letzter Patch unvollstaendig. Entsprechende Filed-Abfrage hinzugefuegt.
//
// Revision 1.19  2003/01/25 04:38:40  gnomi
// /z/Gilden/<Gilde>/Admin ist lesegeschuetzt fuer die Beschreibungen der
// Gildenaufstiegsquests und aehnliches.
//
// Revision 1.18  2002/12/05 00:46:18  gnomi
// tar.bz2 als Endung im /tar zulassen
//
// Revision 1.17  2002/11/30 23:49:34  gnomi
// /w/OLD/*/priv ist nicht lesbar.
//
// Revision 1.16  2002/03/02 12:02:43  gnomi
// /tar/Doc darf jeder lesen.
//
// Revision 1.15  2002/02/23 05:18:19  gnomi
// /var/master.o ist nicht mehr geheim.
//
// Revision 1.14  2002/02/09 10:42:14  gnomi
// Den Player-Objekten der Spielerraete direkten Zugriff auf das SR-Archiv
// geben.
//
// Revision 1.13  2001/12/03 23:27:01  gnomi
// Newsreader darf auch Artikel direkt lesen (fuer Zusammenfassungen).
// caller statt previous_object() genutzt.
//
// Revision 1.12  2001/12/03 01:45:07  gnomi
// Sicherheitsloch gestopft: Newsartikel darf man nur lesen, wenn PO=TP=TI ist.
//
// Revision 1.11  2001/05/30 20:59:15  gnomi
// w:<name> darf in /w/name/.../save lesen.
//
// Revision 1.10  2001/05/05 02:55:47  gnomi
// file_size in /var/adm nicht zulassen.
//
// Revision 1.9  2001/04/20 00:01:01  freaky
// Domain-Check verbessert. (schnellere Funktion dafuer genommen)
//
// Revision 1.8  2001/04/06 22:21:51  gnomi
// /apps/wizard_apprecations (oder so aehnlich) rausgenommen. Hat anderen
// Filenamen und benoetigt wegen UID "Root" keine besonderen Rechte.
//
// Revision 1.7  2001/02/16 23:57:16  sissi
// Offline Wuerdigungen eintragen.
//
// Revision 1.6  2001/02/11 04:18:58  sissi & gnomi
// Neues Levelsystem
//
// Revision 1.5  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

int valid_read_in_w(string* path, string wiz)
{
    string dir;
    string *readers;
    int priv = rmember(path, "priv");
    
    if(sizeof(path)<2)
	return 0;

    if(priv<1) priv = 1;
    dir = "/"+implode(path[0..priv-1],"/");
    
    foreach(string subdir: path[priv..])
    {
	string tmp;
	
	dir += "/" + subdir;
	tmp = read_file(dir + "/READ");
	if(tmp)
	{
	    readers = explode(tmp, "\n");
	    if(member(readers, "*"+wiz) >= 0 || member(readers, "*alle") >= 0)
		return 1;
	}
	else
	    readers = 0;
    }

    if(readers && 
	(member(readers, wiz) >= 0 || member(readers, "alle") >= 0))
	return 1;
}


/*
 * Function name:   valid_read
 * Description:     Checks if a certain user has the right to read a file
 * Arguments:       file - File name of the file to be read
 *                  user - Name of the wizard responsible for the read.
 *		    func - The calling function.
 * Returns:         True if read is allowed.
 */
mixed valid_read(string file, string eff_user, string func, object caller)
{
    string *path, tmp, *tmps;
    mixed destfile = 1;
    int level;

#if 0
    if (find_player("gnomi") && !strstr(file,"/var/adm"))
    {
	tmp="READ:FN:"+file+", EffUser:"+eff_user+",\nfunc:"+func+", caller:";
	if (caller) tmp+=object_name(caller)+".\n";
	else tmp+="0.\n";
#if 0
	tmp+=sprintf("PO:%O:\n",previous_object());
	tmp+=sprintf("TI:%O:\n",this_interactive());
	tmp+=sprintf("TP:%O:\n",this_player());
#endif
	tell_object(find_player("gnomi"),tmp);
    }
#endif

    // Gueltige Filenamen haben keine Spaces
    // Effektiver User muss angeben sein
    if (!file || file == "" || member(file,' ')>=0 || !eff_user)
	return 0;

    // Root darf alles lesen
    // file_size darf man auf alles machen
    if (eff_user == ROOT_UID)
	return 1;
	
    // Wenn // oder /./ im Pfad ist, darf man nicht lesen:
    // read_file("/w/freaky/./priv/");
    if (file[0] != '/' || strstr(file,"//") >= 0 || strstr(file,"/./") >= 0 ||
	strstr(file,"/../") >= 0)
    	return 0;

    path = explode(file[1..],"/");

#if defined(Orbit) && !defined(UnionFS)
    if(sizeof(path)>1 && path[0] == "var" && member(({"d","p","z"}),path[1])>=0)
    {
	path = path[1..<1];
	destfile = file;
    }
    else if(member(({"d","p","z"}),path[0])>=0 && (file_size("/var"+file)>=0 ||
	file_size("/var"+file+".__mark__")>=0))
	destfile = "/var"+file;
#endif

    if(func == "file_size" && file[0..8]!="/var/adm/")
	return destfile;

    if (sizeof(path) > 1)
    {
	//path = (path[0..<2] - ({"","."})) + path[<1..<1];
	switch(path[0])
	{
	  case "var":
	    // Apps darf /var/* lesen (alles)
	    if (eff_user == APPS_UID)
		return 1;
	    // /var/* darf man lesen (keine unterverzeichnisse)
	    if (sizeof(path) < 3)
		return 1;
	    // Player duerfen sich restoren
	    if (path[1] == "players" &&
		    func == "restore_object" &&
		    sizeof(path) == 4 &&
		    playerp(previous_object()))
		return 1;

	    // bei /var/spool/news wird NEWSD gefragt
	    if (sizeof(path) > 4 && path[2] == "news" &&
		    this_player() == this_interactive() && 
		    (caller == this_player() ||
		     load_name(caller) == "/obj/newsreader") &&
		    NEWSD->valid_read(this_player(),path[3],path[4]))
		return 1;

	    if (sizeof(path) > 3 && path[1] == "adm" &&
		    path[2] == "spielerratsarchiv" && 
		    this_player() == this_interactive() && 
		    caller == this_player() && 
		    (adminp(this_player()) || spielerratp(this_player())))
		return 1;
	    break;
	  case "w":
	    // Jeder eff_user darf sein /w/eff_user/ lesen
	    if (sizeof(path) > 1 && path[1] == eff_user)
		return 1;
            // von /save/ duerfen sich auch Objekte mit UID w:<name> restoren.
            if (member(path,"save") > 1)
                if(eff_user == ("w:" + path[1]))
                    return 1;
	    if (sizeof(path) == 2 && func == "get_dir")
                return 1;
            if (sizeof(path) > 2 && path[2] == "public")
                return 1;
            break;
	  case "z":
	    // das Admin-Verzeichnis duerfen nur die jeweilige Admins lesen.
	    if (sizeof(path) < 3 || (path[2] != "Admin" &&
	       (sizeof(path) < 4 || path[1] != "Gilden" || path[3] != "Admin")))
	    	return destfile;
	    if ((member(({string *})FILED->query_auth(lower_case(path[1]))
		    || ({}),eff_user) >= 0) ||
		(path[1]=="Gilden" && (FILED->is_coder_of(lower_case(path[1]),
		    path[2], eff_user) 
		    || query_access(path[0..2],eff_user,ACL_WRITE))))
				return destfile;
	    break;
	  case "d":
	    // das Admin-Verzeichnis duerfen nur die Lords und Helfer lesen
	    if (sizeof(path) < 3 || path[2] != "Admin" ||
	        DOMAIN_INFOS->domain_lord(path[1],eff_user) ||
	        DOMAIN_INFOS->domain_helfer(path[1],eff_user))
		return destfile;

	    /*
	    if (member(query_domains_of(eff_user), path[1]) >= 0
                || member(query_domainhelfer_of(eff_user), path[1]) >= 0)
		return 1;
	    */
	    break;
	  case "tar":
	     // Verzeichnis darf jeder lesen
	     if(func == "get_dir")
		return 1;

	     // Doku darf auch jeder lesen
	     if(path[1]=="Doc")
	        return 1;
		
	     // Domainlords und Domainhelfer duerfen ihr .tar.gz lesen
	     // wenn sie via ftp zugreifen, Files ohne .tar.gz als Endung
	     // darf jeder lesen
	     if (sscanf(path[<1],"%s.tar.gz",tmp) == 1 ||
	         sscanf(path[<1],"%s.tar.bz2",tmp) == 1)
	     {
		if(!strstr(object_name(previous_object()), "/secure/rpc/") && // FTP
			(tmp == "p"
			|| tmp == "exports"
			|| DOMAIN_INFOS->domain_lord(tmp,eff_user)
			|| DOMAIN_INFOS->domain_helfer(tmp,eff_user)
			/*
		    	|| member(query_domains_of(eff_user),tmp) >= 0
			|| member(query_domainhelfer_of(eff_user),tmp) >= 0
			*/
                        || member(FILED->query_coder_of("gilden",tmp) || ({}),
			   	eff_user) >= 0
			|| member(FILED->query_auth(lower_case(tmp)) || ({}),
				eff_user) >= 0
			|| (sizeof(path) > 2 && path[1] == "Gilden" &&
			    member(FILED->query_auth("gilden") || ({}),
				eff_user) >= 0)
			)
		    )
		    return 1;
                else
		   break;
	    }
	    else
	        return 1;
	    break;
	
	  case "pub":
	    if(sizeof(path)>2 && path[1]=="incoming")
	    {
		// Dem FTP erlauben, sonst geht nicht mal ein 'cd'.
		// In der proftpd.conf wird es dann verboten.
		if(func=="get_dir" &&
		    object_name(previous_object())=="/secure/udp/ftpserv")
			return 1;
		return 0;
	    }
			    
	    return 1;


	  // Alles andere darf jeder lesen
	  default:
	    return destfile;
        }
    }
    else
    {
        // /* darf man lesen
        return 1;
    }


    // Player oriented special privileges
    //
    if(!strstr(object_name(previous_object()), "/secure/rpc/"))
    {
        // FTPD
        if(!GOETTER_REGISTER->is_wiz(eff_user))
            return 0;
    }
    else if(!this_interactive() ||
            geteuid(this_interactive()) != eff_user ||
            !(level = wizp(this_interactive())))
        return 0;

    // Only wizards after this point.
    // (Gott <eff_user>.)

    // Admin darf alles lesen
    if(adminp(this_interactive()))
        return 1;

    if(sizeof(({string*}) DOMAIN_INFOS->query_domains_of(eff_user)) ||
        member(({string*}) FILED->query_all_auth(), eff_user) >= 0)
    {
        // Lords duerfen /w/ ausser /w/*/priv/ lesen
        if(path[0] == "w" && (sizeof(path) < 3 || path[2] != "priv") &&
           (sizeof(path)<4 || path[1]!="OLD" || path[3]!="priv"))
               return 1;

          // Lords duerfen /var/intern lesen
          if(sizeof(path) > 1 && path[0] == "var" && path[1] == "intern")
           return 1;
    }

    // Normale Goetter:
    if(path[0] == "w")
    {
	// Learner haben noch keine eigene uid, deshalb
	// test auf real_name , so dass sie ihr /w/<real_name> lesen koennen
	if (level == LVL_LEARNER && sizeof(path) > 1 &&
	    (({string})this_interactive()->query_real_name() == path[1]))
	        return 1;
	
	if (valid_read_in_w(file_size(file) == -2 ?path[0..]:path[0..<2],
		level == LVL_LEARNER?({string})this_interactive()->query_real_name():eff_user))
	    return 1;
	    
        // Wenn man Lehrmeister dieses Gott ist, darf man auch dort 
	// lesen, ausser in /w/*/priv
	if(member(({string *})GOETTER_REGISTER->query_lehrmeisters(path[1]), eff_user) >= 0 &&
		  (sizeof(path) < 3 || path[2] != "priv"))
	    return 1;
    }

    return 0;
}
