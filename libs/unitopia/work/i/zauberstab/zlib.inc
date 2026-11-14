// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zlib.inc
// Description: Libary-Funktionen des Zauberstabes
// Author:	Freaky (23.12.93)
//
// $Log: zlib.inc,v $
// Revision 1.31  2009-04-28 09:44:02  gnomi
// Fehler in str2mixed (Indizierung uebers Stringende hinaus).
//
// Revision 1.30  2008-05-19 14:27:45  gnomi
// clone/destruct_msg: $Der()/$Ein() ohne Parameter sind jetzt
// TP und nicht der Zauberstab.
//
// Revision 1.29  2008/01/21 14:15:44  gnomi
// notify_ed_enter/exit mit zusaetzlichem Parameter aufrufen.
//
// Revision 1.28  2008/01/16 09:38:56  gnomi
// Eval-Beschraenkungen beim Laden von Plugins.
// ed: Doppelten Aufruf verhindern.
//
// Revision 1.27  2007/09/20 14:58:49  gnomi
// Private Gruppen in der FDB.
//
// Revision 1.26  2007/08/12 00:48:53  gnomi
// Bei ED-Start/Ende notify_ed_enter/exit aufrufen.
//
// Revision 1.25  2007/08/06 13:44:26  menaures
// zsqlite
//
// Revision 1.24  2007/05/26 22:54:39  gnomi
// Indexing past string end.
//
// Revision 1.23  2007/02/14 18:40:01  gnomi
// Indexing past string end.
//
// Revision 1.22  2005/10/20 19:33:57  gnomi
// Indexing past string end.
//
// Revision 1.21  2005/06/03 20:00:47  menaures
// Ungueltigen Eintrag "inhalt" raus.
//
// Revision 1.20  2004/07/25 00:01:38  gnomi
// str2mixed erkennt jetzt auch "([])".
//
// Revision 1.19  2004/04/19 22:13:27  gnomi
// Security-Check verbessert.
//
// Revision 1.18  2004/04/14 22:04:10  gnomi
// zfe: Man kann zusaetzliche Gruppen anmelden, die man beobachtet.
//
// Revision 1.17  2003/12/31 15:20:02  menaures
// Einstellung "zfe-g"
//
// Revision 1.16  2003/08/16 22:09:02  gnomi
// Sicherheitscheck mittels /i/tools/security durchfuehren.
//
// Revision 1.15  2002/12/17 03:54:43  gnomi
// Goetter koennen sich einstellen, dass sie ihre Fehler in die FDB haben
// wollen.
//
// Revision 1.14  2002/04/03 06:44:43  gnomi
// str2mixed: Nicht sofort trim() anwenden, sondern nur da, wo noetig. (Damit
// keine Leerzeichen aus Strings entfernt werden.)
//
// Revision 1.13  2002/03/09 04:35:23  gnomi
// Bugfix im str2mixed.
//
// Revision 1.12  2002/02/24 03:16:33  gnomi
// 'zerneure'-Befehl neu strukturiert und die Option '-t' hinzugefuegt.
//
// Revision 1.11  2001/12/02 00:18:39  gnomi
// convert_string: Die ^A (einzelnes Zeichen mit ASCII-Code 1 im Quelltext)
// durch \1 (Zwei Klartext-Zeichen) ersetzt. implode(explodde(..),..) durch
// regreplace(...) ersetzt.
//
// Revision 1.10  2001/06/28 22:34:50  freaky
// typo gefixed
//
// Revision 1.9  2001/06/28 22:25:36  freaky
// variablen koennen nur noch Objekte mit korrekter UID abgefragt werden.
// zlpc bekommt jetzt eine 'echte' UID.
//
// Revision 1.8  2001/03/24 23:46:15  gnomi
// zetup ptitel eingefuehrt.
//
// Revision 1.7  2001/03/08 19:02:44  gnomi
// Bei zern -a, -A, -as, -As den load_name auch beachten, da dieser bei
// VC/Map-Raeumen mit einem Blueprint, welches replace_program nutzt, nicht
// beachtet wird.
//
// Revision 1.6  2001/03/05 00:37:49  sissi
// volk Befehl innerhalb von Kuerzeln erlaubt, wodurch er fuer das login-
// Kuerzel ein idealer Kandidat geworden ist.
//
// Revision 1.5  2001/02/14 02:37:27  gnomi
// Neue Option -w und -H. Format der vordefinierten Formatierungen geaendert.
// Ein paar neue Felder fuer den volk-Befehl.
//
// Revision 1.4  2001/02/11 16:03:41  freaky
// check_invis geaendert.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strong_types

string check_invis(int i, string str) {
    if (i==V_VIS)
	return str;
    if (i==V_INVIS)
	return "("+str+")";
    if (i==V_HIDDEN)
	return "["+str+"]";
    if (i==V_SHIMMER)
        return "<"+str+">";
    if (i==V_NOLIST)
	return "{"+str+"}";

    if (i & V_ATOM_NOLIST)
	str="{"+str+"}";
    if (i & V_ATOM_HIDDEN)
	str="["+str+"]";
    if (i & V_ATOM_INVIS)
	str="("+str+")";
    if (i & V_ATOM_NOSHIMMER)
	str="<"+str+">";
    /*
    if (i & V_ATOM_INVIS && !(i & V_ATOM_NOSHIMMER))
	str="("+str+")";
    */
    return "|"+str+"|";
}

int secure(string verb, string str)
{
    if(this_player()==owner &&
       geteuid(this_object())==geteuid(owner) && 
       check_security())
	return 0;
#if 0
    // volk in tue - Kuerzeln erlauben
    if (verb == "volk" && !TI && environment()
        && previous_object()==environment() && this_player()==environment())
        return 0;
    if (TI==OWN && previous_object() && geteuid(previous_object())==geteuid())
	return 0;
#endif
    tell_object(OWN,"ACHTUNG!!!!!!!\n"+Name(TI)+" wollte dich zu:\n"+
	verb+" "+str+"\nzwingen.\n");
    tell_object(OWN,"TI:"+(TI?OFN(TI):"0")+" "+Name(TI)+"\n");
    tell_object(OWN,"TP:"+(TP?OFN(TP):"0")+" "+Name(TP)+"\n");
    tell_object(OWN,"PO:"+OFN(previous_object())+" "+
	Name(previous_object())+"\n");
    return 1;
}

int secure_call()
{
    if (this_interactive() && previous_object() &&
	    this_interactive() == this_player() &&
	    geteuid(previous_object()) == geteuid(this_interactive()) &&
	    geteuid(previous_object()) == geteuid())
	return 1;
    return 0;
}

mixed query_variable(string str)
{
#if 0
    if (secure_call())
#else
    if (check_security())
#endif
	return vars[str];
}

private varargs mixed *get_com1(string str, int flag) {
    string par, obst;

    if (!str)
	return ({"",SO(MARK_ICON)});
    if (sscanf(str,"-%s %s",par,obst)==2)
	return ({par,flag?VSO(obst):SO(obst)});
    if (sscanf(str,"-%s",par))
	return ({par,SO(MARK_ICON)});
    return ({"",flag?VSO(str):SO(str)});
}

private string convert_string(string str) {
    str=regreplace(str,"\\\\\\\\","\1",1);  /* wegen \ */
    str=regreplace(str,"\\\\\"","\"",1);  /* wegen Hochkommas */
    str=regreplace(str,"\\\\a","\a",1);   /* wegen ^G */
    str=regreplace(str,"\\\\b","\b",1);   /* wegen BS */
    str=regreplace(str,"\\\\e","\e",1);   /* wegen ESC */
    str=regreplace(str,"\\\\f","\f",1);   /* wegen FF */
    str=regreplace(str,"\\\\n","\n",1);   /* wegen Zeilenumbruch */
    str=regreplace(str,"\\\\r","\r",1);   /* wegen CR */
    str=regreplace(str,"\\\\t","\t",1);   /* wegen Tabs */
    return regreplace(str,"\1","\\",1); /* wegen \ */
}

mixed *str2mixed(string str) {
    string *all, sub, test;
    int i, j, jj;
    mixed *end;

    if (!str)
	FAIL("Kein Argument uebergeben!\n");

    end=({});
    if (str=="")
	return end;
    all=explode(str,",");
    if (!sizeof(all))
	FAIL("Fehler im Argument '"+str+"'\n");

    for (i=0; i<sizeof(all); i++) { // Achtung! Zaehler i wird noch veraendert!
	sub=all[i];
	for(j=0;strlen(sub)>j && sub[j]==' ';j++);
	sub=sub[j..<1];
	if (sub=="") {					/* leer */
	    string fal="";
	    if (i>0)
		fal=all[i-1];
	    fal+=","+all[i];
	    if (sizeof(all)>i+1)
		fal+=","+all[i+1];
	    FAIL("Ein Komma zuviel: '"+fal+"'\n");
	    }
	else if (sscanf(sub,"%d.%d%s",j,jj,test)>=2)		/* Float */
	    if (jj>=0 && !strlen(test && trim(test)))
		end+=({ to_float(sub) });
	    else
		FAIL("Fehler im Argument: '"+sub+"'\n");
	else if (sscanf(sub,"%d%s",j,test))			/* Integer */
	    if (!strlen(test && trim(test)))
		end+=({j});
	    else
		FAIL("Fehler im Argument: '"+sub+"'\n");
	else if (sub[0]=='\"') {			/* String */
		string tmp, ttmp;
		tmp=sub[1..];
		ttmp = trim(tmp);
		
		while (sizeof(all)>(i+1) &&
			(!sizeof(ttmp) || ttmp[<1]!='\"' || (sizeof(ttmp)>1 && ttmp[<2]=='\\')) ) {
		    i++;
		    tmp+=","+all[i];
		    ttmp = trim(tmp);
		    }
		if ((i+1)>=sizeof(all) &&
			(!sizeof(ttmp) || ttmp[<1]!='\"'))
		    FAIL("Fehler im Argument: '"+tmp+ "' (es fehlt ein \")\n");
		for(j=1;tmp[<j]!='\"';j++);
		end+=({convert_string(tmp[0..<(j+1)])});
		}
	else if (sub[0..0]==MARK_ICON && ((j=(sub+"0")[1]-'0')>=0) && j<10)
							/* Markierung */
		end+=({OWN->query_mark(j)});
	else if (sub[0..3]=="OBJ(") {			/* Objekt */
		object ob;
		sub = trim(sub);
                if (sub[<1]!=')')
		    FAIL("Fehler im Argument: '"+sub+"' Es fehlt ')'\n");
		ob=SO(sub[4..<2]);
		if (!ob)
		    return 0;
		end+=({ob});
		}
	else if (sub[0..3]=="VAR(") {			/* Variable */
		sub = trim(sub);
		if (sub[<1]!=')')
		    FAIL("Fehler im Argument: '"+sub+"' Es fehlt ')'\n");
		end+=({vars[sub[4..<2]]});
		}
	else if (sub[0..1]=="([") {			/* Mapping */
		string *va, ts;
		mixed index, value;
		mapping map;

		ts=sub[2..];
		map=([]);
		j=0;
		do {
		    if (trim(ts)[<2..]=="])") {
			j=1;
			ts=trim(ts)[0..<3];
			if(ts=="")
			    break;
			}
		    else if (ts=="")
			FAIL("Da ist ein Komma zuviel bei '"+
						all[i-1]+","+all[i]+"'\n");
		    /* Suche Index und Value */
		    va=explode(ts,":");
		    if (sizeof(va)!=2)
			FAIL("Das Argument '"+ts+
					"' ist mir zu kompliziert :(\n");
		    if (!(index=str2mixed(va[0])))
			return 0;
		    if (!(value=str2mixed(va[1])))
			return 0;
		    map[index[0]]=value[0];
		    if (!j) {
			i++;
		    	ts=all[i];
			if (trim(ts)=="])")
			    j=1;
			}
		    } while(!j);
		end+=({map});
		}
	else if (sub[0..1]=="({") {			/* Array */
		string tst;
                int k,l,m;
		mixed *tend;

		tst="";
		do {
		    tst+=","+all[i];
		    l=0;
		    m=strlen(all[i])-1;
		    while (l<strlen(all[i])) {
			if (all[i][l..l+1]=="({") { k++; l+=2; }
			else if(all[i][l]==' ')   l++;
			else break;
		    }
		    while (m>0) {
			if (all[i][m-1..m]=="})") { k--; m-=2; }
			else if(all[i][m]==' ') m--;
			else break;
		    }
		    i++;
		    if (i>=sizeof(all) && k>0)
		       FAIL("Fehler im Argument: '"+all[i-1]+
				   "' (es fehlt ein '})' )\n");
		    if (k<0)
		       FAIL("Fehler im Argument: '"+all[i-1]+
				   "' (es ist ein '})' zuviel)\n");
		    }
		while (k>0);

		tst = trim(trim(tst)[3..<3]);
		if (sizeof(tst) && tst[<1]==',')
		    tend=str2mixed(tst[0..<2]);
		else
		    tend=str2mixed(tst);
		if (!tend)
		    return 0;  /* Fehler */
		end+=({tend});
		i--; // damit die FOR-Schleife an der richtigen Stelle weitermacht
	}
	else						/* alles andere */
	    FAIL("Fehler im Argument: '"+sub+"'\n");
	}
    return end;
}

private string add_plugin(string file, mixed args);

static int set_param(string was, mixed par)
{
    string msg;

    switch (lower_case(was))
    {
	case "prompt":	OWN->set_prompt_string(par||"> ");
			return 1;
	case "print":   params[was]=par||"array";
			OWN->set_zauberstab_info(params);
			return 1;
	case "zeilen":	OWN->set_more_chunk(to_int(par));
			return 1;
	case "max-out":	params[was]=to_int(par);
			set_max_output(to_int(par));
			OWN->set_zauberstab_info(params);
			return 1;
	case "ankommen": OWN->set_msg_in(par);
			 return 1;
	case "verlassen": OWN->set_msg_out(par);
			  return 1;
	case "zankommen": OWN->set_mmsg_in(par);
			  return 1;
	case "zverlassen": OWN->set_mmsg_out(par);
			   return 1;
	case "unsichtbar": OWN->set_msg_invis(par);
			   return 1;
	case "sichtbar": OWN->set_msg_vis(par);
			 return 1;
	case "clone_msg" : OWN->set_clone_msg(par);
			   c_clone_msg = mixed_to_closure(
			      add_dot_to_msg(par),({'ob}),1);
			   return 1;
	case "destruct_msg" : OWN->set_destruct_msg(par);
			      c_destruct_msg = mixed_to_closure(
			         add_dot_to_msg(par),({'ob}),1);
			   return 1;
	case "home_msg"  : OWN->set_home_msg(par);
			   return 1;
	case "titel":	OWN->set_title(par||"");
			return 1;
	case "ptitel":
	case "pt":
	case "personal_title":
			OWN->set_personal_title(par);
			return 1;
	case "ansehen": OWN->set_align_title(par);
			return 1;
	case "file":	OWN->set_eye_option("file",par=="an");
			return 1;
	case "wer-liste": OWN->set_no_wer(par && lower_case(par)=="nein");
			  return 1;
	case "last-init":
	case "volk":
	case "own-rtes":
	case "zfe-groups":
        case "zfe-g":
	case "zfe-s":
	case "zfe-privgroups":
        case "zsqlite":
                      params[was]=par;
	              OWN->set_zauberstab_info(params);
		      return 1;
	case "fingertext": if (!par) {
			  OWN->set_finger_info(0);
			  return 1;
			}
			if(strlen(par) > 500)
			  FAIL("Mehr als 500 Zeichen sind nicht erlaubt.\n");
			OWN->set_finger_info(implode(explode(par,"\\n"),"\n"));
			return 1;
	case "plugins":
	{
	    int num = sizeof(par);
	    foreach(string pl : par)
		catch((msg = add_plugin(pl,par[pl])) && write(msg); reserve (get_eval_cost()-25000)/num*(--num)+10000);
	    return 1;
	}
	default: FAIL("Parameter "+was+" gibt es nicht.\n");
    }
}

private varargs void own_ed(string file, string func)
{
    if(query_editing(OWN))
    {
	write("Du editierst bereits eine Datei.\n");
	return;
    }
    
    ed_func = func;
    OWN->notify_ed_enter(1);
    ed(file,"ed_ends");
}

static void ed_ends()
{
    object ob;
    closure c;

    OWN->notify_ed_exit(1);

    if (ed_func && c = symbol_function(ed_func,TO))
	funcall(c);
}

/*
 * Eigene left() Funktion, da im Zauberstab maximal 80 Zeichen ausgegeben 
 * werden und dann auch nur mit Spaces aufgefuellt wird
 * (ist schneller als die left()-Funktion in /secure/simul_efun)
 */
string left(string str, int len) {
    return (str+"                                                                                  ")[0..len-1];
}
