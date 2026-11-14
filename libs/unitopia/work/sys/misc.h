// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/misc.h
// Description: Defines, die gerne und haeufig verwendet werden
// Author:      Diverse
// Modified by: 
//
// $Log: misc.h,v $
// Revision 1.23  2005/08/28 21:13:21  gnomi
// TP_RCN: Abfrage auf playerp() wie bei den anderen real_name-Abfragen auch.
//
// Revision 1.22  2005/03/27 20:38:36  menaures
// in_renewal(ob) findet das umbenannte zern -T Objekt waehrend dem create()
//
// Revision 1.21  2004/09/02 18:42:27  gnomi
// ON vorher undef'n.
//
// Revision 1.20  2004/01/18 23:04:34  gnomi
// ENV_TO auf environment() statt environment(this_object()) geaendert.
// (Gibt keinen Fehler, wenn TO=0)
//
// Revision 1.19  2003/11/06 04:00:59  gnomi
// FAILP, FAILPW eingefuehrt.
//
// Revision 1.18  2003/09/03 15:53:56  menaures
// #undef inheritp
//
// Revision 1.17  2003/07/31 00:51:31  menaures
// Neues Makro inheritp(x)
//
// Revision 1.16  2003/05/06 02:40:09  gnomi
// FAIL/FAILW so geaendert, dass sie auch bei Funktionen, welche kein int
// zurueckliefern, funktionieren.
//
// Revision 1.15  2003/01/26 03:52:56  gnomi
// #define LN(ob) load_name(ob)
//
// Revision 1.14  2002/12/10 01:25:16  gnomi
// ENV*-Defines versuchen keinen RTE zu werfen.
//
// Revision 1.13  2002/11/20 04:13:26  gnomi
// RCNAME: auf playerp pruefen.
//
// Revision 1.12  2002/11/07 01:09:25  gnomi
// TP_RN und RNAME testen auch gleich auf playerp ab.
//
// Revision 1.11  2002/07/08 23:55:55  gnomi
// #undefs fuer die neuen Defines eingefuegt.
//
// Revision 1.10  2002/07/07 22:52:04  gnomi
// Neues Define RCN.
//
// Revision 1.9  2002/07/06 23:12:42  gnomi
// Define CHOOSE.
//
// Revision 1.8  2002/01/15 03:39:15  gnomi
// query_short umgestellt.
//
// Revision 1.7  2001/06/22 23:38:38  gnomi
// FAILW eingefuehrt.
//
// Revision 1.6  2001/04/09 21:39:42  gnomi
// Nicht in den UDL-Master einlesen.
//
// Revision 1.5  2001/03/29 16:17:06  gnomi
// Define monsterp von Croft.
//
// Revision 1.4  2001/03/20 23:29:49  gnomi
// PL: living statt livingp nutzen.
//
// Revision 1.3  2001/03/13 00:23:04  gnomi
// min/max rausgehauen, da nun Efun.
// ENV_TO korrigiert.
//
// Revision 1.2  2001/03/12 04:46:11  gnomi
// MIN/MAX -> min/max in Vorbereitung auf dev255
//
// Revision 1.1  2001/03/11 22:26:46  gnomi
// Eingebaut.
//

#if !defined(MISC_H) && !defined(__UDL_PARSER__)
#define MISC_H

//Erstmal alles undef'n, besser als jedesmal nachzufragen,
//ob es nicht zufaellig definiert wurde...
#undef TP
#undef TP_N
#undef TP_RN
#undef TP_CN
#undef TP_RCN
#undef TO
#undef PO
#undef PP
#undef PL
#undef TI
#undef QSO
#undef ENV 
#undef EENV
#undef ENVR
#undef ENVP
#undef ENVL
#undef ENVRP
#undef ENVRL
#undef ENV_TO
#undef ENV_TP
#undef RN
#undef RCN
#undef NAME
#undef RNAME
#undef CNAME
#undef RCNAME
#undef SHORT
#undef LN
#undef ON
#undef FN
#undef FAIL
#undef FAILW
#undef CAP
#undef LOW
#undef UPP
#undef MIN
#undef MAX
#undef REGMATCH
#undef CHOOSE
#undef statuep
#undef livingp
#undef inheritp
#undef in_renewal


#define TP        this_player()
#define TP_N      this_player()->query_name()
#define TP_RN     (playerp(this_player()) && this_player()->query_real_name())
#define TP_CN     this_player()->query_cap_name()
#define TP_RCN    (playerp(this_player()) && this_player()->query_real_cap_name())
#define TO        this_object()
#define PO        previous_object()

// previous_player: Letzter Player im caller_stack
#define PP        (filter(caller_stack(1),#'playerp)+({this_player()}))[0]
// previous_living: Letztes Lebewesen im caller_stack
#define PL        (filter(caller_stack(1),#'living)+({this_player()}))[0]

#define TI        this_interactive()
#define QSO       query_shadow_owner()

#define ENV(x)    environment(x)
#define EENV(x)   (environment(x) && environment(environment(x)))
// naechster umgebender Raum
#define ENVR(x)   (filter_objects(all_environment(x)||({}),"query_room")+({0}))[0]
// naechster umgebender Spieler
#define ENVP(x)   (filter(all_environment(x)||({}),#'playerp)+({0}))[0]
// naechstes umgebendes Lebewesen
#define ENVL(x)   (filter(all_environment(x)||({}),#'living)+({0}))[0]
// naechster umgebender Raum oder Spieler
#define ENVRP(x)  (filter(all_environment(x)||({}),(:$1->query_room() || playerp($1):))+({0}))[0]
// naechster umgebender Raum oder Lebewesen
#define ENVRL(x)  (filter(all_environment(x)||({}),(:$1->query_room() || living($1):))+({0}))[0]

#define ENV_TO    environment()
#define ENV_TP    ENV(TP)

#define RN(ob)    ((ob)->query_real_name() || (ob)->query_name())
#define RCN(ob)    ((ob)->query_real_cap_name() || (ob)->query_cap_name())
#define NAME(x)   ((x)->query_name())
#define RNAME(x)  (playerp(x) && (x)->query_real_name())
#define CNAME(x)  ((x)->query_cap_name())
#define RCNAME(x) (playerp(x) && (x)->query_real_cap_name())
#define SHORT(x)  ((x)->query_short(TP))
#define FN(x)     object_name(x)
#define ON(x)     object_name(x)
#define LN(x)     load_name(x)

// '||0' deswegen, damit man dies auch bei Funktionen nutzen kann,
// die keinen int-Wert sondern z.B. object als Rueckgabetyp haben.
#define FAIL(x)   return (notify_fail(x)||0)
#define FAILW(x)  return (notify_fail(wrap(x))||0)
#define FAILP(x,p)   return (notify_fail(x,p)||0)
#define FAILPW(x,p)  return (notify_fail(wrap(x),p)||0)
#define FAILWP(x,p)  return (notify_fail(wrap(x),p)||0)
#define CAP(x)    capitalize(x)
#define LOW(x)    lower_case(x)
#define UPP(x)    upper_case(x)

#define CHOOSE(x)	(funcall((:$1[random(sizeof($1))]:),(x)))

// regexp-Sting-matching
#define REGMATCH(str, pattern)  (sizeof( regexp( ({ str }), pattern)) > 0)
// Ist player eine Statue
#define statuep(player)  (playerp(player) && !interactive(player))
#define monsterp(ob)     (living(ob) && !playerp(ob))
// Ist ob ein Lebewesen oder lebendiges V-Item
#define livingp(ob)      ( (objectp(ob) && living(ob)) \
                         ||(mappingp(ob) && ob["living"]))
// ist x ein Inherit
#define inheritp(x) (objectp(x) && strstr(object_name(x), "/i/") != -1)

// Wird das Objekt gerade zern -t erneuert? Liefert das alte Objekt.
#define in_renewal(ob) find_object(regreplace(object_name(ob), \
                                              "/([^/]*)$","/$\\1$", 0))

#endif /* MISC_H */
