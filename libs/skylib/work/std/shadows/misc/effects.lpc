/**
 * Revision 1.4  2002/09/03 17:59:34  sandoz
 * Changed to recycle the shadow.
 *
 * Revision 1.3  2000/05/08 18:05:06  pinkfish
 * Fix up the shadow to work correctly with the effects inheritable using
 * private variables.
 *
 * Revision 1.2  1999/04/21 11:47:21  wodan
 * fixed small bug in stats function
 *
 * Revision 1.1  1998/01/06 04:39:04  ceres
 * Initial revision
 *
 */

#include <origin.h>

inherit "/std/basic/effects";

private object shadowed;

/** @ignore yes */
void setup_shadow( object thing ) {
    shadow( thing, 1 );
    shadowed = thing;
} /* setup_shadow() */

/** @ignore yes */
void destruct_shadow( object thing ) {
    if( thing == TO ) {
        if( !SHADOW_H->recycle_shadow(TO) )
            destruct(TO);
    } else {
        thing->destruct_shadow( thing );
    }
} /* destruct_shadow() */

/** @ignore yes */
void set_effs( mixed args ) { ::set_effs(args); }

/** @ignore yes */
void set_eeq( mixed args ) { ::set_eeq(args); }

/**
 * This method is called by delete_effect(),
 * and will removed the effects shadow from the object.
 */
void event_all_effects_deleted() {
    if( PO == TO )
        destruct_shadow(TO);
} /* event_all_effects_deleted() */

/**
 * This method is called by the basic object inherit, and will
 * removed all effect shadows from the object when being destructed.
 */
void event_object_being_dested() {
    if( PO == shadowed ) {
        int i = sizeof( query_effs() );
        while( i-- )
            TO->remove_effect_shadow( enum_to_sid(i) );
        destruct_shadow(TO);
    }
} /* event_all_effects_deleted() */

/** @ignore yes */
mixed stats() {
    mixed tmp;

    if( !pointerp( tmp = (mixed)shadowed->stats() ) )
        tmp = ({ });

    return ::stats() + tmp;

} /* stats() */
