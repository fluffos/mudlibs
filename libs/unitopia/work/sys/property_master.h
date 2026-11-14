// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/property_master.h
// Author:      Gnomi
// Description: Defines fuer Properties
//
// $Log: property_master.h,v $
// Revision 1.3  2013-04-02 22:12:03  gnomi
// Unterstuetzung fuer V-Item-Properties.
//
// Revision 1.2  2013-03-18 21:46:39  gnomi
// PI_BASENAME wird nicht mehr gesetzt.
//
// Revision 1.1  2013-03-16 15:15:20  gnomi
// Property-Implementation.
//

#ifndef __PROPERTY_MASTER_H__
#define __PROPERTY_MASTER_H__

#include "lpctypes.h"

#define PROPERTY_ROOT_MASTER	"/apps/properties"

#define PROPERTY_VITEM_POSTFIX	"_v_item_property"

// Property-Infos

#define PI_VALUE	"Value"		// Wert
#define PI_FLAGS	"Flags"		// Flags, siehe unten
#define PI_MASTER	"Master"	// Die beteiligten Master (Array aus Dateinamen)
#define PI_TYPES	"Types"		// Erlaubte Types
#define PI_USES		"Uses"		// Erlaubte Verwendungen

#define PI_SHORTNAME    "ShortName"     // Kurzer Name

#define PI_WIZ_SHORT	"WizShort"	// Kurzbeschreibung fuer Goetter
#define PI_WIZ_LONG	"WizLong"	// Langbeschreibung fuer Goetter

#define PI_SET_FUN	"SetFun"	// Funktion zum Setzen des Wertes
#define PI_GET_FUN	"GetFun"	// Funktion zum Abfragen
#define PI_ADD_FUN	"AddFun"	// Zum Hinzufuegen von Werten
#define PI_DEL_FUN	"DelFun"	// Zum Loeschen von Werten

#define PI_VITEM_SET_FUN	"SetFun" PROPERTY_VITEM_POSTFIX		// Funktion zum Setzen des Wertes
#define PI_VITEM_GET_FUN	"GetFun" PROPERTY_VITEM_POSTFIX		// Funktion zum Abfragen
#define PI_VITEM_ADD_FUN	"AddFun" PROPERTY_VITEM_POSTFIX		// Zum Hinzufuegen von Werten
#define PI_VITEM_DEL_FUN	"DelFun" PROPERTY_VITEM_POSTFIX		// Zum Loeschen von Werten

#define PI_SAVE_FUN	"SaveFun"	// Zum Speichern
#define PI_RESTORE_FUN	"RestoreFun"	// Zum Laden


// Flags

#define PF_SET_LOCAL	1	// Nur lokal schreibar (impliziert PF_GET_NOMASK).
#define PF_LOCAL	2	// Nur lokal les- und schreibbar (impliziert PF_SET_NOMASK und PF_GET_NOMASK)
#define PF_GET_NOMASK	4	// Keine Modify-Controller beim Abfragen
#define PF_SET_NOMASK	8	// Keine Modify-Controller beim Setzen
#define PF_SINGLE_SHOT	16	// Nur einmal setzbar, kein add/delete.
#define PF_NO_CLOSURE	32	// Closures werden nicht ausgefuehrt (sofern keine PI_GET_FUN)
#define PF_PERSISTANT	64	// Wird abgespeichert (Siehe save_properties() / restore_properties())

// Typen

#define PT_MIXED	(1 << T_INVALID)
#define PT_INT		(1 << T_NUMBER)
#define PT_STRING	(1 << T_STRING)
#define PT_ARRAY	(1 << T_POINTER)
#define PT_OBJECT	(1 << T_OBJECT)
#define PT_MAPPING	(1 << T_MAPPING)
#define PT_FLOAT	(1 << T_FLOAT)
#define PT_CLOSURE	(1 << T_CLOSURE)
#define PT_SYMBOL	(1 << T_SYMBOL)
#define PT_QUOTED_ARRAY	(1 << T_QUOTED_ARRAY)
#ifdef __LPC_STRUCTS__
#define PT_STRUCT	(1 << T_STRUCT)
#endif

// Verwendungen

#define PU_ROOM		1
#define PU_ITEM		2
#define PU_MONSTER	4
#define PU_PLAYER	8
#define PU_VITEM	16

#define PU_LIVING	(PU_MONSTER | PU_PLAYER)
#define PU_MOVABLE	(PU_ITEM | PU_LIVING)
#define PU_OBJECT	(PU_MOVABLE | PU_ROOM)

#define PU_DEFAULT	PU_MOVABLE

#endif
