// SilberLand MUDlib
//
// sys/mnpc.h -- standard moving NPC header
//
// $Date: 1997/03/31 13:07:58 $
/* $Revision: 1.1 $
 * $Log: mnpc.h,v $
 * Revision 1.1  1997/03/31 13:07:58  Woody
 * prepared for revision control
 *
 */

// 1996/05/15
// Revision 1.1  1996/05/15  20:00  Woody
// 1996/04/13
// Revision 1.0  1996/04/13  20:00  Woody

#ifndef __MNPC_H__
#define __MNPC_H__

// properties

#define P_MNPC "is_mnpc"
#define P_MNPC_AREA "mnpc_area"
#define P_MNPC_CMDS "mnpc_cmds"
#define P_MNPC_WAIT "mnpc_wait"
#define P_MNPC_FLAGS "mnpc_flags"
#define P_MNPC_DEFAULTROOM "mnpc_defaultroom"

// flags

#define MOV_BACKWARDS 1  // MNPC darf auch zurueck gehen
#define MOV_INDOORS   2  // MNPC darf in geschlossene Raeume
#define MOV_OUTDOORS  4  // MNPC darf ins Freie
#define MOV_SPECIAL   8  // MNPC darf special exits verwenden
#define MOV_MAYLOAD  16  // MNPC darf Raeume bei Bedarf laden
                         // (nur wenn wirklich notwendig!!)
#define MOV_MOVES    32  // MNPC ist aktiv
#define MOV_CMDS     64  // MNPC verwendet Kommandoabfolge statt random move
#define MOV_INFIGHT 128  // MNPC bewegt sich auch im Kampf

#endif

#ifdef NEED_PROTOTYPES

#ifndef __MNPC_H_PROTO__
#define __MNPC_H_PROTO__

// prototypes

// lets our moving NPC move; returns 1 if moved, 0 otherwise
int wandern();

// compatibility functions; to be removed
void SetMove (string Where, int Backwards, int Indoors,
    int Wait1st, int WaitMin, int WaitRnd, string DefRoom);
int ActivateMove (int flag);

#endif // __MNPC_H_PROTO__

#endif  // NEED_PROTOYPES

