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
#define FIELDS ([\
                 "abfahrtsort" : "Woher kommst Du:";1,\
                 "fahrt"       : "Wie kommst Du her (Auto, Bahn, ...):";2, \
                 "mfg"         : "Wenn Auto o.ae., kannst Du noch wen mitnehmen:";3, \
                 "schlafen"    : "Schlafplatz (suche/biete):";4,\
                 "gaeste"      : "Wieviele Gaeste bringst Du mit:";5,\
                 "buffet"      : "Willst Du organisiertes Buffet/Alk (zB. Zombie):";6, \
                 "vorschlaege" : "Buffet/Alk-Vorschlaege bzw. Wuensche:";7, \
                 "helfen"      : "Kannst Du bei Organisation/Einkaufen/Zubereiten/\nDeko/Aufraeumen/... mithelfen?:";8, \
                 "bemerkungen" : "Bemerkungen:";9])
