/*
 * SilberLand MUD-Lib
 * ---
 * /secure/npcmaster.h
 * Definitionen fuer den NPC Master, maintained by Woody
 * ---
 * $Date: 2004/11/09 22:26:45 $
 * $Revision: 1.7 $
 * $Log: npcmaster.h,v $
 * Revision 1.7  2004/11/09 22:26:45  Feyaria
 * EXP_MARK geaendert
 *
 * Revision 1.6  2003/11/26 20:39:56  Feyaria
 * EXP_MARK geaendert
 *
 * Revision 1.5  2001/02/17 00:13:38  Woody
 * P_NO_SCORE definiert
 *
 * Revision 1.4  1999/05/22 01:08:01  Woody
 * NPCLOGFILE
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
#define NPCLOGFILE      "ARCH/npc.log"

#define NPC_NUMBER	0
#define NPC_SCORE	1

#define NPC_INVALID_ARG         -1
#define NPC_NO_PERMISSION       -2
#define NPC_QUEUED              -3

#define NPC_EXP_MARK1   400000
#define NPC_EXP_MARK2   1000000
#define NPC_EXP_MARK3   3000000

#define P_NO_SCORE      "no_score"

#endif

