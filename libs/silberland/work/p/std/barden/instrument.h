//
// instrument.h 
//
// Andyl@Silberland
// 
// 27.01.1999 
//
// last updated: 26.05.1999

// Art des Instruments (entspricht der zugehoerigen Bardengruppe)
#define P_INSTRUMENT_TYPE "inst_type"

// Stufe des Insturments (1-5), je hoeher desto besser. Bardenzauber die mit
// zu niedrigem Instrument gespielt werden, haben Nachteile, wenn mit einem
// besseren Instrument gespielt wird gibt es Vorteile.
#define P_INSTRUMENT_LEVEL "inst_level"

// Ein zweidimensionales Array, das je nach Qualitaet des Muszierens die Meldungen
// beim Spielen des Instruments enthaelt. Es muessen immer 12 Stufen sein, dabei
// entspricht der Index
// 0 == Fehschlag (Erfolg auf SK_MUSIC < 0)
// 1 == Erfolg 0-1000
// 2 == Erfolg 0-2000
// ...
// 11 == Maximaler Erfolg (10000+)
// Der gegebene String wird durch process_string geschleust
#define P_INSTRUMENT_MESSAGES "inst_messages"

#define IT_WIND "wind" // floeten, oboen, ...
#define IT_STRING "string" // gitarren, chellos, alles mit saiten
#define IT_DRUM "drum" // trommeln, pauken und andere schlaginstrumente
#define IT_GLASS "glass" // Glasinstrumente
