// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/mapil.h
// Description:	Magic Application Programm Interface Light
// Author:	Freaky (27.08.2001)
//
// $Log: mapil.h,v $
// Revision 1.4  2016/07/16 07:28:16  myonara
// M_F_NO_MESSAGE eingefuehrt.
//
// Revision 1.3  2009-03-20 08:25:56  gnomi
// M_T_TRANSPORT eingetragen.
//
// Revision 1.2  2002/02/27 23:51:04  freaky
// neue Typen: create,summon
//
// Revision 1.1  2001/08/27 14:10:58  freaky
// added
//

#ifndef MAPIL_H
#define MAPIL_H

// Typ (Handwerk oder Magie) 1. Parameter
#define M_B_HANDWERK	"handwerk"
#define M_B_H		M_B_HANDWERK	// Alias
#define M_B_MAGIE	"magie"
#define M_B_M		M_B_MAGIE	// Alias

// Flags fuer den 2. Parameter
#define M_T_FIGHT	 1	// Kampf, Angriff, Schaden
#define M_T_PROTECT	 2	// Schutz
#define M_T_HEAL	 3	// Heilung
#define M_T_INFO	 4	// Information
#define M_T_TELEPORT	 5	// Teleport
#define M_T_NUTRITION	 6	// Nachrungsaufnahme, -erzeugung, ...
#define M_T_MANIPULATION 7	// Allgemeine Manipulationen
#define M_T_MP		 7		// kuerzeres Alias
#define M_T_MINDCONTROL	 8	// Gedankenkontrolle
#define M_T_MC		 8		// kuerzeres Alias
#define M_T_HIDE	 9	// Tarnung
#define M_T_COMM	10	// Kommunikation
#define M_T_CREATE	11	// Ein Objekt erzeugen
#define M_T_SUMMON	12	// Ein Wesen beschwoeren
#define M_T_TRANSPORT	13	// Einen Gegenstand verschicken

// veroderbare Flags fuer die Auswirkung des Zaubers:
#define M_F_FAR		0x001	// Fernzauber
#define M_F_OFFENSIVE	0x002	// Offensive Zauber
#define M_F_AREA	0x004	// Flaecheneffekt
#define M_F_POSITIVE	0x008	// Positiver Effekt
#define M_F_NEGATIVE	0x010	// Negativer Effekt
#define M_F_TEST	0x020	// Es soll nur getestet werden, ob der
				// Spruck moeglich ist. Es wird aber keiner
				// ausgefuehrt. -> Keine Meldung erzeugen.
				// Der Rueckgabewert ist in diesem Fall
				// ein Integer, der den Grund liefern kann.
#define M_F_NO_MESSAGE  0x040   // alle Meldungen unterdruecken.

#endif // MAPIL_H
