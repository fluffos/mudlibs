// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/description.h
// Description:	Defines fuer /i/tools/description.c
//
// $Log: description.h,v $
// Revision 1.19  2013-03-16 16:09:08  gnomi
// Typos.
//
// Revision 1.18  2009-09-07 22:12:24  gnomi
// TI_OBJECT eingetragen.
//
// Revision 1.17  2009-06-17 08:04:21  gnomi
// T_BROKEN und Co. eingetragen.
//
// Revision 1.16  2009-01-15 09:32:58  gnomi
// T_ROOMTYPETEXT korrigiert.
//
// Revision 1.15  2008-05-28 07:29:59  gnomi
// Typo.
//
// Revision 1.14  2008-04-26 18:20:22  gnomi
// T_EMPTY eingebaut.
//
// Revision 1.13  2008/02/25 11:51:22  gnomi
// T_COND_(DEEP_)PRESENT* eingebaut.
//
// Revision 1.12  2008/01/31 07:57:42  gnomi
// T_DEBUG.
//
// Revision 1.11  2008/01/24 22:51:56  gnomi
// T_CAPITALIZE, T_UPPERCASE und T_LOWERCASE implementiert.
//
// Revision 1.10  2008/01/21 14:29:58  gnomi
// T_OWNER vergessen gehabt.
//
// Revision 1.9  2008/01/16 09:56:17  gnomi
// Defines fuer die Tuer, Nahrung und Leuchte eingebaut.
// T_PSEUDO definiert.
//
// Revision 1.8  2007/08/25 23:20:47  gnomi
// Defines fuer das Beschuetzen.
//
// Revision 1.7  2007/08/09 22:31:14  gnomi
// Ein paar neue Defines, u.a. fuer Kleidung, Waffen und Ruestungen.
//
// Revision 1.6  2007/06/25 22:21:27  gnomi
// Defines fuer i/living/face.
//
// Revision 1.5  2007/05/26 22:51:01  gnomi
// T_EXIT_FLAG und die T_CON-Bedingungen fuer Container eingetragen.
//
// Revision 1.4  2006/12/30 01:09:47  gnomi
// T_(VIS|INVIS|HIDDEN)_PRESENT(_ROOM|_CONT) eingebaut.
//
// Revision 1.3  2006/08/29 22:31:51  gnomi
// T_SPIELERRAT eingebaut.
//
// Revision 1.2  2006/06/25 00:19:10  gnomi
// T_DARKNESS eingebaut.
//
// Revision 1.1  2006/06/07 18:48:54  gnomi
// Spezielle Beschreibungsmoeglichkeiten fuer Gegenstaende und Raeume.
//

#ifndef __DESCRIPTION_H__
#define __DESCRIPTION_H__ 1

// Aus hysterischen Gruenden.
#include "player_description.h"
#include "description_core.h"
#include "simul_efuns.h"
#include "invis.h"

#define TP_ALL			"all"
#define TP_ROOM			"room"
#define TP_CONTAINER		"cont"
#define TP_VIEWER		"viewer"

// Vordefinierte Bedingungen fuer Raeume (2. Element im Array)
#define T_ATOM_DAY		"tag"
#define T_ATOM_NIGHT		"nacht"
#define T_ATOM_DARK		"dunkel"
#define T_ATOM_LIGHT		"hell"
#define T_ATOM_BLIND		"blind"
#define T_ATOM_EMPTY		"empty"
#define T_ATOM_VIS_EMPTY	"vis_empty"
#define T_ATOM_PRESENT		"present"
#define T_ATOM_PRESENT_ROOM	"present_room"
#define T_ATOM_PRESENT_CONT	"present_cont"
#define T_ATOM_VIS_PRESENT	"vis_present"
#define T_ATOM_VIS_PRESENT_ROOM	"vis_present_room"
#define T_ATOM_VIS_PRESENT_CONT	"vis_present_cont"
#define T_ATOM_INVIS_PRESENT		"invis_present"
#define T_ATOM_INVIS_PRESENT_ROOM	"invis_present_room"
#define T_ATOM_INVIS_PRESENT_CONT	"invis_present_cont"
#define T_ATOM_COND_PRESENT	"cond_present"
#define T_ATOM_EXIT_FLAG	"exit_flag"
#define T_ATOM_GILDE		"gilde"
#define T_ATOM_GENDER		"gender"
#define T_ATOM_VCLOCK		"vclock"
#define T_ATOM_CLOCK		"clock"
#define T_ATOM_ROOMTYPE		"roomtype"
#define T_ATOM_NO_ASCII_ART	"no_ascii_art"
#define T_ATOM_FAR		"far"
#define T_ATOM_OWNER		"owner"
#define T_ATOM_ENTRANCE		"entrance"
#define T_ATOM_GUEST		"is_guest"
#define T_ATOM_NEWBIE		"is_newbie"
#define T_ATOM_WIZ		"is_wiz"
#define T_ATOM_SPIELERRAT	"is_spielerrat"
#define T_ATOM_EYE_OPTION	"eye_option"

// Von /i/base/container
#define T_ATOM_CON_LOCKED	"con_locked"
#define T_ATOM_CON_CLOSED	"con_closed"
#define T_ATOM_CON_NO_DOOR	"con_no_door"

#define T_ATOM_TAG_CON_LOCKED	"con_locked"
#define T_ATOM_TAG_CON_CLOSED	"con_closed"

// Von /i/living/face
#define T_ATOM_HAS_VICTIMS	"has_victims"
#define T_ATOM_HAS_SCARS	"has_scars"
#define T_ATOM_HAS_PROTECTEE	"has_protectee"
#define T_ATOM_HAS_PROTECTORS	"has_protectors"

#define T_ATOM_VICTIM_TEXT	"victim_text"
#define T_ATOM_SCAR_TEXT	"scar_text"
#define T_ATOM_HP_TEXT		"hp_text"
#define T_ATOM_PROTECTEE_TEXT	"protectee_text"
#define T_ATOM_PROTECTORS_TEXT	"protectors_text"

#define T_ATOM_TAG_VICTIM_TEXT	"victim_text"
#define T_ATOM_TAG_SCAR_TEXT	"scar_text"
#define T_ATOM_TAG_HP_TEXT	"hp_text"
#define T_ATOM_TAG_PROTECTEE_TEXT	"protectee_text"
#define T_ATOM_TAG_PROTECTORS_TEXT	"protectors_text"

// Von /i/object/tuer
#define T_ATOM_DOOR_LOCKED	"door_locked"
#define T_ATOM_DOOR_CLOSED	"door_closed"
#define T_ATOM_DOOR_STATUS_TEXT	"door_status_text"
#define T_ATOM_TAG_DOOR_STATUS	"door_status"

// Von /i/clothes/kleidung
#define T_ATOM_WORN		"worn"
#define T_ATOM_WORN_TEXT	"worn_text"
#define T_ATOM_TAG_WORN_TEXT	"worn_text"

// Von /i/weapon/weapon_logic
#define T_ATOM_WIELD		"wield"
#define T_ATOM_WIELD_TEXT	"wield_text"
#define T_ATOM_TAG_WIELD_TEXT	"wield_text"

// Von /i/weapon/weapon_logic und /i/armour/armour
#define T_ATOM_BROKEN		"broken"
#define T_ATOM_BROKEN_TEXT	"broken_text"
#define T_ATOM_TAG_BROKEN_TEXT	"broken_text"
#define TN_LIFE			"life"

// Von /i/object/nahrung
#define T_ATOM_BITTEN_INTO		"bitten_into"
#define T_ATOM_BEING_EATEN		"being_eaten"
#define T_ATOM_BEING_EATEN_BY_VIEWER	"being_eaten_by_viewer"

#define T_ATOM_BITTEN_INTO_TEXT		"bitten_text"
#define T_ATOM_BEING_EATEN_TEXT		"eating_text"
#define T_ATOM_TAG_BITTEN_INTO_TEXT	"bitten_text"
#define T_ATOM_TAG_BEING_EATEN_TEXT	"eating_text"

// Von /i/object/leuchte
#define T_ATOM_IS_LIGHTED		"is_lighted"
#define TN_FUEL_PERCENT			"fuel_percent"

// Vordefinierte Texte
#define T_ATOM_DAYTIME	"daytime"
#define T_ATOM_DARKNESS	"darkness"
#define T_ATOM_SHORT_DESC "shortdesc"

// Tags, die gesetzt werden.
#define T_ATOM_TAG_DAYTIME	"daytime"
#define T_ATOM_TAG_DARKNESS	"darkness"
#define T_ATOM_TAG_BLINDTEXT	"blindtext"
#define T_ATOM_TAG_SHORT_DESC	"shortdesc"

// Vordefinierte Filter
#define T_ATOM_CAPITALIZE	"capitalize"
#define T_ATOM_UPPERCASE	"uppercase"
#define T_ATOM_LOWERCASE	"lowercase"
#define T_ATOM_DEBUG		"debug"

// Vordefinierte Sprachen
#define T_ATOM_PSEUDO		"pseudo closure"

// Vordefinierte Eigenschaften fuer T_GREATER & Co.
#define TN_VCLOCK	"vclock"
#define TN_CLOCK	"clock"
#define TN_STAT_STR	"stat_str"
#define TN_STAT_INT	"stat_int"
#define TN_STAT_CON	"stat_con"
#define TN_STAT_DEX	"stat_dex"
#define TN_KOERPERGROESSE "koerpergroesse"
#define TN_ALIGN	"align"
#define TN_LEVEL	"level"
#define TN_STAYDUR	"duration of stay"

// Und nun die Defines, die man verwenden sollte:
#define T_DAY			({ T_ATOM_COND, T_ATOM_DAY })
#define T_NIGHT			({ T_ATOM_COND, T_ATOM_NIGHT })
#define T_DARK			T_TAG_COND(T_ATOM_TAG_DARKNESS, ({ T_ATOM_COND, T_ATOM_DARK }))
#define T_LIGHT			T_TAG_COND(T_ATOM_TAG_DARKNESS, ({ T_ATOM_COND, T_ATOM_LIGHT }))
#define T_DAY_DARK		T_AND(T_DAY, T_DARK)
#define T_DAY_LIGHT		T_AND(T_DAY, T_LIGHT)
#define T_NIGHT_DARK		T_AND(T_NIGHT, T_DARK)
#define T_NIGHT_LIGHT		T_AND(T_NIGHT, T_LIGHT)
#define T_BLIND			T_TAG_COND(T_ATOM_TAG_BLINDTEXT, ({ T_ATOM_COND, T_ATOM_BLIND }))
#define T_EMPTY			({ T_ATOM_COND, T_ATOM_EMPTY })
#define T_VIS_EMPTY		({ T_ATOM_COND, T_ATOM_VIS_EMPTY })
#define T_PRESENT(id)		({ T_ATOM_COND, T_ATOM_PRESENT, (id) })
#define T_PRESENT_ROOM(id)	({ T_ATOM_COND, T_ATOM_PRESENT_ROOM, (id) })
#define T_PRESENT_CONT(id)	({ T_ATOM_COND, T_ATOM_PRESENT_CONT, (id) })
#define T_VIS_PRESENT(id)	({ T_ATOM_COND, T_ATOM_VIS_PRESENT, (id) })
#define T_VIS_PRESENT_ROOM(id)	({ T_ATOM_COND, T_ATOM_VIS_PRESENT_ROOM, (id) })
#define T_VIS_PRESENT_CONT(id)	({ T_ATOM_COND, T_ATOM_VIS_PRESENT_CONT, (id) })
#define T_INVIS_PRESENT(id, inv)	({ T_ATOM_COND, T_ATOM_INVIS_PRESENT, (id), (inv) })
#define T_INVIS_PRESENT_ROOM(id, inv)	({ T_ATOM_COND, T_ATOM_INVIS_PRESENT_ROOM, (id), (inv) })
#define T_INVIS_PRESENT_CONT(id, inv)	({ T_ATOM_COND, T_ATOM_INVIS_PRESENT_CONT, (id), (inv) })
#define T_HIDDEN_PRESENT(id)		T_INVIS_PRESENT((id), V_ATOM_HIDDEN)
#define T_HIDDEN_PRESENT_ROOM(id)	T_INVIS_PRESENT_ROOM((id), V_ATOM_HIDDEN)
#define T_HIDDEN_PRESENT_CONT(id)	T_INVIS_PRESENT_CONT((id), V_ATOM_HIDDEN)

#define T_COND_PRESENT(id,fun)			({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_ALL, CDP_FLAT, (id), (fun) })
#define T_COND_PRESENTV(id,fun,arg)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_ALL, CDP_FLAT, (id), (fun), (arg) })
#define T_COND_PRESENT_ROOM(id,fun)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_ROOM, CDP_FLAT, (id), (fun) })
#define T_COND_PRESENT_ROOMV(id,fun,arg)	({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_ROOM, CDP_FLAT, (id), (fun), (arg) })
#define T_COND_PRESENT_CONT(id,fun)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_CONTAINER, CDP_FLAT, (id), (fun) })
#define T_COND_PRESENT_CONTV(id,fun,arg)	({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_CONTAINER, CDP_FLAT, (id), (fun), (arg) })
#define T_COND_PRESENT_VIEWER(id,fun)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_VIEWER, CDP_FLAT, (id), (fun) })
#define T_COND_PRESENT_VIEWERV(id,fun,arg)	({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_VIEWER, CDP_FLAT, (id), (fun), (arg) })
#define T_COND_DEEP_PRESENT(id,deep,fun)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_ALL, (deep), (id), (fun) })
#define T_COND_DEEP_PRESENTV(id,deep,fun,arg)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_ALL, (deep), (id), (fun), (arg) })
#define T_COND_DEEP_PRESENT_ROOM(id,deep,fun)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_ROOM, (deep), (id), (fun) })
#define T_COND_DEEP_PRESENT_ROOMV(id,deep,fun,arg)	({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_ROOM, (deep), (id), (fun), (arg) })
#define T_COND_DEEP_PRESENT_CONT(id,deep,fun)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_CONTAINER, (deep), (id), (fun) })
#define T_COND_DEEP_PRESENT_CONTV(id,deep,fun,arg)	({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_CONTAINER, (deep), (id), (fun), (arg) })
#define T_COND_DEEP_PRESENT_VIEWER(id,deep,fun)		({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_VIEWER, (deep), (id), (fun) })
#define T_COND_DEEP_PRESENT_VIEWERV(id,deep,fun,arg)	({ T_ATOM_COND, T_ATOM_COND_PRESENT, TP_VIEWER, (deep), (id), (fun), (arg) })

#define T_EXIT_FLAG(cmd,flag)	({ T_ATOM_COND, T_ATOM_EXIT_FLAG, (cmd), (flag) })
#define T_GILDE(gilde)		({ T_ATOM_COND, T_ATOM_GILDE, (gilde) })
#define T_GENDER(gender)	({ T_ATOM_COND, T_ATOM_GENDER, (gender) })
#define T_VCLOCK(from,to)	({ T_ATOM_COND, T_ATOM_VCLOCK, (from), (to) })
#define T_CLOCK(from,to)	({ T_ATOM_COND, T_ATOM_CLOCK, (from), (to) })
#define T_ROOMTYPE(type)	({ T_ATOM_COND, T_ATOM_ROOMTYPE, (type) })
#define T_NO_ASCII_ART		({ T_ATOM_COND, T_ATOM_NO_ASCII_ART })
#define T_FAR			({ T_ATOM_COND, T_ATOM_FAR })
#define T_OWNER			({ T_ATOM_COND, T_ATOM_OWNER })
#define T_ENTRANCE(exit)	({ T_ATOM_COND, T_ATOM_ENTRANCE, (exit) })
#define T_GUEST			({ T_ATOM_COND, T_ATOM_GUEST })
#define T_NEWBIE		({ T_ATOM_COND, T_ATOM_NEWBIE })
#define T_WIZ			({ T_ATOM_COND, T_ATOM_WIZ })
#define T_SPIELERRAT		({ T_ATOM_COND, T_ATOM_SPIELERRAT })
#define T_EYE_OPTION(opt)	({ T_ATOM_COND, T_ATOM_EYE_OPTION, (opt) })

#define T_HAS_DAYTIME		T_TAG(T_ATOM_TAG_DAYTIME)
#define T_HAS_BLINDTEXT		T_TAG(T_ATOM_TAG_BLINDTEXT)
#define T_HAS_SHORT_DESC	T_TAG(T_ATOM_TAG_SHORT_DESC)

#define T_DAYTIME		T_TAG_COND(T_ATOM_TAG_DAYTIME, ({ T_ATOM_TEXT, T_ATOM_DAYTIME }))
#define T_ROOMTYPETEXT(type)	({ T_ATOM_TEXT, T_ATOM_ROOMTYPE, (type) })
#define T_DARKNESS_TEXT		({ T_ATOM_TEXT, T_ATOM_DARKNESS })
#define T_SHORT_DESC		T_TAG_COND(T_ATOM_TAG_SHORT_DESC, ({ T_ATOM_TEXT, T_ATOM_SHORT_DESC }))

#define T_CAPITALIZE		({ T_ATOM_FILTER, T_ATOM_CAPITALIZE })
#define T_UPPERCASE		({ T_ATOM_FILTER, T_ATOM_UPPERCASE })
#define T_LOWERCASE		({ T_ATOM_FILTER, T_ATOM_LOWERCASE })
#define T_DEBUG			({ T_ATOM_FILTER, T_ATOM_DEBUG })

#define T_PSEUDO(str)		({ T_ATOM_COMPILE, T_ATOM_PSEUDO, (str) })

// Von /i/base/container
#define T_CON_LOCKED		T_TAG_COND(T_ATOM_TAG_CON_LOCKED, ({ T_ATOM_COND, T_ATOM_CON_LOCKED }))
#define T_CON_CLOSED		T_TAG_COND(T_ATOM_TAG_CON_CLOSED, ({ T_ATOM_COND, T_ATOM_CON_CLOSED }))
#define T_CON_NO_DOOR		({ T_ATOM_COND, T_ATOM_CON_NO_DOOR })

// Von /i/living/face
#define T_HAS_VICTIMS		({ T_ATOM_COND, T_ATOM_HAS_VICTIMS })
#define T_HAS_SCARS		({ T_ATOM_COND, T_ATOM_HAS_SCARS })
#define T_HAS_PROTECTEE		({ T_ATOM_COND, T_ATOM_HAS_PROTECTEE })
#define T_HAS_PROTECTORS	({ T_ATOM_COND, T_ATOM_HAS_PROTECTORS })

#define T_HAS_VICTIM_TEXT	T_TAG(T_ATOM_TAG_VICTIM_TEXT)
#define T_HAS_SCAR_TEXT		T_TAG(T_ATOM_TAG_SCAR_TEXT)
#define T_HAS_HP_TEXT		T_TAG(T_ATOM_TAG_HP_TEXT)
#define T_HAS_PROTECTEE_TEXT	T_TAG(T_ATOM_TAG_PROTECTEE_TEXT)
#define T_HAS_PROTECTORS_TEXT	T_TAG(T_ATOM_TAG_PROTECTORS_TEXT)

#define T_VICTIM_TEXT		T_TAG_COND(T_ATOM_TAG_VICTIM_TEXT, ({ T_ATOM_TEXT, T_ATOM_VICTIM_TEXT }))
#define T_SCAR_TEXT		T_TAG_COND(T_ATOM_TAG_SCAR_TEXT, ({ T_ATOM_TEXT, T_ATOM_SCAR_TEXT }))
#define T_HP_TEXT		T_TAG_COND(T_ATOM_TAG_HP_TEXT, ({ T_ATOM_TEXT, T_ATOM_HP_TEXT }))
#define T_PROTECTEE_TEXT	T_TAG_COND(T_ATOM_TAG_PROTECTEE_TEXT, ({ T_ATOM_TEXT, T_ATOM_PROTECTEE_TEXT }))
#define T_PROTECTORS_TEXT	T_TAG_COND(T_ATOM_TAG_PROTECTORS_TEXT, ({ T_ATOM_TEXT, T_ATOM_PROTECTORS_TEXT }))

// Von /i/object/tuer
#define T_DOOR_LOCKED		T_TAG_COND(T_ATOM_TAG_DOOR_STATUS, ({ T_ATOM_COND, T_ATOM_DOOR_LOCKED }))
#define T_DOOR_CLOSED		T_TAG_COND(T_ATOM_TAG_DOOR_STATUS, ({ T_ATOM_COND, T_ATOM_DOOR_CLOSED }))
#define T_DOOR_STATUS_TEXT	T_TAG_COND(T_ATOM_TAG_DOOR_STATUS, ({ T_ATOM_TEXT, T_ATOM_DOOR_STATUS_TEXT }))
#define T_HAS_DOOR_STATUS	T_TAG(T_ATOM_TAG_DOOR_STATUS)

// Von /i/clothes/kleidung
#define T_WORN			({ T_ATOM_COND, T_ATOM_WORN })
#define T_HAS_WORN_TEXT		T_TAG(T_ATOM_TAG_WORN_TEXT)
#define T_WORN_TEXT		T_TAG_COND(T_ATOM_TAG_WORN_TEXT, ({ T_ATOM_TEXT, T_ATOM_WORN_TEXT }))

// Von /i/weapon/weapon_logic
#define T_WIELD			({ T_ATOM_COND, T_ATOM_WIELD })
#define T_HAS_WIELD_TEXT	T_TAG(T_ATOM_TAG_WIELD_TEXT)
#define T_WIELD_TEXT		T_TAG_COND(T_ATOM_TAG_WIELD_TEXT, ({ T_ATOM_TEXT, T_ATOM_WIELD_TEXT }))
#define T_BROKEN		({ T_ATOM_COND, T_ATOM_BROKEN })
#define T_HAS_BROKEN_TEXT	T_TAG(T_ATOM_TAG_BROKEN_TEXT)
#define T_BROKEN_TEXT		T_TAG_COND(T_ATOM_TAG_BROKEN_TEXT, ({ T_ATOM_TEXT, T_ATOM_BROKEN_TEXT }))

// Von /i/object/nahrung
#define T_BITTEN_INTO		T_TAG_COND(T_ATOM_TAG_BITTEN_INTO_TEXT, ({ T_ATOM_COND, T_ATOM_BITTEN_INTO }))
#define T_BEING_EATEN		T_TAG_COND(T_ATOM_TAG_BEING_EATEN_TEXT, ({ T_ATOM_COND, T_ATOM_BEING_EATEN}))
#define T_BEING_EATEN_BY_VIEWER	T_TAG_COND(T_ATOM_TAG_BEING_EATEN_TEXT, ({ T_ATOM_COND, T_ATOM_BEING_EATEN_BY_VIEWER}))

#define T_BITTEN_INTO_TEXT	T_TAG_COND(T_ATOM_TAG_BITTEN_INTO_TEXT, ({ T_ATOM_TEXT, T_ATOM_BITTEN_INTO_TEXT}))
#define T_BEING_EATEN_TEXT	T_TAG_COND(T_ATOM_TAG_BEING_EATEN_TEXT, ({ T_ATOM_TEXT, T_ATOM_BEING_EATEN_TEXT}))

#define T_HAS_BITTEN_INTO_TEXT	T_TAG(T_ATOM_TAG_BITTEN_INTO_TEXT)
#define T_HAS_BEING_EATEN_TEXT	T_TAG(T_ATOM_TAG_BEING_EATEN_TEXT)

// Von /i/object/leuchte
#define T_IS_LIGHTED		({ T_ATOM_COND, T_ATOM_IS_LIGHTED })

// Mapping-Eintraege
#define TI_VIEWER		"viewer"
#define TI_ROOM			"room"
#define TI_DARK			"dark"
#define TI_ITEM			"item"
#define TI_OBJECT		"object"

/*
FUNKTION: T_LISTE
DEKLARATION: Liste der T-Defines fuer Raeume und Gegenstaende
BESCHREIBUNG:

Bedingungen:
 - T_DAY		Es ist Tag.
 - T_NIGHT		Es ist Nacht.
 - T_DARK		Es ist dunkel (fuer den Betrachter).
 - T_LIGHT		Es ist hell (fuer den Betrachter).
 - T_DAY_DARK		Es ist Tag, aber dunkel fuer den Betrachter.
 - T_DAY_LIGHT		Es ist Tag und hell.
 - T_NIGHT_DARK		Es ist Nacht und dunkel.
 - T_NIGHT_LIGHT	Es ist Nacht, aber hell.
 - T_BLIND		Der Betrachter ist blind.
 - T_EMPTY		Der betrachtete Container (oder Raum) ist leer.
 - T_VIS_EMPTY		Der betrachtete Containter enthaelt nur unsichtbares.
 - T_PRESENT(id)	Im Raum oder Objekt liegt ein Objekt mit der Id 'id'.
 - T_PRESENT_ROOM(id)	Im Raum liegt ein Gegenstand mit der Id 'id'.
 - T_PRESENT_CONT(id)	Der betrachtete Container hat ein Objekt mit der Id.
 - T_HIDDEN_PRESENT(id), T_HIDDEN_PRESENT_ROOM(id), T_HIDDEN_PRESENT_CONT(id)
			Das Objekt ist zudem versteckt.
 - T_INVIS_PRESENT(id, inv), T_INVIS_PRESENT_ROOM(id, inv),
   T_INVIS_PRESENT_CONT(id, inv)
			Das Objekt hat den Unsichtbarkeitslevel 'inv'.
			(V_ATOM_NOLIST, V_ATOM_HIDDEN, V_ATOM_INVIS oder
			V_ATOM_NOSHIMMER).
 - T_VIS_PRESENT(id), T_VIS_PRESENT_ROOM(id), T_VIS_PRESENT_CONT(id)
			Das Objekt ist sichtbar.
 - T_COND_(DEEP_)PRESENT(_ROOM/_CONT/_VIEWER)(V)(id [, deep-flag], fun[, args])
			Fuehrt ein cond_present bzw. cond_deep_present aus.
			Die V-Defines erhalten als 3. bzw. 4. Parameter die
			Argumente fuer die aufzurufende Funktion.
 - T_EXIT_FLAG(cmd, f)	Der Ausgang entspricht dem Flag (s. query_exit_flag)
 - T_GILDE(gilde)	Der Betrachter ist Mitglied der Gilde 'gilde'.
 - T_GENDER(gender)	Der Betrachter hat das Geschlecht 'gender'.
 - T_VCLOCK(from,to)	vclock() liegt zwischen (inkl.) from und (exkl.) to.
 - T_CLOCK(from,to)	clock() liegt zwischen (inkl.) from und (exkl.) to.
 - T_ROOMTYPE(type)	Der Raum hat den Raumtyp 'type' gesetzt.
 - T_NO_ASCII_ART	Der Betrachter moechte keine ASCII-Graphiken sehen.
 - T_FAR		Der Betrachter ist nicht anwesend.
 - T_OWNER		Der Betrachter hat den Gegenstand bei sich.
 - T_ENTRANCE(dir)	Der Betrachter kam aus der Richtung 'dir'.
 - T_GUEST		Der Betrachter ist ein Gast.
 - T_NEWBIE		Der Betrachter ist ein Newbie.
 - T_SPIELERRAT		Der Betrachter ist ein Spielerratsmitglied.
 - T_WIZ		Der Betrachter ist Gott.
 - T_EYE_OPTION(opt)	Betrachter ist Gott und hat Augenoption 'opt' gesetzt.

Vordefinierte Texte:
 - T_DAYTIME		Die Tageszeitenmeldung.
 - T_DARKNESS_TEXT	Die Standardraumbeschreibung in der Dunkelheit.
 - T_ROOMTYPETEXT(type)	Der Inhalt des Raumtypes 'type'.
 - T_SHORT_DESC		Die Short-Beschreibung des Gegenstandes/Raumes
 - T_PSEUDO(string)	Bindet 'string' als Pseudo-Closure ein.

Vordefinierte Filter:
 - T_CAPITALIZE		Den ersten Buchstaben des Textes gross schreiben.
 - T_UPPERCASE		Alles gross schreiben.
 - T_LOWERCASE		Alles klein schreiben.
 - T_DEBUG		Text wird nur Goettern in Debug-Farbe ausgegeben.

Vordefinierte Eigenschaften zum Vergleich mit T_GREATER & Co.:
 - TN_VCLOCK		Die VL-Uhrzeit
 - TN_CLOCK		Die RL-Uhrzeit
 - TN_STAT_STR		Die Staerke des Betrachters
 - TN_STAT_INT		Die Intelligenz des Betrachters
 - TN_STAT_CON		Die Ausdauer des Betrachters
 - TN_STAT_DEX		Die Geschichklichkeit des Betrachters
 - TN_KOERPERGROESSE	Die Koerpergroesse des Betrachters
 - TN_ALIGN		Das Ansehen des Betrachters
 - TN_LEVEL		Der Level des Betrachters
 - TN_STAYDUR		Wie lange der Betrachter bereits im Raum ist.

Hinweise fuer die Meldungsgeneration:
 - T_HAS_DAYTIME	Es soll keine Tageszeitmeldung angehaengt werden.
 - T_HAS_BLINDTEXT	Der Text hat eine eigene Meldung fuer (VL-)Erblindete.
 - T_HAS_SHORT_DESC	Der Text nennt die Short-Beschreibung.
  
VERWEISE: set_long, compile_desc, query_type
GRUPPEN: beschreibung, raum
*/
#endif // __DESCRIPTION_H__
