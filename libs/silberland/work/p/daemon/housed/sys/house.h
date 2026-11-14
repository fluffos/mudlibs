/* 
 * /p/daemon/housed/sys/house.h - Deklarationen zum Seherhausverwalter 
 *
 * (c) 2000 Mud Silberland - Adrian Holzwarth / Anatol@Silberland
 *
 *  2000 11 18 Revision 0.1   Aus houses.h extrahiert.
 *
 *  2000 12 04 Revision 0.2   Umgestellt. Viel umgestellt.
 */

#ifndef _HOUSED_HOUSE_H_
#define _HOUSED_HOUSE_H_

#include "housed.h"

#define KURZ           2
#define LANG           4
#define DETAIL         8
#define RDETAIL       16
#define BEFEHL        32  // Nur aendern
#define REPORT        64  // Nur aendern
#define GERAEUSCH    128
#define GERUCH       256

#define H_OWNSMELLS   "h_ownsmells"
#define H_OWNSOUNDS   "h_ownsounds"
#define H_COMMANDS    "h_commands" 
#define H_REPORT      "h_report"    
#define H_SPECIAL     "h_special" 
#define H_ACCESS      "h_access"

#define HS_ITEM       1  // ein bestimmtes Objekt (per AddItem())
#define HS_EXIT       2  // ein Ausgang (per AddExit())

#define TH (file_name(this_object())[0..<3]+"00")
#define THROOM(x) (sprintf("%s%02d", \
              file_name(this_object())[0..<3],x))
#define THQ(x) TH->Query(x)
#define HMQ(x) (HOUSED->Query(owner,house_no, x))
#define REPFILE(x,y) sprintf("/log/%s%s:%02d.rep",HOUSED_HOUSES_REPORTDIR,x,y)

#define SPECIALID "house_speci\al_i\tem"

#ifdef NEED_PROTOTYPES
public varargs void Save(int crunched);
public void Load();
public varargs string QueryOwner(int withNr);
#endif

#endif
