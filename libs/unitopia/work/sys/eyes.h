// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/eyes.h
// Description: Includefile fuer Konstanten fuer die Augen.
// Author:	Garthan (04.01.94)
//
// $Log: eyes.h,v $
// Revision 1.12  2016/03/10 20:26:24  gnomi
// LOOK_COST fuer examine_object() eingebaut.
//
// Revision 1.11  2012-04-15 14:45:41  sorcerer
// Define fuer beaeuge LOOK_SHORT
//
// Revision 1.10  2009-01-15 08:32:25  gnomi
// Defines fuer query_inventory_category und query_inventory_flags.
//
// Revision 1.9  2008/01/16 09:10:09  gnomi
// EYE_NO_EXIT_VIEW eingefuehrt.
//
// Revision 1.8  2006/06/07 20:29:19  gnomi
// Defines fuer die Augenoptionen. Doku fuer set_eye_option.
//
// Revision 1.7  2003/11/01 15:08:40  freaky
// CONTENTS_ flags bereinigt
//
// Revision 1.6  2003/11/01 14:39:55  freaky
// neues Define
//
// Revision 1.5  2003/01/25 04:21:57  gnomi
// EYE_SHOW_ME eingefuehrt, damit der Betrachter selbst mit aufgefuehrt wird.
//
// Revision 1.4  2002/10/28 02:59:15  gnomi
// Defines fuer query_contents hinzugefuegt.
//
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef EYES_H
#define EYES_H 1

// Defines fuer query_room_description
#define EYE_FORCE_LONG		0x01
#define EYE_NO_EXITS		0x02
#define EYE_NO_CONTENTS		0x04
#define EYE_NO_DESCRIPTION	0x08
#define EYE_DARK		0x10
#define EYE_FORCE_DARK		0x10
#define EYE_FORCE_LIGHT         0x20
#define EYE_SHOW_ME		0x40
#define EYE_NO_EXIT_VIEW	0x80

// Augenoptionen:
#define EYE_DIRINFO		"dirinfo"
#define EYE_FILE		"file"
#define EYE_KURZ		"kurz"
#define EYE_HIDDEN_EXITS	"hidden"
#define EYE_NOLIST_EXITS	"nolist"
#define EYE_LOCKED_EXITS	"locked"
#define EYE_ROOM_INVIS		"roominv"
#define EYE_MY_INVIS		"myinv"
#define EYE_OTHER_INVIS		"otherinv"
#define EYE_INVSTYLE		"invstyle"
#define EYE_V_ITEMS		"v_items"
#define EYE_SHADOWS		"shadows"
#define EYE_DEBUG		"debug"

// Defines fuer query_contents
#define CONTENTS_SHOW_INVIS	0x01
#define CONTENTS_SHOW_CONTENTS	0x02

// Defines fuer den ausr-Befehl (Inventory)
#define IC_LIVING	"Lebendiges"
#define IC_WEAPON	"Waffen"
#define IC_ARMOUR	"Ruestungen"
#define IC_CONTAINER	"Behaelter"
#define IC_CLOTHES	"Kleidung"
#define IC_FOOD		"Nahrung"
#define IC_MONEY	"Geld"
#define IC_VALUEABLES	"Wertvolles"
#define IC_OTHER	"Sonstiges"

#define IF_HIDE_INVENTORY	1

// Diese Flags duerfen nicht mit den CONTENTS-Flags kollidieren
#define LOOK_SHORT		0x08
#define LOOK_COST		0x10    // Mustere-ZP-Kosten fallen an

#endif // EYES_H
