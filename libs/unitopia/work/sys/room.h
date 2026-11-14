// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/room.h
// Description:	Defines fuer /i/room.c
//
// $Log: room.h,v $
// Revision 1.9  2015/01/21 15:43:10  gnomi
// EXIT_IS_(UN)LOCKED eingebaut.
//
// Revision 1.8  2011-12-10 01:19:42  gnomi
// Schatztruhen umgebaut.
//
// Revision 1.7  2010-03-28 13:15:56  gnomi
// EI-Konstanten nach /sys/room.h ausgelagert.
//
// Revision 1.6  2009-06-17 08:04:52  gnomi
// Defines fuer die Schatzkisten.
//
// Revision 1.5  2006/06/07 20:26:39  gnomi
// Defines fuer die temp_traces.
//
// Revision 1.4  2002/08/10 00:24:55  gnomi
// Neues Define fuer neuen query_visitors-Eintrag.
//
// Revision 1.3  2002/07/20 02:34:07  gnomi
// Defines fuer weitere Eintraege bei query_visitors().
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef ROOM_H
#define ROOM_H 1

/* room internals */

#define EXIT_ATOM_NOLIST	0x01
#define EXIT_ATOM_HIDDEN	0x02
#define EXIT_ATOM_LOCKED	0x04
#define EXIT_ATOM_NOT		0x08
#define EXIT_ATOM_VIEW		0x10

/* externals to be used with add_exit_flag / query_exit_list / query_command_list */

#define EXIT_HIDDEN       (EXIT_ATOM_NOLIST | EXIT_ATOM_HIDDEN)
#define EXIT_VISIBLE      (EXIT_ATOM_NOT | EXIT_ATOM_NOLIST | EXIT_ATOM_HIDDEN | EXIT_ATOM_LOCKED)
#define EXIT_LOCKED       (EXIT_ATOM_NOLIST | EXIT_ATOM_LOCKED)
#define EXIT_UNLOCKED     (EXIT_ATOM_NOT | EXIT_ATOM_LOCKED)
#define EXIT_NOLIST       (EXIT_ATOM_NOLIST)
#define EXIT_VIEW	  (EXIT_ATOM_VIEW)

/* externals to be used with query_exit_list / query_command_list */

/* EXIT_LOCKED/UNLOCKED enthaelt wegen der Nutzung fuer add_exit_flag
 * auch EXIT_ATOM_NOLIST. Daher fuer die Abfrage eigene Defines.
 */
#define EXIT_IS_LOCKED    (                EXIT_ATOM_LOCKED)
#define EXIT_IS_UNLOCKED  (EXIT_ATOM_NOT | EXIT_ATOM_LOCKED)

// traces
#define CREATE_TRACES

// Maximale Anzahl an Besuchern, die gespeichert werden sollen.
#define TR_MAX_VISITORS 7

// special exits
#define TR_NO_ENVIRONMENT "#1"
#define TR_MAGIC_MOVE     "#2"

// traces indices
#define TRT_COUNT 0
#define TRT_TIME  1
#define TRT_WHO   2
#define TRT_NAME  3
#define TRT_STAT  4
// insert here
#define TRT_WIDTH 5 // LAST

// visitors indices
#define TRV_TRACE 0
#define TRV_TIME  1
#define TRV_WHO   2
#define TRV_NAME  3
#define TRV_INVIS 4
#define TRV_DESC  5
#define TRV_REAL_DESC 6
#define TRV_TRACE_ROOMS 7

// temp_traces indices
#define TRTT_ORIGIN	0
#define TRTT_ORIGIN_FN	1
#define TRTT_TIME	2
// insert here
#define TRTT_WIDTH	3

// Indizes bei query_exit_info()
#define EI_EXIT			0
#define EI_C_EXIT_MSG_OUT	1
#define EI_C_EXIT_MSG_IN	2
#define EI_DIR_MSG_OUT		3
#define EI_DIR_MSG_IN		4
#define EI_DIR_PREP_IN		7
#define EI_DIR_PREP_OUT		8
#define EI_EXIT_FLAG		9
#define EI_C_EXIT_MSG_SELF	10
#define EI_DIRECTION		11
#define EI_SIZE			12

#define CHEST_NAME      "name"
#define CHEST_OWNER     "owner"
#define CHEST_MONEY     "money"
#define CHEST_INV_ID    "inv_id"
#define CHEST_INV_VALUE "inv_value"
#define CHEST_OB        "ob"

#endif // ROOM_H
