// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/database.h
// Description: Defines zu Datenbankfunktionen aus /i/tools/database.c
// Author:      Myonara (16.Apr.2013)
// Modified by:
//
// $Log: database.h,v $
// Revision 1.4  2016/07/16 07:42:46  myonara
// Diverse Parameter(05-Jan-2016)
//
// Revision 1.3  2015/12/15 19:01:50  myonara
// 1) neu DB_DBG_ACL_QUERY
// 2) mapping Eintraege fuer Optionen bei query_dbg_messages
//
// Revision 1.2  2015/09/11 04:50:59  myonara
// Neue acl defines fuer send_to_debuggers und Co.
//
// Revision 1.1  2013-05-03 16:23:06  myonara
// Erstellung.
//
//

#ifndef DATABASE_H
#define DATABASE_H

#define DB_DBGLVL_DEBUG   0
#define DB_DBGLVL_INFO    1
#define DB_DBGLVL_WARNING 2
#define DB_DBGLVL_ERROR   3

#define DB_DBG_BUFFER_MSG       0x0001
#define DB_DBG_FLUSH_BUFFER     0x0002
#define DB_DBG_DELETE_BUFFER    0x0004
#define DB_DBG_CREATE           0x1000

#define DB_DBG_ACL_DB_DEBUG     0x0001
#define DB_DBG_ACL_DEBUGLOG     0x0002
#define DB_DBG_ACL_EXPLAIN      0x0004
#define DB_DBG_ACL_OTHER        0x0008
#define DB_DBG_ACL_QUERY        0x0010

#define DB_DBG_FLAGS            "database:debug:flags"
#define DB_DBG_LIMIT            "database:debug:limit"
#define DB_DBG_OFFSET           "database:debug:offset"
#define DB_DBG_START_TIME       "database:debug:time:start"
#define DB_DBG_END_TIME         "database:debug:time:end"
#define DB_DBG_COUNT            "database:debug:count"
#define DB_DBG_FILTER           "database:debug:filter"

// Name der Suchabfrage ist string
#define DEBUGLOG_NAME "debuglog:name"
// Parameter Zeitbereich ist ({ int von, int bis })
#define DEBUGLOG_ZEITBEREICH "debuglog:zeitbereich"
// Parameter Benutzer ist ({ string rn1, rn2,... })
#define DEBUGLOG_BENUTZER "debuglog:benutzer"
// Parameter Kategorie ist ({ string kat1,kat2,... })
#define DEBUGLOG_KATEGORIEN "debuglog:kategorien"
// Parameter level ist string (bitfeld)
#define DEBUGLOG_LEVEL "debuglog:level"
// Stringparameter mit %-Selektion.
#define DEBUGLOG_MASKE "debuglog:maske"
// int Parameter 0 Rueckwaerts/ 1 Vorwaertssortierung
#define DEBUGLOG_SORTIERUNG "debuglog:sortierung"
// int markierungslevel: Prioritaeten fuer die Reihenfolge des dbchecks
#define DEBUGLOG_MARKPRIO "debuglog:markierung:priotaet"


#ifdef UNItopia
#define DB_DBG_VALID_PO ({ "/w/myonara/public/db/obj/dbbuch.lpc" })
#else
#define DB_DBG_VALID_PO ({ })
#endif

#endif