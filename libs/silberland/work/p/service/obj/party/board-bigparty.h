// SilberLand MUDlib
//
// /p/service/obj/party/board.h -- Partybrett header file
//
// $Date: 1997/03/16 17:38:26 $
/* $Revision: 1.1 $
 * $Log: board.h,v $
 * Revision 1.1  1997/03/16 17:38:26  Woody
 * prepared for revision control
 *
 */

#define SAVEFILE "/p/service/save/party/board"
#define PM       "/p/service/obj/party/boardmaster"
#define FORM     "/p/service/obj/party/formular"

#define PARTY_ADMINS ([ ])
#define FIELDS ([ \
		 "abfahrtsort" : "Abfahrtsort (von wo kommst Du):";1, \
		 "fahrt"       : "Wie kommst Du her (Auto, Bahn, ...):";2, \
		 "mfg"         : "Wenn Auto o.ae., kannst Du noch Leute mitnehmen:";3, \
		 "schlafen"    : "Schlafplatz (Zelt oder Huette):";4, \
		 "fruehstueck" : "Soll Fruehstueck organisiert werden (ja/nein):";5, \
		 "vegetarier"  : "Vegetarier(in) (ja/nein/selbstversorger):";6, \
		 "ankunft"     : "Ankunft beim Partyort (Datum/Uhrzeit):";7, \
		 "abfahrt"     : "Abfahrt vom Partyort (Datum/Uhrzeit):";8, \
		 "t-shirt"     : "Hast Du Interesse an einem SL-T-Shirt (Groesse, Anzahl):";9, \
		 "bemerkungen" : "Bemerkungen:";10, \
               ])

