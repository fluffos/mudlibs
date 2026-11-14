// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/quest.h
// Description:	Defines fuer Raetsel
//
// $Log: quest.h,v $
// Revision 1.4  2001/09/16 19:32:20  sissi
// Wahl-Pflicht-Raetsel eingefuehrt (Nethar)
//
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef QUEST_H
#define QUEST_H 1

#define QUEST_ROOM "/room/rathaus/raetsel"
#define Q_AUTH_NAME "raetsel"

#define Q_ALL		0x01
#define Q_NOT_NECESSARY	0x02
#define Q_NECESSARY	0x04
#define Q_TEST		0x08
#define Q_WAHL      0x10

#define Q_SOLVED	-1
#define Q_NOT_INSTALLED -1

#define Q_NAME		0
#define Q_OBJ		1
#define Q_PROGRAMMERS	2
#define Q_PARAMETERS	3
#define Q_REMARKS	4
#define Q_CAP_NAME      5

// Flags
#define QF_TEST		1
#define QF_REQUIRED	2
#define QF_RENOVATE	4
#define QF_WAHL     8

// Parameters
#define QP_FLAGS	0

// Anzahl der benoetigten Wahlraetsel fuer Engelswerdung
#define NEEDED_CHOICE_QUESTS 5

#endif // QUEST_H
