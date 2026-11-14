// This file is part of UNItopia Mudlib.
// -----------------------------------------------------------------------
//  Datei:  /sys/umfragen.h
//  Autor:  Myonara 28.Sep.2014 
// -----------------------------------------------------------------------
// Beschreibung: Die Include Datei fuer Umfrage-und Ideenkobold (uiko)
// -----------------------------------------------------------------------
// Aenderungen:
//  $Log: umfragen.h,v $
//  Revision 1.7  2014/11/01 14:42:28  myonara
//  Neue Defines fuer Diskussionen und Ignorieren
//
//  Revision 1.6  2014/10/30 17:40:58  myonara
//  Anpassungen fuer Diskussion und Beitraege
//
//  Revision 1.5  2014/10/16 17:59:41  myonara
//  neue Defines UI_OPT_UMFRAGE_OFFEN und UI_MENUTYPE_OFFEN
//
//  Revision 1.4  2014/10/16 04:53:12  myonara
//  neue Defines zu UIERHEBUNG1E_...
//
//  Revision 1.3  2014/10/05 19:46:41  myonara
//  defines fuer Nachrichten ergaenzt.
//
//  Revision 1.2  2014/10/04 11:18:34  myonara
//  Einbaufertig
//
//  Revision 1.1  2014/10/03 16:52:29  myonara
//  Neuerstellung fuer den Umfrage- und Ideenkobold
//
// 


#ifndef __UMFRAGEN_H
#define __UMFRAGEN_H

#ifdef Orbit
#define UMFRAGE_ROOTPATH "/w/myonara/public/Umfrage/"
#define UMFRAGE_MASTER   UMFRAGE_ROOTPATH "apps/umfragen_db"
#define UMFRAGE_AUTOLOAD UMFRAGE_ROOTPATH "obj/uiko"
#define UMFRAGE_DBFILE   "/w/myonara/save/umfragen.db"
#else
#define UMFRAGE_MASTER   "/apps/umfragen_db"
#define UMFRAGE_AUTOLOAD "/room/rathaus/obj/uiko"
#define UMFRAGE_DBFILE   "/var/spool/umfragen/umfragen.db"
#endif


#define UMFRAGE_S_GELOESCHT  0
#define UMFRAGE_S_NEU        1
#define UMFRAGE_S_STANDARD   2
#define UMFRAGE_S_BEREIT     3
#define UMFRAGE_S_AKTIV      4
#define UMFRAGE_S_OFFEN      5
#define UMFRAGE_S_BEENDET    6
#define UMFRAGE_S_ABGELEHNT  7
#define UMFRAGE_S_ARCHIVIERT 8

#define IDEEN_W_ZEICHEN 0
#define IDEEN_W_I_ID    1
#define IDEEN_W_TEXT    2
#define IDEEN_W_U_ID    3

#define UI_BEITRAG_B_ID    0
#define UI_BEITRAG_WANN    1
#define UI_BEITRAG_WER     2
#define UI_BEITRAG_TITEL   3

#define UI_MENUTYPE_WAHL        1
#define UI_MENUTYPE_OWN         2
#define UI_MENUTYPE_BEREIT      3
#define UI_MENUTYPE_ALLE        4
#define UI_MENUTYPE_OFFEN       5
#define UI_MENUTYPE_DISKU       6
#define UI_MENUTYPE_NDISKU      7
#define UI_MENUTYPE_IGNORIERT   8

#define UI_OPT_COUNTALL   "ui:opt:countall"
#define UI_OPT_PANTHEON   "ui:opt:pantheon"
#define UI_OPT_SUCHFILTER "ui:opt:suchfilter"
#define UI_OPT_ERSTELLER  "ui:opt:ersteller"
#define UI_OPT_I_ID       "ui:opt:i_id"
#define UI_OPT_U_ID       "ui:opt:u_id"
#define UI_OPT_D_ID       "ui:opt:d_id"
#define UI_OPT_B_ID       "ui:opt:b_id"
#define UI_OPT_ITEM       "ui:opt:item"
#define UI_OPT_OFFSET     "ui:opt:offset"
#define UI_OPT_LIMIT      "ui:opt:limit"
#define UI_OPT_DATA       "ui:opt:data"
#define UI_OPT_GOTO       "ui:opt:goto"
#define UI_OPT_STATUS     "ui:opt:status"
#define UI_OPT_MC         "ui:opt:multiplechoice"
#define UI_OPT_MENUTYPE   "ui:opt:menutype"
#define UI_OPT_UMFRAGE_OFFEN  "ui:opt:umfrage:offen"
#define UI_OPT_DISKUSSION "ui:opt:diskussion"
#define UI_OPT_OHNE_DISKUSSION "ui:opt:ohne:diskussion"
#define UI_OPT_IGNORELIST "ui:opt:diskussion"

#define UI_MSG_N_ID       "ui:msg:n_id"
#define UI_MSG_VON        "ui:msg:von"
#define UI_MSG_AN         "ui:msg:an"
#define UI_MSG_WANN       "ui:msg:wann"
#define UI_MSG_WAS        "ui:msg:was"
#define UI_MSG_ID         "ui:msg:id"
#define UI_MSG_STATUS     "ui:msg:status"
#define UI_MSG_KATEGORIE  "ui:msg:kategorie"
#define UI_MSG_NACHRICHT  "ui:msg:nachricht"

#define UI_ERHEBUNG1I_SCHLUESSEL  0
#define UI_ERHEBUNG1I_U_ID        1
#define UI_ERHEBUNG1I_I_ID        2
#define UI_ERHEBUNG1I_TEXT        3

#endif
// EOF
