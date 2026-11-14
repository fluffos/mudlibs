// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zmarker.inc
// Description: Objekthandling des Zauberstabes
// Author:	Freaky (23.12.93)
// Modified by: Garthan (30.12.93) z_etup, z_zerstoere, z_erneuerer (msgs)
//		Freaky  (13.05.97) zerneuere: laden besser gemacht
//
// $Log: zmarker.inc,v $
// Revision 1.70  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.69  2014/03/13 20:01:25  myonara
// Suchparamter fuer zteleport.
//
// Revision 1.68  2014/03/13 19:03:09  gnomi
// Ergebnisse des Veraltet-Tests cachen, um bei Mehrfachinherits Evals zu
// sparen.
//
// Revision 1.67  2013-03-16 15:51:26  gnomi
// Mit 'zm' kann man eine Markierung auch loeschen.
//
// Revision 1.66  2012-11-16 17:53:34  gnomi
// zfl freigegeben. Eval-Anzeige beim zerschaffen.
//
// Revision 1.65  2010-08-05 19:08:27  sorcerer
// Fehler bei geloeschten Files von noch bestehenden Objekten abgefangen
//
// Revision 1.64  2010-07-28 20:21:39  sorcerer
// z_erschaffe akzeptiert auch Objektstrings
//
// Revision 1.63  2010-01-22 18:31:41  sorcerer
// return in z_erneuere_filter muss int liefern
//
// Revision 1.62  2009-06-17 07:52:08  gnomi
// Loeschen von Variablen mit 'zvar x=' erlauben.
//
// Revision 1.61  2008-05-19 14:27:55  gnomi
// clone/destruct_msg: $Der()/$Ein() ohne Parameter sind jetzt
// TP und nicht der Zauberstab.
//
// Revision 1.60  2008-04-26 18:22:56  gnomi
// Call from destructed object.
//
// Revision 1.59  2008/01/21 14:16:43  gnomi
// Call from destructed object beim Zernen.
// zdbg via show_func_result.
//
// Revision 1.58  2007/12/05 11:28:48  gnomi
// Zerstoerung des Inhabers nicht zulassen.
//
// Revision 1.57  2007/12/05 11:05:30  gnomi
// Eigene Zerstoerung akzeptieren, eigene Erneuerung ablehnen.
//
// Revision 1.56  2007/08/30 20:31:51  gnomi
// zcout aufgebohrt.
// zvl, zfl und zfunktion liefern mehr Informationen.
//
// Revision 1.55  2007/08/20 18:19:31  gnomi
// zers: ggf. not_moved_reason anzeigen.
//
// Revision 1.54  2007/08/09 22:24:19  gnomi
// Typo in Doku.
//
// Revision 1.53  2007/05/26 22:57:16  gnomi
// Kein RTE mehr, wenn man den Zauberstab selbst zerstoert.
// Ausserdem Indexing past string end.
//
// Revision 1.52  2006/08/03 09:51:15  gnomi
// zern: Sicherstellen, dass finish_renewal auf jeden Fall aufgerufen wird.
//
// Revision 1.51  2005/07/22 10:29:41  menaures
// zmore auch Blueprints von Mapraeumen finden lassen
//
// Revision 1.50  2005/05/06 22:50:05  gnomi
// zgehzu: MEldung bei Urlaubsgoettern.
//
// Revision 1.49  2005/04/10 01:28:04  gnomi
// query_file_name eingefuehrt.
//
// Revision 1.48  2005/02/06 03:27:45  gnomi
// zerschaffe um ein paar Optionen erweitert.
//
// Revision 1.47  2004/11/27 21:26:39  gnomi
// zco -n eingefuehrt.
//
// Revision 1.46  2004/09/17 08:39:09  gnomi
// zlpc verwendet jetzt den mini_ed.
//
// Revision 1.45  2004/08/21 23:07:30  gnomi
// Mit 'zg' kommt man nur in Container.
//
// Revision 1.44  2004/02/19 21:40:36  gnomi
// Typo.
//
// Revision 1.43  2003/11/06 23:11:36  gnomi
// zern: -t wird automatisch genommen, wenn es moeglich ist.
//
// Revision 1.42  2003/09/30 22:45:16  gnomi
// Ermoeglicht, dass zlpc auch von tue aus genutzt werden kann.
//
// Revision 1.41  2003/08/16 22:07:19  gnomi
// static add_actions entfernt.
//
// Revision 1.40  2003/05/28 01:03:29  gnomi
// MAY_WRITE statt MASTER->valid_write.
//
// Revision 1.39  2003/03/02 14:06:09  freaky
// zvl eingebaut
//
// Revision 1.38  2003/01/17 01:50:00  gnomi
// Gnauere Fehlermeldung bei zcall.
//
// Revision 1.37  2002/11/09 02:44:15  gnomi
// zzerstoere: Umgestellt auf getopt. Zerstoert keine Raeume mit Spielern drin.
//    Zusaetzliche Option -f, wie beim Zerneuern.
// zzerstoere/zerneuere: Ohne Option nicht im /apps erlaubt.
// zgrep: Eingebaut. Wie grep, nur mit Objektstring.
// zg: Fehlermeldung bei 'zg -', wenn man noch nirgends vorher war.
// zerneuern: Bei zern -aT wurden die Schreibrechte nicht korrekt ueberprueft,
//    da das erste Zeichen '/' des Dateinamens verschluckt wurde.
// zinherit: Auf getopt umgestellt. Virtuelle Inherits kann man sich markieren
//    lassen.
// zlicht: Zeigt auch query_daylight (Tag/Nacht) an.
//
// Revision 1.36  2002/10/31 23:02:52  gnomi
// zfu: Zeigt auch an, wenn Funktionen geshadowt werden.
//
// Revision 1.35  2002/10/29 01:51:52  gnomi
// zerschaffe: Bugfix bei Behandlung des getopt-Ergebnisses, wenn zwar
// Optionen aber kein Dateiname angegeben wurde.
//
// Revision 1.34  2002/10/28 03:04:13  gnomi
// zlpc: Fehlermeldung beim Laden des Files ausgeben.
//
// Revision 1.33  2002/10/19 00:39:58  gnomi
// zlicht: wrap nutzen.
//
// Revision 1.32  2002/08/31 01:15:10  gnomi
// zern -as: Das angegebene Objekt wird auf jeden Fall gezernt.
//
// Revision 1.31  2002/07/08 17:17:23  gnomi
// zlicht erweitert.
//
// Revision 1.30  2002/07/03 16:12:55  sissi
// Pulami: zlicht fuers neue Lichtsystem erweitert.
//
// Revision 1.29  2002/06/24 02:20:53  gnomi
// Typo.
//
// Revision 1.28  2002/06/19 23:23:24  gnomi
// zern: Beachtet nun auch Map-Raeume.
//
// Revision 1.27  2002/03/09 04:07:11  gnomi
// zern: Test auf Spieler im Raum eingebaut.
//
// Revision 1.26  2002/03/09 02:41:35  gnomi
// zers -l
//
// Revision 1.25  2002/02/28 00:45:28  gnomi
// Test auf Schreibrechte besser mit Dateiendung durchfuehren...
//
// Revision 1.24  2002/02/24 03:16:33  gnomi
// 'zerneure'-Befehl neu strukturiert und die Option '-t' hinzugefuegt.
//
// Revision 1.23  2002/01/11 00:24:34  gnomi
// HELP_NO_VERB eingefuehrt, fuer Befehle, bei denen query_verb verschieden
// sein kann.
//
// Revision 1.22  2001/09/02 11:52:43  freaky
// an ldmud-3.2.9-dev.332 angepasst.
//
// Revision 1.21  2001/07/22 23:37:01  gnomi
// Anstatt MOVE_FORCE wird force_move genutzt.
//
// Revision 1.20  2001/06/29 14:19:15  freaky
// zlpc laesst jetzt wieder lokale Variablen zu.
//
// Revision 1.19  2001/06/28 22:25:36  freaky
// variablen koennen nur noch Objekte mit korrekter UID abgefragt werden.
// zlpc bekommt jetzt eine 'echte' UID.
//
// Revision 1.18  2001/06/24 00:33:40  gnomi
// Beim Zernen MOVE_FORCE nutzen.
//
// Revision 1.17  2001/05/14 23:08:25  gnomi
// zmore/zfe: UDL-Dateien erkennen und anzeigen.
//
// Revision 1.16  2001/05/09 17:27:31  gnomi
// zmsg-Text nur im priv zwischenspeichern, wenn das priv existiert.
//
// Revision 1.15  2001/04/28 03:33:58  gnomi
// zmsg: den Mini-ED nutzen.
//
// Revision 1.14  2001/04/17 22:37:04  gnomi
// seteuid ueber eine Dummy-Variable (-> __INIT) setzen,
// damit es nirgends kracht.
//
// Revision 1.13  2001/04/17 20:18:37  gnomi
// EUID bei zlpc setzen.
//
// Revision 1.12  2001/03/24 00:30:17  gnomi
// Auch beim zerstoeren eines unsichtbaren Gottes keine Meldung.
//
// Revision 1.11  2001/03/24 00:23:17  gnomi
// Keine Erschaffensmeldung an den Raum, wenn der Gott unsichtbar ist.
//
// Revision 1.10  2001/03/21 01:12:50  gnomi
// set_light(0) -> environment(OWN)->query_light()
//
// Revision 1.9  2001/03/08 19:02:44  gnomi
// Bei zern -a, -A, -as, -As den load_name auch beachten, da dieser bei
// VC/Map-Raeumen mit einem Blueprint, welches replace_program nutzt, nicht
// beachtet wird.
//
// Revision 1.8  2001/02/11 02:24:19  sissi
// Anpassung an neues Levelsystem.
//
// Revision 1.7  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#include <inherit_list.h>

#pragma strong_types
#pragma verbose_errors

int z_markiere(string str)
{
    object ob;
    int nr, i;
    string obst;

    SECURE;
    HELP("zmarkiere");
    if (!str)
    {
	string *ms;
	object *m;

	m=OWN->query_marks();
	ms=OWN->query_marks(1);
	for (i=0; i<sizeof(m); i++)
	{
	    W(MARK_ICON+i+" : ");
	    if (m[i])
		W(OFN(m[i]));
	    else if (ms[i])
		W("("+ms[i]+")");
	    else
		W("0");
	    W("\n");
	}
	PRINT;
	return 1;
    }

    if (sscanf(str,MARK_ICON+"%d %s",nr,obst)!=2)
	obst=str;

    if(obst!="nichts")
    {
        ob=SO(obst);
        if (!ob)
	    return 0;
    }

    OWN->set_mark(nr,ob);
    if(ob)
        WLN("Markierung "+MARK_ICON+nr+": "+OFN(ob));
    else
        WLN("Markierung "+MARK_ICON+nr+" geloescht.");
    PRINT;
    return 1;
}

int z_zerstoere(string str)
{
    string obname, tmp;
    mapping opt;
    object what;

    SECURE;
    HELP("zzerstoere");

    if (str)
    {
	opt = getopt(str,(["d":0, "f":0]),GO_FAILS);
	if (!opt)
	    return 0;
    }
    else
    	opt = ([]);

    if (opt["args"])
	obname = implode(opt["args"]," ");
    if(!(what = SOT(obname)))
	return 0;

    if (query_once_interactive(what) && what != OWN)
    {
	write("Spieler darf man nicht zerstoeren.\n");
	return 1;
    }

    if (!strstr(object_name(what),"/apps/") && !adminp(OWN))
    {
	write("Objekte aus dem /apps solltest Du nicht zerstoeren.\n");
	return 1;
    }

    if (!opt["f"] && sizeof(filter(all_inventory(what),
	(: playerp($1) && !wizp($1) && !testplayerp($1) :))))
    {
	WLN("-"*79);
	W("ACHTUNG: Zerstoerung wurde nicht durchgefuehrt!\n\n");
	W(wrap("Grund: Es befindet sich noch mindestens ein Spieler "
	    "(kein Gott oder Testie) in diesem Raum. Diesen Test kannst Du "
	    "mit -f ausschalten."));
	WLN("-"*79);
	PRINT;
	return 1;
    }
    
    if(!opt["f"] && playerp(what)) // what == OWN, wegen oben
    {
	WLN("-"*79);
	W("ACHTUNG: Zerstoerung wurde nicht durchgefuehrt!\n\n");
	W(wrap("Grund: Es soll ein Spieler zerstoert werden. "
	    "Diese Ueberpruefung kannst Du mit -f ausschalten."));
	WLN("-"*79);
	PRINT;
	return 1;
    }

    if(what->query_name() && !IS_INVIS(OWN)
       && (tmp=closure_to_string(c_destruct_msg,({what}))) 
       && tmp != "" && (present(what, OWN) || present(what, ENV(OWN))))
	    OWN->send_message(MT_LOOK,MA_UNKNOWN,wrap(tmp));

    obname=OFN(what);
    if(what == this_object())
	W("Okay, zerstoere mich selbst. Auf Wiedersehen.\n");
    if (opt["d"])
    {
	W("Zerstoere Objekt nur mit destruct()\n");
	if(what == this_object())
	    PRINT;
	    
	destruct(what);
    }
    else
    {
	if(what == this_object())
	    PRINT;
	    
	what->remove();
	if (what)
	{
	    W("Objekt "+obname+" ist noch vorhanden! Versuche destruct()\n");
	    if(what == this_object())
		PRINT;
	    destruct(what);
	}
    }
    if (what) 
	W("FEHLER! Objekt "+obname+" noch vorhanden!!!\n");
    else 
	WLN("Zerstoert : "+obname);
    if (this_object())
	PRINT;
    return 1;
}

int z_call(string str)
{
    string wer, fun, arg, fehl, tmp, var;
    int i, owner_level, victim_level, *usg1, *usg2, eval, res;
    object ob;
    mixed *a, got;
    mapping opt;

    SECURE;
    HELP("zcall");
    fehl = query_verb() +
	" [-e] [-s] [<Variable>=][<Objektstring>->]<Funktion>([<Argument>])\n";
    if (!str)
	FAIL(fehl);
    i = member(str,'(');
    if (i < 0)
	FAIL(fehl);
    opt = getopt(str[0..i], (["e":0, "s":0]), GO_FAILS);
    if (!opt)
	return 0;
    if (sizeof(opt["args"]) != 1)
	FAIL(fehl);
    str = opt["args"][0] + str[(i + 1)..];
    if (sscanf(str,"%s=%s",var,tmp) != 2 || strstr(var,"\"") != -1 ||
	strstr(var,"->") != -1 || strstr(var,"(") != -1)
    {
	tmp = str;
	var = "Got";
    }

    if (sscanf(tmp,"%s->%s(%s",wer,fun,arg) < 3 || strstr(wer,"\"") != -1 ||
		strstr(wer,"(") != -1)
	if (sscanf(tmp,"%s(%s",fun,arg) == 2 && strstr(fun,"\"") == -1)
	    wer = MARK_ICON;
	else
	    FAIL(fehl);
   
    if (sizeof(arg) && arg[<1] == ';')		// ; am Ende weg *seufz*
	arg = arg[0..<2];

    if (!sizeof(arg) || arg[<1] != ')')
	FAIL(fehl + "    ( Klammer-zu vergessen? )\n");

    ob = SO(wer);
    if (!ob)
	return 0;

    if ((ob != OWN) && !adminp (OWN))
    {
	owner_level = query_real_player_level(OWN);
	victim_level = query_real_player_level(ob);
	if (owner_level < LVL_WIZ)
	{
	    W("Du nicht!\n");
	    PRINT;
	    return 1;
	}
	if ((victim_level >= owner_level) && (fun[0..5] != "query_"))
	{
	    W("Du kannst doch nicht in gleich- oder hoeherrangigen Goettern herumpfuschen!\n");
	    PRINT;
	    return 1;
	}
    }
    a = str2mixed(arg[0..<2]);
    if (!a)
	return 0;
    usg1 = rusage();
    eval = get_eval_cost();
    res = apply(#'call_resolved,&got,ob,fun,a);
    usg2 = rusage();
    eval -= get_eval_cost();
    vars[var] = got;
    
    if(!this_object()) // Bye bye.
	return 1;
    
    if (!opt["s"])
    {
        if(!res)
	    W(sprintf("%s=0 (Funktion existiert nicht oder ist privat bzw. static.)\n",var));
	else
	    switch(params["print"])
	    {
	      case "printf":
		W(sprintf("%s=%O\n",var,got));
		break;
	      case "none":
		WLN(var + "=" + mixed2str(got));
		break;
	      default:
		W(wrap(var + "=" + mixed2str(got),79));
	    }
    }
    else
	W("Returnwert in '" + var + "' gespeichert.\n");
    if (opt["e"])
	WLN("Eval-Cost: " + eval +
		"   Time: " + (usg2[0] + usg2[1] - usg1[0] - usg1[1]) +
		"   User-Time: " + (usg2[0] - usg1[0]) +
		"   Sys-Time: " + (usg2[1] - usg1[1]));
    PRINT;
    return 1;
}

static void start_lpc()
{
    object ob;
    int *ru1, *ru2, eval;
    mixed got;

    if (ob = find_object(LPC_FILE))
	destruct(ob);
    if (got = catch(ob = touch(LPC_FILE,NO_LOG)))
	write(got[1..<1]);
    if (!ob)
	return;
    rm(LPC_FILE); //Kurdel: hierher geschoben, fun() kann owner/stab zerstoeren
    ru1 = rusage();
    eval = get_eval_cost();
    got = ob->fun();

    if(!this_object())	// Wir wurden zerstoert, was wollen wir da noch machen.
	return;
	
    ru2 = rusage();
    eval -= get_eval_cost();
    vars["Got"] = got;
    if (lpc_no_print_ret)
    {
	W("Returnwert in 'Got' gespeichert.\n");
    }
    else
    {
	switch(params["print"])
	{
	  case "printf":
	    W(sprintf("Got=%O\n",got));
	    break;
	  case "none":
	    WLN("Got=" + mixed2str(got));
	    break;
	  default:
	    W(wrap("Got=" + mixed2str(got),79));
	}
    }
    if (eval_lpc)
	WLN("Eval-Cost: " + eval +
		"   Time: " + (ru2[0] - ru1[0] + ru2[1] - ru1[1]) +
		"   User-Time: " + (ru2[0] - ru1[0]) +
		"   Sys-Time: " + (ru2[1] - ru1[1]));
    destruct(ob);
    PRINT;
}

private void write_lpc(string lpc)
{
    if (file_size(LPC_FILE) > 0)
	rm(LPC_FILE);
    write_file(LPC_FILE,
	"#pragma verbose_errors\n"
	"#define OBJ(x) search_object(\"x\")\n"
	"#define VAR(x) (previous_object()->query_variable(\"x\"))\n" +
	(file_size(INCLUDE_FILE) > 0 ? "#include \"" + INCLUDE_FILE +
	"\"\n" : "") + "\nmixed fun()\n{\n"
	"    if (previous_object() && (!this_interactive() ||\n"
	"            this_interactive() == this_player()) &&\n"
	"            geteuid(previous_object()) == geteuid(this_player()) &&\n"
	"            geteuid(this_player()) == geteuid(this_object()))\n"
	"    {\n\n\n        " + lpc + "\n\n    }\n}\n");
}

void lpc_ed_end(string* text)
{
    if(!text)
	return;
	
    write_lpc(implode(text,"\n")+"\n");

    start_lpc();
    return;
}

int z_lpc(string str)
{
    mapping opt;
    string fehl;

    SECURE;
    HELP_NO_PIPE("zlpc");

    fehl = query_verb() + " [-e] [-s] <LPC-Anweisung>\n";

    if (!str)
	FAIL(fehl);

    opt = getopt(str, (["e":0, "s":0]), GO_FAILS);
    if (!opt)
	return 0;
    if (sizeof(opt["args"]) != 1)
	FAIL(fehl);
    str = opt["args"][0];
    eval_lpc = opt["e"];
    lpc_no_print_ret = opt["s"];

    if (str[<1] == '\\')
    {
	string rest = trim(str[0..<2]);
	this_player()->mini_ed(#'lpc_ed_end, 0, 0, 0, 0,
	    strlen(rest)?({rest}):({}));
	return 1;
    }
    if (str[<1] != ';')
	str += ";";
    write_lpc(str + "\n");
    start_lpc();
    return 1;
}

int z_variablen(string str)
{
    string var, wert, *ind;
    int i;
    mixed *tmp;

    SECURE;
    HELP("zvariablen");
    if (!str)
    {
	ind = m_indices(vars);
	for (i = 0; i < sizeof(ind); i++)
	    WLN(ind[i] + "=" + mixed2str(vars[ind[i]]));
	PRINT;
	return 1;
    }
    if (sscanf(str,"%s=%s",var,wert) == 2)
    {
	tmp = str2mixed(wert);
	if (!tmp)
	    return 0;
	if(!sizeof(tmp))
	    m_delete(vars, var);
	else
	    vars[var] = tmp[0];
	W("Ok.\n");
	PRINT;
	return 1;
    }
    switch(params["print"])
    {
      case "printf":
	W(sprintf("%s=%O\n",str,vars[str]));
	break;
      case "none":
	WLN(str + "=" + mixed2str(vars[str]));
	break;
      default:
	W(wrap(str + "=" + mixed2str(vars[str]),79));
    }
    PRINT;
    return 1;
}

private string get_real_file_name(object ob)
{
    string fil;
    string * list;

    fil = FN(ob);

    list = ({ob->query_file_name(),
             fil+".c", 
             map2domain(fil, 1),
             load_name(ob)+".c",
             program_name(ob)});

    return (filter(list, (: $1 && file_size($1) > 0 :)) + ({0}))[0];
}

int z_more(string str)
{
    int tmp;
    string fil, ret, mapfile;
    object ob;

    SECURE;
    HELP("zmore");
    if(!(ob = SO(str)))
	return 0;

    if(!(fil = get_real_file_name(ob)))
        FAIL(wrap("Quelldatei fuer "+FN(ob)+" nicht auffindbar!\n"));

    WLN("File : "+fil+"\n"+copies("-",strlen(fil)+7));
    PRINT;
    if(ret = OWN->more(fil))
	FAIL(M_ERR(ret));
    return 1;
}

int z_grep(string str)
{
    string fil, *words;
    object ob;

    SECURE;
    HELP("zgrep");
    
    words = str?explode(str, " "):({0});
    
    if(!(ob = SO(words[<1])))
	return 0;

    if(!(fil = get_real_file_name(ob)))
        FAIL(wrap("Quelldatei fuer "+FN(ob)+" nicht auffindbar!\n"));

    WLN("File : "+fil+"\n"+copies("-",strlen(fil)+7));
    
    return this_object()->f_grep(implode(words[0..<2]," "), fil);
}

int z_cd(string str)
{
    int tmp;
    string fil, ret, mapfile, *p;
    object ob;

    SECURE;
    HELP("zcd");
    if(!(ob = SO(str)))
	return 0;

    if(!(fil = get_real_file_name(ob)))
        FAIL(wrap("Quelldatei fuer "+FN(ob)+" nicht auffindbar!\n"));

    p = explode (fil,"/");
    return OWN->cd(implode(p[0..<2],"/"));
}

int z_ed(string str)
{
    int tmp;
    string fil;
    object ob;

    SECURE;
    HELP("zed");
    if(!(ob = SO(str)))
	return 0;

    if(!(fil = get_real_file_name(ob)))
        FAIL(wrap("Quelldatei fuer "+FN(ob)+" nicht auffindbar!\n"));

    /*
    fil = (fil = map2domain(FN(ob),1)) ? fil[0..<3] : FN(ob);
    sscanf(fil,"%s#%d",fil,tmp);
    */

    own_ed(fil);
    return 1;
}

int z_teleport(string str)
{
    SECURE;
    HELP("zteleport");
    if (str)
    {
        W(TELEPORT_LISTE_FILTER(str));
        PRINT;
        return 1;
    }
    W(TELEPORT_LISTE);
    PRINT;
    return 1;
}

int z_gehzu(string str)
{
    object ob, env;
    int res;
    string tmp, tmp2;

    SECURE;
    HELP("zgehzu");
    if (str == "-")
    {
	ob = touch(OWN->query_last_room(), NO_LOG|NO_WRITE);
	notify_fail("Du warst vorher noch nirgends.\n",FAIL_INTERNAL);
    }
    else
	ob = SO(str);
    if (!ob)
    {
	if (!str)
	    return 0;
	if (sscanf(str,"%s#%d",tmp,res) == 2)
	    return 0;
	if (sscanf(str,"%s:%s",tmp,tmp2) > 0)
	    return 0;
	if (sscanf(str,"%s|%s",tmp,tmp2) > 0)
	    return 0;
	if (str[0..0] == MARK_ICON)
	    return 0;
	if (str == ENV_ICON)
	    return 0;
	ob = touch(ADD_PATH(str),NO_LOG|NO_WRITE);
	if (!ob)
	{
	    tmp = TELEPORT(str);
	    if (!tmp)
		return 0;
	    ob = touch(tmp,NO_LOG|NO_WRITE);
	}
	if (!ob)
	    return 0;
    }

    
    if(ob->query_container())
	res = OWN->move(ob,MOVE_MAGIC);
    else
	res = MOVE_NOT_ALLOWED;
	
    if (res != MOVE_OK)
    {
	env = ENV(ob);
	if (env)
	    res = OWN->move(env,MOVE_MAGIC);
    }
    if (res!=MOVE_OK)
    {
	switch(res)
	{
	  case MOVE_NOT_ALLOWED:
	    if(ob && !ob->query_container())
		tmp = Name(ob)+" ist kein Container";
	    else
		tmp = "Bewegung ist nicht erlaubt";
	    break;
	  case MOVE_NO_ROOM:
	    tmp = "Im Zielraum ist nicht genug Platz";
	    break;
	  case MOVE_DESTRUCTED:
	    tmp = "Bewegung zerstoert";
	    break;
	  case MOVE_DEST_CLOSED:
	    tmp = "Zielraum ist geschlossen";
	    break;
	  case MOVE_ENV_CLOSED:
	    tmp = "Umgebung ist geschlossen";
	    break;
	  case MOVE_NO_DEST:
	    tmp = "Zielraum existiert nicht";
	    break;
	  default:
	    tmp = "unbekannt";
	}
	W("Du kannst nicht zu "+str+" gehen.\n        Grund: "+tmp+".\n");
    }
    else if(OWN && environment(OWN))
    {
	object* vacationwizzes = filter(all_inventory(environment(OWN)),
	    (: playerp($1) && 
	       GOETTER_REGISTER->is_wiz_on_vacation($1->query_real_name())
	    :));
	
	if(sizeof(vacationwizzes))
	    OWN->send_message_to(OWN,MT_NOTIFY|MT_DEBUG,MA_MOVE_IN,
		wrap("Achtung: "+liste(vacationwizzes->query_real_cap_name())+
		    ((sizeof(vacationwizzes)>1)?" sind":" ist")+
		    " gerade im Urlaub."));
    }
    PRINT;
    return 1;
}

// Liefert ({ ({string dateiname(ohne Endung), string aktion}) })
private mixed* all_to_update(object oob, int all)
{
    int i;
    object ob, ob2;
    string tmp, tmp2, *list;
    mixed *back = ({});

    if (!objectp(oob))
	return back;

    list = inherit_list(oob);
    tmp = load_name(oob) + ".c";
    if(member(list,tmp)<0)
	list = ({tmp}) + list;

    for (i = 0; i < sizeof(list); i++)
	if (all || MAY_WRITE(map2domain(list[i],1)||list[i],TO))
	    back += ({ ({list[i][0..<3],
		find_object(list[i])?"zerstoert.":"war nicht geladen."
		}) });

    if (member(list,object_name(oob)+".c")<0)
    {
	tmp = FN(oob);
	if (sscanf(tmp,"%s#%d",tmp2,i) == 2 && member(list,tmp2 + ".c") == -1)
	    back += ({ ({ tmp2,
		find_object(tmp2)?"zerstoert.":"war nicht geladen."
		}) });
	back += ({ ({object_name(oob), "zerstoert."}) });
    }
    
    return back;
}

private mapping alt(string *list, object pob, int all, mapping cache)
{
    int *dir, i;
    object ob;
    mapping tmp, ret;
    string *il, tmp2;
    mixed back = ({});

    ret = ([]);
    
    for (i = 0; i < sizeof(list); i++)
    {
	if (!all && !MAY_WRITE(map2domain(list[i],1)||list[i],TO))
	    continue;
	if(member(cache, list[i]))
	{
	    ret[list[i]] = cache[list[i]];
	    continue;
	}

	ob = find_object(list[i]);
	if (!ob)
	{
	    if (!ret[list[i]])
		ret[list[i]] = "war nicht geladen.";
	    continue;
	}
	if (pob == ob)
	    continue;
	il = inherit_list(ob);
	tmp2 = load_name(ob) + ".c";
	if(member(il,tmp2)<0)
	    il = ({tmp2}) + il;
	if (tmp = alt(il,ob,all,cache))
	{
	    ret += tmp;
	    if (!ret[list[i]])
		ret[list[i]] = "destructed (old)";
	    continue;
	}

	dir = get_dir(map2domain(list[i],1)||list[i],4);
	if (!dir || sizeof(dir) < 1)
	{
	    if (!ret[list[i]])
		ret[list[i]] = "existiert nicht.";
	}
	else if (program_time(ob) < dir[0])
	{
	    if (!ret[list[i]])
		ret[list[i]] = "war aelter als File auf Platte.";
	}
	else if (pob && ob && program_time(ob) > program_time(pob))
	{
	    if (!ret[FN(pob) + ".c"])
		ret[FN(pob) + ".c"] =
			"Inherit-File " + FN(ob) + ".c ist neuer.";
	}
    }
    cache += ret;
    return sizeof(ret) ? ret : 0;
}

// 0: Nix da, zum updaten
// Sonst wie bei all_to_update
private mixed* new_to_update(object ob, int all)
{
    string *li, tmp;
    mapping ret;
    int i, junk, clone;
    mixed *back = ({ });

    li = inherit_list(ob);
    if (sscanf(FN(ob),"%s#%d",tmp,junk) == 2)
    {
	tmp += ".c";
	clone = 1;
    }
    else
    {
	tmp = load_name(ob) + ".c";
	if(member(li,tmp)<0)
	    li = ({tmp}) + li;
	tmp = FN(ob) + ".c";
	clone = 0;
    }

    if (member(li,tmp) < 0)
	li = ({ tmp }) + li;

    if (ret = alt(({ tmp }),clone ? ob : 0,all,([])))
    {
	back += map(li, (: $2[$1]?({$1[0..<3],$2[$1]}):0 :), ret) - ({0});
	if (member(li, object_name(ob)+".c")<0)
	    back += ({ ({ FN(ob),
		(tmp = ret[FN(ob) + ".c"])?tmp:"destructed (old)"
		}) });
	return back;
    }
    else
    {
	W(FN(ob) + " is up to date.\n");
	return 0;
    }
}

static int z_erneuere_filter(object ob)
{
    return query_once_interactive(ob) || stringp(ob->query_vehikel())
	|| ob->query_animal();
}

int z_erneuere(string str)
{
    object ob, env, *pl, blueprint;
    string obnam, tmp, ob_str, file;
    int nr, gotoit, clone, *dir, failure, eval;
    string *savethem;
    mixed args, list;
    mapping opt;

    SECURE;
    HELP("zerneuere");

    if (str)
    {
	opt = getopt(str,(["a":0, "d":0, "n":0, "A":0, "s":0, "t":0, "T":0, "f":0, "u":0]),GO_FAILS);
	if (!opt)
	    return 0;
    }
    else
    	opt = ([]);

    if (opt["d"] && (opt["t"] || opt["T"]))
    {
	W("Die Optionen -d und -t bzw. -T schliessen sich aus.\n");
	PRINT;
	return 1;
    }

    if (opt["args"])
	ob_str = implode(opt["args"]," ");
    ob = SOT(ob_str);

    if (!ob_str)
	nr = 1;
    else if (!strstr(ob_str,MARK_ICON))
	nr = to_int(ob_str[strlen(MARK_ICON)..]) + 1;

    eval = get_eval_cost();

    if (!ob)
    {
	if (nr)
	{
	    nr -= 1;
	    ob_str = OWN->query_mark(nr,1);
	    if (!ob_str || member(ob_str,'#') >= 0)
		return 0;
	}
	ob = touch(ADD_PATH(ob_str),NO_LOG);
	if (!ob)
	    return 0;
	WLN(sprintf("Geladen: %s (%d Evals)", OFN(ob), eval - get_eval_cost()));
	PRINT;
	return 1;
    }


    if (!strstr(object_name(ob),"/apps/") && !adminp(OWN) && !opt["f"])
    {
	write("Objekte aus dem /apps solltest Du normalerweise nicht erneuern.\n"
	      "Fuer Notfaelle funktioniert dies jedoch mit der Option -f.\n");
	return 1;
    }

    if (query_once_interactive(ob))
    {
	W("Spieler darf man nicht erneuern.\n");
	PRINT;
	return 1;
    }
    
    if(ob == this_object())
    {
	W("Ich kann mich nicht selbst erneuern.\n");
	PRINT;
	return 1;
    }

    env = ENV(ob);
    obnam = OFN(ob);
    file = FN(ob);

    if (sscanf(file,"%s#%d",file,clone) == 2)
    	clone = 1;

    if (!opt["n"])
	args = ob->query_auto_load();

    if (opt["a"] || opt["A"])
    {
	// Jetzt Objekt mit allen inherits erneuern. (nicht laden)
	if (opt["s"])
	    list = all_to_update(ob,opt["A"] && adminp(OWN));
	else
	{
	    if (!(list=new_to_update(ob,opt["A"] && adminp(OWN))))
	    {
		PRINT;
		return 1;
	    }
	}
	if(!sizeof(list))
	    list += ({ ({object_name(ob), "zerstoert"}) });
    }
    else
    {
	if (clone && (blueprint = find_object(file)) &&
	    MAY_WRITE(map2domain(file,1) || (file+".c"),TO))
	{
	    if (opt["s"])
		list = ({ ({ file, "zerstoert."}) });
	    else
	    {
		dir = get_dir(file+".c",4);
		if (sizeof(dir) == 1 && program_time(blueprint) < dir[0])
		    list = ({ ({ file, 
			"war aelter als File auf Platte."
			}) });
		else
		    list = ({});
	    }
	}
	else
	    list = ({});
	list += ({ ({object_name(ob), "zerstoert"}) });
    }
    
    if(opt["t"] || opt["T"])
    {
	savethem = map(list,#'[, 0);
	foreach(string name: savethem)
	    if(name+".c" == SIMUL_EFUN || name+".c"==SPARE_SIMUL_EFUN)
	    {
		WLN("Die simul_efun darf nicht mit '-t' erneuert werden!");
		PRINT;
		return 1;
	    }
	    else if(name+".c"==MASTER_OB)
	    {
		WLN("Der Master darf nicht mit '-t' erneuert werden!");
		PRINT;
		return 1;
	    }
	    else
	    {
		object o = find_object(name);
		if(o && sizeof(
		    filter(({"prepare_renewal","finish_renewal","abort_renewal"}),
	    		#'function_exists, o))!=3 &&
		    !(opt["T"] &&
		    (MAY_WRITE(map2domain(name,1) || (name+".c"),TO) || adminp(OWN))))
		{
		    WLN("-"*79);
		    W("ACHTUNG: Erneuerung wurde nicht durchgefuehrt!\n\n");
		    W(wrap("Grund: Das Objekt '"+name+"' soll auf sichere Weise "
			"erneuert werden, besitzt aber mindestens eine der "
			"Funktionen prepare_renewal, finish_renewal und "
			"abort_renewal nicht"+
			(opt["T"]?" und Du hast keine Schreibrechte darauf.":".")
		    ));
		    WLN("-"*79);
		    PRINT;
		    return 1;
	        }
	}
    }
    else if(!opt["u"] && !opt["d"])
    {
	savethem = ({});
	foreach(string name: map(list,#'[, 0))
	{
	    object o = find_object(name);
	    if(o && sizeof(
		filter(({"prepare_renewal","finish_renewal","abort_renewal"}),
	    	    #'function_exists, o))==3)
			savethem += ({name});
	}
	if(!sizeof(savethem))
	    savethem = 0;
    }

    if (!opt["f"] && sizeof(filter(all_inventory(ob),
	(: playerp($1) && !wizp($1) && !testplayerp($1) :))))
    {
	WLN("-"*79);
	W("ACHTUNG: Erneuerung wurde nicht durchgefuehrt!\n\n");
	W(wrap("Grund: Es befindet sich noch mindestens ein Spieler "
	    "(kein Gott oder Testie) in diesem Raum. Diesen Test kannst Du "
	    "mit -f ausschalten."));
	WLN("-"*79);
	PRINT;
	return 1;
    }
    
    // bei 'zern hier' werden alle wichtigen Objekte gerettet
    if (ob == ENV(OWN))
    {
	pl = filter(all_inventory(ob),"z_erneuere_filter",this_object());
        pl->force_move("/room/void",MOVE_SECRET);
	gotoit=1;
    }

    if(savethem)
	MASTER_OB->save_objects_for_renewal(savethem);

    foreach(mixed l:list)
    {
	object o;
	if(sizeof(list)==1 && strstr(l[1]," ")<0)
	    W(capitalize(l[1])+": "+l[0]+"\n");
	else
	    W(sprintf("%-22s %s\n", l[0]+":", l[1]));
	if(!savethem || member(savethem,l[0])<0)
	{
	    o = find_object(l[0]);
	    if(o)
	    {
		o->remove();
		if(o)
	    	    destruct(o);
		// Wir wurden dabei zerstoert? Na dann Gute Nacht.
		if(!this_object())
		    return 0;
	    }
	}
    }

    if (!opt["d"])
    {
	ob = 0;
	failure = 1;
	
	// Jetzt Objekt clonen oder laden
	if (clone)
	{
	    if (touch(file,NO_LOG))
	    {
		ob = clone_object(file);
		
		if (!ob)
		{
		    W(sprintf("Das Objekt hat sich im create() zerstoert. (%d Evals)\n", eval - get_eval_cost()));
		    failure = 0;
		}
		else
		    WLN(sprintf("Erschafft: %s (%d Evals)", OFN(ob), eval - get_eval_cost()));
	    }
	}
	else
	{
	    ob=touch(file,NO_LOG);
	    if (ob)
		WLN(sprintf("Geladen: %s (%d Evals)", OFN(ob), eval - get_eval_cost()));
	}
	
	if(ob)
	    failure = 0;

	if (ob && env)
	{
	    if (ob->move(env) != MOVE_OK)
	    {
		WLN("Das Objekt konnte nicht an seinen alten Platz bewegt "
		    "werden!\n");
		if (ob)
		{
		    tmp = OFN(ob);
		    ob->remove();
		    if (ob)
			destruct(ob);
		    WLN("Zerstoert: "+tmp);
		}
		else
		    WLN("Das Objekt wurde beim Bewegen zerstoert!\n");
	    }
	    else
	    {
		if (!ob)
		    WLN("Das Objekt wurde beim Bewegen zerstoert!\n");
		else
		{
		    if (env != ENV(ob))
			W("Objekt ist woanders gelandet!\n");
		    WLN("Move nach "+OFN(ENV(ob)));
		}
	    }
	}

	if (ob && nr)
	{
	    nr -= 1;
	    OWN->set_mark(nr,ob);
	    WLN("Neue Markierung "+MARK_ICON+nr+": "+OFN(ob));
	}
	if (ob && gotoit)
	    map_objects(pl,"move",ob);
	if (args && ob)
	    ob->init_arg(args);
    }
    PRINT;

    if(savethem)
	MASTER_OB->finish_renewal(failure, ob);

    return 1;
}

int z_erschaffe(string str)
{
    int nr, do_set_mark;
    string was, wohin, tmp, usage, err;
    object ob, wohin_ob;
    mapping opt;
   
    SECURE;
    HELP("zerschaffe");

    usage = query_verb()+" [-lcn] [<Markierung>=]<file> [<objektstring>]\n";
    if (!str)
	FAIL(usage);
	
    opt = getopt(str,(["l":0,"c":0,"n":0]),GO_FAILS);
    if (!opt)
	return 0;
    if (!opt["args"])
	FAIL(usage);
    str = space(implode(opt["args"]," "));

    if (strstr(str,MARK_ICON) == 0)
    {
	if (sscanf(str, MARK_ICON "%.0d%!.0t=%!.0t%s",nr,tmp) != 2)
	    FAIL(usage);
	if (sscanf(tmp,"%s %s",was,wohin) != 2)
	{
	    was = tmp;
	    // Markierung angegeben, aber kein Ziel -> nicht bewegen
	    wohin = "";
	}
	do_set_mark = 1;
    }
    else
    {
	if (sscanf(str,"%s %s",was,wohin) != 2)
	    was = str;
    }

    if (nr>9 || nr<0)
	FAIL("Die Markierung "+MARK_ICON+nr+" kenne ich nicht.\n");

    was = load_name(SOT(was))||ADD_PATH(was);
    if (was[<2..] == ".c")
	was = was[0..<3];
    if (strstr(was,"/obj/") == -1 && !opt["l"])
    {
	if (file_size(was + ".c") < 0)
	    FAIL("Dieses File gibt es nicht.\n");
	else if (!MAY_WRITE(was + ".c",TO))
	    FAIL("Dieses Objekt ist nicht zum Erschaffen vorgesehen, "
		 "es kann nur geladen werden.\n");
	else
	    W("INFO: Dieses Objekt liegt in einem falschen Verzeichnis.\n"
	      "INFO: Bitte lege es in ein Unterverzeichnis, das 'obj' "
	      "heisst,\nINFO: damit klar ist, dass es ein clonebares "
	      "Objekt ist.\n");
    }

    if (strlen(wohin) && !(wohin_ob = SO(wohin)))
	return 0;

    if (playerp(wohin_ob) && wohin_ob != OWN &&
	    wohin_ob->query_level() >= OWN->query_level())
	FAIL(Der(wohin_ob)+" haette das sicher nicht gerne.\n");

    
    if (opt["l"] && find_object(was))
	FAIL("Das Objekt existiert bereits.\n");

    if (file_size(was + ".c") > 0 || file_size(was + ".udl") < 0 || opt["l"])
    {
	if (opt["c"])
	{
	    err = catch(ob = touch(was, NO_LOG));
	    if(stringp(err))
	    {
		W("Fehler beim Laden: "+err[1..<1]);
		ob = find_object(was);
	    }
	    if(!ob)
	    {
		PRINT;
		return 1;
	    }
	}
	else if (!(ob = touch(was,NO_LOG)))
	{
	    PRINT;
	    return 1;
	}
    }

    if(!opt["l"])
    {
	if (ob && environment(ob))
	    FAIL("Objekte, die eine Umgebung haben kann man nicht clonen.\n");

	if(opt["c"])
	{
	    err = catch(ob = clone_object(was));
	    if (err)
		W("Fehler beim Clonen: " + err[1..<1]);
	}
	else
	    ob = clone_object(was);
    }

    if (!ob)
    {
	if(!err)
	    W("Das Objekt hat sich im create() zerstoert.\n");
    }
    else
    {
	if (opt["n"])
	    0; // Nix machen
	else if (!wohin_ob && wohin != "")
	{
	    if (ob->move(OWN) != MOVE_OK)
	    {
		if (!ob)
		    W("Das Objekt hat sich beim Bewegen in Dich zerstoert.\n");
		else if (ob->move(ENV(OWN)) != MOVE_OK || !ob)
		{
		    if (!ob)
			W("Das Objekt hat sich beim Bewegen in Deine "
			  "Umgebung zerstoert.\n");
		    else
		    {
			W("Das Objekt liess sich nicht bewegen. "
			  "Ich zerstoere es.\n");
			ob->remove();
			if (ob)
			    destruct(ob);
		    }
		}
		else
		    W("Objekt wurde in deine Umgebung bewegt.\n");
	    }
	    else
		W("Ok.\n");
	}
	else if (wohin_ob)
	{
	    if (ob->move(wohin_ob) != MOVE_OK)
	    {
		if (!ob)
		    W(wrap("Das Objekt hat sich beim Bewegen nach "+wohin+" ("+
			mixed2str(wohin_ob)+") zerstoert."));
		else
		{
		    string grund = ob->query_not_moved_reason();
		    W("Das Objekt liess sich nicht bewegen. "
		      "Ich zerstoere es.\n");
		    if(stringp(grund))
			W(wrap("Grund: "+grund));
		    
		    ob->remove();
		    if (ob)
			destruct(ob);
		}
	    }
	    else
	    {
		W("Objekt wurde nach "+OFN(wohin_ob)+" bewegt.\n");
		if (living(wohin_ob) && ob && ob->query_name())
		    tell_object(wohin_ob, Der(OWN,"")+" hat Dir "+einen(ob,"")+
			    " ins Gepaeck gesteckt.\n");
	    }
	}
    
	if (do_set_mark && ob)
	{
	    OWN->set_mark(nr,ob);
	    W("Objekt in "+MARK_ICON+nr+" gespeichert : "+OFN(ob)+"\n");
	}
	if (ob && environment(ob) == OWN && !IS_INVIS(OWN) &&
	       (tmp = closure_to_string(c_clone_msg,({ob}))) && tmp != "")
	    OWN->send_message(MT_LOOK,MA_UNKNOWN,wrap(tmp));
    }
    PRINT;
    return 1;
}

private int get_inherit_tree(string str, string add, int show_virtual, int is_virtual)
{
    object ob;
    string *inh;
    int i, siz;

    ob = find_object(str);
    inh = inherit_list(ob,show_virtual?INHLIST_TAG_VIRTUAL:0);
    W((show_virtual?(is_virtual?"v ":"  "):"")+ add + FN(ob) + ".c");
    if ((show_virtual?inh[0][2..<1]:inh[0]) != FN(ob) + ".c")
	W("  (REPLACED)");
    else
	i = siz = 1;
    W("\n");
    for (; i<sizeof(inh); i++)
    {
	siz += get_inherit_tree(show_virtual?inh[i][2..<1]:inh[i],"  " + add,
		show_virtual, show_virtual && inh[i][0]=='v');
	if (siz >= sizeof(inh))
	    break;
    }
    return siz;
}

int z_inherit(string str)
{
    mapping opt;
    string obname;
    object what;
    string *list;
    int i;

    SECURE;
    HELP("zinherit");

    if (str)
    {
	opt = getopt(str,(["r":0, "v":0]),GO_FAILS);
	if (!opt)
	    return 0;
    }
    else
    	opt = ([]);

    if (opt["args"])
	obname = implode(opt["args"]," ");
    if(!(what = SO(obname)))
	return 0;

    if (opt["r"])
    {
	int junk;
	object ob;
	string name;

	list = inherit_list(what);
	i = sizeof(list);
	while(i--)
	    if (!(ob = find_object(list[i])))
	    {
		W(list[i] + " war nicht geladen.\n");
		if(!touch(list[i],NO_LOG|NO_WRITE))
		{
		    W("Konnte " + list[i] + " nicht laden.\n");
		    PRINT;
		    return 1;
		}
	    }
	W(ON(what) + ":\n");
	if (sscanf(ON(what),"%s#%d",name,junk) != 2)
	    name = ON(what);
	get_inherit_tree(name,"",opt["v"],0);
    }
    else
    {
	list = inherit_list(what,opt["v"]?INHLIST_TAG_VIRTUAL:0);
	for(i = 0; i<sizeof(list); i++)
	    WLN(list[i]);
    }
    PRINT;
    return 1;
}

int z_cout(string str)
{
    mapping opt;
    object ob;
    mixed *co;
    int i, j;

    SECURE;
    HELP("zcout");

    if (str)
    {
	opt = getopt(str,(["l":0, "n":0, "c":0]),GO_FAILS);
	if (!opt)
	    return 0;
    }
    else
    	opt = ([]);

    if (opt["args"])
    {
	ob = SO(implode(opt["args"]," "));
	if(!ob)
	    return 0;
    }

    co=call_out_info();
    if(ob)
    {
	if(opt["c"])
	    co = filter(co, (: load_name($1[0]) == $2 :), load_name(ob));
	else
	    co = filter(co, (: $1[0] == $2 :), ob);
    }
    
    if (!sizeof(co))
	W("Im Moment laufen keine call_outs.\n");
    else
    {
	W(sprintf("%-38s %-20s %-6s Argument\n","Objekt","Funktion","Zeit"));
	for (i=0; i<sizeof(co); i++)
	{
	    W(sprintf("%-59s %6d",
		sprintf("%-38s %s",
		    objectp(co[i][0])?FN(co[i][0]):mixed2str(co[i][0]),
		    stringp(co[i][1])?co[i][1]:mixed2str(co[i][1])),
		    co[i][2]));
	    if (opt["l"])
		for (j=3; j<sizeof(co[i]); j++)
		    W((" "+mixed2str(co[i][j])));
	    else if(!opt["n"])
		for (j=3; j<sizeof(co[i]); j++)
		    W((" "+mixed2str(co[i][j]))[0..79]);
	    W("\n");
	}
    }
    PRINT;
    return 1;
}

int z_dbg(string str)
{
    object obj;
    int nr, obnr, i;
    string obst;

    SECURE;
    HELP("zdbg");

    if (!str)
	str = MARK_ICON;
    i = sscanf(str,"-%d %s",nr,obst);
    if (i == 1)
	obst = MARK_ICON;
    else if (i == 0)
	obst = str;
    if (nr<0 || nr>2)
	FAIL(query_verb()+" [-1] [<Objektstring>]\n");

    obj = SO(obst);
    if (!obj)
	return 0;

#if __EFUN_DEFINED__(driver_info)
    if(nr == 0)
    {
        W(sprintf("O_HEART_BEAT      : %s\n", efun::object_info(obj, OC_HEART_BEAT)       ? "TRUE" : "FALSE"));
        W(sprintf("O_ENABLE_COMMANDS : %s\n", efun::object_info(obj, OC_COMMANDS_ENABLED) ? "TRUE" : "FALSE"));
        W(sprintf("O_CLONE           : %s\n", efun::clonep(obj)                           ? "TRUE" : "FALSE"));
        W(sprintf("O_DESTRUCTED      : FALSE\n"));
        W(sprintf("O_SWAPPED         : %s\n", efun::object_info(obj, OI_SWAPPED)          ? "TRUE" : "FALSE"));
        W(sprintf("O_ONCE_INTERACTIVE: %s\n", efun::object_info(obj, OI_ONCE_INTERACTIVE) ? "TRUE" : "FALSE"));
        W(sprintf("O_RESET_STATE     : %s\n", efun::object_info(obj, OI_RESET_STATE)      ? "TRUE" : "FALSE"));
        W(sprintf("O_WILL_CLEAN_UP   : %s\n", efun::object_info(obj, OI_WILL_CLEAN_UP)    ? "TRUE" : "FALSE"));
        W(sprintf("O_REPLACED        : %s\n", efun::object_info(obj, OI_REPLACED)         ? "TRUE" : "FALSE"));
        W(sprintf("time_reset  : %d\n",       efun::object_info(obj, OI_NEXT_RESET_TIME)));
        W(sprintf("time_of_ref : %d\n",       efun::object_info(obj, OI_LAST_REF_TIME)));
        W(sprintf("ref         : %d\n",       efun::object_info(obj, OI_OBJECT_REFS)));

        int gticks = efun::object_info(obj, OI_GIGATICKS);
        if(gticks)
            W(sprintf("evalcost   :  %d%09d\n", gticks, efun::object_info(obj, OI_TICKS)));
        else
            W(sprintf("evalcost   :  %d\n",   efun::object_info(obj, OI_TICKS)));

        W(sprintf("swap_num    : %d\n",       efun::object_info(obj, OI_SWAP_NUM)));
        W(sprintf("name        : '%s'\n",     efun::object_name(obj)));
        W(sprintf("load_name   : '%s'\n",     efun::load_name(obj)));

        object next_ob = efun::object_info(obj, OI_OBJECT_NEXT);
        if (next_ob)
            W(sprintf("next_all    : OBJ(%s)\n", efun::object_name(next_ob)));

        object prev_ob = efun::object_info(obj, OI_OBJECT_PREV);
        if (prev_ob)
            W(sprintf("Previous object in object list: OBJ(%s)\n", efun::object_name(prev_ob)));
        else
            W(sprintf("This object is the head of the object list.\n"));
    }
    else if(nr == 1)
    {
        W(sprintf("program ref's %3d\n",   efun::object_info(obj, OI_PROG_REFS)));
        W(sprintf("Name: '%s'\n",          efun::program_name(obj)));
        W(sprintf("program size    %6d\n", efun::object_info(obj, OI_PROG_SIZE)));
        W(sprintf("num func's:  %3d (%4d)\n",
                                        efun::object_info(obj, OI_NUM_FUNCTIONS),
                                        efun::object_info(obj, OI_SIZE_FUNCTIONS)));
        W(sprintf("num vars:    %3d (%4d)\n",
                                        efun::object_info(obj, OI_NUM_VARIABLES),
                                        efun::object_info(obj, OI_SIZE_VARIABLES)));

        W(sprintf("num strings: %3d (%4d) : overhead %d + data %d (%d)\n",
                                        efun::object_info(obj, OI_NUM_STRINGS),
                                        efun::object_info(obj, OI_SIZE_STRINGS) + efun::object_info(obj, OI_SIZE_STRINGS_DATA),
                                        efun::object_info(obj, OI_SIZE_STRINGS),
                                        efun::object_info(obj, OI_SIZE_STRINGS_DATA),
                                        efun::object_info(obj, OI_SIZE_STRINGS_DATA_TOTAL)));

        W(sprintf("num inherits %3d (%4d)\n",
                                        efun::object_info(obj, OI_NUM_INHERITED),
                                        efun::object_info(obj, OI_SIZE_INHERITED)));

        W(sprintf("total size      %6d\n", efun::object_info(obj, OI_PROG_SIZE_TOTAL)));

        W(sprintf("data size       %6d (%6d\n",
                                        efun::object_info(obj, OI_DATA_SIZE),
                                        efun::object_info(obj, OI_DATA_SIZE_TOTAL)));
    }
#else
    OWN->show_func_result(lambda(0,({#'efun::debug_info, nr, obj})));
#endif

    PRINT;
    return 1;
}

int z_HB(string str)
{
    mixed *obs;
    int i;

    SECURE;
    HELP("zHB");
    if (str)
	return 0;
    obs = efun::heart_beat_info();
    for (i = 0; i < sizeof(obs); i++)
	WLN(OFN(obs[i]) + "\t" + Name(obs[i]));
    PRINT;
    return 1;
}

#define MWRAP(x,y) sprintf("%-13s %=-65s\n",x,y)

int z_etup(string str)
{
    string was, par, tmp;
    int ret;

    SECURE;
    HELP_NO_VERB("zetup");
    if (!str)
    {
#       include "show_msg.inc"
	if((tmp = OWN->query_home_msg()) && tmp != "")
	{
	   W(MWRAP("home_msg:",OWN->query_home_msg()));
	   W(MWRAP("  ==>",OWN->message_expansion(
	      OWN->message_parser(OWN->query_home_msg()))));
	}
	else
	{
	   W(MWRAP("home_msg:",
		     "0"));
	   W(MWRAP("  ==>",Der(OWN)+" geht nach Hause."));
	}
	if((tmp = OWN->query_clone_msg()) && tmp != "")
	{
	   c_clone_msg = mixed_to_closure(tmp, ({'ob}), 1);
	   W(MWRAP("clone_msg:",OWN->query_clone_msg()));
	   W(MWRAP("  ==>",closure_to_string(c_clone_msg,
	      ({(["name":"fackel","gender":"weiblich","environment":OWN])}
	      ))));
	}
	else
	{
	   W(MWRAP("clone_msg:",
		     "0"));
	   W(MWRAP("  ==>","<Keine Meldung>"));
	}
	if((tmp = OWN->query_destruct_msg()) && tmp != "")
	{
	   c_destruct_msg = mixed_to_closure(tmp,({'ob}),1);
	   W(MWRAP("destruct_msg:",OWN->query_destruct_msg()));
	   W(MWRAP("  ==>",closure_to_string(c_destruct_msg,
	      ({(["name":"fackel","gender":"weiblich","environment":OWN])}
	      ))));
	}
	else
	{
	   W(MWRAP("destruct_msg:",
		     "0"));
	   W(MWRAP("  ==>","<Keine Meldung>"));
	}
	W("\nZeilen:  "+OWN->query_more_chunk()+" (Anzahl Zeilen, nachdem der More anhaelt)\n");
	W("Max-Out: "+query_max_output()+" (Anzahl Zeilen, nachdem der Zauberstab die Ausgabe automatisch\n            in einen More umleitet)\n");
	WLN("Print:       "+params["print"]);
	WLN("Prompt:      "+OWN->query_prompt_string());
	WLN("Wer-Liste:   "+(OWN->query_no_wer()?"Nein (Du tauchst in der "
	    "Wer-Liste aller Spieler NICHT auf)":"Ja (Du tauchst in der "
	    "Wer-Liste aller Spieler auf)"));
	if((tmp = OWN->query_finger_info()) && tmp != "")
	   WLN("Fingertext:\n"+tmp);
	else
	   W(MWRAP("Fingertext:", "Keiner"));
	PRINT;
	return 1;
    }

    par = 0;
    if (sscanf(str,"%s %s",was,par)!=2 && sscanf(str,"%s",was)!=1)
	FAIL(query_verb()+" <Was> <Parameter>\n");

    ret=set_param(was,par);
    if (ret)
	W("Ok.\n");
    PRINT;
    return ret;
}

int z_licht(string str)
{
    int tmp;

    SECURE;
    HELP("zlicht");
    if (!str)
    {
	WLN("Gesamt-Licht-Level     : "+environment(OWN)->query_light()+"\n"+
		"Zauberstab-Licht-Level : "+query_own_light());
	PRINT;
	return 1;
    }

    str = space(str);
    switch(str)
    {
      case "an":
	add_own_light(1);
	if (environment(OWN)->query_light()==1)
	   say(wrap(Ihr()+" beginnt in einem warmen Licht zu leuchten."));
	break;
      case "aus":
	add_own_light(-1);
	if (environment(OWN)->query_light()==0)
	   say(wrap(Ihr()+" erlischt."));
	break;
      case "AN":
	if (environment(OWN)->query_light()<=0)
	    say(wrap(Ihr()+" beginnt in einem warmen Licht zu leuchten."));
	add_own_light(1-environment(OWN)->query_light());
	break;
      case "AUS":
	if (environment(OWN)->query_light()>0)
	    say(wrap(Ihr()+" erlischt."));
	add_own_light(-environment(OWN)->query_light());
	break;
      default:
	if (sscanf(str,"%d",tmp)==1)
	{
	    set_own_light(tmp);
	    if (environment(OWN)->query_light()==0)
	       say(wrap(Ihr()+" erlischt."));
	    else if (environment(OWN)->query_light()==1)
	       say(wrap(Ihr()+" beginnt in einem warmen Licht zu leuchten."));
            break;
	}

        {
	    int rek;
            object ob;
	    if(lower_case(str[0..2])=="-r ")
	    {
		rek = (str[1]=='r')?1:2;
		str = str[3..<1];
	    }
	    ob=search_object(str);
            if(ob)
            {
		object *obs;
		
                WLN(copies("-", 79));

                W(sprintf(
                    "Objekt: %O\n"
                    "query_outer_light()=%O (berechnet: %O)\n"
                    "query_own_light  ()=%O\n"
                    "query_inner_light()=%O\n"
                    "query_transparent()=%O\n"
                    "query_light      ()=%O\n"
		    "query_day_light  ()=%O\n",
                    ob,
                    ob->query_outer_light(),
                    ob->query_own_light()+(ob->query_transparent()?
                        ob->query_inner_light():0),
                    ob->query_own_light(),
                    ob->query_inner_light(),
                    ob->query_transparent(),
                    ob->query_light(),
		    (({ob})+(all_environment(ob)||({})))[<1]->query_daylight()
                    ));

		switch(rek)
		{
		    case 0:
			obs=all_inventory(ob);
			break;
		    case 1:
			obs = all_inventory(ob);
			for(int i=0;i<sizeof(obs);i++)
			    if(obs[i]->query_transparent())
				obs[i+1..i] = filter_objects(all_inventory(obs[i]),"query_outer_light");
			break;
		    case 2:
			obs=deep_inventory(ob);
		}
		
                if(sizeof(obs))
                {
                    string *nr=({});

                    WLN("\nInhalt: (out=query_outer_light(), own=query_own_light(), in=query_inner_light()");
		    
                    while(sizeof(nr)<sizeof(obs))
		    {
                        nr+=({to_string(sizeof(nr))});
		    }

                    WLN(
                        implode(
                            build_table(
                                ({
                                    ({"Nr", "-"})+nr,
                                    ({"out", "-"})+map(obs->query_outer_light(),#'to_string),
				    ({"own", "-"})+map(obs->query_own_light(),#'to_string),
				    ({"in",  "-"})+map(obs->query_inner_light(),#'to_string),
                                    ({"Objekt", "-"})+
                                        map(obs, (: "  "*(sizeof(all_environment($1))-$2)+sprintf("%O", $1) :),
					    sizeof(all_environment(ob))),
                                    }),
                                ({"", "-", ""}),
                                ({"r", "r", "r", "r", "l"})
                                ),
                            "\n"
                            )
                        );
                }
                else
                    WLN("\nKein Inhalt.");

                WLN(copies("-", 79));

                PRINT;
                return 1;
            }
        }

        FAIL(query_verb()+" [an | aus | AN | AUS | <Licht-Level>| "
            "<Objektstring>]\n");
    }
    WLN("Gesamt-Licht-Level     : "+environment(OWN)->query_light()+"\n"+
	"Zauberstab-Licht-Level : "+query_own_light());
    PRINT;
    return 1;
}

int f_chsh(string str)
{
   string * shs;
   int i;

   SECURE;
   SECURE_ADMIN;
   HELP("chsh");

   shs = MASTER_OB->query_valid_shells();

   if(!str)
   {
      WLN("Deine aktuelle Shell: "+FN(OWN));
      WLN("Verfuegbare Shells:");
      for(i = 0; i < sizeof(shs); i++)
	 WLN(right(i+1, 3)+" "+shs[i]);
      PRINT;
      return 1;
   }
   if(sscanf(str, "%d", i))
   {
      if(--i >= 0 && i < sizeof(shs))
	 "/secure/chsh"->chsh(shs[i]);
      else
	 FAIL("Eine Shell mit dieser Nummer gibt es nicht!\n");
   }
   else
   {
      if(member(shs, str) >= 0)
	 "/secure/chsh"->chsh(str);
      else
	 FAIL("Die Shell "+str+" gibt es nicht!\n");
   }
   PRINT;
   return 1;
}

static void z_msg_text(string *text, string ob)
{
    object obj;

    if (!obj=touch(ob))
    {
	write("Zielobjekt ist nicht mehr vorhanden. Meldung wurde nicht "
	      "ausgegeben.\n");
	return;
    }

    if (!sizeof(text))
    {
	write("Abbruch der Meldung (Meldung wurde nicht ausgegeben)\n");
	return;
    }

    write("[Ende der Meldung]\n");

    if (living(obj))
        tell_object(obj, "[Meldung von "+OWN->query_real_cap_name()+"]\n" +
            implode(text,"\n") + "\n[Ende der Meldung]\n");
    else
        tell_room(obj, "[Meldung von "+OWN->query_real_cap_name()+"]\n" +
            implode(text,"\n") + "\n[Ende der Meldung]\n",({OWN}));
    return;
    
}

int z_msg(string str)
{
    object ob;

    SECURE;
    HELP_NO_PIPE("zmsg");

    if (str)
    {
	ob=SO(str);
	if (!ob)
	    return 0;
	if (!playerp(ob))
	    FAIL(Name(ob)+" ist kein Spieler.\n");
    }
    else
	ob=ENV(OWN);

    if (!ob)
	return 0;
    
    OWN->mini_ed(lambda(({'text}),({#'z_msg_text,'text,object_name(ob)})), 0,
        (file_size("/w/"+OWN->query_real_name()+"/priv")==FSIZE_DIR)
            ?"/w/"+OWN->query_real_name()+"/priv/ZMSG_TEXT"
            :"/w/"+OWN->query_real_name()+"/ZMSG_TEXT",
        ([MINI_ED_START_TEXT: 
            (living(ob)?("Sende Meldung an "+Name(ob)+".\n")
                       :"Sende Meldung in den Raum.\n") +
            "Ende mit '.' oder '**' Abbruch mit '~q' (Meldung wird nicht "
	    "ausgegeben)\n"
        ]));
    return 1;
}

private string type_to_str(int typ)
{
    string ret, tmp;

    if (typ & TYPE_MOD_POINTER)
    {
	typ &= ~TYPE_MOD_POINTER;
	tmp = " *";
    }
    else
    {
	tmp = " ";
    }
    switch(typ)
    {
	case TYPE_NUMBER:	ret = "int";		break;
	case TYPE_STRING:	ret = "string";		break;
	case TYPE_VOID:		ret = "void";		break;
	case TYPE_OBJECT:	ret = "object";		break;
	case TYPE_MAPPING:	ret = "mapping";	break;
	case TYPE_FLOAT:	ret = "float";		break;
	case TYPE_ANY:		ret = "mixed";		break;
	case TYPE_CLOSURE:	ret = "closure";	break;
	case TYPE_SYMBOL:	ret = "symbol";		break;
	case TYPE_QUOTED_ARRAY:	ret = "quoted_array";	break;
	case TYPE_UNKNOWN:				break;
	default:		ret = "ERROR";		break;
    }
    return ret + tmp;
}

private string add_modifier(string tmp, int def)
{
    if (def & NAME_INHERITED)
	tmp += " (inherit)";
    if (def & TYPE_MOD_PRIVATE)
	tmp = "private " + tmp;
    if (def & TYPE_MOD_PROTECTED)
	tmp = "protected " + tmp;
    if (def & TYPE_MOD_STATIC)
	tmp = "static " + tmp;
    if (def & TYPE_MOD_PUBLIC)
	tmp = "public " + tmp;
    if (def & TYPE_MOD_VARARGS)
	tmp = "varargs " + tmp;
    if (def & TYPE_MOD_NO_MASK)
	tmp = "nomask " + tmp;
    if (def & TYPE_MOD_NOSAVE)
	tmp = "nosave " + tmp;
    if (def & NAME_CROSS_DEFINED)
	tmp += " (cross-defined)";
    if (def & NAME_HIDDEN)
	tmp += " (hidden)";
    if (def & NAME_UNDEFINED)
	tmp += " (undefined)";
    if (def & NAME_PROTOTYPE)
	tmp += " (prototype)";
    if (def & NAME_TYPES_LOST)
	tmp += " (types-lost)";
    if (def & TYPE_MOD_VIRTUAL)
	tmp += " (virtual)";
    if (def & TYPE_MOD_XVARARGS)
	tmp += " (xvarargs)";
/*
    if (!(def & VAR_INITIALIZED))
	tmp = "shared " + tmp;
*/
    return tmp;
}

private string mach_fun(string fun, int def, int typ, int num)
{
    string tmp;
    int j;

    tmp = "";
    for (j = 1; j <= num; j++)
	tmp += "v" + j + ",";
    if (def & TYPE_MOD_XVARARGS)
	tmp += "...,";
    tmp = type_to_str(typ) + fun + "(" + tmp[0..<2] + ")";

    return add_modifier(tmp,def);
}

private string exist_fun(string fun, object where)
{
    string inh = function_exists(fun, where, FEXISTS_ALL);
    if(!inh)
    {
	inh = function_exists(fun, where, NAME_HIDDEN|FEXISTS_ALL);
	if(!inh)
	    return 0;
	else
	    return sprintf("(%s\n %s, Zeile %d)",
		inh[FEXISTS_PROGNAME],
		inh[FEXISTS_FILENAME],
		inh[FEXISTS_LINENO]);
    }
    else
	return sprintf("%s\n%s, Zeile %d",
	    inh[FEXISTS_PROGNAME],
	    inh[FEXISTS_FILENAME],
	    inh[FEXISTS_LINENO]);
}

private string mach_var(string var, int def, int typ)
{
    return add_modifier(type_to_str(typ) + var,def);
}

private string exist_var(string var, object where)
{
    string inh = variable_exists(var, where);
    if(!inh)
    {
	inh = variable_exists(var, where, NAME_HIDDEN);
	if(!inh)
	    return "()";
	else
	    return "("+inh+")";
    }
    else
	return inh;
}

int z_fl(string str)
{
    string s1, s2, ret, *list, *funs;
    object ob;
    int i, j;
    mixed *flags, *types, *args;

    SECURE;
    HELP("zfl");

    if (!str)
	FAIL(query_verb() + " [<Objektstring>] <Pattern>\n");
    if (!sscanf(str,"%s %s",s1,s2))
	s2 = str;
    ob = search_object(s1);
    if (!ob)
	return 0;
    funs  = efun::functionlist(ob,RETURN_FUNCTION_NAME);
    flags = efun::functionlist(ob,RETURN_FUNCTION_FLAGS);
    types = efun::functionlist(ob,RETURN_FUNCTION_TYPE);
    args  = efun::functionlist(ob,RETURN_FUNCTION_NUMARG);
    ret = "";
    if (s2 == "*" || s2 == "." || s2 == ".*")
    {
	for (i = 0; i < sizeof(funs); i++)
	    ret += sprintf("%-=78s\n        %-=70s\n",
		mach_fun(funs[i],flags[i],types[i],args[i]),
		exist_fun(funs[i],ob)||"()");
    }
    else
    {
	list = regexp(funs,s2);
	j = -1;
	for (i = 0; i < sizeof(list); i++)
	{
	    while(list[i] != funs[++j])
		;
	    ret += sprintf("%-=78s\n        %-=70s\n",
		mach_fun(funs[j],flags[j],types[j], args[j]),
		exist_fun(funs[j],ob)||"()");
	}
    }
    W(ret);
    PRINT;
    return 1;
}

int z_vl(string str)
{
    string s1, s2, ret, *list, *vars;
    object ob;
    int i, j;
    mixed *flags, *types;

    SECURE;
    SECURE_ADMIN;
    HELP("zvl");

    if (!str)
	FAIL(query_verb() + " [<Objektstring>] <Pattern>\n");
    if (!sscanf(str,"%s %s",s1,s2))
	s2 = str;
    ob = search_object(s1);
    if (!ob)
	return 0;
#if __EFUN_DEFINED__(variable_list)
    vars  = efun::variable_list(ob,RETURN_FUNCTION_NAME);
    flags = efun::variable_list(ob,RETURN_FUNCTION_FLAGS);
    types = efun::variable_list(ob,RETURN_FUNCTION_TYPE);
    ret = "";
    if (s2 == "*" || s2 == "." || s2 == ".*")
    {
	for (i = 0; i < sizeof(vars); i++)
	    ret += sprintf("%-50s %s\n",mach_var(vars[i],flags[i],types[i]),
			exist_var(vars[i],ob));
    }
    else
    {
	list = regexp(vars,s2);
	j = -1;
	for (i = 0; i < sizeof(list); i++)
	{
	    while(list[i] != vars[++j])
		;
	    ret += sprintf("%-50s %s\n",mach_var(vars[j],flags[j],types[j]),
			exist_var(vars[i],ob));
	}
    }
#endif
    W(ret);
    PRINT;
    return 1;
}

int z_funktion(string str)
{
    object obj, s_obj;
    string wer,fun;
    int sh;

    SECURE;
    HELP("zfunktion");
    if (!str)
       FAIL(query_verb()+" [<Objektstring>] <Funktion>\n");
    if (sscanf(str,"%s %s",wer,fun)!=2)
    {
	wer=MARK_ICON;
	fun=str;
    }
    obj=SO(wer);
    if (!obj)
	return 0;

    s_obj = obj;
    while(s_obj=shadow(s_obj,0))
    {
	string prog = function_exists(fun,s_obj);
	if(prog)
	{
	    if(!sh)
		WLN("Shadows:");
	    sh = 1;
	    WLN(sprintf("  %s (%s)",prog,object_name(s_obj)));
	}
    }
    if(sh)
        WLN(sprintf("%O:",obj));
    
    WLN((sh?"  ":"")+(exist_fun(fun,obj)||"Nirgends"));
    PRINT;
    return 1;
}


/*
FUNKTION: prepare_renewal
DEKLARATION: void prepare_renewal()
BESCHREIBUNG:
Diese Funktion wird beim einem 'zerneuere -t'-Befehl im zu erneuernden
Objekt aufgerufen, bevor es umbenannt wird und das neue Objekt geladen
wird. Hier sollte ungefaehr alles getan werden, war vor dem Neuladen
des Objektes erforderlich ist (z.B. Daten abspeichern).
VERWEISE: abort_renewal, finish_renewal
GRUPPEN: grundlegendes
*/

/*
FUNKTION: abort_renewal
DEKLARATION: void abort_renewal()
BESCHREIBUNG:
Diese Funktion wird aufgerufen, nachdem bei einem 'zerneuere -t' das
Neuladen fehlschlug und nachdem daher dieses Objekt wieder zurueck
umbenannt wurde. Hier kann man Aktionen aus prepare_renewal rueckgaengig
machen.
VERWEISE: prepare_renewal, finish_renewal
GRUPPEN: grundlegendes
*/

/*
FUNKTION: finish_renewal
DEKLARATION: void finish_renewal(object neu)
BESCHREIBUNG:
Falls ein Erneuern bei 'zerneuere -t' erfolgreich war, wird diese
Funktion im alten Objekt aufgerufen, bevor dieses mittels destruct() 
(kein remove()!) zerstoert wird.
VERWEISE: prepare_renewal, abort_renewal
GRUPPEN: grundlegendes
*/

/*
FUNKTION: query_file_name
DEKLARATION: string query_file_name()
BESCHREIBUNG:
Falls aus dem Objekt- oder Programmnamen (via object_name bzw. program_name)
nicht der richtige Dateiname abgeleitet werden kann, so kann ein Objekt
diese Funktion definieren und damit den richten Dateinamen (inklusive Endung)
zurueckliefern. zmore, zgrep, zcd und zed nutzen diesen dann.
VERWEISE: object_name, program_name, virtual_compiler
GRUPPEN: grundlegendes, virtual_compiler
*/
