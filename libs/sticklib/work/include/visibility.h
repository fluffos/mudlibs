/*
 * visibility.h
 *
 * VISIBLE              - Normally visible to everyone.
 * WEAK_INVISIBLE       - Weak invisiblity, or a "shadow".
 * INVISIBLE            - Invisible. Players of high level enough can see
 *                        us, as well as with some spells.
 * DEEP_INVISIBLE       - Only coders can see us. Only coders should be set
 *                        to this invisibility level.
 *
 * Future ideas:
 *
 * Invisibility spell. Makes casting player and all his/hers carryings
 * invisible, but not what he/she gets later on. => "Plate mail leaves north"
 *
 * Weak_invisible - spells like 'wraithform' and so on..
 *
 * Deep_invisible - "disappearance" of coders..
 */

#ifndef VISIBILITY_H
#define VISIBILITY_H
 
#define VISIBLE			0
#define WEAK_INVISIBLE		1
#define INVISIBLE		2
#define DEEP_INVISIBLE		3
 
#endif
 
