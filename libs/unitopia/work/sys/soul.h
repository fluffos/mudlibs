// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/soul.h
// Description: Defines fuer die Seele
// Created by : Monty 11.11.94
// Modifyed by:
//   Parsec  02.10.98   - neu: IGNORE_FAR  (wenn's egal ist ob ein gefundenes
//                        V-Item weit weg ist.
//                      - MIES, NEUTRAL, NETT als Bewertungen von Seeleaktionen
//
// $Log: soul.h,v $
// Revision 1.5  2006/01/22 01:24:12  gnomi
// Defines fuer modify_comm.
//
// Revision 1.4  2002/02/23 05:17:02  gnomi
// PO/PL -> SOUL_PO/PL
//
// Revision 1.3  2001/03/23 01:16:23  gnomi
// Zusaetzliches Flag fuer soul_parser (siehe dort.)
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef SOUL_H
#define SOUL_H 1

#define PARTNER 	1
#define LIVING 		2
#define OBJECT 		4
#define IGNORE_FAR      8
#define NOT_TO_ENV	16

#define SOUL_PO		PARTNER | OBJECT
#define SOUL_PL		PARTNER | LIVING

// Fuer Align von Seele-Befehlen
#define MIES            -1
#define NEUTRAL         0
#define NETT            1

// Fuer zusaetzliche Flags von Seele-Befehlen
#define PSEUDO_MOVE     1

#define VOICE_FLUESTERMODUS	0x0100
#define VOICE_TUSCHELMODUS	0x0200
#define VOICE_LALLEN		0x0400
#define VOICE_LISPELN		0x0800
#define VOICE_STOTTERN		0x1000
#define VOICE_SUMMEN		0x2000

#endif // SOUL_H
