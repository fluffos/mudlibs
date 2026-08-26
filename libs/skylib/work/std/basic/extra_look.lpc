/**
 * Handles adding bits to the long description of objects.
 * @author Pinkfish
 * @changed Added the ability to use function pointers.
 * - Sandoz, 2002.
 */

private nosave mixed extra_looks;

/**
 * This method creates the extra long strings based on the current list
 * of objects to use an extra_look on.  The function extra_look() is
 * called on every object with TO passed in as the first (and only)
 * parameter.  If the result is non-zero it is added onto the output.
 * In case of function pointers, the function pointer will be evaluated
 * with TO as the argument.
 * @return the extra look string
 */
string calc_extra_look() {
    int i;
    string ret, tmp;

    ret = "";

    if( !sizeof(extra_looks) )
        return ret;

    for( i = 0; i < sizeof(extra_looks); i++ ) {
        if( extra_looks[i] ) {
            if( functionp( extra_looks[ i ] ) )
                tmp = evaluate( extra_looks[ i ], TO );
            else
                tmp = extra_looks[ i ]->extra_look( TO );

            if( tmp )
                ret += tmp;

        } else {
            extra_looks = delete( extra_looks, i, 1 );
            i--;
        }
    }

    return ret;

} /* calc_extra_look() */

/**
 * This method adds an object or function pointer into the list of
 * extra look objects/functions.  When using function pointers,
 * remember that you cannot use remove_extra_look() to remove them.
 * @param add the object or function to add
 * @see calc_extra_look()
 * @see remove_extra_look()
 */
void add_extra_look( mixed add ) {
    if( pointerp(extra_looks) ) {
        if( member_array( add, extra_looks ) == -1 )
            extra_looks += ({ add });
    } else {
        extra_looks = ({ add });
    }
} /* add_extra_look() */

/**
 * This method removes an object from the list of extra look objects.
 * This will only work for objects and string, function pointers
 * cannot be removed from the extra look list.
 * @param ob the object to remove
 * @see calc_extra_look()
 * @see add_extra_look()
 */
void remove_extra_look( object ob ) {
    int i;

    if( sizeof(extra_looks) && ( i = member_array( ob, extra_looks ) ) != -1 )
        extra_looks = delete( extra_looks, i, 1 );

} /* remove_extra_look() */

/**
 * This method returns the current list of objects to be used for
 * the extra look list.
 * @see add_extra_look()
 * @see remove_extra_look()
 * @see calc_extra_look()
 * @return the array of extra look objects
 */
mixed query_extra_look_list() { return extra_looks || ({ }); }
