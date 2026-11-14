// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/epilog.inc
// Description:
// Modified By:	Freaky (12.10.2000) Autoloader auch einlesen
//
// $Log: epilog.inc,v $
// Revision 1.7  2008/03/04 11:00:22  gnomi
// Unterstuetzung fuer verteiltes LOAD_AT_STARTUP.
//
// Revision 1.6  2007/08/09 22:27:20  gnomi
// Etwas umstrukturiert.
//
// Revision 1.5  2006/01/22 01:09:23  gnomi
// Flags bei debug_message angeben.
//
// Revision 1.4  2004/04/19 09:34:32  gnomi
// An dev623 angepasst. (restore_value wirft einen Fehler, wenn nach dem
// Zeilenumbruch noch was kommt.)
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

private string *expand_path(string str)
{
    int offset, i;
    string *tmp, *ret, path, rest, pattern;

    offset = member(str,'*');

    if (offset < 0)
    	return ({ str });

    offset = strstr(str,"/",offset);

    if (offset < 0)
    {
	pattern = str;
	rest = "";
    }
    else
    {
	pattern = str[0..(offset-1)];
	rest = str[offset..];
    }
    
    tmp = explode(pattern,"/") - ({"","."});
    path = "/"+implode(tmp[0..<2],"/")+"/";

    tmp = (get_dir(pattern) || ({})) - ({".",".."});

    if (!sizeof(tmp))
    	return ({ str });
    
    tmp = map(tmp,lambda(({'file,'path,'rest}),
    	({#'+, ({#'+, 'path, 'file}), 'rest})),path,rest);

    ret = ({});

    for (i = 0; i < sizeof(tmp); i++)
        ret += filter(expand_path(tmp[i]),lambda(({'x}),
		({#'>, ({#'file_size, 'x}), 0})));
    return ret;
}

/*
 * Function name: 	epilog()
 * Description:		Loads master data, including list of all domains and
 *			wizards. Then make a list of preload stuff
 * Arguments:		load_empty: If true, epilog() does no preloading
 * Return:		List of files to preload
 */
string *epilog(int load_empty)
{
    string *lines, file, *list;
    int i;

    if (load_empty)
    {
	debug_message("Not preloading.\n", DMSG_STDOUT | DMSG_LOGFILE);
	return 0;
    }
    file = read_file("/static/adm/LOAD_AT_STARTUP");
    if (!file)
	return 0;
    lines = explode(file, "\n") - ({""});
    list = ({});
    for (i = 0; i < sizeof(lines); i++)
	if (lines[i][0] == '+')
	{
	    int j = i;
	    foreach(string subfile: expand_path(lines[i][1..<1]))
	    {
		string *sublines = explode(read_file(subfile)||"", "\n") - ({""});
		lines[j+1..j] = sublines;
		j+=sizeof(sublines);
		
	    }
	}
	else if (lines[i][0] != '#')
	    list += expand_path(lines[i]);

    // Jetzt die Gilden-Obs Autoloader einlesen
    if (file = read_file("/var/filed.o"))
    {
	mixed filed_info;
	
	i = strstr(file,"reg ") + 4;
	
	filed_info = restore_value(file[i..strstr(file,"\n",i)]);

#if 0 // Wird bereits vom Gildenraum gemacht
	list += ({ "!Loading Guild-Objects:" });
	list += map(filed_info["gilden"] || ({}), #'[, 0);
#endif

	// Strings die mit '!' anfangen, werden einfach ausgegeben :)
	list += ({ "!Loading Autoloader:" });
	list += map(filed_info["autoloader"] ||({}), #'[,0);
    }

    return list;
}
