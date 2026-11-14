// homepaged.h - Header File for Homepaged
// $Date: 2002/01/06 04:26:52 $
/* $Revision: 1.3 $
 * $Log: homepaged.h,v $
 * Revision 1.3  2002/01/06 04:26:52  Woody
 * HP_DATAFILE definiert
 *
 * Revision 1.2  2000/03/21 13:18:43  Zordan
 * Header erneuert
 *
 */

#ifndef __HOMEPAGED_H__
#define __HOMEPAGED_H__

#define HP_WWWFILE  "/p/daemon/save/homepaged.shtml"
#define HP_DATAFILE  "/p/daemon/save/homepaged.data"
#define HP_SAVEFILE "/p/daemon/save/homepaged"
#define HP_HEADER "<TABLE BORDER=\"1\" CELLSPACING=\"n\" BGCOLOR=\"#222222\">\n" \
                  "<TR>"
#define HP_TAILER "</TD>\n</TR>\n</TABLE>\n<BR>\n"
#define HP_DEB(x) if(find_player("zordan")) tell_object(find_player("zordan"),x)

#define HOMEPAGED "/p/daemon/homepaged"

#endif // __SHIPD_H__

