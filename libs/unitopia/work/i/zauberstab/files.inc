// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/files.inc
// Description: Filehandling des Zauberstabes
// Author:	Freaky (23.12.93)
// Modified:    Sissi (30.6.97) ls bringt zuerst Verzeichnisse und dann Dateien
//
// $Log: files.inc,v $
// Revision 1.27  2014/05/20 21:42:42  gnomi
// 'Bad assignment' korrigiert.
//
// Revision 1.26  2013/11/21 13:01:41  sorcerer
// RTE bei cp_mv beseitigt, wenn Ziel nur eine Pfadkomponente hatte
//
// Revision 1.25  2008/01/16 09:36:51  gnomi
// INPUT_PROMPT verwenden.
//
// Revision 1.24  2007/12/05 11:03:08  gnomi
// Grep: Option -p fuer PCRE-Ausdruecke eingebaut.
//
// Revision 1.23  2007/05/26 22:52:22  gnomi
// cp/mv: Auch 'Y[es]' akzeptieren.
//
// Revision 1.22  2005/10/20 19:33:57  gnomi
// Indexing past string end.
//
// Revision 1.21  2004/08/21 23:08:01  gnomi
// grep: Falsche regexps abfangen.
//
// Revision 1.20  2004/07/04 00:05:40  gnomi
// cp/mv: Ja/Nein/Alle-Abfrage korrigiert.
//
// Revision 1.19  2004/02/19 21:40:13  gnomi
// Typo.
//
// Revision 1.18  2003/08/16 22:07:19  gnomi
// static add_actions entfernt.
//
// Revision 1.17  2003/07/16 02:31:35  gnomi
// Kosmetik.
//
// Revision 1.16  2003/02/26 04:01:35  gnomi
// Schoenheitskorrektur bei cp_mv.
//
// Revision 1.15  2002/11/09 02:48:08  gnomi
// grep: Fuer zgrep erweitert.
// cp/mv: 2 Optionen, um Abfragen auszuschalten und Ueberschreiben zuzulassen.
//
// Revision 1.14  2002/08/07 23:32:41  gnomi
// grep -n zeigt die Zeilennumern an.
//
// Revision 1.13  2002/07/27 23:59:17  gnomi
// grep: Gegen 0 als Rueckgabewert von read_file abgesichert.
//
// Revision 1.12  2002/07/01 23:50:08  gnomi
// Abfrage der UIDs beim 'ls' korrigiert.
//
// Revision 1.11  2001/08/25 13:32:13  freaky
// Evals angepasst
//
// Revision 1.10  2001/06/05 16:47:45  gnomi
// cp_mv_ja_nein (oder so aehnlich): Anstatt Rekursion eine normale Schleife
// nehmen.
//
// Revision 1.9  2001/04/26 22:50:02  freaky
// die cvs-Verzeichnisse wieder anzeigen, da auch User cvs-Verzeichnisse
// anlegen koennen.
//
// Revision 1.8  2001/04/03 01:43:17  gnomi
// cp/mv-ja/nein-Abfrage: Bessere Formatierung.
//
// Revision 1.7  2001/03/03 18:56:50  sissi
// ls listet die unix - seitigen, fuers mud irrelevanten CVS Verzeichnisse
// nicht mehr mit auf.
//
// Revision 1.6  2001/02/20 19:43:39  gnomi
// Beim ls -l eine eval-cost-Abfrage reingebaut.
//
// Revision 1.5  2001/02/04 22:41:40  freaky
// grep nur noch fuer Files < 500 kB zulassen.
//
// Revision 1.4  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strong_types

private mixed *expand_wildcards(string str) {
    string *wild_files, *files, *ret;
    string path, *com_path, last;
    int i;

    if (str)
	wild_files=explode(str," ")-({""});
    else
	wild_files=({""});
    ret=({});
    for (i=0; i<sizeof(wild_files); i++) {
	com_path=OWN->compose_path(wild_files[i],LAST);
	if (sizeof(com_path) &&
		(member(last=com_path[<1],'*')>=0 || member(last,'?')>=0)) {
	    if (sizeof(com_path)>1)
		path="/"+implode(com_path[0..<2],"/")+"/";
	    else
		path="/";

	    if ((files=get_dir(path+last)) && sizeof(files-=({".",".."})))
		ret+=map(files,lambda(({'x}),({#'+,path,'x})));
	    else
		ret+=({path+last});
	    }
	else
	    ret+=({"/"+implode(com_path,"/")});
	}

    return ret;
}

int f_tail(string str) {
    SECURE;
    HELP("tail");
    if (!str)
	FAIL("tail <file>\n");
    tail(ADD_PATH(str,MSG));
    return 1;
}

int f_cat(string str) {
    SECURE;
    HELP("cat");
    if (!str)
	FAIL("cat <file>\n");
    cat(ADD_PATH(str,MSG));
    return 1;
}

int f_more(string str) {
    string ret;

    SECURE;
    HELP("more");
    if (!str)
	FAIL("more <file>\n");
    ret=OWN->more(ADD_PATH(str,MSG));
    if (ret)
	FAIL(M_ERR(ret));
    return 1;
}

int f_ed(string str) {
    SECURE;
    HELP("ed");
    if (!str) {
	/* request for file with last error */
	mixed *error;
	error=get_error_file(OWN->query_real_name());
	if (!error || error[3]) {
	    write("Kein Fehler.\n");
	    return 1;
	    }
	str=error[0];
	write(str+" Zeile "+error[1]+": "+error[2]+"\n");
	}
    else
	str=ADD_PATH(str);

    if (file_size(str)!=-2)
	own_ed(str);
    else
	write("Ein Verzeichnis darf man nicht Editieren!\n");
    return 1;
}

int f_mkdir(string str) {
    string *dirs;
    int i, err;

    SECURE;
    HELP("mkdir");
    if (!str)
	FAIL("mkdir <pfad> {<pfad>}\n");
    dirs=expand_wildcards(str);
    for (i=0; i<sizeof(dirs); i++)
	if (!mkdir(dirs[i])) {
	    W("Verzeichnis '"+dirs[i]+"' konnte nicht angelegt werden.\n");
	    err=1;
	    }
    if (!err)
	W("Ok.\n");
    PRINT;
    return 1;
}

int f_rmdir(string str) {
    string *dirs;
    int i, err;

    SECURE;
    HELP("rmdir");
    if (!str)
	FAIL("rmdir <pfad> {<pfad>}\n");
    dirs=expand_wildcards(str);
    for (i=0; i<sizeof(dirs); i++)
	if (!rmdir(dirs[i])) {
	    if (file_size(dirs[i])!=-2)
		W("'"+dirs[i]+"' ist kein Verzeichnis.\n");
	    else
		W("Verzeichnis '"+dirs[i]+"' konnte nicht geloescht werden.\n");
	    err=1;
	    }
    if (!err)
	W("Ok.\n");
    PRINT;
    return 1;
}

/*
 * get_path() zerlegt den string str so in 2 Teile, damit nachher leicht ein
 * get_dir() gemacht werden kann.
 * get_path[0] ist der Pfad
 * get_path[1] ist das File-Wildcard, nach dem die Files ausgesucht werden
 */
private string *get_path(string str) {
    string *strs, tmp;
    if (!str || str=="") {
	tmp=ADD_PATH(0);
	return ({tmp=="/"?"":tmp, "."});
	}

    strs=OWN->compose_path(str,LAST);
    if (!sizeof(strs))
	return ({"", "."});

    if (file_size(tmp="/"+implode(strs,"/"))==-2)
	return ({tmp,"."});
    if (strs[<1]=="*")
	strs[<1]=".";
    if (sizeof(strs)<2)
	return ({"",strs[0]});
    return ({"/"+implode(strs[0..<2],"/"),strs[<1]});
}

/*
 * get_wildcard_files liefert ein Array mit den Files zurueck, die bei
 * get_dir(path_match[0]+"/"+path_match[1],i) zurueckgegeben wird,
 * und gegebenfalls eine Fehlermeldung (dann wird 0 returned)
 */
private mixed *get_wildcard_files(string dir, string wild_file, int i) {
    string *fils;

    fils=get_dir(dir+"/"+wild_file,i);
    if (!fils) {
	if (file_size(dir)==-2)
	    notify_fail("Das Verzeichnis "+dir+" darfst du nicht lesen.\n");
	else
	    notify_fail("Das Verzeichnis "+dir+" gibt es nicht.\n");
	return 0;
	}
    if (!sizeof(fils)) {
	if (wild_file==".")
	   notify_fail("Das Verzeichnis "+dir+" ist leer.\n");
	else
	   notify_fail("Es gibt kein solches File oder Verzeichnis.\n");
	return 0;
	}
    return fils;
}

private string ls_time(int date)
{
    string ct;

    ct = ctime(date);
    if(time()-date > 15552000)
       return ct[4..10]+ct[19..];
    else
        return ct[4..15];
}

private string long_ls(string path, string file, int size, int date)
{
    string ret, *uid, gid;
    int is_dir, is_read, is_write, is_exec;
    mixed tmp;

    if(get_eval_cost()<100000)
	return sprintf("???? %-10s %-10s %10d %s %s\n",
	    "?","?",(size<0)?0:size, ls_time(date), file);

    if (size == -2)
    {
	path += file + "/Dummy";
	file += "/";
	is_dir = 1;
	size = 0;
    }
    else
    {
    	path += file;
	if (is_exec = path[<2..] == ".c" && find_object(path) && 1)
	    file += "*";
    }

    is_read = MASTER_OB->valid_read(path,geteuid(),"read_file",TO);
    is_write = MASTER_OB->valid_write(path,geteuid(),"write_test",TO);
    if (path[<2..] == ".c")
    	path = path[0..<3];
    tmp = MASTER_OB->get_load_uid(path[1..]);
    if(pointerp(tmp))
	tmp = tmp[1] || tmp[0];
    uid = explode( tmp || "nobody", ":");
    if (sizeof(uid) < 2)
	if (strstr(path,"/w/"))
	    gid = "mudlib";
	else
	    gid = "privat";
    else
	gid = uid[0];

    return sprintf("%c%c%c%c %-10s %-10s %10d %s %s\n",
    	is_dir ? 'd':'-',
	is_read? 'r':'-',
	is_write?'w':'-',
	is_exec ?'x':'-',
	capitalize(uid[<1]),
	gid,
	size,
	ls_time(date),
	file);
}

private int is_loaded(string path, string file)
{
    if (file[<4..] == ".udl")
	file = file[0..<5];
    if (find_object(path + file))
	return 1;
}

int f_ls(string str)
{
    string wie, *path_match, out, outsub, outfiles, path;
    mixed *fils;
    int i, j;
    object ob;

    SECURE;
    HELP("ls");
    if (str && str[0]=='-')
    {
	if (sscanf(str,"-%s %s",wie,str)!=2)
	{
	    wie=str[1..];
	    str=0;
	}
	if (strlen(wie)!=1 || member("lsdkL",wie[0])<0)
	    FAIL("Unbekannter Parameter.\n");
    }
    else
    {
	/* Hier benutze ich eine schnellere Methode, da dies wohl der
	 * haeufigste Anwendungsfall ist
	 */
	path_match=get_path(str);
	fils=get_wildcard_files(path_match[0],path_match[1],3);
	if (!fils)
	    return 0;
	outsub=outfiles="";
	path=path_match[0]+"/";
	for (i=0; i<sizeof(fils); i+=2)
       	{
	    // if (fils[i] != "CVS")
	    if (fils[i+1] == -2)
	        outsub+=fils[i]+"/\n";
	    else if (is_loaded(path,fils[i]))
		outfiles+=fils[i]+"*\n";
	    else
		outfiles+=fils[i]+"\n";
	}
	W(sprintf("%-79#s\n",outsub+outfiles));
	PRINT;
	return 1;
    }

    path_match=get_path(str);
    fils=get_wildcard_files(path_match[0],path_match[1],7);
    if(!fils)
	return 0;
    path=path_match[0]+"/";
    out="";
    for (j=0; j<2; j++)
      for (i=0; i<sizeof(fils); i+=3)
        if (/*fils[i]!="CVS" &&*/
	    ((!j && fils[i+1] == -2) || (j && fils[i+1] != -2)))
	{
	  switch (wie)
	  {
	    case "l": out+= long_ls(path,fils[i],fils[i+1],fils[i+2]);
		      break;
	    case "d": out+=shorttimestr(fils[i+2])+"  "+fils[i];
		      break;
	    case "s": out+=right(fils[i+1],10)+" "+fils[i];
		      break;
	    case "k": out+=right((fils[i+1]+1023)/1024,3)+" "+fils[i];
		      break;
	    case "L": if (fils[i][<2..]==".c")
			out+=sprintf("%-10s %-10s %-10s %-10s %s",
			to_string(MASTER_OB->get_load_uid(path[1..]+fils[i][0..<3])),
			to_string(MASTER_OB->get_clone_uid(path[1..]+fils[i][0..<3])),
			(ob=find_object(path+fils[i]))?to_string(getuid(ob)):"0",
			ob?to_string(geteuid(ob)):"0",
			fils[i]);
		      else
			out+="                                            "+fils[i];
		      break;
	  }
	  if (wie != "l")
	  {
	    if (fils[i+1] == -2)
		out+="/\n";
	    else if (is_loaded(path,fils[i]))
		out+="*\n";
	    else
		out+="\n";
	  }
	}
    W(sprintf("%-79#s\n",out));
    PRINT;
    return 1;
}

static void loesche_ja_oder_nein(string str, string *files) {
    int ask;

    if (str) {
	switch(lower_case(str)) {
	  case "j":
	  case "ja":
	  case "y":
	  case "yes":
	    if (!rm(files[0]))
		write("Hat nicht geklappt.\n");
	    files=files[1..];
	    break;
	  case "n":
	  case "nein":
	    files=files[1..];
	    break;
	  case "e":
	  case "ende":
	    return;
	  default:
	    ask=1;
	  }
	}
    while (sizeof(files) && (file_size(files[0])<0)) {
	write("'"+files[0]+"' ist kein File.\n");
	files=files[1..];
	}
    if (sizeof(files))
	input_to("loesche_ja_oder_nein",INPUT_PROMPT,
	    files[0]+"? "+(ask?"ja, nein, ende? ":""),
	    files);
}

int f_rm(string str) {
    string *files;

    SECURE;
    HELP("rm");
    files=expand_wildcards(str);
    loesche_ja_oder_nein(0,files);
    return 1;
}

static void cp_mv_ja_oder_nein(string str, string *files, string dest,
				int dir, int copy_true, int dontask, int force)
{
    int ask, siz;
    string out_file;
    int firstround=dontask;	// Eine Runde benoetigt, um alle Infos
				// auszugeben.

    do
    {
        if (str || (dontask && !firstround))
        {
	    switch(dontask?"alle":lower_case(str))
	    {
	      case "j":
	      case "ja":
	      case "y":
	      case "yes":
	      case "a":
	      case "alle":
	        if (dir)
		    out_file=dest+"/"+explode(files[0],"/")[<1];
	        else
		    out_file=dest;
	        if (!force && file_size(out_file) >= 0)
		    write("File existiert bereits.\n");
	        else
	        {
		    if (copy_true)
		    {
		        if (copy_file(files[0],out_file))
			    write("Hat nicht geklappt.\n");
		        else
			    if (dontask || str[0]=='a')
			        write("Ok.\n");
		    }
		    else
		    {
                        if (!strstr(out_file,files[0]+"/"))
                            write("Zielverzeichnis ist im Quellverzeichnis.\n");
		        else if (rename(files[0],out_file))
			    write("Hat nicht geklappt.\n");
		        else if (dontask || str[0]=='a')
			    write("Ok.\n");
		    }
	        }
	        files=files[1..];
	        break;
	      case "n":
	      case "nein":
	        files=files[1..];
	        break;
	      case "e":
	      case "ende":
	        return;
	      default:
	        ask=1;
            }
        }
	else
	    firstround=0;
        while (sizeof(files) && ((siz=file_size(files[0]))==-1 ||
			    copy_true && (siz==-2)))
        {
	    if (copy_true)
	        write("'"+files[0]+"' ist kein File.\n");
	    else
	        write("'"+files[0]+"' ist kein File oder Verzeichnis.\n");
	    files=files[1..];
        }
        if (sizeof(files))
        {
	    printf("%-=1.75s",files[0]+" -> " + dest +
		    (dir?"/"+explode(files[0],"/")[<1]:"") + "? ");
	    if (!dontask && (!str || (str!="a" && str!="alle") || copy_true))
	        input_to("cp_mv_ja_oder_nein",INPUT_PROMPT,
		    ask?("ja, nein, "+(copy_true?"":"alle, ")+"ende? "):"",
		    files,dest,dir,copy_true,dontask,force);
        }
    }while(sizeof(files) && (dontask || (str && (str=="a" || str=="alle") && !copy_true)));
}

private int cp_mv(string str, int copy_true) {
    string *fils;
    int force, dontask;

    str = space(str||"");
    while(sizeof(str) && str[0]=='-')
    {
	if(strlen(str)<2 || str[1]==' ')
	{
	    str=str[2..<1];
	    continue;
	}
	switch(str[1])
	{
	    case 'y':
		dontask = 1;
		break;
	    case 'f':
		force = 1;
		break;
	    default:
		FAIL("Unbekannte Option: -"+str[1]+"!\n");
	}
	str[1..1]="";
    }
    
    fils=expand_wildcards(str);
    if (sizeof(fils)<2)
	FAIL(query_verb()+" <in_file> <out_file>\n");
    if (sizeof(fils)>2 && file_size(fils[<1])!=-2)
	FAIL(query_verb()+": Bei mehreren Files muss das Ziel ein "
				"Verzeichnis sein.\n");
    if (strrstr(fils[<1],"/") &&
        file_size(implode(explode(fils[<1],"/")[0..<2],"/"))!=-2)
	FAIL("Das Output-Verzeichnis existiert nicht.\n");
    cp_mv_ja_oder_nein(0,fils[0..<2],(fils[<1]=="/"?"":fils[<1]),
		file_size(fils[<1])==-2,copy_true,dontask,force);
    return 1;
}

int f_cp(string str) {
    SECURE;
    HELP("cp");
    return cp_mv(str,1);
}

int f_mv(string str) {
    SECURE;
    HELP("mv");
    return cp_mv(str,0);
}

// Der 2. Parameter existiert, wenn es vom zgrep aufgerufen wird.
int f_grep(string str, string fil) {
    string *g, *h, was;
    int i, ignore_lower_case, all_other, linenum, size, reflags;
    mapping opt;

    SECURE;

    if(!fil)
    {
	HELP("grep");
    }

    if (!str)
	FAIL(query_verb()+" [-i] [-v] [-n] [-p] <regular-expression> "+
	    (fil?"<objekt>\n":"<file>\n"));
    opt=getopt(str,(["i":0,"v":0,"n":0,"p":0]),GO_FAILS);
    if (!opt)
	return 0;
    if (sizeof(opt["args"])!=1)
	FAIL(query_verb()+" [-i] [-v] [-n] <regular-expression> "+
	    (fil?"<objekt>\n":"<file>\n"));

    if(!fil)
    {
	g=explode(opt["args"][0]," ");
	if (sizeof(g) < 2)
	    FAIL(query_verb()+" [-i] [-v] [-n] <regular-expression> <file>\n");
	fil=g[<1];
	was=implode(g[0..<2]," ");
    }
    else
	was = opt["args"][0];

    ignore_lower_case = opt["i"];
    all_other = opt["v"];
    linenum = opt["n"];
    
    if(opt["p"])
    {
	reflags = RE_PCRE;
	if(ignore_lower_case)
	{
	    reflags |= RE_CASELESS;
	    ignore_lower_case = 0;
	}
    }
    else
	reflags = RE_TRADITIONAL;
    
    if (ignore_lower_case)
        was=lower_case(was);

    if (catch(regexp(({"dummy"}),was, reflags)))
    {
	was = regreplace(was, "([()+*.])", "\\\\\\1", 1);
	FAIL("Fehler in der regexp.\nMeintest Du vielleicht '"+was+"'?\n");
    }

    fil=ADD_PATH(fil,MSG);
    size = file_size(fil);
    // Wenn groesser 500kB nicht scannen
    if (size > 500000)
	FAIL("Das File ist zu gross (groesser 500kB)\n");
    if (size > 0) {
	g=({});
	do {
	    string *regfiltered;
	    string text = read_file(fil,i+1,400)||"";
	    string *exptext;

	    h = explode(text,"\n");
	    
            if (ignore_lower_case)
	        exptext=explode(lower_case(text),"\n");
            else
		exptext = h;
		
	    regfiltered = regexp(exptext,was,reflags);

	    if(linenum)
	    {
		int j;
	
		// So, jetzt muessen wir herausfinden, welche Zeilen
		// das waren...
		for(int k=0;k<sizeof(regfiltered);k++)
		{
		    j+=member(exptext[j..<1],regfiltered[k]);
		    regfiltered[k]=(i+1+j)+": "+h[j];
		    j++;
		}
		if(all_other)
		    for(j=0;j<sizeof(h);j++)
			exptext[j] = (i+1+j)+": "+h[j];
	    }
	    
	    if (all_other)
		g+=exptext-regfiltered;
	    else
		g+=regfiltered;
	    i+=400;
	    } while (sizeof(h)==401);
	if (sizeof(g)) {
	    WLN(implode(g,"\n"));
	    W("In "+sizeof(g)+" Zeilen gefunden.\n");
	    }
	}
    PRINT;
    return 1;
}

int z_sort (string str)
{
    string *s, t;

    SECURE;
    HELP("zsort");
    if (!str)
	FAIL("zsort <file>\n");
    str = ADD_PATH(str,MSG);
    if (!t = read_file(str))
        FAIL("Datei nicht gefunden.\n");
    s = explode(t,"\n");
    s = sort_array(s, #'>);
    t = implode(s,"\n");
    rm(str+".sorted");
    write_file(str + ".sorted",t);
    write("Datei " + str + " sortiert nach " + str + ".sorted.\n");
    return 1;
}

int f_xed(string str)
{
    SECURE;
    HELP("xed");
    return xeditor::edit_command(str);
}
