// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/message.h
// Description:	Definiert Message- und Messageaction-Typen
// Author:	Freaky (18.05.97)
//
// $Log: message.h,v $
// Revision 1.8  2015/06/01 20:18:40  gnomi
// MT_NO_WRAP eingebaut.
//
// Revision 1.7  2015/06/01 19:47:26  gnomi
// MT_INDENT eingebaut.
//
// Revision 1.6  2001/09/29 23:37:17  sissi
// MA_REMOVE hinzugefuegt
//
// Revision 1.5  2001/03/24 03:28:00  gnomi
// MT_DEBUG eingefuehrt.
//
// Revision 1.4  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef MESSAGE_H
#define MESSAGE_H 1

// Message-Typen

#define MT_UNKNOWN	0x000
#define MT_LOOK		0x001
#define MT_NOISE	0x002
#define MT_FEEL		0x004
#define MT_TASTE	0x008
#define MT_SMELL	0x010
#define MT_SENSE	0x020	// Uebersinnlich (z.B. rede)
#define MT_NOTIFY	0x040	// Einfache Statusmeldungen (z.B. Prompt)
#define MT_CHANNEL	0x080	// Kurier-Kanal
#define MT_FAR          0x100   // Das ganze auf die Ferne 
                                // (nicht im selben Raum)
#define MT_DEBUG	0x200	// Nur fuer Goetter
#define MT_MASK		0x3FF

#define MT_INDENT       0x10000 // Text mit wrap_say umbrechen.
#define MT_NO_WRAP      0x20000 // Text nicht umbrechen.

// Aktions-Typen

#define MA_UNKNOWN	0
#define MA_LOOK		1
#define MA_NOISE	2
#define MA_FEEL		3
#define MA_TASTE	4
#define MA_SMELL	5
#define MA_SENSE	6
#define MA_PUT		8
#define MA_TAKE		9
#define MA_MOVE_IN     10
#define MA_MOVE_OUT    11
#define MA_MOVE        13
#define MA_EMOTE       14
#define MA_FIGHT       15
#define MA_WIELD       16
#define MA_UNWIELD     17
#define MA_WEAR        18
#define MA_UNWEAR      19
#define MA_EAT         20
#define MA_DRINK       21
#define MA_COMM        22
#define MA_MAGIC       23	// Nur verwenden, wenn es in die anderen
				// Kategorien nicht passt!
#define MA_READ        24
#define MA_USE	       25
#define MA_CRAFT       26
#define MA_REMOVE      27

#endif // MESSAGE_H
