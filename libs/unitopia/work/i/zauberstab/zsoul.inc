// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zsoul.inc
// Description: Allgemeine Goetterbefehle
// Author:	Freaky (23.12.93)
// Modified:	Monty (06.07.95) 'kneble ?' ermoeglicht, das selbst-
//		kneblen und -entknebeln ermoeglicht.
//		Garthan	(11.08.96) expand_controls
//
// $Log: zsoul.inc,v $
// Revision 1.32  2012-11-16 17:53:49  gnomi
// Eval-Anzeige beim Laden.
//
// Revision 1.31  2009-07-30 16:48:36  gnomi
// entferne: Nur entfernen, wenn es ein Autoloader ist.
//
// Revision 1.30  2009-03-20 08:07:31  gnomi
// Beim zputze entfernt sich der Zauberstab zuletzt.
// Neuen Bauarbeiter nur dann setzen, wenn noch ein zu sperrender Ausgang
// uebrig blieb.
// Man kann die Hoehe und Breite des Xeditors nun auf Automatik stellen.
//
// Revision 1.29  2008/02/25 11:49:01  gnomi
// Typo.
//
// Revision 1.28  2008/01/28 13:19:38  gnomi
// Neues Sperren.
//
// Revision 1.27  2008/01/16 09:39:49  gnomi
// INPUT_PROMPT nutzen.
//
// Revision 1.26  2007/12/05 11:06:17  gnomi
// Indexing past string end.
//
// Revision 1.25  2007/08/09 22:25:10  gnomi
// Indexing past string end.
//
// Revision 1.24  2006/05/01 00:42:13  gnomi
// entferne: Fehlermeldung via notify_fail ausgeben.
//
// Revision 1.23  2005/05/06 22:59:55  gnomi
// Ueberfluessige #ifdefs entfernt.
//
// Revision 1.22  2004/11/27 21:27:15  gnomi
// add_hp-Aenderung: add_hp-Aufruf beim Blitzen angepasst.
//
// Revision 1.21  2004/04/14 22:04:10  gnomi
// zfe: Man kann zusaetzliche Gruppen anmelden, die man beobachtet.
//
// Revision 1.20  2004/02/19 21:40:45  gnomi
// Typo.
//
// Revision 1.19  2003/12/31 15:19:41  menaures
// 'unsichtbar n' funktioniert auch, wenn man schon unsichtbar war.
// Einstellung fuer Zfehler: Letzten Fehler merken.
//
// Revision 1.18  2003/11/04 03:18:42  gnomi
// Knebel kann auch Kurierkanaele sperren.
//
// Revision 1.17  2003/03/13 23:26:07  gnomi
// unsichtbar/sichtbar: Beachten, dass auch die ZVerlassen/ZAnkommen-Meldung 0
// sein kann.
//
// Revision 1.16  2003/03/05 04:38:58  gnomi
// zheile: Alkoholpegel und Kopfschmerzen auf 0 setzen.
//
// Revision 1.15  2003/02/14 03:49:12  gnomi
// Optionen fuer den xed eingebaut.
//
// Revision 1.14  2003/01/25 04:24:05  gnomi
// sperre: Himmelsrichtung entsprechend den Abkuerzungen erweitern.
//
// Revision 1.13  2002/12/17 03:54:43  gnomi
// Goetter koennen sich einstellen, dass sie ihre Fehler in die FDB haben
// wollen.
//
// Revision 1.12  2002/11/09 02:39:17  gnomi
// (Un)sichtbarkeitsmeldungen umbrechen.
//
// Revision 1.11  2002/01/11 00:24:01  gnomi
// Einstellungsmenue eingebaut.
//
// Revision 1.10  2001/05/13 21:07:43  gnomi
// Da fehlte noch ein wrap.
//
// Revision 1.9  2001/05/09 01:23:00  gnomi
// Ein paar wrap's eingebaut.
//
// Revision 1.8  2001/04/20 00:32:18  gnomi
// entferne: Objekt muss nicht unbedingt existieren.
//
// Revision 1.7  2001/03/17 18:04:25  gnomi
// ebruelle/eich: Bei saechlichen Goettern -> "Goettliches"
//
// Revision 1.6  2001/02/11 02:24:19  sissi
// Anpassung an neues Levelsystem.
//
// Revision 1.5  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strong_types
#pragma verbose_errors

private string expand_controls(string strc)
{
   int i, len;
   string str;

   if(!strc)
      return 0;

   len = strlen(strc);
   str = "";
   for(i = 0; i < len; i++)
   {
      if(strc[i] < 32)
         str += sprintf("^%c", '@'+strc[i]);
      else if(strc[i] >= 128)
         ;
      else if(strc[i] == 127)
         str += "^?";
      else
         str += strc[i..i];
   }
   return str;
}

int f_echoanalle(string str)
{
    SECURE;
    HELP_NO_PIPE("echoanalle");
    if (!str)
	FAIL("Echoanalle was?\n");
    shout(expand_controls(str)+"\n");
    write(str+"\n");
    return 1;
}

int f_echo(string str)
{
    SECURE;
    HELP_NO_PIPE("echo");
    if (!str)
	FAIL("Echo was?\n");
    say(wrap(str));
    write(wrap(str));
    return 1;
}

int f_echoan(string str)
{
    object ob;
    string who, msg;

    SECURE;
    HELP_NO_PIPE("echoan");
    if (!str || sscanf(str,"%s %s",who,msg)!=2)
	FAIL("Echoan wen was?\n");
    ob=SO(who);
    if (!ob)
	return 0;
    tell_object(ob,wrap(msg));
    write(wrap_say("Echoan "+who+":",msg));
    return 1;
}


int f_ebruelle(string str)
{
   string g;
   if(!str)
      FAIL(query_verb()+" was?\n");
   EVENT_MASTER->event("Engel", ENVTO, wrap_say (
      ((g=ENVTO->query_real_gender())=="weiblich"?"Goettin":
       (g=="saechlich")?"Goettliches":"Gott")
      +" "+ENVTO->query_real_cap_name(),
      "redet zur Engelsschar: " + str));
   write("Ok.\n");
   return 1;
}

int f_eich(string str)
{
   string g;
   if(!str)
      FAIL(query_verb()+" was?\n");
   EVENT_MASTER->event("Engel", ENVTO, wrap_say (
      ((g=ENVTO->query_real_gender())=="weiblich"?"Goettin":
       (g=="saechlich")?"Goettliches":"Gott")
      +" "+ENVTO->query_real_cap_name(),
      str));
   write("Ok.\n");
   return 1;
}

int z_bruelle(string str)
{
    string tmp, out;

    SECURE;
    HELP_NO_PIPE("zbruelle");

    if (!str)
	FAIL(query_verb()+" was?\n");

    str = "redet zum Pantheon: " + expand_controls(str);
    tmp = OWN->query_real_cap_name();
    out = sprintf("%s %=-*s\n", tmp, 78-strlen(tmp), str);

    EVENT_MASTER->event("Pantheon", ENVTO, out);
    write("Ok.\n");
    return 1;
}

int z_echo(string str)
{
    string out;

    SECURE;
    HELP_NO_PIPE("zecho");

    if (!str)
	FAIL(query_verb()+" was?\n");

    out = wrap(expand_controls(str),79);

    EVENT_MASTER->event("Pantheon", OWN, out);
    write("Ok.\n");
    return 1;
}

int z_stop(string str)
{
    object *inv;
    int i;

    SECURE;
    HELP("zstop");

    if (inv = all_inventory(ENV(OWN)))
	for (i=0;i<sizeof(inv);i++)
	    if (inv[i] && living(inv[i]))
		inv[i]->stop_all_fights();
    OWN->send_message(MT_LOOK|MT_NOISE,MA_FIGHT,Der(OWN)+" stoppt alle Kaempfe im Raum.\n");
    W("Du stoppst alle Kaempfe im Raum.\n");
    PRINT;
    return 1;
}

int z_heile(string str)
{
    object ob;

    SECURE;
    HELP("zheile");
    if (!(ob=SO(str)))
	return 0;
    if(vogtp(OWN) || ob == OWN || testplayerp(ob))
    {
	ob->set_hp(ob->query_max_hp());
	ob->set_sp(ob->query_max_sp());
	if (ob->query_wp()<30)
	    ob->set_wp(30);
	if (ob->query_fp()<30)
	    ob->set_fp(30);
	ob->set_alc(0);
	ob->set_headache(0);

	if (ob!=OWN)
	    tell_object(ob,"Du bist von "+dem(OWN)+" geheilt worden.\n");
	W("Ok.\n");
	PRINT;

	return 1;
    }
    else
        FAIL("Du kannst nur Dich heilen.\n");
}

int f_zwinge(string str)
{
    string who, what;
    object ob;

    SECURE;
    HELP("zwinge");
    if (!str || sscanf(str,"%s %s",who,what)!=2)
	FAIL(CAP(query_verb())+" wen was?\n");
    ob=SO(who);
    if (!ob)
	return 0;
    if (query_real_player_level(OWN) < query_real_player_level(ob))
    {
	W(Der(ob)+" ist weitaus maechtiger als Du.\n");
	tell_object(ob, CAP(OWN->query_real_name())+
			" wollte dich zu '"+what+"' zwingen.\n");
	PRINT;
	return 1;
    }
    tell_object(ob,Der(OWN)+" zwingt dich zu: "+what+".\n");
    ob->do_command(what);
    W("Ok.\n");
    PRINT;
    return 1;
}

int f_lade(string str)
{
    int eval;

    SECURE;
    HELP("lade");

    if (!str)
	FAIL("Lade was?\n");

    eval = get_eval_cost();
    if (touch(ADD_PATH(str),NO_LOG))
	W(sprintf("Ok (%d Evals).\n", eval - get_eval_cost()));
    PRINT;
    return 1;
}

int f_heim(string str)
{
    string tmp;
    SECURE;
    HELP("heim");
    tmp = OWN->query_home_msg();
    OWN->move("/w/"+OWN->query_real_name()+"/workroom",MOVE_MAGIC,
	tmp=OWN->query_home_msg()&&tmp!="" ? tmp : "geht nach Hause.");
    PRINT;
    return 1;
}

static int blitze2(string antwort, object *obs)
{
    int i;

    if(antwort != "j" && antwort != "J" && antwort != "ja" && antwort != "Ja")
    {
        write("Dann eben nicht.\n");
        return 0;
    }

    if(sizeof(obs)>1)
    {
	OWN->send_message(MT_LOOK|MT_NOISE,MA_UNKNOWN,Der(OWN)+" sendet ein Buendel Blitze vom Himmel.\n\n");
	write("Du sendest ein Buendel Blitze vom Himmel.\n\n");
    }
    else
    {
	OWN->send_message(MT_LOOK|MT_NOISE,MA_UNKNOWN,Der(OWN)+" sendet einen Blitz vom Himmel.\n\n");
	write("Du sendest einen Blitz vom Himmel.\n\n");
    }
    tell_room(ENV(OWN),"Ein lautes Donnern ist zu hoeren.\n\n");

    for(i = sizeof(obs); i--;)
        if(objectp(obs[i]))
	    if(living(obs[i]))
	        obs[i]->add_hp(-(obs[i]->query_hp()+1000000),
		    ([
			AH_ATTACKER: OWN,
			AH_DAMAGE_TYPE: ({ "heilig", "magie" }),
		    ]));
	    else
	        obs[i]->remove();
    return 1;
}

int f_blitze(string str)
{
    mixed *pars;
    object *obs;
    int i;

    SECURE;
    HELP("blitze");

    if (!str)
	FAIL("Blitze was?\n");

    str=LOW(str);
    if (str=="hier")
	obs=({});
    else
    {
	pars=parse_com(str,0,0,PARSE_NO_V_ITEMS);
	if (parse_com_error(pars,"Blitze wen?\n"))
	    return 0;
        obs=pars[PARSE_OBS];
    }

    if(sizeof(filter(obs, #'interactive)))
    {
        input_to("blitze2", INPUT_PROMPT,
	    "Bist Du sicher, dass Du Spieler TOETEN willst? (j/N) ",
	    obs);
    }
    else
        blitze2("j", obs);
    PRINT;
    return 1;
}

int f_hole(string str)
{
    object ob;
    int res;
    string where;

    SECURE;
    HELP("hole");
    ob=SO(str);
    if (!ob)
	return 0;

    if (wizp(ob) > wizp(OWN))
    {
	W(Der(ob)+" ist maechtiger als du und bleibt wo "+er(ob)+" ist !\n");
	tell_object(ob,CAP(OWN->query_real_name())+
		" hat vergeblich versucht, dich zu "+ihm(OWN)+" zu holen.\n");
	PRINT;
	return 1;
    }
    tell_object(ob,"\nDie Umgebung verschwimmt vor deinen Augen...\n\n");
    if (living(ob))
    {
        where = ENV(ob) ? ON(ENV(ob)) : "0";
	res=ob->move(ENV(OWN),MOVE_MAGIC);
    }
    else
    {
	res=ob->move(OWN);
	if (res!=MOVE_OK)
	    res=ob->move(ENV(OWN));
    }

    if (res!=MOVE_OK)
	W("Du kannst "+den(ob)+" nicht bewegen!\n");
    else
    {
	W("Ok.\n");
	if (objectp(ob) && query_once_interactive(ob) && !testplayerp(ob) &&
		!wizp(ob))
	    sys_log("HOLE", shorttimestr(time())+" "+
			   left(Name(OWN),10)+" "+
			   left(Name(ob), 10)+" "+
			   where+" "+
			   ON(ENV(OWN))+"\n");
    }
    PRINT;
    return 1;
}

int f_in(string str)
{
    object ob, here;
    string wo, cmd;
    int res;
    string tmp;

    SECURE;
    HELP("in");
    if (!str)
	FAIL(CAP(query_verb())+" wo was?\n");

    if (sscanf(str,"%s %s",wo,cmd) != 2)
	FAIL(CAP(query_verb())+" wo was?\n");

    if (wo == "-")
        ob = touch(OWN->query_last_room(), NO_LOG|NO_WRITE);
    else
	ob = SO(wo);
    if (!ob)
    {
        if (!(tmp = TELEPORT(wo)))
	   return 0;
        ob = touch(tmp,NO_LOG|NO_WRITE);
    }
    if (!ob)
        return 0;

    here = ENV(OWN);
    res = OWN->move(ob,MOVE_SECRET);
    if (res != MOVE_OK)
    {
	W("Kann keine Kommandos in "+wo+" ausfuehren.\n");
	PRINT;
	return 1;
    }
    OWN->do_command(cmd);
    if (!OWN)
	return 1;
    OWN->move(here,MOVE_SECRET);
    W("Ok.\n");
    PRINT;
    return 1;
}

int z_putze(string str)
{
    object ob, *inv;
    int a, myself;
    string was, id_string;

    SECURE;
    HELP("zputze");
    if (str && sscanf(str,"%s %s",was,id_string)==2)
	str=was;
    ob=SO(str);
    if (!ob)
	return 0;

    inv=all_inventory(ob);
    
    for (a=0; a<sizeof(inv); a++)
    {
	if (!inv[a] || query_once_interactive(inv[a]))
	    continue;
	if (!id_string || inv[a]->id(id_string))
	    if (!inv[a]->no_remove())
	    {
		if(inv[a] == this_object())
		    myself = 1;
		else
		    inv[a]->remove();
	    }
    }
    if(myself)
	W("Ok. Auf Wiedersehen.\n");
    else
	W("Ok.\n");
    PRINT;
    
    if(myself)
	this_object()->remove();

    return 1;
}

int f_unsichtbar(string str)
{
    int mode;

    SECURE;
    HELP("unsichtbar");
    if(!str || sscanf(str, "%d", mode) != 1)
       mode = V_INVIS;

    if (OWN->query_invis() && OWN->query_invis() == mode)
	W("Du bist bereits unsichtbar (invis=="+OWN->query_invis()+").\n");
    else
    {
	W("Du bist nun unsichtbar (invis=="+mode+").\n");

        // Meldungen nur ausgeben, wenn man vorher noch nicht Invis war
        if(!OWN->query_invis())
        {
	    if(OWN->query_msg_invis())
	        OWN->send_message(MT_LOOK,MA_MOVE_OUT,wrap(OWN->query_exp_msg_invis()));
	    else if(OWN->query_exp_mmsg_out())
	        OWN->send_message(MT_LOOK,MA_MOVE_OUT,wrap(OWN->query_exp_mmsg_out()));
        }
    }
    OWN->set_invis(mode);
    PRINT;
    return 1;
}

int f_sichtbar(string str)
{
    SECURE;
    HELP("sichtbar");
    if (!OWN->query_invis())
	W("Du bist nicht unsichtbar (invis!="+V_VIS+").\n");
    else
    {
	OWN->set_invis(V_VIS);
        W("Du bist wieder sichtbar (invis="+V_VIS+").\n");
	if(OWN->query_msg_vis())
	    OWN->send_message(MT_LOOK,MA_MOVE_IN,wrap(OWN->query_exp_msg_vis()));
	else if(OWN->query_exp_mmsg_in())
	    OWN->send_message(MT_LOOK,MA_MOVE_IN,wrap(OWN->query_exp_mmsg_in()));
    }
    PRINT;
    return 1;
}

int f_installiere(string str)
{
    object room, ob;
    string *line, parameter;

    SECURE;
    SECURE_LORD;
    HELP("installiere");

    if (!str)
	FAIL(CAP(query_verb())+" <file> \n");

    line=explode(str," ");
    if (sizeof(line)==1)
        parameter = "";
    else
    {
        parameter=implode(line[1..sizeof(line)]," ");
        str=line[0];
    }
    room = ENV(OWN);
    if (!room)
	FAIL("Du bist in keinem Raum!\n");

    if (file_size(str+".c") <= 0)
	FAIL("Diese Datei ist nicht zu finden!\n");

    ob = clone_object(str);
    if (!ob)
	FAIL("Das Objekt konnte nicht erschaffen werden!\n");

    if ((int)ob->move(room) != MOVE_OK)
	FAIL("Das Objekt konnte nicht hierher transferiert werden!\n");

    if (!room->set_autoload(ob,parameter))
	FAIL("Eintragen im Raum hat nicht geklappt.\n");

    if (parameter && parameter != "")
        ob->install_parameter(parameter);

    W("Ok.\n");
    PRINT;
    return 1;
}

int f_entferne(string str)
{
    object room, ob;
    string obj_name, name;
    int num;
    mixed *parsed;

    SECURE;
    SECURE_LORD;
    HELP("entferne");

    if (!str)
	FAIL(CAP(query_verb())+" was?\n");

    room = ENV(OWN);
    if (!room)
	FAIL("Du bist in keinem Raum!\n");

    parsed=parse_com(str,room);
    if (parse_com_error(parsed,CAP(query_verb())+" was?\n",1))
	ob=find_object(str);
    else
    {
	ob=parsed[PARSE_OBS][0];
        if (!objectp(ob))
	    FAIL("Virtuelle Objekte koennen nicht entfernt werden.\n");
    }

    if(ob)
        obj_name = ON(ob);
    else
        obj_name = str;

    if (sscanf(obj_name,"%s#%d",name,num) == 2)
	obj_name = name;

    if (!room->remove_autoload(obj_name))
    {
        // Kein Autoloader. Dafuer gibts zzerstoere...
        FAIL("Austragen aus dem Raum hat nicht geklappt.\n");
    }
    else
	W("Ok.\n");

    if(ob && clonep(ob))
    {
        ob->remove();
        if (ob)
            destruct(ob);
    }

    PRINT;
    return 1;
}

private string make_sperre(string richtung, mapping info)
{
    object room = ENV(OWN);
    object schranke = present("Schranke", room);
    string altxt;
    mapping result;
    
    if(schranke)
    {
	result = schranke->query_block_info();
	if(!result)
	    return "Die bestehende Schranke ist veraltet, bitte Raum vorher erneuern.\n";
	if (!room->remove_autoload("/obj/bauarbeiter"))
	    return "Eintragen im Raum hat nicht geklappt.\n";
	schranke->remove();
    }
    else
	result = ([:1]);

    m_add(result, richtung, info);
    altxt = save_value(result);

    schranke=clone_object("/obj/bauarbeiter");
    schranke->move(room);
    schranke->install_parameter(altxt);
    if (!room->set_autoload(schranke, altxt))
	return "Eintragen im Raum hat nicht geklappt.\n";
    else
	return "Ok.\n";
}

void f_sperre_plinfo(string *text, string dir, mapping info)
{
    if(text && sizeof(text-({""})))
	m_add(info, "plinfo", implode(text,"\n")+"\n");

    write(make_sperre(dir, info));
}

void f_sperre_wizinfo(string *text, string dir, mapping info)
{
    if(!text)
    {
	write("Abbruch.\n");
	return;
    }
    
    if(sizeof(text-({""})))
	m_add(info, "wizinfo", implode(text,"\n")+"\n");

    OWN->mini_ed(lambda(({'text}),({#'f_sperre_plinfo, 'text, dir, info})),
	0, 0,
    ([
	MINI_ED_START_TEXT:
	    "Bitte gib einen Kommentar fuer Spieler ein.\n"
	    "Mit '.' beenden, mit '~q' kein Kommentar.\n"
    ]));
}

void f_sperre_typ(string str, string dir, mapping info)
{
    str = lower_case(space(str||""));
    
    if(str=="0" || str=="q" || str=="~q")
    {
	write("Abbruch.\n");
	return;
    }
    else if(str=="1" || str=="" || strstr(str,"rot")>=0)
	m_add(info, "typ", 1);
    else if(str=="2" || strstr(str,"gruen")>=0)
	m_add(info, "typ", 2);
    else
    {
	input_to(#'f_sperre_typ, INPUT_PROMPT,
	    "Welcher Typ (0: Abbruch, 1: rotweiss, 2:gruenweiss)? ",
	    dir, info);
	return;
    }
    
    OWN->mini_ed(lambda(({'text}),({#'f_sperre_wizinfo, 'text, dir, info})),
	0, 0,
    ([
	MINI_ED_START_TEXT:
	    "Bitte gib den Kommentar fuer andere Goetter ein.\n"
	    "Mit '.' beenden, mit '~q' abbrechen.\n"
    ]));

    return;
}

int f_sperre(string str)
{
    string *s,dir,kommentar;
    object ob, room;
    mapping info;

    SECURE;
    HELP("sperre");

    room=ENV(OWN);
    if (!room)
	FAIL("Du bist in keinem Raum.\n");

    if (!str)
	FAIL(CAP(query_verb())+" welche Richtung ab?\n");

    s = explode(str," ");
    dir = expand_direction(s[0],DIR_ALS_DEFAULT);

    if (!(string)room->query_one_exit(s[0]))
	FAIL("Diesen Ausgang gibt es hier nicht.\n");
	
    if (sizeof(s) > 1)
        kommentar = implode(s[1..<1]," ");

    info = ([ "wiz": capitalize(OWN->query_real_name()),
	      "time": time(),
	   ]);
    	
    if(!kommentar)
    {
	// Nix.
    }
    else if(lower_case(kommentar) == "ab")
    {
	PRINT;
	input_to(#'f_sperre_typ, INPUT_PROMPT,
	    "Welcher Typ (0: Abbruch, 1: rotweiss, 2:gruenweiss)? ",
	    dir, info);
	return 1;
    }
    else
    {
	m_add(info, "wizinfo", kommentar);
    }
    
    m_add(info, "typ", 1);
    
    W(make_sperre(dir, info));
    PRINT;
    return 1;
}

int f_entsperre(string str)
{
    object ob, room;
    mapping infos;
    string dir;

    SECURE;
    HELP("entsperre");

    room=ENV(OWN);
    if (!room)
	FAIL("Du bist in keinem Raum.\n");

    ob=present("Schranke",room);// Koennte das nicht Probleme geben?
    if (!ob)
        FAIL("Hier ist keine Schranke.\n");

    if (!str)
    {
	if (!room->remove_autoload("/obj/bauarbeiter"))
	    W("Entfernen aus dem Raum hat nicht geklappt.\n");
	else
	    W("Ok.\n");
	ob->remove();
	PRINT;
	return 1;
    }
    
    dir = expand_direction(str,DIR_ALS_DEFAULT);
    
    infos = ob->query_block_info();
    if(!infos)
    {
	W("Die bestehende Schranke ist veraltet, bitte Raum vorher erneuern.\n");
	PRINT;
	return 1;
    }
    
    if(!member(infos, dir))
    {
	W("Dieser Ausgang ist nicht gesperrt.\n");
	PRINT;
	return 1;
    }
    
    if (!room->remove_autoload("/obj/bauarbeiter"))
	W("Entfernen aus dem Raum hat nicht geklappt.\n");
    ob->remove();
    
    m_delete(infos, dir);
    
    if(sizeof(infos))
    {
	string altxt = save_value(infos);

	ob=clone_object("/obj/bauarbeiter");
	ob->move(room);
	ob->install_parameter(altxt);
	if (!room->set_autoload(ob, altxt))
	    W("Eintragen im Raum hat nicht geklappt.\n");
	else
	    W("Ok.\n");
    }
    else
	W("Ok.\n");

    PRINT;
    return 1;
}

#define PATH "/obj/knebel_shadow"
 
int identify_option(string s)
{
    int i,j;
    string opt;
    mapping event_liste;
    mixed nr;

    for (i=0;opt=(string)PATH->query_option(i);++i) {
        for (j=0;opt[j]<'a';++j);
        if (strlen(s)>=j
            && LOW(s[0..j-1])==LOW(opt[0..j-1]) )
            return i;
        }
	
    // Schauen wir mal, ob es ein Kurierkanal ist.
    s = lower_case(s);
    if(!strstr(s,"kurier"))
	s = s[6..<1];
    else if(!strstr(s,"k"))
	s = s[1..<1];
    else
	nr = capitalize(s);
    if(!nr)
	sscanf(s,"%d",nr) || nr=capitalize(s);
    nr=EVENT_MASTER->get_event_index(nr);
    if(nr>=0)
	return 100+nr;
    return -1;
}

int f_kneble(string str)
{
    string opt;
    object player,knebel;
    string *args;
    int i;
    int pm,option_number;
    string msg;

    SECURE;
    HELP("kneble");

    if (!str||str=="")
    {
        write("kneble [<person> [(+|-)<option> [<meldung>]]]\n");
        write("<option> := ");
        write((string)PATH->query_option(0));
        for (i=1;opt=(string)PATH->query_option(i);++i)
            write("|"+opt);
	write("|\n            kurier<nr>|k<nr>|<kanalname>\n");
        return 1;
    }

    args=explode(str," ");
    if (!sizeof(args)) return 1;

    if (!(player=find_player(LOW(args[0]))))
    {
        write("Spieler "+args[0]+" nicht gefunden.\n");
        return 1;
    }

    if (query_real_player_level(OWN) <= query_real_player_level(player) &&
	player != OWN)
    {
        write("Dazu bist Du nicht maechtig genug!\n");
        return 1;
    }

    if (sizeof(args)>1)
    {
        pm=args[1][0];
        if (pm!='+'&&pm!='-')
	{
            write("Option muss mit '+' oder '-' beginnen.\n");
            return 1;
	}
        if ((option_number=identify_option(args[1][1..<1]))<0)
	{
            write("Option '"+args[1]+"' nicht erkannt.\n");
            return 1;
	}
        if (sizeof(args)>2)
	    msg=implode(args[2..sizeof(args)-1]," ");
        else
	    msg=0;

        if (!(player->query_knebel_exists()))
	{
            knebel=clone_object(PATH);
            knebel->attach(player);
	}

        if (pm=='+')
	    player->set_forbid(option_number,msg,
	        CAP((string)OWN->query_real_name()));
        else
	    player->clear_forbid(option_number);
    }

    if (player->query_knebel_exists())
    {
	foreach(int f: player->query_forbids())
	{
    	    msg=(string)player->query_forbid(f);
            if (msg) write((PATH->query_option(f)||f)+": "+msg+"\n");
	}
    }
    else
    	write("Kein Knebel angelegt.\n");

    return 1;
}

private varargs void print_zauberstab_options(int quiet)
{
    mapping eopts = this_player()->query_editor_options();
    string str;
    
    this_player()->more(({
" Zauberstab:",
"  ["+((params["zfe-s"]) ?" ":"*")+"] (L)eere Bereiche in der FDB anzeigen",
"  ["+((params["zfe-g"]) ?"*":" ")+"] Zuletzt (g)elesenen Fehler merken",
"  ["+(params["own-rtes"]?"*":" ")+"] (E)igene RTEs immer (ausser zlpc) in der FDB speichern",
"   -  Ab "+query_max_output()+" Zeilen wird (m)ore genutzt.",
    }) + (explode(sprintf(
"   -  Folgende Fe(h)lergruppen beobachten: %-=36s\n",
	    strlen(str=implode(sort_array(unmkmapping(params["zfe-groups"])[0],#'>),", "))?str:("_"*35)
	),"\n")[0..<2]) + ({
"      (Hinzufuegen: h+ <gruppe>, Entfernen: h- <gruppe>, Setzen: h <gruppen>)",
"",
" Variablen- und Ergebnisanzeige:",
"  ("+(params["print"]=="none"?"*":" ")+") Mit mixed2str (o)hne Umbrueche",
"  ("+((params["print"]!="none"&&params["print"]!="printf")?"*":" ")+") Mit mixed2str m(i)t Umbruechen",
"  ("+(params["print"]=="printf"?"*":" ")+") Mit (p)rintf(\"%O\", wert)",
"",
" Einstellungen des X-Editors:",
sprintf("   -  Zeilen(b)reite:          %4s       [%s] Ein(f)uegemodus",     eopts["max_x"]?to_string(eopts["max_x"]):"auto", eopts["insert"]?"X":" "),
sprintf("   -  Gesamte Zeilen(a)nzahl:  %4s       [%s] Po(s)ition anzeigen", eopts["max_y"]?to_string(eopts["max_y"]):"auto", eopts["show_pos"]?"X":" "),
sprintf("   -  Anzahl der MUD-Zeile(n): %4d       [%s] Bac(k)ups anfertigen", eopts["split_y"], eopts["backup"]?"X":" "),
sprintf("   -  (T)abulatorweite:        %4d",eopts["tab_width"]),
	}),
	({ "Zauberstabeinstellungen [q,z,?] ",
	   "----------- Einstellungen: ----------------------------------------------------",
	   "-------------------------------------------------------------------------------",
	   "...--------------------------------------------------------------------- (MORE)",
	   "...--------------------------------------------------------------------- (MORE)"
	}), 0, M_DO_NOT_END|M_FRAME|(quiet?M_NO_FIRST_SCREEN:0),
	"Options");
}

private varargs int handle_editor_options_number(string optname, string prompt, string str, int auto, int again)
{
    if(strlen(str))
    {
	int nr;
	if(sizeof(str) && !strstr("automatisch", str))
	{
	    this_player()->set_editor_options(m_add(
		this_player()->query_editor_options(),
		optname, 0));
	}
	else if(sscanf(str,"%d",nr) && nr>=0)
	{
	    this_player()->set_editor_options(m_add(
		this_player()->query_editor_options(),
		optname, nr));
	}
	else
	{
	    write("Du musst schon eine nicht negative Zahl angeben.\n");
	    return NOTHING;
	}
    }
    else if(!again)
    {
	input_to(
	    (:
		if(handle_editor_options_number($2, $3, $1, $4, 1) == NOTHING)
		    print_zauberstab_options();
	    :), INPUT_PROMPT, prompt, optname, prompt, auto);
	return END_MORE;
    }

    print_zauberstab_options();
    return END_MORE;
}

private int handle_zauberstab_options(string str)
{
    if(!strlen(str))
        return CONTINUE;

    if(strlen(str)>1 && member("hH",str[0])>=0 && member("+-",str[1])>=0)
	str = str[0..0] + " " + str[1..<1];

    if(strlen(str)==1 || str[1]==' ')
    {
	mapping eopts;
	int c = lower_case(str)[0];
	str = trim(str[2..<1]);
	switch(c)
	{
	    case 'l':
                set_param("zfe-s", !params["zfe-s"]);
		break;
            case 'g':
                set_param("zfe-g", !params["zfe-g"]);
                break;
	    case 'e':
		set_param("own-rtes", !params["own-rtes"]);
		break;
	    case 'm':
		if(strlen(str))
		{
		    int nr;
		    if(sscanf(str,"%d",nr) && nr>=0)
		    {
			set_param("max-out", nr);
			break;
		    }
		    else
		    {
			write("Du musst schon eine nicht negative Zahl angeben.\n");
			return NOTHING;
		    }
		}
		else
		{
		    input_to(
			(:
			    int nr;
			    if($1 && sscanf($1,"%d",nr) && nr>=0)
				set_param("max-out", nr);
			    print_zauberstab_options();
			:), INPUT_PROMPT,
			"Ab wieviel Zeilen soll more genutzt werden? ");
		    return END_MORE;
		}
	    case 'h':
		{
		    int last = 1;
		    if(sizeof(str) && member("+-", str[0])<0)
			set_param("zfe-groups", ([]));
			
		    foreach(string name: regexplode(str,"[ ,;]")-({""," ",",",";"}))
		    {
			if(member("+-", name[0])>=0)
			{
			    last = (name[0]=='+');
			    name = trim(name[1..<1]);
			}
			if(!strlen(name))
			    continue;
			else if(last)
			    set_param("zfe-groups", params["zfe-groups"]+([name]));
			else
			    set_param("zfe-groups", params["zfe-groups"]-([name]));
		    }
		}
		break;
	    case 'o':
		set_param("print","none");
		break;
	    case 'i':
		set_param("print","array");
		break;
	    case 'p':
		set_param("print","printf");
		break;
	    case 'b':
		return handle_editor_options_number("max_x",
		    "Wieviele Spalten soll der Xeditor nutzen? ", str, 1);
	    case 'a':
		return handle_editor_options_number("max_y",
		    "Wieviele Zeilen darf der Xeditor insgesamt nutzen? ", str, 1);
	    case 'n':
		return handle_editor_options_number("split_y",
		    "Wieviele Zeilen von der MUD-Ausgabe soll der Xeditor anzeigen? ",
		    str);
	    case 't':
		return handle_editor_options_number("tab_width",
		    "Welche Tabulatorweite moechtest Du? ",
		    str);
	    case 'f':
		eopts = this_player()->query_editor_options();
		eopts["insert"] = !eopts["insert"];
		this_player()->set_editor_options(eopts);
		break;
	    case 's':
		eopts = this_player()->query_editor_options();
		eopts["show_pos"] = !eopts["show_pos"];
		this_player()->set_editor_options(eopts);
		break;
	    case 'k':
		eopts = this_player()->query_editor_options();
		eopts["backup"] = !eopts["backup"];
		this_player()->set_editor_options(eopts);
		break;
	    case 'q':
		return END_MORE;
	    case 'z':
		this_player()->start_options_menue();
		return END_MORE;
	    case '?':
		this_player()->print_options_help(0, "Zauberstab", str,
		    #'print_zauberstab_options, 0);
		return END_MORE;
	    default:
		return CONTINUE;
	}
	print_zauberstab_options();
	return END_MORE;
    }
}
