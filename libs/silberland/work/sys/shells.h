// SilberLand MUDlib
//
// sys/shell.h -- shell header
//
// $Date: 2001/12/01 16:42:11 $
/* $Revision: 1.5 $
 * $Log: shells.h,v $
 * Revision 1.5  2001/12/01 16:42:11  Woody
 * neu: P_FILESYS
 *
 * Revision 1.4  2000/10/27 19:23:17  Zordan
 * neue Propertie: P_LAST_DIR (last_dir) fuer cd -
 *
 * Revision 1.3  1997/03/31 13:39:09  Woody
 * prepared for revision control
 *
 * Revision 1.2  1994/05/18  13:25:03  Jof
 * P_SHORT_CWD
 *
 * Revision 1.1  1994/02/08  17:15:40  Hate
 * Initial revision
 *
 */

#ifndef __SHELLS_H__
#define __SHELLS_H__

// properties

#define P_CURRENTDIR "currentdir"
#define P_SHORT_CWD  "short_cwd"
#define P_LAST_DIR   "last_dir"
#define P_FILESYS    "filesys"

#endif // __SHELLS_H__

#ifdef NEED_PROTOTYPES

#ifndef __SHELLS_H_PROTO__
#define __SHELLS_H_PROTO__

// prototypes
// no prototypes

#endif // __SHELLS_H_PROTO__

#endif	// NEED_PROTOYPES
