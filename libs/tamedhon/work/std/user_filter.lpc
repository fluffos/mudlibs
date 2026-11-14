// Tamedhon MUDlib
//
// std/user_filter.c -- Diverse Filterfunktionen (fuer kwer)
//
// $Date: 2008/01/13 16:00:00 $
/* $Revision: 1.15 $
 * $Log: user_filter.c,v $
 *
 * Revision 1.15  2008/01/13 16:00:00  TamTam
 * Race Troll eingefuegt
 *
 * Revision 1.14  2006/08/13 16:36:00  Querolin
 * Vereinsmitglieder eingefuegt.
 *
 * Revision 1.13  2003/06/29 10:00:00  Querolin
 * Race Daemon eingefuegt, filter fuer tot und geist
 *
 * Revision 1.12  2003/01/03 16:00:00  Querolin
 * Wahnsinnige eingefuegt :) - "nicht" geht nun auch...
 *
 * Revision 1.11  2002/08/09 17:30:00  Querolin
 * default Filter erweitert...
 *
 * Revision 1.10  1998/01/23 21:41:08  Woody
 * "abwesend" als Filter eingebaut
 *
 * Revision 1.9  1997/10/06 11:10:25  Woody
 * Idle ab 60 Sekunden Idletime, nicht erst ab 61...
 *
 * Revision 1.8  1997/09/24 14:57:56  Woody
 * Filter fuer "idle" eingebaut
 *
 * Revision 1.7  1997/09/17 14:22:37  Woody
 * neue Filter: erzmagier/erzies/regionsmagier
 *
 * Revision 1.6  1997/08/28 12:49:21  Woody
 * Warnung bei unbekanntem Suchkriterium
 *
 * Revision 1.5  1997/08/21 14:13:35  Woody
 * Parameter "" wie 0 behandeln, Bugfix bei 'oder' Verknuepfungen
 *
 * Revision 1.4  1997/06/25 11:41:06  Woody
 * auch "kwer aus..." mgl., invis magier bei "kwer bei" ausnehmen
 *
 * Revision 1.3  1997/06/12 17:53:27  Woody
 * So, NOCH flexibler. "kwer in (d)" klappt zB. nun
 *
 * Revision 1.2  1997/06/12 17:40:48  Woody
 * is_in() (Filtern nach Einloggort) etwas flexibler
 *
 * Revision 1.1  1997/03/13 03:21:35  Woody
 * prepared for revision control
 *
 */

// This may look like C code, but it is really -*- C++ -*-

/*
 * 18. Jan 1996 Hadra@AnderLand
 * i++ gegen ++i ausgetausch
*/

#include <properties.h>
#include <wizlevels.h>
#include <language.h>
#define ME this_object()

#define VEREINSMASTER "/p/service/querolin/vereinsmaster"

int is_in(object ob, mixed x) {
  // return (country(ob)==x);
  return sizeof(explode(lower_case(country(ob))," ") & ({ x }) );
}
int is_at(object ob, mixed x) {
  return (environment(ob)==x);
}
int is_wiz_level_lt(object ob, mixed x) {
  return (query_wiz_level(ob)<x);
}
int is_wiz_level_ge(object ob, mixed x) {
  return (query_wiz_level(ob)>=x);
}
int is_prop_set(object ob, mixed x) {
  return (ob->QueryProp(x));
}
int is_in_gilde(object ob, mixed x) {
  return (ob->QueryProp(P_GUILD)==x);
}
int is_name_in(object ob, mixed x) {
  return (member(x,capitalize(geteuid(ob)))>=0);
}
int is_in_region(object ob, mixed x) {
  return (environment(ob) &&
	  (object_name(environment(ob))[0..(sizeof(x)-1)]==x));
}
int is_gender(object ob, mixed x) {
  return (ob->QueryProp(P_GENDER)==x);
}
int is_race(object ob, mixed x) {
  return (ob->QueryProp(P_RACE)==x);
}
int is_idle(object ob) {
  return (query_idle(ob) >= 60);
}
int is_verein(object ob) {
  return (VEREINSMASTER->__query(ob->Name())==1);
}

object *filter_users(string str) {
  object *res,*orig,*zwi;
  string *words;
  int i,sz,f;
  mixed x;

  orig=users();
  if (!str || str=="") return orig;
  res=({});
  words=explode(lower_case(str)," ");sz=sizeof(words);
  for (i=0;i<sz;i++) {
    zwi=({});
    switch(words[i]) {
      case "ausser":
      case "außer":
      case "ohne":
      f=-1;
      continue;

      case "oder":
      f=0;
      continue;
      case "und":
      f=1;
      continue;

      case "nicht":
      f=-2;
      continue;

      case "alle":
      zwi=orig;
      break;

      case "wahnsinnig":
      case "wahnsinnige":
      case "irre":
      case "dummkoepfe":
      case "dummköpfe":
      case "dummkopf":
      zwi=orig;
      if (this_player()) {
       write("Alle hier sind doch eindeutig "+capitalize(words[i])+", oder?\n");
       write("Have fun...\n\n"); }
      break;

      case "in":
      case "aus":
      if (++i>=sz) break;
      zwi=filter(orig,"is_in",ME,words[i]);
      break;
      case "region":
      if (++i>=sz) break;
      zwi=filter(orig,"is_in_region",ME,"/d/"+words[i]);
      break;
      case "gilde":
      if (++i>=sz) break;
      zwi=filter(orig,"is_in_gilde",ME,words[i]);
      break;

      case "bei":
      if (++i>=sz) break;
      if (!objectp(x=find_player(words[i])) &&
	  !objectp(x=find_living(words[i])))
	break;
      if (x->QueryProp(P_INVIS))
        break;
      zwi=filter(orig,"is_at",ME,environment(x));
      break;

      case "goetter":
      case "götter":
      case "gott":
      zwi=filter(orig,"is_wiz_level_ge",ME,GOD_LVL);
      break;
      case "erzmagier":
      case "erzies":
      zwi=filter(orig,"is_wiz_level_ge",ME,ARCH_LVL);
      break;
      case "archon":
      case "archont":
      case "archonten":
      zwi=filter(orig,"is_wiz_level_ge",ME,ARCHON_LVL);
      break;
      case "regionsmagier":
      zwi=filter(orig,"is_wiz_level_ge",ME,LORD_LVL);
      break;
      case "magier":
      zwi=filter(orig,"is_wiz_level_ge",ME,LEARNER_LVL);
      break;
      case "spieler":
      zwi=filter(orig,"is_wiz_level_lt",ME,SEER_LVL);
      break;
      case "seher":
      zwi=filter(filter(orig,"is_wiz_level_lt",ME,LEARNER_LVL),
		       "is_wiz_level_ge",ME,SEER_LVL);
      break;

      case "maennlich":
      case "männlich":
      zwi=filter(orig,"is_gender",ME,MALE);
      break;
      case "weiblich":
      zwi=filter(orig,"is_gender",ME,FEMALE);
      break;

      case "mensch":
      zwi=filter(orig,"is_race",ME,"Mensch");
      break;
      case "zwerg":
      zwi=filter(orig,"is_race",ME,"Zwerg");
      break;
      case "elf":
      zwi=filter(orig,"is_race",ME,"Elf");
      break;
      case "hobbit":
      zwi=filter(orig,"is_race",ME,"Hobbit");
      break;
      case "ork":
      zwi=filter(orig,"is_race",ME,"Ork");
      break;
      case "brownie":
      zwi=filter(orig,"is_race",ME,"Brownie");
      break;
      case "daemon":
      case "dämon":
      zwi=filter(orig,"is_race",ME,"Dämon");
      break;
      case "troll":
      zwi=filter(orig,"is_race",ME,"Troll");
      break;

      case "frosch":
      zwi=filter(orig,"is_prop_set",ME,P_FROG);
      break;

      case "testies":
      case "testspieler":
      zwi=filter(orig,"is_prop_set",ME,P_TESTPLAYER);
      break;
      case "zweities":
      case "zweitspieler":
      zwi=filter(orig,"is_prop_set",ME,P_SECOND);
      break;

      case "abwesend":
      zwi=filter(orig,"is_prop_set",ME,P_AWAY);
      break;

      case "geist":
      case "tot":
      zwi=filter(orig,"is_prop_set",ME,P_GHOST);
      break;

      case "idle":
      zwi=filter(orig,"is_idle",ME);
      break;

      case "erwartete":
      if (!pointerp(x=this_player()->QueryProp(P_WAITFOR))) break;
      zwi=filter(orig,"is_name_in",ME,x);
      break;

      case "vereinsmitglieder":
      case "vereinsmitglied":
      case "mitglieder":
      case "mitglied":
      case "verein":
      zwi=filter(orig,"is_verein",ME);
      break;

      default:
      f=0;
      if (this_player())
        write("Warnung: Unbekanntes Suchkriterium "+words[i]+".\n");
        write("Gesamtliste wird ausgegeben:\n\n");
      zwi=orig;
    }
    switch (f) {
      case -2: res=orig-zwi; break;
      case -1: res-=zwi; break;
      case 1:  res=res&zwi; break;
      default: res-=zwi; res+=zwi;
    }
  }
  return res;
}

