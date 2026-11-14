// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/room_types.h
// Description: Konstanten fuer Raumtypen
// Author:      Sorcerer (Nov 2012)
//
// $Log: room_types.h,v $
// Revision 1.2  2016/01/24 11:58:12  myonara
// neuer Typ RT_ARCHITEKTEN: Fuer Schiffe,Mietshaeuser u.ae. die RealNamen
// der Architekten, die den Raum veraendern duerfen.(string*)
//
// Revision 1.1  2012-11-11 21:51:08  sorcerer
// Initial revision
//
//

#ifndef __ROOM_TYPES_H__
#define __ROOM_TYPES_H__

#define RT_KAEMPFEN_VERBOTEN        "kaempfen_verboten"
#define RT_STEHLEN_VERBOTEN         "stehlen_verboten"
#define RT_GRABEN_VERBOTEN          "graben_verboten"
#define RT_MAGIE_VERBOTEN           "keine_magie"
#define RT_HANDWERK_VERBOTEN        "kein_handwerk"
#define RT_TELEPORT_REIN_VERBOTEN   "teleport_rein_verboten"
#define RT_TELEPORT_RAUS_VERBOTEN   "teleport_raus_verboten"
#define RT_VERSAND_REIN_VERBOTEN    "versand_rein_verboten"
#define RT_VERSAND_RAUS_VERBOTEN    "versand_raus_verboten"

#define RT_KEIN_TOTENGRAEBER        "kein_totengraeber"
#define RT_KEIN_CLEANUP             "nocleanup"
#define RT_KEIN_KOMPASS             "kompass_defekt"
#define RT_KEIN_VERBRAUCH           "kein_verbrauch"
#define RT_KEIN_STARTRAUM           "kein_startraum"
#define RT_KEIN_KURIER              "ruhe"
#define RT_KEIN_UEBERFALL_KANAL     "arena"

#define RT_BALLON_ERLAUBT           "ballon_erlaubt"
#define RT_S_BAHN_ERLAUBT           "s-bahn_erlaubt"
#define RT_SCHIFF_ERLAUBT           "schiff_erlaubt"

#define RT_FLUG_FLUGPLATZ           "fliegen_erlaubt"
#define RT_FLUG_START_MELDUNG       "flugstart_meldung"
#define RT_FLUG_LANDE_MELDUNG       "lande_meldung"
#define RT_FLUG_LANDEPLATZ          "landeplatz"

#define RT_SPERRGEBIET              "sperrgebiet"
#define RT_REPRAESENTANT            "repraesentant"
#define RT_UMGEBUNG                 "umgebung"
#define RT_KOMPASS                  "kompass"
#define RT_HAFEN                    "hafen"
#define RT_KUNSTLICHT               "kunstlicht"
#define RT_TAG_NACHT_WECHSEL        "change_daylight"
#define RT_X_KOORDINATE             "x_koordinate"
#define RT_Y_KOORDINATE             "y_koordinate"
#define RT_TEMPERATUR               "temperatur"
#define RT_WASSERVERBRAUCH          "wasserverbrauch"
#define RT_NAHRUNGSVERBRAUCH        "nahrungsverbrauch"
#define RT_STARTRAUM                "startraum"
#define RT_KIRCHE                   "kirche"
#define RT_TEMPEL                   "tempel"
#define RT_RAUMHOEHE                "raumhoehe"
#define RT_FLUCHTAUSGAENGE          "fluchtausgaenge"
#define RT_ARCHITEKTEN              "architekten"

#define RT_LANDSCHAFT               "landschaft"
#ifndef LANDSCHAFT_H
#include "landschaft.h"
#endif // LANDSCHAFT_H

#endif // __ROOM_TYPES_H__
