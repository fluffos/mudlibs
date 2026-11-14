/* sys/kraut.h  - zwei kraut properties
 * __________________________________________(i) Anatol@Silberland (2012) */


#ifndef DEFINES_KRAUT_PROPERTIES
#define DEFINES_KRAUT_PROPERTIES

// The P_KRAUT_DRYING_FACTOR ist mindestens 1 und nach oben quasi unbegrenzt.
// Eine Ausnahme ist 0, hierfuer wird "unendlich" (immer frisch!) angenommen. 
// Als Default-Wert kann 20 angesetzt werden.

// Der Faktor verlaengert den Trockungsprozess der Pflanze. In der Minimum-
// Konfiguration (1) ist das gepflueckte Kraut nach 8 Sekunden nicht mehr 
// frisch und nach einer Minute trocken.


#define P_KRAUT_DRYING_FACTOR "kraut_drying_factor"

// P_KRAUT_RESETS_UNTIL_DECOMPOSE steuert die Gesamtlebensdauer des Krauts.
// Abgefragt wird die Property erst, wenn das Kraut durchgetrocknet ist, 
// ab dann bestimmt der Reset, ob es zerfaellt oder nicht. Die Property
// wird in jedem Reset heruntergezaehlt.

#define P_KRAUT_RESETS_UNTIL_DECOMPOSE "kraut_resets_until_decompose"

#endif
