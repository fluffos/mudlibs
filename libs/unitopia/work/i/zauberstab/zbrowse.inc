// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zbrowse.inc
// Description: Browsercode: volk, zinhalt, zausruestung
// Author:	Garthan (23.12.93) volk
// Modified by:	Garthan (15.02.94) zinhalt, zausruestung
//              Garthan (03.12.96) apply(#'sprintf, fmt, array)
//              Parsec  (27.06.00) MAX_SUM_WISSEN -> query_soll_wissen()
//
// $Log: zbrowse.inc,v $
// Revision 1.16  2007/12/05 11:03:54  gnomi
// Absicherung gegen falsche Uebergabe der w-Option.
//
// Revision 1.15  2007/05/26 22:52:35  gnomi
// Indexing past string end.
//
// Revision 1.14  2005/08/25 22:21:39  gnomi
// Indexing past string end...
//
// Revision 1.13  2004/08/21 22:34:20  gnomi
// Leeres 'index'-Array verhindern.
//
// Revision 1.12  2002/11/09 02:47:18  gnomi
// Man kann eine kleinere Spaltenbreite angeben, als man den Text abschneiden
// laesst, damit man diese mehrzeilig im Tabellenmodus ausgeben lassen kann.
//
// Revision 1.11  2002/04/10 05:19:43  gnomi
// Einige Variableninitialisierungen wegen Typcheck getrennt.
//
// Revision 1.10  2001/03/15 14:59:54  freaky
// geshadowte Variablen rausgenommen.
//
// Revision 1.9  2001/03/01 23:25:56  gnomi
// Beim Anhaengen des Sortierfeldes zu den anzuzeigenden Feldern testen,
// dort beim Testen, ob dieses Feld schon angezeigt wird, schauen, ob das Feld
// einen Modifier hat. (falls nicht, geht ein einfaches strstr nicht mehr.)
//
// Revision 1.8  2001/02/28 23:12:46  sissi
// Formatierung mit (30.30), was eine Spalte auf Breite 30 setzt und auch
// nach 30 Zeichen abschneidet und nicht in die folgende Zeile geht, eingebaut.
//
// Revision 1.7  2001/02/24 16:18:14  freaky
// bei volk -t auch die Monats-Statistik ausgeben.
//
// Revision 1.6  2001/02/18 00:12:26  sissi
// Gilden - Mitgliedsname und Level - Klartext als weitere Volk Moeglichkeiten.
//
// Revision 1.5  2001/02/14 02:37:27  gnomi
// Neue Option -w und -H. Format der vordefinierten Formatierungen geaendert.
// Ein paar neue Felder fuer den volk-Befehl.
//
// Revision 1.4  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strong_types

// infos struct
#define I_FUNC 0
#define I_REPLACER 1
#define I_PREFIX 2
#define I_LEN 3
#define I_TYPE 4
#define I_HEADER 5
#define I_DOC 6

#define G_OPTION 0
#define G_FORMAT 1
#define G_SORT 2

#define MODIFIER (['*','+','-'])

#define PART(o,i) ({#'o,({#'[,'a,i}),({#'[,'b,i})})


// ------------ SORTER CODE (browser)------------------------------

#define INVERT_KEY "!"

private int invers_sort;

// Closuregenerator fuer Multiple Column Sort
// Die Closure hat ungefaehr folgendes Aussehen:
//   a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]) || (a[0]==b[0] && a[1]==b[1] && a[2]<b[2]) || ...
private closure get_multi_sorter(string sort, string *index,
				 int depth, string sort_text, mapping infos)
{
   int i, j, pos, *deps, invers;
   mixed *ret, zw;
   string * sort_info;
   string feld;
   /*
      deps sind alle Indizes, die beim naechsten || gleich bleiben muessen.
   */

   for(i = 0, ret = ({ #'|| }), sort_info = ({}), deps = ({}); i < strlen(sort); i++)
      if(sort[i..i] == INVERT_KEY)
	 invers = 1;
      else
      {
         feld=sort[i..i];
	 if(i+1<strlen(sort) && member(MODIFIER,sort[i+1]))
	 {
	    feld+=sort[i+1..i+1];
	    i++;
	 }
	 if((pos = member(index, feld)) >= 0)
	 {
	    invers ^= invers_sort;
            if(sizeof(deps))
            {
               for(j = 0, zw = ({ #'&& }); j < sizeof(deps); j++)
                  zw += ({PART(==,deps[j])});
	       zw += ({ invers ? PART(<,pos) : PART(>,pos) });
	       ret += ({ zw });
	    }
	    else
	       ret += ({ invers ? PART(<,pos) : PART(>,pos) });
            deps += ({ pos });
	    sort_info += ({(invers?"!":"") + infos[feld][I_DOC]});
	    invers = 0;
         }
      }
   depth = sizeof(sort_info);
   sort_text = depth ? implode(sort_info, ", "): 0;
   return lambda(({'a,'b}),ret);
}

private void sort_data(string sort, string *defsort, string *index, mixed *data,
		  string sort_text, mapping infos)
{
   int i, depth, keylen;
   closure sorter;

   if(sort == "!")
      sort_text = 0;
   else
   {
      depth = 1;
      // Von sort alle ! und Modifier abziehen.
      // Dann ist die Stringlaenge gleich der Anzahl an Feldern, 
      // die bei der Sortierung beachtet werden.
      keylen = strlen((sort||"")-INVERT_KEY-to_string(m_indices(MODIFIER)));
      if(sort)
	 sorter = get_multi_sorter(sort, index, &depth, &sort_text, infos);
      for(i = 0; depth != keylen && i < sizeof(defsort); i++)
      {
	 sort = defsort[i];
         keylen = strlen((sort||"")-INVERT_KEY-to_string(m_indices(MODIFIER)));
	 sorter = get_multi_sorter(sort, index,&depth,&sort_text,infos);
      }
      if(depth != keylen)
      {
	 sort = index[0];
	 keylen = 1;
	 sorter = get_multi_sorter(sort, index,&depth,&sort_text,infos);
      }
      if(depth != keylen)
	 sort_text = 0;
      else
	 data = sort_array(data, sorter);
   }
}

// ------------ BROWSER CODE (volk && zinhalt) --------------------

private int browser_options(mapping opts, string spec, string sort,
			    mapping infos, mapping groups, string verb, string bef)
{
   int i;
   string *infos_idxs, tmp;
   mixed *data, *info;

   if(opts["errors"])	// GET_OPT_ERRORS?
   {
      for(i = 0; i < sizeof(opts["errors"]); i++)
	 W(verb+": "+opts["errors"][i]);
      PRINT;
      return 1;
   }
   if(opts["h"])	// SHOW_FORMAT_INFO?
   {
      for(i = sizeof(infos_idxs = sort_array(m_indices(infos), #'<)); i--;)
      {
	 info = infos[infos_idxs[i]];
	 W(sprintf(" %-2s : %-8s %s\n", infos_idxs[i],
	    sprintf("\"%%%s%d%s\"",info[I_PREFIX],info[I_LEN],info[I_TYPE]),
	    info[I_DOC]));
      }
      PRINT;
      return 1;
   }
   if(stringp(opts["w"])) // Neue Formatierung eintragen
   {
      if(sizeof(opts["w"])<3 || !strlen(opts["w"][1]-"-"))
      {
         if(member(params[bef]||([]),opts["w"][0]))
	 {
             set_param(bef,(params[bef]||([]))-([opts["w"][0]]));
	     W("Formatierung '"+opts["w"][0]+"' entfernt.\n");
	 }
	 else
	     W("Eine Formatierung '"+opts["w"][0]+"' gibt es nicht.\n");
      }
      else
      {
         if(!strlen(opts["w"][2]-"-"))
	 opts["w"][2]=0;
         set_param(bef,(params[bef]||([]))+([opts["w"][0]:opts["w"][1];opts["w"][2]]));
         W("Formatierung '"+opts["w"][0]+"' eingetragen.\n");
      }
      PRINT;
      return 1;
   }
   groups+=params[bef]||([]);
   if(opts["H"])  // Alle Formatierungen anzeigen
   {
      if(!sizeof(groups))
         W("Keine Formatierungen eingetragen.\n");
      else
      {
         mixed gtmp=sort_array(m_indices(groups),#'>);
	 W("Kuerzel Formatierung                                  Sortierung\n"
	   "------- --------------------------------------------- --------------------\n");
         foreach(string k:gtmp)
            W(sprintf("%-7s %-45s %-20s\n",k,groups[k,0],groups[k,1]||""));
      }
      PRINT;
      return 1;
   }
   
   i=0;

   foreach(string kuerzel,string f, string s:groups)
   {
       if(opts[kuerzel])
       {
           spec=f;
	   sort=s;
	   i=1;
	   break;
       }
   }
   
   if(!i && member(groups,"-"))
   {
       spec=groups["-",0];
       sort=groups["-",1];
   }
   
   if(data = opts["f"])	// FORMAT?
      spec = data[0];

   if(data = opts["S"])	// SORTER?
      sort = data[0];
   invers_sort = opts["R"] ? 1 : 0;
}

private void make_header(string spec, mapping str,
                         string *index, string format,
                         closure *funcs, closure *repls, int *sizes,
			 mapping infos)
{
   int i, f, g;
   string header, forms, line, feld;
   mixed *info;

   format = header = forms = line = "";
   index = ({});
   funcs = ({});
   repls = ({});
   sizes = ({});

   for(i = 0; i < strlen(spec); i++)
   {
      feld = spec[i..i];
      if(i+1<strlen(spec) && member(MODIFIER,spec[i+1]))
      {
         feld += spec[i+1..i+1];
	 i++;
      }
      if(info = infos[feld])
      {
         f = info[I_LEN];
	 g = 0;
         index  += ({feld});
         if(i+1<strlen(spec) && spec[i+1] == '(') {
            i += str2int(spec[i+2..], &f) + 1;
	    if (spec[i] == '.')
		i += str2int(spec[i+1..],&g);
	 }

	 if((f > 0)&&(g > 0)&&(g>f))
	 {
	    sizes += ({g});
	    g=0;
	 }
	 else
	    sizes += ({0});

         if((f > 0)&&(g > 0))
         {
	    format += "%"+implode(explode(info[I_PREFIX],"")-({"="}),"")+to_string(f)+"."+to_string(g)+info[I_TYPE];
	    header += sprintf("%"+implode(explode(info[I_PREFIX],"")-({"="}),"")
				 +"*.*s",f,g,info[I_HEADER]);
	    line   += sprintf("%'-'*.*s",f,g,"");
	    forms  += sprintf("%*.*-s",f,g,feld);
         }
         else if(f > 0)
         {
	    format += "%"+info[I_PREFIX]+to_string(f)+info[I_TYPE];
	    header += sprintf("%"+implode(explode(info[I_PREFIX],"")-({"="}),"")
				 +"*.*s",f,f,info[I_HEADER]);
	    line   += sprintf("%'-'*s",f,"");
	    forms  += sprintf("%*-s",f,feld);
         }
         funcs  += ({ info[I_FUNC] });
         repls  += ({ info[I_REPLACER] });
      }
      else
      {
         header += spec[i..i];
         line   += spec[i..i];
         format += spec[i..i];
	 forms  += spec[i..i];
      }
   }
   
   if(!sizeof(index))
   {
      index += ({ "N" });
      sizes += ({ 0 });
      funcs += ({ infos["N"][I_FUNC] });
      repls += ({ infos["N"][I_REPLACER] });
   }

   /* ===== Header ausgeben */

   if(!str["n"] && !str["k"])   // !NO_HEADER && !KURZ ?
   {
      WLN(header);
      if(str["i"])		// INFO_LINE?
	 WLN(forms);
      WLN(line);
   }
}

private mixed *retrieve_data(object *pls, closure *funcs)
{
   int i, f, min_evals, s;
   mixed *data, *set;

   // Freaky: Damit es keine too long evals gibt
   min_evals=sizeof(funcs)*sizeof(pls)*30;

   s = sizeof(pls);
   data = ({});
   // finger weg!
   for(i = 0; i < s; i++)
   {
      set = allocate(sizeof(funcs)+1);
      for(f = 0; f < sizeof(funcs); f++)
      {
	 if(funcs[f])
	    set[f] = funcall(funcs[f], pls[i]);
	 else
	    set[f] = i;
      }
      set[sizeof(funcs)] = pls[i];
      data += ({ set });
      if(get_eval_cost() < min_evals)
      {
	 WLN("Unvollstaendige Liste! "+(s-i-1)+" Eintraege fehlen.");
	 break;
      }
   }
   return data;
}

private void format_data(mixed *data, closure *repls)
{
   int f, anz, i;
   for(f = anz = sizeof(repls); f--;)
      if(repls[f])
         for(i = sizeof(data); i--;)
            data[i][f] = funcall(repls[f], data[i][f], data[i][anz]);
}

// ------------ VOLK-BEFEHL ----------------------------------------

// Levelfilter fuer -l
int f_level(object who, int min, int max)
{
   int l;
   l = who->query_level();
   return l >= min && l <= max;
}

private string listing_type(mapping opts)
{
   if(opts["P"])
      return "Spieler";
   if(opts["p"])
      return "Sterbliche";
   if(opts["g"])
      return "Goetter";
   if(opts["G"])
      return "Gaeste";
   if(opts["l"])
      return "Ausgesuchte";
   return "Leute";
}

private int is_guest(object ob)
{
   return guestp(ob);
}

private int volk_options(mapping opts, object *pls, string spec, string sort,
			 mapping infos, mapping groups)
{
   int i;
   mixed *data;

   if(browser_options(opts, &spec, &sort, infos, groups, query_verb(), "volk"))
      return 1;
   if(opts["k"])	// KURZ?
      spec = "Nl(0)";
   if(!opts["a"])
   {
      if(opts["p"])	// PLAYER_FILTER?
	 pls -= filter_objects(pls, "query_wiz_level");
      else if(opts["g"])	// WIZ_FILTER?
	 pls  = filter_objects(pls, "query_wiz_level");
      else if(opts["G"])
	 pls = filter(pls, #'is_guest);
      else if(opts["P"])
	 pls = filter(pls, "f_level", TO, LVL_PLAYER, LVL_PLAYER);
      if(data = opts["l"])	// LEVEL_FILTER?
      {
	 if(data[0] > data[1])
	    i = data[0], data[0] = data[1], data[1] = i;
	 pls = filter(pls, "f_level", TO, data[0], data[1]);
      }

   }
   if(opts["t"])	// TOTALS?
   {
	W("Zur Zeit sind es "+sizeof(pls)+" "+listing_type(opts)+". ("+
		query_load_average()+")\n");
        W("Heute waren bisher "
            +STATISTIK->query_sum_users()+
            " Leute in " MUD_NAME ", maximal "
            +STATISTIK->query_max_users()
            +" gleichzeitig.\nDiesen Monat waren bisher " +
	    STATISTIK->query_sum_users_month()+
            " Leute in " MUD_NAME ".\nRekord: "
            +STATISTIK->query_max_users_ever()+
            " Spielende am "+
            timestr(STATISTIK->query_max_users_ever_time())+
            ".\n");
      PRINT;
      return 1;
   }
}


// Hauptfunktion des Volkbefehls
int f_volk(string str)
{
   int i, anz;
   string out;
   string  spec, sort, *def_sort, format, *index, sort_text;
   object  *pls;
   mixed   *data;
   mapping groups;
   mapping opts, infos;
   closure *funcs, *repls;
   int *sizes;

   SECURE;
   HELP("volk");

   infos    = query_volk_infos();    // Eintraege der verfuegbaren "Spalten"
   groups   = query_volk_groups();   // Vordefinierte Formate. aus zvolk.inc
   spec     = "N l+ a IFEVZMP e";     // Defaultformatstring
   def_sort = ({"lN","ln","l+N","l+n","l*N","l*n","N","n"}); // Defaultsortierungen
   opts     = getopt(str, (["f":"\"%s\"", "S":"%s", "l":"%d %d",
                            "w":"%1s \"%s\" %s"]), GO_SLOPPY);
   pls      = users();

   if(volk_options(opts, &pls, &spec, &sort, infos, groups))
      return 1;

   // Sortierfeleder anhaengen an spec falls nicht enthalten.
   if(sort)
      for(i = 0; i < strlen(sort); i++)
      {
         string tmp;
	 if(sort[i..i] == INVERT_KEY) continue;
	 if(i+1<strlen(sort) && member(MODIFIER,sort[i+1]))
	 {
	    tmp=sort[i..i+1];
	    i++;
	 }
	 else
	    tmp=sort[i..i];
	    
	 if((anz=strstr(spec, tmp)) < 0) // Feld, nach dem sortiert wird
	    spec += tmp+"(0)";           // muss auch ermittelt werden
	 else if(strlen(tmp)==1)         // aber nicht anzeigen (0).
	 {
	    while(anz+1<strlen(spec) && member(MODIFIER,spec[anz+1]))  
						 // Schauen, ob Feld auch
		anz=strstr(spec,tmp,anz+1);      // ohne MODIFIER vorkommt.
	    if(anz<0)
		spec += tmp+"(0)";
	 }
      }

   make_header(spec, opts, &index, &format, &funcs, &repls, &sizes, infos);

   if(member(index,"H")>=0)
   {
      max_quest = QUEST_ROOM->query_skill_quests();
      max_game  = GAME_ROOM->query_skill_games();
      soll_wissen  = WISSEN_MASTER->query_soll_wissen();
   }

   data = retrieve_data(pls, funcs);

   sort_data(sort, def_sort, index, &data, &sort_text, infos);
   format_data(&data, repls);

   if(!opts["k"])
   {
      for(i = 0, anz = sizeof(data); i < anz; i++)
      {
         for(int j=0;j<sizeof(sizes);j++)
	    if(sizes[j])
		data[i][j] = data[i][j][0..sizes[j]-1];
	 W(apply(#'sprintf, format+"\n", data[i]));
      }
   }
   else
   {
      out = "";
      for(i = 0, anz = sizeof(data); i < anz; i++)
	 out += data[i][0]+"\n";
      W(sprintf("%#-79s\n",out));
   }
   if(sizeof(data) > 1)
      WLN("Zur Zeit sind es "+sizeof(data)+" "+listing_type(opts)+
	     (sort_text ? ", sortiert nach " + sort_text : " unsortiert")+".");
   if (!opts["k"])
      WLN ("Heute gleichzeitig: "+STATISTIK->query_max_users()+
           ", insgesamt: "+STATISTIK->query_sum_users()+
           ", Monat: "+STATISTIK->query_sum_users_month()+
           ", jemals gleichzeitig: "+STATISTIK->query_max_users_ever());
   PRINT;
   return 1;
}

// ------------ INHALT-BEFEHL --------------------------------------


private int
recurse_inhalt(object what, int depth, closure *funcs, closure *repls, int *sizes,
	       string *def_sort, string sort, string *index, string format,
	       mapping infos, int recurse, string sort_text)
{
   object  *pls;
   mixed *data;
   int i, anz, sub;

   data = retrieve_data(pls = all_inventory(what), funcs);
   sort_data(sort, def_sort, index, &data, &sort_text, infos);
   format_data(&data, repls);

   // print data
   for(i = 0, anz = sizeof(data); i < anz; i++)
   {
      for(int j=0;j<sizeof(sizes);j++)
         if(sizes[j])
	    data[i][j] = data[i][j][0..sizes[j]-1];
      W(apply(#'sprintf, copies("  ",depth)+format+"\n", data[i]));

      if(recurse)
	 sub += recurse_inhalt(data[i][sizeof(index)], depth+1,
		      funcs,repls,sizes,def_sort,sort,index,format,infos,1,sort_text);
   }
   return sub+anz;
}

// Hauptfunktion des Inhaltbrowsers
private int inhalt(string str)
{
   int anz;
   string  spec, sort, *def_sort, format, *index, sort_text;
   mixed   *data;
   mapping groups;
   mapping opts, infos;
   closure *funcs, *repls;
   int *sizes;
   object who;

   infos    = query_inv_infos();    // Eintraege der verfuegbaren "Spalten"
   groups   = query_inv_groups();   // Vordefinierte Formate. aus zvolk.inc
   spec     = "# N i O";            // Defaultformatstring
   def_sort = ({"!"});              // Defaultsortierungen
   opts     = getopt(str, (["f":"\"%s\"", "s":"%s", "S":"%s"]), GO_SLOPPY);

   if(browser_options(opts, &spec, &sort, infos, groups, query_verb(), "inhalt"))
      return 1;
   if(!(who = SO(sizeof(data = opts["args"]) ? data[<1] : MARK_ICON)))
      return 0;
   make_header(spec, opts, &index, &format, &funcs, &repls, &sizes, infos);
   anz = recurse_inhalt(who, 0,
			funcs, repls, sizes, def_sort, sort, index, format, infos,
		        opts["r"], &sort_text);
   if(!anz)
   {
      if (who->query_name())
      {
	 if(living(who))
	    notify_fail(Der(who,"")+" hat nichts bei sich.\n");
	 else
	    notify_fail(Der(who,"")+" enthaelt nichts.\n");
      }
      else
	 notify_fail(Name(who)+" enthaelt nichts.\n");
      return 0;
   }
   if(sort_text && sort_text != "Lfd. Nummer" ||
      opts["r"] || member(index,"#") < 0)
   WLN(""+anz+" Objekte"+(sort_text?" sortiert nach "+sort_text:"")+".");

   PRINT;
   return 1;
}

// Kommando zausruestung
int z_ausruestung(string str)
{
   SECURE;
   HELP("zausruestung");
   return inhalt("-a"+(str?" "+str:""));
}

// Kommando zinhalt
int z_inhalt(string str)
{
   SECURE;
   HELP("zinhalt");
   return inhalt(str);
}
