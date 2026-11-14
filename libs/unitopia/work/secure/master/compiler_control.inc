// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/compiler_control.inc
// Description: Funktionen die den LPC-Compiler betreffen.
// Modified by:	Freaky (16.06.1998) rename_allowed eingebaut
//		Freaky (05.02.1999) rename_allowed: check auf environment()
//			und bessere Fehlermeldung (reason)
//			privi-violation: rename_object: /room/serv raus
//			privi-violation: command: alles noetige eingebaut
//
// $Log: compiler_control.inc,v $
// Revision 1.80  2016/03/21 12:40:38  gnomi
// strlen -> sizeof
//
// Revision 1.79  2015/09/10 17:23:30  myonara
// sqlite_pragma fuer user_version,foreign_keys
// mehr playerinherits fuer query_ip,interactive_info (gnomi)
//
// Revision 1.78  2015/08/26 22:03:30  gnomi
// Anpassungen fuer LDMud 3.5.0
//
// Revision 1.77  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.76  2015/07/03 21:22:51  myonara
// /apps/object_db eingetragen
//
// Revision 1.75  2015/06/07 15:11:44  myonara
// Bugfix zu vorherigem Patch *grummel*/ Danke @sorcerer
//
// Revision 1.74  2015/06/07 14:58:17  myonara
// bind_lambda, variable_list fuer Myonara.
//
// Revision 1.73  2012/12/09 22:46:48  gnomi
// Unterschiedliche Zertifikate fuer Telnet und Portal.
//
// Revision 1.72  2012-11-26 22:26:04  gnomi
// Unterstuetzung fuer InterMUD-Portale.
//
// Revision 1.71  2010-04-29 19:10:55  sorcerer
// bind_lambda fuer sorcerer
//
// Revision 1.70  2009-11-08 11:25:56  sorcerer
// variable_list fuer Sorcerer
//
// Revision 1.69  2009-06-17 08:01:00  gnomi
// limited fuers Goetterregister, damit wir mehr als 5000 Goetter daemmern
// koennen... ;-)
//
// Revision 1.68  2009-01-15 09:19:09  gnomi
// debug-/objectinfo-Plugins sind umgezogen.
// Ein paar SQLite-Pragmas erlaubt.
//
// Revision 1.67  2008/02/25 20:47:34  gnomi
// RPC-Anbindung.
//
// Revision 1.66  2007/12/05 11:15:01  gnomi
// variable_list for Gnomi.
//
// Revision 1.65  2007/10/24 21:55:38  gnomi
// SQLite-Pragma auto_vacuum erlauben.
//
// Revision 1.64  2007/08/11 23:31:50  gnomi
// Ein paar Privis fuer die Telnet Negotiations und den VT100-Client.
//
// Revision 1.63  2007/08/09 22:27:01  gnomi
// SQLite-Pragma table_info erlaubt.
//
// Revision 1.62  2007/07/27 15:09:18  gnomi
// limited im Player erlauben.
//
// Revision 1.61  2007/05/26 23:02:22  gnomi
// sqlite_pragma gibt's nun auch als Privi.
//
// Revision 1.60  2006/01/22 01:09:23  gnomi
// Flags bei debug_message angeben.
//
// Revision 1.59  2005/11/12 18:45:13  gnomi
// MySQL zum Testen fuer /w/gnomi erlauben. :-)
//
// Revision 1.58  2005/08/27 23:26:36  gnomi
// i/sperre darf auf die IP-Namen zugreifen.
//
// Revision 1.57  2005/06/04 13:31:59  gnomi
// Define NO_PRIVILEGE_VIOLATIONS schaltet (fuer HomeMUDS) die Privis aus.
//
// Revision 1.56  2005/03/27 20:34:00  menaures
// ERQ-Freischaltung fuer GNU Go
// virtual_compiler per catch(;publish) laden
//
// Revision 1.55  2005/01/05 21:48:10  gnomi
// efun::command_stack fuer /i/player/player erlauben.
//
// Revision 1.54  2004/08/27 13:12:11  menaures
// Ausnahmeregelungen fuer UNItopia-1993 Terminal auf dem Campus.
//
// Revision 1.53  2004/04/19 10:33:52  gnomi
// Login-Ob darf binary_message verwenden.
//
// Revision 1.52  2003/12/13 15:59:03  gnomi
// setup_renamed_object kann das Objekt auch zerstoeren.
//
// Revision 1.51  2003/11/05 01:46:20  menaures & gnomi
// limited auch fuer die Wizard-Shell (zfe).
// Zweitieregister darf IGNORE_BANG fuers input_to (PW-Abfrage) nutzen.
//
// Revision 1.50  2003/09/30 22:43:55  gnomi
// /obj/pplayer darf efun::tell_object nutzen.
//
// Revision 1.49  2003/08/12 17:00:19  menaures
// Nicht mehr versuchen, VCs aus OLD/ etc. zu laden
//
// Revision 1.48  2003/06/07 01:30:21  gnomi
// /apps/help_tool darf limited nutzen.
//
// Revision 1.47  2003/04/01 00:08:03  freaky
// set_this_object: an neuen Driver angepasst.
//
// Revision 1.46  2003/02/16 05:31:39  gnomi
// compile_object fragt bei /map/m?_?-Raeumen bei /map/map nach.
//
// Revision 1.45  2003/01/25 17:16:49  sissi
// *** empty log message ***
//
//
// Revision 1.43  2002/11/07 01:18:18  gnomi
// dangling_lfun_closure: Fehlermeldung an previous_object anhaengen.
//
// Revision 1.42  2002/07/29 00:43:03  gnomi
// Wenn ein VC weder 0 noch Objekt zurueckliefert, Fehler absetzen.
//
// Revision 1.41  2002/03/28 09:11:32  gnomi
// news_index darf den ERQ nutzen.
//
// Revision 1.40  2002/02/24 06:37:56  gnomi
// nomask simul_efuns im Master/Simul-Efun erlauben, auch wenn sie im Endeffekt
// nicht Master oder Sefun werden, damit man die anderen Compile-Fehler sieht.
//
// Revision 1.39  2002/02/22 03:07:18  gnomi
// Gnomi noch ein paar Privilegien eingeraeumt. :-)
//
// Revision 1.38  2002/02/02 23:03:41  gnomi
// Fehlermelder ist umgezogen.
//
// Revision 1.37  2002/01/23 09:18:16  gnomi
// Fehlermelder erlauben, Arrays bis zu 5000 Elementen zu verarbeiten.
//
// Revision 1.36  2001/12/21 19:20:53  freaky
// fehlendes ifdef eingefuegt.
//
// Revision 1.35  2001/12/21 19:16:06  freaky
// nomask-simul-efun: checks auf switch-case umgestellt.
//
// Revision 1.34  2001/12/14 23:58:05  gnomi
// Beim Laden/Aufruf eines virtal_compilers TO auf PO setzen, damit wir nicht
// schuld fuer evntl. Ladefehler sind...
//
// Revision 1.33  2001/10/01 17:52:56  freaky
// ab jetzt arbeitet UNItopia nur noch mit Drivern ohne deprecated Funktionen.
//
// Revision 1.32  2001/08/28 23:21:25  freaky
// message-system jetzt default
//
// Revision 1.31  2001/08/23 13:34:29  freaky
// Laden der Gilden-Objekte mit limited
//
// Revision 1.30  2001/07/22 01:06:03  gnomi
// Gnomi etwas mehr Freiheiten geben... ;-)
//
// Revision 1.29  2001/07/18 20:59:39  gnomi
// setup_renamed_object eingefuehrt.
//
// Revision 1.28  2001/06/24 00:58:36  gnomi
// Fuer Passworteingaben darf man INPUT_IGNORE_BANG nutzen.
//
// Revision 1.27  2001/05/30 16:03:08  freaky
// Versionabhaengigkeiten rausgeworfen.
//
// Revision 1.26  2001/05/30 14:41:55  freaky
// Beim Laden der simul-efun keine weiteren Lade-Versuche unternehmen.
//
// Revision 1.25  2001/05/30 10:55:32  freaky
// simul-efun braucht keine privilege-violations
//
// Revision 1.24  2001/05/14 15:10:16  gnomi
// (string) -> ({string})
//
// Revision 1.23  2001/04/30 21:55:23  freaky
// login-ob darf Limited verwenden.
//
// Revision 1.22  2001/04/30 21:14:48  freaky
// /apps/plugin darf limited verwenden fuer den Preload aller Plugins.
//
// Revision 1.21  2001/04/29 14:21:54  freaky
// deprecated Funktion copy-mapping rausgenommen.
//
// Revision 1.20  2001/04/26 21:15:49  sissi
// Auch die Berechtigung fuer debug info rausgenommen.
//
// Revision 1.19  2001/04/26 21:01:04  sissi
// Genehmigung auf limited fuer call out simul efun wieder rausgenommen,
// war unnoetig.
//
// Revision 1.18  2001/04/26 20:52:37  sissi
// call out simul efun darf limited und debug info verwenden.
//
// Revision 1.17  2001/04/26 00:23:31  sissi
// Sissis Workroom darf debug info aufrufen.
//
// Revision 1.16  2001/03/13 22:53:22  freaky
// einige Funktionen protected machen.
//
// Revision 1.15  2001/02/24 15:33:22  freaky
// send_imp wieder eingebaut, wenn __DEPRECATED__ definiert ist.
//
// Revision 1.14  2001/02/24 15:09:41  freaky
// receive_imp und send_imp nach *_udp umbenannt.
//
// Revision 1.13  2001/02/11 22:59:09  sissi
// Mammi Privilegien geben richtig gemacht.
//
// Revision 1.12  2001/02/11 22:56:13  sissi
// Mammis Zauberstabtools, die sie im Auftrag von Freaky erstellt, ein
// üaar Privilegien eingeraeumt.
//
// Revision 1.11  2001/01/24 17:47:09  freaky
// tweak
//
// Revision 1.10  2001/01/15 22:15:50  freaky
// MESSAGE_SYSTEM ist im HomeMUD aktiv -> privilege_violation anpassen.
//
// Revision 1.9  2001/01/06 18:29:49  freaky
// kleiner Tweak.
//
// Revision 1.8  2000/12/07 23:01:50  sissi
// wahlurne eingetragen
//
// Revision 1.7  2000/08/29 14:27:23  freaky
// file_name() nach object_name() umgebaut.
// filter_array() nach filter() umgebaut.
// map_array() nach map() umgebaut.
// (also alles an die neuen Efuns angepasst)
//
// Revision 1.6  2000/07/16 00:04:55  freaky
// nomask simul_efun bekommt bei who bei symbol_function() eon Objekt uebergeben
// und keinen String.
//
// Revision 1.5  2000/06/18 16:26:15  freaky
// kleinere schoenheitsaenderungen in compile_object()
//

#pragma strict_types

/*
 * Give a path to a simul_efun file. Observe that it is a string returned,
 * not an object. But the object has to be loaded here. Return 0 if this
 * feature isn't wanted.
 */
string get_simul_efun()
{
    string err;

    if (!loading_simul_efun)
    {
	loading_simul_efun = 1;
	if (err = catch(load_object(SIMUL_EFUN)))
	{
	    loading_simul_efun = 0;
	    debug_message("Failed to load Simul-Efun " + SIMUL_EFUN +
		    " " + err, DMSG_STDOUT | DMSG_LOGFILE);
	}
	else
	{
	    loading_simul_efun = 0;
	    return SIMUL_EFUN;
	}
    }
    if (err = catch(load_object(SPARE_SIMUL_EFUN)))
    {
	debug_message("Failed to load Spare-Simul-Efun " + SPARE_SIMUL_EFUN +
		" " + err, DMSG_STDOUT | DMSG_LOGFILE);
	efun::shutdown();
	return 0;
    }
    return SPARE_SIMUL_EFUN;
}

/*
 * Diese Funktion wird von printf("%O") aufgerufen, wenn die Variable ein
 * objekt enthaelt.
 * Seit 3.2.6-dev63 gibt es eine efun object_name. Deswegen wurde das hier
 * umbenannt nach printf_obj_name.
 */
string printf_obj_name(object ob)
{
    string tmp;

    tmp = ({string})ob->query_real_name();
    if (stringp(tmp) && tmp != "")
	return tmp;
    tmp = ({string})ob->query_name();
    if (stringp(tmp) && tmp != "")
	return tmp;
    return "UID:" + getuid(ob);
}

void dangling_lfun_closure()
{
    set_this_object(previous_object());
    raise_error("dangling lfun closure\n");
}

int valid_file_name(string name)
{
    return !sizeof(lower_case(name) -
	    "abcdefghijklmnopqrstuvwxyz1234567890/-_.@ ");
}

// Hiermit kann man ueberpruefen lassen, ob ein Objekt mit der Funktion
// rename_object umbenannt werden darf.
// Wenn flag != 0 ist, wird das Objekt zerstoert, und eine Fehlermeldung
// erzeugt, wenn dies der Fall ist.
#define ALLOWED_RENAME_OBS ({ "d", "obj", "p", "w", "z" })
int rename_allowed(object ob, string to_name, int flag)
{
    string *path, tmp, file, reason;
    int junk;

    file = object_name(ob);
    path = explode(file,"/");
    // Check, ob es ein Clone ist.
    if (sscanf(path[<1],"%s#%d",tmp,junk) == 2)
    {
	// Check, ob das Objekt aus einem legalen Verzeichnis kommt
	if (member(ALLOWED_RENAME_OBS,path[1]) >= 0)
	{
	    // Check, ob das Objekt aus .../obj/... kommt
	    if (member(path,"obj") >= 0)
	    {
		if (!environment(ob))
		{
		    if (valid_file_name(to_name))
		    {
			return 1;
		    }
		    else
		    {
			reason = "Can't rename to an invalid filename (" +
			    to_name + ")";
		    }
		}
		else
		{
		    reason = "Object has an environment";
		}
	    }
	    else
	    {
		reason = "Object does not resides in a '/obj/'-dir";
	    }
	}
	else
	{
	    reason = "Not allowed to rename this Object";
	}
    }
    else
    {
	reason = "Object is no clone";
    }

    // Objekt darf nicht umbenannt werden
    write_file("/log/sys/PRIVI","Illegal use of rename_object: " + file +
	    " PO:" + object_name(previous_object()) + " " + reason + ".\n");
    if (flag)
    {
	// wenn flag != 0 ist, dann hier Objekt zerstoeren und
	// Raise-error aufrufen
	ob->remove();
	if (ob)
	    destruct(ob);
	raise_error("Illegal use of rename_object by a virtual_compiler: " +
		"Illegal to rename object '" + file + "': " + reason + ".\n");
    }
    return 0;
}

private object call_vc(mixed vc, string file, string path)
{
    set_this_object(previous_object());

    if(stringp(vc))
    {
        catch(vc = load_object(vc); publish);

        if(!objectp(vc))
            vc = 0;
    }

    if(vc)
        return ({object})vc->virtual_compiler(file,path);
}

int last_compiled_objects_time;
mapping last_compiled_objects = ([:0]);  // Ein Mapping mit den Namen aller zu ladenden Dateien, um Rekursionen zu finden.

object compile_object(string str)
{
    object ob;
    mixed vc;
    mapping lco; // Referenz auf last_compiled_objects wegen set_this_object.

#if 1
    if ((object_name(previous_object()) + ".c") != SIMUL_EFUN)
	if (find_player("freaky"))
	    tell_object(find_player("freaky"),sprintf("$$ CO:%O: TP:%O PO:%O\n",
			str,this_player(),previous_object()));
#endif

    // Filenamen anpassen
    str = str[0..<3];
    if (str[0] != '/')
	str = "/" + str;

    if(last_compiled_objects_time == time() &&
       member(last_compiled_objects, str))
    {
        do_log_error("Rekursiver Aufruf von compile_object() "
                     "mit gleichem Dateinamen: " + str + "\n",
                     __FILE__,
                     object_name(
                         ((object_name(previous_object()) + ".c") != SIMUL_EFUN)?
                         previous_object(1):previous_object()),
                     __LINE__, 0, 1);
    }
    else
    {
        if(last_compiled_objects_time != time())
        {
            last_compiled_objects_time = time();
            last_compiled_objects = ([str]);
        }
        else
            m_add(last_compiled_objects, str);
    }
    lco = last_compiled_objects;

    if (file_size(str + ".udl") > 0)
	ob = build_udl_object(str);
    else	// Virtual Compiler
    {
	string *path, tmp;
        object vc_ob;
	object to = this_object();

	path = explode(str,"/");
	if (sizeof(path) < 3)
	{
            m_delete(lco, str);
	    return 0;
	}

	// MAP-Raeume. 
	// Achtung, das ist leicht rekursiv. Daher bei /map/m?_? testen,
	// ob dort nicht die Datei zum Laden rumliegt.
	if ((path[1] == "map" && file_size(str + ".c") < 0) &&
    	    sscanf(path[<1],"m%~d_%~d") == 2)
	    {
	    	set_this_object(previous_object());
		ob = ({object})MAP_OB->create_map_object(str);
		set_this_object(to);
		m_delete(lco, str);
		return ob;
	    }

	tmp = implode(path[0..<2],"/");
	vc = tmp + "/virtual_compiler.c";
        vc = find_object(vc) || ((file_size(vc)>0)?vc:0);

        // VC nur laden, wenn er in einem ladbaren Verzeichnis liegt
        if(stringp(vc) && no_load_file(vc))
        {
            vc = 0;
        }

	if (vc)
	{
	    ob = funcall(#'call_vc,vc,path[<1],tmp + "/");
	    //set_this_object(previous_object());
	    //ob = ({object})vc->virtual_compiler(path[<1],tmp + "/");
	    //set_this_object(to);
	    if (ob && !objectp(ob))
	    {
		do_log_error("virtual_compiler lieferte weder 0 noch ein Objekt zurueck.\n",
		    tmp + "/virtual_compiler.c", objectp(vc)?object_name(vc):vc, 0, 0, 0);
		m_delete(lco, str);
		return 0;
	    }
	}
    }
    
    if (!ob || object_name(ob) == str)
    {
	m_delete(lco, str);
	return ob;
    }
    if (rename_allowed(ob,str,1))
    {
        string old_name = object_name(ob);
        rename_object(ob,str);
        if(vc)
            vc->setup_renamed_object(ob, old_name);
	if(ob)
	    ob->setup_renamed_object(stringp(vc)?find_object(vc):vc, old_name); 
	m_delete(lco, str);
	return ob;
    }
    m_delete(lco, str);
    return 0;
}

/*
 * privilege_violation is called when objects try to do illegal things,
 * or files being compiled request a privileged efun.
 *
 * return values: 
 *   1: The caller/file is allowed to use the privilege.
 *   0: The caller was probably misleaded; try to fix the error.
 *  -1: A real privilege violation. Handle it as error.
 */
#define PROFILE_PRIVI
#ifdef PROFILE_PRIVI
private static mapping profile_privi;
mapping query_profile_privi() { return copy(profile_privi); }
#endif

int privilege_violation(string what, mixed who, mixed where, mixed how)
{
#if 0
    if (find_player("menaures"))
	tell_object(find_player("menaures"),
		sprintf("WHAT:%O:\nWHO:%O:\nWHERE:%O:\nHOW:%O\n",what,who,where,how));
#endif


#ifdef UNItopia
#   define FTOOL "w/freaky/obj/ftool"
#   define TERMINAL_1993 "d/Campus/obj/1993/connect"
#else
#   ifdef NO_PRIVILEGE_VIOLATIONS
	return 1;
#   endif
#endif

#ifdef PROFILE_PRIVI
    if (!profile_privi)
	profile_privi = ([]);
    profile_privi[what]++;
#endif
    switch(what)
    {
      case "configure_driver":
        if (load_name(who) == PORTAL_CONNECTION && where == DC_TLS_CERTIFICATE)
           return 1;
        break;

      case "input_to":
	if (!strstr(object_name(who),"/obj/zauberstab#") ||
		!strstr(object_name(who),"/secure/obj/login#") ||
                object_name(who) == PLAYER_SECOND ||
                object_name(who) == PORTAL_ROOM ||
#ifdef TERMINAL_1993
                !strstr(object_name(who), "/"TERMINAL_1993"#") ||
#endif
                playerp(who))
	    return 1;
	break;
      case "bind_lambda":
	if (object_name(who) == MAP_OB)
	    return 1;
#ifdef FTOOL
	if (object_name(who) == "/" FTOOL)
	    return 1;
	if (object_name(who) == "/w/freaky/LPC_zst")
	    return 1;
	if (object_name(who) == "/w/gnomi/LPC_zst")
	    return 1;
	if (object_name(who) == "/w/sorcerer/LPC_zst")
	    return 1;
	if (object_name(who) == "/w/menaures/LPC_zst")
	    return 1;
	if (object_name(who) == "/w/myonara/LPC_zst")
	    return 1;
#endif
	break;
      case "rename_object":
	if (object_name(who) == MAP_OB)
	    return 1;
	break;
      case "send_udp":
	if (object_name(who) == INETD ||
	    object_name(who) == FTP_SERVER ||
	    object_name(who) == RPC_SERVER)
	    return 1;
	break;
      case "erq":
	if (object_name(who) == INTERNET_MAILD || playerp(who) ||
		object_name(who) == SOCKETD ||
		object_name(who) == NEWS_INDEX
#ifdef UNItopia
                || load_name(who) == "/z/Spiele/Go/obj/gnugo"
		|| load_name(who) == "/w/gnomi/erqtest"
#endif
                )
	    return 1;
	break;
      case "limited":
	if (object_name(who) == ERROR_DB)
	    return 1;
	if (!strstr(object_name(who),LOGIN_OB "#"))
	    return 1;
	if (playerp(who))
	    return 1;
	if (object_name(who) == GOETTER_REGISTER)
	    return 1;
	if (object_name(who) == QUEST_ROOM)
	    return 1;
	if (object_name(who) == GILDEN_OB)
	    return 1;
	if (object_name(who) == "/apps/autoloader")
	    return 1;
	if (!strstr(object_name(who),"/obj/zauberstab#") ||
            !strstr(object_name(who),"/obj/wizard_shell#"))
	    return 1;
	if (object_name(who) == "/apps/plugin")
	    return 1;
	if (object_name(who) == HELP_TOOL)
	    return 1;
	if (object_name(who) == "/w/gnomi/LPC_zst")
	    return 1;
        break;
      case "call_out_info":
	if (!strstr(object_name(who),"/obj/zauberstab#"))
	    return 1;
	break;
      case "nomask simul_efun":
	if (objectp(who))
	    break;
	switch (where)
	{
	  case "binary_message":
	    if (who == "secure/obj/login.c" ||
	        who == "i/player/webmud.c" ||
	        who == "i/player/options.c" ||
	        who == "i/player/telnet_neg.c")
		return 1;
	    break;
	  case "move_object":
	    if (who == "i/move.c" ||
		    who == "i/tools/update_actions.c" ||
		    who == "i/player/login.c")
		return 1;
	    break;
	  case "query_ip_number":
	  case "query_ip_name":
	  case "interactive_info":
	    if (who == "apps/town.c" ||
		    who == "apps/statistik.c" ||
		    who == "i/player/login.c" ||
		    who == "i/player/more.c" ||
		    who == "i/player/webmud.c" ||
		    who == "i/player/vt100client.c" ||
		    who == "i/player/player.c" ||
		    who == "secure/obj/login.c" ||
		    who == "secure/i/sperre.c" ||
		    who == "secure/level_lister.c" ||
		    who == "secure/rpc/webmud.c" ||
		    who == "secure/portal/portal.c" ||
		    who == "w/sissi/priv/wahl/wurne.c")
		return 1;
	    break;
	  case "tell_object":
	    if (who == "i/player/player.c" ||
		    who == "obj/pplayer.c" ||
		    who == LOGIN_OB[1..] + ".c" ||
		    who == "i/wizard_shell/wizard_shell.c" ||
		    who == "i/player/telnet_neg.c" ||
		    who == "i/player/vt100client.c" ||
		    who == RPC_CONNECTION[1..] + ".c" ||
		    who == PORTAL_CONNECTION[1..] + ".c"
#ifdef TERMINAL_1993
                 || who == TERMINAL_1993".c"
#endif
               )
		return 1;
	    break;
	  case "command":
	    if (who == "i/player/tippse.c" ||
		    who == "i/player/player.c" ||
		    who == "i/player/vt100client.c" ||
		    who == "i/player/intermud.c" ||
		    who == "i/wizard_shell/shell.inc" ||
		    who == "i/monster/monster.c")
		return 1;
	    break;
	  case "command_stack":
	    if (who == "i/player/player.c")
	        return 1;
	  case "garbage_collection":
	  case "shutdown":
	    if (who == "room/rathaus/div/shut.c"
#ifdef UNITOPIA
            ||  who == "w/gnomi/LPC_zst.c"
#endif
	    )
		return 1;

	    break;
	  case "debug_info":
	    if (who == "room/rathaus/div/shut.c" ||
	        who == "apps/object_db.c" ||
		    who == "p/Plugins/zdebuginfo.c" ||
		    who == "p/mammi/plugin/zdebuginfo.c" ||
#ifdef UNItopia
		    who == "w/sissi/workroom.c" ||
#endif
		    who == "i/player/wiz_soul.c" ||
		    who == "i/living/hands.c")
		return 1;
	    break;
	  case "object_info":
	    if (who == "p/mammi/plugin/zobjectinfo.c" ||
	        who == "apps/object_db.c" ||
	        who == "p/Plugins/zobjectinfo.c")
		return 1;
	    break;
	  case "functionlist":
	    if (who == "p/Plugins/zshowfunction.c")
		return 1;
	    break;
	  case "query_actions":
	    if (who == "i/player/vt100client.c")
		return 1;
	    break;
	    
	  case "set_this_player":
	    if (who == "obj/newsreader.c"
#ifdef TERMINAL_1993
                || who == TERMINAL_1993".c"
#endif
               )
		return 1;
	    break;
	}
	// Damit bei einem Compile Fehler man nicht diese Privis
	// auf dem Schirm bekommt, sondern die Compile Fehler.
	if (!strstr(who, "secure/master/") ||
	    !strstr(who, "secure/simul_efun/"))
		return 1;
	/*
        if (who == SIMUL_SECURE[1..] || who == SPARE_SIMUL_SECURE[1..])
	    return 1;
	if (who == "secure/simul_efun/call_out.inc")
	    return 1;
	*/
	if (who[0..12] == "i/zauberstab/")
	    return 1;
#ifdef FTOOL
	if (who == FTOOL ".c")
	    return 1;
	if (who == "w/freaky/LPC_zst.c")
	    return 1;
	if (who == "w/gnomi/LPC_zst.c")
	    return 1;
        if (who == "w/menaures/LPC_zst.c")
            return 1;
        if (who == "w/sorcerer/LPC_zst.c")
            return 1;
        if (who == "w/myonara/LPC_zst.c")
            return 1;
#endif
	break;

      case "garbage_collection":
      case "shutdown":
	if (object_name(who) == "/room/rathaus/div/shut"
#ifdef UNItopia
         || object_name(who) == "/w/gnomi/LPC_zst"
#endif
	)
	    return 1;
	break;

      case "set_extra_wizinfo":
      case "set_extra_wizinfo_size":
      case "get_extra_wizinfo":
	if (who == find_object(SIMUL_EFUN) ||
		who == find_object(SPARE_SIMUL_EFUN))
	    return 1;
#ifdef FTOOL
	if (!strstr(object_name(who),"/" FTOOL "#"))
	    return 1;
	if (object_name(who) == "/w/freaky/LPC_zst")
	    return 1;
#endif
	break;
      case "wizlist_info":
#ifdef FTOOL
	if (!strstr(object_name(who),"/" FTOOL "#"))
	    return 1;
	if (object_name(who) == "/w/freaky/LPC_zst")
	    return 1;
#endif
        if (object_name(who) == "/w/menaures/apps/top")
            return 1;
        break;

      case "variable_list":
#ifdef FTOOL
        if (object_name(who) == "/w/gnomi/LPC_zst")
	    return 1;
        if (object_name(who) == "/w/sorcerer/LPC_zst")
	    return 1;
        if (object_name(who) == "/w/myonara/LPC_zst")
	    return 1;
#endif
	break;

      case "net_connect":
#ifdef UNItopia
        // Fuer das UNItopia 1993 Terminal:
        if(!strstr(object_name(who), "/"TERMINAL_1993"#")
           && where == "127.0.0.1" && how == 1993)
           return 1;
#endif
        if( load_name(who) == PORTAL_CONNECTION)
           return 1;
        break;
      case "enable_telnet":
        if(
#ifdef UNItopia
            !strstr(object_name(who), "/"TERMINAL_1993"#") ||
#endif
	    load_name(who) == RPC_CONNECTION ||
	    load_name(who) == PORTAL_CONNECTION)
           return 1;
        break;

      case "mysql":
        break;
	
      case "sqlite_pragma":
        switch(lower_case(where))
	{
	    case "table_info":
	    case "auto_vacuum":
	    case "count_changes":
	    case "case_sensitive_like":
	    case "user_version":
	    case "foreign_keys":
		return 1;
	}
	    
#ifdef UNItopia
        if(!strstr(object_name(who), "/w/gnomi/"))
	   return 1;
#endif
	break;

      case "set_limits": // Neue Werte in 'where'
      case "attach_erq_demon":
      case "execute_command":
      case "set_auto_include_string":
      case "set_driver_hook":
      case "set_this_object":
      case "shadow_add_action":
      case "symbol_variable":
	break;
    }
    write_file("/log/sys/PRIVI",sprintf("what:%O: who:%O: where:%O:\n",
		what,who,where));
    return -1;
}
