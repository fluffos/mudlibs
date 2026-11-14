// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zinfos.inc
// Description: Informationsbefehle des Zauberstabes
// Author:	Freaky	(23.12.93)
// Modified by:	Freaky	(28.03.96) zinfo_living verbessert (Armours)
// Modified by: Monty	(22.04 96) in do_info_object eine Abfrage auf
//		                   query_info() eingebaut.
//		Garthan	(09.08.96) z_kommandos: major rewrite
//              Sissi	(31.08.96) Landschaftstypen - Infos bei Raeumen
//              Garthan	(24.02.97) ztrace
//              Parsec	(23.11.98) Rasse/Form/Groesse/Faehigkeiten bei Livings
//              Parsec	(24.10.99) Neue Lebenslaeufe mit Daemmerungen
//              Parsec	(05.06.00) L_LUFT
//              Parsec  (27.06.00) MAX_SUM_WISSEN -> query_soll_wissen()
//
// $Log: zinfos.inc,v $
// Revision 1.76  2016/08/31 16:59:17  myonara
// Auswertung Origin-Property in zinfo, falls vorhanden. (Schliesfaecher)
// Origin sammelt first_room,first_player und object_time vor dem 1. Einalgern
//
// Revision 1.75  2016/03/21 12:39:12  gnomi
// Mit efun::interactive() vor efun::interactive_info() pruefen.
//
// Revision 1.74  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.73  2015/05/01 16:34:17  myonara
// zclient um -a erweitert
//
// Revision 1.72  2015/03/17 11:23:57  myonara
// Neuer Adminbefehl zclient.
//
// Revision 1.71  2013/12/14 19:54:47  myonara
// ob:query_damage_type, pl: query_damage_percentages und andere
//
// Revision 1.70  2010-07-13 10:39:15  sorcerer
// sort_short bekommt Objektnamen, nicht Objekte
//
// Revision 1.69  2009-09-21 18:11:10  sorcerer
// zi: alle Inherits als solche behandeln
//
// Revision 1.68  2009-06-16 13:38:03  gnomi
// zco: Auch Closures als Funktionsname erwarten.
//
// Revision 1.67  2009-03-20 08:06:24  gnomi
// ID-Liste und Umgebung umbrechen statt abschneiden.
//
// Revision 1.66  2008-05-19 14:27:02  gnomi
// "noise" bei V-Items als Beschreibung anzeigen.
//
// Revision 1.65  2008-04-26 18:22:41  gnomi
// query_no_store anzeigen.
// Dateinamen von Ausgaengen umbrechen.
//
// Revision 1.64  2008/01/16 09:37:58  gnomi
// Indexing past string end.
//
// Revision 1.63  2007/12/05 11:04:38  gnomi
// Debugger anzeigen, bei Nahrung auch Maximal- und Minimalgewicht.
// Raumtypen besser formatieren (nicht abschneiden).
//
// Revision 1.62  2005/04/10 01:28:04  gnomi
// query_file_name eingefuehrt.
//
// Revision 1.61  2005/03/28 00:48:13  gnomi
// V-Items: "feel" anzeigen.
//
// Revision 1.60  2005/02/06 03:28:30  gnomi
// Aktuell/Existent -> Programm/Objekt
//
// Revision 1.59  2004/08/27 13:03:40  menaures
// Dokumentation zu query_info()
//
// Revision 1.58  2004/07/04 00:14:06  gnomi
// Bei query_info() testen, ob es wirklich ein String ist.
//
// Revision 1.57  2004/02/18 22:31:55  gnomi
// zkuerzel-Befehl eingebaut.
//
// Revision 1.56  2003/11/06 04:04:30  gnomi
// Kaputt-Meldung automatisch umbrechen.
//
// Revision 1.55  2003/11/04 03:18:55  gnomi
// Staedteanzeige ausgebaut.
//
// Revision 1.54  2003/08/29 18:21:46  menaures
// ob->set_light(0) durch ob->query_outer_light() ersetzt
// Ein paar Casts wurden (nicht von mir) korrigiert
//
// Revision 1.53  2003/07/16 00:59:10  gnomi
// Abfrage der wirklichen IP eingebaut.
//
// Revision 1.52  2003/06/19 22:38:13  gnomi
// Der Name wurde falsch angezeigt.
//
// Revision 1.51  2003/06/02 00:06:56  gnomi
// Statt abzuschneiden werden einige Infos jetzt ordentlich umgebrochen.
//
// Revision 1.50  2003/02/02 03:18:30  gnomi
// query_last_player() anzeigen.
//
// Revision 1.49  2002/11/20 04:06:15  gnomi
// learning_type-Anzeige ausgebaut.
//
// Revision 1.48  2002/11/09 02:44:34  gnomi
// Bei Objekten eine Liste der V-Items ausgeben.
//
// Revision 1.47  2002/10/19 00:40:13  gnomi
// zinfos: Schoenheitskorrektur bei Anzeige des 1. Raumes.
//
// Revision 1.46  2002/10/16 01:04:21  gnomi
// Zeigt extra_look's mit an.
//
// Revision 1.45  2002/09/08 00:08:20  gnomi
// kurzlang wird nun auch angezeigt.
//
// Revision 1.44  2002/08/10 00:25:27  gnomi
// ztrace Nutzt neuen query_visitors-Eintrag.
//
// Revision 1.43  2002/08/04 14:43:48  sissi
// zstatistik um die letzten Rettungen erweitert.
//
// Revision 1.42  2002/07/30 23:19:59  gnomi
// zshadow: Fehlerhafte getopt-Nutzung korrigiert.
//
// Revision 1.41  2002/07/19 23:51:27  gnomi
// zshadow: Den Erschaffer der Shadows mit anzeigen.
//
// Revision 1.40  2002/07/19 23:41:31  gnomi
// ztrace: real_name anzeigen.
//
// Revision 1.39  2002/07/14 01:55:57  gnomi
// min/max_weight anzeigen.
//
// Revision 1.38  2002/06/18 02:39:54  gnomi
// "read" erhaelt besondere Argumente.
//
// Revision 1.37  2002/05/17 21:49:56  sissi
// statt "zsuch" geht nun auch "zsuche"
//
// Revision 1.36  2002/04/18 12:59:23  freaky
// nochmal an anderer Stelle
//
// Revision 1.35  2002/04/18 12:56:49  freaky
// object_time auch bei nicht echten clones (efun::clonep()) verwenden
//
// Revision 1.34  2002/02/16 06:22:00  gnomi
// Pulamis Anzeige von Countob-Infos eingebaut.
//
// Revision 1.33  2002/02/14 00:36:05  gnomi
// Bei Closures in V-Items das V-Item als Argument uebergeben.
//
// Revision 1.32  2002/01/15 03:38:29  gnomi
// query_short umgestellt.
//
// Revision 1.31  2002/01/14 04:15:34  gnomi
// long, read: Betrachter bei Abfragen als Parameter angeben.
// V-Items: V-item wird bei Ausfuehrung der Closures als Parameter uebergeben.
//
// Revision 1.30  2002/01/12 21:21:11  gnomi
// zqueue entfernt.
//
// Revision 1.29  2002/01/10 07:34:37  gnomi
// Schoenheitskorrektur bei zgrad.
//
// Revision 1.28  2001/12/24 21:49:20  gnomi
// zgrad: Spalten vergroessert.
//
// Revision 1.27  2001/10/31 23:07:32  sissi
// *** empty log message ***
//
// Revision 1.26  2001/10/31 22:23:49  sissi
// zgrad schoener gemacht
//
// Revision 1.25  2001/06/22 17:06:33  freaky
// Parameter fuer negative add-action-flags eingefuehrt bei zkommand
//
// Revision 1.24  2001/06/12 21:46:17  jesaia
// Code fuer experimentelles Align eingebaut...
//
// Revision 1.23  2001/06/03 11:18:12  freaky
// UDL-info eingebaut.
//
// Revision 1.22  2001/05/19 22:19:25  gnomi
// zraetsel/zspiele: Anzeige, ob man das Raetsel/Spiel voll hat.
//
// Revision 1.21  2001/05/06 22:04:51  gnomi
// Monatsstatistik.
//
// Revision 1.20  2001/05/06 20:19:18  gnomi
// Schoenheitskorrektur im zsuch.
//
// Revision 1.19  2001/04/26 09:33:55  sissi
// Parsec: Es wird angezeigt, wann ein Clone erzeugt wurde und nicht mehr,
// seit wann der blueprint geladen ist.
//
// Revision 1.18  2001/04/17 16:33:19  gnomi
// Bugfix in der Inline-Closure von zsuch.
//
// Revision 1.17  2001/04/10 21:33:03  sissi
// Bruellstatistik hinzugefuegt
//
// Revision 1.16  2001/04/07 22:05:00  gnomi
// zsuch sucht im deep_inventory.
//
// Revision 1.15  2001/03/28 22:30:20  sissi
// Todesstatistik.
//
// Revision 1.14  2001/03/24 22:57:04  gnomi
// zi: Auch Geraeusch anzeigen, kein Read, wenn es ein Buch ist.
//
// Revision 1.13  2001/03/14 17:31:03  freaky
// deprecated Funktion member-array durch member ersetzt.
//
// Revision 1.12  2001/02/25 13:56:14  sissi
// Statt "idle seit 193248 Sek." gibts jetzt ein "idle seit 1d 5h 40m 48s"
//
// Revision 1.11  2001/02/08 23:58:41  gnomi
// query_creator anzeigen.
//
// Revision 1.10  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#include <level.h>
#include <notify_fail.h>

#pragma strong_types

private string get_map_file(string str)
{
    int x, y, dx, dy, *dc;
    string name, domain, member, sub, source, map;

    if (sscanf(str,"/map/m%d_%d",x,y) == 2)
    {
	name = MAP_OB->query_map_file_name(x,y);
	if (sscanf(name,"/map/m%d_%d",dx,dy) == 2)
	    source = "/map/map  (m"+dx+"_"+dy+")";
	else if (file_size(name) > 0)
	    source = name;
	else if (sscanf(name,"/d/%s/%s/%s/m%d_%d",domain,member,sub,dx,dy) == 5)
	{
	    map = "/d/"+domain+"/"+member+"/"+sub+"/map";
	    if (file_size(map+".c") > 0)
		source = map+"  (m"+dx+"_"+dy+")";
	    else
	    {
		map = "/d/"+domain+"/map";
		if (file_size(map+".c") > 0)
		{
		    dc = MAP_OB->query_domain_coords(domain);
		    source = map+"  (m"+(x-dc[0])+"_"+(y-dc[1])+")";
		}
		else
		    source = "/map/map  (m"+x+"_"+y+")";
	    }
	}
	else if (sscanf(name,"/d/%s/%s/m%d_%d",domain,member,dx,dy) == 4)
	{
	    map = "/d/"+domain+"/"+member+"/map";
	    if (file_size(map+".c") > 0)
		source = map+"  (m"+dx+"_"+dy+")";
	    else
	    {
		map = "/d/"+domain+"/map";
		if (file_size(map+".c") > 0)
		{
		    dc = MAP_OB->query_domain_coords(domain);
		    source = map+"  (m"+(x-dc[0])+"_"+(y-dc[1])+")";
		}
		else
		    source = "/map/map  (m"+x+"_"+y+")";
	    }
	}
	else if (sscanf(name,"/d/%s/m%d_%d",domain,dx,dy) == 3)
	{
	    map = "/d/"+domain+"/map";
	    if (file_size(map+".c") > 0)
		source = map+"  (m"+dx+"_"+dy+")";
	    else
		source = "/map/map  (m"+x+"_"+y+")";
	}
	else
	    source = str;
	return("Source:     "+source);
    }
    else
    {
	name = MAP_OB->get_map_file_name(str);
	if (name)
	    return("Map-File:   "+name[0..<3]);
	else
	    return 0;
    }
}

private string get_replace_info(object obj)
{
    string inh, name, dummy;

    inh = inherit_list(obj)[0];
    name = (sscanf(FN(obj),"%s#%s",name,dummy)?name:FN(obj))+".c";
    if (inh!=name)
	return " (replaced mit "+inh+")";
    else return "";
}

#define SHOW(name,info) W(sprintf("%-11s %-=67s\n",(name)+":",(info)))

private void do_info_inherit_file(object obj, int flag)
{
    object sh;
    int i;
    string type;

    if (flag)
	W(LINE[0..10] + " Inherit-File " + LINE[25..]);
    else
	W(LINE);
    WLN("File-Name:  " + FN(obj) + get_replace_info(obj));
    WLN("Load-Name:  " + load_name(obj));
    WLN("Prog-Name:  " + program_name(obj));
    if (ENV(obj))
	SHOW("Umgebung",FN(ENV(obj)));
    if (i = sizeof(all_inventory(obj)))
	SHOW("Inhalt", i + " Objekt" + (i > 1 ? "e" : ""));
    SHOW("Programm", format_seconds(time() - program_time(obj)));
    // Freaky: wenn schon, dann efun:: oder immer
    // if ( efun::clonep( obj) )
    SHOW("Objekt", format_seconds(time() - object_time(obj)));
    SHOW("Debugger", implode(MASTER_OB->query_debugger(object_name(obj)),", "));
    SHOW("User-Id", getuid(obj) +
	(geteuid(obj)?("       Effektive User-Id: " + geteuid(obj)):""));

    if (sh = shadow(obj,0))
    {
	i = 1;
	while (sh = shadow(sh,0))
	    i++;
	SHOW("Shadow", i + ": " + FN(shadow(obj,0)));
    }
    if (sh = query_shadowing(obj))
	SHOW("Shadowing", FN(sh));
    type = "";
#if __EFUN_DEFINED__(driver_info)
    if (object_info(obj, OC_HEART_BEAT))
#else
    if (object_info(obj,OINFO_BASIC)[OIB_HEART_BEAT])
#endif
	type += "Heart-Beat ";
    if (interactive(obj))
	type += "Interaktiv ";
    else if (query_once_interactive(obj))
	type += "Once-Interaktiv ";
    if (living(obj))
	type += "Living ";
    if (query_editing(obj))
	type += "Editing ";
    if (query_input_pending(obj))
	type += "Input ";
    if (type != "")
	SHOW("Zustand", type);
#if __EFUN_DEFINED__(query_snoop)
    if (sh = query_snoop(obj))
#else
    if (sh = interactive_info(obj, II_SNOOP_NEXT))
#endif
	SHOW("Snooped", FN(sh));
    W(LINE);
}

private void do_info_objekt(object obj)
{
    string *tmpsa, *tmpsb, tmps, tmp;
    int i, landschaft;
    object sh;
    mixed *auto;
    mapping types,m_origin;

    if (tmp=obj->query_long(this_player()))
	W(LINE2("Long")+tmp);
    if(living(environment(obj)) && (tmp=obj->extra_look()))
	W(LINE2("Extra-Look")+wrap(tmp));
    if (tmp=obj->query_smell())
	W(LINE2("Geruch")+tmp);
    if (tmp=obj->query_noise())
	W(LINE2("Geraeusch")+tmp);
    if (tmp=obj->query_feel())
	W(LINE2("Gefuehl")+tmp);
    if (!obj->query_book() && tmp=obj->query_read(0,0,this_player()))
	W(LINE+tmp);
    if (sizeof(auto=obj->query_all_v_items()))
    {
	W(LINE2("V-Items"));
	auto = transpose_array(({ ({0})*sizeof(auto), auto }));
	while(sizeof(auto))
	{
	    WLN("  "*auto[0][0] + Ein(auto[0][1]));
	    if(sizeof(auto[0][1]["v_item"]))
		auto = transpose_array(({ ({auto[0][0]+1})*sizeof(auto[0][1]["v_item"]), auto[0][1]["v_item"]}))
		     + auto[1..<1];
	    else
		auto = auto[1..<1];
	}
    }
    W(LINE);
    if (tmp=SHORT(obj))
	SHOW("Kurz",tmp);
    if (tmp=obj->query_cap_name())
    {
	string gtyp;
	i=obj->query_invis();
	gtyp=check_invis(i,tmp);
	if (obj->query_personal())
	    gtyp+=" [pers]";
	if (obj->query_eigen())
	    gtyp+=" [eigen]";
	if (obj->query_plural())
	    gtyp+=" [plural]";
	if (i)
	    gtyp+=" [invis:"+i+"]";
	if (tmp=query_living_name(obj))
	    gtyp+="   Living-Name: "+tmp;
	SHOW("Name",gtyp);
    }
    if (call_resolved(&i,obj,"query_own_light"))
	SHOW("Licht", i+"     Gesamt: "+obj->query_outer_light()+
	    (call_resolved(&i,obj,"query_light")?("/"+i):""));
    tmpsa=obj->query_id();
    if (pointerp(tmpsa) && sizeof(tmpsa))
	SHOW("Id",implode(tmpsa,", "));
    tmpsa=obj->query_class_id();
    if (pointerp(tmpsa) && sizeof(tmpsa))
	SHOW("Class-Id",implode(tmpsa,", "));
    tmpsa=obj->query_plural_id();
    if (pointerp(tmpsa) && sizeof(tmpsa))
	SHOW("Plural-Id",implode(tmpsa,", "));
    tmpsa=obj->query_adjektiv_grundform();
    if (pointerp(tmpsa) && sizeof(tmpsa))
	SHOW("Adjektive", implode(tmpsa,", "));
    if (tmp=obj->query_gender())
	SHOW("Geschlecht", tmp);
    if (i=obj->query_value())
    {
	string vstr = i+" Taler";
	string* vattr = ({});
	if (i=obj->query_min_value())
	    vstr+="     Min: "+i;
	if (i=obj->query_max_value())
	    vstr+="     Max: "+i;
	if (obj->query_sellable())
	    vattr += ({"verkaufbar"});
	if (obj->query_no_store())
	    vattr += ({"nicht lagerbar"});
	if(sizeof(vattr))
	    vstr+="     ("+implode(vattr,", ")+")";
	SHOW("Wert", vstr);
    }
    if(obj->query_container() && !obj->query_room() || obj->query_nahrung())
	WLN(sprintf("Gewicht:    %-3d    Minimal: %-3d    Maximal: %d",
		obj->query_weight(), obj->query_min_weight(),
		obj->query_max_weight()));
    else if (i=obj->query_weight())
	WLN("Gewicht:    "+i);

    // Ist es ein Count-Objekt?
    if(obj->query_count())
    {
        WLN(sprintf("Count:      %d",obj->query_count()));
        WLN(sprintf("Count-Type: %O",obj->query_count_type()));
    }

    tmpsa=obj->query_material();
    if (pointerp(tmpsa) && sizeof(tmpsa))
	SHOW("Material",implode(tmpsa,", "));
    if (obj->query_container())
    {
	W("Traglast:   " + obj->query_internal_encumbrance() +
	    "     Maximal: " + obj->query_max_internal_encumbrance());
	if (obj->query_con_close())
	    W("   (geschlossen)");
	W("\n");
    }
    if (i=sizeof(all_inventory(obj)))
	SHOW("Inhalt",i+" Objekt"+(i>1?"e":""));
    tmps=FN(obj);
    SHOW("File-Name",tmps+get_replace_info(obj));
    
    if (tmp=obj->query_file_name())
	SHOW("Orig-File",tmp);
    if (tmp=obj->query_udl_file())
	SHOW("UDL-File",tmp);
    if (auto=obj->query_auto_load())
	SHOW("Auto-Load",mixed2str(auto));
    // Selbst konfigurierbare Info!
    if ((tmp=obj->query_info()) && stringp(tmp))
	WLN(tmp);
    if (ENV(obj))
	SHOW("Umgebung",FN(ENV(obj)));
    if (tmp=obj->query_creator())
	SHOW("Creator",tmp);
    if (tmp=obj->query_first_room())
    {
	tmpsa=explode(tmp,"|")-({""});
	if (sizeof(tmpsa))
	{
	    SHOW("1. Raum",regreplace(tmpsa[0],"([^ ])\\(","\\1 (",0));
	    for (i=1; i<sizeof(tmpsa); i++)
		SHOW(to_string(i)+". Objekt",regreplace(tmpsa[i],"([^ ])\\(","\\1 (",0));
	}
    }
    if (tmp=obj->query_first_player())
	SHOW("1. Spieler",capitalize(tmp));

    m_origin = obj->query(P_ORIGIN);
    if (sizeof(m_origin))
    {
        if (tmp=m_origin[P_ORIGIN_ROOM])
        {
	    tmpsa=explode(tmp,"|")-({""});
            if (sizeof(tmpsa))
	    {
	        SHOW("1. Raum(Origin)",regreplace(tmpsa[0],"([^ ])\\(","\\1 (",0));
	        for (i=1; i<sizeof(tmpsa); i++)
		    SHOW(to_string(i)+". Objekt(Origin)",regreplace(tmpsa[i],"([^ ])\\(","\\1 (",0));
	    }
        }
        if (tmp=m_origin[P_ORIGIN_PLAYER])
            SHOW("1. Spieler(Origin)",capitalize(tmp));
        if (i=m_origin[P_ORIGIN_CREATED_ON])
            SHOW("1. Ladezeitpunkt(Origin)",shorttimestr(i));
    }

    if (tmp=obj->query_last_player())
	SHOW("L. Spieler",capitalize(tmp));

    if (tmp=obj->query_loader())
	SHOW("Loader",tmp);
    SHOW("Programm", format_seconds(time() - program_time(obj)));
    SHOW("Objekt", format_seconds(time() - object_time(obj)));
    /**********  Raum **********/
    if (tmp=get_map_file(tmps))
	WLN(tmp);
    tmpsa=obj->query_command_list();
    tmpsb=obj->query_exit_list();
    if (sizeof(tmpsa))
    {
	tmps="Ausgaenge:  ";
	for (i=0; i<sizeof(tmpsa); i++)
	{
	    W(sprintf("%s%-=16.16s %-=50O\n",
		tmps, tmpsa[i], tmpsb[i]));
	    tmps="            ";
	}
    }
    types=obj->query_types();
    if (types)
    {
	tmps="Typen:";
	tmpsa=m_indices(types);
	for (i=0; i<sizeof(tmpsa); i++)
            if (tmpsa[i] != LANDSCHAFT)
	    {
		W(sprintf("%:-11s %:-24s %=-42s\n",
		    tmps, tmpsa[i], mixed2str(types[tmpsa[i]])));
	        tmps="";
	    }
            else
	    	landschaft = types[tmpsa[i]];
        if (landschaft)
        {
            tmp = "";
            if (landschaft & L_DRINNEN) tmp += "drinnen ";
            if (landschaft & L_WASSER) tmp += "Wasser ";
            if (landschaft & L_FLIESSEND) tmp += "fliessend ";
            if (landschaft & L_FLACH) tmp += "flach ";
            if (landschaft & L_UNTERWASSER) tmp += "Unterwasser ";
            if (landschaft & L_MEERESGRUND) tmp += "Meeresgrund ";
            if (landschaft & L_STEG) tmp += "Steg ";
            if (landschaft & L_STRAND) tmp += "Strand ";
            if (landschaft & L_WIESE) tmp += "Wiese ";
            if (landschaft & L_WALD) tmp += "Wald ";
            if (landschaft & L_WUESTE) tmp += "Wueste ";
            if (landschaft & L_STEPPE) tmp += "Steppe ";
            if (landschaft & L_BERG) tmp += "Berg ";
            if (landschaft & L_MOOR) tmp += "Moor ";
            if (landschaft & L_SUMPF) tmp += "Sumpf ";
            if (landschaft & L_EIS) tmp += "Eis ";
            if (landschaft & L_DSCHUNGEL) tmp += "Dschungel ";
            if (landschaft & L_WEG) tmp += "Weg ";
            if (landschaft & L_SIEDLUNG) tmp += "Siedlung ";
            if (landschaft & L_HAUS) tmp += "Haus ";
            if (landschaft & L_LUFT) tmp += "Luft ";
	    if (landschaft & L_KANALISATION) tmp += "Kanalisation ";
            if (tmp != "")
		W(sprintf("%:-11s %:-24s %=-42s\n",
		    tmps, "Landschaft", tmp));
        }
    }

    SHOW("Debugger", implode(MASTER_OB->query_debugger(object_name(obj)),", "));
    W("User-Id:    "+getuid(obj)+"       ");
    if (geteuid(obj))
	WLN("Effektive User-Id: "+geteuid(obj));
    else
	W("\n");

    if (sh=shadow(obj,0))
    {
	i=1;
	while (sh=shadow(sh,0))
	    i++;
	WLN("Shadow:     "+i+": "+FN(shadow(obj,0)));
    }
    if (sh=query_shadowing(obj))
	WLN("Shadowing:  "+FN(sh));

    /************ Getraenk ***********/
    if (i=obj->query_healing())
	WLN("Heil-Wirkung:     "+i);
    if (i=obj->query_strength())
	WLN("Heil-Staerke:     "+i);
    if (i=obj->query_amount())
	WLN("Volumen:          "+i);

    /************ Ruestung + Waffe *********/
    if (tmp=obj->query_armour_class())
	WLN("Ruestungsklasse:  "+tmp);
    if (i=obj->query_armour_protection())
	WLN("Ruestungsstaerke: "+i);
    tmpsa=obj->query_skill_path();
    if (sizeof(tmpsa))
	WLN("Skillpfad:        "+implode(tmpsa,","));
    if (i=obj->query_min_damage())
    {
	W("Waffenstaerke:    Minimal: "+i);
	if (i=obj->query_max_damage())
	    W("     Maximal: "+i);
	W("\n");
    }
    else if (i=obj->query_max_damage())
	WLN("Waffenstaerke:    Maximal: "+i);
    if (i=obj->query_life())
    {
	W("Leben:            "+i);
	if (i=obj->query_max_life())
	    W("     Maximal: "+i);
	W("\n");
    }
    else if (i=obj->query_max_life())
	WLN("Leben:            Maximal: "+i);
    tmpsa=obj->query_damage_type();
    if (pointerp(tmpsa) && sizeof(tmpsa))
	SHOW("DamageType",implode(tmpsa,", "));    

    if (i=obj->query_schutz())
	WLN("Temp.-Schutz:     "+i);
    if (tmp=obj->query_typ())
	WLN("Typ:              "+tmp);
    tmps="";
    if (query_shadowing(obj))
	tmps+=" Shadow";
    if (obj->query_stay_in_pub())
	tmps+=" Pub-Getraenk";
    if (obj->query_cloth())
	tmps+=" Kleidung";
    if (obj->query_weapon())
	tmps+=" Waffe";
    if (obj->query_armour())
	tmps+=" Ruestung";
    if (obj->query_nahrung())
	tmps+=" Nahrung";
    if (obj->query_getraenk())
	tmps+=" Getraenk";
    if (tmp=obj->query_weapon_class())
	tmps+=" "+capitalize(tmp)+"-Waffe";
    if (obj->query_broken())
	tmps+=" (kaputt)";
    if (obj->query_wield())
	tmps+=" (gefuehrt)";
    if (obj->query_worn())
	tmps+=" (angezogen)";
    if (tmps!="")
	WLN("Zustand:         "+tmps);
    if (tmp=obj->query_broken_message())
	W(sprintf("Kaputt-Meldung:   %-=61s\n",
	    (sizeof(tmp) && tmp[<1]=='\n')?tmp[0..<2]:tmp));
    W(LINE);
}

private void do_waffe(object waf, int nr, object own)
{
    string st;
    int tmp;

    if (waf)
    {
	if (!waf->query_broken())
	    tmp=waf->compute_damage();
	st=Name(waf);
	if (waf->query_weapon_class()=="defensiv")
	    st="* "+st;
    }
    else
    {
	tmp=own->compute_damage();
	st="Hand";
    }
    if (nr==0)
	WLN(left(" Waffen:"+right(""+tmp,3)+" "+st,39));
    else
	WLN(left(right(""+tmp,11)+" "+st,39));
}

private void do_ruestung(object ob, int nr2, string r)
{
    string st;
    int tmp;

    if (nr2==-1)
    {
	W(r);
	return;
    }
    st=Name(ob);
    if (!ob->query_broken())
	tmp=ob->query_armour_protection();
    WLN(left(right(""+tmp,11)+" "+st,39));
}

#define SPALTE2  if (nr<num_hands) { do_waffe(waffe[nr],nr,obj); nr++; } \
		 else if (nr2<num_ruest) { do_ruestung(nr2<0?0:ruest[nr2],nr2,r); nr2++; } \
		 else W("\n");

private void do_info_spieler(object obj)
{
    object inv, *waffe, *ruest, sh;
    int spieler, traglast, i, align;
    int tmp, num_ruest, sum_ruest, num_hands, nr, nr2;
    string stxt, r, level, tmps;
    mapping tmpm;

    if (playerp(obj))
	spieler=1;

    num_hands=obj->query_num_hands();
    waffe=obj->query_hand_objects();
    ruest=obj->query_armours();
    FOR_ALL(inv,obj)
    {
	traglast+=inv->query_weight();
	if (inv->query_weapon() && inv->query_wield())
	{
	    if (member(waffe,inv)==-1)
		WLN("Fehler in Waffen: "+OFN(inv));
	    if (inv->query_weapon_class()=="defensiv" &&
			!inv->query_broken())
		sum_ruest+=inv->compute_damage(0);
	}
	if (inv->query_armour() && inv->query_worn())
	{
	    if (member(ruest,inv)==-1)
		WLN("Fehler in Ruestungen: "+OFN(inv));
	    if (inv->query_weapon_class()=="defensiv")
		ruest-=({inv});
	    else if (!inv->query_broken())
		sum_ruest+=inv->query_armour_protection();
	}
    }
    num_ruest=sizeof(ruest);
    sum_ruest+=obj->query_armour_level();
    nr2=-1;
    r=" Ruestungen: "+sum_ruest+"/"+obj->query_armour_protection()+"\n";

    if (!spieler)
    {
	stxt="Monster: "+SHORT(obj);
	if (obj->query_personal())
	    stxt+=" [pers]";
	if (tmp=obj->query_invis())
	    stxt+=" [invis:"+tmp+"]";
    }
    else
    {
	stxt="Spieler: ";
	stxt+=check_invis(obj->query_invis(),obj->query_real_cap_name());
	tmps=obj->query_title();
	if (tmps && tmps!="")
	{
	    if (tmps[0]==',')
		stxt+=tmps;
	    else
		stxt+=" "+tmps;
	}
	tmps=obj->query_align_title();
	if (tmps && tmps!="")
	    stxt+=" ("+tmps+")";
	if (obj->query_moerder())
	    stxt+=" (M)";
    }

    level = " (Level " + obj->query_level() + "/" +
	query_real_player_level(obj) + ")";
    W(LINE);
    WLN(left(stxt,79-strlen(level))+level);
    if (playerp(obj))
    {
        if (obj->is_intermud_guest())
            stxt="  (InterMUD-Gast, Idle seit "+short_format_seconds(obj->query_intermud_idle())+")";
	else if (!interactive(obj))
	    stxt="  (Non-interactive Spieler)";
	else if (query_idle(obj))
	    stxt="  (Idle seit "+short_format_seconds(query_idle(obj))+")";
        else stxt = "";
	WLN(left("Alter:   "+format_seconds(obj->query_age()),
		  79-strlen(stxt))+stxt);
    }
    else
	WLN("Alter:   "+format_seconds(time()-program_time(obj)));

    if (!spieler)
	WLN(left("File:    "+FN(obj),79));
    if (ENV(obj))
	WLN("Raum:    "+FN(ENV(obj)));
    if (stxt=obj->query_first_room())
	WLN(left("1. Raum: "+stxt[0..<2],79));
#if __EFUN_DEFINED__(query_ip_number)
    if ((guestp(obj) || (obj==this_interactive()) || adminp(this_interactive()))
        && efun::query_ip_number(obj))
	WLN(left("IP:      "+(obj->query_real_ip_number() || efun::query_ip_number(obj))+
	    "   ("+(obj->query_real_ip_name() || efun::query_ip_name(obj))+")",79));
#else
    if ((guestp(obj) || (obj==this_interactive()) || adminp(this_interactive()))
        && efun::interactive(obj) && efun::interactive_info(obj, II_IP_NUMBER))
	WLN(left("IP:      "+(obj->query_real_ip_number() || efun::interactive_info(obj, II_IP_NUMBER))+
	    "   ("+(obj->query_real_ip_name() || efun::interactive_info(obj, II_IP_NAME))+")",79));
#endif
//    else if (INST(obj))
//	WLN(left("Adresse: "+INST(obj),79));
    if (sh=shadow(obj,0))
    {
	i=1;
	while (sh=shadow(sh,0))
	    i++;
	WLN("Shadow:  "+i+": "+FN(shadow(obj,0)));
    }
    W(LINE);

    tmp = obj->query_abilities() ;
    tmps = "" ;
    if ( tmp & MD_AB_WALK )
        tmps += "laufen, " ;
    if ( tmp & MD_AB_SWIM )
        tmps += "schwimmen, " ;
    if ( tmp & MD_AB_FLY )
        tmps += "fliegen, " ;
    if ( (tmps = tmps[0..<3]) == "" )
        tmps = "-" ;

    tmp = obj->query_koerpergroesse() ;
    if ( tmp < 1 )
        tmp = 1 ;
    else if ( tmp > 10 )
        tmp = 10 ;

    W( sprintf( "Rasse:    %-18.18s  "   "Form:    %-40.40s\n"
                "Groesse:  %-2d %-15.15s  Faehig.: %-40.40s\n",
                to_string( obj->query_race() || "-"),
                to_string( obj->query_koerperform() || "-"),
                obj->query_koerpergroesse(),
                "("+({
                    "0 cm - 5 cm",
                    "5 cm - 30 cm",
                    "30 cm - 70 cm",
                    "70 cm - 1,2 m",
                    "1,2 m - 1,7 m",
                    "1,7 m - 2,2 m",
                    "2,2 m - 3,7 m",
                    "3,7 m - 7 m",
                    "7 m - 15 m",
                    "> 15 m"
                })[tmp-1]+")",
                tmps)) ;

    for (i=0; i<STAT_NUMBER; i++)
    {
    	tmp = obj->query_stat(i);
	if (tmp != obj->query_real_stat(i))
	    W(sprintf("%s %d/%d",STAT_NAMES[i],tmp,obj->query_real_stat(i)));
	else
	    W(sprintf("%s %d",STAT_NAMES[i],tmp));
    	if (i < STAT_NUMBER-1)
	    W("   ");
    }
    W("\n");

    i=obj->compute_one_skill(({"skill"}));
    if (spieler)
        tmps = " "+(obj->query_experience_promille() / 10.0)+"%" ;
    else
        tmps = "" ;
    WLN("Erfahrung: "+right(""+i,10)+
	left(" ("+TOTAL_EXPERIENCE+")"+tmps,18)+"+"+LINE[1..39]);

    W("Ausdauer-Pkt: "+right(""+obj->query_hp(),7) +
	left(" ("+obj->query_max_hp()+")",18) + "|");
    if (spieler)
	W(sprintf(" Essen   : %5d   Alkohol       : %4d\n",
			obj->query_fp(),obj->query_alc()));
    else
	SPALTE2

    W("Zauber-Pkt:   "+right(""+obj->query_sp(),7) +
	left(" ("+obj->query_max_sp()+")",18) + "|");
    if (spieler)
	W(sprintf(" Trinken : %5d   Kopfschmerzen : %4d\n",
			obj->query_wp(),obj->query_headache()));
    else
	SPALTE2
    W("Traglast:" +
	right("" + traglast + "/" + obj->query_internal_encumbrance(),12) +
	left(" (" + obj->query_max_internal_encumbrance() + "+" +
	    obj->query_num_worn_objects() + ")",18) + "|");
    if (spieler)
	W(LINE[40..]);
    else
	SPALTE2
    W(LINE[1..39]+"|");
    SPALTE2
    align=obj->query_align();
    W(left("Ansehen:    "+get_align_string(align)+
	" ("+align+")",39)+"|");
    SPALTE2
    align=obj->query_new_align();
    W(left("Align (exp):"+get_align_string(align)+
        " ("+align+")",39)+"|");
    SPALTE2
    W(left("Geschlecht: "+obj->query_gender(),39)+"|");
    SPALTE2
    if (spieler)
    {
	W(left("Konto: "+obj->query_konto()+" Taler",39)+"|");
	SPALTE2
	W(left("Flags: Schaue-Modus   : " + ({"lang","kurz","kurz & lang"})[obj->query_eye_option("kurz")],39)+"|");
	SPALTE2
	W(left("       Flucht-Modus   : " +
	    ((tmp=obj->query_whimpy())?"an ("+tmp+")":"aus"),39)+"|");
	SPALTE2
	W(left("       Verteid.-Modus : " +(obj->query_reattack()?"an":"aus"),39)+"|");
	SPALTE2
	if (obj->query_con_close())
	{
	    W(left("       "+Er(obj)+" ist "+
		(obj->query_ghost()?"ein Geist.":"geschlossen worden.")
		,39)+"|");
	    SPALTE2
	}
    }
    while (nr<num_hands)
    {
	W(copies(" ",39)+"|");
	do_waffe(waffe[nr],nr,obj);
	nr++;
    }
    if (nr2<0)
    {
	W(copies(" ",39)+"|");
	do_ruestung(0,nr2,r);
	nr2++;
    }
    while (nr2<num_ruest)
    {
	W(copies(" ",39)+"|");
	do_ruestung(ruest[nr2],nr2,0);
	nr2++;
    }
    tmpm = obj->query_damage_percentages();
    if (mappingp(tmpm) && sizeof(tmpm))
    {
        WLN(left(LINE[1..3]+" query_damage_percentages "+LINE,79));
        W(wrap(implode(m_values(map(tmpm, (: $1+"="+$2 :))),", ")));
    }
    W(LINE);
}

#define FCLN(x) wrap(arg?(closurep(x)?mixed2str(x):x):funcall(x,ob))
#define FCLN2(x) wrap(arg?(closurep(x)?mixed2str(x):x):funcall(x,ob,this_player()))
#define FCLNR(x) wrap(arg?(closurep(x)?mixed2str(x):x):funcall(x,0,0,ob,this_player()))
#define FC(x) (arg?(closurep(x)?mixed2str(x):x):funcall(x,ob))
#define V_JUNK ({"long","smell","feel","read","name","gender","id","environment"})

private void do_info_mapping(mapping ob, string args)
{
    string *ind;
    mixed tmp;
    int arg, i;

    if (member(args,'m')>=0)
    {
	switch(params["print"])
	{
	  case "printf":
	    W(sprintf("%O\n",ob));
	    break;
	  case "none":
	    WLN(mixed2str(ob));
	    break;
	  default:
	    W(wrap(mixed2str(ob),79));
	}
	return;
    }

    arg=(member(args,'c')>=0);

    if (tmp=ob["long"])
	W(left(LINE[1..3]+" LONG "+LINE,79)+"\n"+FCLN2(tmp));
    if (tmp=ob["read"])
	W(left(LINE[1..3]+" READ "+LINE,79)+"\n"+FCLNR(tmp));
    if (tmp=ob["smell"])
	W(left(LINE[1..3]+" SMELL "+LINE,79)+"\n"+FCLN(tmp));
    if (tmp=ob["feel"])
	W(left(LINE[1..3]+" FEEL "+LINE,79)+"\n"+FCLN(tmp));
    if (tmp=ob["noise"])
	W(left(LINE[1..3]+" NOISE "+LINE,79)+"\n"+FCLN(tmp));

    W(LINE);

    if (tmp=ob["name"])
	WLN("Name:       "+FC(tmp));
    if (tmp=ob["id"])
	W(sprintf("Id:         %-=67s\n",
	    arg && closurep(tmp)?mixed2str(tmp):implode(tmp,", ")));
    if (tmp=ob["gender"])
	WLN("Geschlecht: "+FC(tmp));
    if (tmp=ob["environment"])
	W(sprintf("Umgebung:   %-=67s\n", mixed2str(tmp)));

    ind=m_indices(ob);
    for (i=0; i<sizeof(ind); i++)
	if (member(V_JUNK,ind[i])<0)
	    W(sprintf("%-11s %-=67s\n",ind[i]+":",
		arg?mixed2str(ob[ind[i]]):mixed2str(funcall(ob[ind[i]],ob))));

    W(LINE);
}

/*
FUNKTION: query_info
DEKLARATION: string query_info()
BESCHREIBUNG:
Definiert ein Objekt eine solche Funktion, und liefert einen String zurueck,
so wird dieser String bei dem Zauberstabkommando 'zinfo <objekt>' angezeigt.

Dies ist vor allem fuer Debugging-Zwecke interessant. Der String sollte
idealerweise formatiert ausgegeben werden, damit er zur restlichen zinfo-
Ausgabe passt.

Beispiel in einem Raetsel-NPC:

string query_info()
{
    if(objectp(quester))
    {
        return wrap("Zur Zeit versucht "+der(quester)+", das Raetsel "
                    "zu loesen.");
    }
}

Ein Gott kann mit einem 'zinfo npc' dann sofort sehen, dass gerade jemand
das Raetsel loest, ohne umstaendlich Funktionen (z.B. query_quester())
heraussuchen zu muessen, um an diese Information zu kommen.

ACHTUNG:
  Die von query_info() gelieferten Informationen sind nicht fuer Spieler!
  Zusatzinformationen fuer Spieler (Sehergilde) siehe query_seher_info().

VERWEISE: query_seher_info
GRUPPEN: grundlegendes
*/

int z_information(string str)
{
    mixed *ob;

    SECURE;
    HELP("zinformation");
    ob=get_com1(str,1);
    if (!ob[C_OBJ])
	return 0;
    if (mappingp(ob[C_OBJ]))
	do_info_mapping(ob[C_OBJ],ob[C_ARG]);
    else switch(ob[C_ARG])
    {
      case "s":
	do_info_spieler(ob[C_OBJ]);
	break;
      case "i":
	do_info_inherit_file(ob[C_OBJ],0);
	break;
      case "o":
	do_info_objekt(ob[C_OBJ]);
	break;
      default:
	if (living(ob[C_OBJ]))
	    do_info_spieler(ob[C_OBJ]);
	else if (strstr(FN(ob[C_OBJ]),"/i/")!=-1)
	    do_info_inherit_file(ob[C_OBJ],1);
	//else if (strstr(FN(ob[C_OBJ]),"/apps/")!=-1)
	//    do_info_inherit_file(ob[C_OBJ],0);
	else
	    do_info_objekt(ob[C_OBJ]);
    }
    PRINT;
    return 1;
}

int z_kommandos(string str)
{
   int i, count;
   mapping opt;
   object commander, action_holder, header;
   mixed *actions, *cmds, *types, *names, *obs, *len;
   string action_holder_string, action_string;

   SECURE;
   HELP("zkommandos");

   if(!str)
      str = MARK_ICON;
   if(!opt = getopt(str,
      (["t":0,    // Typen anzeigen
        "n":0,    // Funktionsnamen anzeigen
        "f":0,    // Filenamen anzeigen
        "l":0,    // entspricht -tn
        "o":"%s", // Nur Object -o <obj>'s Actions suchen
        "a":"%s", // Nach bestimmter Action -a <act> suchen (driver)
        "s":"%s", // Nach bestimmter Action -g <act> suchen (diese fkt, multi)
      ]), GO_FAILS))
      return 0;
   str = opt["args"] ? implode(opt["args"], " ") : MARK_ICON;

   // old style parsing
   sscanf(str, "%s %s", str, action_string);
   if(action_string)
      opt["a"] = ({ action_string });
   sscanf(str, "%s->%s", str, action_holder_string);
   if(action_holder_string)
      opt["o"] = ({ action_holder_string });

   if(!(commander = SO(str)) ||
      opt["o"] && !(action_holder = SO(opt["o"][0])))
      return 0;

   if(opt["a"])
   {
      if(!sizeof(actions = efun::query_actions(commander, opt["a"][0])))
         FAIL("Dieses Kommando ist nicht definiert.\n");
      WLN("Objekt:    "+OFN(actions[2]));
      WLN("Funktion:  "+actions[3]);
      WLN("Parameter: "+actions[0]+","+actions[1]);
      PRINT;
      return 1;
   }

   if(!(cmds = efun::query_actions(commander, 1)))
      FAIL("Keine Kommandos definiert.\n");
   if(opt["t"] || opt["l"])
      types = efun::query_actions(commander, 2);
   if(opt["n"] || opt["l"])
      names = efun::query_actions(commander, 16);
   if (opt["l"])
      len = efun::query_actions(commander, 4);
   obs = efun::query_actions(commander, 8);

   for(i = 0; i < sizeof(cmds); i++)
   {
      if(action_holder && action_holder != obs[i])
         continue;
      if(opt["s"] && strstr(cmds[i], opt["s"][0]) != 0)
         continue;
      if(header != obs[i])
      {
         header = obs[i];
	 if(!opt["f"] && !opt["s"])
	    WLN(OFN(header)+": "+Name(header));
      }
      count++;
      W(left("\""+cmds[i]+"\"",15)+" ");
      if(opt["t"] || opt["l"])
	 switch(types[i])
         {
            case SENT_PLAIN:      W(". "); break;
            case SENT_SHORT_VERB: W("* "); break;
            case SENT_NO_SPACE:   W("+ "); break;
            case SENT_NO_VERB:    W("- "); break;
            case SENT_MARKER:     W("@ "); break;
            default:              W("? "); break;
         }
      if (opt["l"])
	  W(sprintf("%2d ",len[i]));
      if(opt["f"] || opt["s"])
         W(object_name(obs[i])+" ");
      if(opt["n"] || opt["l"])
      {
         if(stringp(names[i]))
             W(names[i]+"() ");
         else
             W(sprintf("%Q",names[i]));
      }
      W("\n");
   }
   if(count > 10)
      WLN(""+count+" Kommandos gefunden.");
   if(!count)
      WLN("Keine Kommandos gefunden.");

   PRINT;
   return 1;
}

private string exit_flag_string(int flag)
{
   string *res;

   res = ({});
   if(flag & EXIT_ATOM_NOLIST)
      res += ({ "nl" });
   if(flag & EXIT_ATOM_HIDDEN)
      res += ({ "h" });
   if(flag & EXIT_ATOM_LOCKED)
      res += ({ "l" });
   if(flag & EXIT_ATOM_NOT)
      res += ({ "n" });
   if(flag & EXIT_ATOM_VIEW)
      res += ({ "v" });
   return implode(res,",");
}

int z_ausgaenge(string str)
{
    object obj;
    string *exits, *commands, *flags, name;
    int i,x,y;

    SECURE;
    HELP("zausgaenge");
    obj=SO(str);
    if (!obj)
	return 0;
    exits=obj->query_exit_list();
    commands=obj->query_command_list();
    flags=obj->query_flag_list();
    if (!exits || sizeof(exits) <= 0)
       FAIL(SHORT(obj)+" hat keine Ausgaenge.\n");
    W("Ausgaenge von "+FN(obj)+":\n");
    for (i=0; i<sizeof(exits); i++)
	W(sprintf("%-20s %=-40s %s\n",
	   commands[i],
	   sscanf(exits[i], "/map/m%d_%d", x, y) == 2 ?
	      get_map_file(exits[i])[12..<1] : exits[i],
	   exit_flag_string(to_int(flags[i]))));
    PRINT;
    return 1;
}

int z_map(string str)
{
    object ob;
    int tmp;

    SECURE;
    HELP("zmap");
    ob=SO(str);
    if (ob)
	if (sscanf(FN(ob),"%s#%d",str,tmp)==0)
	    str=FN(ob);
	else
	    FAIL(FN(ob)+" ist kein Raum.\n");

    if (!str || str[0..0]==MARK_ICON || str==ENV_ICON)
	return 0;
    str=ADD_PATH(str);

    W(LINE);
    WLN("File-Name:  "+str);
    str=get_map_file(str);
    if (str)
	WLN(str);
    else
	W("Kein Map-Raum.\n");
    W(LINE);
    PRINT;
    return 1;
}

int z_raetsel(string str)
{
    mixed *com;
    string *quests;
    int i, gesamt, points, spalte;
    object qobj;

    SECURE;
    HELP("zraetsel");
    com = get_com1(str);
    if(!com[C_OBJ])
       return 0;
    WLN(left("Raetsel",20)+right("Punkte",8)+right("(Max)",10)+" | "+
	  left("Raetsel",20)+right("Punkte",8)+right("(Max)",10));
    WLN(LINE[1..39]+"|"+LINE[1..39]);
    quests = sort_array(QUEST_ROOM->query_quest_objects(Q_ALL),
        (: $1->query_name() > $2->query_name() :));
    for(i = 0; i < sizeof(quests); i++)
       if((qobj = touch(quests[i])) &&
	  ((points = qobj->query_points(com[C_OBJ])) ||
	   com[C_ARG] == "a"))
       {
          gesamt = qobj->query_skill();
	  W(left(capitalize(qobj->query_name()),23)+
		right(points,5)+((points<gesamt)?" < ":"   ")+
		right("("+qobj->query_skill()+")",7));
	  W( (spalte ? "\n" : " | ") );
	  spalte = (spalte+1)%2;
       }
    if(spalte)
       W("\n");
    PRINT;
    return 1;
}

static int sort_short(string a, string b)
{
    return a->query_short() < b->query_short();
}

int z_spiele(string str)
{
    mixed *com;
    string *games;
    int i, gesamt, points, spalte;
    object gobj;

    SECURE;
    HELP("zspiele");
    com = get_com1(str);
    if(!com[C_OBJ])
       return 0;
    WLN(left("Spiele",20)+right("Punkte",8)+right("(Max)",10)+" | "+
	  left("Spiele",20)+right("Punkte",8)+right("(Max)",10));
    WLN(LINE[1..39]+"|"+LINE[1..39]);
    games = sort_array(GAME_ROOM->query_game_objects(),"sort_short");
    for(i = sizeof(games); i--;)
       if((gobj = touch(games[i])) &&
	  ((points = gobj->query_points(com[C_OBJ])) ||
	   com[C_ARG] == "a"))
       {
          gesamt = gobj->query_skill();
	  W(left(gobj->query_short(),23)+
		right(points,5)+((points<gesamt)?" < ":"   ")+
		right("("+gesamt+")",7));
	  W( (spalte ? "\n" : " | ") );
	  spalte = (spalte+1)%2;
       }
    if(spalte)
       W("\n");
    PRINT;
    return 1;
}

int z_gilde(string str)
{
    object ob;
    int level, tmp, *limits;
    string gilde, tmps;

    SECURE;
    HELP("zgilde");
    if (!str)
	str=MARK_ICON;
    if (!(ob = SO(str)))
       return 0;
    W(LINE);
    if(tmps = ob->query_gilden_info(GILDEN_NAME))
    {
       WLN("Gilde:         "+tmps);
       if(tmps = ob->query_gilden_info(FILE_NAME))
	  WLN("Gildenobjekt:  "+tmps);
       if(tmps = ob->query_gilden_info(AUTO_LOADER))
	  WLN("Autoloader:    "+tmps);
       if(tmps = ob->query_gilden_info(GILDEN_MEISTER))
	  WLN("Gildenmeister: "+capitalize(tmps));
       if(tmps = ob->query_gilden_info(MITGLIED))
	  WLN("Mitgliedsname: "+capitalize(tmps));
       W(LINE);
       if(tmps = ob->query_gilden_info(RANG))
       {
	  WLN("Rang:          "+tmps);
	  WLN("num. Rang:     "+ob->query_rang());
       }
    }
    else
    {
       WLN("Gilde:         --keine gueltige--");
       WLN("query_gilde(): "+ob->query_gilde());
       WLN("query_rang():  "+ob->query_rang());
    }
    W(LINE);
    PRINT;
    return 1;
}

private void writetab(string st, int a, int b)
{
    WLN(left(st,15)+" |" + right(""+a+" |",12) +
	right(""+b+" |",12) + right(""
	    +(b?(int)((((float)a)*100.0)/((float)b)):0)+"%",6));
}

int z_grad(string str)
{
    object obj;

    SECURE;
    HELP("zgrad");
    obj=SO(str);
    if (!obj)
	return 0;

    W(LINE);
    W(left(Name(obj),10));
    WLN("      |   Summe   |    Max    | Prozent");
    WLN("----------------|-----------|-----------|"+LINE[1..38]);
    writetab("Erfahrung:",obj->compute_one_skill(({"skill"})),
	TOTAL_EXPERIENCE);
    writetab("Waffen:",obj->compute_one_skill(({"skill","offensiv"})) +
	obj->compute_one_skill(({"skill","defensiv"})), MAX_SUM_WEAPON);
    writetab("Raetsel:",obj->compute_one_skill(({"skill","raetsel"})),
    	QUEST_ROOM->query_skill_quests());
    writetab("Spiele:",obj->compute_one_skill(({"skill","spiel"})),
    	GAME_ROOM->query_skill_games());
    writetab("Wissen:",obj->compute_one_skill(({"skill","wissen"})),
    	WISSEN_MASTER->query_soll_wissen());
    writetab("Zauber:",obj->compute_one_skill(({"skill","zauber"})),
    	MAX_SUM_ZAUBER);
    writetab("Ausdauer-Pkt:",obj->query_sum_hp(),MAX_SUM_HP);
    writetab("Zauber-Pkt:",obj->query_sum_sp(),MAX_SUM_SP);
    writetab("Gewicht:",obj->query_sum_weight(),MAX_SUM_WEIGHT);
    writetab("Kommunikation:",obj->query_sum_comm(),MAX_SUM_COMM);
    writetab("Gefuehle:",obj->query_sum_feel(),MAX_SUM_FEEL);
    writetab("Bewegungen:",obj->query_sum_move(),MAX_SUM_MOVE);
    writetab("Alter:",obj->query_age(),ADULT_AGE);
    W(LINE);
    WLN("Hinweis: Ausser bei Raetseln und Spielen sollen mit Erreichen der \"Max\"-");
    WLN("         Werte 80er Stats erreicht werden");
    PRINT;
    return 1;
}

int z_shadows(string str)
{
    object obj;
    mapping opts;

    SECURE;
    HELP("zshadows");
    
    opts = getopt(str, (["c":0]), 0);
    
    if(opts["errors"])
	return notify_fail(implode(map(opts["errors"], (:sprintf("zshadow: %-=69s\n",$1[0..<2]):)),""),
	    FAIL_WRONG_ARG);
    
    obj=SO(implode(opts["args"]||({})," "));
    if (!obj)
	return 0;
    if (!shadow(obj,0))
    {
	W(FN(obj)+" wird nicht geshadowed.\n");
	PRINT;
	return 1;
    }
    W("Shadows von "+FN(obj)+" :\n");
    while(obj=shadow(obj,0))
    {
       WLN(FN(obj));
       if(opts["c"])
          WLN("    Creator: "+obj->query_shadow_creator(obj));
    }
    PRINT;
    return 1;
}

int z_qspion(string str)
{
    object *us, ob;
    int i;

    SECURE;
    HELP("zqspion");

    if (str)
	return 0;
    us=users();
    for(i=0; i<sizeof(us); i++)
#if __EFUN_DEFINED__(query_snoop)
	if (ob=query_snoop(us[i]))
#else
	if (ob=interactive_info(us[i], II_SNOOP_NEXT))
#endif
	    WLN(left(Name(ob),15)+"--> "+Name(us[i]));
    PRINT;
    return 1;
}

int z_dbg_komm(string str)
{
    string *fun, *rul, *rulc;
    int i;
    object ob;

    SECURE;
    HELP("zdbg_komm");
    ob=SO(str);
    if (!ob)
	return 0;
    fun=ob->query_funcs();
    rul=ob->query_rules();
    rulc=ob->query_rules_case();
    if (!fun)
    {
	W("Monster hat keine Kommunikation.\n");
	PRINT;
	return 1;
    }
    WLN("Funktion:  rule: rule_case:");

    for (i=0; i<sizeof(fun); i++)
	W(sprintf("%-15s | %-35s | %s\n",to_string(fun[i]),to_string(rul[i]),
		to_string(rulc[i])));
    PRINT;
    return 1;
}


int z_dbg_hands(string str)
{
    int i, numh, fh, ff;
    object ob, *hobs, *henem;
    string *aggvic;

    SECURE;
    HELP("zdbg_hands");
    ob=SO(str);
    if (!ob)
	return 0;

    hobs=ob->query_hand_objects();
    henem=ob->query_hand_enemies();
    numh=ob->query_num_hands();
    aggvic=ob->query_aggression_victims();
    fh=ob->free_hand();
    ff=ob->free_fight();

    WLN("Anzahl Haende:    "+numh);
    WLN("Freie Hand:       "+fh);
    WLN("Freie Kampf-Hand: "+fh);
    if (hobs && sizeof(hobs))
    {
	W("Hand Objects:\n");
	for (i=0; i<sizeof(hobs); i++)
	    if (hobs[i])
		WLN(right(i,3)+": "+Name(hobs[i])+" "+FN(hobs[i]));
	    else
		W(right(i,3)+": 0\n");
    }
    if (henem && sizeof(henem))
    {
	W("Hand Enemies:\n");
	for (i=0; i<sizeof(henem); i++)
	    if (henem[i])
		WLN(right(i,3)+": "+Name(henem[i])+" "+FN(henem[i]));
	    else
		W(right(i,3)+": 0\n");
    }
    if (aggvic && sizeof(aggvic))
    {
	W("Aggression Victims:\n");
	for (i=0; i<sizeof(aggvic); i++)
		WLN(right(i,3)+": "+aggvic[i]);
    }
    PRINT;
    return 1;
}

int z_alter(string str)
{
   object ob;
   mixed  dates;
   int i;

   SECURE;
   HELP("zalter");

   if(!(ob = SO(str)))
      return 0;
   if(!playerp(ob))
      FAIL(Name(ob)+" ist kein Spieler.\n");

   dates = ob->query_level_dates();

   W(LINE);
   WLN("Lebenslauf von "+capitalize(ob->query_real_name()));
   W(LINE);
   for(i = 0; i < sizeof(dates); i++)
      W(sprintf("%2d:  %s%-30s\n",
	 dates[i][LVL_D_LEVEL],
	 dates[i][LVL_D_DATE] ?
                " "+shorttimestr(dates[i][LVL_D_DATE])+"    " :
                "<"+shorttimestr(DATUM_KONV_VOLLST_LEBENSLAEUFE)+"   <",
	 dates[i][LVL_D_AGE] ? format_seconds( dates[i][LVL_D_AGE]) : ""));

   W(LINE);
   W(sprintf("%2d:   %s    %-30s\n",
      ob->query_level(),
      shorttimestr(time()),
      format_seconds(ob->query_age())));
   W(LINE);
   W(sprintf ("Diesen Monat in UNItopia:  %s\n",
      "/apps/statistik"->query_month_time_of(ob) || ""));
   W(LINE);
   PRINT;
   return 1;
}

#define SLEEP_TIME 120 /* Ab welcher Zeit gilt man als schlafend */

int z_idle(string str)
{
   object *userlist;
   int i, pennzeit;
   string rname, away;
   int idleout;

   SECURE;
   HELP("zidle");

   idleout = SLEEP_TIME;
   if(str && sscanf(str, "%d", idleout))
      idleout *= 60;

   if(userlist = sort_array(users(),
      lambda(({'a,'b}), ({ #'<, ({ #'call_other, 'a, "query_real_name" }),
				({ #'call_other, 'b, "query_real_name" }) }))))
      for(i = sizeof(userlist); i--;)
	 if(rname = userlist[i]->query_real_name())
	    if(!interactive(userlist[i]))
	       WLN(left(capitalize(rname),15)+" nicht interaktiv");
	    else if((pennzeit = query_idle(userlist[i])) >= idleout)
	       WLN(left(capitalize(rname),15)+" "+
		     format_seconds(pennzeit/60*60)+
		     ((away = userlist[i]->query_away()) ? " ("+away+")":""));
   PRINT;
   return 1;
}

int z_suche(string str)
{
   object * list, * obs;
   int i, anz;
   string str1, str2, stra;

   SECURE;
   HELP("zsuche");

   if(!str)
      FAIL("zsuche <id>\n");
   if(list = users())
      for(i = 0; i < sizeof(list); i++)
      {
         obs = filter_objects(deep_inventory(list[i]),"id",str);
         if(sizeof(obs))
         {
            W(sprintf("%=-10s %=-68s\n", list[i]->query_real_cap_name(),
              implode(map(obs,
                  (:
                      $2=$1->query_short(this_player());
                      $3=object_name($1);
                      if(strlen($2)>34 || strlen($3)>33)
                            return $2+"\n"+$3;
                      else
                            return sprintf("%-34s %-1.33s",$2,$3);
                  :)),"\n")));
            anz+=sizeof(obs);
         }
      }
   if(!anz)
      WLN("Keine Objekte mit dieser ID bei den Spielern gefunden.");
   PRINT;
   return 1;
}

#ifdef CREATE_TRACES
private string format_trace(string tr, string rtr)
{
   string *trs, *rtrs, *res;
   int i;

   for(res = ({}), trs = explode(tr,"|"), rtrs = explode(rtr||"|","|"), i = 0; i < sizeof(trs); i++)
      switch(trs[i])
      {
	 case TR_NO_ENVIRONMENT:
	    res += ({"Nirwana"}); break;
	 case TR_MAGIC_MOVE:
	    if(!strstr(rtrs[i],"/obj/flugraum"))
		res += ({"Flugraum"});
	    else
		res += ({"Irgendwo"});
	    break;
         default:
	    res += ({capitalize(trs[i])}); break;
      }
   return implode(res, " - ");
}

private string format_trace_delay(int delay)
{
   if (delay/86400 > 0)
      return right(delay/86400,3)+"D";
   if (delay/3600 > 0)
      return right(delay/3600,3)+"h";
   if (delay/60 > 0)
      return right(delay/60,3)+"m";
   if(!delay)
      return "-";
   return right(delay,3)+"s";
}

int z_trace(string str)
{
   object obj;
   mixed *visitors;
   mapping traces;
   string *idxs;
   int i;

   SECURE;
   HELP("ztrace");

   if(!(obj = SO(str)))
      return 0;
   if(!obj->query_room())
      FAIL(FN(obj)+" ist kein Raum.\n");

   WLN("Statistik fuer die verschiedenen Spuren:");
   WLN("Spur                  Anz  Paus Datum             Name       Objekt");
   WLN("--------------------- ---- ---- ----------------- ---------- "
       "------------------");
   traces = obj->query_traces() || m_allocate(0, TRT_WIDTH);
   for(i = sizeof(idxs = sort_array(m_indices(traces),#'<)); i--;)
   {
      W(sprintf("%-=21s %4d %4s %s %-=10s %-=18s\n",
         format_trace(idxs[i], 0),
	 traces[idxs[i], TRT_COUNT],
	 format_trace_delay(traces[idxs[i], TRT_STAT]),
	 shorttimestr(traces[idxs[i], TRT_TIME]),
	 capitalize(traces[idxs[i], TRT_NAME]),
	 traces[idxs[i], TRT_WHO] ? object_name(traces[idxs[i], TRT_WHO]) : "-"));
   }

   W("\nLetzte Besucher dieses Raumes:\n");
   W("Name       Datum             Spur                  Objekt\n");
   W("---------- ----------------- --------------------- "
       "----------------------------\n");
   visitors = obj->query_visitors() || ({});
   for(i = sizeof(visitors); i--;)
   {
      W(sprintf("%-=10s %s %-=21s %-=28s\n",
         (sizeof(visitors[i])>TRV_REAL_DESC && visitors[i][TRV_REAL_DESC])
	 ?(visitors[i][TRV_REAL_DESC]["cap_name"]||capitalize(visitors[i][TRV_REAL_DESC]["name"]))
	 :(sizeof(visitors[i])>TRV_DESC)
	 ?(visitors[i][TRV_DESC]["cap_name"]||capitalize(visitors[i][TRV_DESC]["name"]))
	 :capitalize(visitors[i][TRV_NAME]),
	 shorttimestr(visitors[i][TRV_TIME]),
	 format_trace(visitors[i][TRV_TRACE], sizeof(visitors[i])>TRV_TRACE_ROOMS && visitors[i][TRV_TRACE_ROOMS]),
	 visitors[i][TRV_WHO] ? object_name(visitors[i][TRV_WHO]):"-"));
   }

   PRINT;
   return 1;
}
#endif

int z_statistik(string str)
{
   string *text;
   int i;

   SECURE;
   if (!str || str == "") str = "?";
   HELP("zstatistik");

   if ((str == "g") || (str == "gilden"))
      text = STATISTIK->query_gilden_statistik();
   else if ((str == "t") || (str == "tod") || (str == "tode")
       || (str == "todesursachen"))
      text = STATISTIK->player_died_statistik();
   else if ((str == "b") || (str == "bruellen") || (str == "gebruell")
       || (str == "bruellerei") || (str == "bruell"))
      text = STATISTIK->query_brueller_statistik();
   else if (str && !strstr("monats",str))
      text = STATISTIK->query_monats_statistik();
   else if ((str == "r") || (str == "rettung") || (str == "rettungen"))
      text = STATISTIK->player_saved_statistik();
   if (text) {
      for (i=0; i < sizeof(text); i++)
         WLN(text[i]);
      PRINT;
      return 1;
   }
   notify_fail ("Dafuer gibts keine Statistik.\n");
   return 0;
}

int z_kuerzel(string str)
{
    string* param;
    
    SECURE;
    if(!strlen(str))
	str = "?";
    HELP("zkuerzel");
    
    param = explode(space(str)," ");
    if(sizeof(param)!=2)
	return notify_fail("zkuerzel <spieler> <kuerzel>\n", FAIL_WRONG_ARG);

    param[0] = lower_case(param[0]);
    if(!player_exists(param[0]))
	return notify_fail(wrap("Spieler '"+param[0]+"' existiert nicht."));
    W(wrap(PLAYER_READER->alias_exists(param[0], param[1])
	?("Ja, "+capitalize(param[0])+" besitzt ein Kuerzel '"+param[1]+"'.")
	:("Nein, "+capitalize(param[0])+" hat kein Kuerzel '"+param[1]+"'.")));
    PRINT;
    return 1;
}

int z_client(string str)
{
    object pl;
    
    SECURE;
    if (!adminp(OWN))
    {
        return 0; // reiner adminbefehl.
    }
    if(!strlen(str))
        str = "?";
    HELP("zclient");
    
    if (str == "-a")
    {
        foreach (pl : sort_array(users(),
                (: $1->query_real_name() > $2->query_real_name() :) ))
        {
            W(sprintf("%11s: %s\n",capitalize(pl->query_real_name()),
                pl->query_telnet_client()));
        }
        PRINT;
        return 1;
    }
    
    pl = find_player(lower_case(space(str)));
    if (pl)
        W("Client: \""+pl->query_telnet_client()+"\"\n");
    else
        W("Spieler nicht gefunden.\n");
    PRINT;
    return 1;
}
