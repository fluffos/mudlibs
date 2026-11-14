// SilberLand MUDlib
//
// /p/service/obj/party/board.h -- Partybrett header file
//
// $Date: 2001/10/03 09:53:33 $
/* $Revision: 1.2 $
 * $Log: board.h,v $
 * Revision 1.2  2001/10/03 09:53:33  Woody
 * Fragen klarer
 *
 * Revision 1.1  1997/03/16 17:38:26  Woody
 * prepared for revision control
 *
 */

#define SAVEFILE "/p/service/save/party/board"
#define PM       "/p/service/obj/party/boardmaster"
#define FORM     "/p/service/obj/party/formular"

#define PARTY_ADMINS ([ ])
#define FIELDS ([ \
          "abfahrtsort" : "Abfahrtsort (wg. MFG evtl. relevant):";1,\
          "aufenthalt"  : "Hast Du einen weiten Weg und bleibst "\
                          "laenger (Datum):";2,\
          "schlafen"    : "Schlafplatz (suche/biete):";3,\
          "gaeste"      : "Bringst Du Gaeste mit (wen/wieviele):";4,\
          "rauchfrei"   : "Soll mind. 1 Raum rauch(er)frei bleiben (ja/nein):";5,\
          "hilfe"       : "Kannst/willst Du beim Vorbereiten helfen:";6,\
          "bemerkungen" : "Bemerkungen:";7 ])
