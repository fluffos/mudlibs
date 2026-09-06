#include <item.h>

/** This is a variation on Item that allows you to have more then
 * one 'thing' per item.
 */

/** If this variable is set, this material MUST be held in a watertight container. If
 * it is clear (0), then it may be dropped on the ground.
 */
int liquid;

/** The weight of each unit of the material.
 */
int unit_weight;

/// Used by the object editor to edit these properties
string material_info() {
   return "liquid\nvolume";
}

/// \return True, if this material is a liquid, false otherwise.
int query_liquid() {
   return liquid;
}

/** Allows you to set whether this material is a liquid. If \a x is 0, it isn't, otherwise it is.
 * Note that a liquid is defined as any material which requires a watertight container to hold
 * it, which may be poured, which mixes and separates freely, and which is effectively dissipated
 * by pouring it on the ground. Thus, sand, flour, water, and milk are liquids. Money is not,
 * because it doesn't dissipate.
 */
void set_liquid( int x ) {
   liquid = x;
}
