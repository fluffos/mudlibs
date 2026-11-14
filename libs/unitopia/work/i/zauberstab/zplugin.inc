// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zplugin.inc
// Description:	Der zplugin-Befehl des Zauberstabes
// Author:	Freaky (10.01.2000)
// Modified by:	Freaky (11.02.2000) Plugin-Variablen-Handling korrigiert
//				    -H als Option eingebaut
//
// $Log: zplugin.inc,v $
// Revision 1.12  2015/06/01 19:39:17  gnomi
// Rueckgabetypen korrigiert.
//
// Revision 1.11  2012-09-03 17:58:05  sorcerer
// handle_plugin_list_options mit selber Datenbasis wie print_...
//
// Revision 1.10  2009-01-07 15:25:24  gnomi
// Plugin-Ersatz-Mechanismus von Sorcerer eingebaut.
//
// Revision 1.9  2008-04-26 18:23:07  gnomi
// Einstellungsmenue eingebaut.
//
// Revision 1.8  2008/01/16 09:39:34  gnomi
// Eval-Reserven fuer die catch-Aufrufe festlegen.
//
// Revision 1.7  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#define PL_VERB  0
#define PL_FLAG  1
#define PL_USAGE "zplugin -l | -L | [-s | -S] { -n | -l } | [-a | -d | -c | -h | -H] <plugin>\n"
#define PL_ALL		0
#define PL_REGISTERED	1

mixed *plugin_commands = ({});

int plugin_exists(string ob)
{
    return member(params["plugins"],ob);
}

private int compare_plugin_name(string plugin, string cmp)
{
    if (plugin == cmp)
	return 1;
    if (explode(plugin,"/")[<1] == cmp)
	return 1;
}

private string* internal_search_plugin(string plugin, int flag)
{
    string tmp;
    mapping pls;
    
    if (flag == PL_REGISTERED)
	pls = params["plugins"];
    else
	pls = PLUGIN_MASTER->query_plugins();

    tmp = OWN->add_path(plugin);
    if (member(pls,tmp))
	return ({tmp});

    return filter(m_indices(pls),#'compare_plugin_name,plugin);
}

private string search_plugin(string plugin, int flag)
{
    string *liste = internal_search_plugin(plugin, flag);

    if (sizeof(liste) == 1)
	return liste[0];
    if (sizeof(liste) == 0)
	W("Das Plugin '" + plugin + "' gibt es nicht.\n");
    else
	WLN("Der Pluginname ist nicht eindeutig:\n    " +
		implode(liste,"\n    "));
    return 0;
}

private int list_plugins(int flag)
{
    W("Plugins:\n");
    foreach(mixed *plugin : plugin_commands)
    {
	W(plugin[0] + "\n");
	if (flag)
	{
	    foreach(mixed *cmd : plugin[1])
		W(sprintf("    %-15s %3d\n",cmd[PL_VERB],cmd[PL_FLAG]));
	}
    }
    PRINT;
    return 1;
}

private int sort_plugins(string pl1, string pl2, mapping pls, int flag)
{
    return pls[pl1,flag] > pls[pl2,flag];
}

private string show_plugins(string str, int flag)
{
    mapping pls;
    string *names, ret, tmp;
    
    pls = PLUGIN_MASTER->query_plugins();

    if (str == "-n")
	names = sort_array(m_indices(pls),#'<);
    else if (str == "-l")
	names = sort_array(m_indices(pls),#'sort_plugins,pls,1);
    else
	names = sort_array(m_indices(pls),#'sort_plugins,pls,0);
    
    ret = "Plugin                                    registriert         Letzte Nutzung\n";
    if (flag)
	ret += LINE;
    for (int i = sizeof(names); i--; )
    {
	ret += sprintf("%-40s  %s   %s\n",names[i],
		shorttimestr(pls[names[i],0]),
		shorttimestr(pls[names[i],1]));
	if (flag)
	{
	    if (!tmp = names[i]->query_plugin_info())
		ret += "Plugin '" + names[i] + "' hat keine Hilfe.\n";
	    else
		ret += tmp;
	    ret += LINE;
	}
    }
    return ret;
}

private string get_plugin_help(object plugin)
{
    string ret, tmp;
    mixed *coms;

    ret = "Plugin: " + object_name(plugin) + "\n" + LINE;
    if (!tmp = plugin->query_plugin_info())
	ret += "Plugin '" + object_name(plugin) + "' hat keine Hilfe.\n";
    else
	ret += tmp;
    ret += LINE;
    coms = plugin->query_plugin_commands();
    if (!sizeof(coms))
	ret += "Plugin '" + object_name(plugin) +
	    "' definiert keine Kommandos.\n" + LINE;
    else
    {
	ret += "\nDefinierte Kommandos:\n" + LINE;
	foreach(mixed *com : coms)
	    ret = sprintf("%s%-15s %3d\n%s" LINE,ret,com[PL_VERB],com[PL_FLAG],
		    plugin->query_plugin_help(com[PL_VERB]) || "");
    }
    return ret;
}

private string add_plugin(string file, mixed args)
{
    object ob;
    mixed *coms;
    string ret;

    if (ret = PLUGIN_MASTER->query_plugin_replacement(file))
        file = ret;
    ret = catch(ob = touch(file); reserve 5000);
    if (ret)
	return "Fehler beim Laden des Plugins '" + file + "': "+ ret;
    if (!ob)
	return "File '" + file + "' gibt es nicht.\n";
    if (ret = PLUGIN_MASTER->invalid_plugin(ob))
	return wrap("Plugin '" + object_name(ob) +
		    "' ist kein gueltiges Plugin: " + ret + "\n");
    coms = ob->query_plugin_commands();
    if (!sizeof(coms))
	return "Plugin '" + object_name(ob) + "' definiert keine Kommandos.\n";
    plugin_commands += ({ ({ object_name(ob), coms }) });
    foreach(mixed *com : coms)
	add_action("do_plugin_command",com[PL_VERB],com[PL_FLAG]);
    // Als Plugin eintragen
    params["plugins"][object_name(ob)] = args;
    OWN->set_zauberstab_info(params);
    ret = catch(ob->do_plugin_initialize(); reserve 3000);
    if (ret)
        do_error2("Fehler beim Initialisieren des Plugins: "+ret,file,file,0); 
    return 0;
}

int z_plugin(string str)
{
    object ob;
    string ret, flag, file;

    SECURE;
    HELP_NO_VERB("zplugin");

    if (!str || str[0] != '-')
	FAIL(PL_USAGE);
    if (str == "-l")
	return list_plugins(0);
    if (str == "-L")
	return list_plugins(1);
    if (str == "-s")
    {
	W(show_plugins(0,0));
	PRINT;
	return 1;
    }
    if (str == "-S")
    {
	W(show_plugins(0,1));
	PRINT;
	return 1;
    }

    if (sscanf(str,"-%s %s",flag,file) != 2)
	FAIL(PL_USAGE);

    switch(flag)
    {
	case "a":
	    file = search_plugin(file,PL_ALL);
	    if (!file)
	    {
		PRINT;
		return 1;
	    }
	    ob = touch(file,NO_LOG | NO_WRITE);
	    if (!ob)
		FAIL("Plugin '" + file + "' gibt es nicht.\n");
	    if (plugin_exists(object_name(ob)))
		FAIL("Plugin '" + object_name(ob) +
			"' ist schon eingetragen.\n");
	    ret = add_plugin(file,0);
	    if (ret)
		FAIL(ret);
	    W("Ok.\n");
	    break;
	case "d":
	    file = search_plugin(file,PL_REGISTERED);
	    if (!file)
	    {
		PRINT;
		return 1;
	    }
	    if (!plugin_exists(file))
		FAIL("Plugin '" + file + "' ist nicht eingetragen.\n");
	    for (int i = sizeof(plugin_commands); i--; )
	    {
		if (plugin_commands[i][0] == file)
		{
		    foreach(mixed *com : plugin_commands[i][1])
			remove_action(com[PL_VERB]);
		    plugin_commands = arr_delete(plugin_commands,i);
		    break;
		}
	    }
	    ob = touch(file,NO_LOG);
	    if (ob)
		ob->do_plugin_remove();
	    m_delete(params["plugins"],file);
	    OWN->set_zauberstab_info(params);
	    W("Ok.\n");
	    break;
	case "c":
	    file = search_plugin(file,PL_REGISTERED);
	    if (!file)
	    {
		PRINT;
		return 1;
	    }
	    if (!plugin_exists(file))
		FAIL("Plugin '" + file + "' ist nicht eingetragen.\n");
	    W(sprintf("Config:%O\n",params["plugins"][file]));
	    break;
	case "h":
	    file = search_plugin(file,PL_ALL);
	    if (!file)
	    {
		PRINT;
		return 1;
	    }
	    ob = touch(file,NO_LOG | NO_WRITE);
	    if (!ob)
		FAIL("File '" + file + "' gibt es nicht.\n");
	    if (PLUGIN_MASTER->invalid_plugin(ob))
		FAIL("Objekt '" + object_name(ob) + "' ist kein Plugin.\n");
	    if (!ret = ob->query_plugin_info())
		FAIL("Plugin '" + object_name(ob) + "' hat keine Hilfe.\n");
	    W(ret);
	    break;
	case "H":
	    file = search_plugin(file,PL_ALL);
	    if (!file)
	    {
		PRINT;
		return 1;
	    }
	    ob = touch(file,NO_LOG | NO_WRITE);
	    if (!ob)
		FAIL("File '" + file + "' gibt es nicht.\n");
	    if (PLUGIN_MASTER->invalid_plugin(ob))
		FAIL("Objekt '" + object_name(ob) + "' ist kein Plugin.\n");
	    W(get_plugin_help(ob));
	    break;
	case "s":
	    W(show_plugins(file,0));
	    break;
	case "S":
	    W(show_plugins(file,1));
	    break;
	default:
	    FAIL(PL_USAGE);
    }
    PRINT;
    return 1;
}

private string *get_plugin_commands(string verb)
{
    string *ret, plugin;

    ret = ({});
    foreach(mixed *comm : plugin_commands)
    {
	plugin = comm[0];
	foreach(mixed *com : comm[1])
	{
	    if (com[PL_FLAG] == 0)
	    {
		if (verb == com[PL_VERB])
		    ret += ({ com[PL_VERB], plugin });
	    }
	    else if (com[PL_FLAG] == 1)
	    {
		if (!strstr(verb,com[PL_VERB]))
		    ret += ({ com[PL_VERB], plugin });
	    }
	    else if (com[PL_FLAG] < 0)
	    {
		if (strlen(verb) >= -com[PL_FLAG] &&
			!strstr(com[PL_VERB],verb))
		    ret += ({ com[PL_VERB], plugin });
	    }
	    else
	    {
		printf("Falscher Typ: %O (%O %O %O)\n",com[PL_FLAG],
			com[PL_VERB],com[PL_FLAG],plugin);
	    }
	}
    }
    return ret;
}

int do_plugin_command(string str)
{
    string *coms;
    
    coms = get_plugin_commands(query_verb());
    for (int i = 0; i < sizeof(coms); i += 2)
	if (coms[i + 1]->execute_plugin_fun(coms[i],str))
	    return 1;
    return 0;
}

private string *get_plugin_command_help(string verb)
{
    string ret, help;
    mixed *coms;

    coms = get_plugin_commands(verb);
    if (!sizeof(coms))
	coms = get_plugin_commands(lower_case(verb));
    
    ret = "";
    for (int i = 0; i < sizeof(coms); i += 2)
    {
	help = coms[i + 1]->query_plugin_help(coms[i]);
	if (help)
	    ret += help + LINE;
    }
    if (strlen(ret))
	return explode(LINE + ret,"\n")[0..<2];
}

/*
mixed *query_plugin_commands()
{
    return deep_copy(plugin_commands);
}
*/

mixed query_plugin_vars()
{
    return params["plugins"][object_name(previous_object())];
}

void set_plugin_vars(mixed vars)
{
    if (plugin_exists(object_name(previous_object())))
    {
	params["plugins"][object_name(previous_object())] = vars;
	OWN->set_zauberstab_info(params);
    }
}

private void do_plugin_remove(string plugin)
{
    object ob;
    
    ob = touch(plugin,NO_LOG);
    if (ob)
	ob->do_plugin_remove();
}

private void plugins_remove()
{
    if (params)
	map(params["plugins"],#'do_plugin_remove);
}

private varargs void print_plugin_options(int quiet)
{
    int length = sizeof(to_string(sizeof(plugin_commands)));
    int i;
    
    OWN->more(
        ({
" Plugin:",
"   -  (H)inzufuegen",
"",
" Eingetragene Plugins:",
        })+
	foldl(map(sort_array(m_indices(params["plugins"]),#'>),
	(:
	    explode(sprintf("  %*d: %-=*s\n", length, ++$2, 74-length, $1),"\n")[0..<2]
	:), &i),({}),#'+),
        ({ "Zauberstabplugins [q,z,?] ",
           "----------- Plugins: ----------------------------------------------------------",
           "-------------------------------------------------------------------------------",
           "...--------------------------------------------------------------------- (MORE)",
           "...--------------------------------------------------------------------- (MORE)"
        }), 0, M_DO_NOT_END|M_FRAME|(quiet?M_NO_FIRST_SCREEN:0),
        "Plugins");
}

private varargs void print_active_plugin_options(int quiet, string plugin)
{
    string name = capitalize(explode(plugin,"/")[<1]);
    object ob = touch(plugin, NO_LOG | NO_WRITE);
    
    OWN->more(
        ({
" Plugin:                        Information:",
"   -  (E)ntfernen                 -  (B)efehle auflisten",
ob->has_plugin_options()?
"   -  (K)onfigurieren             -  Befehe mit H(i)lfe anzeigen":
"                                  -  Befehe mit H(i)lfe anzeigen",
"                                  -  (V)ariablen anzeigen",
"",
        })+
	(explode(((ob && ob->query_plugin_info())||""),"\n")[0..<2]),
        ({ "Plugin "+name+" [q,z,?] ",
	   "----------- Plugin "+name+": "+"-"*(58-sizeof(name)),
           "-------------------------------------------------------------------------------",
           "...--------------------------------------------------------------------- (MORE)",
           "...--------------------------------------------------------------------- (MORE)"
        }), 0, M_DO_NOT_END|M_FRAME|(quiet?M_NO_FIRST_SCREEN:0),
        (["id":"Plugins:Active","plugin":plugin]));
}

private void print_plugin_commands(int quiet, object plugin, int withhelp, closure callback)
{
    string name = capitalize(explode(object_name(plugin),"/")[<1]);
    mixed *text;
    mixed *coms;
    
    text = ({ "Befehle von "+name+":"});
    coms = plugin->query_plugin_commands();
    if (!sizeof(coms))
	text += ({ "Das Plugin definiert keine Befehle." });
    else if(withhelp)
    {
        text += ({
	    "-------------------------------------------------------------------------------"
	});

	foreach(mixed *com : coms)
	    text += ({ sprintf("%-15s %3d", com[PL_VERB], com[PL_FLAG]) })
		 +  (explode(plugin->query_plugin_help(com[PL_VERB]) || "","\n")[0..<2])
		 +  ({ "-------------------------------------------------------------------------------" });
    }
    else
    {
	foreach(mixed *com : coms)
	    text += ({ sprintf("%-15s %3d", com[PL_VERB], com[PL_FLAG]) });
    }
    
    OWN->more(text,
    	({ "Befehle [q,z] ",
	   "----------- Plugin "+name+": "+"-"*(58-sizeof(name)),
    	   "-------------------------------------------------------------------------------",
	   "...--------------------------------------------------------------------- (MORE)",
	   "...--------------------------------------------------------------------- (MORE)"
	}), 0, M_AUTO_END|M_FRAME|(quiet?M_NO_FIRST_SCREEN:0),
	([
	    "id":	"Plugins:Info",
	    "callback":  callback
	]));
}

private varargs void print_plugin_list_options(int quiet)
{
    mixed* pls = sort_array(transpose_array(unmkmapping(
	PLUGIN_MASTER->query_plugins() - params["plugins"])),
	(: $1[0]>$2[0] :));
    int length = sizeof(to_string(sizeof(pls)));
    int i;

    OWN->more(
        ({
	    sprintf("%*s  %-=*s  %-17s  %-17s",
		length, "", 39-length, "Plugin", "registriert", "Letzte Nutzung"),
        })+
	foldl(pls, ({}),
	(:
	    $1 + explode(sprintf("%*d: %-=*s  %s  %s\n",
		length, ++$3, 39-length,
		$2[0], shorttimestr($2[1]), shorttimestr($2[2])),"\n")[0..<2]
	:), &i),
        ({ "Zauberstabplugins [q,z,?] ",
           "----------- Registrierte Plugins: ---------------------------------------------",
           "-------------------------------------------------------------------------------",
           "...--------------------------------------------------------------------- (MORE)",
           "...--------------------------------------------------------------------- (MORE)"
        }), 0, M_DO_NOT_END|M_FRAME|(quiet?M_NO_FIRST_SCREEN:0),
        "Plugins:List");
}

private varargs void print_inactive_plugin_options(int quiet, string plugin)
{
    string name = capitalize(explode(plugin,"/")[<1]);
    object ob = touch(plugin, NO_LOG | NO_WRITE);
    
    OWN->more(
        ({
" Plugin:                        Information:",
"   -  (H)inzufuegen               -  (B)efehle auflisten",
"                                  -  Befehle mit H(i)lfe anzeigen",
"",
        })+
	(explode(((ob && ob->query_plugin_info())||""),"\n")[0..<2]),
        ({ "Plugin "+name+" [q,z,?] ",
	   "----------- Plugin "+name+": "+"-"*(58-sizeof(name)),
           "-------------------------------------------------------------------------------",
           "...--------------------------------------------------------------------- (MORE)",
           "...--------------------------------------------------------------------- (MORE)"
        }), 0, M_DO_NOT_END|M_FRAME|(quiet?M_NO_FIRST_SCREEN:0),
        (["id":"Plugins:Inactive","plugin":plugin]));
}

private int handle_plugin_options(string str)
{
    int nr;

    if(!strlen(str))
        return CONTINUE;

    if(!str2int(str, &nr))
    {
	string *plugins = sort_array(m_indices(params["plugins"]),#'>);

	if(nr<1 || nr>sizeof(plugins))
	    return NOTHING;
	
	print_active_plugin_options(0, plugins[nr-1]);
	return END_MORE;
    }
    else if(strlen(str)==1 || str[1]==' ')
    {
        int c = lower_case(str)[0];
        str = trim(str[2..<1]);

        switch(c)
        {
            case 'h':
		if(sizeof(str))
		{
		    string file;
		    object ob;
		    string *liste;
		    
		    liste = internal_search_plugin(str, PL_ALL);
		    if (sizeof(liste) == 1)
			file = liste[0];
		    else if (sizeof(liste) == 0)
			write("Das Plugin '" + str + "' gibt es nicht.\n");
		    else
			write("Der Pluginname ist nicht eindeutig:\n    " +
			    implode(liste,"\n    ")+"\n");
	
		    if (!file)
			return NOTHING;
		    
		    ob = touch(file, NO_LOG | NO_WRITE);
		    if (!ob)
			write("Plugin '" + file + "' gibt es nicht.\n");
		    else if (plugin_exists(object_name(ob)))
			write("Plugin '" + object_name(ob) +
			    "' ist schon eingetragen.\n");
		    else
		    {
			string ret = add_plugin(file,0);
			if (ret)
			    write(ret);
			else
			    break;
		    }
		    return NOTHING;
		}
		
		print_plugin_list_options(0);
		return END_MORE;
	    
	    case 'q':
		return END_MORE;
	
	    case 'z':
		OWN->start_options_menue();
		return END_MORE;
	
	    case '?':
		OWN->print_options_help(0, "Plugins", str,
		    #'print_plugin_options, 0);
		return END_MORE;
	
            default:
	        return CONTINUE;
	}
	
	print_plugin_options();
	return END_MORE;
    }
}

private int handle_active_plugin_options(string str, string plugin)
{
    object ob;
    
    if(!strlen(str))
        return CONTINUE;

    ob = touch(plugin, NO_LOG | NO_WRITE);

    if(strlen(str)==1 || str[1]==' ')
    {
        int c = lower_case(str)[0];
        str = trim(str[2..<1]);

        switch(c)
        {
            case 'e': // Entfernen
		for (int i = sizeof(plugin_commands); i--; )
		    if (plugin_commands[i][0] == plugin)
		    {
			foreach(mixed *com : plugin_commands[i][1])
			    remove_action(com[PL_VERB]);
			plugin_commands = arr_delete(plugin_commands,i);
			break;
		    }
		
		if (ob)
		    ob->do_plugin_remove();
		m_delete(params["plugins"],plugin);
		OWN->set_zauberstab_info(params);
		print_plugin_options();
		return END_MORE;

	    case 'k': // Konfigurieren
		if(ob->has_plugin_options())
		{
		    ob->do_plugin_options(
			lambda(({'quiet}),({#'print_active_plugin_options, 'quiet, plugin})));
		    return END_MORE;
		}
		break;
	
	    case 'b': // Befehle anzeigen
		if(!ob)
		{
		    write("Plugin konnte nicht geladen werden.\n");
		    return NOTHING;
		}
		print_plugin_commands(0, ob, 0,
		    lambda(({'quiet}),({#'print_active_plugin_options,'quiet,plugin})));
		return END_MORE;

	    case 'i': // Befehle mit Hilfe anzeigen
		if(!ob)
		{
		    write("Plugin konnte nicht geladen werden.\n");
		    return NOTHING;
		}
		print_plugin_commands(0, ob, 1,
		    lambda(({'quiet}),({#'print_active_plugin_options,'quiet,plugin})));
		return END_MORE;

	    case 'v': // Variablen anzeigen
		if(!ob)
		{
		    write("Plugin konnte nicht geladen werden.\n");
		    return NOTHING;
		}
		else
		{
		    string name = capitalize(explode(plugin,"/")[<1]);

		    OWN->more(explode(
		    sprintf("Variable zu %s:\n\n  %-=77Q\n",
			name, params["plugins"][plugin]),"\n")[0..<2],
    		    ({ "Variable [q,z] ",
		       "----------- Plugin "+name+": "+"-"*(58-sizeof(name)),
    		       "-------------------------------------------------------------------------------",
	    	       "...--------------------------------------------------------------------- (MORE)",
	    	       "...--------------------------------------------------------------------- (MORE)"
		    }), 0, M_AUTO_END|M_FRAME,
		    (["id":"Plugins:Info",
		      "callback": lambda(({'quiet}),({#'print_active_plugin_options,'quiet,plugin}))]));
		    return END_MORE;
		}

	    case 'q':
		return END_MORE;
	
	    case 'z':
		print_plugin_options();
		return END_MORE;
	
	    case '?':
		OWN->print_options_help(0, "PluginsAktiv", str,
		    #'print_active_plugin_options, plugin);
		return END_MORE;
	
            default:
	        return CONTINUE;
	}
	
	print_active_plugin_options(0, plugin);
	return END_MORE;
    }
}

private int handle_plugin_info_options(string str, closure callback)
{
    if(!strlen(str))
        return CONTINUE;

    switch(str)
    {
        case "q":
	    return END_MORE;

	case "z":
	    funcall(callback, 0);
	    return END_MORE;

        default:
	    return CONTINUE;
    }
}

private void handle_plugin_info_end(string str, closure callback)
{
    if(!member((["q","z"]),str))
	funcall(callback, 1);
}

private int handle_plugin_list_options(string str)
{
    int nr;

    if(!strlen(str))
        return CONTINUE;

    if(!str2int(str, &nr))
    {
	string *plugins = sort_array(m_indices(PLUGIN_MASTER->query_plugins()
                                                - params["plugins"]), #'>);

	if(nr<1 || nr>sizeof(plugins))
	    return NOTHING;
	
	print_inactive_plugin_options(0, plugins[nr-1]);
	return END_MORE;
    }
    else if(strlen(str)==1 || str[1]==' ')
    {
        int c = lower_case(str)[0];
        str = trim(str[2..<1]);

        switch(c)
        {
	    case 'q':
		return END_MORE;
	
	    case 'z':
		print_plugin_options();
		return END_MORE;
	
	    case '?':
		OWN->print_options_help(0, "PluginsList", str,
		    #'print_plugin_list_options, 0);
		return END_MORE;
	
            default:
	        return CONTINUE;
	}
	
	print_plugin_list_options();
	return END_MORE;
    }
    else
    {
        string file;
        string *liste;
		    
        liste = internal_search_plugin(str, PL_ALL);
        if (sizeof(liste) == 1)
	    file = liste[0];
	else if (sizeof(liste) == 0)
	    write("Das Plugin '" + str + "' gibt es nicht.\n");
	else
	    write("Der Pluginname ist nicht eindeutig:\n    " +
		    implode(liste,"\n    ")+"\n");
	
	if (!file)
	    return NOTHING;

	print_inactive_plugin_options(0, file);
	return END_MORE;
    }
}

private int handle_inactive_plugin_options(string str, string plugin)
{
    object ob;
    
    if(!strlen(str))
        return CONTINUE;

    ob = touch(plugin, NO_LOG | NO_WRITE);

    if(strlen(str)==1 || str[1]==' ')
    {
        int c = lower_case(str)[0];
        str = trim(str[2..<1]);

        switch(c)
        {
            case 'h': // Hinzufuegen
		if(!ob)
		    write("Plugin konnte nicht geladen werden.\n");
		else if (plugin_exists(object_name(ob)))
		    write("Plugin '" + object_name(ob) +
			  "' ist schon eingetragen.\n");
		else
		{
		    string ret = add_plugin(plugin,0);
		    if (ret)
		        write(ret);
		    else
		    {
			print_plugin_options();
			return END_MORE;
		    }
		}
		return NOTHING;

	    case 'b': // Befehle anzeigen
		if(!ob)
		{
		    write("Plugin konnte nicht geladen werden.\n");
		    return NOTHING;
		}
		print_plugin_commands(0, ob, 0,
		    lambda(({'quiet}),({#'print_inactive_plugin_options,'quiet,plugin})));
		return END_MORE;

	    case 'i': // Befehle mit Hilfe anzeigen
		if(!ob)
		{
		    write("Plugin konnte nicht geladen werden.\n");
		    return NOTHING;
		}
		print_plugin_commands(0, ob, 1,
		    lambda(({'quiet}),({#'print_inactive_plugin_options,'quiet,plugin})));
		return END_MORE;

	    case 'q':
		return END_MORE;
	
	    case 'z':
		print_plugin_list_options();
		return END_MORE;
	
	    case '?':
		OWN->print_options_help(0, "PluginsInaktiv", str,
		    #'print_inactive_plugin_options, plugin);
		return END_MORE;
	
            default:
	        return CONTINUE;
	}
	
	print_inactive_plugin_options(0, plugin);
	return END_MORE;
    }
}

string do_plugin_more(mixed text, mixed status_line, int begin, int flags, mixed more_id)
{
    if (plugin_exists(object_name(previous_object())))
	return OWN->more(text, status_line, begin, flags,
	    (["id":"Plugins:Proxy",
	      "plugin": object_name(previous_object()),
	      "data": more_id
	    ]));
}

private int handle_plugin_proxy(string str, int line, int max_line, mixed more_id)
{
    if(plugin_exists(more_id["plugin"]))
    {
	object ob = touch(more_id["plugin"], NO_LOG | NO_WRITE);
	if(ob)
	    return ob->do_plugin_more_action(str, line, max_line, more_id["data"]);
    }

    return END_MORE;
}

private void handle_plugin_proxy_end(string str, int line, int max_line, mixed more_id)
{
    if(plugin_exists(more_id["plugin"]))
    {
	object ob = touch(more_id["plugin"], NO_LOG | NO_WRITE);
	if(ob)
	    return ob->do_plugin_more_end(str, line, max_line, more_id["data"]);
    }
}

private void plugin_input_to_proxy(string str, string plugin, mixed fun, mixed* pars)
{
    if(plugin_exists(plugin))
    {
	object ob = touch(plugin, NO_LOG | NO_WRITE);
	if(ob)
	    ob->do_input_to(str, fun, pars);
    }
}

void do_plugin_input_to(mixed fun, int flags, mixed* pars)
{
    if (plugin_exists(object_name(previous_object())))
    {
	if(flags & INPUT_PROMPT)
	    input_to(#'plugin_input_to_proxy, flags, pars[0], object_name(previous_object()), fun, pars[1..<1]);
	else
	    input_to(#'plugin_input_to_proxy, flags, object_name(previous_object()), fun, pars);
    }
}

closure do_create_callback(mixed fun)
{
    if (plugin_exists(object_name(previous_object())))
	return function mixed(varargs mixed* args) :
	    string plugin = object_name(previous_object())
	{
	    if(plugin_exists(plugin))
	    {
		object ob = touch(plugin, NO_LOG | NO_WRITE);
		if(ob)
		    return ob->do_plugin_callback(fun, args);
	    }
	};
}
