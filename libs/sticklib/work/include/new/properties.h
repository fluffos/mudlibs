/*
 * properties.h
 *
 * See /std/atom.c for more information.
 *
 */
 
 
#ifndef _PROPERTIES_H
#define _PROPERTIES_H
 
// Special properties
//
// P_NO_DESTRUCT	This object can not be destructed by mortal means.
// P_NO_CLEAN_UP	This object won't be cleaned up. NOT USED CURRENTLY!
// P_NO_RESET		This object won't be resetted.
// P_NO_ENTER		No objects allowed to enter us.
// P_NO_LEAVE		No objects allowed to leave us.
 
#define P_NO_DESTRUCT		1
#define P_NO_CLEAN_UP		2
#define P_NO_RESET		3
#define P_NO_ENTER		4
#define P_NO_LEAVE		5
 
// Living specialities
//
// P_NO_PICK		This object can't be picked up
// P_NO_DROP		This object can't be dropped.
 
#define P_NO_PICK		10
#define P_NO_DROP		11
 
// Standard properties
 
#define P_NAME			20
#define P_LIGHT			21
#define P_WEIGHT		22
#define P_VOLUME		23
 
// Container properties
 
#define P_LIGHT_IN		30
#define P_WEIGHT_IN		31
#define P_VOLUME_IN		32
#define P_MAX_WEIGHT		35
#define P_MAX_VOLUME		36
 
// Living properties. None used yet.
 
#define LIV_RACE		100
#define LIV_TMP_RACE		101
 
#endif /* _PROPERTIES_H */
 
 
