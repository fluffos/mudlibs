// SilberLand MUDlib
//
// /p/daemon/object.h -- persistent object handling
//
// $Date: 1997/03/16 02:32:07 $
/* $Revision: 1.2 $
 * $Log: object.h,v $
 * Revision 1.2  1997/03/16 02:32:07  Woody
 * prepared for revision control
 *
 * Revision 1.1  1995/03/31  13:30:33  Hate
 * Initial revision
 *
 */
 
#ifndef __OBJECT_H__
#define __OBJECT_H__

// defines
#define OBJECTD       "/p/daemon/objectd"
#define OBJECTD_SAVE  "/p/daemon/save/objectd"

#endif // __OBJECT_H__

#ifdef NEED_PROTOTYPES

#ifndef __OBJECT_H_PROTO__
#define __OBJECT_H_PROTO__

// prototypes
mixed AddObject(string obj, string env);
mixed RemoveObject(string obj, string env);
varargs void QueryObject(mixed env);


#endif // __OBJECT_H_PROTO__

#endif	// NEED_PROTOYPES
