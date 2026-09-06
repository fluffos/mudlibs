#include <const.h>

/** This object has functions for doing simple calculations on shapes
 * and storing the shape of this object. Note that if the shape is
 * an important piece of data (i.e. it has to save when the mud
 * reboots, and it can't be recalculated from other data), then
 * you should look at the Spots component.
 */

/// Cache storage of this object's shape and its border.
nosave mapping shape, border;

/** Gets the outline of the shape in \a m -- i.e. every
 * cell that is adjacent (up, down, left, or right) from a cell
 * in m, but which does not occur in m.
 */
mapping get_border_shape( mapping m ) {
   mapping out;
   int p;

   out = ([ ]);
   foreach( p : m ) {
      if( !member(m, MAKE_C(CX(p)-1,CY(p),CZ(p))) ) out += ([ MAKE_C(CX(p)-1,CY(p),CZ(p)) ]);
      if( !member(m, MAKE_C(CX(p),CY(p)-1,CZ(p))) ) out += ([ MAKE_C(CX(p),CY(p)-1,CZ(p)) ]);
      if( !member(m, MAKE_C(CX(p)+1,CY(p),CZ(p))) ) out += ([ MAKE_C(CX(p)+1,CY(p),CZ(p)) ]);
      if( !member(m, MAKE_C(CX(p),CY(p)+1,CZ(p))) ) out += ([ MAKE_C(CX(p),CY(p)+1,CZ(p)) ]);
   }

   return out;
}

/** \return This object's shape. If you don't specify a shape, the
 * shape will be guessed by painting the object in a special mode.
 * It's a little slow, but functional if that is all you want.
 */
mapping query_shape() {
   if( shape ) return shape;
   shape = environment()->get_shape( this_object() );
   if( !shape ) shape = ([ ]);
   return shape;
}

/** Set the shape directly. Not generally useful for anything but
 * debugging, since shapes do not save.
 */
void set_shape( mapping m ) {
   shape = m;
}

/** You can generally use this implementation -- calls get_border_shape()
 * on whatever the shape of this object is (determined by calling query_shape()),
 * and returns it.
 */
mapping query_border() {
   if( !border ) border = get_border_shape( query_shape() );
   return border;
}

/// Set the border shape directly. Only useful for debugging.
void set_border( mapping m ) {
   border = m;
}
