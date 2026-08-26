/**
 * This has the controlling code for holding/weilding objects.
 * @author Pinkfish
 */

nosave mixed using, weapons;

int *set_unhold( object ob );
int *set_hold( object ob, int pos );

void create() {
    weapons = ({ });
} /* create() */

/**
 * This method returns the an array of the names of the limbs
 * on the living object.
 * @return an array of limbs
 */
mixed query_limbs() {
    mixed race_ob;
    string *limbs;

    if( !race_ob = TO->query_race_ob() )  {
        using = ({ });
        return ({ });
    }

    limbs = (string *)race_ob->query_limbs();

    if( !using )
        using = allocate( sizeof(limbs) );

    return limbs;

} /* query_limbs() */

/**
 * This method returns the current holding array of the living object.
 * This has one element in the array for each object and a 0 is in the
 * array if that limb is not holding anything.  The positions correspond
 * to the positions returned by the query_limbs() function.
 * @return an array of held objects
 * @see query_holding()
 * @see query_free_limbs()
 * @see query_weapons()
 */
object *query_holding() {
    if( !using )
        query_limbs();
    return copy(using);
} /* query_holding() */

/**
 * This method returns the number of free limbs on the living object.
 * A free limb!  Yes, have a couple of free legs, beat the rush!
 * Buy now!
 * @return the number of free limbs
 * @see query_holding()
 * @see query_limbs()
 */
int query_free_limbs() {
    if( !using )
        query_limbs();
    return sizeof( using ) - sizeof( using - ({ 0 }) );
} /* query_free_limbs() */

/**
 * This method returns the currently held weapons on the living object.
 * This is an array of held items which are weapons and can be used
 * in combat.
 * @return the array of held weapons
 * @see query_holding()
 */
object *query_weapons() { return copy( weapons -= ({ 0 }) ); }

/**
 * This method sets the object as unheld.  It will attempt to remove
 * the object from a held limb.
 * <p>
 * The return array contains the index of the limbs from which the
 * item was removed, if the array is 0 size then no items were
 * removed.
 * @param ob the object to unhold
 * @return a array of limb numbers
 * @see set_hold()
 * @see query_limbs()
 */
int *set_unhold( object ob ) {
    int *bits, pos, j;

    if( ( pos = member_array( ob, using ) ) == -1 )
        return ({ });

    if( !ob->set_holder(0) )
        return ({ });

    if( ob->query_weapon() )
        weapons = weapons - ({ ob, 0 });

    // Ok, put it down, check to see if it occurs elsewhere in the array.
    bits = ({ pos });
    using[pos] = 0;

    while( ( j = member_array( ob, using ) ) != -1 ) {
        using[j] = 0;
        bits += ({ j });
    }

    if( ob->query_armour() )
        TO->remove_armour(ob);

    call_out("calc_burden", 1 );

    return bits;

} /* set_unhold() */

/**
 * This method sets the object as held.  It will attempt to hold it
 * starting at the given position in the limbs array.
 * <p>
 * The return array contains the index of the limbs from which the
 * item was added, if the array is 0 size then no items were
 * added.
 * @param ob the object to hold
 * @param pos the position in the limb array to start holding at
 * @return a array of limb numbers
 * @see set_unhold()
 * @see query_limbs()
 */
int *set_hold( object ob, int pos ) {
    int j, x, y, off, ret, *bits, ok;

    if( !using )
        query_limbs();

    if( pos == -1 && ( pos = member_array( 0, using ) ) == -1 )
        return ({ });

    if( using[pos] && !sizeof( set_unhold(using[pos]) ) )
        return ({ });

    if( member_array( ob, using ) != -1 && !sizeof( set_unhold(ob) ) )
        return ({ });

    if( ret = ob->query_no_limbs() ) {
        // Wants more than one hand.
        ok = 1;
        for( j = 1; ok ; j++ ) {
            ok = 0;
            if( (pos-j) >= 0 && !using[pos-j] )
                ok = ++y;
            if( (pos+j) < sizeof(using) && !using[pos+j] )
                ok = ++x;
        }

        // We failed.  Tell the object about it.
        if( y+x+1 < ret )
            return ({ });

        if( !ob->set_holder( TO, pos ) )
            return ({ });

        // Try and go up first...
        using[pos] = ob;
        bits = ({ pos });
        for( j = 1; j < ret; j++ ) {
            if( x > 0 ) {
                bits += ({ pos+(++off) });
                using[pos+off] = ob;
                if( !--x )
                    off = 0;
            } else {
                bits += ({ pos-(++off) });
                using[pos-off] = ob;
            }
        }

        if( ob->query_weapon() )
            weapons += ({ ob });

        call_out("calc_burden", 1 );

        return bits;

    }

    return ({ });

} /* set_hold() */
