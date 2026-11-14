// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/find.inc
// Description:	Find-Befehl (aehnlich wie UNIX-find)
// Author:	Freaky ('94-'95)
// Modified by:	Freaky (07.03.96) OWN, F_*
//		Freaky (07.06.1999) kompletter rewrite.
//
// $Log: find.inc,v $
// Revision 1.6  2008-04-26 18:21:50  gnomi
// Fehler bei der Erkennung des Ende der Dateiliste.
//
// Revision 1.5  2005/03/21 21:33:08  menaures
// -name mit Wildcards. Das alte -name ist jetzt -regex.
//
// Revision 1.4  2003/08/16 22:07:19  gnomi
// static add_actions entfernt.
//
// Revision 1.3  2002/08/07 23:32:23  gnomi
// find testet nun, ob der angegebene Pfad existiert.
//
// Revision 1.2  2002/07/29 00:46:50  gnomi
// Regexp-Fehler besser abfangen.
//
// Revision 1.1  2001/03/16 01:48:26  freaky
// in den Zauberstab eingebaut.
//

// Wenn weniger als FIND_*_EVALS uebrig sind call-out machen.
#define FIND_MIN_EVALS     (100000)
#define FIND_DEFAULT_EVALS (300000)
#define FIND_MAX_EVALS     (390000)
#define FIND_DEFAULT_DELAY (3)
#define F_FILE 1
#define F_DIR  2
#define F_OB   3

private void find_do_file(string file, int size, int date, string cmd,
       	string name, int print, int type)
{
    if (type && (
		(type == F_DIR  && size != -2) ||
		(type == F_FILE && size < 0)   ||
		(type == F_OB   && !find_object(file))
		) )
	return;
    if (print)
	tell_object(OWN,file + "\n");
    if (cmd)
    {
	cmd = process_string(sprintf(cmd,file,size,date));
	if (stringp(cmd) && strlen(cmd))
	    OWN->do_command(sprintf(cmd,file,size,date));
    }
}

private void find_get_next_file(string *path, mixed *dir, int i, int end)
{
    mixed *tmpdir;

    if (dir[i + 1] == -2)
    {
	// Es ist ein Verzeichnis
	if (sizeof(path))
	    tmpdir = get_dir("/" + implode(path,"/") + "/.",7);
	else
	    tmpdir = get_dir("/.",7);
	// Wenn das Verzeichnis leer ist
	if (sizeof(tmpdir))
	{
	    dir = tmpdir;
	    i = 0;
	    path += dir[0..0];
	}
	else
	{
	    // Damit es nicht immer hoch und runter geht...
	    dir[i + 1] = 0;
	    find_get_next_file(&path,&dir,&i,end);
	}
    }
    else if ((i + 3) >= sizeof(dir))
    {
	// Alle Files in diesem Verzeichnis gemacht -> eins hoch
	path = path[0..<2];
	if (sizeof(path) > 1)
	    dir = get_dir("/" + implode(path[0..<2],"/") + "/.",7);
	else
	    dir = get_dir("/.",7);
	i = member(dir,path[<1]);
	if (i < 0)
	{
	    tell_object(OWN,sprintf("File nicht gefunden: /%s\n",
			implode(path,"/")));
	    return;
	}
	// Damit es nicht immer hoch und runter geht...
	dir[i + 1] = 0;
	if (sizeof(path) > end)
	    find_get_next_file(&path,&dir,&i,end);
    }
    else
    {
	i += 3;
	path[<1] = dir[i];
    }
}

static void find_do_find(string *path, int end, string cmd, string name,
		   int print, int type, int eval, int find_delay)
{
    int i;
    mixed *dir;
    
    // tell_object(OWN,sprintf("Path:%O\nEnd:%O\n",path,end));
    if (sizeof(path))
    {
	if (sizeof(path) == 1)
	{
	    dir = get_dir("/.",7);
	}
	else
	{
	    dir = get_dir("/" + implode(path[0..<2],"/") + "/.",7);
	}
	if (!sizeof(dir) || (i = member(dir,path[<1])) == -1)
	{
	    tell_object(OWN,"Find konnte weiterfuehrendes File nicht finden\n");
	    return;
	}
    }
    else
    {
	dir = get_dir("/*",7)[0..2];
    }

    do
    {
	if (get_eval_cost() < eval)
	{
	    call_out("find_do_find",find_delay,path,
		    end,cmd,name,print,type,eval,find_delay);
	    return;
	}
	if (!name || sizeof(regexp(({dir[i]}),name)))
	    find_do_file("/" + implode(path,"/"),dir[i+1],dir[i+2],cmd,name,print,type);
	find_get_next_file(&path,&dir,&i,end);
    }
    while(sizeof(path) > end);
    tell_object(OWN,"Find beendet.\n");
    return;
}

int f_find(string str)
{
    int i, find_delay, type, eval, print;
    string path, *param, cmd, name, *tmp;
    mixed *dir;

    SECURE;
    HELP("find");

    if (!str)
    {
	if (remove_call_out("find_do_find") == -1)
	    FAIL(query_verb() + " <dir> -print -type <f|d|x> -name <pattern> "
		    "-eval <evals> -delay <delay> -exec <command>\n");
	else
	{
	    W("Find abgebrochen.\n");
	    PRINT;
	    return 1;
	}
    }

    param = explode(str," ");
    if (!sizeof(param))
	FAIL("Keine Parameter uebergeben.\n");
    eval = FIND_DEFAULT_EVALS;
    find_delay = FIND_DEFAULT_DELAY;
    for (i = 1; i < sizeof(param); i++)
    {
	if (param[i] == "")
	    continue;
	if (param[i] == "-print")
	    print = 1;
	else
	{
	    if (sizeof(param) < i)
		FAIL("Bei Parameter '" + param[i]+
			"' wurde nichts angegeben.\n");
	    switch (param[i])
	    {
	      case "-regex": 
		name = param[++i];
		{
		    mixed ret;
		    if (catch(ret=regexp(({"dummy"}),name)) || !ret)
		    {
			if(!strlen("^$<>|[]()" & name) && strlen("*?+" & name))
			{
			    FAIL("Fehler in der Regexp.\n"
				 "Vielleicht meintest du '-name "+name+"'?\n");
			}
			FAIL("Fehler in der Regexp.\n");
		    }
		}
		break;
              case "-name":
                name = escape_string(param[++i], ESCAPE_WILDCARD|ESCAPE_EXACT);
                break;
	      case "-exec":
		cmd = implode(param[i+1..]," ");
		i = sizeof(param);
		break;
	      case "-type":
		i++;
		if (param[i] == "f")
		    type = F_FILE;
		else if (param[i] == "d")
		    type = F_DIR;
		else if (param[i] == "x")
		    type = F_OB;
		else
		    FAIL("Type '" + param[i] + "' kenne ich nicht.\n");
		break;
	      case "-delay":
		i++;
		if (sscanf(param[i],"%d",find_delay) != 1)
		    FAIL("Fehler bei Delay.\n");
		break;
	      case "-eval":
		i++;
		if (sscanf(param[i],"%d",eval) != 1)
		    FAIL("Fehler bei Evals.\n");
		break;
	      default:
		FAIL("Parameter '" + param[i] + "' kenne ich nicht.\n");
	    }
	}
    }
    if (!cmd)
	print = 1;
    if (eval < FIND_MIN_EVALS)
	FAIL("Zu wenige Evals angegeben (minimal " + FIND_MIN_EVALS + ")\n");
    if (eval > FIND_MAX_EVALS)
	FAIL("Zu viele Evals angegeben (maximal " + FIND_MAX_EVALS + ")\n");
    if (find_delay < 2)
	find_delay = 2;
    path = OWN->add_path(param[0],0);
    if (file_size(path) != -2)
	FAIL(path + " ist kein Verzeichnis.\n");
    dir = get_dir((path == "/" ? "" : path) + "/.",7);
    if (!sizeof(dir))
	FAIL("Das Verzeichnis " + path + " ist leer.\n");
    
    tmp = explode(path,"/") - ({ "" });
    find_do_find(tmp,sizeof(tmp),cmd,name,print,type,eval,find_delay);
    PRINT;
    return 1;
}
