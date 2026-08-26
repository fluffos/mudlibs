/**
 * Decays all the decable objects in the game.
 * @author Ember
 * @changed 17 Dec 1997 -- Sin
 *    I added a reset_eval_cost() call into the do_update() routine
 *    so that it wouldn't quit when there were a whole bunch of
 *    bits to decay.
 * @changed 6 Jan 1998 -- Sin
 *    I modified the do_update() routine so it'll register a callback
 *    even if one of the bits fails to decay.  That should help prevent
 *    the callout from disappearing.  If it does disappear, I added
 *    a kickstart function.
 * @changed 07 November 2001 -- Sandoz
 *    Changed the for loop to foreach in do_decay(), plus general cleanup.
 * @see /obj/food.c
 * @see /std/bit.c
 * @see /obj/corpse.c
 */

#include <bits_controller.h>

object *bits;
private int id;

private void do_update();

/** @ignore yes */
void kickstart() {
    if( sizeof(bits) && !id )
        id = call_out( (: do_update :), TIME_OUT );
} /* kickstart() */

/** @ignore yes */
void create() {
    bits = ({ });
} /* create() */

/**
 * Adds in a decable object into the decaying array.
 * @param ob the bit to decay
 */
void add_bit( object ob ) {
    if( member_array( ob, bits ) == -1 )
        bits += ({ ob });
    kickstart();
} /* add_bit() */

/**
 * Removes the decable object from the decaying array.
 * @param ob the bit to remove
 */
void remove_bit( object ob ) {
    int i;

    if( ( i = member_array( ob, bits ) ) == -1 )
        return ;

    bits = delete( bits, i, 1 );

} /* remove_bit() */

/** @ignore yes */
private void do_update() {
    object bit;

    bits -= ({ 0 });

    remove_call_out(id);
    id = 0;

    if( !sizeof(bits) )
        return;

    kickstart();

    foreach( bit in bits ) {
        reset_eval_cost();
        bit->do_decay();
    }

    bits -= ({ 0 });

} /* do_update() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping m;

    m = ([ ]);

    if( sizeof(bits) )
        m["bits"] = bits;

    return m;

} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping m ) {
    if( m["bits"] ) {
        bits = m["bits"];
        kickstart();
    }
} /* init_dynamic_arg() */

/** @ignore yes */
int query_num_bits() { return sizeof(bits); }
/** @ignore yes */
object *query_bits() { return bits; }
