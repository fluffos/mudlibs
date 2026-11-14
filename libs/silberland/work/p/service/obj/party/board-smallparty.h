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
                 "abfahrtsort" : "Abfahrtsort:";1,\
                 "fahrt"       : "Wie kommst Du her?";2,\
                 "mfg"         : "Kannst Du noch Leute mitnehmen?";3,\
                 "schlafen"    : "Schlafplatz (suche/biete):";4,\
                 "ankunft"     : "Ankunft (Datum/Uhrzeit):";7, \
                 "abfahrt"     : "Abfahrt (Datum/Uhrzeit):";8, \
                 "bemerkungen" : "Bemerkungen:";7])
