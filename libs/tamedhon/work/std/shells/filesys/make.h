// SilberLand MUDlib
//
// make.h -- definitions for make
//
// $Date: 1997/03/13 02:10:07 $
/* $Revision: 1.1 $
 * $Log: make.h,v $
 * Revision 1.1  1997/03/13 02:10:07  Woody
 * prepared for revision control
 *
 */

#ifndef __MAKE_H__
#define __MAKE_H__

#define UPD_OPTS  "afilrmbvc"

#define UPD_A		 1		// update all found instances
#define UPD_F		 2		// find all instances
#define UPD_I		 4		// update inherited blueprints
#define UPD_L		 8		// update/load files (if not loaded)
#define UPD_R		16		// update/reload files (only loaded)
#define UPD_M   32    // make (check dependencies)
#define UPD_B   64    // give backtrace when failed to load
#define UPD_V  128    // verbose (give more info)
#define UPD_C  256    // copy (save and restore properties)

#define NO_CHECK        M_GO|M_SILENT|M_NO_SHOW|M_NO_ATTACK

#define INV_SAVE        "/gilden/abenteurer.lpc"
#define INV_SAVE_E      "/room/void.lpc"

#endif // __MAKE_H__
