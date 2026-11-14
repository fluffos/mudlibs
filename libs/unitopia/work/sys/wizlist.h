// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/wizlist.h
// Description: Defines fuer wizlist_info()
// Author:	Driver
//
// $Log: wizlist.h,v $
// Revision 1.5  2006/10/18 20:14:32  gnomi
// Auf 3.3.714 aktualisiert.
//
// Revision 1.4  2003/04/24 15:06:43  freaky
// Doku von ldmud-3.2.10dev575 eingespielt
//
// Revision 1.3  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_WIZLIST_H_
#define LPC_WIZLIST_H_ 1

/* Indices returned by wizlist_info()
 */

#define WL_NAME           0  /* Wizard name */
#define WL_COMMANDS       1  /* Number of commands executed */
#define WL_COST           2  /* Weighted evalcost spent on this wizard */
#define WL_GIGACOST       3  /* Weighted giga-evalcost spent on this wizard */
#define WL_TOTAL_COST     4  /* Total evalcost spent on this wizard */
#define WL_TOTAL_GIGACOST 5  /* Total giga-evalcost spent on this wizard */
#define WL_HEART_BEATS    6  /* Heartbeats spent on this wizard */
#define WL_CALL_OUT       7  /* unimplemented */
#define WL_ARRAY_TOTAL    8  /* Arrays accounted for */
#define WL_MAPPING_TOTAL  9  /* Mappings accounted for */
#define WL_STRUCT_TOTAL  10  /* Struct elements accounted for */
#define WL_EXTRA         11  /* Extra Wizinfo, if set */

#define WL_SIZE  12  /* Number of entries */

#endif /* LPC_WIZLIST_H_ */
