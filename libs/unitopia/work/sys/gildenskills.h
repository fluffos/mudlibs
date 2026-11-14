// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/gildenskills.h
// Description:	Defines fuer die Gilden-Skills
// Author:	Parsec
//
// $Log: gildenskills.h,v $
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef GILDENSKILLS_H
#define GILDENSKILLS_H 1

// Reihenfolge darf NICHT veraendert werden, wegen gespeicherten
// Spielerdaten!
#define MAGIE_MANIPULATION  0
#define MAGIE_OFFENSIV      1
#define MAGIE_ILLUSION      2
#define MAGIE_DEFENSIV      3
#define MAGIE_INFORMATION   4
#define HANDWERK_STEHLEN    5
#define ZAUBER_TARNEN       6
#define ZAUBER_SUCHE        7
#define ZAUBER_NEHMEN       8
// Neue hoehere Nummern koennen vom  Gildenskill-Objekt automatisch
// verwaltet werden -> keine Aenderungen notwendig.

// Hoechste Nummer bei den Gildenskills
#define MAX_GILDENSKILL     8

#endif // GILDENSKILLS_H
