// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/creator_file.inc
// Description: Welche UID soll ein neues Objekt bekommen ?
// Author:	Freaky (23.12.93)
// Modified by:	Freaky (25.09.95) Security-Check bei /map/mX_Y.c
//              Kurdel (20.08.97) Clones unter /map/obj/ erhalten MAP_UID
//
// $Log: creator_file.inc,v $
// Revision 1.39  2009/09/07 21:59:04  gnomi
// /Orbit/ laesst sich nur in Orbit laden.
//
// Revision 1.38  2008/02/25 20:47:34  gnomi
// RPC-Anbindung.
//
// Revision 1.37  2007/02/04 22:03:01  gnomi
// Sonderbehandlungen fuer Levitanis.
//
// Revision 1.36  2006/05/01 00:43:48  gnomi
// Laden von Map-Raeumen ausserhalb /map verbieten.
//
// Revision 1.35  2004/05/12 20:57:10  gnomi
// Fehlermeldungen statt Warnungen bei unerlaubten Clonen.
//
// Revision 1.34  2003/07/31 00:49:18  menaures
// Warning erzeugen, wenn nicht aus .../obj/... geklont wird
//
// Revision 1.33  2003/04/01 00:08:03  freaky
// set_this_object: an neuen Driver angepasst.
//
// Revision 1.32  2002/06/24 22:50:07  gnomi
// Objekte aus /apps und /secure erhalten einzigartige UIDs, damit
// sie call_out-Evals nicht mit anderen Objekten teilen muessen.
//
// Revision 1.31  2002/04/03 09:50:18  freaky
// Laden aus .../Admin/Secure/... zulassen.
//
// Revision 1.30  2001/08/26 12:50:32  freaky
// todos entfernt
//
// Revision 1.29  2001/08/10 18:25:07  freaky
// NO_*-logging ausgebaut.
//
// Revision 1.28  2001/07/21 12:43:43  freaky
// Path-Restrictions aktiviert.
//
// Revision 1.27  2001/06/28 22:26:02  freaky
// das zlpc-File bekommt jetzt eine 'richtige' UID
//
// Revision 1.26  2001/06/25 13:57:22  freaky
// Old-Verzeichnisse ausgeschlossen vom Laden und Includen
//
// Revision 1.25  2001/06/03 11:18:21  freaky
// Neues UID-Handling eingebaut.
//
// Revision 1.24  2001/05/30 11:12:23  freaky
// UID fuer Files aus /w geaendert.
//
// Revision 1.23  2001/05/13 22:16:39  gnomi
// do_log_error: "Root" als Debugger rausnehmen, wenn es doch andere Debugger
// gibt...
//
// Revision 1.22  2001/04/14 00:11:38  sissi
// Man kann jetzt *wirklich* ls -l machen. Bisher stand im Kommentar drin,
// dass es geht, es ging aber nicht wirklich...
//
// Revision 1.21  2001/04/13 13:49:48  freaky
// UID-Handling ueberarbeitet.
//
// Revision 1.20  2001/03/31 17:13:29  freaky
// *** empty log message ***
//
// Revision 1.19  2001/03/30 18:11:38  freaky
// UID in /d/ vereinfacht.
//
// Revision 1.18  2001/03/23 13:11:48  freaky
// variablennamen klarer gemacht.
//
// Revision 1.17  2001/03/21 11:02:07  freaky
// do-log-error: weiteren Parameter eingefuerhrt, mit dem keine Meldung
// an Spieler erzeugt wird.
//
// Revision 1.16  2001/03/21 10:40:57  freaky
// Fehlermeldungen bei illegalen Files verbessert.
//
// Revision 1.15  2001/03/21 10:34:43  freaky
// Fehlermeldung bei illegalem clone/load verbessert.
//
// Revision 1.14  2001/03/16 00:49:13  freaky
// Meldung aendern.
//
// Revision 1.13  2001/03/16 00:32:52  freaky
// Error erzeugen, wenn nicht lad/clone-bar
//
// Revision 1.12  2001/02/20 16:31:11  gnomi
// Beim Logging von get_clone_uid aufpassen, dass previous_object(1) nicht 0
// wird. (Kommt beim ls -L z.B. vor.)
//
// Revision 1.11  2000/11/14 12:12:34  freaky
// NO_* /z/Raetsel/Admin ausgenommen.
//
// Revision 1.10  2000/08/29 14:27:23  freaky
// file_name() nach object_name() umgebaut.
// filter_array() nach filter() umgebaut.
// map_array() nach map() umgebaut.
// (also alles an die neuen Efuns angepasst)
//
// Revision 1.9  2000/07/03 23:13:04  freaky
// NO_LOAD-log besser gemacht.
//
// Revision 1.8  2000/07/03 23:03:34  freaky
// NO_CLONE-log besser gemacht.
//
// Revision 1.7  2000/06/23 15:34:38  freaky
// no_load_file(): /log/ eingefuehrt.
// get_load_uid(): Logging umgestellt.
//
// Revision 1.6  2000/06/20 00:37:35  freaky
// Es war zu restriktiv, deswegen nicht nur /i/ bzw. /obj/ zulassen
//
// Revision 1.5  2000/06/19 18:48:49  freaky
// speedup in no_clone_file()
//
// Revision 1.4  2000/06/19 18:11:46  freaky
// no*file-Handling verbessert
//
// Revision 1.3  2000/06/19 17:51:14  freaky
// no_*_file eingebaut
//

#pragma strict_types

#define NO_LOAD_DIRS ({ "/sys/", "/INFO/", "/doc/", "/save/", \
	"/var/", "/static/", "/priv/", "/log/", "/Old/", "/OLD/" })
#define NO_CLONE_DIRS ({ "/touch/", "/apps/", "/i/" })

private string get_apps_uid(string name)
{
    string fil, uid, junk;

    fil = read_bytes(name + ".c",0,10000);
    if (fil && (sscanf(fil,"%s\n// UID: %s\n",junk,uid) == 2))
	return uid;
    return GENERAL_UID;
}

int no_load_file(string file)
{
    foreach(string dir : NO_LOAD_DIRS)
	if (strstr(file,dir) >= 0)
	    return 1;
#ifndef TestMUD
    if(strstr(file, "/Orbit/") >= 0)
	return 1;
#endif

    if (strstr(file,"/Admin/") >= 0)
    {
	// TODO: Rausnehmen, da es /Admin/Secure/ gibt.
	if (strstr(file,"/z/Raetsel/Admin/") == 0)
	    return 0;
	// in /{z,d}/*/Admin/Secure/ duerfen von den Admins genehmigte
	// Objekte geladen werden
	if (strstr(file,"/Admin/Secure/") >= 0)
	{
	    string *path;

	    path = explode(file,"/");
	    if ((path[1] == "z" || path[1] == "d") && path[3] == "Admin" &&
		    path[4] == "Secure")
		return 0;
	}
	return 1;
    }
}

int no_clone_file(string file)
{
    foreach(string dir : NO_CLONE_DIRS)
	if (strstr(file,dir) >= 0)
	    return 1;
    if (strstr(file,"/obj/") >= 0)
	return 0;

    /*
    if (strstr(file,"/Admin/") >= 0)
	return 1;
    if (strstr(file,"/room/") >= 0)
	return 1;
    */

    return 1;
}

// from_hook == 1, wenn wir vom Driver-Hook beim Laden eines Objektes
//                 aufgerufen wurden.
// from_hook == 0, wenn wir vom /map/map oder ls-Befehl aufgerufen wurden.

mixed get_load_uid(string str, int from_hook)
{
    string *name;
    int s;

#if 0
    if (find_player("gnomi"))
	//tell_object(find_player("freaky"),sprintf("LU:%O: po:%O:\n",str,previous_object(1)));
	tell_object(find_player("gnomi"),sprintf("LU:%O: po:%O:\n",str,caller_stack()));
#endif

    name = explode(str,"/");
    s = sizeof(name);
    if (s < 2)
	return 0;
    if (!valid_file_name(str))
	return 0;

    if (no_load_file("/" + str))
	return 0;

    switch(name[0])
    {
      case "d":
        // Map-Raeume nur von /map.
    	if (from_hook && funcall(symbol_function("domain2map"), "/"+str))
	    return 0;
#ifdef UNItopia	
	if(name[1] == "Levitanis")
	{
	    if(s==3)
		return 0;
	    
	    switch(name[2])
	    {
		case "i":
		case "obj":
		case "apps":
		    return name[1]+":"+name[2];
		
		case "public":
		case "wiz":
		{
		    object ob = find_object(str);
		    if(!ob)
			return 0;
		
		    // Inherits testen	
		    foreach(mixed inh: efun::inherit_list(ob,INHLIST_TREE))
		    {
			string inhname = stringp(inh)?inh:(inh[0]);
			if(strstr(inhname,"/d/Levitanis/i/") &&
			   inhname != "/"+str+".c")
			    return 0;
		    }
		    
		    // Funktionen pruefen
		    if(sizeof(efun::functionlist(ob, NAME_INHERITED|RETURN_FUNCTION_NAME)
			-({"create","__INIT"})))
			return 0;
		    
		    if(name[2]=="public" || s==4)
			return name[1]+":"+name[2];
		    return name[1]+":"+name[3];
		}
	    }
	    return 0;
	}
#endif

	if (s > 3)
	{
	    /*
	    if (GOETTER_REGISTER->is_wiz(name[2]))
	    	return name[1] + ":" + name[2];
	    if (s > 4 && name[2][0] >= 'A' && name[2][0] <= 'Z' &&
	    		GOETTER_REGISTER->is_wiz(name[3]))
	    	return name[1] + ":" + name[3];
	    */
	    return name[1] + ":" + name[2];
	}
	return s == 3 ? name[1] + ":Std" : 0;
      case "map":
      {
	int x, y;
	if (str == "map/map")
	    return ROOT_UID;
	// Freaky: Hier sollte man besser noch abpruefen, ob prev_ob==/map/map
	//         ist...
	if (sscanf(name[1],"m%d_%d",x,y) == 2)
	    return previous_object() &&
		   (object_name(previous_object()) == MAP_OB) && BACKBONE_UID;
	return MAP_UID;
      }
      case "z":
        return s > 3 ? name[1] + ":" + name[2] : 0;
      case "p":
	return s > 2 ? "p:" + name[1] : 0;
      case "w":
        // LPC-File bekommt echte UID
        if (s == 3 && name[2] == "LPC_zst")
	    return name[1];
	return s > 2 ? "w:" + name[1] : 0;
      case "obj":
      case "i":
      case "room":
	return GENERAL_UID;
      case "secure":
	return ({ ROOT_UID + ":" + name[<1], ROOT_UID });
      case "apps":
        {
	  string apps_uid = get_apps_uid(str);
	  return ({apps_uid+":"+name[<1], apps_uid});
	}
    }
    return 0;
}

#if 0
#define TEST_OBJ if (strstr(str,"/obj/") == -1) \
    write_file("/log/sys/CLONE",sprintf("CU-NoObj:%O PO:%O\n",str,caller_stack()));
#else
#define TEST_OBJ
#endif

mixed get_clone_uid(string str)
{
    string *name;
    int s;

#if 0
    if (find_player("gnomi"))
	tell_object(find_player("gnomi"),sprintf("CU:%O:\n",str));
#endif

    name = explode(str,"/");
    s = sizeof(name);
    if (s < 2)
	return 0;

    if (no_clone_file("/" + str))
	return 0;

    switch(name[0])
    {
      case "d":
      	TEST_OBJ
	if (s > 3)
	{
	    /*
	    if (GOETTER_REGISTER->is_wiz(name[2]))
	    	return name[1] + ":" + name[2];
	    if (s > 4 && name[2][0] >= 'A' && name[2][0] <= 'Z' &&
	    		GOETTER_REGISTER->is_wiz(name[3]))
	    	return name[1] + ":" + name[3];
	    */
	    return name[1] + ":" + name[2];
	}
	return s == 3 ? name[1] + ":Std" : 0;
      case "obj":
	return BACKBONE_UID;
      case "map":
        return name[1] == "obj" ? MAP_UID : 0;
      case "z":
        return s > 3 && strstr(str,"/obj/") != -1 ? name[1] + ":"+ name[2] : 0;
      case "p":
      	TEST_OBJ
	return s > 2 ? "p:" + name[1] : 0;
      case "w":
      	TEST_OBJ
	/*
	if (strstr(str,"/obj/") == -1)
	    write_file("/log/sys/CLONE",sprintf("CU-NoObj:%O PO:%O\n",str,
			caller_stack()));
	*/
	return s > 2 ? "w:" + name[1] : 0;
      case "room":
	return GENERAL_UID;
      case "secure":
	return name[1] == "obj" ? ({ ROOT_UID + ":" + explode(name[<1],"#")[0], ROOT_UID }) : 
	       name[2] == "obj" ? ({ ROOT_UID + ":" + name[1], ROOT_UID }) : 0;
    }
    return 0;
}

// Fuer die Driver-Hooks
private string h_load_uids(string obj_name)
{
    string uid;

    uid = get_load_uid(obj_name, 1);
    if (uid == BACKBONE_UID)
	return geteuid(previous_object());
    return uid;
}

private string h_clone_uids(string blueprint, string new_name)
{
    string uid;

    uid = get_clone_uid(new_name);
    if (uid == BACKBONE_UID)
	return geteuid(previous_object());
    return uid;
}
