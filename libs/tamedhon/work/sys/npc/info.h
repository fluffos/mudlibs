// Tamedhon MUDlib
//
// sys/npc/info.h -- NPC info system
//
// $Date: 2004/01/27 20:05:00 $
/* $Revision: 1.6 $
 * $Log: info.h,v $
 * Revision 1.6  2004/01/27 20:05:00  Serii
 * anpassung des pfades fuer den libmaster (von /obj nach /secure)
 *
 * Revision 1.5  1997/05/15 15:57:57  Woody
 * prototype fuer AddInfo() aktualisiert (silent Parameter)
 *
 * Revision 1.4  1997/03/31 14:42:25  Woody
 * prepared for revision control
 *
 * Revision 1.3  1997/02/19  21:30:00  Woody
 * neuer Prototyp fuer AddLibrary()
 *
 * Revision 1.2  1997/02/12  21:30:00  Woody
 * INFOLIB_MASTER definiert, Prototyp fuer AddLibrary() und RemoveLibrary()
 *
 * Revision 1.1  1996/03/12  14:33:00  Mupfel
 * Konstanten uebernommen aus /sys/properties.h und /sys/npc.h
 *
 */
 
#ifndef __NPC_INFO_H__
#define __NPC_INFO_H__

#define INFOLIB_MASTER "/secure/libmaster"

// properties

#define P_LOG_INFO "log_info"
#define P_DEFAULT_INFO "default_info"

// special defines

#define DEFAULT_INFO "\ndefault info"

#endif // __NPC_INFO_H__

#ifdef NEED_PROTOTYPES

#ifndef __NPC_INFO_H_PROTO__
#define __NPC_INFO_H_PROTO__

// prototypes

varargs void AddInfo(mixed key, mixed info, string indent, mixed silent);
void RemoveInfo( string key );
varargs mixed GetInfo( string key );
varargs void AddLibrary( string library, int level, int localflag );
void RemoveLibrary( string library );

#endif // __NPC_INFO_H_PROTO__

#endif	// NEED_PROTOYPES
