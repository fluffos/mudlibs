// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        wasser.h
// Description: Definitionen fuer Brunnen, Fluesse, Flaschen und Wasser
// Author:      Jafar & Yellow
//
// $Log: wasser.h,v $
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef WASSER_H
#define WASSER_H 1

// die Pfade der Inherits und Objekte

#define WASSER_I    "/i/wasser/wasser"
#define GIFT_I      "/i/wasser/gift"
#define BRUNNEN_I   "/i/wasser/brunnen"
#define FLUSS_I     "/i/wasser/fluss"
#define FLASCHE_I   "/i/wasser/flasche"

#define WASSER_OBJ  "/obj/wasser"
#define GIFT_OBJ    "/obj/gift"
#define BRUNNEN_OBJ "/obj/brunnen"
#define FLASCHE_OBJ "/obj/flasche"

// die Default-Werte fuer gewoehnliches Wasser

#define AMOUNT      40
#define HEALING     0
#define STRENGTH    0

// Inhalt der Flasche

#define MAX_CONTENT 10

// potentielle Quellen fuer Wasser

#define WATER_ID ({"wasser", "brunnen", "fluss", "bach", "see", \
                   "teich", "quelle", "wasserfall", "wein", "fass" })

#endif // WASSER_H
