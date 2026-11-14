/*
 * Tamedhon MUDlib
 * ---
 * /secure/npcmaster.h
 * Maintained in Tamedhon by Querolin & TamTam
 * Definitionen fuer den NPC Master, maintained by Woody
 * ---
 * $Date: 2008/03/09 20:00:00 $
 * $Revision: 1.4 $
 * $Log: npcmaster.h,v $
 *
 * Revision 1.4  2008/03/09 20:00:00  TamTam
 * #define NPCLOGFILE + NPC_NO_ENTRY + NPC_ORACLE_ARG
 *
 * Revision 1.3  1997/06/01 15:56:34  Woody
 * #define NPC_QUEUED
 *
 * Revision 1.2  1997/03/15 23:29:40  Woody
 * _NPCMASTER_H_ -> __NPCMASTER_H__ (general convention)
 *
 * Revision 1.1  1997/03/15 23:28:39  Woody
 * prepared for revision control
 *
 * Revision 1.0  96-10-05  Woody
 * Erste Implementation
 *
 */

#ifndef __NPCMASTER_H__
#define __NPCMASTER_H__

#define NPCMASTER	"/secure/npcmaster"
#define NPCSAVEFILE	"/secure/ARCH/npcmaster"
#define NPCDUMPFILE	"/secure/ARCH/npcdump"
// - Logfile --------------------------------------------------------------
#define NPCLOGFILE      "ARCH/npc.log"

#define NPC_NUMBER	0
#define NPC_SCORE	1

#define NPC_INVALID_ARG -1
#define NPC_NO_PERMISSION -2
#define NPC_QUEUED      -3
// - Oracle --------------------------------------------------------------
#define NPC_NO_ENTRY     -4	// Eintrag nicht gefunden
#define NPC_ORACLE_ARG   -5	// Ungueltiges Argument

#define NPC_EXP_MARK1 250000
#define NPC_EXP_MARK2 600000
#define NPC_EXP_MARK3 1000000

#endif

