/* 
 * /p/daemon/housed/sys/housed.h - Deklarationen zum Seherhausverwalter 
 *
 * (c) 1998-2000 Mud Silberland - Adrian Holzwarth / Anatol@Silberland
 *
 *  1998 01 15 Revision 0.1   Redefinition REPFILE()
 *                          
 *  1999 02 22 Revision 0.2   PROPER_EXITS erweitert.
 *
 *  2000 11 18 Revision 0.3   Umzug nach /p/daemon/housed/sys,
 *                            Abspaltung von house.h,
 *
 *  2000 12 04 Revision 0.4   Total umgestellt :)
 *
 *  2015 04 13 Revision 0.5   Eros in die Caretaker-Liste aufgenommen
 */

#ifndef _HOUSED_HOUSED_H_
#define _HOUSED_HOUSED_H_

#define DEBUG_MESSAGE( key, level, text ) catch(call_other("/players/anatol/r/debug","I", key, level, text))
#define DB(level, text) DEBUG_MESSAGE("haeuser",level,text)

#define HOUSED_HOMEPATH         "/p/daemon/housed/"
#define HOUSED                  HOUSED_HOMEPATH "housed"
#define HOUSED_PATHFINDER       HOUSED_HOMEPATH "pathfinder"
#define HOUSED_UPGRADE          HOUSED_HOMEPATH "upgrade"

#define HOUSED_HOUSES_SAVEDIR   "/d/seher/save/haeuser/"
#define HOUSED_HOUSES_REPORTDIR "d/seher/haeuser/"   
#define HOUSED_CARETAKER        ({"dusty","woody","anatol","angrox","eros","gwenshara","wraz"})

#define HOUSED_SAVEFILE        HOUSED_HOMEPATH+"save/housed"
#define HOUSED_PATHFINDER_SAVEFILE HOUSED_HOMEPATH+"save/pathfinder"
#define HOUSED_UPGRADE_SAVEFILE HOUSED_HOMEPATH+"save/upgrade"

#define HOUSED_STD_HOUSE       "/d/seher/std/housed/room00"
#define HOUSED_STD_ROOM        "/d/seher/std/housed/room"
#define HOUSED_ISAHOUSE                      1
#define HOUSED_ISAROOM                       2


#define VIRTUAL "/d/seher/haus/"
#define VIRTUAL_COMPILER (VIRTUAL+"virtual_compiler")

#define PROPER_EXITS ({ \
    "owe","rein","norden","westen","oben","nordwesten","nordosten",\
    "vorne","links","vornelinks","vornerechts",\
    "nordoben","suedoben","westoben","ostoben",\
    "nordwestoben","nordostoben","suedwestoben","suedostoben",\
    "aufi","raus","sueden","osten","unten","suedosten","suedwesten",\
    "hinten","rechts","hintenrechts","hintenlinks",\
    "suedunten","nordunten","ostunten","westunten",\
    "suedostunten","suedwestunten","nordostunten","nordwestunten",\
    })

#endif
