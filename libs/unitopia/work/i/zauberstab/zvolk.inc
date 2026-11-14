// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /i/zauberstab/zvolk.inc
// Description: Volk-Befehl, Infofunktionen
// Author:      Garthan (28.12.93)
// Modified by: Parsec  (11.03.99) V_SHIMMER und Kontinente eingefuehrt
//              Parsec  (27.06.00) MAX_SUM_WISSEN -> query_soll_wissen()


#pragma strong_types

private int max_quest, max_game, soll_wissen;

private int percent(int wert, int max)
{
    if(wert > MAX_INT/100)
	return (wert/(max/100));
    else
	return ((wert*100)/max);
}

private string i_name(object who)
{
   return capitalize(who->query_real_name());
}

private string r_name(string name, object who)
{
   return check_invis(who->query_invis(), name);
}

private int i_invis(object who)
{
   switch(who->query_invis())
   {
      case V_VIS:     return ' ';
      case V_NOLIST:  return 'N';
      case V_HIDDEN:  return 'H';
      case V_SHIMMER: return 'S';
      case V_INVIS:   return 'U';
      default:        return '?';
   }
}

private int i_no_wer(object who)
{
    return who->query_no_wer() ? 'V' : ' ';
}

private int i_moerder(object who)
{
   return who->query_moerder() ? 'M' : ' ';
}

private int i_testplayer(object who)
{
   return testplayerp(who) ? 'Z' : ' ';
}

private int i_lehrerlaubnis(object who)
{
   return GOETTER_REGISTER->query_lehrerlaubnis(who->query_real_name()) ?
      'L' : ' ';
}

private int i_age(object who) { return who->query_age(); }

private string r_age(int a)
{
   if (a/86400 > 0)
      return right(to_string(a/86400),3)+" D";
   if (a/3600 > 0)
      return right(to_string(a/3600),3)+" h";
   return right(to_string(a/60),3)+" m";
}

private string r_lvl(int level, object who)
{
   string short, rang;
   level = who->query_level();
   if(level > LVL_HLP)
      return to_string(level);
   if(level == LVL_HLP) {
      if(short = who->query_gilden_info(KUERZEL))
         return sprintf("%1s:%2d", capitalize(short), who->query_rang());
   }
   else if((short = who->query_gilden_info(KUERZEL)))
      return sprintf("%1s:%2d", short, who->query_rang());
   return to_string(level);
}

private int i_lvlp(object who) // Level + Postenpunkte (Lord +1, Admin +2)
{
   return who->query_level()+(lordp(who)?1:0)+(adminp(who)?1:0);
}

private int i_lvltext(object who) // Level + Postenpunkte (Lord +1, Admin +2)
{
   return guestp(who)?-2:newbiep(who)?-1:testplayerp(who)?15:
      who->query_level()+(lordp(who)?1:0)+(adminp(who)?1:0);
}

private string r_lvltext(int level, object who) // Posten im Mud als Klartext
{
   if (who->query_gender()=="weiblich")
       return adminp(who)?"Admin":lordp(who)?"Lady":vogtp(who)?"Voegtin":
       gesellep(who)?"Gesellin":learnerp(who)?"Lehrling":
       testplayerp(who)?"Testie":hlpp(who)?"Engelin":
       guestp(who)?"Gaestin":newbiep(who)?"Newbie":"Spielerin";
    else
       return adminp(who)?"Admin":lordp(who)?"Lord":vogtp(who)?"Vogt":
       gesellep(who)?"Geselle":learnerp(who)?"Lehrling":
       testplayerp(who)?"Testie":hlpp(who)?"Engel":
       guestp(who)?"Gast":newbiep(who)?"Newbie":"Spieler";
}

private string r_lvlp(int level, object who)
{
   string short, rang;
   level = who->query_level();
   if(level > LVL_HLP)
   {
      if(adminp(who)) return "A:"+LVL_ADMIN;
      else if(lordp(who)) return "L:"+LVL_LORD;
      else return to_string(level);
   }
   if(level == LVL_HLP)
   {
      if(short = who->query_gilden_info(KUERZEL))
         return sprintf("%1s:%2d", capitalize(short), who->query_rang());
   }
   else if((short = who->query_gilden_info(KUERZEL)))
      return sprintf("%1s:%2d", short, who->query_rang());
   return to_string(level);
}
private int i_idle(object who)
{
   int idle;

   switch(idle = query_idle(who) / 60)
   {
      case 0..2 : return ' ';
      case 3..9 : return '0'+idle;
      case 10..29: return 'i';
      default   : return 'I';
   }
}

private int i_echo(object who) { return who->query_echomode() ? '+':' '; }

private int i_edit(object who)
{
    return (query_editing(who) || who->has_editor_shadow()) ? 'E' :' ';
}

private int i_guest(object who) { return guestp(who) ? 'G' : ' '; }

private string i_env(object who)
{
   object env;
   return (env = ENV(who)) ? FN(env) : "";
}

private string i_room_domain( object who)
{
   object env;

   return (env = ENV(who)) ? env->query_room_domain()||"*unbekannt*" : "*unbekannt*";
}

private string i_senv(object who)
{
   object env; string sh;
   return (env = ENV(who)) ?
      ((sh = env->query_short(this_player())) ? sh : "keine Kurzbezeichnung")
      : "keine Umgebung";
}

private int i_gender(object who)
{
   switch(who->query_gender())
   {
      case "maennlich":
         return 'm';
      case "weiblich":
         return 'w';
      case "saechlich":
         return 's';
      default:
         return '?';
   }
}

private int i_expp(object who)
{
   return percent(who->query_sum_skill(), TOTAL_EXPERIENCE);
}

private int i_ac(object pl)
{
   object *inv, o;
   int i, sum_ruest;
   if(inv = all_inventory(pl))
      for(i = 0; i < sizeof(inv); i++)
         if((o = inv[i]) && o->query_armour() && o->query_worn() &&
            !o->query_broken())
            sum_ruest += o->query_armour_protection();
   return sum_ruest;
}

private int i_wc(object pl)
{
   object *ho;
   int wc, i, t;
   ho = pl->query_hand_objects();
   for(i = wc = 0; i < sizeof(ho); i++)
      if(ho[i] && (t = ho[i]->compute_damage()) >= wc )
         wc = t;
   return wc;
}

private int count_struct(object pl, string what)
{
   int i;
   mixed * m;
   if(!(m = pl->query_skill_structure()) || !sizeof(m) || sizeof(m[0])<3)
      return 0;
   for(i = 0; i < sizeof(m[0][2]); i++)
      if(m[0][2][i][0]==what)
         break;
   if(i == sizeof(m[0][2]) || sizeof(m[0][2][i])<3)
      return 0;
   else
      return sizeof(m[0][2][i][2]);
}

private int i_spiele(object who)  { return count_struct(who, "spiel"); }
private int i_raetsel(object who) { return count_struct(who, "raetsel"); }

private string i_grad(object who)
{
   return sprintf("%4d %4d %4d %4d %4d %4d %4d %4d %4d %4d",
     percent(who->compute_one_skill(({"skill", "offensiv"}))+
	      who->compute_one_skill(({"skill", "defensiv"})),
	      MAX_SUM_WEAPON),
     percent(who->compute_one_skill(({"skill", "raetsel"})), max_quest),
     percent(who->compute_one_skill(({"skill", "spiel"})), max_game),
     percent(who->query_sum_hp(),MAX_SUM_HP),
     percent(who->query_sum_sp(),MAX_SUM_SP),
     percent(who->query_sum_weight(),MAX_SUM_WEIGHT),
     percent(who->query_sum_comm(),MAX_SUM_COMM),
     percent(who->query_sum_feel(),MAX_SUM_FEEL),
     percent(who->query_sum_move(),MAX_SUM_MOVE),
     percent(who->compute_one_skill(({"skill","wissen"})), soll_wissen));
}

private string i_gname(object who)
{
   string str;
   return (str = who->query_gilden_info(GILDEN_NAME))? str : "";
}

private string i_gkuerzel(object who)
{
   return who->query_gilden_info(KUERZEL)||"";
}

private string i_gtitle(object who)
{
   string str;
   return (str = who->query_gilden_info(RANG)) ? str : "";
}

private string i_gmitgliedsname(object who)
{
    string str;
    return (str = who->query_gilden_info(MITGLIED))? str : "";
}

private string i_town(object who) { return TOWN(who); }

private string i_institut(object who)
{
   string tmp;
   return (tmp=INST(who)) ? tmp :TOWN(who);
}

private int i_away(object who)
{
   return who->query_away() ? '*': ' ';
}

private string i_awayx(object who)
{
   string tmp;
   return (tmp = who->query_away())?tmp:"";
}

private int i_str(object who)     { return who->query_stat(STAT_STR); }
private int i_int(object who)     { return who->query_stat(STAT_INT); }
private int i_con(object who)     { return who->query_stat(STAT_CON); }
private int i_dex(object who)     { return who->query_stat(STAT_DEX); }

private int i_autoloader(object who)
{
   object *obs;
   int i, ret;

   for(i = sizeof(obs = all_inventory(who)); i--;)
      if(obs[i]->query_auto_load())
	 ret++;
   return ret;
}

private string i_query_ip_number(object who)
{
   if (adminp(this_interactive())||guestp(who))
#if __EFUN_DEFINED__(query_ip_number)
      return who->query_real_ip_number() || efun::query_ip_number(who);
#else
      return who->query_real_ip_number() ||
             (efun::interactive(who) && efun::interactive_info(who, II_IP_NUMBER)) ||
             who->get_intermud_src_mud() || "non-interactive";
#endif
   return "0.0.0.0";
}

private string i_query_ip_name(object who)
{
   if (adminp (this_interactive())||guestp(who))
#if __EFUN_DEFINED__(query_ip_number)
       return who->query_real_ip_name() || efun::query_ip_name(who);
#else
       return who->query_real_ip_name() ||
             (efun::interactive(who) && efun::interactive_info(this_object(), II_IP_NAME)) ||
             who->get_intermud_src_mud() || "non-interactive";
#endif
   return "leider.nicht.mehr.verfuegbar";
}

// Zur Sortierung das erstmal als Zahl
private int i_pkuerzel(object who)
{
   if(guestp(who)) return 0;
   if(testplayerp(who)) return 1;
   if(newbiep(who)) return 2;
   if(hlpp(who)) return 4;
   if(!wizp(who)) return 3;
   if(vogtp(who))
   {
      if(adminp(who)) return 9;
      if(lordp(who)) return 8;
      return 7;
   }
   else
   {
      if(gesellep(who)) return 6;
      return 5;
   }
}

private string r_pkuerzel(int p, object who)
{  //Gast, Newbie, Spieler, Engel, Lehrling, Geselle, Lord, Admin
   return ({"g","t","n","s","e","S","G","V","L","A"})[p];
}

// Alle Domains/Gebiete dieses Lords angeben
// Alle Domains des Helfers als Kleinbuchstaben
private string i_positionkurz(object who)
{
   string rn=who->query_real_name();
   //Ersten Buchstaben rausnehmen und in einen String mit Grossbuchstaben
   //konvertieren
   return upper_case(to_string(
     map(DOMAIN_INFOS->query_domains_of(rn)+FILED->query_auth_of(rn),#'[,0)))+
     //Ersten Buchstaben rausnehmen und in einen String mit Kleinbuchstaben
     //konvertieren     
     lower_case(to_string(map(DOMAIN_INFOS->query_domainhelfer_of(rn),#'[,0)));
}

private string i_position(object who)
{
   string rn=who->query_real_name();
   if(wizp(who))
      return implode(
        (adminp(who)?({"Admin"}):({}))
       +map(DOMAIN_INFOS->query_domains_of(rn)+FILED->query_auth_of(rn),#'capitalize)
       +map(DOMAIN_INFOS->query_domainhelfer_of(rn),#'+," (DH)")
       +GILDEN_OB->query_programmed_gilden(rn)
       ,", ");
   return implode(
      (spielerratp(rn)?({"Spielerrat"}):({}))
     +(testplayerp(rn)?({"Testie"}):({}))
       ,", ");
}

private mapping query_volk_infos()
{
// Freie Zeichen: 5-9, 0, D, Q, b, c, d, j, m, q, u, v, Sonderzeichen...
    return
	([

	/*
	  Feldkuerzel: 
	   ({
	      Funktion - Diese Closure liefert die Daten zum Sortieren,
	                 erhaelt als Parameter den Player
              Replacer - Diese Closure erhaelt die Daten der Funktion und
	                 den Spieler als Parameter und liefert den String
			 zur Ausgabe
	      Praefix  - Formatbezeichner wie - (linksbuending), = (Tabellenmodus)
	                 fuer sprintf
	      Laenge   - Die Feldlaenge
	      Typ      - Der Typ (nach sprintf)
	      Header   - Die Tabellenueberschrift
	      Doku     - Der Text fuer die Hilfe
	   })
	*/
	
	   "#" : ({ 0,0,		"",   2, "d", "Nr", "Lfd. Nummer"}),
	   "1" : ({ #'i_str,0,		"",   3, "d", "Str", "Staerke" }),
	   "2" : ({ #'i_int,0,		"",   3, "d", "Int", "Intelligenz" }),
	   "3" : ({ #'i_con,0,		"",   3, "d", "Con", "Ausdauer" }),
	   "4" : ({ #'i_dex,0,		"",   3, "d", "Dex", "Geschicklichkeit" }),
	   "A" : ({ #'i_ac,0,		"",   2, "d", "AC", "Ruestungsklasse (AC)"}),
	   "B" : ({ #'i_guest,0,        "",   1, "c", "G", "Gast Flag"}),
	   "C" : ({ #'i_echo,0,         "",   1, "c", "C", "Echo-Modus Flag"}),
	   "E" : ({ #'i_edit,0,         "",   1, "c", "E", "Editing Flag"   }),
	   "F" : ({ #'i_away,0,         "",   1, "c", "F","Weg/Fort Flag (away)"}),
	   "G" : ({ CX("align"),0,	"",   5, "d", "Align", "Alignment" }),
	   "H" : ({ #'i_grad,0,		"-", 48, "s",
		       "Waff Raet Spie SuHp SuSp Gewi Comm Feel Move Wiss", "zgrad"}),
	   "I" : ({ #'i_idle,0,		"",   1, "c", "I", "Idle Flag"     }),
	   "J" : ({ #'i_awayx,0,        "=-",30, "s", "Weg-Meldung (away)",
							"Weg-Meldung (away)"}),
	   "K" : ({ CX("konto"),0,	"",   7, "d", "Konto", "Kontostand" }),
	   "L" : ({ CX("internal_encumbrance"),0,
					"",   3, "d", "Enc", "Gepaeck (Encumbrance)" }),
	   "M" : ({ #'i_moerder,0,	"",   1, "c", "M", "Moerderflag"}),
	   "N" : ({ #'i_name,#'r_name,  "-", 12, "s", "Name", "Name"}),
	   "O" : ({ #'object_name,0,	"-", 20, "s", "Objekt", "Objekt"}),
	   "P" : ({ #'i_lehrerlaubnis,0,"",   1, "c", "L", "Lehrerlaubnis Flag"}),
	   "R" : ({ #'i_raetsel,0,	"",   2, "d", "R", "Zahl der gel. Raetsel"}),
	   "S" : ({ #'i_spiele,0,	"",   2, "d", "S", "Zahl der gel. Spiele"}),
	   "U" : ({ #'i_invis,0,	"",   1, "c", "U","Unsichtbarkeit" }),
	   "V" : ({ #'i_no_wer,0,       "",   1, "c", "V","Nicht in Wer-Liste"}),
	   "W" : ({ #'i_wc,0,		"",   2, "d", "WC", "Waffenklasse (WC)"}),
	   "X" : ({ #'i_expp,0,		"",   4, "d", "Erf.", "Erfahrung promille" }),
	   "Y" : ({ #'i_gtitle,0,	"=-",30, "s", "Titel in der Gilde",
		    "Titel in der Gilde" }),
	   "Y*": ({ #'i_gmitgliedsname,0,"=-",15, "s", "G.Mitglied",
		    "Mitgliedsname in der Gilde" }),
	   "Z" : ({ #'i_testplayer,0,	"",   1, "c", "Z", "Zweitcharaktere"}),
	   "a" : ({ #'i_age, #'r_age,	"-",  5, "s", "Alter", "Alter" }),
	   "e" : ({ #'i_env,0,		"=-",47, "s", "Environment", "Environment" }),
	   "f" : ({ CX("fp"),0,		"",   4, "d", "Fp", "Futterpunkte" }),
	   "g" : ({ #'i_gender,0,	"",   1, "c", "G", "Geschlecht"     }),
	   "h" : ({ CX("alc"),0,	"",   4, "d", "Alc", "Alkohol" }),
	   "i" : ({ #'i_query_ip_number,0,"-", 15, "s", "IP-Adresse", "IP-Adresse" }),
	   "k" : ({ #'i_room_domain,0,  "-", 12, "s", "Kon.", "Kontinent" }),
	   "l" : ({ CX("level"),0,      "",   2, "d", "Lv", "Level" }),
	   "l+": ({ CX("level"),#'r_lvl,"",   4, "s", "Lvl.", "Level/Gildenkuerzel+Rang"   }),
	   "l*": ({ #'i_lvlp,#'r_lvlp,"",  4, "s", "Lvl.", "Posten+Level/Gilde+Rang"}),
	   "l-": ({ #'i_lvltext,#'r_lvltext,"-",  9, "s", "Level", "Level als Klartext"}),
	   "n" : ({ #'i_name,0,		"-",  10,"s", "Name","Name"}),
	   "o" : ({ #'i_autoloader,0,	"",   2, "d", "AL","# Autoloader"}),
	   "p" : ({ #'i_pkuerzel,#'r_pkuerzel,"", 1, "s", "P","Position"}),
	   "p+": ({ #'i_positionkurz,0,"-", 3, "s", "Afg", "Aufgabengebiet als Kuerzel" }),
	   "p*": ({ #'i_position,0,  "-=", 45, "s", "Aufgabengebiet", "Aufgabengebiet"}),
	   "r" : ({ #'i_query_ip_name,0,"=-", 35,"s", "Rechnername", "Rechnername"}),
	   "s" : ({ #'i_senv,0,		"=-",25, "s", "Umgebung", "Kurzbezeichnung Umgebung" }),
	   "w" : ({ CX("wp"),0,		"",   4, "d", "Wp", "Wasserpunkte" }),
	   "x" : ({ CX("sum_skill"), 0,	"",   6, "d", "Erf.", "Erfahrung absolut" }),
	   "y" : ({ #'i_gname,0,	"=-", 20,"s", "Gilde", "Name der Gilde" }),
	   "y*": ({ #'i_gkuerzel,0,     "",   1, "s", "G" , "Kuerzel der Gilde" }),
	   "z" : ({ CX("rang"), 0,	"",   2, "d", "Rg", "Gildenrang" }),
	])+(adminp(environment())?
	([
	   "T" : ({ #'i_institut,0,	"=-",50, "s", "Einrichtung", "Einrichtung" }),
	   "t" : ({ #'i_town,0,		"-", 20, "s", "Stadt","Stadt" }),
	]):([]));
}

private mapping query_volk_groups()
{
    return
       //Kuerzel: Formatierung; Sortierung
        ([ "c": "i N l+ a I e(37)"; "lN",
	   "s": "n k(12) s(55)"; "ksn",
	   "x": "n g l+ x r(38) i"; "in",
	   "1": "n l+ x 1 2 3 4 K A W L R S G"; "lx",
	   "2": "n H f w h l(0) x(0)"; "lx",
	   "3": "n X l+ y Y z(0)"; "lyz",
	   "4": "N l+ a IFEVZMP k s(34)"; "klN"
	])+(adminp(environment())?
	([
	   "s": "n T(47) t"; "tTn",
	]):([]));
}
