// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/search_object.inc
// Description: search_object sucht Objekt ueber Objektstring
// Author:	Freaky
// Modified by: Parsec (15.05.98)  flag == 4 eingefuehrt
// 		Freaky (01.06.1998) present() eingebaut
//		Freaky (15.02.1999) Bugfix bei 'obj:1:2'
//
// $Log: search_object.inc,v $
// Revision 1.14  2009-03-20 08:23:14  gnomi
// Bei SO_ENV_FIRST zuerst auch mit present() im Raum pruefen und dann
// im Player.
//
// Revision 1.13  2009-01-15 09:22:33  gnomi
// search_object findet nun auch Plugins.
//
// Revision 1.12  2007/05/26 23:10:53  gnomi
// Komischer Fehler.
//
// Revision 1.11  2005/03/17 18:35:31  menaures
// Den Flags mal Namen gegeben, Dokumentation angepasst
//
// Revision 1.10  2005/02/06 03:32:17  gnomi
// Fehler bei V-Items abfangen.
//
// Revision 1.9  2004/08/05 21:35:18  gnomi
// Kennt jetzt auch Raumausgaenge.
//
// Revision 1.8  2002/02/22 03:10:10  gnomi
// Nach einem set_this_object die simul_efun clone_object per funcall statt
// direkt aufrufen.
//
// Revision 1.7  2002/01/23 10:11:13  gnomi
// Virtuelle Objekte -> virtuelle Gegenstaende.
//
// Revision 1.6  2001/05/19 00:28:08  gnomi
// find_object nur dann nutzen, wenn String mit / beginnt. Ansonsten ueber
// add_path.
//
// Revision 1.5  2001/01/23 22:44:55  gnomi
// Kleiner Tweak ;-)
// (Bei einem deep_present i als Index fuer strs anstatt 0 nehmen.)
//
// Revision 1.4  2001/01/17 22:49:06  gnomi
// Bugfix bei :id (es wurde strs[0] anstatt strs[i] genommen.)
// :*: eingefuehrt fuer Suche im deep_inventory.
//

#pragma strict_types
#pragma save_types

#define FAIL(x) return notify_fail(x)

/*
FUNKTION: search_object
DEKLARATION: mixed search_object(string objekt_string [,int flag] )
BESCHREIBUNG:
Sucht ein Objekt ueber den angegebenen Objektstring. Damit kann man in
eigenen Goettertools, Plugins usw. die vom Zauberstab gewohnte Syntax
zur Angabe von Objekten benutzen.

Infos zum Objektstring siehe /doc/hilfe/goetter/zauberstab/objektstring.

Mit dem optionalen Flag kann man beeinflussen, was wie gesucht wird:

    SO_V_ITEM    (1)    Auch nach V-Items suchen
    SO_DONT_LOAD (2)    Objekt in der Zauberstab-Markierung nicht laden
    SO_ENV_FIRST (4)    Zuerst in der Umgebung suchen, dann im Player.
                        (Diese Reihenfolge ist bei den Spielern ueblich.)

Diese Flags kann man mit dem Operator | verknuepfen.
Die Defines stammen aus /sys/simul_efuns.h
GRUPPEN: simul_efun, objekt
VERWEISE: 
*/
varargs mixed search_object(string str, int flag)
{
    mixed *parsed, ob, ob2;
    string *strs, typ, obst, mark_str;
    object me;
    int i, nr;

    if (!str || str == "")
	str = "@";

    strs = explode(str,":") - ({""});
    if (sizeof(strs) <= 0)
	FAIL("Fehler im Objekt-String.\n");

    if (this_player())
	ob2 = ({object})this_player()->query_mark(0);

    /* Finde das Anfangs-Objekt */

    if (sscanf(strs[0],"%s|%s",typ,obst) == 2)  /*** Typen-Objekt ***/
	switch(lower_case(typ))
	{
	  case "s":
	    ob = find_player(obst);
	    if (!ob)
		ob = find_player(lower_case(obst));
	    if (!ob)
		FAIL("Spieler " + obst + " nicht gefunden.\n");
	    break;
	  case "l":
	    ob = find_living(obst);
	    if (!ob)
		ob = find_living(lower_case(obst));
	    if (!ob)
		FAIL("Lebewesen " + obst + " nicht gefunden.\n");
	    break;
	  case "o":
	    ob = find_object(obst);
	    if (!ob)
		FAIL("Objekt " + obst + " nicht gefunden.\n");
	    break;
	  case "t":
	    ob = touch(this_player()->add_path(obst),NO_LOG);
	    if (!ob)
		FAIL("");
	    break;
	  case "c":
	    if (!touch(this_player()->add_path(obst),NO_LOG))
		FAIL("");
	    me = this_object();
	    set_this_object(previous_object());
	    ob = funcall(symbol_function("clone_object"),({string})this_player()->add_path(obst));
	    set_this_object(me);
	    if (!ob)
		FAIL("Das Objekt hat sich im create() zerstoert.\n");
	    break;
          default:
	    FAIL("Typ '" + typ + "' kenne ich nicht.\n");
	}
    else if (strs[0][0] == '@') /*** Markierung ***/
    {
	if (!this_player())
	    FAIL("Kann keine Markierungen holen.\n");
	if (strs[0] == "@") 
	    nr = 0;
	else 
            if (!sscanf(strs[0][1..],"%d",nr) || nr < 0 || nr > 9)
		FAIL("Markierung " + strs[0] + " kenne ich nicht.\n");
	ob = ({object})this_player()->query_mark(nr);
	if (!ob)
	{
	    mark_str = ({string})this_player()->query_mark(nr,1);
	    if (!mark_str)
		FAIL("In Markierung @" + nr + " ist nichts markiert.\n");
	    ob = find_object(mark_str);
	    if (ob)
	    	this_player()->set_mark(nr,ob);
	    else if (!(flag & SO_DONT_LOAD))
	    {
		int junk;
		string st;
		if (sscanf(mark_str,"%s#%d",st,junk) != 2)
		    ob = touch(mark_str,NO_LOG);
		if (!ob)
		    FAIL("In Markierung @" + nr + " ist nichts markiert.\n");
		this_player()->set_mark(nr,ob);
	    }
	    else
		FAIL("In Markierung @" + nr + " ist nichts markiert.\n");
	}
    }
    else if (!str2int(strs[0],&nr)) /*** Objekt Nr. ***/
    {
        if (!ob2)
	    FAIL("In Markierung @0 ist nichts markiert.\n");
	for (ob = first_inventory(ob2); nr > i++ && ob; ob = next_inventory(ob))
	    ;
	if (!ob)
	    FAIL("Das Objekt Nr." + nr + " ist nicht in " + Name(ob2) + "\n");
    }
    else switch(strs[0])    /*** Umgebung, mich, hier, sonstiges ***/
    {
      case "umgebung":
      case "^":
	if (!ob2)
	    FAIL("In Markierung @0 ist nichts markiert.\n");
	ob = environment(ob2);
	if (!ob)
	    FAIL("Objekt " + Name(ob2) + " hat keine Umgebung.\n");
	break;
      case "mich":
	ob = this_player();
	break;
      case "hier":
	ob = environment(this_player());
        if (!ob)
	    FAIL("Du hast keine Umgebung.\n");
	break;
      default:
        if (flag & SO_ENV_FIRST)
	{
	    if (!ob && environment(this_player()))
		ob = present(strs[0],environment(this_player()));
	    if (!ob && environment(this_player()))
		ob = present(lower_case(strs[0]),environment(this_player()));
	}
	
	if (!ob)
	    ob = present(strs[0],this_player());
	if (!ob)
	    ob = present(lower_case(strs[0]),this_player());

        if (!(flag & SO_ENV_FIRST))
	{
	    if (!ob && environment(this_player()))
		ob = present(strs[0],environment(this_player()));
	    if (!ob && environment(this_player()))
		ob = present(lower_case(strs[0]),environment(this_player()));
	}
	
	if (!ob)
	{
	    if (flag & SO_ENV_FIRST)
		parsed = parse_com(strs[0],0,0,
			(flag & SO_V_ITEM ? 0 : PARSE_NO_V_ITEMS));
	    else if (environment(this_player()))
		parsed = parse_com(strs[0],
			({this_player(),environment(this_player())}),0,
			(flag & SO_V_ITEM ? 0 : PARSE_NO_V_ITEMS));
	    if (parsed && parsed[PARSE_NUM_OBS] == 1)
		ob = parsed[PARSE_OBS][0];
	}
	if (!ob)
	    ob = find_player(strs[0]);
	if (!ob)
	    ob = find_player(lower_case(strs[0]));
	if (!ob)
	    ob = find_living(strs[0]);
	if (!ob)
	    ob = find_living(lower_case(strs[0]));
	if (!ob && strs[0][0]=='/')  // Sonst ueber add_path
	    ob = find_object(strs[0]);
	if (!ob && this_player())
       	{
	    obst = ({string})this_player()->add_path(strs[0]);
	    ob = find_object(obst);
	    if (!ob)
		if (obst = ({string})MAP_OB->get_map_file_name(obst))
		    ob = find_object(obst);
	}
	if (!ob && this_player() && environment(this_player()))
	{
	    string raum = ({string}) environment(this_player())->query_one_exit(strs[0],1);
	    if(raum)
		ob = touch(raum);
	}
	if (!ob)
	{
	    mapping plugins = ({mapping})PLUGIN_MASTER->query_plugins();
	    foreach(string pl: plugins || ([]))
		if (explode(pl,"/")[<1] == strs[0])
		{
		    ob = find_object(pl);
		    if(ob)
			break;
		}
	}
	if (!ob)
	    FAIL("Sorry, " + strs[0] + " ist nicht zu finden.\n");
    }

    /* Finde Folge-Objekte */

    for (i = 1; i < sizeof(strs); i++)
    {
	ob2 = ob;
        if (strs[i] == "*" && objectp(ob2))
        {
            i++;
            if(i == sizeof(strs))
        	FAIL("Suchstring darf nicht mit * enden.\n");
            if(strs[i] != "umgebung" && strs[i] != "^")
	    {
		if (!str2int(strs[i],&nr))
		{
		    object *obs=deep_inventory(ob2);
		    if(nr<=0) nr=1;
		    if(nr>sizeof(obs))
			FAIL("Das Objekt Nr."+nr+" ist nicht in "+
			    Name(ob2)+"\n");
		    ob=obs[nr-1];
		}
		else
		{
		    ob = deep_present(strs[i],ob2);
		    if (!ob)
			ob = deep_present(lower_case(strs[i]),ob2);
		    if (!ob)
		    {
			parsed = parse_com(strs[i],({ob2})+deep_inventory(ob2),
			    0,(flag & SO_V_ITEM?0:PARSE_NO_V_ITEMS));
			if (parsed[PARSE_NUM_OBS] != 1)
			    FAIL("Objekt "+strs[i]+" ist nicht in "+
				Name(ob2)+".\n");
			else
			    ob = parsed[PARSE_OBS][0];
		    }
		}
	    }
        }
	else if (strs[i] == "umgebung" || strs[i] == "^")
       	{
	    if(mappingp(ob2))
	    {
		ob = ob2["environment"];
		if (!ob)
		    FAIL("V-Item " + ob2["name"] + " hat keine Umgebung.\n");
	    }
	    else
	    {
		ob = environment(ob2);
		if (!ob)
		    FAIL("Objekt " + Name(ob2) + " hat keine Umgebung.\n");
	    }
	}
	else if(!objectp(ob2))
	{
	    if(mappingp(ob2))
		FAIL("Kann nicht im V-Item " + ob2["name"] + " suchen.\n");
	    else
		FAIL("Fehler, habe " + mixed2str(ob2) + " wurde gefunden!\n");
	}
	else
       	{
	    if (!str2int(strs[i],&nr))
	    {
		int j;
		for (j = 0, ob = first_inventory(ob2); nr>j++ && ob;
		       ob = next_inventory(ob))
		       ;
		if (!ob)
		    FAIL("Das Objekt Nr."+nr+" ist nicht in "+Name(ob2)+"\n");
	    }
	    else
	    {
		ob = present(strs[i],ob2);
		if (!ob)
		    ob = present(lower_case(strs[i]),ob2);
		if (!ob)
		{
		    parsed = parse_com(strs[i],ob2,0,
			    (flag & SO_V_ITEM?0:PARSE_NO_V_ITEMS));
		    if (parsed[PARSE_NUM_OBS] == 1)
			ob = parsed[PARSE_OBS][0];
		}
		if (!ob)
		{
		    string raum;
		    
		    raum = ({string}) ob2->query_one_exit(strs[i],1);
		    if(raum)
			ob = touch(raum);
		}
		if(!ob)
		    FAIL("Objekt "+strs[i]+" ist nicht in "+Name(ob2)+".\n");
	    }
	}
    }

    return ob;
}
