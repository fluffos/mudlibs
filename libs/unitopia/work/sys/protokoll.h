// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/protokoll.h
// Description: Defines zu /apps/protokollarchiv und Co.
// Author:      Myonara (18.Apr.2013)
// Modified by:
//
// $Log: protokoll.h,v $
// Revision 1.3  2013/06/15 15:13:31  myonara
// PR_FOLGE_MODUS implementiert.
//
// Revision 1.2  2013-05-26 10:38:58  myonara
// neuer PR_ZUSTAND_FREI
//
// Revision 1.1  2013-05-03 16:41:12  myonara
// Erstellung.
//
//

#ifndef PROTOKOLL_H
#define PROTOKOLL_H

#define PROTOKOLL_MASTER    "/apps/protokollarchiv"
#define OBJ_KLAUSUR_RAUM    "/obj/klausur_raum"
#define OBJ_PROTOKOLLANT    "/obj/protokollant"
#define OBJ_PROTOKOLLINDEX  "/obj/protokollindex"
#define PROTOKOLL_VC        "/room/protokoll/"
#define PR_HELPFILE_MAIN    "/doc/hilfe/protokoll/protokoll_einst"
#define PR_HELPFILE_MAIN_L  "/doc/hilfe/protokoll/protokoll_einst_l"
#define PR_HELPFILE_MAIN_S  "/doc/hilfe/protokoll/protokoll_einst_s"
#define PR_HELPFILE_ACTION  "/doc/hilfe/protokoll/protokoll_einst_action"
#define PR_CMD_HILFE        "/doc/hilfe/protokoll/pr_hilfe"

#define PR_OK                  1
#define PR_PARAMETER_ERROR     2
#define PR_ALREADY_OPEN        3
#define PR_DB_ERROR            4

// Zustand und Einstellungen:
#define PR_AKTIV            "protokoll:aktiv"
#define PR_FLAG_ALLE        "protokoll:flag_alle"
#define PR_FLAG_NPC         "protokoll:flag_npc"
#define PR_FLAG_ALLES       "protokoll:flag_alles"
#define PR_FOLGE_MODUS      "protokoll:folgemodus"

// Speicherfelder:
#define PR_ID               "protokoll:id"
#define PR_FILENAME         "protokoll:filename"
#define PR_FILEVERSION      "protokoll:fileversion"
#define PR_ZUSTAND          "protokoll:zustand"
#define PR_TYPKLASSE        "protokoll:typklasse"
#define PR_AUTOR            "protokoll:autor"
#define PR_TITEL            "protokoll:titel"
#define PR_INHALT           "protokoll:inhalt"
#define PR_ZEITSTEMPEL      "protokoll:zeitstempel"
#define PR_STICHWORTE       "protokoll:stichworte"
#define PR_LESEZUGRIFFE     "protokoll:lesezugriffe"
#define PR_SCHREIBZUGRIFFE  "protokoll:schreibzugriffe"
#define PR_ZUSTAND_AKTIV        1
#define PR_ZUSTAND_GELOESCHT    2
#define PR_ZUSTAND_FREI         3

#endif
