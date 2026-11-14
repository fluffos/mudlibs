// SilberLand MUDlib
//
// sys/room/exits.h -- room exits handling header
//
// $Date: 2001/11/07 17:02:44 $
/* $Revision: 1.5 $
 * $Log: exits.h,v $
 * Revision 1.5  2001/11/07 17:02:44  Woody
 * EX_MSG_OUT, EX_MSG_IN, EXG_FUNC definiert
 *
 * Revision 1.4  1997/09/15 23:46:14  Woody
 * P_NEW_EXITS und die EX_ sowie EXG_ Keys definiert
 *
 * Revision 1.3  1997/03/31 15:40:30  Woody
 * prepared for revision control
 *
 * Revision 1.2	 1996/09/25 05:17:00	Woody
 * P_HIDE_EXITS eingefuehrt ("Verstecken" von Ausgaengen)
 *
 * Revision 1.1	 1996/03/11 01:55:00	Mupfel
 * Konstanten aus /sys/properties.h 'verlegt'
 */
 
#ifndef __ROOM_EXITS_H__
#define __ROOM_EXITS_H__

// properties

#define P_NEW_EXITS             "new_exits"
#define P_EXITS                 "exits"
#define P_HIDE_EXITS            "hide_exits"
#define P_SPECIAL_EXITS         "special_exits"
#define P_EXIT_PREPOSITION      "exit_preposition"

// mapping keys

#define EX_DEST                 "ex_dest"
#define EX_TESTFUNC             "ex_testfunc"
#define EX_FUNC                 "ex_func"
#define EX_MSG                  "ex_msg"
#define EX_PLMSG                "ex_plmsg"
#define EX_MSG_OUT              "ex_msg_out"
#define EX_MSG_IN               "ex_msg_in"
#define EXG_ID                  "exg_id"
#define EXG_FUNC                "exg_func"
#define EXG_PLMSG               "exg_plmsg"
#define EXG_RMMSG               "exg_rmmsg"

#endif // __ROOM_EXITS_H__

#ifdef NEED_PROTOTYPES

#ifndef __ROOM_EXITS_H_PROTO__
#define __ROOM_EXITS_H_PROTO__

// prototypes
void AddExit(mixed cmd, mixed room);
void RemoveExit(mixed cmd);
void AddSpecialExit(mixed cmd, mixed function);
void RemoveSpecialExit(mixed cmd);
void AddGuardedExit(mixed cmd, mixed room, string id, mixed fail_msg);
void RemoveGuardedExit(mixed cmd);
varargs string GetExits(object viewer);

#endif // __ROOM_EXITS_H_PROTO__

#endif	// NEED_PROTOYPES
